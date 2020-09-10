package practice.udemy_tut.section10.interfaces;

public class DeskPhone implements ITelephone {
	// now the DeskPhone should either be abstract or use methods(abstract)
	// from ITelephone
	private long myNumber;
	private boolean isRinging;

	public DeskPhone(long phoneNumber) {
		this.myNumber = phoneNumber;
	}

	@Override
	public void powerOn() {
		System.out.println("No action taken, DeskPhone doesn't have power button");
	}

	@Override
	public void dial(long phoneNumber) {
		System.out.println("Now ringing: " + phoneNumber);
	}

	@Override
	public void answer() {
		if (isRinging) {
			System.out.println("Answering");
			isRinging = false;
		}
	}

	@Override
	public boolean callPhone(long phoneNumber) {
		if (phoneNumber == myNumber) {
			isRinging = true;
			System.out.println("Ring Ring");
		}
		else {
			isRinging = false;
		}
		return isRinging;
	}

	@Override
	public boolean isRinging() {
		return isRinging;
	}

	// so inorder to be appropriate class above these methods where needed to
	// be implemented
}
