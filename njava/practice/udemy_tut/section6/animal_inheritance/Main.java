package com.animalinheritance;

public class Main {
	public static void main(String ...args) {
		Animal animal = new Animal("Animal", 1, 1, 5.5, 43.3);

		Dog dog = new Dog("Sheru", 0.34, 34.6, 2, 2, 4, 1, 42);
		System.out.println("Dog's name: " + dog.getName());
		System.out.println("Dog's size: " + dog.getSize());
		System.out.println("Dog's weight: " + dog.getWeight());
		dog.eat();
		dog.move(3.4);

		Fish fish = new Fish("Nemo", 0.016, 0.078, 2, 1, 1);
		System.out.println("Fish's name: " + fish.getName());
		fish.rest();
		fish.swim(8.7);
	}
}
