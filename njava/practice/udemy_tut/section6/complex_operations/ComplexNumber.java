package com.complexoperations;

public class ComplexNumber {
	private double real;
	private double imaginary;

	public ComplexNumber(double real, double imaginary) {
		this.real = real;
		this.imaginary = imaginary;
	}

	// getters
	public double getReal() {
		return this.real;
	}
	public double getImaginary() {
		return this.imaginary;
	}

	// addition
	public void add(double real, double imaginary) {
		this.real += real;
		this.imaginary += imaginary;
	}
	public void add(ComplexNumber complexNumber) {
		this.real += complexNumber.real;
		this.imaginary += complexNumber.imaginary;
	}

	// subtraction
	public void subtract(double real, double imaginary) {
		this.real -= real;
		this.imaginary -= imaginary;
	}
	public void subtract(ComplexNumber complexNumber) {
		this.real -= complexNumber.real;
		this.imaginary -= complexNumber.imaginary;
	}
}
