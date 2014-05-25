//有一个由大小写组成的字符串，现在需要对他进行修改，将其中的所有小写字母排在答谢字母的前面（大写或小写字母之间不要求保持原来次序），如有可能尽量选择时间和空间效率高的算法 c语言函数原型void proc（char *str） 也可以采用你自己熟悉的语言

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define swap(a, b)                              \
    do {                                        \
        char tmp;                               \
        tmp = (a);                              \
        a = (b);                                \
        b = tmp;                                \
    } while (0)

void proc(char *str)
{
    char *p0 = str, *p1 = str + strlen(str) - 1;

    while (p0 < p1) {
        while (*p0 >= 'a' && *p0 <= 'z' && p0 < p1)
            p0++;
        while (*p1 >= 'A' && *p1 <= 'Z' && p0 < p1)
            p1--;
        if (p0 < p1) {
            char tmp;
            tmp = *p0;
            *p0 = *p1;
            *p1 = tmp;
            p0++;
            p1--;
        }
    }
}

int main(int argc, char **argv)
{
    char *str = "hadDadDiFdasfU";
    char *str2 = (char *)malloc(32);
    strcpy(str2, str);

    proc(str2);

    printf("%s\n", str2);
}
