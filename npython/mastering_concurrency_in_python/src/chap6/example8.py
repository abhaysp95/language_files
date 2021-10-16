# updated version of example7.py with implementation of poison pill

from math import sqrt
import multiprocessing

class Consumer(multiprocessing.Process):
    def __init__(self, task_queue, result_queue):
        multiprocessing.Process.__init__(self)
        self.task_queue = task_queue
        self.result_queue = result_queue

    def run(self):
        pname = self.name

        while True:
            temp_task = self.task_queue.get()

            if temp_task is None:
                print("Exiting %s..." % pname)
                self.task_queue.task_done()
                break

            print("%s processing tasks: %s" % (pname, temp_task))

            answer = temp_task.process()
            self.task_queue.task_done()
            self.result_queue.put(answer)

class Task():
    def __init__(self, x):
        self.x = x

    # a simple logic for getting if a number is prime
    def process(self):
        if self.x < 2:
            return "%i is not a prime number" % self.x
        if self.x == 2:
            return "%i is a prime number" % self.x
        if self.x % 2 == 0:
            return "%i is not a prime number" % self.x
        limit = int(sqrt(self.x)) + 1
        for i in range(3, limit, 1):
            if self.x % i == 0:
                return "%i is not a prime number" % self.x
        return "%i is a prime number" % self.x

    def __str__(self):
        return "Checking if %i is a prime or not" % self.x

if __name__ == "__main__":
    tasks = multiprocessing.JoinableQueue()
    results = multiprocessing.Queue()

    # spawning consumers with respect to the
    # number of cores available in the system
    n_consumers = multiprocessing.cpu_count()
    print("Spawing %i consumers..." % n_consumers)
    consumers = [Consumer(tasks, results) for _ in range(n_consumers)]
    for consumer in consumers:
        consumer.start()

    # enquing jobs
    my_input = [2, 36, 101, 193, 323, 513, 1327, 100000, 9999999, 433785907, 282039845, 823094029834907, 203984092384092349,
            238409823823094890321, 320840923849028349082397]
    for item in my_input:
        tasks.put(Task(item))

    # poison pill
    for i in range(n_consumers):
        tasks.put(None)

    tasks.join()

    for _ in range(len(my_input)):
        temp_result = results.get()
        print("Result:", temp_result)

    print("Done")
