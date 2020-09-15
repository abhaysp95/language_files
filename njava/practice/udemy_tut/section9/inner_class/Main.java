package practice.udemy_tut.section9.inner_class;

//import practice.udemy_tut.section9.inner_class.GearBox.Gear;

import java.io.BufferedReader;
import java.io.InputStreamReader;

import practice.udemy_tut.section9.inner_class.Button.OnClickListener;

public class Main {
	private static Button btnPrint = new Button("Print");

	public static void main(String[] args) {
		// it's important to create the outerclass instance to work with innerclass
		//GearBox dodge = new GearBox(6);
		//GearBox.Gear first = dodge.new Gear(1, 12.3);

		// wrong -\
		// GearBox.Gear second = new GearBox.Gear(1, 12.3);
		// GearBox.Gear third = new dodge.Gear(3, 45.23);


		//GearBox.Gear second = dodge.new Gear(2, 22.9);
		//GearBox.Gear third = dodge.new Gear(3, 34.3);
		//GearBox.Gear fourth = dodge.new Gear(4, 44.3);
		//GearBox.Gear fifth = dodge.new Gear(5, 56.1);
		//GearBox.Gear sixth = dodge.new Gear(6, 65.4);
		//System.out.println("Drive Speed at first gear of dodge: " +
				//first.driveSpeed(2500));
		//System.out.println("Drive Speed at second gear of dodge: " +
				//second.driveSpeed(2500));
		//System.out.println("Drive Speed at third gear of dodge: " +
				//third.driveSpeed(2500));
		//System.out.println("Drive Speed at fourth gear of dodge: " +
				//fourth.driveSpeed(2500));
		//System.out.println("Drive Speed at fifth gear of dodge: " +
				//fifth.driveSpeed(2500));
		//System.out.println("Drive Speed at sixth gear of dodge: " +
				//sixth.driveSpeed(2500));
		//dodge.getGear().add(first);
		//dodge.getGear().add(second);
		//dodge.getGear().add(third);
		//dodge.getGear().add(fourth);
		//dodge.getGear().add(fifth);
		//dodge.getGear().add(sixth);

		//System.out.println("Gears: ");
		//for (Gear gear: dodge.getGear()) {
			//System.out.println("gear: " + gear.getGearNumber());
		//}


		// All the above code is done when inner Gear class was public
		// but now innerClass Gear is private


		// added in constructor
		//dodge.addGear(1, 12.3);
		//dodge.addGear(2, 21.3);
		//dodge.addGear(3, 32.1);
		//dodge.addGear(4, 43.2);
		//dodge.addGear(5, 54.3);
		//dodge.addGear(6, 65.4);

		//dodge.operateClutch(true);
		//dodge.changeGear(1);
		//dodge.operateClutch(false);
		//System.out.println(dodge.wheelSpeed(4500));
		//dodge.operateClutch(true);
		//dodge.changeGear(2);
		//System.out.println(dodge.wheelSpeed(2500));


		System.out.println("-----------------------------");

		// code for Button.java

		// local class
		/*class ClickListener implements OnClickListener {
			public ClickListener() {
				System.out.println("I'have been attached");
			}

			@Override
			public void onClick(String title) {
				System.out.println(title + " was clicked.");
			}
		}
		btnPrint.setOnClickListener(new ClickListener());*/

		// Anonymous class(compare it with local class above)
		btnPrint.setOnClickListener(new Button.OnClickListener(){
			@Override
			public void onClick(String title) {
				System.out.println(title + " was clicked");
			}
		});
		// let's compare, ClickListener's object is getting passed to be used
		// as generic class's object on Button.java because ClickListener
		// implements OnClickListener interface.

		// Now, for anonymous one, 'new Button.OnClickListener()' means instead
		// of creating a local class and then it's object, it's passing the
		// object itself from the bluePrint of Button.OnClickListener() generic
		// class
		listen();
	}

	private static void listen() {
		boolean quit = false;
		while(!quit) {
			try {
				BufferedReader bufr = new BufferedReader(new InputStreamReader(System.in));
				int choice = Integer.parseInt(bufr.readLine());
				switch(choice) {
					case 0:
						quit = true;
						break;
					case 1:
						btnPrint.onClick();
						break;
				}
			}
			catch (Exception e) {
				System.out.println("Exception: " + e);
			}
		}
	}
}

/* Anonymous class is used when local class is required only once which happens
 * in most of the case, that's why local class are rarely used */
