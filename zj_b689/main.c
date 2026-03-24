// ZEROJUDGE b589

#include <stdio.h>

int main()
{
    int N, // row
        M, // columns
        x, y; /* point coordinate */

    scanf("%d %d", &N, &M);

    char s[N][M];

    for (int i = 0; i < N; ++i)
    {
        scanf("%s", s[i]);
    }

#if 0
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            printf("%c", s[i][j]);
        }
        printf("\n");
    }
#endif

#if 0 /* 無法處理以字元.標示，卻無法到達的格子 */
    for (int i = 1; i < N - 1; ++i)
    {
        for (int j = 1; j < M - 1; ++j)
        {
            int sum = 0;
            sum += (s[i][j - 1] == '.' ? 1 : 0);
            sum += (s[i][j + 1] == '.' ? 1 : 0);
            sum += (s[i - 1][j] == '.' ? 1 : 0);
            sum += (s[i + 1][j] == '.' ? 1 : 0);

            if (sum == 1)
            {
                x = i;
                y = j;
            }
        }
    }

    printf("%d %d", x + 1, y + 1);
#endif


    return 0;
}