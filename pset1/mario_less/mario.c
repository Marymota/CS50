
#include <cs50.h>
#include <stdio.h>


int get_positive_int(void);                     // Forward declaration of the function "get_positive_int"

int main(void)                                  // Main function that prompts the user for a integer and returns a pyramid with the respective height
{

    int height = get_positive_int();            // Calls a function that certifies that the height is a positive integer

    for (int i = 0; i < height; i++)            // Counts the pyramid's rows
    {
        for (int j = 1; j < height - i; j++)    // Counts how many spaces for each row
        {
            printf(" ");                        // Prints the respective spaces
        }
        for (int d = 0; d <= i; d++)            // Counts how many dash symbols for each row
        {
            printf("#");                        // Prints the respective dashes
        }
        printf("\n");                           // Prints a new line to make a new row
    }
}
                        
int get_positive_int(void)                      
{
    int h; 

    do 
    {
        h = get_int("%s", "height: ");          // Function that prompts the user for a integer between 1 and 8 until it gets a valid result
    }
    while (h < 1 || h > 8);                     
    return h;
}

