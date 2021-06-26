/*
    BST is a Binary Tree with a constraint:
    The root data is greater than all of its descendants in the left subtree, 
    and is less than or equal to all of its descendants in the right subtree
*/

#include <iostream>
#include <queue>
#include <stack>
#include <climits>
#include <cstdlib>
#include "BinaryTreeNode.h"
#include "LLNode.h"
using namespace std;

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

BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "\nEnter root data: ";
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

// Complexity: O(h), h = height of binary trees = n for skewed trees, and log n for balanced trees
BinaryTreeNode<int> *findNode(BinaryTreeNode<int> *root, int k)
{
    if (root == nullptr)
    {
        return root;
    }

    if (root->data == k)
    {
        return root;
    }

    else if (k < root->data)
    {
        return findNode(root->left, k);
    }

    else
    {
        return findNode(root->right, k);
    }
}

void printBetweenK1K2(BinaryTreeNode<int> *root, int k1, int k2)
{
    if (root == nullptr)
    {
        return;
    }

    if (k1 <= root->data && root->data <= k2)
    {
        cout << root->data << " ";
    }

    if (root->data > k1)
    {
        printBetweenK1K2(root->left, k1, k2);
    }
    else if (root->data <= k2)
    {
        printBetweenK1K2(root->right, k1, k2);
    }
}

int minimum(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return INT_MAX;
    }

    return min(root->data, min(minimum(root->left), minimum(root->right)));
}

int maximum(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return INT_MIN;
    }

    return max(root->data, max(maximum(root->left), maximum(root->right)));
}

// Approach: root's data should be > the greatest element in the left subtree, and must be <= the smallest element in the right subtree
// Complxity: O(n*h)    Same story as height and diameter
bool isBST(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return true;
    }

    int leftMax = maximum(root->left);
    int rightMin = minimum(root->right);

    bool ans = (root->data > leftMax) && (root->data <= rightMin) && isBST(root->left) && isBST(root->right);

    return ans;
}

class IsBSTReturn
{
public:
    bool isBST;
    int maximum;
    int minimum;
};

// Complxity: O(n)  Constant work done at each of the n nodes
IsBSTReturn isBST2(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        IsBSTReturn ans;
        ans.isBST = true;
        // The below values are set so because we care only about root->data <= right min and root->data > left max. So, if root is null, we return an answer in favour of the BST condition
        ans.minimum = INT_MAX;
        ans.maximum = INT_MIN;
        return ans;
    }

    IsBSTReturn leftAns = isBST2(root->left);
    IsBSTReturn rightAns = isBST2(root->right);

    int overallMinimum = min(root->data, min(leftAns.minimum, rightAns.minimum));
    int overallMaximum = max(root->data, max(leftAns.maximum, rightAns.maximum));

    bool overallIsBST = (root->data > leftAns.maximum) && (root->data <= rightAns.minimum) && leftAns.isBST && rightAns.isBST;

    IsBSTReturn ans;
    ans.isBST = overallIsBST;
    ans.minimum = overallMinimum;
    ans.maximum = overallMaximum;

    return ans;
}

// There is a much more developer friendly alternative to the isBST2 function, see isBST-prefered.png
bool isBST3(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX)
{
    if (root == nullptr)
    {
        return true;
    }

    if (root->data < min || root->data > max)
    {
        return false;
    }

    bool isLeftOK = isBST3(root->left, min, root->data - 1);
    bool isRightOK = isBST3(root->right, root->data, max);

    return isLeftOK && isRightOK;
}

BinaryTreeNode<int> *constructTreeRec(int *input, int si, int ei)
{
    if (ei < si)
    {
        return nullptr;
    }

    int mid = (si + ei) / 2;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(input[mid]);

    root->left = constructTreeRec(input, si, mid - 1);
    root->right = constructTreeRec(input, mid + 1, ei);

    return root;
}

BinaryTreeNode<int> *constructTreeFromSortedArray(int *input, int n)
{
    return constructTreeRec(input, 0, n - 1);
}

pair<Node<int> *, Node<int> *> constructLinkedListRec(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        pair<Node<int> *, Node<int> *> ans;
        ans.first = nullptr;
        ans.second = nullptr;
        return ans;
    }

    pair<Node<int> *, Node<int> *> leftPair = constructLinkedListRec(root->left);
    pair<Node<int> *, Node<int> *> rightPair = constructLinkedListRec(root->right);

    Node<int> *head = new Node<int>(root->data);
    Node<int> *last = head;

    if (rightPair.first != nullptr)
    {
        head->next = rightPair.first;
        last = rightPair.second;
    }

    if (leftPair.first != nullptr)
    {
        leftPair.second->next = head;
        head = leftPair.first;
    }

    pair<Node<int> *, Node<int> *> ans;
    ans.first = head;
    ans.second = last;
    return ans;
}

Node<int> *constructLinkedList(BinaryTreeNode<int> *root)
{
    pair<Node<int> *, Node<int> *> LLPair = constructLinkedListRec(root);
    return LLPair.first;
}

vector<int> *getPath(BinaryTreeNode<int> *root, int data)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    if (root->data == data)
    {
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    else if (data > root->data)
    {
        vector<int> *rightOutput = getPath(root->right, data);
        if (rightOutput != nullptr)
        {
            rightOutput->push_back(root->data);
        }
        return rightOutput;
    }

    vector<int> *leftOutput = getPath(root->left, data);
    if (leftOutput != nullptr)
    {
        leftOutput->push_back(root->data);
    }
    return leftOutput;
}

// Sample input1: 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 (Not a BST)
// Sample input2: 4 2 6 1 10 5 7 -1 -1 -1 -1 -1 -1 -1 -1 (Not a BST)
// Sample input2: 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1 (BST)
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    cout << "\nIs the tree a BST? " << isBST3(root) << endl;

    int nodeKey;
    cout << "Enter node value whose path from root is to be found: ";
    cin >> nodeKey;
    vector<int> *path = getPath(root, nodeKey);
    if (path != nullptr)
    {
        for (int i = 0; i < path->size(); i++)
        {
            cout << path->at(i) << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "Entered key not found in the tree\n";
    }

    // printTree(root);
    // cout << "Elements between 2 and 6: ";
    // printBetweenK1K2(root, 2, 6);
    // cout << "\nEnter value to be searched: ";
    // int searchEle;
    // cin >> searchEle;
    // BinaryTreeNode<int> *search = findNode(root, searchEle);
    // if (search != nullptr)
    // {
    //     cout << "Found" << endl;
    // }
    // else
    // {
    //     cout << "Not Found" << endl;
    // }

    delete path;
    delete root; // invokes destructor
    return 0;
}