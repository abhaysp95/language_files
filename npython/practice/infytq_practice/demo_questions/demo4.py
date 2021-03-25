#!/usr/bin/env python3

class Pet:
    def __init__(self, name, preferred_food):
        self.name = name
        self.preferred_food = preferred_food

    def eats_food(self):
        print("Pet eats the desired food:", self.preferred_food)

class Cat(Pet):
    def __init__(self, name, preferred_food, game):
        # super().__init__(self, name, preferred_food)  # question has passed self here, which it shouldn't
        # but since options doesn't contain any type of option for this TypeError, so we'll ignore it too
        super().__init__(name, preferred_food)
        self.game = game

    def eats_food(self):
        super().eats_food()
        print("Cat eats the desired food:", self.preferred_food)

    def favorite_game(self):
        print("The favorite game of ", self.name, "is", self.game)
        self.eats_food()

pet = Pet("Reena", "Bone")
cat = Cat("Chaplin", "Fish", "catch")
cat.favorite_game()
