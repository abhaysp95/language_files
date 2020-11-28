#!/usr/bin/env python3

import subprocess
import io




cat = subprocess.Popen(['cat', 'output.txt'], stdout=subprocess.PIPE)
grep = subprocess.Popen(['grep', '-n'], stdin=cat.stdout, stdout=subprocess.PIPE)
cut = subprocess.Popen(['awk', "'{print $9}'"], stdin=grep.stdout, stdout=subprocess.PIPE)
end_of_pipe = cut.stdout

print(end_of_pipe)








# p1 = subprocess.Popen(['grep', '-n', 'good'], stdin=subprocess.PIPE, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
# print(p1.stdout.read())  # deadlock cause, p1 is waiting for input and this line waiting to print output upto end
# stdout, stderr = p1.communicate(input=b'this is good\nthis is bad')
# print(p1.stdout.read())
# print(stdout.decode('UTF-8').strip())
# print(p1.poll())






# p1 = subprocess.run(['cat', 'output.txt'], stdout=subprocess.PIPE, text=True)

# p2 = subprocess.run(['grep', '-n', 'main'], stdout=subprocess.PIPE, text=True, input=p1.stdout)
# print(p2.stdout)





# p1 = subprocess.run(['ls', '-la', 'dne'], stderr=subprocess.DEVNULL)






# p1 = subprocess.run(['ls', '-la', 'dne'], capture_output=True, text=True, check=True)






# p1 = subprocess.run(['ls', '-la', 'dne'], capture_output=True, text=True)
# print(p1.stdout)
# print(p1.returncode)
# print(p1.stderr)




# with open("output.txt", 'w') as file:
    # subprocess.run(['ls', '-la'], stdout=file, text=True)



# p1 = subprocess.run(['ls', '-la'], stdout=subprocess.PIPE, text=True)
# print(p1.stdout)





# p1 = subprocess.run(['ls', '-la'], capture_output=True, text=True)
# print(p1.stdout)





# p1 = subprocess.run(['ls', '-la'], capture_output=True)
# print(p1.stdout.decode())



# p1 = subprocess.run(['ls', '-la'])
# print(p1.stdout)
