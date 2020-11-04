/* to use 'javap', for basic use run following:
   $ javap java.lang.Object

   and you'll see all the methods of Object class
   You can provide any correct class as in the above example */


/* For this class, run in the same folder of this file
   $ javap Simple

   ofcourse, after compiling :)
   you'll see all the components which jvm puts bydefault and other stuffs
*/

class Simple {
	private static String name = "JAVA";

	public static void anotherPrint() {
		System.out.println("Hello User");
	}

	public static void main(String[] args) {
		System.out.println("Hello " + name);
		anotherPrint();
	}
}
