#include <stdio.h>
#include <cs50.h>
#include <math.h>

// Function that distinguishes between letters and other characters/spaces
int isletter(char letter)
{
    if ((letter >= 65 && letter <= 90) || (letter >= 97 && letter <= 122))
    {
        return (1);
    }
    return (0);
}
// Function that counts how many letters are in the input text
int countletters(char *text)
{
    int i = 0;
    int letters = 0;

    while (text[i])
    {
        if (isletter(text[i]))
        {
            ++letters;
        }
        ++i;
    }
    return (letters);
}
// Function that counts how many words are in the input text
int countwords(char *text)
{
    int i = 0;
    int words = 0;

    while (text[i])
    {
        if (isletter(text[i++]))
        {
            ++words;
            while (isletter(text[i]) || (text[i] == '-' || text[i] == '\''))
            {
                ++i;
            }
        }
    }
    return (words);
}
// Function that counts how many sentences are in the input text
int countsentences(char *text)
{
    int i = 0;
    int sentences = 0;

    while (text[i])
    {
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            ++sentences;
        }
        ++i;
    }
    return (sentences);
}
// Function that calculates Coleman-Liau index
float formula(float letters, float words, float sentences)
{
    float index;
    float L;
    float S;

    // Function that calculates the average number of letters per 100 words in the text
    L = 100 * (letters / words);
    // Function that calculates the average number of sentences per 100 words in the text
    S = 100 * (sentences / words);

    index = 0.0588 * L - 0.296 * S - 15.8;
    return (round(index));
}

int main(void)
{
    char *text;
    int letters;
    int words;
    int sentences;
    int grade;

    // Gets a text input from the user
    text = get_string("Text: ");

    // Calls the function that counts letters
    letters = countletters(text);
    // Calls the function that counts words
    words = countwords(text);
    // Calls the function that counts sentences
    sentences = countsentences(text);
    // Calls the function that calculates grade
    grade = formula(letters, words, sentences);
    //printf("%d letter(s)\n", letters);
    //printf("%d word(s)\n", words);
    //printf("%d sentence(s)\n", sentences);

    // Prints the grades from 1-16, before grade 1 and after grade 16
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }
    return (0);
}