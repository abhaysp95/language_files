public class SimpleCalculator {
	private double firstNumber = 0;
	private double secondNumber = 0;

	// getter
	double getFirstNumber() {
		return this.firstNumber;
	}

	// getter
	public double getSecondNumber() {
		return this.secondNumber;
	}

	// setter
	public void setFirstNumber(double number) {
		this.firstNumber = number;
	}

	// setter
	public void setSecondNumber(double number) {
		this.secondNumber = number;
	}

	public double getAdditionResult() {
		return this.firstNumber + this.secondNumber;
	}

	public double getSubtractionResult() {
		return this.firstNumber - this.secondNumber;
	}

	public double getMultiplicationResult() {
		return this.firstNumber * this.secondNumber;
	}

	public double getDivisionResult() {
		if (secondNumber == 0) {
			return 0;
		}
		return this.firstNumber / this.secondNumber;
	}
}
