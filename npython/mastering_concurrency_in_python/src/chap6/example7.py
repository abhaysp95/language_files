from math import sqrt
import multiprocessing

class Consumer(multiprocessing.Process):
    def __init__(self, task_queue, result_queue):
        multiprocessing.Process.__init__(self)
        self.task_queue = task_queue
        self.result_queue = result_queue
        print("Process %s started" % self.name)

    def run(self):
        pname = self.name

        while not self.task_queue.empty():
            temp_task = self.task_queue.get()
            print("%s processing task: %s" % (pname, temp_task))
            answer = temp_task.process()

            # task_done(): indicates that formely enqued task is complete
            # Used by Queue consumer threads. For each get() used to fetch a
            # task, a subsequent call to task_done() tells the queue that the
            # processing on the task is complete.
            # If a join() is currently blocking, it'll resume when all items
            # have been processed (meaning that a task_done() call was recieved
            # for every item that had been put() into the queue).
            self.task_queue.task_done()
            self.result_queue.put(answer)

class Task():
    def __init__(self, x):
        self.x = x

    def process(self):
        if self.x < 2:
            return f"{self.x} is not a prime number"
        if self.x == 2:
            return f"{self.x} is a prime number"
        if self.x % 2 == 0:
            return f"{self.x} is not a prime number"

        limit = int(sqrt(self.x)) + 1
        for i in range(3, limit, 1):
            if self.x % i == 0:
                return f"{self.x} is not a prime number"
        return f"{self.x} is a prime number"

    def __str__(self):
        return f"Checking if {self.x} is a prime or not"

if __name__ == "__main__":
    tasks = multiprocessing.JoinableQueue()
    results = multiprocessing.Queue()

    # spawing consumers with respect to the
    # number of cores available in the system
    n_consumers = multiprocessing.cpu_count()
    print("Spawning %i consumers..." % n_consumers)
    consumers = [Consumer(tasks, results) for _ in range(n_consumers)]
    for consumer in consumers:
        consumer.start()

    # enqueing jobs
    my_input = [2, 36, 101, 193, 323, 513, 1327, 100000, 9999999, 433785907, 282039845, 823094029834907, 203984092384092349,
            238409823823094890321, 320840923849028349082397]
    for item in my_input:
        tasks.put(Task(item))

    # Blocks until all items in the Queue have been gotten and processed
    # The count of unfinished tasks goes up whenever an item is added to the
    # queue. The count goes down whenever a consumer thread calls task_done()
    # to indicate the item was retrieved and all work on it is complete.
    # When the count of unfinished tasks drops to zero, join() unblocks
    tasks.join()

    for i in range(len(my_input)):
        temp_result = results.get()
        print("Result:", temp_result)

    print("Done")



# poison pill
# to try to stop a consumer taking priority over another consumer for processing.
# Essentially, when one of our consumers - let's say Consumer-3 finished
# executing task, it tried to look for another task to execute immediately
# after. Most of the time, it would get priority over other consumers,
# since it was already being run by the main program. And so, other
# consumers will not get there chance(and many times this will in-turn make
# program behave like a sequential program, I think)
