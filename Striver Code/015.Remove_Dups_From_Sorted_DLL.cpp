// Remove duplicated from sorted DLL

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
    Node *removeDuplicates(Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        Node *tail = head;

        // Find tail
        while (tail->next != NULL)
        {
            tail = tail->next;
        }

        Node *start = head;

        while (start != NULL)
        {
            Node *t = tail;

            while (t != start)
            {
                Node *prevNode = t->prev;

                if (t->data == start->data)
                {
                    // If deleting tail, update tail
                    if (t == tail)
                    {
                        tail = tail->prev;
                    }

                    // Remove t safely
                    if (t->prev != NULL)
                        t->prev->next = t->next;

                    if (t->next != NULL)
                        t->next->prev = t->prev;

                    delete t;
                }

                // Doing the same for previous nodes
                t = prevNode;
            }

            // Checking for the next in front
            start = start->next;
        }

        return head;
    }
};

int main()
{

    return 0;
}