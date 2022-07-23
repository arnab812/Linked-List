#include<iostream>
using namespace std;

class node {
    public :
    int data;
    node* next;

    node(int value)
    {
        int data = value;
        next = NULL;
    }
};

void insert_data_at_the_end (node* &head, int data_element)
{
// creating a new node :
    node* new_node = new node(data_element);
    
    
    new_node->data = data_element; 

// in-case the linked-list is totally empty : [address of first node will be 'NULL']
    if(head == NULL)
    {
        head = new_node;
        return;
    }

    // traverse to the last node of the linked-list : 
    node* temp = head; 
    while(temp->next != NULL)
    {
        temp = temp->next; 
    }
    temp->next = new_node; 
}

// to print the linked-list :
void displayLinkedList (node* head)
{
    node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

/* Function to reverse linked-list by 'K' nodes :
   head | 1 -> 2 -> 3 -> 4 -> 5 -> 6 | NULL
   if K = 2,
   2 -> 1 [ 3 -> 4 -> 5 -> 6 | NULL ]
   ^
   |
   new-head 
   the next part [ 3 -> 4 -> 5 -> 6 | NULL ] is needed to be reversed now.
   after getting the reversed list [from (K+1)th node to the last node], we need the first-node of that list to be pointed by the 
   new-head -> next

   new-head | 2 -> 1 -> 4 -> 3 -> 6 -> 5 | NULL  
*/

node* reverseK (node* &head, int K)
{
    // Iterative approach to reverse the 'K' nodes. 

    // initializing pointers : 
    node* previousPointer = NULL;
    node* currentPointer = head;
    node* nextPointer;

    int count = 0; // to track 'K'

    while( currentPointer != NULL && count < K)
    {
        nextPointer = currentPointer->next;
        currentPointer->next = previousPointer; // to reverse the list, currentPointer must point to it's previous node. 

        previousPointer = currentPointer;
        currentPointer = nextPointer;

        count++;
    }

    if(nextPointer != NULL)
    {
        head->next = reverseK (nextPointer, K);
    }

    return previousPointer; // 'previousPointer' points to the new-head. 
}

int main()
{
    node* head = NULL;

    insert_data_at_the_end(head, 1);
    insert_data_at_the_end(head, 2);
    insert_data_at_the_end(head, 3);
    insert_data_at_the_end(head, 4);
    insert_data_at_the_end(head, 5);
    insert_data_at_the_end(head, 6);

    cout<<"List before deletion -> "<<endl;
    displayLinkedList(head);



    cout<<"Reversed linked-list by 'K' nodes : "<<endl;

    int K;
    cout<<"Enter the number of nodes by which you want to reverse your linked-list : ";
    cin >> K;

    node* new_head = reverseK(head, K);
    displayLinkedList(new_head);
   
    return 0;
}

// Time-complexity = O(n)

/* Important takeaway -> 
   head | 1 -> 2 -> 3 -> 4 -> 5 -> 6 | NULL
   'K' divided the list into two different parts

   if K = 2, 
   the list will be divided into 1 -> 2  and 3 -> 4 -> 5 -> 6

   after that both the parts will be reversed and get linked to create or fulfill the ultimate reversed linked-list.  
*/

