#include <stdio.h>
#include <string.h>

void echo_input( char* user_input ) {
	char buffer[20];
	strcpy( buffer, user_input );
	printf("\n\n%s\n\n", buffer);
}

int main( int argc, char** argv ) {
	echo_input( argv[1] );
}
