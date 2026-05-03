// Add 1 to a number represented by LL

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
    Node *addOne(Node *head)
    {
        // When head is NULL, return list with the one element whose value is 1
        if (head == NULL)
        {
            return new Node(1);
        }

        // Reversing the Linked List
        Node *prev = NULL;
        Node *curr = head;
        Node *front = NULL;
        while (curr != NULL)
        {
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        // The Linked List is reversed
        head = prev;

        // To add One to the first[initially last] element and check for carry
        int add = 1;
        int carry = 0;
        Node *temp = head;

        while (temp != NULL)
        {
            // When both add and carry becomes zero, break the loop
            if (add == 0 && carry == 0)
            {
                break;
            }
            prev = temp;
            temp->data += add + carry;
            add = 0;
            if (temp->data > 9)
            {
                carry = 1;
                temp->data -= 10;
            }
            else
            {
                carry = 0;
            }
            temp = temp->next;
        }

        // To check if the carry occured in the last bit also
        if (carry)
        {
            Node *p = new Node(1);
            prev->next = p;
        }

        // To reverse the Linked List back to the original
        prev = NULL;
        curr = head;
        front = NULL;
        while (curr != NULL)
        {
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        // The Linked List is reversed to original
        head = prev;

        return head;
    }
};

int main()
{

    return 0;
}