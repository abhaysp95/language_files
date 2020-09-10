package practice.udemy_tut.section10.interfaces;

public class Main {
	public static void main(String[] args) {
		// creating instance of DeskPhone
		// we can have type of interface
		ITelephone myPhone;
		// but can't have something like this
		//ITelephone myPhone = new ITelephone();
		// so, interface is there abstract to tell you what method to be overridden in actual class
		// now, DeskPhone myPhone; will also work, but there is some
		// difference, you'll know later
		myPhone = new DeskPhone(1234567890L);
		myPhone.powerOn();
		myPhone.callPhone(1234567890L);
		myPhone.isRinging();
		myPhone.answer();

		myPhone = new MobilePhone(534230929324L);
		myPhone.powerOn();
		myPhone.callPhone(534230929324L);
		myPhone.answer();

		// java library have extensive use of interface

	}
}
