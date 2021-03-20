#!/usr/bin/env python3

class Node:
    def __init__(self, value):
        self.__data = value
        self.__next = None

    def get_data(self):
        return self.__data

    def get_next(self):
        return self.__next

    def set_data(self, data):
        self.__data = data

    def set_next(self, node):
        self.__next = node

