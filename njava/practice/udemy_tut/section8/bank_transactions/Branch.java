package practice.udemy_tut.section8.bank_transactions;

import java.util.ArrayList;

public class Branch {
	private String branchName;
	private ArrayList<Customer> customers;

	public Branch() {
		this.branchName = "No branch name given";
	}

	public Branch(String branchName) {
		this.branchName = branchName;
		this.customers = new ArrayList<Customer>();
	}

	public String getBranchName() {
		return this.branchName;
	}

	public ArrayList<Customer> getCustomers() {
		return this.customers;
	}

	public boolean newCustomer(String customerName, double balance) {
		if (findCustomer(customerName) == null) {
			this.customers.add(new Customer(customerName, balance));
			return true;
		}
		// if customer already exist or wrong customer name provided
		return false;
	}

	public boolean addTransaction(String customerName, double amount, String method) {
		Customer existingCustomer = findCustomer(customerName);
		if (existingCustomer != null) {
			existingCustomer.addCustomerTransaction(method, amount);
			return true;
		}
		System.out.println("Customer " + customerName + " is not in this branch");
		return false;
	}

	private Customer findCustomer(String customerName) {
		for (int i = 0; i < this.customers.size(); ++i) {
			Customer checkedCustomer = this.customers.get(i);
			if (checkedCustomer.getName().equals(customerName)) {
				return checkedCustomer;
			}
		}
		return null;
	}

	/* Imo, using customers.indexOf(<some object>) is not right as customers is
	 * the arraylist of objects of Customer class and we don't know which
	 * Customer object is wanted and the user is passing Customer Name not
	 * Customer class's object, so you understand
	 */
}
