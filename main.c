#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int main()
{
    char *str;
    char question[10][256];
    int answer[10];
    FILE* fin;
    int ch = 0;
    int x = 0;

     /* open the file*/
    fin = fopen("./Questions.txt", "r");

    /* Read out each question, a line at a time and take an answer from the user */
    for(int i = 0; i < 8 ; i++ )
    {
       fgets(question[i], 80, fin);
       printf("%s", question[i]);
       while((ch = question[i][x]) == '?');

       /* start prompting the user from line 2 of the text file */
       if (i > 1)
       {
           answer[i] = getchar();   /* prompt the user to type in a character from the console */
           getchar();              /* expect the Enter key to be pressed */
       }
    }

    /* close when done */
    fclose(fin);

    int z = 0;
    for (z ; z < 8; z++)
    {
       putchar(answer[z]);
    }

    /* write the contents to a new text file */

    return 0;
}
