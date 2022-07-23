
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

// 2. ***** Function to reverse the linked-list : Recursive approach -> 
// We have to return the new 'head' of the reversed linked-list -> 
node* reverseRecursively (node* &head)
{

    // considering the base-cases : [empty list or single-elemented list]
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    // recursion ->
    node* newHead = reverseRecursively(head->next); // iterating through the list and getting the 'newHead' by shifting the position of 
    // initial 'head' [head->next], [head->next->next], [head->next->next->next] ,.,.,.,.,. till the initial 'head' points "NULL"
    // With that the rest of the list will be reversed.

    // To perform the last switch [from node2 to node1] ->
    head->next->next = head; // node2 [point to] will store the address of node1. 
    head->next = NULL; // to denote the end of the list. 

    return newHead;
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
    node* newList = reverseRecursively(head);
    displayLinkedList(newList);
   
    return 0;
}

// Time-complexity = O(n)
