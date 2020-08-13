/**There are two types of initialization blocks-
    instance initialization block
    static initialization block
1.
Instance initialization block runs when we create object of that class

You can create more than one initialization block, compiler turns them into one and run in sequence and constructor initial lines will be of initialization block's initial lines

Also known as instance initializer or initialization block, no name block in class, is same as function but has no return.

Instance initializers are permitted to refer to the current object via the keyword this and to use the keyword super(if has any parent class)

2.
Structure is same as Instance initialization block, only static keyword is used just above the block(also static in the statement above the block).

This block can only access static members of class not instance members.

This type of block can also be more than one, but compiler will rearrange it to one.

Useful when we want to execute a code just before object is started.

Unlike instance initialization block, static initialization block runs only one time in a class.

Runs when an object of class is created, or to access a member which is static by using its class name
