// Searching an element in the Linked List -

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
    new_node->data = value; 
    new_node->next = head; 
    head = new_node;     
    new_node->data = value;
}

void insert_data_at_the_end (node* &head, int data_element)

{
// creating a new node :
    node* new_node = new node(data_element);
    
    // ***** without the below initialization the program will produce / contain garbage values.
    new_node->data = data_element; 

// in-case the linked-list is totally empty : [address of first node will be 'NULL']
    if(head == NULL)
    {
        head = new_node;
        return;
    }

    // traverse to the last node of the linked-list : 
    node* temp = head; 
    while(temp->next != NULL) // at 'NULL' the iterator reaches at the end.
    {
        temp = temp->next; // perform storing the next node(s) address to 'temp' 
    }
    temp->next = new_node; // when 'temp' is pointing the end just place the data_element in it's data part 
}

// to print the linked-list :
    void displayLinkedList (node* head)

    {
        node* temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<"->"; // print out the value
            temp = temp->next; // point to the next node
        }
        cout<<"NULL"<<endl;
    }

// Searching an element in the linked-list : 
    bool searchElement (node* head, int keyToFind)
    {
        node* temp = head; // 'temp' is an iterator that trverses the list from head -> tail
        while(temp != NULL)
        {
            if(temp->data == keyToFind)
            {
                return true;
            }
            temp = temp->next; // the pointer moves forward (towards the next node)
        }
        return false;
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

    cout<<"Finding the elemenet -> ";
    cout<<searchElement(head, 5)<<endl;
    return 0;
}