/* copy file1 file2: copy file1 to file2. 
   UNIX implemenation
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#define BUF_SIZE 256

int main(int argc, char *argv[]) {
    int in_fd, out_fd;
    char rec[BUF_SIZE];
    ssize_t bytes_in, bytes_out;
    if (argc != 3) {
        printf("Usage: cp file1 file2\n");
        return 1;
    }
    in_fd = open(argv[1], O_RDONLY);
    if (in_fd == -1) {
        perror(argv[1]);
        return 2;
    }
    out_fd = open(argv[2], O_WRONLY | O_CREAT, 0666);
    if (out_fd == -1) {
        perror(argv[2]);
        return 3;
    }
    while ((bytes_in = read(in_fd, &rec, BUF_SIZE)) > 0) {
        bytes_out = write(out_fd, &rec, (size_t) bytes_in);
        if (bytes_in != bytes_out) {
            perror("Fatal write error.");
            return 4;
        }
    }
    close(in_fd);
    close(out_fd);
    return 0;
}