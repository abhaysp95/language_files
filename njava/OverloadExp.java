//Here are versions of function overloading example

/**1. When one method is in parent and other in child class

  class A{
  //calling a function or method in parent class
  public void f1(int x){
    System.out.println("Class A");
  }
}
class B extends A{
  //calling a  function or method in child class
  public void f1(int x, int y){
    System.out.println("Class B");
  }
}
public class OverloadExp{
  public static void main(String []args){
    B obj = new B();
    obj.f1(15);
    obj.f1(14,28);
  }
}*/

/*In C++, fuction overloading is known as function hiding as child function hides the parent function. There we can only access child version not parent, but this is not the case with Java.*/

/**2. In this version of function overloading, there are two methods in parent class and one in child class and it is still method oveloading.


  class A{
  public void f1(int x){
    System.out.println("Class A");
  }
  public void f1(int x, int y){
    System.out.println("Class A1");
  }
}
class B extends A{
  //creating a blank class which inherits the property of class A
  public void f1(int x, int y, int z){
    System.out.println("Class B");
  }
}
public class OverloadExp{
  public static void main(String[] args){
    B obj = new B();
    obj.f1(45);
    obj.f1(778,45);
    //If you pass two same name function with two arguments(it means method overriding) then it will use that class whose object it is. I think so.
    obj.f1(45,89,69);
    //Created a 3 argument function in child class, so now when fuction calls it will go to that class from there it'll match the number of arguments passed and will access that method.
  }
}*/

class A{
  //Creating a blank parent class
}
class B extends A{
  public void f1(int x){
    System.out.println("Class B1.");
  }
  public void f1(int x, int y){
    System.out.println("Class B2.");
  }
  //Now, two methods with same number of arguments will not compile if they are in same class, they will compile if they are different clas. You can see this in version 2 of this program.
/**  public void f1(int x, int y){
    System.out.println("Class B3.");
  }*/
  public void f1(int x, int y, int z){
    System.out.println("Class B4.");
  }
}
public class OverloadExp{
  public static void main(String[] atgs){
    B obj = new B();
    obj.f1(45);
    obj.f1(45,69);
    //obj.f1(65,49);
    obj.f1(45,69,76);
  }
}
