/**************
This is an example for final instance variable
**************/
/*
public class FinalKey1{
  private final int x; //final instance member variable(instance means of object)
  public static void main(String[] args){
    FinalKey1 f1 = new FinalKey1();//now x will get memory as its object is now created
    /*Now, here three methods to initialize this final instance
    1. private final int x = 5;
    2. By initialization block ->
            private final int x;{x=5;}
    3. By constructor
        private final int x;
        FinalKey1(){x=5;}
  }
}*/

/**********
final static variable
**********/
/*
public class FinalKey1{
  private static final int y;//final static member variable
  //As you know, local variable can't be made static only class variable
  static{y=10};//static initialization block
}*/

/*************
final local Variables
*************/
/*
public class FinalKey1{
  public void fun(){
    final int z;//local variable, local variable is blank by default. So, initialization is important other it will give error. Now, adding final.
    //Only difference, if I used final here is now we can't alter the value of local variable once it is initialized.
  }
}*/

/****************
final class
****************/
/*
final class Dummy//now, this class can't be extend. Extending the class means that if we inherit this class or make its sub class, it means we extends the class
{//no child class}*/

/***********
final methods
***********/
class Dummy{
  public final void SomeFunction(){
  }
}
class MoreDummy extends Dummy{
  //You can override or overload SomeFunction method in this child class but if we use final in the method in SomeFunction() then you can't override
  public void SomeFunction(){}//As now, final keyword is used in method, so it'll give error as no overloading.
}
