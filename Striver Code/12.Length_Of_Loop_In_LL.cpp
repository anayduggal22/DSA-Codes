// Length of Loop in Linked List

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor to initialize node with a value
    Node(int val)
    {
        data = val;
        next = nullptr;
    }

    void insert_end(Node *head, int val)
    {
        Node *ptr = new Node(val);

        Node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;
    }
};

class solution
{
public:

    // Using Slow & Fast Pointer [Floyd’s algorithm]
    int lengthOfLoop(Node* head) {

        Node* slow = head;
        Node* fast = head;
        int iscycle = 0;

        // For Finding if the linked list is a cycle or not
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            // When both slow and fast pointer meet, then that list is a cycle
            if(slow == fast){
                iscycle = 1;
                break;
            }
        }
        
        if(iscycle == 0){
            return 0;
        }

        // Now fixing one pointer, and using do-while loop moving the other pointer in the cycle till it reaches 
        // the position where it is equal to the fixed pointer
        int length = 0;
        do{
            fast = fast->next;
            length++;
        }while(slow != fast);

        return length;

    }
    
};

int main()
{

    return 0;
}