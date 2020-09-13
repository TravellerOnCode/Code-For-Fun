//Given a text file and an integer 
//n the program must report number of words, 
//number of characters, number of lines in the file, and do paragraph formatting to fit width n. 
//Two consecutive newlines are to be treated as paragraph separator.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    printf("Hello World ! \n");
    FILE *fp,*fp2;
    char words_list[1000][1000];
    int chars_per_line[1000];
    int words_per_line[1000];
    int ch,words,lines,chars,j=0,i=0,M=5,l=0,max=0,index=0,r,q,w,f=0,paragraphs=0,words_written=0;
    chars = 0;
    lines = 0;
    words = 0;
    paragraphs = 0;
    fp = fopen("input.txt","r");
    fp2 = fopen("output.txt","w");
    //ch = fgetc(fp);
    while(ch != EOF)
    {
        ch = fgetc(fp);
        chars = chars + 1;
        if (ch == ' ')
        {
            words_list[words][j] = '\0';
            words = words + 1;
            j=0;
        }
        else if (ch == '\n')
        {
            if (f==1)
            {
                words_list[words][j] = '\n';
                words = words + 1;
                paragraphs++;
                f = 0;
            }
            else
            {
            words_list[words][j] = '\0';
            lines = lines + 1;
            words = words + 1;
            j=0;
            f = 1;
            }
        }
        else
        {
            words_list[words][j] = ch;
            j++;
            f = 0;
        }
        //printf("%c ",ch);
    }
    lines = lines + 1;
    words = words-paragraphs;
    printf("Lines = %d \n",lines);
    printf("Words = %d \n",words);
    printf("Characters = %d \n",chars);
    printf("Paragraphs = %d \n",paragraphs);
    fclose(fp);
    
    fprintf(fp2,"File Statistics: \n");
    fprintf(fp2,"No. of Lines = %d \n",lines);
    fprintf(fp2,"No. of Words = %d \n",words);
    fprintf(fp2,"No. of Characters = %d \n",chars);
    fprintf(fp2,"\n\n Formatted Document : \n");
    /*
    for(i=0;i < words+paragraphs;i++)
    {
        if (words_list[i][0]=='\n')
        {
            printf("\n");
            continue;
        }
        printf("%s ",words_list[i]);
    }
    printf("\n\n");
    */
    //printf("\n Strings or words after split by space are :\n");
    r = words;
    for(i=0;i < words+paragraphs;i++)
    {
        
        if (words_list[i][0]!='\n')
        {
            printf("%s ",words_list[i]);
            words_written++;
            l = l + strlen(words_list[i]);
        }
        
        if ((i+1) % M == 0 || i==(words+paragraphs-1) || words_list[i][0]=='\n')
        {
            r = M - words_written;
            if (r==0)
                words_per_line[index] = M;
            else
                words_per_line[index] = r;
            
            chars_per_line[index] = l;
            index++;
            printf("%d \n",l);
            if (l>max)
                max = l;
            l = 0;
            words_written=0;
        }
    }
    //printf(" %d \n",max);
    printf(" \n\n\n");
    
    printf("\n Words After Formatting : :\n");
    l=0;
    index = 0;
    w = 0;
    r = max - chars_per_line[index];
    q = r / (M-1);
    for(i=0;i < words+paragraphs;i++)
    {
        if (words_list[i][0]!='\n')
        {
            fprintf(fp2,"%s ",words_list[i]);
            printf("%s ",words_list[i]);
            w++;
            l = l + strlen(words_list[i]);
            if (w == words_per_line[index]-1 || r==0)
                q = r;
            for(j=1;j<=q;j++)
            {
                printf(" ");
                fprintf(fp2," ");
            }
            r = r - q;
        }

        if ((i+1) % M == 0 || words_list[i][0]=='\n')
        {
            index++;
            r = max - chars_per_line[index];
            q = r / (M-1);
            fprintf(fp2,"\n");
            printf("\n",l);
            //printf(" %d %d %d \n",r,q,i);
            w = 0;
        }
    }
    fclose(fp2);
    return 0;
}