import java.util.Scanner;

public class Main {

	private static Scanner scanner = new Scanner(System.in);
	private static Button btnPrint = new Button("Print");

	public static void main(String[] args) {
		//GearBox mcLaren = new GearBox(6);
		/*GearBox.Gear first = mcLaren.new Gear(1, 12.3);
		GearBox.Gear second = mcLaren.new Gear(2, 15.3);
		[>* new GearBox.Gear(...) will not work <]
		GearBox.Gear third = mcLaren.new Gear(3, 17.3);
		System.out.println(first.driveSpeed(1000));*/

		/*mcLaren.addGear(1, 5.3);
		mcLaren.addGear(2, 10.6);
		mcLaren.addGear(3, 15.9);
		mcLaren.operateClutch(true);
		mcLaren.changeGear(1);
		mcLaren.operateClutch(false);
		System.out.println(mcLaren.wheelSpeed(1000));
		mcLaren.operateClutch(true);
		mcLaren.changeGear(2);
		System.out.println(mcLaren.wheelSpeed(1000));*/


		/** local class for Button */

		/*class ClickListener implements Button.OnClickListener {
			public ClickListener() {
				System.out.println("I'v been attached");
			}

			@Override
			public void onClick(String title) {
				System.out.println(title + " was clicked");
			}
		}
		btnPrint.setOnClickListener(new ClickListener());*/

		/** anonymous class */
		btnPrint.setOnClickListener(new Button.OnClickListener() {
			@Override
			public void onClick(String title) {
				System.out.println(title + " was clicked");
			}
		});
		listen();
	}

	public static void listen() {
		boolean quit = false;
		while (!quit) {
			int choice = scanner.nextInt();
			scanner.nextLine();
			switch(choice) {
				case 0:
					quit = true;
				case 1:
					btnPrint.onClick();
			}
		}
	}
}
