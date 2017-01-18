
#include <stdio.h>

void swap(char balls[], int a, int b)
{
    int temp = balls[a];
    balls[a] = balls[b];
    balls[b] = temp;
}

void sortballs(char balls[], int size)
{
    int i;
    int red = 0;
    int blue = size - 1;
    
    for (i = 0; i <= blue; ++i) {
        if (red <= blue) {
            if (balls[i] == 'b') {
                swap(balls, i, blue);
                blue--;
                i--;
            } else if (balls[i] == 'r') {
                swap(balls, i, red);
                red++;
            }
        }
    }
}

int main(void)
{
    char balls[] = {'g', 'b', 'r', 'g', 'r', 'r', 'r', 'b'};
    
    int i;
    int size = sizeof(balls) / sizeof(balls[0]);
    sortballs(balls, size);
    for (i = 0; i < size; ++i)
        printf("%c ", balls[i]);
    printf("\n");
    return 0;
}