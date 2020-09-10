package practice.udemy_tut.section10.interfaces;

public class MobilePhone implements ITelephone {
	private long myNumber;
	private boolean isRinging;
	private boolean isOn = false;

	public MobilePhone(long phoneNumber) {
		this.myNumber = phoneNumber;
	}

	@Override
	public void powerOn() {
		isOn = true;
		System.out.println("Mobile phone powered on");
	}

	@Override
	public void dial(long phoneNumber) {
		if (isOn) {
			System.out.println("Now ringing: " + phoneNumber);
		}
		else {
			System.out.println("Mobile is turned of, can't dial");
		}
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
		if (isOn && phoneNumber == myNumber) {
			isRinging = true;
			System.out.println("Melody Ring");
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
}
