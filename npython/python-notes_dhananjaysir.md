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
