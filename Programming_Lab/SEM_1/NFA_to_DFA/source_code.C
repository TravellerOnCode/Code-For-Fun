//
//

#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#define N 4

struct state
{
    int input_symbol;
    int output_state;
    struct state *next;
};

struct state_details
{
    int state;
    struct state_details *next;

    //int start_state;
    //int final_state;
    //int value;
    //int state_chars[50];
};

struct list_of_states
{
    state *head;
};

struct list_state_details
{
    state_details *head;
};

list_of_states *automata_states[N] = {0};
list_state_details *automata_details[N*2] = {0};
int arr[50];
int X,STATE_NUMBER;

void addState(int,int,int);
void printAutomata();
void hash_state();
void addStateInfo(int);
void traverse_automata();


void addState(int s,int i,int d)
{
    state *dest, *tmp, *src;
    if (automata_states[s] -> head == NULL)
    {
        src = (state *)malloc(sizeof(state));
        src -> input_symbol = i;
        src -> output_state = d;
        src -> next = NULL;
        automata_states[s] -> head = src;
    }
    else
    {
    dest = (state *)malloc(sizeof(state));
    dest -> input_symbol = i;
    dest -> output_state = d;
    dest -> next = NULL;

    tmp = automata_states[s] -> head;

    while(tmp->next != NULL)
        tmp = tmp -> next;
    
    tmp -> next = dest;
    }
}

void printAutomata()
{
    int i;
    //printf("Hello ! \n\n");
    for (i=0; i< N; i++)
    {
        state *p = automata_states[i] -> head;
        printf("States for State %d :  ",i);

        while(p)
        {
            printf("( %d , %d )",p->input_symbol,p->output_state);
            p = p->next;
        }
        printf("\n\n");
    }
}

void printAutomata_details()
{
    int i;
    printf("New States to be expanded : \n");
    for (i=0; i< STATE_NUMBER; i++)
    {
        state_details *p = automata_details[i] -> head;
        printf("States for State %d :  ",i);

        while(p)
        {
            printf("( %d ) ->",p->state);
            p = p->next;
        }
        printf("\n");
    }
}


void addStateInfo(int STATE_NUMBER)
{
    //printf ("Called ...");
    automata_details[STATE_NUMBER] = (list_state_details *)malloc(sizeof(list_state_details));
    automata_details[STATE_NUMBER]->head = NULL;
    state_details *dest, *tmp, *src;
    int i;
    if (automata_details[STATE_NUMBER] -> head == NULL)
    {
         src = (state_details *)malloc(sizeof(state_details));
          src -> state = arr[0];
          //src -> output_state = d;
           src -> next = NULL;
           automata_details[STATE_NUMBER] -> head = src;
    }
    for (i=1;i<X;i++)
    { 
      dest = (state_details *)malloc(sizeof(state_details));
      dest -> state = arr[i];
      dest -> next = NULL;

      tmp = automata_details[STATE_NUMBER] -> head;

       while(tmp->next != NULL)
         tmp = tmp -> next;
     tmp -> next = dest;
      }
    //printf("Call executed .... \n");
}

void traverse_automata()
{
    int i;
    printf("Composite States are : \n\n");
    X=0;
    STATE_NUMBER=0;
    for (i=0; i< N; i++)
    {
        state *p = automata_states[i] -> head;
        state *temp = NULL;
        printf("States for State %d \n",i);

        while(p)
        {
            temp = p;
            if (temp->next != NULL ) {
                if (temp->input_symbol == temp->next->input_symbol)
                   arr[X++] = temp->output_state;
                else
                {
                    arr[X++] = temp->output_state;
                    //printf("-- %d -- \n",x);
                    for (int j = 0; j<X;j++)
                        printf("-- %d --",arr[j]);
                    printf("\n");
                  if (X!=1)
               {
                    addStateInfo(STATE_NUMBER);
                    STATE_NUMBER++;   
               }
                X = 0;
                    
                }
            }
            else if (X!=0)
            {
                arr[X++] = temp->output_state;
                //printf("-- %d -- \n",x);
                for (int j = 0; j<X;j++)
                    printf("-- %d --",arr[j]);
                printf("\n");
              if (X!=1)
               {
                    addStateInfo(STATE_NUMBER);
                    STATE_NUMBER++;   
                }
                X = 0;
            }
            //printf("( %d , %d )",p->input_symbol,p->output_state);
            p = p->next;
        }
        printf("\n");
    }
}



int main()
{

    int i;
    for (i=0;i<N;i++)
    {
        automata_states[i] = (list_of_states *)malloc(sizeof(list_of_states));
        automata_states[i]->head = NULL;
    }
    /*
    for (i=0;i<2*N;i++)
    {
        automata_details[i] = (list_state_details *)malloc(sizeof(list_state_details));
        automata_details[i]->head = NULL;
    }
    */
    

    addState(0,0,1);
    addState(0,0,3);
    addState(0,1,1);
    addState(1,0,2);
    addState(1,1,0);
    addState(2,3,0);
    addState(3,-1,-1);
    /*
    addState(2,0,0);
    addState(2,1,3);
    addState(3,0,0);
    addState(3,0,3);
    addState(3,1,3);
    addState(3,1,3);
    addState(3,1,3);
    addState(3,1,3);
    */
    printAutomata();
    /*
    X = 1;
    arr[0] = 0;
    addStateInfo(0);

    arr[0] = 1;
    addStateInfo(1);
    
    arr[0] = 2;
    addStateInfo(2);
    
    arr[0] = 3;
    addStateInfo(3);
    */
    
    traverse_automata();
    printAutomata_details();

    printf(" %d \n",STATE_NUMBER);

    return 0;
}