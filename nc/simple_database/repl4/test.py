#!/usr/bin/env python3

import subprocess
# from timeit import timeit
import time

def runQueries(commands):
    """ run the queries in repl and return output """
    # working
    proc = subprocess.Popen(['./bin/repl4'],
                            stdin=subprocess.PIPE,
                            stdout=subprocess.PIPE,
                            encoding="ASCII")
    output = proc.communicate('\n'.join(commands))[0]
    return output

# working
# proc = subprocess.run(['./bin/repl4'], capture_output=True, text=True, input="\n".join(commands))
# print(proc.stdout)

# add a "" at last, so that when joining it'll add a newline char and it will
# used an "return(enter)" after '.exit' for repl
def checkOutput():
    """ provide queries and match output """
    query = ["insert 1 1969 dodge charger 720", "select", ".exit", ""]
    output = runQueries(query).split('\n')
    expected_output = ["spdb > Executed.",
                       "spdb > (1, 1969, dodge, charger, 720.000000)",
                       "Executed.",
                       "spdb > "]
    scount = 0
    fcount = 0
    if output == expected_output:
        scount += 1
    else:
        fcount += 1
    # for l1, l2 in zip(output, expected_output):
        # print("l1: %s, l2: %s ,done" % (l1, l2))
        # print(l1 == l2)
    return [scount, fcount]

if __name__ == "__main__":
    # total_time = timeit(lambda: checkOutput(), number=2)
    # print(f"total time taken: {total_time:.3f} secs")
    count = 0
    number = 2
    start_time = time.time()
    try:
        for _ in range(number):
            if checkOutput():
                count += 1
    except:
        pass
    time_taken = time.time() - start_time
    print(f"{number} runs, {number - count} failures")
    print(f"Total time taken: {time_taken:.3f} secs")
