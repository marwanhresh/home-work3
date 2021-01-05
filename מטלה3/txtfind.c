#include <stdio.h>
#include <string.h>
#include "txtfind.h"
#include <stdlib.h>
#include <unistd.h>
#include <math.h>


int similar(char *str1, char *str2){
  int n = strlen(str1) - strlen(str2);
  int s1 = 0, s2 = 0, count = 0;
  int len1 = strlen(str1), len2 = strlen(str2);
  int lenDiff = abs(len1 - len2);
  if (lenDiff != n || lenDiff >= 2) // כי הגודל של מילה ב אף פעם לא תיהיה קטנה או גדולה ממילה ש ב-2 ומעלה
    return 0;
  while (s1 < len1 && s2 < len2){
    if (*(str1 + s1) == *(str2 + s2)){
      s1++;
      s2++;
    }
    else
    {
      s1++;
      count++;
    }
  }
  if (count > n)
    return 0;
  if (count == n && s1 < len1)
    return 0;
  return 1;
}

void print_lines(char *str, char *text)
{
  const char n[2] = "\n";
  const char ws[3] = " \t";
  char *lineTk;
  char *linePos;
  lineTk = strtok_r(text, n, &linePos);
  // Iterating through the lines
  while (lineTk != NULL)
  {
    int shouldPrint = 0;

    char lineClone[LINE];
    strcpy(lineClone, lineTk);

    char *wordTk;
    char *wordPos;
    wordTk = strtok_r(lineClone, ws, &wordPos);
    // iterating through the words
    while (wordTk != NULL)
    {
      // printf("str1: '%s' str2: '%s' => result: %d\n", wordTk, str, similar(wordTk, str));
      if (similar(wordTk, str) == 1)
      {
        shouldPrint = 1;
        break;
      }
      wordTk = strtok_r(NULL, ws, &wordPos);
    }

    if (shouldPrint)
    {
      printf("%s\n", lineTk);
    }
    lineTk = strtok_r(NULL, n, &linePos);
  }
}

void print_similar_words(char *str, char *text)
{
  const char n[2] = "\n";
  const char ws[3] = " \t";
  char *lineTk;
  char *linePos;
  lineTk = strtok_r(text, n, &linePos);
  // Iterating through the lines
  while (lineTk != NULL)
  {
    char lineClone[LINE];
    strcpy(lineClone, lineTk);
 
    char *wordTk;
    char *wordPos;
    wordTk = strtok_r(lineClone, ws, &wordPos);
    // iterating through the words
    while (wordTk != NULL)
    {
      if (similar(wordTk, str) == 1)
      {
        printf("%s\n", wordTk);
      }
      wordTk = strtok_r(NULL, ws, &wordPos);
    }
 
    lineTk = strtok_r(NULL, n, &linePos);
  }
}
