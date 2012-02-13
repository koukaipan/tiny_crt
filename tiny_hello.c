void print(char* s)
{
	asm (	"movq $28, %%rdx	\n\t"	//length of str
			"movq %0, %%rcx		\n\t" //buf
			"movq $0, %%rbx		\n\t" //STDOUT_FILENO
			"movq $4, %%rax		\n\t" //syscall number of write()
			"int $0x80			\n\t"
			:
			:"r" (s)
			:"rdx", "rcx", "rbx");
}

int main(int argc, char* argv[])
{
	char* str = "hello world without stdlibc\n";
	print(str);
	
	return 0;
}

