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
