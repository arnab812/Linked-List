/*
Reverse a linked-list : 
    linked lsit : | head | 1 | ->2->3-> | 4 | NULL |
    Reversed linked list :| head | 4 | ->3->2-> | 1 | NULL |

    => Methods to reverse a linked-list ->
       1. Iterative method.
       2. Recursive method. 

*/

/*
1. Iterative method :-
=> We have to reverse the link between the nodes. 'n'th node will store the address of (n-1)th node.
   Approach : 
   1. Pointers : i. previous, ii. current
      2 pointers will not be abale to reach the next node in the list. [Because, they will point each-other]
   2. Reverse the link between the pointers

   * Therefore, 3 pointers will be required. 
   3. Pointers : i. previous, ii. current, iii. next
   Initially, 'current' will point to the 'head'
              'previous' will point to "NULL"
              'next' will point to current->next
    
    4. Change 'current' pointer from pointing current->next to previous. ['n'th node storing address of (n-1)th node]

    *Q. Why 'previous' is pointing to 'NULL' ?
    =>  Because, in the reversed linked-list 'previous' will point to 'NULL'(the end of the list)

    5. Move all the pointers one step ahead.  
*/

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

// ***** Function to reverse the linked-list : 
// We have to return the new 'head' of the reversed linked-list -> 

node* reversedLinkedList(node* &head) // 'node*' at the beginning is the return-type of the function - 'reversedLinkedList'
{
    // Initialization - 
    node* previousPointer = NULL;
    node* currentPointer = head;
    node* nextPointer;
    // not initializing the 'nextPointer'. Will be initialized inside the loop. 

    while(currentPointer != NULL)
    {
        nextPointer = currentPointer->next; // otherwise the pointer will not move forward. 
        currentPointer->next = previousPointer;
        // ultimately 'nextPointer' will store the address of the 'previousPointer'

        /* ***** to continue the iteration -
           1. previousPointer will now point current,
           2. currentPointer will now point current->next
           3. nextPointer will be at current->next->next

           to perform this operation we need to perform the below action -> 
        */ 
        // moving the 3 pointers forward ->
        previousPointer = currentPointer;
        currentPointer = nextPointer;
        // * now you need not to move forward the 'nextPointer', because it'll get the value assigned 
        // when the loop will run for the next time. [nextPointer = currentPointer->next;]

    }
    // with the end of this loop, the 'currentPointer' will point to 'NULL' and by then the previousPointer 
    // will be at the new'head'

    return previousPointer;
}



int main()
{
    node* head = NULL;

    insert_data_at_the_end(head, 1);
    insert_data_at_the_end(head, 2);
    insert_data_at_the_end(head, 3);
    insert_data_at_the_end(head, 4);

    cout<<"List before deletion -> "<<endl;
    displayLinkedList(head);

    // deleteElement(head, 3);
    // deleteHead(head);
    // cout<<"List after deletion -> "<<endl;
    // displayLinkedList(head);

    cout<<"Reversed linked-list : ";
    node* newList = reversedLinkedList(head);
    displayLinkedList(newList);
   
    return 0;
}

