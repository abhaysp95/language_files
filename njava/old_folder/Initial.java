public class Initial{
  private int x;{
    System.out.println("Initialization Block: x="+x);
    x = 5;
  }
  public Initial(){
    System.out.println("Constructor: x="+x);
  }
  public static void main(String []args){
    Initial i1 = new Initial();
    Initial i2 = new Initial();//the value of x in Initialization will again be 0, x will differnet for every object
  }
}
