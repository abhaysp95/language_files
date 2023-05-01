use std::{
    io::{BufRead, BufReader, Write},
    net::{TcpListener, TcpStream}, fs, thread, time::Duration, num::NonZeroUsize,
};

use hello_server::ThreadPool;

fn main() {
    let listener = TcpListener::bind("127.0.0.1:8080").unwrap();
    let pool = ThreadPool::new(NonZeroUsize::new(4).unwrap());

    for stream in listener.incoming().take(2) {
        let stream = stream.unwrap();

        thread::spawn(|| {});

        pool.execute(|| {
            handle_connection(stream);
        });
    }
}

fn handle_connection(mut stream: TcpStream) {
    println!("{:?}", &stream.peer_addr().unwrap());
    let buf_reader = BufReader::new(&mut stream);
    /* let http_request = buf_reader
        .lines()
        .map(|res| res.unwrap())  // could be problematic
        .take_while(|line| !line.is_empty())
        .collect::<Vec<_>>(); */

    let request_line = buf_reader.lines().next().unwrap().unwrap();

    /* let (response_status, response_file) = if request_line == "GET / HTTP/1.1" {
        ("HTTP/1.1 200 OK", "./hello.html")
    } else {
        ("HTTP/1.1 404 NOT FOUND", "./404.html")
    }; */

    let (response_status, response_file) = match &request_line[..] {
        "GET / HTTP/1.1" => ("HTTP/1.1 200 OK", "./hello.html"),
        "GET /sleep HTTP/1.1" => {
            thread::sleep(Duration::from_secs(5));
            ("HTTP/1.1 200 OK", "./hello.html")
        },
        _ => ("HTTP/1.1 404 NOT FOUND", "./404.html"),
    };

    let response_body = fs::read_to_string(response_file).unwrap();
    let response_body_len = response_body.len();
    let response = format!("{response_status}\r\nContent-Length: ${response_body_len}\r\n\r\n{response_body}");

    stream.write(response.as_bytes()).unwrap();
}
