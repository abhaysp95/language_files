/** Name -> Abhay Shanker Pathak
Date -> 2020-03-09
Description -> Find the volume of all the boxes for height strictly less than 41 feet
Email -> abhaysp9955@gmail.com
Github -> https://github.com/CoolAbhayS
Last Edit -> 2020-03-09 */

#include<stdio.h>
#include<stdlib.h>
#define mheight 41

struct box {
	int length, width, height;
};

typedef struct box box;

int is_lower_than_max_height(box );
int get_volume(box );

int main(int argc, char *argv[]){
	int n;
	printf("\nNo. of the boxes: ");
	scanf("%d", &n);
	box *boxes = malloc(n*sizeof(box));
	for (int i = 0; i < n; i++)
		scanf("%d%d%d", &boxes[i].length, &boxes[i].width, &boxes[i].height);
	for (int i = 0; i < n; i++) {
		if (is_lower_than_max_height(boxes[i])) {
			printf("%d\n", get_volume(boxes[i]));
		}
	}
	return 0;
}

int is_lower_than_max_height(box b) {
	if (b.height < 41)
		return 1;
	else
		return 0;
}

int get_volume(box b) {
	return (b.length * b.width * b.height);
}
