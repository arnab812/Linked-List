// Corner-case 1 : Deleting the first (starting) node of a linked-list.
// Corner-case 2 : Deletion of a 'node' in an empty linked-list. 
// Corner-case 3 : Deletion of a 'node' when there is only a single node present in the list. 

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

// Function to perform deletion :

// ***** The below approach will not work against deleting the first-node of the linked-list :
// The concept of storing (n+1)th node's address into (n-1)th node will not work deleting the first node. 
void deleteElement (node* head, int nodeToBeDeleted)
{
    // Corner-case 2 : 
    if(head == NULL)
    {
        return;
    }

    // Corner-case 3 :
    if(head->next == NULL)
    {
        deleteHead(head);
        return;
    }

    node* temp = head; // 'temp' get initialized with head.

    while(temp->next->data != nodeToBeDeleted)  
    {
        temp = temp->next;
    }

    node* deletingNode = temp->next;  
    temp->next = temp->next->next; 

    delete deletingNode; 
}

// Corner-case 1 : function to delete 'head' -
void deleteHead(node* &head) {
    node* toDelete = head; // storing 'head' into 'toDelete' node that will be deleted.
    head = head->next; // 'head' will now basically point to NULL. 
    delete toDelete;
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

    // deleteElement(head, 3);
    deleteHead(head);
    cout<<"List after deletion -> "<<endl;
    displayLinkedList(head);

   
    return 0;
}