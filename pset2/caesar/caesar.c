#include <stdio.h>
#include <cs50.h>

// Checks if a string contains only digits
int isDigit(char *arg)
{
    while (*arg)
    {
        if (*arg >= 48 && *arg <= 57)
        {
            ++arg;
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return (0);
        }
    }
    return (1);
}

// Atoi converts strings with digits into numbers
// Iterates through a string and converts each digit into a number
int AtoI(char *key)
{
    int number = 0;
    while (*key)
    {
        if (*key)
        {
            number = number * 10 + *key++ - '0';
        }
    }
    return (number);
}

int main(int argc, char **argv)
{
    // Before anything else confirm that argc has more than 1 argument
    // Else it will cause "sagmentation fault"

    // Confirm that the argument passed is/are digit(s)
    // The argc 1st argument is the name of the program
    // To confirm that an argument was passed argc must have 2 arguments
    int i;
    if (argc == 2 && isDigit(argv[1]))
    {

        char *plaintext;
        char *ciphertext;
        int key;
        // Convert the key argument that is presently a string into an integer
        // (See AtoI above)
        key = AtoI(argv[1]);
        // Get text to be converted
        plaintext = get_string("plaintext: ");
        //
        ciphertext = plaintext;
        i = 0;
        // The formula ((((plaintext[i] - 'a') + key) % 26) + 'a')
        // Ensures that when we pass the letter 'z'
        // The key count will continue from 'a' again
        while (plaintext[i])
        {
            if (plaintext[i] <= 'Z' && plaintext[i] >= 'A')
            {
                ciphertext[i] = ((((plaintext[i] - 'A') + key) % 26) + 'A');
            }
            if (plaintext[i] <= 'z' && plaintext[i] >= 'a')
            {
                ciphertext[i] = ((((plaintext[i] - 'a') + key) % 26) + 'a');
            }
            ++i;
        }
        printf("ciphertext: %s\n", ciphertext);
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return (1);
    }
    return (0);
}