#include <cs50.h>
#include <stdio.h>

// A program that prompts the user for a credit card number and then reports whether it is a valid American Express, MasterCard, or Visa card number.

int main(void)
{
    // GET CREDIT CARD NUMBER
    long number = get_long("Number: ");
    long storedNumber = number;

    // CHECK IF INVALID
    int i = 1;
    int total1 = 0;
    int total2 = 0;
    do
    {
        int digit = number % 10;

        // IF EVEN NUMBER
        if(i % 2 == 0)
        {
            // ADD THE INDIVIDUAL DIGITS
            digit *= 2;
            while(digit)
            {
                int sum = digit % 10;
                total1 += sum;
                digit /= 10;
            }
        }
        // IF ODD NUMBER
        else
        {
            total2 += digit;
        }
        number /= 10;
        i++;
    }
    while (number);

    // CHECK IF VALID CREDIT CARD NUMBER
    int checksum = total1 + total2;
    if (checksum % 10 == 0)
    {
        // GET CARD LENGTH
        int cardLength = i-1;

        // GET STARTING 2 DIGITS
        long startingDigits = storedNumber;
        while (startingDigits >= 100)
        {
            startingDigits /= 10;
        }

        // CHECK IF AMEX if 15 characters
        if (cardLength == 15 && (startingDigits == 34 || startingDigits == 37))
        {
            printf("AMEX\n");
        }

        // CHECK IF MASTERCARD
        else if (cardLength == 16 && (startingDigits == 51 || startingDigits == 52 || startingDigits == 53 || startingDigits == 54 || startingDigits == 55))
        {
            printf("MASTERCARD\n");
        }

        // CHECK IF VISA
        else if ((cardLength == 16 || cardLength == 13) && startingDigits/10 == 4)
        {
            printf("VISA\n");
        }

        // OTHERWISE, INVALID
        else
        {
            printf("INVALID\n");
        }
    }
    // IF IT DOESN'T PASS CHECKSUM, INVALID
    else
    {
        printf("INVALID\n");
    }
}
