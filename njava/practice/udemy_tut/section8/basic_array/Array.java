import java.util.Arrays;

// basic demostration of array in java

class Array {
	// to declare a array
	public static void printArray() {
		int[] myIntArray = new int[10];  // this declares the int array of size 10
		// we can do this
		int[] myIntArray2 = {1, 2, 3, 4, 5};

		// insert element
		for (int i = 0; i < myIntArray.length; ++i) {
			myIntArray[i] = i * 10;
		}
		for (int i = 0; i < myIntArray.length; ++i) {
			System.out.println(myIntArray[i]);
		}
	}

	public void printArr(int ...arr) {
		for (int i = 0; i < arr.length; ++i) {
			System.out.println(arr[i]);
		}
	}

	public int[] modifyArrayWithReturn(int ...arr) {
		// modify third element
		if (arr.length >= 3) {
			arr[2] = 10;
		}
		return arr;
	}

	public void modifyArrayWithoutReturn(int ...arr) {
		// modify third element
		if (arr.length >= 3) {
			arr[2] = 20;
		}
	}

	// to copy a array int[] newArr = arrays.copyOf(old_array, old_array.length);
	// arrays is from java.util package
}

class Main {
	public static void main(String[] args) {
		Array array = new Array();
		int[] myArr = new int[5];
		for (int i = 1; i <= 5; ++i) {
			myArr[i - 1] = i * 3;
		}

		System.out.println("First print:");
		array.printArr(myArr);
		array.modifyArrayWithReturn(myArr);
		System.out.println("Print with modifyArrayWithReturn:");
		array.printArr(myArr);
		array.modifyArrayWithoutReturn(myArr);
		System.out.println("Print with modifyArrayWithoutReturn:");
		System.out.println(Arrays.toString(myArr));
		//method to print array as string [ ..., ... ]

		// so this little experiment from above proves that passing of array is
		// passing of reference, so the actual array is modified if we modify
		// the array in some other method. Just like it's with pointer in C for
		// array
	}
}


// the default numeric array elements are set to 0 on declaration
// for boolean array, it'll be initialized to false
// for char, it'll be null
