extern int main(int argc, char* argv[]);

void exit(int status)
{
	asm (	"movl %0, %%ebx	\n\t"
			"movq $1, %%rax		\n\t"
			"int $0x80			\n\t"
			:
			:"r"(status)
			:);
}

void _start()
{
	int ret;
	int argc=0;
	char** argv = 0;

	/* antoher initialization */

	ret = main(argc, argv);
	exit(ret);
}
