// Merge Two Sorted Linked Lists [ Recursion ]

// We compare the first nodes of both linked lists.
// The smaller node becomes part of the final merged list.
// Then we recursively call the function for the next node of that list
// and the other list.
// Base cases:
// If list1 is NULL, return list2.
// If list2 is NULL, return list1.
// We keep doing this until both lists are merged into a single sorted list.

#include <iostream>
#include <vector>

using namespace std;

// Definition for linked list.
struct ListNode
{
    int val;
    ListNode *next;

    ListNode()
    {
        val = 0;
        next = NULL;
    }
    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        // Base Case
        if (list1 == NULL)
        {
            return list2;
        }

        // Base Case
        if (list2 == NULL)
        {
            return list1;
        }

        // Choose smaller node and recurse
        if (list1->val < list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

int main()
{
    Solution obj;

    // Creating first linked list: 1 -> 3 -> 5
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    // Creating second linked list: 2 -> 4 -> 6
    ListNode *list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    // Merging lists
    ListNode *merged = obj.mergeTwoLists(list1, list2);

    // Printing merged list
    cout << "Merged List: ";
    while (merged != NULL)
    {
        cout << merged->val << " ";
        merged = merged->next;
    }

    return 0;
}