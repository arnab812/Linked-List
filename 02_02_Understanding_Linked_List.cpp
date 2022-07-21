// Add elements in a Linked List at the start (head)

#include<iostream>
using namespace std;

// Linked List 'Node' is not built-in data type. [user-defined]  

class node {
    public :
    int data;
    node* next;

    //creating a constructor ->
    node(int value)
    {
        int data = value; // initialized the node |data| element
        next = NULL;
    }
};

void insert_data_at_the_start(node* &head, int value)
{
    node* new_node = new node(value);
    new_node->data = value; // data part 
    new_node->next = head; // 'next' will now refer to contain the address of the next-node of the list.
    head = new_node; // 'head' will now store the address of the currently created node address.     
    new_node->data = value;
}

void insert_data_at_the_end (node* &head, int data_element)
// 'head' is taken here by reference [for modifying purpose],
// means we'll be able to get the adresses that get stored in the 'head'
{
// creating a new node :
    node* new_node = new node(data_element);
    // constructor 'node' will create the 'new_node' of type 'node*'
    // 'new_node' will get it's 'data' from 'data_element' and 'NULL' will be assigned to the pointer section.  

    // ***** without the below initialization the program will produce / contain garbage values.
    new_node->data = data_element; 

// in-case the linked-list is totally empty : [address of first node will be 'NULL']
    if(head == NULL)
    {
        head = new_node;
        return;
    }

    // traverse to the last node of the linked-list : 
    // creating an iterator to traverse from start to end - 
    node* temp = head; // initialization 
    while(temp->next != NULL) // at 'NULL' the iterator reaches at the end.
    {
        temp = temp->next; // perform storing the next node(s) address to 'temp' 
    }
    temp->next = new_node; // when 'temp' is pointing the end just place the data_element in it's data part 
}

// to print the linked-list :
    void displayLinkedList (node* head)
// 'head' is taken here by value, because we are not modifying the linked-list here.
    {
        node* temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<"->"; // print out the value
            temp = temp->next; // point to the next node
        }
        cout<<"NULL"<<endl;
    }

int main()
{
    node* head = NULL; // initialization

    insert_data_at_the_end(head, 1);
    insert_data_at_the_end(head, 2);
    insert_data_at_the_end(head, 3);
    insert_data_at_the_end(head, 4);
    
    insert_data_at_the_start(head, 0);

    displayLinkedList(head);
    return 0;
}