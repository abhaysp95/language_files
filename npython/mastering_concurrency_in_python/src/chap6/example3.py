from multiprocessing import Process, current_process
import time
import os

def print_info(title):
    print(title)

    if hasattr(os, 'getppid'):
        print("Parent process ID: %s" % str(os.getppid()))
    print("Current process ID: %s" % str(os.getpid()))

def f():
    print_info("Function f")
    pname = current_process().name
    print("starting process %s..." % pname)
    time.sleep(1)
    print("exiting process %s..." % pname)

if __name__ == "__main__":
    print_info("Main function")
    p1 = Process(name="p1", target=f)
    p2 = Process(name="p2", target=f)
    p3 = Process(name="p3", target=f)

    p1.start()
    p2.start()
    p3.start()

    p1.join()
    p2.join()
    p3.join()

    print("done")
