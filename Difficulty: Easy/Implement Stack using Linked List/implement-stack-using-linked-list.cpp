//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct StackNode {
    int data;
    StackNode *next;

    StackNode(int a) {
        data = a;
        next = NULL;
    }
};


// } Driver Code Ends

class Node{
    public:
    Node* next;
    int val;
    Node(int data){
        next=NULL;
        val= data;
    }
};

class MyStack {
  private:
    StackNode *top;

  public:
  Node* head=NULL;
    void push(int x) {
        //insert at head
        Node* new_node = new Node(x);
        if(head==NULL){
            head= new_node;
        }else{
            new_node->next=head;
            head=new_node;
        }
        
    }

    int pop() {
        int val;
        if(head){
            val= head->val;
            head=head->next;
        }else return -1;
        return val;
        // code here
    }

    MyStack() { top = NULL; }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        MyStack *sq = new MyStack();
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        int n = nums.size();
        int i = 0;
        while (i < n) {
            int QueryType = nums[i++];
            if (QueryType == 1) {
                int a = nums[i++];
                sq->push(a);
            } else if (QueryType == 2) {
                cout << sq->pop() << " ";
            }
        }
        cout << endl;
        delete sq;
    }
}

// } Driver Code Ends