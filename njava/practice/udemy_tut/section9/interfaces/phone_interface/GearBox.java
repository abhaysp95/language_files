package practice.udemy_tut.section10.interfaces;

public class GearBox {
	private boolean clutchIsIn;

	//public void operateGearbox(String inOrOut) {
		// this will give boolean, but let's change this method
		//this.clutchIsIn = inOrOut.equals("in");
	//}

	public void operateGearbox(boolean inOrOut) {
		this.clutchIsIn = inOrOut;
	}

	// now since we change the argument type, this could be problamatic if this
	// public method is used in many places, that's why we use interface. It's
	// sort of contract that you fix that you are not going to change the
	// method
}
