#include<iostream>
using namespace std;

// Linked List 'Node' is not built-in data type. [user-defined]  

class node {
    public :
    int data; // to store the data elements in the nodes.
    node* next; // the pointer points to the next node.
    // 'node' is the type of the 'next' pointer variable. 

    //creating a constructor ->
    node(int value)
    {
        int data = value; // initialized the node |data| element
        next = NULL;
    }
};

/*
    adding an element in the linked-list :
    Linked-List : |head|-> |1|next|-> |2||NULL|, add data_element 3 in the list =>
    through traversing :  |head|-> |1|next|-> |2||next|-> |3||NULL|

*/

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
    /*

    Linked List : Linear data structure that stores a list of values. 
    Array : Can be conceptualized as - single block of memory with partitions. 
            | 1 | 2 | 3 | 4 | 5 |
    Linked List : Multiple blocks of memory linked to each other. 
            | head |-> | 1 |-> | 2 |-> | 3 |-> | 4 |-> | 5 | null |

    => Limitations in Array : 
       1. Fixed size.
       2. Contiguous block of memory.
       3. Insertion & Deletion is costly. 

    => Properties of Linked List :
       1. Size can be modified.
       2. Non-contiguous memory.
       3. Insertion and Deletion at any point is easier.

    => Structure of Linked List :
       Blocks of memory (interconnected / linked) are called as "Node"
       Node -> | Data || Next |
       'Next' is the pointer that points (stores address) the next node in the list.

       |head|-> |Data1||Address of Data2|-> |Data2||Address of Data3|-> |Data3||null|
       * 'head' pointer stores the address of the first node of the linked list. [start of a linked-list]
       *  'null' represents the end of a linked-list.

       * Each and every 'Node' just takes care of it's next 'Node'

    */

    node* head = NULL; // initialization
    insert_data_at_the_end(head, 1);
    insert_data_at_the_end(head, 2);
    insert_data_at_the_end(head, 3);
    insert_data_at_the_end(head, 4);
    insert_data_at_the_end(head, 5);

    displayLinkedList(head);
    return 0;
}