/** Name -> Abhay Shanker Pathak
Date -> 2020-03-10
Description -> same question as smalltri_largetri.c but with linked list
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-03-10 */

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct triangle {
	int a, b, c;
};

typedef struct triangle triangle;

void sort_by_area(triangle* ,int );

int main(int argc, char *argv[]){
	int n;
	printf("\nEnter the count of triangles: ");
	scanf("%d", &n);
	triangle *tri = (triangle *)malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tri[i].a, &tri[i].b, &tri[i].c);
	}
	sort_by_area(tri, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tri[i].a, tri[i].b, tri[i].c);
	}
	return 0;
}

void sort_by_area(triangle* tri, int n) {
	float *area = (float *)malloc(n * sizeof(float));
	triangle *temptri = (triangle *)malloc(sizeof(triangle));
	for (int i = 0; i < n; i++) {
		float p = (tri[i].a + tri[i].b + tri[i].c) / 2.0;
		*(area + i) = (p * (p - tri[i].a) *  (p - tri[i].b) * (p - tri[i].c));
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (*(area + j) > *(area + (j + 1))) {
				float temp = *(area + j);
				*(area + j) = *(area + (j + 1));
				*(area + (j + 1)) = temp;

				*temptri = tri[j];
				tri[j] = tri[j + 1];
				tri[j + 1] = *temptri;
			}
		}
	}
}
