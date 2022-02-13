#include <iostream>
#include <cstring>
#include <climits>

#define SZ 5001

int buf[SZ];

bool check_passed(int *buf, int count) {
	for(int i = 0; i < count; i++) {
		if(!isalpha(buf[i])) return false;
	}
	return true;
}

void fill_num(int num, int *buf, int i, int count, int level) {
	if(i + 1 >= count) return;
	buf[i] = (buf[i] * 10) + buf[i + 1];
	for(int j = i + 1; j < (count - level); j++) {
		buf[j] = buf[j + 1];
	}
	buf[count - level] = '\0';
}

int decodings(int num, int* buf, int idx, int count, int level) {
	if(idx + 1 >= count) return 1;
	int sum = 0;
	for(int i = idx; i < count - 1; i++) {
		if(!check_passed(buf, count - level)) continue;
		fill_num(num, buf, i);
		sum += decodings(num, buf, idx + 1 + i, count, level + 1);
	}
	return sum;
}

int solution(int num) {
	int count = 0, temp = num;
	while(temp--) {
		temp /= 10, count++;
	}
	decodings(num, buf, 0, count, 1);
	return 0;
}

int main(int argc, char** argv)
{
	int num = 0;
	while(scanf("%d", &num)) {
		printf("%d\n", solution(num));
	}
	return 0;
}
