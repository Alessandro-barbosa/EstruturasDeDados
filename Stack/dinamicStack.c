#include <stdio.h>
#include <stdlib.h>
#define True 1

typedef struct stack{
    int value;  
    struct stack *next;
}Stack;

void push(Stack **stack, int value){
    Stack *new = malloc(sizeof(Stack));
    if(new == NULL){
        printf("Memory error");
    }
    else{
        new->value = value;
        new->next = *stack;
        *stack = new;
    }    
}

void pop(Stack **stack){
    Stack *new = malloc(sizeof(Stack));
    if(*stack == NULL){
        printf("Empty stack!\n");
    }
    else{
    new = *stack;        
    *stack = new->next;
    printf("Popped value: %d\n", new->value);
        if(new->next == NULL){
           *stack = NULL;
        }
    }
}

void showStack(Stack *stack){
    if(stack == NULL){
        printf("Empty stack, can't impress!\n");
    }
    else{        
        while(stack != NULL){
        printf("|%d|\n", stack->value);
        stack = stack->next;
        }
    }
}

void menu(){
    Stack *stack = NULL;
    int option;
    while (True)
    {    
        printf("\n<1> Push\n");
        printf("<2> Pop\n");
        printf("<3> ShowStack\n");
        printf("<4> Exit\n");
        printf("Option: ");    
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("push value: ");
            int value;
            scanf("%d", &value);
            push(&stack, value);
            break;
        case 2:
            pop(&stack);
            break;
        case 3:
            printf("\n");
            showStack(stack);
            break;
        case 4:
            exit(1);
        default:
            printf("\n--Invalid Option--\n");
            break;
        }
    }
}
int main(int argc, char const *argv[])
{
    menu();
    return 0;
}
