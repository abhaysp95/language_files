package com.printer;

public class Printer {
	private int tonerLevel;
	private int pagesPrinted;
	private boolean isDuplex;

	public Printer(int tonerLevel, int pagesPrinted, boolean isDuplex) {
		if (tonerLevel >= 0 && tonerLevel <= 100) {
			this.tonerLevel = tonerLevel;
		}
		this.pagesPrinted = pagesPrinted;
		this.isDuplex = isDuplex;
	}

	public void fillToner(int addUpto) {
		if (currentTonerLevel() == 100) {
			System.out.println("Toner Level already 100%");
		}
		else if (currentTonerLevel() + addUpto > 100) {
			this.tonerLevel = 100;
			System.out.println("Toner bucket is starting to flow out");
		}
		else {
			this.tonerLevel += addUpto;
		}
	}

	public void reduceToner(int reduce) {
		if (currentTonerLevel() == 0) {
			System.out.println("Toner already empty");
		}
		else if(currentTonerLevel() - reduce < 0) {
			this.tonerLevel = 0;
			System.out.println("Can't reduce toner level more than Zero");
		}
		else {
			this.tonerLevel -= reduce;
		}
	}

	public void printPages(int number) {
		while (number > 0 && currentTonerLevel() > 0) {
			if (this.isDuplex) {
				this.pagesPrinted += 1;
			}
			else {
				this.pagesPrinted += 2;
			}
			reduceToner(1);
			--number;
		}
	}

	public int currentTonerLevel() {
		return this.tonerLevel;
	}

	public int getPagePrinted() {
		return this.pagesPrinted;
	}
}
