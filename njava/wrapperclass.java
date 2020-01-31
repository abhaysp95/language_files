/** Wrapper Classes = Java allows to include the primitives in the family of objects by using what are called wrapper classes. There is a wrapper class for every primitive data type in java
      Primitive type -> Wrapper classes
      boolean       ->    Boolean
      byte          ->    Byte
      char          ->    Character
      short         ->    Short
      int           ->    Integer
      long          ->    Long
      float         ->    Float
      double        ->    Double

    Useful methods of wrapper classes
    1. valueOf()
      -static method // this is a function for which object isn't needed to call this static method
      -Return Object reference of relative wrapper class
      eg,.*/
    public class Example{
      public Static void main(String[] args){
        Integer.valueOf("123");//here object isn't needed to call valueOf() function, and "123" is string. Here, valueOf() fn is of Integer class
        //Here, valueOf() will create object of Integer class and will put value 123 as integer not as string. So, we can also save it in variable of a integer type
        Integer i1 = Integer.valueOf("123");
        Double.valueOf("3.14")://This function is different for every wrapper class, here it is of Double class, but only we pass string in it
        Double d1 = Double.valueOf("3.14");//d1 is the reference variable of double which will contain the reference of Double class object.
        Integer i1 = Integer.valueOf("1111011",2);//here value is in binary form.
      }
    }

      /**2. parseXxx()
        - Here, Xxx means int, char, float etc. Static function same as valueOf(), and it returns Xxx type of value
          e.g.,
          */
        public class Example{
          public Static void main(String[] args){
            int a = Integer.parseInt("123");//Converts string in desired form, here converting in integer and returning primitive data type(int) of value
            double b = Double.parseDouble("3.14");
          }
        }
      /**xxxValue()
        -Instance method of wrapper classes
        -xxx can be replaced by any primitive type
        -returns corresponding primitive type
        e.g., */
        Integer i1 = Integer.valueOf("1111011",2);
        int c = i1.intValue();//used to copy the value of i1 from Integer class to primitive int
