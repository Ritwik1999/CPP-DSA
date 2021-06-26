#include <iostream>
#include <queue>
#include <stack>
#include <climits>
#include <cstdlib>
#include "LLNode.h"
#include "BinaryTreeNode.h"
using namespace std;

void printLL(Node<int> *head)
{
    Node<int> *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printTree(BinaryTreeNode<int> *root)
{
    // Binary Trees have to have a base case
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << ": ";

    if (root->left != nullptr)
    {
        cout << "L" << root->left->data;
    }
    if (root->right != nullptr)
    {
        cout << "R" << root->right->data;
    }
    cout << endl;
    printTree(root->left);
    printTree(root->right);
}

void printTreeLevelWise(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";

        if (front->left != nullptr)
        {
            cout << "L:" << front->left->data;
            pendingNodes.push(front->left);
        }

        else
        {
            cout << "L:-1";
        }

        if (front->right != nullptr)
        {
            cout << ",R:" << front->right->data;
            pendingNodes.push(front->right);
        }

        else
        {
            cout << ",R:-1";
        }

        cout << endl;
    }

    return;
}

// Bad and unintuitive way to take input, basic though
BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cout << "Enter data: ";
    cin >> rootData;

    if (rootData == -1)
    {
        return nullptr;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = takeInput();
    root->right = takeInput();

    return root;
}

BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter root data: ";
    cin >> rootData;

    if (rootData == -1)
    {
        return nullptr;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (pendingNodes.size() != 0)
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();

        cout << "Enter left child of " << front->data << ": ";
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }

        cout << "Enter right child of " << front->data << ": ";
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }

    return root;
}

int numNodes(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    return (1 + numNodes(root->left) + numNodes(root->right));
}

int getSum(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    return (root->data + getSum(root->left) + getSum(root->right));
}

bool isNodePresent(BinaryTreeNode<int> *root, int x)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->data == x)
    {
        return true;
    }

    return isNodePresent(root->left, x) || isNodePresent(root->right, x);
}

void mirrorBinaryTree(BinaryTreeNode<int> *root)
{

    if (root == nullptr)
    {
        return;
    }

    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);

    BinaryTreeNode<int> *temp = root->left;
    root->left = root->right;
    root->right = temp;

    return;
}

// Generic trees have only two types of traversals, whereas binary trees have 3 types of traversals
void inOrder(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }

    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }

    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// O(n); because negligible work done at each step, and every node visited once.
int height(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    return 1 + max(height(root->left), height(root->right));
}

// See the txt file
int diameter(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);

    return max(option1, max(option2, option3));
}

// Complexity: O(n). Use this approach frequently
pair<int, int> heightDiameter(BinaryTreeNode<int> *root)
{
    // Base Case
    if (root == nullptr)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }

    // Hypothesis (Reursion)
    pair<int, int> leftAns = heightDiameter(root->left);
    pair<int, int> rightAns = heightDiameter(root->right);
    int ld = leftAns.second;
    int lh = leftAns.first;
    int rd = rightAns.second;
    int rh = rightAns.first;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));

    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;
}

pair<int, int> getMinAndMax(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        pair<int, int> p;
        p.first = INT_MAX;
        p.second = INT_MIN;
        return p;
    }

    pair<int, int> leftAns = getMinAndMax(root->left);
    pair<int, int> rightAns = getMinAndMax(root->right);

    int minEle = min(root->data, min(leftAns.first, rightAns.first));
    int maxEle = max(root->data, max(leftAns.second, rightAns.second));

    pair<int, int> p;
    p.first = minEle;
    p.second = maxEle;

    return p;
}

// TODO: Improve this fuction to return a pair
/*
    For a non empty binary tree to be balanced, following conditions must be met:
    1. The left and right subtrees must be balanced.
    2. |hL - hR| <= 1, where hL is the height or depth of left subtree and hR is the height or depth of right subtree.
*/
bool isBalanced(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return true;
    }

    bool leftBalanced = isBalanced(root->left);
    if (leftBalanced == false)
    {
        return false;
    }

    bool rightBalanced = isBalanced(root->right);
    if (rightBalanced == false)
    {
        return false;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    return (abs(lh - rh) <= 1);
}

void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }

    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(nullptr);

    while (q.size() != 0)
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();

        cout << front->data << " ";

        if (front->left != nullptr)
        {
            q.push(front->left);
        }

        if (front->right != nullptr)
        {
            q.push(front->right);
        }

        if (q.front() == nullptr)
        {
            cout << endl;
            q.pop();
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
    }

    return;
}

BinaryTreeNode<int> *removeLeafNodes(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return root;
    }

    if (root->left == nullptr && root->right == nullptr)
    {
        delete root;
        return nullptr;
    }

    root->left = removeLeafNodes(root->left);
    root->right = removeLeafNodes(root->right);

    return root;
}

