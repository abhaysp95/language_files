# Some topics that I noted:

## Class and Object:

Let's first see the syntax:
```python
In [14]: class Mobile:
    ...:     def __init__(self, company, money, build):
    ...:         self.company=company
    ...:         self.price=money
    ...:         self.model=build
    ...:     def show(self):
    ...:         print("Company name="+self.company)
    ...:         print("Price=",self.price)
    ...:         print("Model="+self.model)

In [15]: obj1=Mobile("Nokia", 12000, "A6 plus")

In [16]: obj1.show()
Company name=Nokia
Price= 12000
Model=A6 plus
```

In the above syntax, we are defining a class named `Mobile` and in that class we are starting a `constructor` **self**.

We are also passing some variables as `parameter`, they are:
* company
* money
* build

Then we are creating attributes for those variables as,
* self.company
* self.price
* self.model

Then creating a function of that class. And then we created a object `obj1` by passing appropriate **parameters**.

# Programming Approach:
It means what will be the procedure of solving any problem. It could be of two types-
1) Procedural Approach - It means solving problem step by step
2) Object Oriented Approach

## Object Oriented Programming System-
	It is based on real life concepts. The basic concepts of OOPs are-
	1. Class
	2. Object

* **Class** - It is like a blueprint or prototype. A class contains two things-
	- Attributes
	- Behaviour
		Attributes specifies the properties of the system while behaviour specifies the functionality.

ex.

class human {
	mind, hands, legs, eyes........, } Attributes
	---
	thinking()
	working()			=> Behaviours
	walking()
	vision()
}

* **Object**- These are instances of class. They contains all the properties & methods whatever is defined inside the class.
	They are the active entities which directly interact with the external environment.

| **Class** | **Object**               |
| :---:     | :---:                    |
| Car       | Maruti-800               |
| Mobile    | Nokia-X6, Samsung Galaxy |
| Pen       | Raynold Jetter           |
| Dog       | Tommy                    |

## Features of OOPs-

1. Encapsulation & Abstraction
2. Polymorphism
3. Inheritance
4. Message Passing

**Encapsulation** - This is the concept of data hiding.
Is says represent only the essential information infront of the user.

*Abstraction** - This is the concept of mechanism hiding.

**OR**

To using any thing without knowing the background details of that thing is known as abstraction.

**Polymorphism** - This is concept of one to many, when an entity perform different operations on different occasions
then we can say entity implements the Polymorphism.

**Inheritance** - This is the concept of reusability.

**Message Passing** - This is concept of runtime communication of the objects.
