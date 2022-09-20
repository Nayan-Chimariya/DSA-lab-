#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *ptr;
    int tos;
    int size;
} stack;

void push(stack *sp, int data)
{
    int i;
    if(sp->tos == sp->size -1)
        printf("\nStack is full\n");
    else
    {
        sp->tos ++;
        sp->ptr[sp->tos] = data;
    }
}

int pop(stack *sp)
{
    int data = sp->ptr[sp->tos];
    sp->tos --;
    return data;
}

stack * create(int size)
{
    stack *sp = (stack*)malloc(sizeof(stack));
    sp->ptr = (int*) malloc(sizeof(int)*size);
    sp->tos = -1;
    sp->size = size;
}

int user_choice()
{
    int task;
    printf("#--------*--------#\n| Enter: \t  |\n");
    printf("| [1] to push \t  |\n| [2] to pop \t  |\n| [3] to exit\t  |");
    printf("\n#--------*--------#\n");
    scanf("%d",&task);
    return task;
}
int main()
{
    stack *sp = create(5);
    int choice, n_data, value;
    while(1)
    {
        choice = user_choice();
        switch(choice)
        {
        case 1:
            printf("\nHow many data do you want to push to the stack? [MAX = %d]: ",sp->size);
            scanf("%d",&n_data);
            if(n_data>sp->size)
            {
                printf("only %d data will be pushed\n",sp->size);
            }
            for(int i=0; i<n_data; i++)
            {
                printf("Enter number |%d|: ",i+1);
                scanf("%d",&value);
                push(sp,value);
            }
            printf("\n->Successfully pushed data to the stack\n",);
            break;
        case 2:
            printf("\nHow many data do you want to pop from the stack? : ");
            scanf("%d",&n_data);
            if(sp->tos == -1)
                printf("-> Stack is empty\n");
            else
            {
                printf(" ________\n");
                for(int i=0; i<n_data; i++)
                {
                    if(sp->tos == -1)
                    {
                        printf("-> Stack is empty\n");
                        break;
                    }
                    else
                        printf("|___%d___| \n",pop(sp));
                }
            }

            break;

        case 3:
            exit(0);
        }

        printf("\n\t------------------\n\t| Stack Size : %d |\n\t------------------\n\n",sp->size);
    }

    return 0;
}
