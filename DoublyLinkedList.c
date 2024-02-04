#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
    struct node *prev;
};
struct node* list = NULL;
void insertAtStart(int x){
    struct node* p;
    if(list==NULL)
    {
        p = (struct node*)malloc(sizeof(struct node));
        p->info = x;
        p->next = NULL;
        p->prev = NULL;
        list = p;
    }
    else{
        p = (struct node*)malloc(sizeof(struct node));
        p->info = x;
        p->next = list;
        p->prev = NULL;
        (p->next)->prev = p;
        list = p;
    }
    
}


void deleteAtStart(){
    struct node* p;
    p = list;
if (list == NULL)
{
    printf("Doubly Linked List is empty\n");
}
else{
    (p->next)->prev = NULL;
    list = p->next;
    free(p);
}

}
void insertAtEnd(int x){
struct node* p;
struct node* q;

q = list;
    if(list==NULL)
    {
        p = (struct node*)malloc(sizeof(struct node));
        p->info = x;
        p->next = NULL;
        p->prev = NULL;
        list = p;
    }
    else{
        while (q->next != NULL)
        {
            q = q->next;        
        }
        p = (struct node*)malloc(sizeof(struct node));
        p->info = x;
        p->next = NULL;
        p->prev = q;
        q->next = p;

    }
}
void deleteAtEnd(){
struct node* p;
struct node* q;

q = list;
    if (list == NULL)
{
    printf("Doubly Linked List is empty\n");
}
else{
    while (q->next != NULL)
    {
        q = q->next;
    }
    (q->prev)->next = NULL;
    free(q);
}
}
void insertAtSpecifiedPosition(int x){
struct node* p;
struct node* q;
int value;
    if(list==NULL)
    {
        p = (struct node*)malloc(sizeof(struct node));
        p->info = x;
        p->next = NULL;
        p->prev = NULL;
        list = p;
    }
    else{
        q = list;
        printf("Enter value where you want to insert\n");
        scanf("%d", &value);
        while (q->next != NULL)
        {
            if (q->info == value)
            {
                p = (struct node*)malloc(sizeof(struct node));
                p->info = x;
                p->next = q;
                p->prev = q->prev;
                q->prev = p;
                (q->prev)->next = p;
            }
            q = q->next;
        }
        
    }

}
void deleteAtSpecifiedPosition(){
struct node* q;
int value;
q = list;
    if (list == NULL)
{
    printf("Doubly Linked List is empty\n");
}
else{
    printf("Enter value you want to delete\n");
    scanf("%d", &value);
    while (q->next != NULL)
    {
        if (q->info == value)
        {
            (q->next)->prev = q->prev;
            (q->prev)->next = q->next;
            free(q); 
        }
        q = q->next;
    }
    
}


}

void display(){
struct node* p;
p = list;
if (list == NULL)
{
   printf("No node to show\n");
}
else{
printf("Displaying Nodes\n");
while (p != NULL)
{
    printf("%d\n", p->info);
    p = p->next;
}
}

}
int main(){
int opt;
int x;
do
{
    printf("Enter 1 to insert at start\n2 to delete at start\n3 to insert at end\n4 to delete at end\n5 to insert At Specified Position\n6 to delete At Specified Position\n7 to display\n-1 to terminate\n");
    scanf("%d", &opt);
switch (opt)
{
case 1:
printf("Enter value you want to insert\n");
scanf("%d", &x);
insertAtStart(x);
break;
case 2:
deleteAtStart();
break;
case 3:
printf("Enter value you want to insert\n");
scanf("%d", &x);
insertAtEnd(x);
break;
case 4:
deleteAtEnd();
break;
case 5:
printf("Enter value you want to insert\n");
scanf("%d", &x);
insertAtSpecifiedPosition(x);
break;
case 6:
deleteAtSpecifiedPosition();
break;
case 7:
display();
break;
case -1:
printf("Program ENDED\n");
break;
default:
printf("Invalid key!\n");
    break;
}
} while (opt!=-1);

}