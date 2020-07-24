// another header file as example for my_func.c

int give_fibonacci(int number) {
	int fnum = 1, snum = 1;
	int count = 2, tsum = 0;
	if (number == 1 || number == 2) {
		return fnum;
	}
	while (count != number) {
		tsum = fnum + snum;
		fnum = snum;
		snum = tsum;
		count++;
	}
	return tsum;
}
