#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// A program that calculates the approximate grade level needed to comprehend some text

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Get input
    string input = get_string("Text: ");

    // Count letters
    int letters = count_letters(input);

    // Count words
    int words = count_words(input);

    // Count sentences
    int sentences = count_sentences(input);

    // Calculation for Coleman-Liau index
    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;

    // Index to nearest integer
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Print index to user
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

// Count letters
int count_letters(string text)
{
    int charCount = 0;
    for (int i=0, length = strlen(text); i < length; i++)
    {
        if(isupper(text[i]) || islower(text[i]))
        {
            charCount += 1;
        }
    }
    return charCount;
}

// Count words
int count_words(string text)
{
    int wordCount = 1;
    for (int i=0, length = strlen(text); i < length; i++)
    {
        if(isspace(text[i]))
        {
            wordCount += 1;
        }
    }
    return wordCount;
}

// Count sentences
int count_sentences(string text)
{
    int sentenceCount = 0;
    for (int i=0, length = strlen(text); i < length; i++)
    {
        if(text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentenceCount += 1;
        }
    }
    return sentenceCount;
}
