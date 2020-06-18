/**

Abhay Shanker Pathak
abhaysp9955@gmail.com
https://github.com/coolabhays


recursive function to enter a word and return the depth of space */


#include<stdio.h>

int if_got_space(int);
int if_got_space2(int);

int if_got_space(int count) {
	char letter;
	// scanf ("%c", &letter);
	// letter = getchar();  // this will work if user enters the word in single line
	// but task is to enter one by one, so we have to deal with carraige return
	scanf("%c%*c", &letter);  // works perfectly(leaves all the char after first one)
	// but if entered one by one
	// scanf(" %c", &letter);  // this doesn't works, because it skips any whitespace
	// char, so <space> isn't considered here
	// or add a getchar() after scanf to deal with return
	// scanf("%c", &letter);  // these two(and line below) in combination work fine
	// getchar();
	if (letter != ' ') {
		count = if_got_space(count + 1);
	}
	return count;
}

int if_got_space2(int count) {
	char letter;
	scanf("%c%*c", &letter);
	if (letter == ' ') {
		return count;
	}
	if_got_space2(count + 1);  // there's no statement to be evaluated after this,
	// so return is only done one time, unlike the above function
}

// main function
int main(int argc, char* argv[]) {
	int count = 0;
	count = if_got_space2(1);
	printf("Space occured after %d letter", count - 1);
	return 0;
}
