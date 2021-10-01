#include <iostream>
#include <cmath>

/** pattern is, at for every i(natural number) to the power of 5, it increases one more zero, so:
  1->4 = 0, 5->9(i = 1) = 1, 10->14 = 2, 15->19 = 3, 20->24 = 4, but 25->29 = 6
  (one extra zero(two zeros now) in steady increment(of zero by 1, with every 5
  numbers), because 25 = pow(5, 2)). The increament of zero by 2 will happen on
  every 5th multiple of 5 now. Once, the number reaches 125 then zero will be
  incremented extra two(3 zero) for every multiple of 5 */

int main(int argc, char** argv) {
	int t = 0;
	scanf("%d", &t);
	while(t--) {
		int num = 0;
		scanf("%d", &num);
		int power = 0;
		for(int i = 1; pow(5, i) <= num; i++) {
			power++;
		}
		int count = 0;
		for(int i = 1; i <= power; i++) {
			count += num / pow(5, i);
		}
		printf("%d\n", count);
	}
	return 0;
}
