#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SUCCESS 0
#define TRUE 1
#define FALSE 0

int is_prime(int num)
{
    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return FALSE;
        }
    }
    return TRUE;
}

void palprime(int num)
{
    int cnt = 0;
    if (num >= 2)
    {
        printf("%d ", 2);
        cnt++;
        if (num > 3)
        {
            printf("%d ", 3);
            cnt++;
            if (num > 5)
            {
                printf("%d ", 5);
                cnt++;
                if (num > 7)
                {
                    printf("%d ", 7);
                    cnt++;
                    if (num > 11)
                    {
                        printf("%d ", 11);
                        cnt++;
                        int pal;
                        int a[4] = {1, 3, 7, 9};
                        for (int i = 0; i < 4; i++)
                        {
                            for (int j = 0; j < 10; j++)
                            {
                                pal = a[i] * 101 + j * 10;
                                if (pal <= num && is_prime(pal))
                                {
                                    printf("%d ", pal);
                                    cnt++;
                                }
                                else if (pal > num)
                                {
                                    printf("\ncount: %d\n", cnt);
                                    return;
                                }
                            }
                        }
                        for (int i = 0; i < 4; i++)
                        {
                            for (int j = 0; j < 10; j++)
                            {
                                for (int k = 0; k < 10; k++)
                                {
                                    pal = a[i] * 10001 + j * 1010 + k * 100;
                                    if (pal <= num && is_prime(pal))
                                    {
                                        printf("%d ", pal);
                                        cnt++;
                                    }
                                    else if (pal > num)
                                    {
                                        printf("\ncount: %d\n", cnt);
                                        return;
                                    }
                                }
                            }
                        }
                        for (int i = 0; i < 4; i++)
                        {
                            for (int j = 0; j < 10; j++)
                            {
                                for (int k = 0; k < 10; k++)
                                {
                                    for (int l = 0; l < 10; l++)
                                    {
                                        pal = a[i] * 1000001 + j * 100010 + k * 10100 + l * 1000;
                                        if (pal <= num && is_prime(pal))
                                        {
                                            printf("%d ", pal);
                                            cnt++;
                                        }
                                        else if (pal > num)
                                        {
                                            printf("\ncount: %d\n", cnt);
                                            return;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    printf("\ncount: %d\n", cnt);
}

int main(int argc, char *argv[])
{
    int n = atoi(argv[1]);
    // int n = 100;
    int cnt = 0;
    clock_t start, end;
    start = clock();
    palprime(n);
    end = clock();
    double diff = end - start; // ms
    printf("%f  ms", diff);
    return SUCCESS;
}
