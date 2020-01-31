package pack1;
import pack2.Student;//Use pack2.*; if you want to all the class files of that package

public class MStudent{
  public static void main(String []args){
    Student s1 = new Student();
    s1.setRollNo(45);
    s1.setName("Abhay Shanker Pathak");
    System.out.println("Roll no. is - "+s1.getRollNo());
    System.out.println("Name is - "+s1.getName( ));
  }
}
