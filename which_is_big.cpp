//定义一个宏，比较两个数a、b的大小，不能使用大于、小于、if语句

#include <stdio.h>

#define max2(a, b)                              \
    ({                                          \
        (unsigned int)((a-b)>>31);              \
    })

int main(int argc, char **argv)
{
    unsigned int ret;

    ret = max2(3, 5);
    printf("%d\n", ret);
}
