import java.util.Scanner;

public class DecToBin{
  public static void main(String[] args){
    int d1, i=0, j=0;
    int[] b1 = new int[20];

    Scanner Scan = new Scanner(System.in);
    System.out.println("Enter the number in decimal - ");
    d1 = Scan.nextInt();
    Scan.close();

    while(d1!=0){
      b1[i++] = d1%2;
      d1/=2;
    }
    i-=1;

    if(i>3 && i<8){
      j = 7 - i;
      while(j>0)
        b1[i++] = 0;
    }

    if(i>7 && i<16){
      j = 15 - i;
      while(j>0)
        b1[i++] = 0;
    }

    System.out.println("Binary output is - ");
      while(i>=0)
        System.out.print(b1[i--]);
      System.out.println();
  }
}
