package com.table;

/* @brief: Table class having logic to print table */
class Table {
	/**
	  * @brief: print the table of provided num
	            resource to thread(printTable()) synchronized
	  * @param: number provided
	*/
	public synchronized void printTable(int num) {
		for (int i = 0; i <= 10; ++i) {
			System.out.println(num + " * " + i + " = " + num * i);
		}
	}
}

class TableThread extends Thread {
	Table tt;
	int x;

	/**
	   recieving Table's object from Main class's main method
	*/
	TableThread(Table tt, int x) {
		this.tt = tt;
		this.x = x;
	}

	@Override
	public void run() {
		//Table tt = new Table();
		tt.printTable(x);
	}
}

public class Main {
	public static void main(String ...args) {
		Table table = new Table();
		//table.printTable(7);

		TableThread newThread = new TableThread(table, 7);
		TableThread anotherThread = new TableThread(table, 8);
		newThread.start();
		anotherThread.start();
	}
}