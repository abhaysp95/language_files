package atm_machine;

import java.text.DecimalFormat;
import java.util.Scanner;

public class Account {
	private String pattern = "'$'###,##0.00";
	Scanner scan = new Scanner(System.in);
	DecimalFormat moneyFormat = new DecimalFormat(pattern);

	// getters and setters
	public void setCustomerNumber(long customerNumber) {
		this.customerNumber = customerNumber;
	}

	public void setPinNumber(int pinNumber) {
		this.pinNumber = pinNumber;
	}

	public long getCustomerNumber() {
		return this.customerNumber;
	}

	public int getPinNumber() {
		return this.pinNumber;
	}

	public double getCheckingAccountBalance() {
		return this.checkingAccountBalance;
	}

	public double getSavingAccountBalance() {
		return this.savingAccountBalance;
	}


	/** get the calculation for withdraw and deposit for accounts */

	private double calcCheckingAccountWithdraw(double amount) {
		this.checkingAccountBalance -= amount;
		return this.checkingAccountBalance;
	}

	private double calcSavingAccountWithdraw(double amount) {
		this.savingAccountBalance -= amount;
		return this.savingAccountBalance;
	}

	private double calcCheckingAccountDeposit(double amount) {
		this.checkingAccountBalance += amount;
		return this.checkingAccountBalance;
	}

	private double calcSavingAccountDeposit(double amount) {
		this.savingAccountBalance += amount;
		return this.savingAccountBalance;
	}

	public void getCheckingWithdrawInput() {
		System.out.println("Current checking account balance: " +
				moneyFormat.format(getCheckingAccountBalance()));
		System.out.println("Enter the amount to withdraw:");
		double amount = scan.nextDouble();

		if (getCheckingAccountBalance() - amount >= 0) {
			calcCheckingAccountWithdraw(amount);
			System.out.println("New checking account balance: " +
					moneyFormat.format(getCheckingAccountBalance()));
		}
		else {
			System.out.println("Proper amount not given");
		}
	}

	public void getCheckingDepositInput() {
		System.out.println("Current checking account balance: " +
				moneyFormat.format(getCheckingAccountBalance()));
		System.out.println("Enter the amount to Deposit:");
		double amount = scan.nextDouble();

		if (getCheckingAccountBalance() + amount >= 0) {
			calcCheckingAccountDeposit(amount);
			System.out.println("New checking account balance: " +
					moneyFormat.format(getCheckingAccountBalance()));
		}
		else {
			System.out.println("Proper amount not given");
		}
	}

	public void getSavingWithdrawInput() {
		System.out.println("Current checking account balance: " +
				moneyFormat.format(getSavingAccountBalance()));
		System.out.println("Enter the amount to Deposit:");
		double amount = scan.nextDouble();

		if (getCheckingAccountBalance() - amount >= 0) {
			calcSavingAccountWithdraw(amount);
			System.out.println("New checking account balance: " +
					moneyFormat.format(getSavingAccountBalance()));
		}
		else {
			System.out.println("Proper amount not given");
		}
	}



	public void getSavingDepositInput() {
		System.out.println("Current checking account balance: " +
				moneyFormat.format(getSavingAccountBalance()));
		System.out.println("Enter the amount to Deposit:");
		double amount = scan.nextDouble();

		if (getCheckingAccountBalance() + amount >= 0) {
			calcSavingAccountDeposit(amount);
			System.out.println("New checking account balance: " +
					moneyFormat.format(getSavingAccountBalance()));
		}
		else {
			System.out.println("Proper amount not given");
		}
	}




	private long customerNumber;
	private int pinNumber;
	private double checkingAccountBalance = 0.0;
	private double savingAccountBalance = 0.0;
}
