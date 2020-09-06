package practice.udemy_tut.section8.bank_transactions;

import java.util.ArrayList;

public class Bank {
	private String bankName;
	private ArrayList<Branch> branches;

	public Bank(String bankName) {
		this.bankName = bankName;
		branches = new ArrayList<Branch>();
	}

	public String getBankName() {
		return this.bankName;
	}

	public boolean addBranch(String branchName) {
		if (findBranch(branchName) == null) {
			this.branches.add(new Branch(branchName));
			return true;
		}
		return false;
	}

	public boolean addCustomer(String branchName, String customerName, double balance) {
		Branch branch = findBranch(branchName);
		if (branch != null) {
			System.out.println("New customer [ " + customerName + " ] in branch " + branchName + " with intial balance: " + balance);
			return branch.newCustomer(customerName, balance);
			// will return boolean
		}
		return false;
	}

	public boolean addCustomerTransaction(String branchName, String customerName, double amount, String method) {
		Branch branch = findBranch(branchName);
		if (branch != null) {
			return branch.addTransaction(customerName, amount, method);
		}
		return false;
	}

	private Branch findBranch(String branchName) {
		for (int i = 0; i < this.branches.size(); ++i) {
			Branch checkedBranch = this.branches.get(i);
			if (checkedBranch.getBranchName().equals(branchName)) {
				//System.out.println("Found branch: " + branchName);
				return checkedBranch;
			}
		}
		return null;
	}

	public boolean listCustomers(String branchName, boolean showTransaction) {
		Branch branch = findBranch(branchName);
		//System.out.println("Branch Name found: " + branch.getBranchName());
		if (branch != null) {
			// create a getter in Branch class to get the list of customers in the branch
			System.out.println("Customer detail for branch " + branchName);
			ArrayList<Customer> branchCustomers = branch.getCustomers();
			// print customers
			int branchCustomerCount = 0;
			for (Customer branchCustomer: branchCustomers) {
				++branchCustomerCount;
				System.out.println(branchCustomerCount + ": " + "Customer: " + branchCustomer.getName());
				// if showTransaction is true
				if (showTransaction) {
					ArrayList<Double> customerTransactions = branchCustomer.getTransaction();
					int customerTransactionCount = 0;
					for (Double customerTransaction: customerTransactions) {
						++customerTransactionCount;
						System.out.println("\t" + customerTransactionCount + ": " + customerTransaction);
					}
				}
			}
			return true;
		}
		return false;
	}

	//public boolean listCustomers(String branchName, boolean showTransaction) {
		//Branch branch = findBranch(branchName);
		//if (branch != null) {
			//System.out.println("Customer detail for branch: " + branch.getBranchName());
			//ArrayList<Customer> branchCustomers = branch.getCustomers();
			//for (int i = 0; i < branchCustomers.size(); ++i) {
				//Customer branchCustomer = branchCustomers.get(i);
				//System.out.println((i + 1) + ": " + "Customer: " + branchCustomer.getName());
				//if (showTransaction) {
					//System.out.println("Transaction details:");
					//ArrayList<Double> customerTransactions = branchCustomer.getTransaction();
					//for (int j = 0; j < customerTransactions.size(); ++j) {
						//System.out.println("\t" + (j + 1) + ": " + customerTransactions.get(j));
					//}
				//}
			//}
			//return true;
		//}
		//return false;
	//}

	public void listBranch(String bankName) {
		System.out.println("List all branches in bank " + bankName);
		System.out.println("Total number of branches: " + this.branches.size());
		for (int i = 0; i < this.branches.size(); ++i) {
			System.out.println((i + 1) + ": " + this.branches.get(i).getBranchName());
		}
	}
}
