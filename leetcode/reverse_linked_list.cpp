// https://leetcode.com/problems/reverse-linked-list/

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
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *newHead = reverseListIterative(head);
        ListNode *newHead = reverseListRecursive(head, head->next);

        head->next = nullptr;
        head = newHead;
        return head;
    }

    ListNode *reverseListIterative(ListNode *head)
    {
        if (head != nullptr)
        {
            ListNode *cur = head->next;
            ListNode *prev = head;

            while (cur != nullptr)
            {
                prev = cur;
                cur = cur->next;
                prev->next = head;
                head = prev;
            }
        }
        return head;
    }

    ListNode *reverseListRecursive(ListNode *prev, ListNode *cur)
    {
        if (cur->next == nullptr)
        {
            cur->next = prev;
            return cur;
        }
        ListNode *newHead = reverseListRecursive(cur, cur->next);
        cur->next = prev;
        return newHead;
    }
};