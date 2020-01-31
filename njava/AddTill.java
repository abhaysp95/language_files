/**Print the sum between two given numbers including themselves*/

import java.util.Scanner;

class Sum{
  public int p = 0;
  public void GetSum(int a, int b){
    p = ((a+b)*(Math.abs(a-b)+1)/2);
    //return p;//This is Euler's logic to calculate sum
  }
}

public class AddTill{
  public static void main(String[] args){
    int m,n;
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the two desired integers - ");
    m = sc.nextInt();
    n = sc.nextInt();
    Sum s = new Sum();
    s.GetSum(m , n);
    System.out.println("Result "+s.p);
  }
}
