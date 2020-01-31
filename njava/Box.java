class Box{
  private int length, breadth, height;//these are instance member variable
  public void setDimension(int l, int b, int h)
  //These two functions are instance member function
  {
    length = l; breadth = b; height = h;}
    public void showDimension(){
        System.out.println("L="+length);
        System.out.println("B="+breadth);
        System.out.println("H="+height);
  }
}
class Example{
  public static void main(String[] args){
    Box setBox = new Box();
    setBox.setDimension(12,7,5);
    setBox.showDimension();
    setBox = new Box();//This will create a new object block for same reference
    //Old object will become garbage value
    setBox.showDimension();
  }
}
