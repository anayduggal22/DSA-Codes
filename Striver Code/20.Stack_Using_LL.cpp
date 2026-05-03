// Implement stack using Linkedlist

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
    // A whole stack
    Node *s = NULL;

    solution()
    {
    }
    void push(int data)
    {
        if (s == NULL)
        {
            Node *temp = new Node(data);
            s = temp;
        }

        else{
            Node *temp = new Node(data);
            temp->next = s;
            s = temp;
        }
    }

    int pop(){
        int a;
        if(s == NULL){
            return -1;
        }
       
        Node* temp = s;
        s = s->next;
        a = temp->data;
        delete(temp);
        return a;
    }

    int top(){
        if(s == NULL){
            return -1;
        }
        return s->data;
    }
};

int main()
{

    return 0;
}