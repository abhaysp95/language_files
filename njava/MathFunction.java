//import java.lang.*; //This class isn't important to import I think

import java.util.Scanner;

public class MathFunction{
  public static void main(String[] args){
    int a,b;
    Scanner scan = new Scanner(System.in);
    a = scan.nextInt();
    b = scan.nextInt();
    System.out.println("Absolute a "+Math.abs(a));
    System.out.println("Absolute b "+Math.abs(b));
    System.out.println("Maximum = "+Math.max(a,b));
    System.out.println("Minimum = "+Math.min(a,b));
  }
}
