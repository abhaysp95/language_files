from multiprocessing import Process
import time

def count_down(name, delay):
    print("Processing %s started..." % name)

    counter = 5

    while counter:
        time.sleep(delay)
        print(f"Process {name} is counting: {counter}")
        counter -= 1
    print("Process %s exiting..." % name)

if __name__ == "__main__":
    process1 = Process(target=count_down, args=('A', 0.5))
    process2 = Process(target=count_down, args=('B', 0.5))

    process1.start()
    process2.start()

    process1.join()
    process2.join()

    print("Done")

# The 'Process' calss has equivalent methods and APIs that can be found in the 'threading.Thread' class
# Some of the most used resources from 'multiprocessing' class are:
# * 'run()'
# * 'start()'
# * 'join()'
# * 'isAlive()'
# * 'name': this attribute contains the name of the callingg 'Process' object
# * 'pid': this attribute contains the process ID of the calling 'Process' object
# * 'terminate()': this method terminates the calling 'Process' object

# Just like we did for 'threading.Thread' class, one could also override the default 'Process()' constructor and implement one's own 'run()' function
