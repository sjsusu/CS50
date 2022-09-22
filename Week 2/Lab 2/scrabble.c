#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    //Declares winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

//Computes the score
int compute_score(string word)
{
    int total_pts = 0;

    int n = strlen(word);
    for (int i = 0; i < n; i++)
    {
        //Makes sure that the current char is lowercase
        if (islower(word[i]) == 0)
        {
            word[i] = tolower(word[i]);
        }

        //Finds the point value of the current char and adds it to the total score
        if (word[i] >= 97 && word[i] <= 122)
        {
            int char_val = (int)word[i];

            //Shifts the char's ASCII value so that it aligns w/ POINT values
            char_val = char_val - 97;

            int char_pts = POINTS[char_val];
            total_pts = total_pts + char_pts;
        }
    }

    return total_pts;
}
