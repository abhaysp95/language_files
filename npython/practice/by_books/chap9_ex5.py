#!/usr/bin/env python

# print the domain name and there total sent mail count

def get_dict(fname):
    try:
        fhand = open(fname, 'r')
    except:
        print('File {} not found' % fname)
        exit()

    domain_dict = dict()
    for line in fhand:
        line = line.rstrip()
        if not line.startswith('From'):
            continue
        words = line.split()
        if len(words) < 2:
            continue
        domain_name = words[1].split('@')[1]
        # print(domain_name)
        domain_dict[domain_name] = domain_dict.get(domain_name, 0) + 1
    return domain_dict


res_dict = get_dict(input('Enter file name: '))
print(res_dict)
