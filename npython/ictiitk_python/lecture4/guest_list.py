#!/usr/bin/env python

"""
Author: Abhay Shanker Pathak
Date: 2020-02-02
Description: Creating a guest list
Email: abhaysp9955@gmail.com
Last Edited: 2020-02-02
"""

guest_list = ['Ironman', 'Thor', 'Arrow']
print(f"Genius, billionaire, playboy, philanthropist, what could I say for you {guest_list[0]}, I would like you to come at my place and some food.\n")
print(f"O {guest_list[1]}, God of Thunder, What's your say on a grand feast at my place\n")
print(f"Oliver Queen or should I say green {guest_list[2]}, You with your family are invited by me for dinner at my place.\n")

busy = guest_list.remove('Thor')
print(f"{busy}, son of Odin, I understand that you are busy but you should have come to my house and enjoy some 'Creature Comforts', don't you think")
print(f"Anyway, {guest_list[0]} and {guest_list[1]} are on the way to my house.")

guest_list.insert(0,'Captain Rogers')
guest_list.insert(3,'Aquaman')
guest_list.append('Geralt of Rivia')
a = len(guest_list)-1
# print(guest_list)

print(f"Okk guests, some other very important persons are joining the dinner here.\n")
print(f"So, please welcome {guest_list[0]}, who is also going to say prayer for dinner.\n")
print(f"Our next guest is {guest_list[3]}, King of the seven seas. Please welcome him and his almighty trident.\n")
print(f"And now welcome {guest_list[a]} who posses some amazing skills with swords and in hand to hand combat")

a = guest_list.pop()
b = guest_list.pop()
c = guest_list.pop()

print(f"Now, there's some unattended work which {a}, {b} and {c} have to attend. They are very pleased by having dinner with me. I am also thankful to them.")

d = len(guest_list)
for i in range(d):
    if i==d-1:
        print("and", end='') # end='' doesn't takes the output to next line
    print(f"{guest_list[i]}, ", end='')
print("are still with us.")
