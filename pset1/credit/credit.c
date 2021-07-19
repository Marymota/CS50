#include "cs50.h"
#include "stdio.h"
#include "math.h"

// Check card number first digits
int checkstart(long card_number)
{
    int len = 0;

    while (card_number > 55)
    {
        card_number = card_number / 10;
    }
    if ((card_number == 34 || card_number == 37) || (card_number >= 51 && card_number <= 55))
    {
        return (card_number);
    }
    else if (card_number / 10 == 4)
    {
        return (card_number / 10);
    }
    return (0);
}

// Check card number length
int checklen(long card_number)
{
    int len = 0;

    while (card_number)
    {
        card_number = card_number / 10;
        len++;
    }
    if (len != 14 && (len >= 13 && len <= 16))
    {
        return (len);
    }
    return (0);
}

// Check Luhn's Algorithm
int checksum(long card_number)
{
    long number = card_number;
    int digit = 0;
    long sum = 0;

    // While iterating through the card number
    // Multiply every other digit by 2, starting with the number’s second-to-last digit
    // If the result of the multiplication has more that one digit sum them
    // Sum the other numbers
    // Return one if the last digit od the result is a zero and return zero otherwise
    while (number > 0)
    {
        digit = number % 10;
        sum += digit;
        number = number / 10;
        digit = (number % 10) * 2;
        if (digit > 9)
        {
            sum += digit % 10;
            sum += digit / 10;
        }
        else
        {
            sum += digit;
        }
        number = number / 10;
    }
    if (sum % 10 == 0)
    {
        return (1);
    }
    return (0);
}

int main(void)
{
    long card_number;
    card_number = get_long("Number: ");

    // Check's Luhn's Algorithm, length and first digits to identify the card brand
    // Returns invalid if all the requirements are not met for any brand
    // American Express requires: 15 length, 34 or 37 as first digits
    // Mastercard requires: 16 length, between 51 and 55 as first digits
    // Visa requires: 16 or 13 length, a 4 as first digits
    if (checksum(card_number))
    {
        if (checklen(card_number) == 15)
        {
            if (checkstart(card_number) == 34 || (checkstart(card_number) == 37))
            {
                printf("AMEX\n");
                return (0);
            }
        }
        else if (checklen(card_number) == 16)
        {
            if ((checkstart(card_number) >= 51 && (checkstart(card_number) <= 55)))
            {
                printf("MASTERCARD\n");
                return (0);
            }
            else if ((checkstart(card_number) == 4))
            {
                printf("VISA\n");
                return (0);
            }
        }
        else if (checklen(card_number) == 13 && (checkstart(card_number) == 4))
        {
            printf("VISA\n");
            return (0);
        }
    }
    printf("INVALID\n");
    return (0);
}
