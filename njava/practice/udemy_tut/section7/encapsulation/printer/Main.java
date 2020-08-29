package com.printer;

public class Main {
	public static void main(String[] args) {
		Printer printer = new Printer(50, 0, true);
		System.out.println("Current Pages printed: " + printer.getPagePrinted());
		System.out.println("Toner level: " + printer.currentTonerLevel());
		printer.fillToner(35);
		System.out.println("Toner level: " + printer.currentTonerLevel());
		printer.printPages(45);
		System.out.println("Current Pages printed: " + printer.getPagePrinted());
		System.out.println("Toner level: " + printer.currentTonerLevel());
		printer.fillToner(78);
		System.out.println("Toner level: " + printer.currentTonerLevel());
	}
}
