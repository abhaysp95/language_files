#include <iostream>
#include <cmath>
#include <cstring>

#define MAXN 100000
int prime[MAXN + 1];
int prime_count = 0;
int primes[MAXN];

void sieve() {
	memset(prime, 1, sizeof(prime));
	prime[0] = prime[1] = 0;
	for(int i = 2; i <= MAXN; i++) {
		if(prime[i]) {
			primes[prime_count++] = i;
			if(i * (long long)1 * i <= MAXN) {
				for(int j = i * i; j <= MAXN; j += i) {
					prime[j] = 0;
				}
			}
		}
	}
}

void sieve_segment(int x, int y) {
	int arr[MAXN + 1];
	memset(arr, 0, sizeof(arr));
	if(x == 1) x++;
	int sqrty = sqrt(y);
	for(int i = 0; i < prime_count && primes[i] <= sqrty; i++) {
		int p = primes[i];
		int j = p * p;
		if(j < x) j = ((x + p - 1) / p) * p;
		for(; j <= y; j+=p) arr[j - x] = 1;
	}
	for(int i = x; i <= y; i++) if(arr[i - x] == 0) printf("%d\n", i);
}

int main(int argc, char** argv) {
	int t = 0;
	scanf("%d", &t);
	sieve();
	while(t--) {
		int n{}, m{};
		scanf("%d %d", &m, &n);
		sieve_segment(m, n);
	}
	return 0;
}
