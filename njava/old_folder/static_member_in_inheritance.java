/**Static member function*/

/*
-> A class C inherits from its direct superclass all concrete methods m(both static and instance) of the superclass.
-> No method declared in C(not C language) has same signature.

//Function hiding -
 -> If subclass has a method m with the same signature as of the method present in the superclass, then method m hides the method of superclass.
 -> The difference between overriding and function hiding is overriding does not use static while function hiding uses static function. Eg,.
            class child extends parent{
            public static fun(){}
          }

//Notes -
-> It's a compile-time error if a static method hides an instance method.
-> it's a compile-time error if an instance method overrides a static method.

-> Static member variables do not iherit, they hide.Eg,.
          Inheritance                           Hidiing

      class parent{                               class parent{
      static int y = 4;                           static int y = 4;
    }                                             }

    class child extends parent{                   class child extend parent{
    static{y=5;}                                  static int y;
  }                                               y = 5;
    public class Example{                         }
    public static void main(String[]args){        public class Example{
    System.out.println("y="+child.y);             public static void main(Str..){
    //this will print y = 4; It means that        System.out.println(child.y);
    y is not inherited. To print y = 5 see        //This will print y = 5, as
    hiding.                                       y of parent is hidden by child
  }                                               }
}                                                  }
