/*
=> Functions required for this program :- 
   1. void generateCycle(){...}
   2. bool detectCycle(){...}
   3. void removeCycle(){...}
*/

#include<iostream>
using namespace std;

// creation of a node :
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

// new node insertion : 
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

// print the linked-list :
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

// 1. void generateCycle(){...}
void generateCycle (node* &head, int position)
{
    node* temp = head;
    node* startNode;

    int count = 1; // 'count' will track 'temp' 

    while(temp->next != NULL) // when 'temp' is not at the last node
    {
        if(count == position)
        {
            startNode = temp; // 'startNode' got defined by 'temp' using it's current position. 
        }
        // else 
        temp = temp->next; // 'temp' will be moving forward. 
        count++;
    }
    temp->next = startNode;
}

// 2. bool detectCycle(){...}
bool detectCycle(node* &head)
{
    // perform Floyd's algorithm - (part-2) : 
    node* slow = head;
    node* fast = head;

    while(fast != NULL && fast->next != NULL) // means we are not getting out of the linked-list
    {
        slow = slow->next;
        fast = fast->next->next;

        if(fast == slow)
        {
            return true;
        }
    }
    return false;
}

// 3. void removeCycle(){...}
void removeCycle (node* &head)
{
    node* fast = head;
    node* slow = head;

    // step-1 : perform Floyd's algorithm - (part-1)
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    while (slow != fast);
    // now, both the pointers have met each-other and their position is in the same node. 

    // step - 2 : perform Floyd's algorithm - (part-2)
    fast = head;
    while(fast->next != slow->next)
    {
        fast = fast->next;
        slow = slow->next;
    }
    // now, both the pointers->next is pointing to the same node.

    slow->next = NULL;
}

int main()
{
    node* head = NULL;

    // creation -
    insert_data_at_the_end(head, 1);
    insert_data_at_the_end(head, 2);
    insert_data_at_the_end(head, 3);
    insert_data_at_the_end(head, 4);
    insert_data_at_the_end(head, 5);
    insert_data_at_the_end(head, 6);
    insert_data_at_the_end(head, 7);
    insert_data_at_the_end(head, 8);
    insert_data_at_the_end(head, 9);

    displayLinkedList(head);

    generateCycle(head, 2);
    
    // displayLinkedList(head); // by commenting out this line we can actually get the result from detectCycle()
    
    // detection -
    cout<<detectCycle(head)<<endl;

    // removal - 
    removeCycle(head);

    displayLinkedList(head);
    
    cout<<detectCycle(head)<<endl;
}


