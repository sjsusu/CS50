#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Array used to check if a duplicate letter has been used position will change to 1 if used
int letters_used[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
//Length of key
const int LENGTH = 26;

int check_arguements(int argc);
int check_length(string k);
int check_letters(string k);
int check_duplicates(string k);
char convert_ptxt(string txt, string key, int i);

int main(int argc, string argv[])
{
    //Checks that 2 args are given
    if (check_arguements(argc) == 1)
    {
        return 1;
    }

    string key = argv[1];

    //Checks the 26 characters are given in key
    if (check_length(key) == 1)
    {
        return 1;
    }

    //Checks that all 26 characters are letters in key
    if (check_letters(key) == 1)
    {
        return 1;
    }

    //Checks for duplicate letters in key
    if (check_duplicates(key) == 1)
    {
        return 1;
    }

    //Asks user for plain text
    string ptxt = get_string("plaintext:  ");

    //Encrypts and prints out the cipher text 1 char at a time
    printf("ciphertext: ");
    int length = strlen(ptxt);
    for (int i = 0; i < length; i++)
    {
        char ctxt = convert_ptxt(ptxt, key, i);
        printf("%c", ctxt);
    }
    printf("\n");


}

//Checks the # of command-line arguements given, exits if not 2.
int check_arguements(int argc)
{
    if (argc == 0)
    {
        printf("You must provide a key.\n");
        return 1;
    }
    else if (argc != 2)
    {
        printf("Too many arguements, only a single key is required.\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

//Checks the length of the given key, exits if not given 26 charcters.
int check_length(string k)
{
    int length = strlen(k);
    if (length != 26)
    {
        printf("The key requires 26 letters.\n");
        return 1;
    }

    return 0;
}

//Checks that the key contains all letters, exits if there is a character that is not a letter.
int check_letters(string k)
{
    for (int i = 0; i < LENGTH; i++)
    {
        if (isalpha(k[i]) == 0)
        {
            printf("All characters in key must be alphabetical.\n");
            return 1;
        }
    }

    return 0;
}

//Checks all the letters for any duplicates using the letters_used array (1 = taken , 0 = available)
int check_duplicates(string k)
{
    for (int i = 0; i < LENGTH; i++)
    {
        if (islower(k[i]) != 0)
        {
            int p = k[i] - 97;
            if (letters_used[p] == 1)
            {
                printf("All 26 letters must be unique.\n");
                return 1;
            }
            else
            {
                letters_used[p] = 1;
            }
        }
        else
        {
            int P = k[i] - 65;
            if (letters_used[P] == 1)
            {
                printf("All 26 letters must be unique.\n");
                return 1;
            }
            else
            {
                letters_used[P] = 1;
            }
        }
    }

    return 0;
}

//Converts a char in plain text to cipher text, returns the same char if not a letter
char convert_ptxt(string txt, string key, int i)
{
    char ctxt;

    //Converts lowercase letters
    if (islower(txt[i]) != 0)
    {
        int key_position = txt[i] - 97;
        char k = key[key_position];
        ctxt = tolower(k);

    }
    //Converts uppercase letters
    else if (isupper(txt[i]) != 0)
    {
        int KEY_position = txt[i] - 65;
        char K = key[KEY_position];
        ctxt = toupper(K);
    }
    //Returns non-letters
    else
    {
        return txt[i];
    }

    return ctxt;
}