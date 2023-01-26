#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //asks user for name
    string name = get_string("what is your name? \n");

    //says hi to the user w/ their name
    printf("\nhi %s! \n", name);
}