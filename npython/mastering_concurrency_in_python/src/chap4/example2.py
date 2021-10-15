from threading import Lock

my_lock = Lock()

def get_data_from_file_v1(filename):
    print("acquiring lock")
    my_lock.acquire()
    print("lock acquired")

    with open(filename, 'r') as file:
        data.append(file.read())

    print("releasing lock")
    my_lock.release()
    print("lock released")

def get_data_from_file_v2(filename):
    # since, Lock objects are context managers, simply using with my_lock:
    # would ensure that the lock object is acquired and released appropriately,
    # even if an exception is encountered inside the blcok
    with my_lock, open(filename, 'r') as file:
        data.append(file.read())

data = []

try:
    # get_data_from_file_v1("sample0.txt")
    get_data_from_file_v2("sample0.txt")
except FileNotFoundError:
    print("Encountered an exception...")

print("before last lock acquire statement")
my_lock.acquire()
print("lock can still be acquired")
