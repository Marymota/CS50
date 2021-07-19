#include <stdio.h>
#include <cs50.h>

int main (int argc, string argv[])
{
    printf("%i", argc);
    if(argc == 2)
    {
        printf("Success");
    }
    else
    {
        printf("Usage: ./caeser key");
        return 1;
    }

}