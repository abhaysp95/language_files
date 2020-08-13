/**Command Line Arguments
  When we inittialize program from command prompt and that time we can pass some arguments at that time and these are passed in main fn recived by String[] args, here args is reference variable referring to an array*/

  public class commandLineArg{
    public static void main(String []args){
      int s = 0;
      for(int i = 0; i<args.length; i++)//In java, array has a length variable which will change according to how much arguments user has passed to main function
      {s = s + Integer.parseInt(args[i]);
      System.out.println(args[i] +" and sum is "+s);
    }}
  }

/**Let's take example of adding by CLI, so if it is written as

  int s = 0;
    for(int i= 0; i < args.length; i++)
      s = s + args[i];

    This is wrong, as s is in int and args is String type defined in main fn, so to not concatinate we will use wrapper classes
      s = s + Integer.parseInt(args[i]);
    I'm making this change in above program*/
