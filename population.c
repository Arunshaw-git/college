#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int end;
    int i;
    int n;
    do
    {
        n = get_int("Starting size:\n");
    }
    while (n < 1);
    ;

    do
    {
        end = get_int("End size:\n");
    }
    while (end <= n);

    for (i = 0; n <= end; i++)
    {
        n = n + (n / 3) - (n / 4);
    }
    printf("Years: %i\n", i);

    return 0;
}
