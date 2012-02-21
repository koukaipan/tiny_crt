/**
 * @file    unistd.c
 * @author  Ying-Shiuan Pan
 * @brief   implement system call wrappers
 * 
 *  NOTE: The functions here are based on x64 Linux
 */

/** 
 * @brief write()
 * @return the number of written bytes
 */
long write(int fd, const void *buf, unsigned long count)
{
	long ret;
	asm (	"movq $1, %%rax	\n\t" //rax: syscall number of write()
			"movq %1, %%rdi	\n\t" //rbx: file descriptor
			"movq %2, %%rsi	\n\t" //rcx: buf
			"movq %3, %%rdx	\n\t" //rdx: count
			"syscall		\n\t"
			"movq %%rax, %0	\n\t"
			:"=m"(ret)
			:"m" (fd), "m"(buf), "m"(count)
			:);
	return ret;
}

/** 
 * @brief read()
 * @return the number of read bytes
 */
long read(int fd, void *buf, unsigned long count)
{
	long ret;
	asm (	"movq $0, %%rax	\n\t" //rax: syscall number of read()
			"movq %1, %%rdi	\n\t" //rbx: file descriptor
			"movq %2, %%rsi	\n\t" //rcx: buf
			"movq %3, %%rdx	\n\t" //rdx: count
			"syscall		\n\t"
			"movq %%rax, %0	\n\t"
			:"=m"(ret)
			:"m" (fd), "m"(buf), "m"(count)
			:);
	return ret;
}

