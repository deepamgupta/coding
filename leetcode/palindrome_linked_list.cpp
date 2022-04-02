// https://leetcode.com/problems/palindrome-linked-list/

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
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return true;

        ListNode *mid = midNode(head);
        ListNode *tail = reverseList(mid);

        while (head != tail && tail != nullptr)
        {
            if (head->val != tail->val)
                return false;

            head = head->next;
            tail = tail->next;
        }

        return true;
    }

    ListNode *midNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode *reverseList(ListNode *head)
    {
        if (head->next == nullptr)
            return head;

        ListNode *temp = head;
        ListNode *prev = head;
        ListNode *cur = head->next;

        while (cur != nullptr)
        {
            prev = cur;
            cur = cur->next;
            prev->next = head;
            head = prev;
        }
        temp->next = nullptr;
        return head;
    }
};

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

    cout << Solution().isPalindrome(head) << "\n";

    return 0;
}