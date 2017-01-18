

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>


int
main(int argc, char * argv[])
{
    if (argc != 3)
    {
        printf("Usage: ./copy copyfile newfile\n");
        exit(1);
    }
    int des, src;
    char buffer[256];
    int read_size, write_size;
    read_size = write_size = 0;
    
    src = open(argv[1], O_RDONLY);
    if (src == -1)
    {
        exit(1);
    }

    des = creat(argv[2], S_IRWXU | S_IRWXG | S_IRWXO);
    if (des == -1)
    {
        exit(1);
    }
    
    while ( (read_size = read(src, buffer, 256)) > 0 )
    {
        write_size = write(des, buffer, read_size);
        if (read_size != write_size) {
            printf("write error\n");
            exit(1);
        }
    }
    close(src);
    close(des);
    exit(0);
}
