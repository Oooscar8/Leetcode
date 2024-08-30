#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *dummyHead = new ListNode(0, head);
        ListNode *sentinel = dummyHead;
        while (sentinel->next != nullptr)
        {
            if (sentinel->next->val == val)
            {
                ListNode* tmp = sentinel->next;
                sentinel->next = sentinel->next->next;
                delete tmp;
                continue;
            }
            sentinel = sentinel->next;
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};