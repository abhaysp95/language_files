// getch() is used to get(read) single character from stdin device without echoing
// getche() is used to get(read) single character from stdin with echoing


#include <stdio.h>
#include <termios.h>

static struct termios old, new;

// initialize new terminal i/o settings
void initTermios(int echo) {
	tcgetattr(0, &old); // grab old terminal i/o settings
	new = old; // make new settings same as old settings
	new.c_lflag &= ~ICANON; // disable buffered i/o
	new.c_lflag &= echo ? ECHO : ~ECHO;  // set echo mode
	tcsetattr(0, TCSANOW, &new);  // apply terminal io settings
}
// c_lflag is for local modes
// The c_lflag field of argument structure is used to control various terminal functions:
// ECHO, ECHOE, ECHOK, ECHONL, ICANON, IEXTEN, ISIG, NOFLSH, TOSTOP, XCASE
// checkout following link for more detail on termios:
// https://pubs.opengroup.org/onlinepubs/7908799/xsh/termios.h.html#:~:text=DESCRIPTION,the%20structures%20and%20names%20defined).

// restore old terminal i/o settings
void resetTermios(void) {
	tcsetattr(0, TCSANOW, &old);
}

// Read 1 character - echo defines echo mode
char getch_(int echo) {
	char ch;
	initTermios(echo);
	ch = getchar();
	resetTermios();
	return ch;
}

// read 1 char without echo, getch() function definition
char getch(void) {
	return getch_(0);
}

// read 1 char with echo, getche() function definition
char getche(void) {
	return getch_(1);
}

// main function
int main(int argc, char* argv[]) {
	char c;
	printf("(getche example) Please enter a char: ");
	c = getche();
	printf("\nYou entered: %c\n", c);
	printf("(getch example) Please enter a char: ");
	c = getch();
	printf("\nYou entered: %c\n", c);
	return 0;
}
