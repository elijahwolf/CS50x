#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// A program that implements a substitution cipher

int validate_key (string key);
string encipher (string input, string key);

int main(int argc, string argv[])
{
    // Check command-line arguments
    if(argc != 2){
        if(argc == 1){
            printf("NOT ENOUGH COMMAND-LINE ARGUMENTS\n");
        }
        else{
            printf("TOO MANY COMMAND-LINE ARGUMENTS\n");
        }
        return 1;
    }

    // Get key
    string key = argv[1];

    // Validate key
    if (validate_key(key) == 1){
        return 1;
    }

    // Get plaintext
    string plainText = get_string("plaintext: ");

    // Encipher
    string cipherText = encipher(plainText, key);

    // Print ciphertext
    printf("ciphertext: %s\n", cipherText);

    return 0;
}

// Validate key
int validate_key (string key)
{
    // Check key length
    if (strlen(key) != 26){
        printf("MUST CONTAIN 26 CHARACTERS\n");
        return 1;
    }
    // Check for non-alphabetic characters
    for(int i=0, len = strlen(key); i<len; i++){
        if(!isupper(key[i]) && !islower(key[i])){
            printf("CAN'T INCLUDE NON-ALPHABETIC CHARACTERS\n");
            return 1;
        }
        // Check for repeating characters
        for(int j=i+1; j < len; j++){
            if(tolower(key[i]) == tolower(key[j])){
                printf("CAN'T INCLUDE REPEATING CHARACTERS\n");
                return 1;
            }
        }
    }
    return 0;
}

// Encipher
string encipher (string input, string key)
{
    int len = strlen(input);
    char* encipherText = (char*)malloc(len + 1);

    // Check for memory allocation failure
    if (encipherText == NULL) {
        return NULL;
    }

    // For each alphabetic character, determine what letter it maps to
    for (int i = 0; i < len; i++){
        if (islower(input[i])){
            encipherText[i] = tolower(key[input[i] - 'a']);
        }
        else if (isupper(input[i])){
            encipherText[i] = toupper(key[input[i] - 'A']);
        }
        // Leave non-alphabetic characters as-in
        else{
            encipherText[i] = input[i];
        }
    }
    // Null-terminatation
    encipherText[len] = '\0';

    return encipherText;
}
