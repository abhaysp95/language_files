import java.util.Scanner;

class C1{
  int b, i=0, j=0, c = 0;
  int b1[] = new int[20];
  int arr[] = new int[20];
  //Creating a constructor for converting dec to bin
  public C1(){
    Scanner sc = new Scanner(System.in);
    System.out.println("Enter the no. in decimal - ");
    b = sc.nextInt();
    System.out.println("Entered - "+b);
    while(b!=0){
      arr[i++]=b%2;
      b/=2;
    }
    i-=1;
    while(i>=0)
      b1[j++] = arr[i];c++;
      System.out.print(+arr[i--]);
    System.out.println("\n");
    while(c>=0)
      System.out.println(b1[c--]);
  }
}
public class BinConvAdd{
  public static void main(String[] args){
    //Scanner sc = new Scanner(System.in);
    //Running constructor for first decimal to binary conversion
    C1 obj1 = new C1();
    //Running constructor for second decimal to binary conversion
    C1 obj2 = new C1();
    System.out.println("output "+obj1.b);
    System.out.println(obj2.b);
  }
}


/*To pass try , creating another class and in it another object and in the C1 class create object of that method from other class and call it with 'this' keyword.*/
