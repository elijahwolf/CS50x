#include <cs50.h>
#include <stdio.h>

// Create mario pyramids using hashtags, prompting user for height.

string addSpace();
string addPoundSign();

int main(void)
{
    // PROMPT FOR HEIGHT
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height <= 0 || height > 8);

    // PRINT PYRAMID
    for (int i=1; i <= height; i++)
    {
        // SPACES
        for (int j=1; j<=height-i; j++)
        {
            printf("%s", addSpace());
        }

        // POUND SIGN
        for (int k=height-i; k<height; k++)
        {
            printf("%s", addPoundSign());
        }

        // 2 SPACES
        for (int l=1; l<3; l++)
        {
            printf("%s", addSpace());
        }

        // POUND SIGN
        for (int k=height-i; k<height; k++)
        {
            printf("%s", addPoundSign());
        }

        // NEW LINE
        printf("\n");
    }
}

// ADD SPACE
string addSpace()
{
    string space = " ";
    return space;
}

// ADD POUND SIGN
string addPoundSign()
{
    string pound = "#";
    return pound;
}
