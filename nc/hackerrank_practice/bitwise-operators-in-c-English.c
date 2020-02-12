/** Name -> Abhay Shanker Pathak
Date -> 2020-02-11
Description -> Some bitwise operations with loop
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-02-11 */

#include<stdio.h>
#include<math.h>
#define size 1000

void calculate_the_maximum(int ,int );
void sort_array(int *arr3, int );
void get_max(int *arr4, int , int );

int main(int argc, char *argv[]){
	int n, k;
	printf("\nEnter the n and k(k < n): ");
	scanf("%d %d", &n, &k);
	if ((n >= 2 && n <= pow(10, 3)) && (k >= 2 && k <= n)) {
		calculate_the_maximum(n, k);
	}
	return 0;
}

void calculate_the_maximum(int n, int k) {
	int l = 0, p = 0, q = 0, r, i, j;
	int arr[size], arr1[size], arr2[size];
	for (i = 1; i < n; ++i) {
		r = i;
		for (j = r+1; j < n+1; ++j) {
			arr[l] = i & j;
			arr1[p] = i | j;
			arr2[q] = i ^ j;
			l++; p++; q++;
		}
	}
	printf("\n\n");
	for (i = 0; i < l; i++) {
		printf("%d ",arr[i]);
	}
	printf("\n\n");
	for (i = 0; i < p; i++) {
		printf("%d ",arr1[i]);
	}
	printf("\n\n");
	for (i = 0; i < q; i++) {
		printf("%d ",arr2[i]);
	}
	printf("\n\n");
	sort_array(arr, l);
	sort_array(arr1, p);
	sort_array(arr2, q);
// display the array
	printf("\n");
	for (i = 0; i < l; i++) {
		printf("%d ",arr[i]);
	}
	printf("\n");
	for (i = 0; i < p; i++) {
		printf("%d ",arr1[i]);
	}
	printf("\n");
	for (i = 0; i < q; i++) {
		printf("%d ",arr2[i]);
	}

	get_max(arr, l, k);
	get_max(arr1, p, k);
	get_max(arr2, q, k);

}

void sort_array(int *arr3, int s) {
	int i, j, temp;
	for (i = 0; i < s-1; ++i) {
		for (j = 0; j < s-i-1; j++) {
			if (arr3[j+1] < arr3[j]) {
				temp = arr3[j+1];
				arr3[j + 1] = arr3[j];
				arr3[j] = temp;
			}
		}
	}
}

void get_max(int *arr4, int l, int k) {
	int i = 0, max = 0, arr5[size], u = 0;
	for (i = 0; i < l; i++) {
		if (arr4[i] < k) {
			arr5[u] = arr4[i];
			u++;
		}
	}
	max = arr5[0];
	for (i = 0; i < u; i++) {
		if (arr5[i] > max) {
			max = arr5[i];
		}
	}
	printf("\n%d",max);
}
