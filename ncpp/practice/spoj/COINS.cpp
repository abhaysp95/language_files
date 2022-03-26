#include <iostream>
#define SZ 1000001

using ll = long long;

long long arr[SZ];

ll get_max_amount_rec(ll n) {
	if(n < SZ) {
		return arr[n];
	}
	return get_max_amount_rec(n / 2) +
		get_max_amount_rec(n / 3) +
		get_max_amount_rec(n / 4);
	//return std::max(n, get_max_amount_rec(n / 2) +
			//get_max_amount_rec(n / 3) +
			//get_max_amount_rec(n / 4));
}

void get_max_amount() {
	arr[0] = arr[1] = 0;
	for(ll i = 2; i < SZ; i++)
		arr[i] = std::max(i, arr[i / 2] + arr[i / 3] + arr[i / 4]);
}

int main(int argc, char **argv) {
	ll n = 0;
	get_max_amount();
	while(scanf("%lld", &n) != EOF) {
		if(n < SZ) printf("%lld\n", arr[n]);
		else {
			printf("%lld\n", get_max_amount_rec(n));
		}
	}
}


	/*if(n <= 1) return 0;
	return std::max(n, (get_max_amount_rec(n / 2) +
				get_max_amount_rec(n / 3) +
				get_max_amount_rec(n / 4)));*/
