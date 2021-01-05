#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "txtfind.h"

int main()
{
    char word[WORD], line[LINE], text[LINE], option;
    scanf("%s %c", word, &option);
    for (int i = 1; fgets(line, sizeof line, stdin); i++)
    {
        if (i < 3)
            continue;
        strcat(text, line);
    }


    if (option == 'a')
        print_lines(word, text);
    if (option == 'b')
       print_similar_words(word, text);

    return 0;
}
