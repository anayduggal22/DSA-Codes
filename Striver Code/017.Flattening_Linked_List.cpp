// Flattening a Linked List

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition of special linked list:
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode *child;

    ListNode()
    {
        val = 0;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1)
    {
        val = data1;
        next = NULL;
        child = NULL;
    }
    ListNode(int data1, ListNode *next1, ListNode *next2)
    {
        val = data1;
        next = next1;
        child = next2;
    }
};

class Solution
{
public:
    // For inserting at the Start
    ListNode *insert_at_start(ListNode *head, int data)
    {

        ListNode *ptr = new ListNode(data);

        if (head == NULL)
        {
            return ptr;
        }

        // Chain the new list using child pointer
        ptr->child = head;
        ptr->next = NULL;
        head = ptr;
        return head;
    }

    // This is the BRUTE FORCE METHOD
    // Time is O(n logn) && Space is O(n)
    ListNode *flattenLinkedList(ListNode *head)
    {

        ListNode *tempr = head;
        ListNode *tempc;
        vector<int> arr;

        // For each horizontal node
        while (tempr != NULL)
        {
            // For each vertical node
            tempc = tempr;
            while (tempc != NULL)
            {
                arr.push_back(tempc->val);
                tempc = tempc->child;
            }
            tempr = tempr->next;
        }

        // Sort the vector in descending order lso that inserting at start makes it ascendingly sorted
        sort(arr.begin(), arr.end(), greater<int>());
        ListNode *new_head = NULL;
        int i = 0;

        while (i < arr.size())
        {
            new_head = insert_at_start(new_head, arr[i]);
            i++;
        }

        // Return the new head;
        return new_head;
    }
};

int main()
{

    return 0;
}