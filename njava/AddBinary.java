import java.util.Scanner;

public class AddBinary{
  public static void main(String[] args){
    int i=0, carry = 0;
    long b1, b2;//Variables to hold binary valueOf

    //Declaring sum as array
    int[] sum = new int[10];//This is one of the type to declare array in javac

    //Taking input as binary from user
    Scanner scan = new Scanner(System.in);
    System.out.println("Enter the first binary number - ");
    b1 = scan.nextLong();

    System.out.println("Enter the second binary number - ");
    b2 = scan.nextLong();

    //closing scanner to avoid memory leak
    scan.close();

    //Putting logic
    while(b1!=0||b2!=0){
      sum[i++] = (int)((b1%10 + b2%10 + carry)%2);
      carry = (int)((b1%10 + b2%10 + carry)/2);
      b1/=10;
      b2/=10;
    }

    if(carry!=0)
      sum[i++] = carry;
    i-=1;
      
    System.out.println("Output in binary is - ");
    while(i>=0)
      System.out.print(sum[i--]);
      System.out.println("\n");
  }
}
