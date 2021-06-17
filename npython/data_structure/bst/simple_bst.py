#!/usr/bin/env python3

class node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def insert(root, data):
    if root is not None:
        if data < root.data:
            if root.left is None:
                root.left = node(data)
            else:
                insert(root.left, data)
        else:
            if root.right is None:
                root.right = node(data)
            else:
                insert(root.right, data)
    else:
        root = node(data)

# preorder traversal
def traverse(root):
    if root is None:
        return;
    print(root.data)
    traverse(root.left)
    traverse(root.right)

# inorder traversal with stack(actually, list)
def inorder_stack(root):
    stack = list()
    node = root
    while True:
        if len(stack) == 0 and node is None:
            break
        else:
            # print("len:",len(stack))
            if node is not None:
                stack.append(node)
                node = node.left
            else:
                node = stack.pop()
                print(node.data)
                node = node.right

def preorder_stack(root):
    stack = list()
    node = root
    while True:
        if len(stack) == 0 and node is None:
            break
        else:
            if node is not None:
                print(node.data)
                stack.append(node)
                node = node.left
            else:
                node = stack.pop()
                node = node.right

def peek(lst):
    if len(lst) >= 1:
        return lst[len(lst) - 1]

def postorder_stack(root):
    stack = list()
    node = root
    prev_pop=0
    while True:
        if len(stack) == 0 and node is None:
            break
        else:
            if node is not None:
                if node.right is not None:
                    stack.append(node.right)
                stack.append(node)
                node = node.left
            else:
                node = stack.pop()
                # print("size:", len(stack))
                if node.right is not None \
                        and (peek(stack) is not None \
                        and node.right.data == peek(stack).data):
                    nr = stack.pop()
                    stack.append(node)
                    node = nr
                else:
                    print(node.data)
                    node = None


def preorder_stack2(root):
    stack = [root]
    while True:
        if node is not None:
            print(node.data)
            if node.right is not None:
                stack.append(node.right)
            if node.left is not None:
                stack

nodes = list(map(int, input().split(',')))
root = None
for d in nodes:
    print("inserting:", d)
    if root is None:
        root = node(d)
    else:
        insert(root, d)
postorder_stack(root)
