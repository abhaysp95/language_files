use std::{num::NonZeroUsize, thread::{self, JoinHandle}, sync::{mpsc, Arc, Mutex}};

type Job = Box<dyn FnOnce() + Send + 'static>;

pub struct ThreadPool {
    workers: Vec<Worker>,
    sender: Option<mpsc::Sender<Job>>,
}

pub struct Worker {
    id: usize,
    thread: Option<JoinHandle<()>>,  // return type -> ()
}

impl ThreadPool {
    /// Create a new ThreadPool
    ///
    /// The size of the number of threads in the pool.
    pub fn new(count: NonZeroUsize) -> Self {
        let (sender, reciever) = mpsc::channel();
        let reciever = Arc::new(Mutex::new(reciever));

        let mut workers = Vec::with_capacity(count.get());

        for id in 1..count.get() {
            workers.push(Worker::new(id, Arc::clone(&reciever)));
        }

        ThreadPool { workers, sender: Some(sender) }
    }

    pub fn execute<F>(&self, f: F)
    where
        F: FnOnce() + Send + 'static,
    {
        let job = Box::new(f);
        self.sender.as_ref().unwrap().send(job).unwrap();
    }
}

impl Drop for ThreadPool {
    fn drop(&mut self) {
        drop(self.sender.take());  // close the channel

        for worker in &mut self.workers {
            println!("Shutting down worker {}", worker.id);

            if let Some(thread) = worker.thread.take() {
                thread.join().unwrap();
            }
        }
    }
}

impl Worker {
    fn new(id: usize, reciever: Arc<Mutex<mpsc::Receiver<Job>>>) -> Self {
        let thread = thread::spawn(move || loop {
            let message = reciever.lock().expect(format!("acquiring lock for worker {id}").as_str()).recv();

            match message {
                Ok(job) => {
                    println!("Worker {id} got a job; executing");

                    job();
                },
                Err(_) => {
                    println!("Worker {id} disconnected; shutting down");
                    break;
                }
            }

        });

        Worker { id, thread: Some(thread) }
    }
}
