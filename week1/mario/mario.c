#include <stdio.h>
#include <cs50.h>

void print_row(int height, int width);

int main(void)
{
    // number must be within [1,8]
    int number;
    do
    {
        number = get_int("Height: ");
    }
    while (number < 1 || number > 8);

    // iterate and print @number rows
    for (int i = 0; i < number; i++)
    {
        print_row(i, number);
    }

}

void print_row(int height, int width)
{
    // print @height + 1 of # in the end, with total length @width
    for (int i = width - 1; i >=  0; i--)
    {
        printf(i <= height ? "#" : " ");
    }

    // add gap between two bars
    printf("  ");

    // print @height + 1 of # 
        for (int j = 0; j <= height; j++)
    {
        printf("#");
    }

    printf("\n");
}


