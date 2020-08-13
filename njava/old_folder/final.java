/**final keyword is used in 5 places in javac

1. final instance variables
2. final static variables
3. final local variables
4. final classes
5. final method(instance member function)

  In java, no variable contains garbage value, either it is blank or gets default value according to there data type.(if not initialized)
  Now, final instance variable will be blank if not initialized but they will not get any default value.
1.
-> A java variable can be declared using the keyword final. Then the final variable can be assigned only once.
-> A variable that is declared as final and not initializd is called a blank final variable. A blank final variable forces either the constructors to initizlize it or initizlization block to do the job.

2. final static variable
-> Static member variable when qualified with final keyword, it becommes blank until initialized.
-> Final static variable can be initialized during declaration or within the static block.

3. final local variable
-> Local variables that are final must be initialized before it's use, but you should remember this rule is applicable to non final local variables too.
-> Once they are initialized, can not be altered.

4. final class
-> Java classes declared as final cannot be extended. Restricting inheritance!

5. final methods
-> Methods declared as final cannot be overridden.
