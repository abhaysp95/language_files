package practice.udemy_tut.section10.interfaces;

public interface ITelephone {
	// creating signature, actual code will still be in the class, which will
	// inherit this interface
	void powerOn();
	void dial(long phoneNumber);
	void answer();
	boolean callPhone(long phoneNumber);
	boolean isRinging();
	// signature means we defined here contract which means having valid class
	// and return type and arguments to use within respective class

	// now public/private here would be redundancy cause we are actually going
	// to do it in class
}
