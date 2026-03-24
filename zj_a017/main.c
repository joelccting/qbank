//a017. 五則運算

#include <stdio.h>
#include <string.h>

#define LEN (80)

int main()
{
    char buf[LEN + 1];
    int stack[80];
    int stop = 0;
    char op[80];
    int otop = 0;
    while (fgets(buf, LEN, stdin))
    {
        buf[strnspn(buf, "\n")] = 0; 

        char *p = strtok(buf, " ");
        while (p)
        {
            p = strtok(NULL, " ");
        }
    }
    return 0;
}