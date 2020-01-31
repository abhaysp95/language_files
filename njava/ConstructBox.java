public class ConstructBox{
  private int l, b, h;
  public ConstructBox(){
    l = 10; b = 8; h = 4;
  }
  public ConstructBox(int L, int B, int H){
    l = L; b = B; h = H;
  }
  public static void main(String []args){
    ConstructBox b1 = new ConstructBox();
    System.out.println("First result "+b1.l+" " +b1.b+" " +b1.h);
    ConstructBox b2 = new ConstructBox(20 , 15, 10);
    System.out.println("Second result "+b2.l+" " +b2.b+" " +b2.h);
  }
}
/* A constructor created by compiler looks like
public box(){}*/
