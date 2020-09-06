package practice.udemy_tut.section8.bank_transactions;

public class Main {
	public static void main(String[] args) {
		Bank bank = new Bank("Punjab National Bank");

		bank.addBranch("Rambagh");
		bank.addCustomer("Rambagh", "Abhay", 3400.00);
		bank.addCustomer("Rambagh", "Ashish", 2393.09);
		bank.addCustomer("Rambagh", "Lav", 682.92);

		bank.addBranch("Chauk");
		bank.addCustomer("Chauk", "Mahesh", 9230.0);
		bank.addCustomer("Chauk", "Dina", 9239.0);

		bank.listBranch("Punjab National Bank");

		bank.addCustomerTransaction("Rambagh", "Abhay", 6439.02, "debit");
		bank.addCustomerTransaction("Rambagh", "Lav", 1459.02, "credit");
		bank.addCustomerTransaction("Rambagh", "Ashish", 439.02, "debit");
		bank.addCustomerTransaction("Rambagh", "Dina", 6439.02, "debit");  // put wrong customer intentionally

		bank.listCustomers("Rambagh", true);
		bank.listCustomers("Chauk", true);

		if (!bank.addCustomer("Katra", "Hari", 923.90)) {
			System.out.println("Branch not exist");
		}

		if (!bank.addBranch("Chauk")) {
			System.out.println("Branch already exist");
		}

		// you can do some more validation
	}
}
