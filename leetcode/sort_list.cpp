// https://leetcode.com/problems/sort-list/

#include <bits/stdc++.h>
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
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *temp = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = nullptr;

        return merge(sortList(head), sortList(slow));
    }

    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode *l = new ListNode(0);
        ListNode *p = l;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val < l2->val)
            {
                p->next = l1;
                l1 = l1->next;
            }
            else
            {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1)
            p->next = l1;
        else
            p->next = l2;

        return l->next;
    }
};

void printList(ListNode *head)
{
    while (head != nullptr)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

int main()
{
    ListNode *head = nullptr;
    ListNode *cur;
    int n;
    cin >> n;

    while (n--)
    {
        int a;
        cin >> a;

        ListNode *newNode = new ListNode(a);

        if (head == nullptr)
        {
            head = newNode;
            cur = head;
        }
        else
        {
            cur->next = newNode;
            cur = cur->next;
        }
    }

    printList(Solution().sortList(head));

    return 0;
}
