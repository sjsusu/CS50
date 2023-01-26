#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_block(void);
void print_space(void);
void print_gap(void);
void print_pyramid_spaces(int sc);
void print_pyramid_blocks(int bc);
void new_line(void);

int main(void)
{
    //Recieves height from user
    int h = get_height();

    //Keeps count of how many spaces are needed for each row
    int space_count = h - 1;

    //Keeps track of how many blocks are needed for each row
    int block_count = 1;

    //Prints rows until the row (#)= height
    for (int i = 0; i < h; i++)
    {

        //Prints spaces for left half of pyramid
        print_pyramid_spaces(space_count);

        space_count--;

        //Prints blocks for left side of pyramid
        print_pyramid_blocks(block_count);

        //Prints gap between halves of pyramid
        print_gap();

        //prints blocks for right side of pyramid
        print_pyramid_blocks(block_count);

        block_count++;
        new_line();
    }

}


//Asks user for height of pyramid between 1 & 8 inclusive
int get_height(void)
{
    int n;
    do
    {
        n = get_int("height (1-8): ");
    }
    while (n < 1 || n > 8);
    return n;
}

//Prints a "block" --> (#)
void print_block(void)
{
    printf("#");
}

//Prints a space
void print_space(void)
{
    printf(" ");
}

//Prints gap between two halves of pyramid
void print_gap(void)
{
    printf("  ");
}

//Prints spaces needed for left half of pyramid for corresponding row
void print_pyramid_spaces(int sc)
{
    for (int s = 0; s < sc; s++)
    {
        print_space();
    }
}

//Prints blocks needed for each half of pyramid for corresponding row
void print_pyramid_blocks(int bc)
{
    for (int b = 0; b < bc; b++)
    {
        print_block();
    }
}

//Moves to new line
void new_line(void)
{
    printf("\n");
}
