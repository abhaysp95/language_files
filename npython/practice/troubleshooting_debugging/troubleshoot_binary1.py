#!/usr/bin/env python3

'''
same question with different approach(no need for sorting)
'''

def find_item(list, item):
    '''find the item in list'''
    if len(list) == 0:
        return False

    middle = len(list) // 2
    if list[middle] == item:
        return True
    if item in list[:middle]:
        return find_item(list[:middle], item)
    else:
        return find_item(list[middle + 1:], item)
    return False



list_of_names = ["Parker", "Drew", "Cameron", "Logan", "Alex", "Chris", "Terry", "Jamie", "Jordan", "Taylor"]

print(find_item(sorted(list_of_names), "Alex")) # True
print(find_item(sorted(list_of_names), "Andrew")) # False
print(find_item(sorted(list_of_names), "Drew")) # True
print(find_item(sorted(list_of_names), "Jared")) # False
