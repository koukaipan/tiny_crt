#ifndef __UNISTD_H__
#define __UNISTD_H__

/* predefined file descriptors */
#define STDIN_FILENO	0	/* standard input (keyboard) */
#define STDOUT_FILENO	1	/* standard output (screen) */
#define STDERR_FILENO	2	/* standard error output (screen) */

long write(int fd, const void *buf, unsigned long count);
long read(int fd, void *buf, unsigned long count);

#endif //__UNISTD_H__
