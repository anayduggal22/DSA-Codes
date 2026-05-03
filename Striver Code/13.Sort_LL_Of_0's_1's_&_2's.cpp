// Sort a Linked List of 0's 1's and 2's by changing links


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor to initialize node with a value.
    Node(int val)
    {
        data = val;
        next = nullptr;
    }

    
};

class solution
{
public:
    void sortZeroOneTwo(Node *LL)
    {
        //Creating linked list for each 0, 1 and 2 val having nodes, then connecting them together.
        //Initially these are dummy
        Node *zero_head = new Node(13);
        Node *one_head = new Node(13);
        Node *two_head = new Node(13);

        Node *zero = zero_head;
        Node *one = one_head;
        Node *two = two_head;

        Node *temp = LL;


        while (temp != NULL)
        {
            if (temp->data == 0)
            {
                // Links the node to zero list.
                zero->next = temp;
                zero = zero->next;
                
            }
            else if (temp->data == 1)
            {
                // Links the node to one list.
                one->next = temp;
                one = one->next;
            }
            else if (temp->data == 2)
            {
                // Links the node to two list.
                two->next = temp;
                two = two->next;
                
            }

            // Detaching the Node.
            Node* p = temp;

            temp = temp->next;

            p->next = NULL;
        }

        // Removing the dummy node from all the lists
        zero_head = zero_head->next;
        one_head = one_head->next;
        two_head = two_head->next;
        
        // Creating a head pointer and making it NULL.
        Node* head = NULL;

        // When zero list is not empty.
        if (zero_head != NULL)
        {
            head = zero_head;
        }
        
        
        // When one list is not empty.
        if (one_head != NULL)
        {
            // When zero list was empty
            if(head == NULL){
                head = one_head;
            }
            
            // When zero list was not empty.
            else{
                zero->next = one_head;
            }
            
            
        }
        
        // When two list is not empty
        if (two_head != NULL)
        {
            
            // When both one & zero list were empty.
            if(head == NULL){
                head = two_head;
            }

            // When both one & zero list OR either of them were not empty.
            else{
                if(one_head != NULL){
                    one->next = two_head;
                }
                else{
                    zero->next = two_head;
                }
            }
        }

        // Make this as the original list.
        LL = head;
    }
};

int main()
{

    return 0;
}