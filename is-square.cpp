#include <iostream>
#include <stdio.h>

int is_square(int num)
{
    int len = 0;
    int save = num;

    for (int i = 0;i < 32;i++) {
        if (num & 1)
            len = i;
        num >>= 1;
    }

    len = (len>>1) + 1;
//    printf("len is %d\n", len);

    return (((len*len) == save) || ((len+1)*(len+1) == save))?1:0;
}

int main(int argc, char **argv)
{
    int num[] = {3, 4, 7, 9, 101, 256};

    for (int i = 0; i < 6; i++)
        printf("%d -> %d\n", num[i], is_square(num[i]));

    return 0;
}
