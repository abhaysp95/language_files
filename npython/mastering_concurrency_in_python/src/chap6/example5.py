from multiprocessing import Process, current_process
import time

def f1():
    p = current_process()
    print("Starting process: %s, pid: %s" %
            (p.name, p.pid))
    time.sleep(6)
    print("Exiting process: %s, pid: %s" %
            (p.name, p.pid))

def f2():
    p = current_process()
    print("Starting process: %s, pid: %s" %
            (p.name, p.pid))
    time.sleep(2)
    print("Exiting process: %s, pid: %s" %
            (p.name, p.pid))

if __name__ == "__main__":
    p1 = Process(name="worker1", target=f1)
    p1.daemon = True
    p2 = Process(name="worker2", target=f2)

    p1.start()
    time.sleep(1)
    p2.start()

    # instead of terminating without waiting for the daemon process, in this
    # example, we are calling the join() method on both process: we allow one
    # second for p1 to finish while we block the main program until p2 finishes
    p1.join(1)
    print("Whehter worker1 is still alive:", p1.is_alive())
    p2.join()
