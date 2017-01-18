/* copy file1 file2: copy file1 to file2. */

#include <stdio.h>
#include <errno.h>
#define BUF_SIZE 256

int main(int argc, char *argv[]) {
    FILE *fin, *fout;
    char rec[BUF_SIZE];
    size_t bytes_in, bytes_out;
    if (argc != 3) {
        printf("Usage: cp file1 file2\n");
        return 1;
    }
    fin = fopen(argv[1], "rb");
    if (fin == NULL) {
        perror(argv[1]);
        return 2;
    }
    fout = fopen(argv[2], "wb");
    if (fout == NULL) {
        perror(argv[2]);
        return 3;
    }
    while ((bytes_in = fread(rec, 1, BUF_SIZE, fin)) > 0) {
        bytes_out = fwrite(rec, 1, bytes_in, fout);
        if (bytes_in != bytes_out) {
            perror("Fatal write error.");
            return 4;
        }
    }
    fclose(fin);
    fclose(fout);
    return 0;
}