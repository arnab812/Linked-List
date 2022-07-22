// Deletion of a node in Linked List :
// To delete the 'n'th node in the list, we need to allocate the address of the (n+1)th node to the (n-1)th node. 

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

void insert_data_at_the_start (node* &head, int value)
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

// Function to perform deletion :
void deleteElement (node* head, int nodeToBeDeleted)
{
    node* temp = head; // 'temp' get initialized with head.

    while(temp->next->data != nodeToBeDeleted) // 'temp' will iterate through the list
    // and try to match it's 'data' with the 'nodeToBeDeleted'
    // Therefore, the movement of the iterator will be towards the 'next' element each node.  
    {
        temp = temp->next; // with that we'll reach at the (n-1)th element.
        // staying at the (n-1)th element the pointer will now point the 'n'th element.
    }
    // 'temp' is now at the (n-1)th element 

    node* deletingNode = temp->next; // here, temp->next is the 'n'th node. 
    temp->next = temp->next->next; // with that the (n-1)th node will now point the (n+1)th node.

    delete deletingNode; // 'n'th node will be deleted. 
}

int main()
{
    node* head = NULL;

    insert_data_at_the_end(head, 1);
    insert_data_at_the_end(head, 2);
    insert_data_at_the_end(head, 3);
    insert_data_at_the_end(head, 4);
    
    insert_data_at_the_start(head, 0);

    cout<<"List before deletion -> "<<endl;
    displayLinkedList(head);

    deleteElement(head, 3);

    cout<<"List after deletion -> "<<endl;
    displayLinkedList(head);

   
    return 0;
}