// primitive data type capacity demonstration

public class main {
	public static void main(String[] args) {

		int myintvalue = 2_14_74_83_647;  // _ works as seperator
		System.out.println("Current int value: " + myintvalue);
		int minIntValue = Integer.MIN_VALUE;
		int maxIntValue = Integer.MAX_VALUE;
		System.out.println("Min int value: " + minIntValue);
		System.out.println("Max int value: " + maxIntValue);
		System.out.println("Busted min int value: " + (minIntValue - 1));
		System.out.println("Busted max int value: " + (maxIntValue + 1));

		System.out.println("--------------------------------------");

		System.out.println("For Bytes: ");
		byte minByteValue = Byte.MIN_VALUE;
		byte maxByteValue = Byte.MAX_VALUE;
		System.out.println("Min byte value: " + minByteValue);
		System.out.println("Max byte value: " + maxByteValue);
		System.out.println("Busted min byte value: " + (minByteValue - 1));
		System.out.println("Busted max byte value: " + (maxByteValue + 1));

		System.out.println("--------------------------------------");

		System.out.println("For Short: ");
		short minShortValue = Short.MIN_VALUE;
		short maxShortValue = Short.MAX_VALUE;
		System.out.println("Min short value: " + minShortValue);
		System.out.println("Max short value: " + maxShortValue);
		System.out.println("Busted min short value: " + (minShortValue - 1));
		System.out.println("Busted max short value: " + (maxShortValue + 1));

		System.out.println("--------------------------------------");

		long mylongvalue = 100L;  // this declaration isn't necessary for code below
		System.out.println("For long: ");
		long minLongValue = Long.MIN_VALUE;
		long maxLongValue = Long.MAX_VALUE;
		System.out.println("Min long value: " + minLongValue);
		System.out.println("Max long value: " + maxLongValue);
		System.out.println("Busted min long value: " + (minLongValue - 1));
		System.out.println("Busted max long value: " + (maxLongValue + 1));

		System.out.println("--------------------------------------");

		int newintvalue = (minIntValue / 2);
		System.out.println("newintvalue: " + newintvalue);
		// byte newbytevalue = maxByteValue / 2;  // loosy conversion from int to byte
		// byte newbytevalue = (maxByteValue / 2);  // same here, treating result under () as int
		byte newbytevalue = (byte)(maxByteValue / 2);  // type conversion
		System.out.println("newbytevalue: " + newbytevalue);

		short newshortvalue = (short)(maxShortValue / 2);  // type conversion
		System.out.println("newshortvalue: " + newshortvalue);

		System.out.println("--------------------------------------");
		System.out.println("Starting floating numbers");
		System.out.println("--------------------------------------");

		float minFloatValue = Float.MIN_VALUE;
		float maxFloatValue = Float.MAX_VALUE;
		System.out.println("Min float value: " + minFloatValue);
		System.out.println("Max float value: " + maxFloatValue);
		System.out.println("Busted min float value: " + (minFloatValue - 1));
		System.out.println("Busted max float value: " + (maxFloatValue + 1));

		System.out.println("--------------------------------------");

		double minDoubleValue = Double.MIN_VALUE;
		double maxDoubleValue = Double.MAX_VALUE;
		System.out.println("Min double value: " + minDoubleValue);
		System.out.println("Max double value: " + maxDoubleValue);
		System.out.println("Busted min double value: " + (minDoubleValue - 1));
		System.out.println("Busted max double value: " + (maxDoubleValue + 1));

		System.out.println("--------------------------------------");

		float newfloatnum = 3.24f;
		// float newnum = 3.24;  // loosy conversion from double to float
		float newfloat = (float) (3.24);
		double newdoublenum = 3.25d;
		double newdouble = 3.25;  // by-default number decimal number without type suffix is considered as double

		System.out.println("newfloatnum: " + newfloatnum);
		System.out.println("newfloat: " + newfloat);
		System.out.println("newdoublenum: " + newdoublenum);
		System.out.println("newdouble: " + newdouble);

		System.out.println("--------------------------------------");
		System.out.println("Starting char and bool");
		System.out.println("--------------------------------------");

		char mychar = 'd';
		char charunicodeD = '\u0044';
		System.out.println("mychar: " + mychar);
		System.out.println("unicode D: " + charunicodeD);
		boolean isthistrue = true;
		System.out.println("isthistrue: " + isthistrue);

		System.out.println("--------------------------------------");
		System.out.println("Starting string");
		System.out.println("--------------------------------------");

		String mystring = "This is mystring";  // string maximum memory is limited by the max memory of int
		System.out.println("here's the string: " + mystring);
	}
}
