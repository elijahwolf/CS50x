#include <cs50.h>
#include <stdio.h>

// Practice Problem 1
// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// Calculate half of the bill
float half(float bill, float tax, int tip)
{
    float taxPercent = 0.01*tax;
    float tipPercent = 0.01*tip;
    float subTotal = (bill*(1+(taxPercent)));
    float total = (subTotal*(1+(tipPercent)))/2;
    return total;
}
