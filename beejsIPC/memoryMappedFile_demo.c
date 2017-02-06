#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <errno.h>

#define handle_error(msg) \
	do { perror(msg); exit(EXIT_FAILURE); } while (0)

int main(int ac, char *av[])
{
	FILE *file;
	int fd;

	char *data;
	char initial_w[6] = "hello";
	char initial_r[6];
	char later_w[6] = "kexin";
	char later_r[6];

	file = fopen("memory_mapped_file.txt", "w+");
	if (file == NULL) {
		handle_error("fopen failed");
	}

	/* convert file pointer to file descriptor */
	fd = fileno(file);

	fprintf(file, "%s", initial_w);
	// fseek(file, 0L, SEEK_SET);
	rewind(file);
	fscanf(file, "%s", initial_r);
	rewind(file);

	if (strcmp(initial_r, initial_w) != 0) {
		handle_error("strcmp failed");
	}
	/**
	 * mmap
	 * (caddr_t)0             : let kernel choose a suitable virtual address
	 * 4096	                  : one page
	 * PROT_READ | PROT_WRITE : access type
	 * MAP_SHARED             : share your changes to the file with other processes
	 * 0                      : offset, from where to mapping
	 **/
	data = mmap((caddr_t) 0, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

	if (data == NULL) {
		handle_error("mmap failed");
	}

	pid_t pid;
	int rv;
	switch(pid = fork()) {
		case -1:
			handle_error("fork failed");
		case 0:
			printf("Child process! \n");
			strcpy(data, later_w);
			printf("Child changed the memory_mapped_file.txt!\n");
			exit(rv);
		default:
			printf("Parent process! \n");
			fscanf(file, "%s", later_r);
			while (strcmp(later_r, later_w) != 0) {
				printf("Parent is waiting ... \n");
				rewind(file);
				fscanf(file, "%s", later_r);
			}
			printf("Parent process got it!\n");
			wait(&rv);
	}

	/* munmap */
	munmap(data, 4096);
	fclose(file);
	close(fd);
	return 0;
}
