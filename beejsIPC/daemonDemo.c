#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// init daemon
void init_daemon()
{
	pid_t pid;
	int i = 0;

	if ((pid == fork()) == -1) {
		printf("Fork error !\n");
		exit(1);
	}

	if (pid != 0) {
		exit(0);		// parent process exits
	}

	setsid();			

	if ((pid = fork()) == -1) {
		printf("Fork error !\n");
		exit(-1);		
	}

	if (pid != 0) {
		exit(0);
	}

	chdir("/tmp");
	umask(0);
	for (; i < getdtablesize(); ++i) {
		close(i);
	}
	return;
}

int main(int ac, char *av[])
{
	int fp;
	time_t t;
	char buf[] = {"This is a daemon:  "};
	char *datetime;
	int len = 0;
	//printf("The NOFILE is: %d\n", NOFILE);
	//printf("The tablesize is: %d\n", getdtablesize());
	//printf("The pid is: %d\n", getpid());

	init_daemon();

	while(1) {
		if (-1 == (fp = open("/tmp/daemon.log", O_CREAT|O_WRONLY|O_APPEND, 0600))) {
			printf("Open file error !\n");
			exit(1);
		}

		len = strlen(buf);
		write(fp, buf, len);
		t = time(0);
		datetime = asctime(localtime(&t));
		len = strlen(datetime);
		write(fp, datetime, len);
		close(fp);
		sleep(60);
	}
	return 0;
}

// http://alfred-sun.github.io/blog/2015/06/18/daemon-implementation/