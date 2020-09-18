// https://leetcode.com/problems/copy-list-with-random-pointer/
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {

        Node *current = head;
        while (current != NULL)
        {
            Node *duplicate = new Node(current->val);
            duplicate->next = current->next;
            current->next = duplicate;
            current = duplicate->next;
        }

        current = head;
        while (current->next != NULL)
        {
            if (current->random != NULL)
            {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }

        current = head;
        Node *deepCopy = new Node(0);
        Node *current2 = deepCopy;
        while (current != NULL)
        {
            current2->next = current->next;
            current->next = current->next->next;

            current2 = current2->next;
            current = current->next;
        }

        return deepCopy;
    }
};