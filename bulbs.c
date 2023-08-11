#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{

    string text = get_string("Text: ");

    for (int i = 0, n = strlen(text); i < n; i++)
    {

        unsigned char byte = text[i];
        int rem;
        int quotient = byte;
        int bi_num[8];
        for (int j = 0; j < 8; j++)
        {

            rem = quotient % 2;

            bi_num[j] = rem;

            quotient = quotient / 2;
        }
        for (int k = 7; k >= 0; k--)
        {

            print_bulb(bi_num[k]);
        }

        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}