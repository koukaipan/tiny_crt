#include "unistd.h"

int main(int argc, char* argv[])
{
	long len;
	char buf[256];

	len = read(STDIN_FILENO, buf, 256);
	write(STDOUT_FILENO, buf, len);

	return 0;
}

