// Delete all occurrences of a key in DLL

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    // Constructor to initialize node with a value.
    Node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class solution
{
public:
    Node *deleteAllOccurrences(Node *head, int target)
    {
        Node *ptr = head;
        Node *next = head;

        while (ptr != NULL)
        {

            // When the node has the targets data
            if (ptr->data == target)
            {
                next = ptr->next;

                // When head is the target
                if (ptr->prev == NULL)
                {
                    if (ptr->next != NULL)
                    {
                        ptr->next->prev = NULL;
                    }
                    // Change the head as it will get deleted
                    head = next;
                }

                // When head is not the target
                else
                {
                    ptr->prev->next = ptr->next;
                    if (ptr->next != NULL)
                    {
                        ptr->next->prev = ptr->prev;
                    }
                }

                // Delete that node and repeat for the next node
                delete (ptr);
                ptr = next;
            }

            // If that node does not have target data
            else
            {
                ptr = ptr->next;
            }
        }

        return head;
    }
};

int main()
{

    return 0;
}