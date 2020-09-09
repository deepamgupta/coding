// https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

#include <iostream>
using namespace std;

// structure of linked list node:
struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void removeLoop(Node *head)
{
    Node *p1 = head;
    Node *p2 = head;
    Node *p3 = head;

    while (p1 != NULL && p1->next != NULL)
    {
        p1 = p1->next->next;
        p2 = p2->next;
        if (p1 == p2)
        {
            if (p2 == head) // loop at 0 index i.e. 1st position
            {
                while (p1->next != head)
                {
                    p1 = p1->next;
                }
                p1->next = NULL;
            }
            else
            {
                while (p2->next != p3->next)
                {
                    p2 = p2->next;
                    p3 = p3->next;
                }
                p2->next = NULL;
            }
            break;
        }
    }
}
