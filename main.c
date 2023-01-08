#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

char *get_string(FILE* stream)
{
    int bytes = 0;
    char *buf = NULL;


    char c;
    while((c = fgetc(stream)) != EOF && c != '\r' && c != '\n')
    {
        //We know that we have a valid character
        bytes++;
        buf = realloc(buf, bytes+1);
        if (buf == NULL)
        {
            return NULL; //realloc failed
        }
        buf[bytes-1] = c;

    }

    if (c == '\r')
    {
        c = fgetc(stream);
        if (c != '\n')
        {
            //Oops
            ungetc(c, stream);
        }
    }

    if(buf == NULL)
    {
        if (c == EOF)
        {
            return NULL;
        }else{
            buf = malloc(1);
        }
    }

    //null terminate it
    buf[bytes] = 0;

    return buf;
}

int main()
{
    char *str;

    char questions[10][256];

    //int linenum = 0;

    FILE* fin = fopen("./Questions.txt", "r");

    int i = 0;
    for(int i = 0; i < 7; i++ )
    {
        while(((questions[i] = get_string(fin))!= NULL) && ((questions[i] = get_string(fin))== '\n' ))
        {
            //questions[i] = str;

            printf("%s\n", questions[i]);
            //printf("%d--\t%s\n", linenum++, str);
            free(questions);
        }
    }



    return 0;
}
