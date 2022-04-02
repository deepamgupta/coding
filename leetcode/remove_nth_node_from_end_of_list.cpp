// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *back = head;
        ListNode *front = head;

        while (n--)
        {
            front = front->next;
        }

        if (front == nullptr)
        {
            ListNode *newHead = head->next;
            delete head;
            return newHead;
        }

        while (front->next != nullptr)
        {
            front = front->next;
            back = back->next;
        }

        ListNode *toBeDeleted = back;
        back->next = back->next->next;

        toBeDeleted = nullptr;
        delete toBeDeleted;

        return head;
    }
};