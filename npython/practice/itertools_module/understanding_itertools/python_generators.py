import time

# def csv_reader(file_name):
    # file = open(file_name)  # this returns generator
    # result = file.read().split("\n") # however, split() loads everything in memory, can cause MemoryError
    # return result

def csv_reader(file_name):
    for row in open(file_name, "r"):
        yield row

# def csv_reader(file_name):
    # return open(file_name, "r")

# csv_gen = csv_reader("some_csv.txt")
csv_gen = (row for row in open("some_csv.txt"))  # generator expression
row_count = 0

for row in csv_gen:
    row_count += 1
print(f"Row count is {row_count}")

# generating an infinite sequence
def infinite_sequence():
    num = 0
    while True:
        yield num
        num += 1

# for x in infinite_sequence():
    # print(x, end=" ")

# generator expression
nums_squared_lc = [ num ** 2 for num in range(5) ]  # list comprehension
nums_squared_gc = ( num ** 2 for num in range(5) )  # generator comprehension
print(nums_squared_lc)  # a list
print(nums_squared_gc)  # a generator object

# how yield works
def multi_yield():
    yield_str = "This will print the first string"
    yield yield_str
    yield_str = "This will print the second string"
    yield yield_str

multi_obj = multi_yield()
print(next(multi_obj))
print(next(multi_obj))
# print(next(multi_obj))  # StopIteration

def caller_func():
    multi_obj = multi_yield()
    print(next(multi_obj))
    print("getting out of caller_func")

caller_func()
caller_func()  # this second call doesn't returns to print second string, instead new stack for multi_yield() is made
caller_func()


def is_palindrome(num) -> bool:
    if num // 10 == 0:
        return False
    temp = num
    reversed_num = 0

    while temp != 0:
        reversed_num = (reversed_num * 10) + (temp % 10)
        temp //= 10

    return True if num == reversed_num else False

def infinite_palindromes():
    num = 0
    while True:
        if is_palindrome(num):
            i = (yield num)
            print("i: ", i)
            if i is not None:
                num = i
        num += 1

# for x in infinite_palindromes():
    # print(x)
    # time.sleep(1)

pal_gen = infinite_palindromes()
for x in pal_gen:
    digits = len(str(x))
    print("digits:", digits, ", x:", x)
    try:
        if digits == 5:
            pal_gen.close()  # raises StopIteration
        pal_gen.send(10 ** (digits))
        time.sleep(1)
    except StopIteration:
        print("generator closed")
        # pal_gen.throw(ValueError("No larger palindrome than 5 allowed"))


file_name = "example.csv"
lines = (line for line in open(file_name))
list_line = (line.rstrip().split(',') for line in lines)
cols = next(list_line)

company_dicts = (dict(zip(cols, data)) for data in list_line)
funding = (
        int(company_dict["raisedAmt"])
        for company_dict in company_dicts
        if company_dict["round"] == "a"
        )

total_series_a = sum(funding)
print(f"Total series A fundraising: ${total_series_a}")
