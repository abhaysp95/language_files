#!/usr/bin/env python3

from sys import exit

class Knapsack:
    def __init__(self, profit_list = None, weight_list = None):
        self.profit = profit_list
        self.weight = weight_list
        self.pw_ratio = None

    def calculate_profit_weight_ratio(self):
        # first check if provided profit and weight are actually lists
        if isinstance(self.profit, list) and isinstance(self.weight, list):
            self.pw_ratio = list(map(lambda p, w: p / w, self.profit, self.weight))
        else:
            print("Provide the list of profit and weights")
            exit(1)

    def sort_according_to_pw_ratio(self):
        self.profit, self.weight, self.pw_ratio = zip(*sorted(zip(
            self.profit, self.weight, self.pw_ratio), reverse=True))
        # self.pw_ratio, self.weight, self.profit = zip(*sorted(zip(
            # self.pw_ratio, self.weight, self.profit), reverse=True))


def get_profit(knapsack, capacity) -> float:
    count = 0
    profit = 0
    while capacity != 0:
        if capacity < knapsack.weight[count]:
            capacity = 0
            partition = capacity / knapsack.weight[count]
            profit += knapsack.profit[count] * partition
        else:
            capacity -= knapsack.weight[count]
            profit += knapsack.profit[count]
        count += 1
    return profit

def main():
    knapsack = Knapsack([8, 56, 53, 74, 51, 94, 72, 14, 64, 12],
            [24, 44, 27, 54, 37, 67, 39, 28, 47, 25])
    knapsack.calculate_profit_weight_ratio()
    print("profit: ", knapsack.profit)
    print("weight: ", knapsack.weight)
    print("pw_ratio: ", knapsack.pw_ratio)
    print("type: ", type(knapsack.pw_ratio))
    print("---------------------------------------------------------------------")
    knapsack.sort_according_to_pw_ratio()
    print("profit: ", knapsack.profit)
    print("weight: ", knapsack.weight)
    print("pw_ratio sorted: ", knapsack.pw_ratio)
    print("type: ", type(knapsack.pw_ratio))
    weight_limit = int(input("Enter capacity: "))
    profit = get_profit(knapsack, weight_limit)
    print("profit is: ", profit)

main()
