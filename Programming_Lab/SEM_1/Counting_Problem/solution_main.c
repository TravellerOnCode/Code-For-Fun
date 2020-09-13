//Given a text file and an integer 
//n the program must report number of words, 
//number of characters, number of lines in the file, and do paragraph formatting to fit width n. 
//Two consecutive newlines are to be treated as paragraph separator.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char words_list[1000][100]; //contains the list of words in a file
int chars_per_line[10000]; //stores the characters per line in the justified document
int words_per_line[10000]; //stores the words per line in the justified docuement

//variable declaration
int words,lines,chars,max_length=0,paragraphs=0;
    
//Justify Alignment - keeping characters as constant

//--- used to calculate the optimal chars per line and words per line in the justified format
void format_meta_data_widthwise(int);

//--- use the data calculated above to set the spaces so that the document is aligned
void insert_format_data_widthwise(FILE*,int);

//Justify Alignment - keeping words as constant
void format_meta_data(int);
void insert_format_data(FILE*,int);



int main()
{   
    int i,ch,flag,M,j,W;
    char filename[20];
    chars = 0; //to store number of characters
    lines = 0; //to store number of lines
    words = 0; //to store number of words
    paragraphs = 0; //to store number of paragraphs

    printf("Enter input filename (in .txt format): ");
    gets(filename);

    printf("Enter File Width (no of characters per line) : ");
    scanf("%d",&W);

    //printf("Enter File Width (no of words per line) : ");
    //scanf("%d",&M);
    
    //File Pointers
    FILE *fp,*fp2, *fp3;
    fp = fopen(filename,"r"); //Read
    fp2 = fopen("output.txt","w"); //Write
    //fp3 = fopen("output3.txt","w"); //Write

    //scan the file once to extract all words and necessary file statistics
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
            if (flag==1)
            {
                words_list[words][j] = '\n'; //a paragraph hence insert a line break in word list
                words = words + 1;
                paragraphs++;
                flag = 0;
            }
            else
            {
                words_list[words][j] = '\0';
                lines = lines + 1;
                words = words + 1;
                j=0;
                flag = 1; //set the flag to detect a paragraph
            }
        }
        else
        {
            words_list[words][j] = ch;
            j++;
            flag = 0;
        }
        //printf("%c ",ch);
    }
    lines = lines + 1;
    words = words-paragraphs;
    printf("File Statistics: \n");
    printf("Lines = %d \n",lines);
    printf("Words = %d \n",words);
    printf("Characters = %d \n",chars);
    //printf("Paragraphs = %d \n",paragraphs);
    fclose(fp);
    
    fprintf(fp2,"File Statistics: \n");
    fprintf(fp2,"No. of Lines = %d \n",lines);
    fprintf(fp2,"No. of Words = %d \n",words);
    fprintf(fp2,"No. of Characters = %d \n",chars);
    fprintf(fp2,"\n\nJustified Aligned Text : \n");

    //Justify by number of words
    //format_meta_data(M);
    //insert_format_data(fp2,M);
    //fclose(fp2);

    //Justify by number of Characters
    format_meta_data_widthwise(W);
    insert_format_data_widthwise(fp2,W);
    fclose(fp2);

    return 0;
}

//align with respect to number of characters

void format_meta_data_widthwise(int W)
{
    int i,words_written=0,l=0,temp=0,r,index=0;
    r = words;
    for(i=0;i < words+paragraphs;i++)
    {
        if (words_list[i][0] == '\n')
        {
            //printf("%d  %d  \n",l,words_written);
            words_per_line[index] = words_written;
            chars_per_line[index] = l;
            words_written = 0;
            l = 0;
            index++;
            continue;
        }
        temp = l;
        l = l + strlen(words_list[i])+1;
        if (l<W)
        {
            //printf("%s ",words_list[i]);
            words_written++;
        }
        else
        {
            //printf("%d  %d  \n",temp,words_written);
            words_per_line[index] = words_written;
            chars_per_line[index] = temp;
            words_written = 0;
            l = 0;
            index++;
            i--;
        }  
    }
}

void insert_format_data_widthwise(FILE* fp3,int W)
{
    int i,words_written=0,l=0,r,index=0,q,j;
    printf("\n Text after Justified Alignment :\n");
    //l=0;
    index = 0; //array index
    words_written = 0; //stores the number of words written per line
    max_length = W; //maximum characters per line
    q = 0; //stores the number of spaces inbetween words
    r = max_length - chars_per_line[index]; //number of extra characters required to adjust the alignment

    if (r< words_per_line[index]) //if extra characters required is less than available blank spaces
        q = 1;
    else
        q = r / (words_per_line[index]-1); //if the value is greater 

    for(i=0;i < words+paragraphs;i++)
    {
        if (words_list[i][0]!='\n')
        {
            fprintf(fp3,"%s ",words_list[i]);
            printf("%s ",words_list[i]);
            words_written++;
            //l = l + strlen(words_list[i]);
            if (words_written == words_per_line[index]-1 || r==0 )
                q = r;
            else if (r< words_per_line[index])
                q = 1;
            for(j=1;j<=q;j++)
            {
                printf(" ");
                fprintf(fp3," ");
            }

            //update the remianing blank spaces
            r = r - q;
        }

        //This denotes a paragraph hence insert a line break
        if (words_list[i][0] == '\n')
        {
            fprintf(fp3,"\n");
            printf("\n");
        }
            
        
        if (words_written == words_per_line[index]) //end of a line
        {
            
            index++;
            r = max_length - chars_per_line[index];
            if (r< words_per_line[index])
                q = 1;
            else
                q = r / (words_per_line[index]-1) - 1;
            
            fprintf(fp3,"\n");
            printf("\n");
            //printf("%d %d \n",words_per_line[index],chars_per_line[index]);
            //printf(" %d %d %d \n",r,q,i);
            words_written = 0;
            l=0;
        }
    }
}


/*

//------------------------------------------------------------------------------------------

//align word wise

void format_meta_data(int M)
{

    int i,words_written=0,l=0,r,index=0;
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
            
            if (l>max_length)
                max_length = l;
            l = 0;
            words_written=0;
        }
    }
}

void insert_format_data(FILE* fp2,int M)
{
    int i,words_written=0,l=0,r,index=0,q,j;
    printf("\n Words After Formatting : :\n");
    l=0;
    index = 0;
    words_written = 0;
    r = max_length - chars_per_line[index];
    q = r / (M-1);
    for(i=0;i < words+paragraphs;i++)
    {
        if (words_list[i][0]!='\n')
        {
            fprintf(fp2,"%s ",words_list[i]);
            printf("%s ",words_list[i]);
            words_written++;
            l = l + strlen(words_list[i]);
            if (words_written == words_per_line[index]-1 || r==0)
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
            r = max_length - chars_per_line[index];
            q = r / (M-1);
            fprintf(fp2,"\n");
            printf("\n",l);
            //printf(" %d %d %d \n",r,q,i);
            words_written = 0;
        }
    }
}
*/