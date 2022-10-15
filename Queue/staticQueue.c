#include <stdio.h>
#define size 10
#define true 1

typedef struct queue{
    int queue[size];
    int pos_end;
    int pos_first;

}queue;

void startRow(queue *f){
    f->pos_end = 0;
    f->pos_first = 0;
    for (int i = 0; i < size; i++){
        f->queue[i] = 0;
    }    
    printf("row started!\n");
}   

void insertRow(queue *f, int value){
    if (f->pos_end == size)
    {
        printf("impossible to insert, full row!\n");
    }
    else{
        f->queue[f->pos_end] = value;
        f->pos_end++;
    }    
}

void removeRow(queue *f){
    if(f->pos_end == 0){
        printf("impossible to remove, empty row!\n");
    }
    else{
        printf("value removido: %d\n", f->queue[0]);
        int i = 0;
        while(i < size-1){
            f->queue[i] = f->queue[i+1];
            i++;
        }                
        f->queue[size-1] = 0;
        f->pos_end--;
    }
}
void showRow(queue *f){
    for (int i = 0; i < size; i++)
    {
        printf("%d ", f->queue[i]);
    }
    printf("\n");
    
}

void menu(queue *f){
    startRow(&f);
    while(true){
        int option;
        printf("<1> Insert\n");
        printf("<2> Remove\n");
        printf("<3> Show list\n");
        printf("option: ");
        scanf("%d", &option);
        printf("\n");

        switch (option)
        {
        case 1:
            printf("value: ");
            int value; 
            scanf("%d", &value);
            insertRow(&f, value);
            break;
        case 2: 
            removeRow(&f);
            break;
        case 3:
            showRow(&f);
            break;
        default:
            printf("Invalid option!");
            break;
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    queue f;
    menu(&f);
    return 0;
}
