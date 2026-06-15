// Implement queue using Linkedlist

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
    // A whole queue
    Node* f = NULL; // Front pointer
    Node* r = NULL; // Rear pointer

    solution(){

    }

    void push(int data){
        // When queue is empty
        if(f == NULL){
            Node* temp = new Node(data);
            f = temp;
            r = temp;
        }

        else{
            Node* temp = new Node(data);
            r->next = temp;
            r = temp;
        }
    }

    int pop(){
        if(f == NULL){
            return -1;
        }
        int a;
        if(f == r){
            a = r->data;
            delete(r);
            f = NULL;
            r = NULL;
            return a;
        }

        Node* temp = f;
        a = temp->data;
        f = f->next;
        delete(temp);
        return a;

    }
    void display(){
        if(f == NULL){
            cout << "Empty";
            return;
        }
        Node* temp = f;
        while(temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

};

int main()
{

    return 0;
}