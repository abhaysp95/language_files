package atm_machine;

/** TODO: Maybe add the facility of something like admin, who can add or delete user */

import java.util.Map;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.io.IOException;
import java.lang.Exception;
import java.util.Scanner;
import java.text.DecimalFormat;

public class Operations extends Account {
	private String pattern = "'$'###,##0.00";
	Scanner sc = new Scanner(System.in);
	HashMap<Long, Integer> data = new HashMap<Long, Integer>();

	public void doLogin() {
		data.put(1234567892L, 5456);
		data.put(9822338324L, 8946);
		boolean quit = false;
		do {
			try {
				System.out.println("Welcome to ATM!");
				System.out.println("Enter customer number: ");
				setCustomerNumber(sc.nextLong());
				//sc.nextLine();
				System.out.println("Enter pin number: ");
				setPinNumber(sc.nextInt());
				//sc.nextLine();
			}
			catch (InputMismatchException e) {
				System.out.println("Provide correct Account and Pin number");
				quit = true;
			}

			//System.out.println("You entered customerNumber: " + getCustomerNumber());
			//System.out.println("You entered pinNumber: " + getPinNumber());

			for (Map.Entry<Long, Integer> entry: data.entrySet()) {
				//System.out.println("using key & value now: " + entry.getKey() + " & " + entry.getValue());
				if (entry.getKey() == getCustomerNumber() && entry.getValue() == getPinNumber()) {
					getOptions();
				}
			}
			System.out.println("Provided Account number or Pin number didn't matched");
		} while(!false);
		sc.close();
	}

	private void getOptions() {
		System.out.println("Select Account type\n" +
				"1: Checking Account\n" +
				"2: Saving Account\n" +
				"3: Quit");
		int choice = sc.nextInt();
		switch(choice) {
			case 1:
				getCheckingAccount();
				break;
			case 2:
				getSavingAccount();
				break;
			case 3:
				System.out.println("Exiting!!");
				break;
			default:
				System.out.println("Provide correct option please");
		}
	}

	public void getCheckingAccount() {
		getAccountOptions("Checking");
	}

	public void getSavingAccount() {
		getAccountOptions("Saving");
	}

	private void getAccountOptions(String accountType) {
		System.out.println("Select the operation:\n" +
				"1: View Balance\n" +
				"2: Withdraw Fund\n" +
				"3: Deposit Fund\n" +
				"4: Go Back\n" +
				"5: Quit");
		int choice = sc.nextInt();
		switch(choice) {
			case 1:
				showCurrentBalance(accountType);
				getOptions();
				break;
			case 2:
				withdrawAmount(accountType);
				getOptions();
				break;
			case 3:
				depositAmount(accountType);
				getOptions();
				break;
			case 4:
				getOptions();
				break;
			case 5:
				System.out.println("Exiting!!");
				return;
			default:
				System.out.println("Please provide correct option");
		}
	}

	private void showCurrentBalance(String accountType) {
		if (accountType.equals("Checking")) {
			System.out.println("Current balance is: " +
					moneyFormat.format(getCheckingAccountBalance()));
		}
		else if (accountType.equals("Saving")) {
			System.out.println("Current balance is: " +
					moneyFormat.format(getSavingAccountBalance()));
		}
	}

	private void withdrawAmount(String accountType) {
		if (accountType.equals("Checking")) {
			getCheckingWithdrawInput();
		}
		else if (accountType.equals("Saving")) {
			getSavingWithdrawInput();
		}
	}

	private void depositAmount(String accountType) {
		if (accountType.equals("Checking")) {
			getCheckingDepositInput();
		}
		else if (accountType.equals("Saving")) {
			getSavingDepositInput();
		}
	}
}
