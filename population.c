#include <cs50.h>
#include <stdio.h>

// Lab 1
// Determine how long it takes for a population to reach a particular size.

int main(void)
{
    // TODO: Prompt for start size
    int population;
    do
    {
        population = get_int("Start size: ");
    }
    while (population < 9);

    // TODO: Prompt for end size
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < population);

    // TODO: Calculate number of years until we reach threshold
    int born;
    int dead;
    int years;
    for (years = 0; population < end; years++)
    {
        born = population / 3;
        dead = population / 4;
        population = population + born - dead;
    }

    // TODO: Print number of years
    printf("Years: %i\n", years);
}
