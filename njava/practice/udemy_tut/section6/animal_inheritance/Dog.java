package com.animalinheritance;

public class Dog extends Animal {
	private int eyes;
	private int ears;
	private int legs;
	private int tails;
	private int teeth;

	public Dog(String name, double size, double weight, int eyes, int ears, int legs, int tails, int teeth) {
		super(name, 1, 1, size, weight);  //calling constructor of parent class
		this.eyes = eyes;
		this.ears = ears;
		this.legs = legs;
		this.tails = tails;
		this.teeth = teeth;
	}

	private void chew() {
		System.out.println("chewing its food");
	}

	// override Animal.eat()
	@Override
	public void eat() {
		System.out.print("Dog eats by ");
		chew();
		super.eat();  // another thing to note
		/* if calling super.eat() it will always call eat() method of parent class, but if just say eat() then it'll look for eat() method in this class else it will look in parent class if it's extended */
	}

	// movement
	private void walk(double speed) {
		System.out.println("Dog walks at " + speed);
	}
	private void run(double speed) {
		System.out.println("Dog runs at " + speed);
	}
	private void moveLegs() {
		System.out.println("Dog can move legs");
	}

	// method overriding(we can't override static method only instance method unlike of method overloading)
	@Override
	public void move(double speed) {
		walk(3.2);
		run(23.7);
		moveLegs();
		// we can call super.move() to execute parent's move() method
	}
}

// methods can be overriden only in the child class(means inherited methods can be overriden)
// constructors and private methods can't be overriden
// Methods that are final also can't be overriden
// A subclass can use 'superclass.methodName()' to call the superclass version of overriden method

/* Covariant return type

   class Burger {
   .....................
   }

   class HealthyBurger extends Burger {
   ..................................
   }

   class BurgerFactory {
		public Burger createBurger() {
			return new Burger;
		}
   }

   class HealthyBurgerFactory extends BurgerFactory {
		@Override
		public HealthyBurger createBurger() {
			return new HealthyBurger;
		}
   }
*/
