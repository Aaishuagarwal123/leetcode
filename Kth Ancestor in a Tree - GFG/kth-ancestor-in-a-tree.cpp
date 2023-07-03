//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}
int kthAncestor(Node *root, int k, int node);

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        int k , node;
        scanf("%d ",&k);
        scanf("%d ",&node);
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		cout<<kthAncestor(root,k,node)<<endl;
    }
    return 0;
}

// } Driver Code Ends


//User function Template for C++
/*
Structure of the node of the binary tree is as
struct Node
{
	int data;
	struct Node *left, *right;
};
*/
// your task is to complete this function
unordered_map<Node*,Node*> m;
Node* f;
int v;
void mark(Node* root)
{
    if(!root)
    return ;
    queue<Node*> q;
    q.push(root);
    while(!q.empty())
    {
        auto node=q.front();
        q.pop();
        if(node->data==v)
        f=node;
        if(node->left)
        {
            m[node->left]=node;
            q.push(node->left);
        }
        if(node->right)
        {
            m[node->right]=node;
            q.push(node->right);
        }
    }
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    f=NULL;
    v=node;
    int ans=-1;
    if(!root)
    return ans;
    mark(root);
    if(!f)
    return ans;
    queue<Node*> q;
    q.push(f);
    while(!q.empty())
{   
    auto temp=q.front();
   q.pop();
   if(k==0)
   return temp->data;
   if(m.find(temp)==m.end())
   return -1;
   q.push(m[temp]);
   k--;
    }
    return -1;
    }

