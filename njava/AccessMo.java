import world.*;

class Trial{
  public static int i=3;
  public static int num(){
    i = i + 3;
return 0;}
}
public class AccessMo{
  public static void main(String args[]){
    Trial t1 = new Trial();
    System.out.println("This is trial " +args[0]+" " +args[1]+" "+args[2]+ " "+args[3]+ " and " +t1.i);//Unable to get ouptut 6.

  }
}
