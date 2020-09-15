package practice.udemy_tut.section9.inner_class;

public class Button {
	private String title;
	private OnClickListener onClickListener;

	public Button(String title) {
		this.title = title;
	}

	public String getTitle() {
		return this.title;
	}

	public void setOnClickListener(OnClickListener onClickListener) {
		this.onClickListener = onClickListener;
	}

	public void onClick() {
		this.onClickListener.onClick(this.title);
		// both the onClick are different, above one is of Button
		// and belew one is of onClickListener
	}

	// Now, inteface here is used as comparing to a method(inside a class).
	// You can still have it's separate file and interface in it and then you
	// have to implement that interface with 'implements' in this class Button
	public interface OnClickListener {
		public void onClick(String title);
	}
}
