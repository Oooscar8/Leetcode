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
        ListNode *sentinel = new ListNode(0, head);
        ListNode *new_head = nullptr;
        bool newHeadExist = false;
        while (sentinel->next != nullptr)
        {
            if (sentinel->next->val == val)
            {
                free(sentinel->next);
                sentinel->next = sentinel->next->next;
                continue;
            }
            else if (!newHeadExist)
            {
                new_head = sentinel->next;
                newHeadExist = true;
            }
            sentinel = sentinel->next;
        }
        free(sentinel);
        return new_head;
    }
};