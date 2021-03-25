#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

TreeNode<int> *takeInputLevelWise()
{
    cout << "Enter root data: ";
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        int numChild;
        cout << "Enter number of children of " << front->data << ": ";
        cin >> numChild;

        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter " << i << "th child of " << front->data << ": ";
            cin >> childData;

            // TreeNode<int> child(childData);  This will be deleted after for loop; allocate dynamically
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

TreeNode<int> *takeInput()
{
    cout << "Enter data: ";
    int rootData;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    int n;
    cout << "Enter number of children of " << rootData << ": ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInput();
        root->children.push_back(child);
    }

    return root;
}

void printLevelWise(TreeNode<int> *root)
{
    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout << front->data << ":";

        for (int i = 0; i < front->children.size(); i++)
        {
            if (i == front->children.size() - 1)
            {
                cout << front->children[i]->data;
            }

            else
            {
                cout << front->children[i]->data << ",";
            }

            pendingNodes.push(front->children[i]);
        }
        cout << endl;
    }
}

// this format was used because printing simply the children does not convey the info about its structure
// format to print a tree = parent data: children data separated by commas, and recur
void printTree(TreeNode<int> *root)
{

    // this is an edge case, not a base case
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << ": ";

    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ", ";
    }

    cout << endl;

    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}

// level K is same as depth K; level of root = 0
void printAtLevelK(TreeNode<int> *root, int k) {
    if (root == nullptr) {
        return;
    }
    
    if (k == 0) {
        cout << root->data << " ";
        return;
    }

    for (int i = 0; i < root->children.size(); i++) {
        printAtLevelK(root->children[i], k-1);
    }
}

int numNodes(TreeNode<int> *root)
{
    if (root == nullptr) {
        return 0;
    }
    int ans = 1;

    for (int i = 0; i < root->children.size(); i++)
    {
        ans += numNodes(root->children[i]);
    }

    return ans;
}

int sumOfNodes(TreeNode<int> *root)
{
    int ans = root->data;

    for(int i = 0; i < root->children.size(); i++) {
        ans += sumOfNodes(root->children[i]);
    }

    return ans;
}

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    if (root == nullptr) {
        return root;
    }

    TreeNode<int> *maxNode = root;

    for (int i = 0; i < root->children.size(); i++) {
        TreeNode<int> *subMaxNode = maxDataNode(root->children[i]);
        if (subMaxNode->data > maxNode->data) {
            maxNode = subMaxNode;
        }
    }

    return maxNode;
}

// only root node exists => height = 1
int getHeight(TreeNode<int>* root) {
    int subHeight = 0;

    for (int i = 0; i < root->children.size(); i++) {
        int tempHeight = getHeight(root->children[i]);
        if (tempHeight > subHeight) {
            subHeight = tempHeight; 
        }
    }

    return (subHeight+1);
}

int getLeafNodeCount(TreeNode<int>* root) {
    if (root->children.size() == 0) {
        return 1;
    }

    int count = 0;

    for (int i = 0; i < root->children.size(); i++) {
        count += getLeafNodeCount(root->children[i]);
    }

    return count;
}

void preorder(TreeNode<int> *root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++) {
        preorder(root->children[i]);
    }
}

void postorder(TreeNode<int> *root) {
    if (root == nullptr) {
        return;
    }

    for (int i = 0; i < root->children.size(); i++) {
        postorder(root->children[i]);
    }

    cout << root->data << " ";
}

void deleteTree(TreeNode<int> *root) {
    for (int i = 0; i < root->children.size(); i++) {
        deleteTree(root->children[i]);
    }

    delete root;
}

// Sample tree input: 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
int main()
{
    /*
    // Construct nodes
    TreeNode<int> *root = new TreeNode<int>(1);
    TreeNode<int> *node1 = new TreeNode<int>(2);
    TreeNode<int> *node2 = new TreeNode<int>(3);

    // link nodes
    root->children.push_back(node1);
    root->children.push_back(node2);

    printTree(root);
    */

    TreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);

    cout << "Number of nodes: " << numNodes(root) << endl;
    cout << "Sum of nodes: " << sumOfNodes(root) << endl;
    cout << "Max data node: " << maxDataNode(root)->data << endl;
    cout << "Height of tree: " << getHeight(root) << endl;
    cout << "Number of leaf nodes: " << getLeafNodeCount(root) << endl;
    cout << "Nodes at level 2: ";
    printAtLevelK(root, 2);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    // deleteTree(root);
    delete root; // invoke the destructor, let it delete the whole tree

    return 0;
}