class parent{
  static int y = 4;
}
class child extends parent{
  static{y = 5;}//don't try to use static{this.y = 5;} as this is non-static variable
}
public class Example1{
  public static void main(String[]args){
    System.out.println("y = "+child.y);
    //No need for creating object of child class to call y
  }
}

/*class parent{
  static int y = 4;
}
class child extends parent{
  static int y;
  static{y = 5;}// only y = 5; is not working. Error = <identifier> expected
}
public class Example1{
  public static void main(String[]args){
    System.out.println("y = "+child.y);
  }
}*/
