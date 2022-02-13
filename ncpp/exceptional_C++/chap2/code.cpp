#include <iostream>

void pretty_format(int i, char* buf)
{
	sprintf(buf, "%4d", i);
}

int main()
{
	char b[5];
	//pretty_format(1, b);
	pretty_format(1000502, b);
	printf("%s", b);
}
