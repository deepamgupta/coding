// https://leetcode.com/problems/add-two-numbers/

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1->val == 0 && l1->next == nullptr)
        {
            return l2;
        }
        if (l2->val == 0 && l2->next == nullptr)
        {
            return l1;
        }

        ListNode *p1 = l1;
        ListNode *p2 = l2;

        int curSum = p1->val + p2->val;

        ListNode *ans = new ListNode(curSum % 10, nullptr);
        ListNode *pans = ans;

        int carry = curSum / 10;

        p1 = p1->next;
        p2 = p2->next;

        while (p1 != nullptr && p2 != nullptr)
        {
            curSum = p1->val + p2->val + carry;
            carry = curSum / 10;

            pans->next = new ListNode(curSum % 10, nullptr);

            pans = pans->next;
            p1 = p1->next;
            p2 = p2->next;
        }

        while (p1 != nullptr)
        {
            curSum = p1->val + carry;
            carry = curSum / 10;

            pans->next = new ListNode(curSum % 10, nullptr);

            pans = pans->next;
            p1 = p1->next;
        }

        while (p2 != nullptr)
        {
            curSum = p2->val + carry;
            carry = curSum / 10;

            pans->next = new ListNode(curSum % 10, nullptr);

            pans = pans->next;
            p2 = p2->next;
        }

        if (carry)
        {
            pans->next = new ListNode(carry, nullptr);
        }

        return ans;
    }
};