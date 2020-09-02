// https://leetcode.com/problems/merge-two-sorted-lists/

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {

        if (l1 == nullptr)
        {
            return l2;
        }
        else if (l2 == nullptr)
        {
            return l1;
        }

        ListNode *p1;
        ListNode *p2;
        ListNode *p3;
        ListNode *mergedList;
        p1 = l1->val < l2->val ? l1 : l2;
        p2 = p1->next;
        p3 = p1 == l1 ? l2 : l1;

        mergedList = p1;

        while (p3 != nullptr && p2 != nullptr)
        {
            if (p3->val > p2->val)
            {
                p1 = p2;
                p2 = p2->next;
            }
            else
            {
                p1->next = p3;
                p3 = p3->next;
                p1 = p1->next;
                p1->next = p2;
            }
        }

        if (p2 == nullptr)
        {
            p1->next = p3;
        }

        return mergedList;
    }
};