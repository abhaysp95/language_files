/**class Box{
  //instance member variable
  private int l, b, h;
  //instance member method
  public void SetDimension(int x, int y, int z){
    l = x; b = y; h = z;//here, 'this' named reference variable is already created whether you use it or not. And, here 'this' reference variable is containing the reference of the caller object means 'obj' object in this case.
  }
}
public class ThisKey{
  //main is static member function
  public static void main(String[] args){
    Box obj = new Box();//here obj is reference variable which is contatining the referece of the Box class
    //Here, obj is caller object as SetDimension is called for this object
    obj.SetDimension(12,10,5);
  }
}*/

class Box{
  int l,b,h;
  public void setDimension(int l, int b, int h){
    this.l = l; this.b = b; this.h = h;
      System.out.println(+l" "+b" "+h);
  }//now, if local variable are replaced with the name of instance variable then to remove confusion, this keyword is used. So, this.l means instance variable l. Here, local variable will get more preference that's why to run the program correctly this is used.
  //Lets now create second class named GiftTaker, now
  public void sendBox(){
    GiftTaker gt = new GiftTaker();
    gt.acceptGift(this);//here 'this' means we are passing caller object b1 to acceptGift() method from sendBox() method
  }
}
public class ThisKey{
  public static void main(String[] args){
    Box b1 = new Box();
    b1.setDimension(20,15,10);
    System.out.println(+b1.l+b1.b+b1.h);
  }
}