void printNodesWithoutSibling(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }

    if ((root->left == nullptr && root->right != nullptr) || (root->left != nullptr && root->right == nullptr))
    {
        if (root->left == nullptr)
        {
            cout << root->right->data << " ";
        }
        else
        {
            cout << root->left->data << " ";
        }
    }

    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);

    return;
}

void zigZagOrder(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }

    stack<int> s;
    bool reverse = false;

    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(nullptr);

    while (q.size() != 0)
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();

        if (reverse)
        {
            s.push(front->data);
        }
        else
        {
            cout << front->data << " ";
        }

        if (front->left != nullptr)
        {
            q.push(front->left);
        }

        if (front->right != nullptr)
        {
            q.push(front->right);
        }

        if (q.front() == nullptr)
        {
            q.pop();
            if (!q.empty())
            {
                q.push(nullptr);
            }
            while (!s.empty())
            {
                cout << s.top() << " ";
                s.pop();
            }
            cout << endl;
            reverse = !reverse;
        }
    }
}

vector<Node<int> *> constructLinkedListForEachLevel(BinaryTreeNode<int> *root)
{
    vector<Node<int> *> ans;

    if (root == nullptr)
    {
        return ans;
    }

    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(nullptr);

    Node<int> *last = nullptr;

    while (q.size() != 0)
    {
        BinaryTreeNode<int> *front = q.front();
        q.pop();

        Node<int> *newNode = new Node<int>(front->data);

        if (last == nullptr)
        {
            ans.push_back(newNode);
            last = newNode;
        }
        else
        {
            last->next = newNode;
            last = newNode;
        }

        if (front->left != nullptr)
        {
            q.push(front->left);
        }

        if (front->right != nullptr)
        {
            q.push(front->right);
        }

        if (q.front() == nullptr)
        {
            last = nullptr;
            q.pop();
            if (!q.empty())
            {
                q.push(nullptr);
            }
        }
    }
    return ans;
}

vector<int>* getRootToNodePath(BinaryTreeNode<int> *root, int data) {
    if (root == nullptr) {
        return nullptr;
    }

    if (root->data == data) {
        vector<int> *output = new vector<int>();
        // -> means go to the location pointed by the pointer
        output->push_back(root->data);
        return output;
    }

    vector<int> *leftOutput = getRootToNodePath(root->left, data);
    if (leftOutput != nullptr) {
        leftOutput->push_back(root->data);
        return leftOutput;
    }

    vector<int> *rightOutput = getRootToNodePath(root->right, data);
    if (rightOutput != nullptr) {
        rightOutput->push_back(root->data);
        return rightOutput;
    }

    return nullptr;
}

// Sample input: 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
// Sample input2: 2 4 5 6 -1 -1 7 20 30 80 90 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1 -1
int main()
{
    /*
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);

    root->left = node1;
    root->right = node2;
    */

    BinaryTreeNode<int> *root = takeInputLevelWise();
    printTreeLevelWise(root);
    cout << "Number of nodes in the tree = " << numNodes(root) << endl;
    cout << "Sum of nodes in the tree = " << getSum(root) << endl;
    int element;
    cout << "Enter a value to be searched in the tree: ";
    cin >> element;
    if (isNodePresent(root, element))
    {
        cout << "Node with data " << element << " found" << endl;
    }
    else
    {
        cout << "Node with data " << element << " not found" << endl;
    }
    cout << "Sum of nodes in the tree = " << getSum(root) << endl;
    cout << "Inorder traversal: ";
    inOrder(root);
    cout << endl;
    pair<int, int> minMaxAns = getMinAndMax(root);
    cout << "Min value: " << minMaxAns.first << "\nMax value: " << minMaxAns.second << endl;
    pair<int, int> p = heightDiameter(root);
    cout << "Height: " << p.first << "\nDiameter: " << p.second << endl;
    cout << "Tree balanced? " << isBalanced(root) << endl;
    cout << "Print level wise:\n";
    printLevelWise(root);
    cout << "Nodes without sibling:\n";
    printNodesWithoutSibling(root);
    cout << endl;

    cout << "Linked List for each level:\n";
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);
    for (int i = 0; i < ans.size(); i++)
    {
        printLL(ans[i]);
    }

    cout << "Alternate levels printed in reverse:\n";
    zigZagOrder(root);

    cout << "Mirrored tree:\n";
    mirrorBinaryTree(root);
    printLevelWise(root);

    int nodeKey;
    cout << "Enter node value whose path from root is to be found: ";
    cin >> nodeKey;
    vector<int> *path = getRootToNodePath(root, nodeKey);
    if (path != nullptr) {
        for (int i = 0; i < path->size(); i++) {
            cout << path->at(i) << " ";
        }
        cout << endl;
    } else {
        cout << "Entered key not found in the tree\n";
    }

    cout << "Leaf Nodes removed:\n";
    root = removeLeafNodes(root);
    printLevelWise(root);

    delete path;
    delete root; // invokes destructor
    return 0;
}