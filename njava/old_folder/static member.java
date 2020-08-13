public class example{
  int x;//Instance variable - which will be in the object of example class
  static int y;//Static member variable. It has some value and not blank. These are created once for whole class. It contains class specific info.

  public void fun1(){}//Instance member function - which can only be called by the object of example class
  public static void fun2(){} //static member function, not for object but for whole class
  /**We can't create a static variable inside a function in java
    eg., public void fun1(){static int a;} This is wrong*/

  /**We can have static inner class, like this*/
    static class test{//This is static inner class, inner class can be qualified with the keyword static
      public static String country = "India";
}
  public static void main(String[] args){
      example ex1 = new example();//This will contain x but not y
      example ex2 = new example();//This will also contain x but not y

      /*To access static members in java*/
      example.y=5;//If we not write this line, then y = 0 by default
      /*To access static members in java*/
      example.fun2();
      //Static member function can only access static member
      /*like public static void fun2() { x = 4; }. This is wrong, while
       publlic static void fun2() { y = 4; } . This is correct.*/

       /**Now main function is also a static function so it also can't directly use x, fun1() but can access y,fun2(). So, we can also directly write this instead of example.y=5;*/
       y=5;//Also this correct because main is the member function of the same class.
}
       /*Java can't contain two public class in same program*/
       //Now, lets create another class

       //Remove public and main from example class. main() will be on this class now
       public class Hello{
         public static void main(Stirng[] args){
           example.y=5;
           //Now, let that, y from 3rd line is private,
           //private static int = y; now, private variable can't be accessed out of that class body.
           //So, y can be accessed by fun2() function as it is public and also Static
           example.fun2();
           example.test.country;//Calling a static class and its member from another class
           //or to print it we can write it in this way
           System.out.println("Value "+example.test.country);
           //here System is a predefined class(maybe static) and out is its static member
         }
       }
       /**Now, take another example.
       There is a class named account
       class Account{
          int ac, balance;
          static int rate;
     }
        Now, here ac and balance will be different for every account-holder and will get its different value in every object, but rate will be same for everyone as it is static and used for whole class. So, we don't create object for rate and someone asks for rate then no problem, value will be stored in static rate variable.
}
