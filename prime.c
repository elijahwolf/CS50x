#include <cs50.h>
#include <stdio.h>

// Practice Problem 1
// An algorithm to generate all prime numbers in a range specified by the user

bool prime(int number);

int main(void)
{
    // Get minimum value
    int min;
    do
    {
        min = get_int("Minimum: ");
    }
    while (min < 1);

    // Get max value
    int max;
    do
    {
        max = get_int("Maximum: ");
    }
    while (min >= max);

    // Calculate prime numbers in given range
    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }
}

// Calculate if number is prime
bool prime(int number)
{
    if (number == 1)
    {
        return false;
    }

    for (int j = 2; j < number; j++)
    {
        int check = number % j;
        if (check == 0)
        {
            return false;
        }
    }

    return true;
}
