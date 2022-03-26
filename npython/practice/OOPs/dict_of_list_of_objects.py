#!/usr/bin/env python3

class Customer:
    def __init__(self, cust_id, cust_name, location):
        self.cust_id = cust_id
        self.cust_name = cust_name
        self.location = location

list_of_customers = [
        Customer(101, 'Mark', 'US'),
        Customer(102, 'Jane', 'Japan'),
        Customer(103, 'Kumar', 'India')
        ]

dict_of_customers = {}

for customer in list_of_customers:
    dict_of_customers[customer.location] = customer

for key, value in dict_of_customers.items():
    print(key, value.cust_name)
