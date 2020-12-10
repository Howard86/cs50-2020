#include <stdio.h>
#include <cs50.h>
#include <string.h>

int get_digits(long number);
int calculate_checksum(long number, int digits);
int get_product_sum(int digit);
long power_of_ten(int digit);
string get_card_type(long number, int digits);

int main(void)
{
    // Mininum valid VISA number: start with 4 with 13 digits, i.e. 4,000,000,000,000
    long MIN = 4 * power_of_ten(12);

    // Maxinim valid MasterCard number: start with 55 with 16 digits 5,599,999,999,999,999
    long MAX = 56 * power_of_ten(14);

    long input = get_long("Number: ");

    // A quick number check
    if (input < MIN || input >= MAX)
    {
        printf("INVALID");
    }
    else
    {
        int digits = get_digits(input);
        string card_type = get_card_type(input, digits);

        if (strcmp(card_type, "INVALID") != 0)
        {
            int checksum = calculate_checksum(input, digits);

            printf("%s", checksum % 10 == 0 ? card_type : "INVALID");
        }
        else
        {
            printf("INVALID");
        }
    }
    printf("\n");
}

int get_digits(long number)
{
    long divider;
    long base_ten = power_of_ten(15);
    for (int i = 16; i > 12; i--)
    {
        divider = number / base_ten;
        base_ten /= 10;

        if (divider > 0 && i != 14)
        {
            return i;
        }
    }
    return -1;
}

int calculate_checksum(long number, int digits)
{
    int digit;
    int sum = 0;
    long modulo_base = 10;

    for (int i = 0; i < digits; i++)
    {
        digit = (int)((number % modulo_base) * 10 / modulo_base);
        sum += (i % 2 == 0) ? digit : get_product_sum(digit);

        modulo_base *= 10;
    }

    return sum;
}

int get_product_sum(int digit)
{
    int result = digit * 2;
    return result > 9 ? (1 + result % 10) : result;
}

string get_card_type(long number, int digits)
{
    int first_two_digits = (int)(number / power_of_ten(digits - 2));
    switch (digits)
    {
        case 16:
        {
            // As Visa
            // Valid if starting with 4
            if (first_two_digits > 39 && first_two_digits < 50)
            {
                return "VISA";
            }

            // As MasterCard
            // Only valid if starting with 51, 52, 53, 54, 55
            if (first_two_digits > 50 && first_two_digits < 56)
            {
                return "MASTERCARD";
            }
            return "INVALID";
        }

        case 15:
        {
            // As American Express
            // Only valid if starting with 34 or 37
            if (first_two_digits == 34 || first_two_digits == 37)
            {
                return "AMEX";
            }
            return "INVALID";
        }

        case 13:
        {
            // As Visa
            // Valid if starting with 4
            if (first_two_digits > 39 && first_two_digits < 50)
            {
                return "VISA";
            }
            return "INVALID";
        }

        default:
            return "INVALID";
    }
}

// get power of 10
long power_of_ten(int digit)
{
    long result = 10;

    // iterate
    for (int i = 1; i < digit; i++)
    {
        result *= 10;
    }
    return result;
}
