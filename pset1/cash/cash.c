#include "stdio.h"
#include "cs50.h"
#include "math.h"

float change;
int give;
int coins;

int main(void)
{
    // Prompt the user until a valid number is recieved
    do
    {
        change = get_float("How much change is owed? ");
    }
    while (change < 0);

    // Convert dollars to cents and round the result to prevent errors
    give = round(change * 100);

    // Everytime possible give the most valuable coin
    while (give > 0)
    {
        if (give / 25)
        {
            give -= 25;
        }
        else if (give / 10)
        {
            give -= 10;
        }
        else if (give / 5)
        {
            give -= 5;
        }
        else
        {
            give -= 1;
        }
        coins++;
    }

    // Print the change value
    printf("Change owed: %0.2f\n", change);

    // Print the minimum number of coins given
    printf("%d\n", coins);
}

