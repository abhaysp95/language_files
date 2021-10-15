from multiprocessing import Process, current_process
import time

def f1():
    pname = current_process().name
    print("starting process %s..." % pname)
    time.sleep(2)
    print("exiting process %s..." % pname)

def f2():
    pname = current_process().name
    print("starting process %s..." % pname)
    time.sleep(4)
    print("exiting process %s..." % pname)

if __name__ == "__main__":
    p1 = Process(name="worker-1", target=f1)
    p2 = Process(name="worker-2", target=f2)
    p3 = Process(target=f1)

    p1.start()
    p2.start()
    p3.start()

    p1.join()
    p2.join()
    p3.join()

print("done")
