from timeit import default_timer as timer
import concurrent.futures

# sequential
def f(x):
    print("f called, x:", x)
    return x * x - x + 1

start = timer()

# result = 3
# for _ in range(20):
    # result = f(result)

# concurrent
def concurrent_f(x):
    global result
    print("concurrent_f called, x:", x, ", result:", result)
    result = f(result)

result = 3

with concurrent.futures.ThreadPoolExecutor(max_workers=20) as executor:
    futures = [executor.submit(concurrent_f, i) for i in range(20)]

    _ = concurrent.futures.as_completed(futures)

print("result:", result)
print("process took %.2f seconds" % (timer() - start))
