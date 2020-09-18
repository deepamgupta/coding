// https://leetcode.com/problems/rotate-list/

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
    ListNode *rotateRight(ListNode *head, int k)
    {

        if (k == 0 || head == nullptr || head->next == nullptr)
            return head;

        ListNode *temp = head;
        int size = 1;

        while (temp->next != nullptr)
        {
            ++size;
            temp = temp->next;
        }

        k = k % size;
        if (k == 0)
            return head;

        int jump = size - k;
        temp->next = head;

        temp = head;

        while (jump > 1)
        {
            temp = temp->next;
            --jump;
        }

        ListNode *newHead = temp->next;
        temp->next = nullptr;

        return newHead;
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
    int n, k;
    cin >> n >> k;

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

    printList(Solution().rotateRight(head, k));

    return 0;
}
