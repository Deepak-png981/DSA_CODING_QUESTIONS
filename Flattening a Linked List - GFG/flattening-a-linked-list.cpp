//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }

};

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
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

class Solution {
public:
   Node *mergeTwoList(Node *a, Node *b){
        Node *temp= new Node(-1);
        Node *res=temp;
        
        while(a!=NULL && b!=NULL){
            if(a->data > b->data){
                temp->bottom = b;
                temp = temp->bottom;
                b = b->bottom;
            }
            else{
                temp->bottom = a;
                temp= temp->bottom;
                a = a->bottom;
            }
        }
        while(a!=NULL){
            temp->bottom=a;
            temp=temp->bottom;
            a=a->bottom;
        }
        while(b!=NULL){
            temp->bottom=b;
            temp=temp->bottom;
            b=b->bottom;
        }
        return res->bottom;
    }
    
    Node *flatten(Node *root)
    {
        // Your code here
        if(root == NULL || root->next == NULL){
            return root;
        }
        // recurssion for root right lists
        root->next = flatten(root->next);
        // merge the cuurent list with the next list
        root = mergeTwoList(root, root->next);
        
        // return the root
        // it will be in turn marged with left lists
        return root;
    }
};


//{ Driver Code Starts.

int main(void) {

    int t;
    cin >> t;
    while (t--) {
        int n, m, flag = 1, flag1 = 1;
        struct Node * temp = NULL;
        struct Node * head = NULL;
        struct Node * pre = NULL;
        struct Node * tempB = NULL;
        struct Node * preB = NULL;
        cin >> n;
        int work[n];
        for (int i = 0; i < n; i++)
            cin >> work[i];
        for (int i = 0; i < n; i++) {
            m = work[i];
            --m;
            int data;
            scanf("%d", &data);
            temp = new Node(data);
            temp->next = NULL;
            temp->bottom = NULL;

            if (flag) {
                head = temp;
                pre = temp;
                flag = 0;
                flag1 = 1;
            }
            else {
                pre->next = temp;
                pre = temp;
                flag1 = 1;
            }
            for (int j = 0; j < m; j++) {

                int temp_data;
                scanf("%d", &temp_data);
                tempB = new Node(temp_data);

                if (flag1) {
                    temp->bottom = tempB;
                    preB = tempB;
                    flag1 = 0;
                }
                else {
                    preB->bottom = tempB;
                    preB = tempB;
                }
            }
        }
        Node *fun = head;
        Node *fun2 = head;

        Solution ob;
        Node* root = ob.flatten(head);
        printList(root);
        cout << endl;

    }
    return 0;
}

// } Driver Code Ends