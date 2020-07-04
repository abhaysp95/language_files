#!/usr/bin/env python


def operationOnFileContent(fname):
    fhand = open(fname, 'r')

    data_dict = dict()

    for line in fhand:
        if not line.startswith('From '):
            continue
        # words = line.strip().split()
        words = line.split()
        if len(words) < 3:
            continue
        data_dict[words[1]] = data_dict.get(words[1], 0) + 1
    return data_dict

# we can also sort the values and put in list and then create a list with
# matching values and then print it, but here's another method


def sort_dict(res_dict):
    data_list = list()
    for key, value in res_dict.items():
        data_list.append((value, key))

    data_list.sort(reverse=True)
    return data_list[:]


def main():
    res_dict = operationOnFileContent(input('Enter the filename: '))
    res_list = sort_dict(res_dict)
    print('\n{}: {}\n'.format(res_list[0][0], res_list[0][1]))


if __name__ == "__main__":
    main()
