#!/usr/bin/env python

# histogram using dictionary through mail log

def get_dict(fname):
    try:
        fhand = open(fname, 'r')
    except:
        print('File %s not found' % fname)

    dict_is = dict()
    for line in fhand:
        line = line.strip()
        if not line.startswith('From'):
            continue
        words = line.split()
        if len(words) < 2:
            continue
        dict_is[words[1]] = dict_is.get(words[1], 0) + 1  # 0 + 1
    return dict_is


def main():
    res_dict = get_dict(input('Enter the filename: '))
    print(res_dict)


if __name__ == "__main__":
    main()
