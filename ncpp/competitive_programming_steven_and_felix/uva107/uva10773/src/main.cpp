// main file

// visit for concept: https://www.concepts-of-physics.com/mechanics/relative-velocity-and-river-boat-problem.php

#include <iostream>
#include <cstdio>
#include <cmath>

int main(int argc, char **argv) {
	int T = 0;
	scanf("%d", &T);
	while(T--) {
		// d = distance, u = rel. velocity of both w.r.t to river
		// v = river flow
		int count = 0;
		int d = 0, u = 0, v = 0;
		scanf("%d %d %d", &d, &v ,&u);
		float t1 = d / (float)u;  // shortest time
		float t2 = d / sqrt(u * u - v * v);  // shortest path
		if(t1 == t2 || u < v) printf("Case %d: can't determine\n", ++count);
		else printf("Case %d: %0.3f\n", ++count, (t2 - t1));
	}
	return 0;
}