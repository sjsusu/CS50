#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

string to_lower(string text);
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    //Asks user for a string of text
    string txt = get_string("Text: ");
    txt = to_lower(txt);

    //Finds the # of letters, words, and sentences there are in the text
    int letters = count_letters(txt);
    int words = count_words(txt);
    int sentences = count_sentences(txt);

    //Calculates the index
    float L = (letters / (float) words) * 100;
    float S = (sentences / (float) words) * 100;
    float index = 0.0588 * L - 0.296 *  S - 15.8;
    index = round(index);

    //Tells user the resulting index
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
        printf("Grade %i\n", (int)index);
    }

}

//Converts any uppercase letters to lowercase letters
string to_lower(string text)
{
    int l = strlen(text);
    for (int i = 0; i < l; i++)
    {
        if (islower((int)text[i]) == 0)
        {
            text[i] = tolower(text[i]);
        }
    }

    return text;
}

//Counts the # of letters in the given text
int count_letters(string text)
{
    int num_letters = 0;
    int l = strlen(text);
    for (int i = 0; i < l; i++)
    {
        if (text[i] >= 97 && text[i] <= 122)
        {
            num_letters++;
        }
    }

    return num_letters;
}

//Counts the # of words in the given text
int count_words(string text)
{
    int num_words = 0;
    int l = strlen(text);
    for (int i = 0; i < l; i++)
    {
        //Counts for words by checking for spaces and ignores multiple spaces (32 is ASCII for a space:" ")
        if (text[i] == 32 && text[i - 1] != 32)
        {
            num_words++;
        }
    }

    //Accounts for the final word in the given text w/ a period (46 is ASCII for period: ".")
    if (text[l - 1] == 46 && text[l - 2] != 32)
    {
        num_words++;
    }
    //Accounts for the final word in the given text ending w/ a letter
    else if (text[l - 1] >= 97 && text[l - 1] <= 122 && text[l] == 0)
    {
        num_words++;
    }

    return num_words;
}

//Counts the # of sentences in the given text
int count_sentences(string text)
{
    int num_sentences = 0;
    int l = strlen(text);
    for (int i = 0; i < l; i++)
    {
        //Checks for period: "."
        if (text[i] == 46 && text[i - 1] != 0)
        {
            num_sentences++;
        }
        //Checks for exclamation point: "!"
        else if (text[i] == 33 && text[i - 1] != 0)
        {
            num_sentences++;
        }
        //Checks for question mark: "?"
        else if (text[i] == 63 && text[i - 1] != 0)
        {
            num_sentences++;
        }
    }

    return num_sentences;
}
