#!/usr/bin/env python3

'''
provide multiple queries at a time
'''

import time
import subprocess
import random
from os import urandom

random.seed(urandom(1000))

def run_queries(command):
    ''' run provided query '''
    proc = subprocess.Popen(["./bin/repl4"],
                            stdin=subprocess.PIPE,
                            stdout=subprocess.PIPE,
                            encoding="ASCII")
    output = proc.communicate('\n'.join(command))[0]
    return output

def check_output(number=10):
    ''' provide different queries to run '''
    # at the time of writing this script(repl4), page_size is set to 100 at a
    # page can contain upto 23 rows as every row size was 172 bytes and a page
    # size was 4096 bytes
    queries = list()
    for i in range(1, number + 1):
        query = f"insert {i} {1900 + i} {'c'*32}{i} {'m'*128}{i} {i*100}"
        # print("inserting query -> %s" % (query))
        queries.append(query)
    queries.append("select")
    queries.append(".exit")
    queries.append("")
    output = run_queries(queries)
    # print(output)

    # print("\n----------------------\n")

    expected_output = list()
    for _ in range(1, number + 1):
        expected_output.append("spdb > Executed.")
    expected_output.append(f"spdb > (1, 1901, {'c'*32}1, {'m'*128}1, 100.000000)")
    for i in range(2, number + 1):
        expected_output.append(f"({i}, {1900 + i}, {'c'*32}{i}, {'m'*128}{i}, {i*100:.6f})")
    expected_output.append("Executed.")
    expected_output.append("spdb > ")
    for eo in expected_output:
        print(eo)

    # print("ouput.split('\\n') == expected_output: ", output.split('\n') == expected_output)

    output_lst = output.split('\n')
    for count, _ in enumerate(expected_output):
        print("output => ", output_lst[count])
        print("expected_output => ", expected_output[count])
        print(output_lst[count] == expected_output[count])
        print()
    return output.split('\n') == expected_output

if __name__ == "__main__":
    number = 1
    scount = 0
    start_time = time.time()
    try:
        for i in range(1, number + 1):
            current_random_num = random.randint(1, number + 1)
            if check_output(current_random_num):
                scount += 1
    except:
        pass
    end_time = time.time() - start_time
    print(f"{number} attempts, {number - scount} failed")
    print(f"total time taken: {end_time:.3f} secs")
