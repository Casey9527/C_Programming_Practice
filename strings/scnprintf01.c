#include <stdio.h>
#include <string.h>
#include <linux/debugfs.h>

int main (int argc, char *argv[])
{
    char buffer1 [10]= {""};
    int cx1;
    cx1 = scnprintf (buffer1, 10, "%s", "justfor");
 
    printf("src lenth < n buffer1 is:%s, lenth is:%d return value:%d\n",buffer1, strlen(buffer1),cx1);
 
    char buffer2 [10]= {""};
    int cx2;
    cx2 = scnprintf (buffer2, 10, "%s", "justfortes");
 
    printf("src lenth = n buffer2 is:%s, lenth is:%d return value:%d\n",buffer2, strlen(buffer2),cx2);
    
    char buffer3 [10]= {""};
    int cx3;
    cx3 = scnprintf (buffer3, 10, "%s", "justfortest");
 
    printf("src lenth > n buffer3 is:%s, lenth is:%d return value:%d\n",buffer3, strlen(buffer3),cx3);
    return 0;
}
