#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_LINES 10
#define MAX_LEN 256
int main()
{
   char *str;
   char question[MAX_LINES][MAX_LEN];
   int answer[MAX_LINES];
   FILE* fin;
   int ch = 0;
   int x = 0;
   FILE* fout;

   /* open the file*/
   fin = fopen("./Questions.txt", "r");

   /* Read out each question, a line at a time and take an answer from the user */

   if (fin == NULL)
   {
       printf ("Error opening file.\n");
       return 1;
   }

   int line = 0;
   int isFirstTime = 0;

   while(!feof(fin) && !ferror(fin))
   {
       if(fgets(question[line], 90, fin) != NULL)
            line++;
   }

    printf("%s", question[0]);

    for (int i = 1; i < 7; i++)
    {
        printf("%s", question[i]);
        answer[i] = getchar();
        getchar();

    }

    /* close when done */
    fclose(fin);

    /* write the contents to a new text file */
    fout = fopen("Answers.txt", "w");
    if(fout == NULL)
    {
        puts("Failed to create file");
        return(1);
    }

    /* output */
    fprintf(fout, "These are the answers to the Questions text file:\n");

    fclose(fout);

    fout = fopen("Answers.txt", "a");
    int iterator = 0;
    for (int i = 1; i < 7; i++ )
    {
        fprintf(fout, "%s%c", question[(i)], answer[i] );

        fputc('\n', fout);

        //iterator++;
    }

    fclose(fout);

    return 0;
}
