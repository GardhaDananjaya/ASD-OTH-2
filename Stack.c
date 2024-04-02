#include <stdio.h>

void printStack(int *stack, int count, char *name)
{
    printf("Stack %s : ");
    if (count > 0)
    {
        printf("[ ");
        for (int i = 0; i < count; i++)
        {
            printf("%d ", stack[i]);
        }
        printf("]");
    }
    else
    {
        printf("[] ( Empty )");
    }
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int twoStacks(int maxSum, int *a, int a_count, int *b, int b_count)
{
    int i = 0, j = 0, sum = 0, count = 0, maxCount = 0;

    while (i < a_count && sum + a[i] <= maxSum)
    {
        sum += a[i];
        printf("Mengambil nilai %d dari Stack A\n", a[i]);
        i++;
        count++;
    }
    maxCount = count;

    while (j < b_count && i >= 0)
    {
        if (sum + b[j] <= maxSum)
        {
            sum += b[j];
            printf("Mengambil nilai %d dari Stack B\n", b[j]);
            j++;
            count++;
            maxCount = max(maxCount, count);
        }
        else if (i > 0)
        {
            i--;
            sum -= a[i];
            printf("Mengembalikan nilai %d ke Stack A\n", a[i]);
            count--;
        }
        else
        {
            break;
        }
    }

    return maxCount;
}


int main()
{
    int g;
    printf("Input Jumlah Games: ");
    scanf("%d", &g);

    while (g--)
    {
        int n, m, maxSum;
        printf("Input Stack A, Stack B, maxSum: ");
        scanf("%d %d %d", &n, &m, &maxSum);

        int a[n];
        printf("Input Element Stack A: ");
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        int b[m];
        printf("Input Element Stack B: ");
        for (int i = 0; i < m; i++)
            scanf("%d", &b[i]);

        printf("\n");
        printf("---------------------------------------------------------------\n");
        printStack(a, n, "A");
        printf("\n");
        printStack(b, m, "B");
        printf("\n\n");
        printf("\nOutput: %d\n", twoStacks(maxSum, a, n, b, m));
        printf("---------------------------------------------------------------\n");
    }

    return 0;
}
