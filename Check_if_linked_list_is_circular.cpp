// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};


void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data); 
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

bool isCircular(struct Node *head);

int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;
        cin>>n>>k;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
        if (k==1 && n >= 1)
              tail->next = head;
        printf("%d\n", isCircular(head));
    }
    return 0;
}

bool isCircular(Node *head)
{
    if(head==NULL)
        return 1;
    struct Node *curr=head;
    while(curr!=NULL)
    {
        curr=curr->next;
        if(curr==head)
            return 1;
    }
    return 0;
}
/*5 1      
1 2 3 4 5*/
