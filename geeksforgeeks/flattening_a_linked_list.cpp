// { Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}
// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/* ---------------- My submission ------------------*/


Node* mergeSort(Node*);
Node* merge(Node*, Node*);

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
    Node* temp = root->next;
    root = mergeSort(root);
    root->next = temp;
    
    Node* previous = root;
    
    while(previous->next != NULL){
        temp = mergeSort(previous->next);
        temp->next = previous->next->next;
        previous->next = temp;
        previous = temp;
    }
    
    while(root->next != NULL)
    {
        temp = root->next->next;
        root = merge(root, root->next);
        root->next = temp;
    }
    
    return root;
}

Node* mergeSort(Node* root)
{
    if(root == NULL || root->bottom == NULL) 
        return root;
    
    Node* slow = root;
    Node* fast = root;
    Node* prev = root;
    
    while(fast != NULL && fast->bottom != NULL)
    {
        prev = slow;
        slow = slow->bottom;
        fast = fast->bottom->bottom;
    }
    prev->bottom = NULL;
    
    return merge(mergeSort(root), mergeSort(slow));
}

Node* merge(Node* l1, Node* l2)
{
    Node* sortedList = new Node(0);
    Node* current = sortedList;
    
    while(l1 != NULL && l2 != NULL)
    {
        if(l1->data < l2->data)
        {
            current->bottom = l1;
            l1 = l1->bottom;
        }else
        {
            current->bottom = l2;
            l2 = l2->bottom;            
        }
        current = current->bottom;
    }
    
    if(l1 != NULL)
        current->bottom = l1;
    if(l2 != NULL)
        current->bottom = l2;
        
    return sortedList->bottom;
}