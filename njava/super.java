/* In inheritance, subclass object when call an instance member function of subclass only, function contains implicit reference variables this and super both referring to the current object(Object of subclass).

-> The only difference in this and super is
    this reference variable is of subclass type
    super reference variable is of superclass type

-> If your method overrides one of its superclass's methods, you can invoke the superclass version of the method(the overriddenmethod) through the use of the keyword super.
-> It avoids name conflict between member variables of superclass and subclass.  
