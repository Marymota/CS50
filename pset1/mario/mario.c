#include <cs50.h>
#include <stdio.h>

int get_positive_int(void);                         // Forward declaration of the function "get_positive_int"

int main(void)                                      // Main function that propts the user for a positive integer and creates two opposite pyramides with the defined height
{
    int height = get_positive_int();                // Calls the function that checks if the given number is between 1 and 8

    for (int h = 0; h < height; h++)                // For loop that defines the height of the pyramid
    {
        for (int w = 1; w < height - h; w++)        // The variable w should start at 1 instead of 0 or will add an extra space before "#"
        {
            printf(" ");
        }
        for (int d = 0; d <= h; d++)                // Defines how many "#" are printed (as many as h)
        {
            printf("#");
        }
        printf("  ");                               // Double space add to separate the pyramids
        for (int dd = 0; dd <= h; dd++)             // Another for loop that prints the second pyramid
        {
            printf("#");
        }
        printf("\n");                               // Adds a new row
    }



}

int get_positive_int(void)
{
    int h;                                          // Defines a variable h
    do                                              // The program will prompt the user  until it gets a valid integer
    {
        h = get_int("%s", "height: ");
    }
    while (h < 1 || h > 8);
    return h;
}