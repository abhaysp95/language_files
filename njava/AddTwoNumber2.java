import java.util.Scanner;
public class AddTwoNumber2{
  public static void main(String []args){
    int a,b,sum;
    Scanner sc = new Scanner(System.in);// Creating object of Scanner class, but what is System.in?
    System.out.println("Enter first number -");
    a = sc.nextInt();//assigning a = ? I think nextInt() is a function under Scanner class for sc object

    System.out.println("Enter second number -");
    b = sc.nextInt();

    sc.close();//Don't know why this line is though
    sum = a + b;
    System.out.print("Sum will be - "+sum);
  }
}
