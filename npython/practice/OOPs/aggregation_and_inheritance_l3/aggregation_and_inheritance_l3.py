#!/usr/bin/env python3

class Customer:
    def __init__(self, customer_name, quantity):
        self.__customer_name = customer_name
        self.__quantity = quantity

    def get_customer_name(self):
        return self.__customer_name

    def get_quantity(self):
        return self.__quantity

    def validate_quantity(self):
        if self.__quantity >= 1 and self.__quantity <= 5:
            return True
        else:
            return False

    def __str__(self):
        return "Name: %s, quantity: %d" % (self.__customer_name, self.__quantity)

class PizzaService:
    counter = 100
    def __init__(self, pizza_type, additional_topping, customer):
        self.__pizza_type = pizza_type
        self.__additional_topping = additional_topping
        self.__customer = customer
        self.__service_id = None
        self.pizza_cost = None

    def get_service_id(self):
        return self.__service_id

    def get_pizza_type(self):
        return self.__pizza_type

    def get_customer(self):
        return self.__customer

    def get_additional_topping(self):
        return self.__additional_topping

    def validate_pizza(self):
        if self.__pizza_type.lower() == "small" or self.__pizza_type.lower() == "medium":
            return True
        else:
            return False

    def calculate_pizza_cost(self):
        if self.validate_pizza() and self.__customer.validate_quantity():
            if self.__pizza_type == "small":
                self.pizza_cost = 150
                if self.__additional_topping:
                    self.pizza_cost += 35
            elif self.__pizza_type == "medium":
                self.pizza_cost = 200
                if self.__additional_topping:
                    self.pizza_cost += 50
            PizzaService.counter += 1
            self.__service_id = self.__pizza_type[0] + str(PizzaService.counter)
        else:
            self.pizza_cost = -1

class Doordelievery(PizzaService):
    def __init__(self, distance_in_kms, pizza_type, additional_topping, customer):
        super.__init__(pizza_type, additional_topping, customer)
        self.__delivery_charge = None
        self.__distance_in_kms = distance_in_kms

    def get_delivery_charge(self):
        return self.__delivery_charge

    def get_distance_in_kms(self):
        return self.__distance_in_kms

    def validate_distance_in_kms(self):
        if self.__distance_in_kms >= 1 and self.__distance_in_kms <= 10:
            return True
        else:
            return False

    def calculate_pizza_cost(self):
        if self.validate_distance_in_kms():
            super().calculate_pizza_cost()
            if self.__distance_in_kms <= 5:
                self.__delivery_charge = self.__distance_in_kms * 5
            elif self.__distance_in_kms > 5:
                self.__delivery_charge = (self.__distance_in_kms - 5) * 7 + 5 * 5
            self.pizza_cost += self.pizza_cost + self.__delivery_charge
        else:
            self.pizza_cost = -1

p = PizzaService("small", True, Customer("Me", 4))
d = Doordelievery(7, "medium", True, Customer("Myself", 3))
print(p.get_customer())
print(p.get_pizza_type())
print(p.get_service_id())
print(p.pizza_cost)

print(d.get_customer())
print(d.get_service_id())
print(d.get_pizza_type())
print(d.get_delivery_charge())
print(d.pizza_cost)
