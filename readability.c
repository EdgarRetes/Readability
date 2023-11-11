#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string words);
int count_sentences(string text);
float L = 0;
float S = 0;

int main(void)
{
    string text = get_string("Text: ");

    int numletters = count_letters(text);

    int numwords = count_words(text);

    int numsentences = count_sentences(text);


    //floating values that make the operations more precisely
    L = (float)numletters / (float)numwords * 100;
    S = (float)numsentences / (float)numwords * 100;


    int index = round(0.0588 * L - 0.296 * S - 15.8); //math library

    if (index < 16 && index >= 1) //between 1 n 16
    {
        printf("Grade %i\n", index);
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }

}

int count_letters(string text)//function for counting letters
{
    int letters = 0;

    for (int i = 0; i < strlen(text); i++) //it will count the letters 1 by one if they are alphabetical
    {
        if (isalpha(text[i]))
        {
            letters ++;
        }
    }
    return letters;

}

int count_words(string text)//function for counting words
{
    int words = 1;

    for (int i = 0; i < strlen(text); i++)//it will analize each character and space = word
    {
        if (isblank(text[i]))
        {
            words ++;
        }
    }
    return words;
}

int count_sentences(string text) //function for counting sentences
{

    int sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        int relation = text[i];

        if (relation == 33 || relation == 46 || relation == 63)//identifies numerical assignation of the chracters
        {
            sentences ++;
        }
    }
    return sentences;
}