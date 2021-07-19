// program that promps the user for its name and then says "hello"

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What is your name:\n");
    printf("hello, %s\n", name);
}