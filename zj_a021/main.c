// a021. 大數運算

#include <stdio.h>
#include <string.h>

#define dbg(fmt, ...) printf("[%s] " fmt, __func__, __VA_ARGS__)
#define LEN (510)

void rev(char *s)
{
    int len = strlen(s);
    for (int i = 0; i < len / 2; ++i)
    {
        char t = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = t;
    }

    dbg("%s\n", s);
}

static int adddig(char a, char b, int c, char *res)
{

    int da = a - '0';
    int db = b - '0';
    int r = da + db + c;

    *res = r % 10 + '0';
    dbg("%c + %c = %d\n", a, b, r);
    return r / 10;
}

void add(char *a, char *b, char *res)
{
    int i;
    rev(a);
    rev(b);

    int la = strlen(a);
    int lb = strlen(b);
    int lo = (la > lb ? la : lb);

    // dbg("%d\n", lo);
    int carry = 0;
    for (i = 0; i <= lo; i++)
    {
        char aa = a[i],
             bb = b[i];
        if (0 == a[i])
            aa = '0';
        if (0 == b[i])
            bb = '0';

        if (aa != '0' || bb != '0' || carry != 0)
            carry = adddig(aa, bb, carry, res + i);
    }

    *(res + i) = 0;
    rev(res);
}

void sub(char *a, char *b, char *res)
{
    int i;
    rev(a);
    rev(b);

    int la = strlen(a);
    int lb = strlen(b);
    int lo = (la > lb ? la : lb);

    // dbg("%d\n", lo);
    int carry = 0;
    for (i = 0; i <= lo; i++)
    {
        char aa = a[i],
             bb = b[i];
        if (0 == a[i])
            aa = '0';
        if (0 == b[i])
            bb = '0';

        if (aa != '0' || bb != '0' || carry != 0)
            carry = adddig(aa, bb, carry, res + i);
    }
    *(res + i) = 0;
    rev(res);
}

int main()
{
    char buf[LEN * 2] = {0}, a[LEN] = {0}, b[LEN] = {0};
    // fgets(buf, LEN * 2, stdin);
    // buf[strcspn(buf, "\n")] = 0;
    gets_s(buf, LEN * 2 - 1);
    char *p = strtok(buf, " ");
    int step = 0;
    char op;
    while (p)
    {
        // dbg("%s\n", p);
        switch (step)
        {
        case 0:
            strcpy(a, p);
            step++;
            break;
        case 1:
            op = *p;
            step++;
            break;
        case 2:
        default:
            strcpy(b, p);
            break;
        }

        p = strtok(NULL, " ");
    }

    switch (op)
    {
    case '+':
        add(a, b, buf);
        break;
    case '-':
        break;
    case '*':
        break;
    case '/':
    default:
        break;
    }

    printf("%s", buf);
    return 0;
}