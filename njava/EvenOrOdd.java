import java.util.Scanner;

public class EvenOrOdd{
  public static void main(String args[]){
    int num;
    System.out.println("Enter the number to check out - ");

    //The input number will be stored in num
    Scanner input = new Scanner(System.in);
    num = input.nextInt();

    //Now, basic logic for even or odd checking
    if(num%2 == 0)
      System.out.println("Input number is Even.");
    else
      System.out.println("Input number is Odd.");
  }
}
