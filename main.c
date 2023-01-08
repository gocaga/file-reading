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

     /* open the file*/
    fin = fopen("./Questions.txt", "r");

    /* Read out each question, a line at a time and take an answer from the user */
    for(int i = 0; i < 10; i++ )
    {
       fgets(question[i], 256, fin);
       printf("%s", question[i]);
        //answer[i] = getchar();

        //prompt the user to type in a character from the console


    }


    /* write the contents to a new text file */


    /* close when you are done */
    fclose(fin);


    return 0;
}
