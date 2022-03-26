// main file

#include <stdio.h>
#include <stdbool.h>

#define ABS(x) (((x)<0)?(0-(x)):(x))
#define POW(x) ((x)*(x))

typedef struct _point {
	int x;
	int y;
} Point;

typedef struct _circle {
	Point p;
	int r;
} Circle;

#define CCOUNT 2

void init_circle(Circle *circle) {
	circle->p.x = 0;
	circle->p.y = 0;
	circle->r = 0;
}

bool is_point_in_circle(Circle *circle, Point p) {
	int diff_x = ABS(p.x - circle->p.x), diff_y = ABS(p.y - circle->p.y);
	/* suppose there's a square with its every arm touching circle as tangent */
	if(diff_x > circle->r || diff_y > circle->r) return false;
	/* suppose there's a square(diamond) inside the circle, with its vertex
	 * touching circle */
	if(diff_x + diff_y <= circle->r) return true;
	/* left region inside of circle(left from diamond figure). Well, above
	 * checks are just in case that we don't have to go throuh below expensive
	 * calculation, or else one can just use below condition as only check */
	if(POW(diff_x) + POW(diff_y) <= POW(circle->r)) return true;
	return false;
}

int main(int argc, char **argv) {
	Circle circles[CCOUNT];
	for(int i = 0; i < CCOUNT; i++) {
		init_circle(circles + i);
		int x = 0, y = 0, r = 0;
		char buf[100] = { 0 };
		printf("Enter point for center[enter point: (x, y)]: ");
		fgets(buf, sizeof(buf), stdin);
		sscanf(buf, "(%d,%d)", &x, &y);
		printf("Enter radius: ");
		fscanf(stdin, "%d", &r);
		fgetc(stdin);  // take newline char
		circles[i].p.x = x, circles[i].p.y = y, circles[i].r = r;
	}
	Point point = {.x = 0, .y = 0};
	printf("Enter point to check[enter point: (x, y)]: ");
	fscanf(stdin, "(%d,%d)", &point.x, &point.y);
	fgetc(stdin);
	printf("%s\n",
			((is_point_in_circle(circles, point) && is_point_in_circle(circles + 1, point))
			 ? "True" : "False"));
	return 0;
}