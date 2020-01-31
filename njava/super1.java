//parent class
class A{
  int z;
  public void f1(){
    System.out.println("I'm in super class");
  }
}
//child class
class B extends A{
  int z;
  //instance member function
  public void f1(){
    System.out.println("I'm in child class");
    super.f1();
        //this;//these two(this and super present in this method) are already created and destroyed as this f2 closes
    //f1();//Now, here child function will work and be recursion will call itself
  //  this.f1();//It will also access B class
    //So, to call method of parent from child we use super(if the name of methods are same)
  //  super.f1();
  }
  public void f2(){
    int z;
    z = 2;
    this.z = 4;//for instance variable of class B from obj
    super.z = 8;//for class A
    System.out.println("Sum"+z+this.z+super.z);
  }
  public void f3(){
    System.out.println("I'm in another child class");
    this.f1();//this is storing reference of object new B();
    this.f2();
  }
}

class super1{
  public static void main(String []args){
    B obj = new B();
    obj.f1();
    obj.f2();
    obj.f3();

    //A obj1 = new B();//This means, reference variable of class(which is obj1) can store the reference of object of B class(object is new B()). This line is perfectly fine. Means reference of parent and object of child.
    //Here, rule is now reference variable obj1 can only access the members of parent class not of child class
  }
}
