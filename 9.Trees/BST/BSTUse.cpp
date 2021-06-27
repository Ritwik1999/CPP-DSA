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
#include <algorithm>
#include "BinaryTreeNode.h"
#include "LLNode.h"
using namespace std;

class Quad
{
public:
    int minimum;
    int maximum;
    bool isBST;
    int height;

    Quad()
    {
        minimum = INT_MAX;
        maximum = INT_MIN;
        isBST = true;
        height = 0;
    }
};

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

void printPairs(vector<int> &a, int si, int ei, int sum)
{
    if (si >= ei)
    {
        return;
    }

    int sumExtremes = a.at(si) + a.at(ei);

    if (sumExtremes == sum)
    {
        cout << a.at(si) << " " << a.at(ei) << endl;
        si++;
        ei--;
    }

    else if (sumExtremes > sum)
    {
        ei--;
    }

    else
    {
        si++;
    }

    printPairs(a, si, ei, sum);

    return;
}

void makeArray(BinaryTreeNode<int> *root, vector<int> &array)
{
    if (root == nullptr)
    {
        return;
    }

    array.push_back(root->data);

    makeArray(root->left, array);
    makeArray(root->right, array);

    return;
}

BinaryTreeNode<int> *getLCABSTRec(BinaryTreeNode<int> *root, int a, int b)
{
    if (root == nullptr || root->data == a || root->data == b)
    {
        return root;
    }

    if (root->data < a && root->data < b)
    {
        return getLCABSTRec(root->right, a, b);
    }

    else if (root->data > a && root->data > b)
    {
        return getLCABSTRec(root->left, a, b);
    }

    BinaryTreeNode<int> *leftAns = getLCABSTRec(root->left, a, b);
    BinaryTreeNode<int> *rightAns = getLCABSTRec(root->right, a, b);

    if (leftAns && rightAns)
    {
        return root;
    }

    if (leftAns)
    {
        return leftAns;
    }

    return rightAns;
}

Quad largestBSTSubtreeRec(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        Quad ans;
        return ans;
    }

    Quad leftAns = largestBSTSubtreeRec(root->left);
    Quad rightAns = largestBSTSubtreeRec(root->right);

    bool overallIsBST = leftAns.isBST && rightAns.isBST && (leftAns.maximum < root->data && rightAns.minimum >= root->data);
    int overallMinimum = min(root->data, min(leftAns.minimum, rightAns.minimum));
    int overallMaximum = max(root->data, max(leftAns.maximum, rightAns.maximum));
    int overallHeight = max(leftAns.height, rightAns.height);

    if (overallIsBST)
    {
        overallHeight++;
    }

    Quad ans;
    ans.minimum = overallMinimum;
    ans.maximum = overallMaximum;
    ans.isBST = overallIsBST;
    ans.height = overallHeight;

    return ans;
}

int replaceWithLargerNodesSumRec(BinaryTreeNode<int> *root, int sum)
{
    if (root == nullptr)
    {
        return sum;
    }

    sum = replaceWithLargerNodesSumRec(root->right, sum);

    sum += root->data;
    root->data = sum;

    sum = replaceWithLargerNodesSumRec(root->left, sum);

    return sum;
}

void printRec(BinaryTreeNode<int> *root, int k, string ans)
{
    if (root == nullptr)
    {
        return;
    }

    ans = ans + to_string(root->data) + " ";

    if (root->left == nullptr && root->right == nullptr && k == root->data)
    {
        cout << ans << endl;
    }

    printRec(root->left, k - root->data, ans);
    printRec(root->right, k - root->data, ans);

    return;
}

void printNodesAtDepthK(BinaryTreeNode<int> *root, int depth)
{
    if (root == nullptr)
    {
        return;
    }

    if (depth == 0)
    {
        cout << root->data << endl;
        return;
    }

    printNodesAtDepthK(root->left, depth - 1);
    printNodesAtDepthK(root->right, depth - 1);

    return;
}

int printnodesAtDistanceK(BinaryTreeNode<int> *root, int K, int elem)
{
    if (root == nullptr)
    {
        return -1;
    }

    if (root->data == elem)
    {
        printNodesAtDepthK(root, K);
        return 0;
    }

    int leftDepth = printnodesAtDistanceK(root->left, K, elem);
    if (leftDepth != -1)
    {
        if (leftDepth + 1 == K)
        {
            cout << root->data << endl;
        }
        else
        {
            printNodesAtDepthK(root->right, K - leftDepth - 2);
        }
        return leftDepth + 1;
    }

    int rightDepth = printnodesAtDistanceK(root->right, K, elem);
    if (rightDepth != -1)
    {
        if (rightDepth + 1 == K)
        {
            cout << root->data << endl;
        }
        else
        {
            printNodesAtDepthK(root->left, K - rightDepth - 2);
        }
        return rightDepth + 1;
    }

    return -1;
}

// TODO: Call all the functions defined below from within the main function
void insertDuplicateNode(BinaryTreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }

    BinaryTreeNode<int> *duplicateNode = new BinaryTreeNode<int>(root->data);
    BinaryTreeNode<int> *leftChild = root->left;
    // BinaryTreeNode<int> *rightChild = root->right;

    root->left = duplicateNode;
    duplicateNode->left = leftChild;

    insertDuplicateNode(leftChild);
    insertDuplicateNode(root->right);
}

void pairSumBinaryTree(BinaryTreeNode<int> *root, int sum)
{

    vector<int> array;

    makeArray(root, array);

    sort(array.begin(), array.end());

    printPairs(array, 0, array.size() - 1, sum);

    return;
}

int getLCABinaryTree(BinaryTreeNode<int> *root, int a, int b)
{
    if (root == nullptr)
    {
        return -1;
    }

    if (root->data == a || root->data == b)
    {
        return root->data;
    }

    int leftAns = getLCABinaryTree(root->left, a, b);
    int rightAns = getLCABinaryTree(root->right, a, b);

    if (leftAns == -1 && rightAns != -1)
    {
        return rightAns;
    }

    if (leftAns != -1 && rightAns == -1)
    {
        return leftAns;
    }

    if (leftAns == rightAns)
    {
        if (leftAns == -1)
        {
            return -1;
        }

        return leftAns;
    }

    return root->data;
}

int getLCABST(BinaryTreeNode<int> *root, int val1, int val2)
{
    BinaryTreeNode<int> *LCANode = getLCABSTRec(root, val1, val2);
    return (LCANode == nullptr ? -1 : LCANode->data);
}

// Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST.
int largestBSTSubtree(BinaryTreeNode<int> *root)
{
    Quad q = largestBSTSubtreeRec(root);
    return q.height;
}

// Given a binary search tree, you have to replace each node's data with the sum of all nodes which are greater or equal than it. You need to include the current node's data also.
// That is, if in given BST there is a node with data 5, you need to replace it with sum of its data (i.e. 5) and all nodes whose data is greater than or equal to 5.
void replaceWithLargerNodesSum(BinaryTreeNode<int> *root)
{
    replaceWithLargerNodesSumRec(root, 0);
}

// For a given Binary Tree of type integer and a number K, print out all root-to-leaf paths where the sum of all the node data along the path is equal to K.
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k)
{
    string ans = "";
    printRec(root, k, ans);
    return;
}

// You are given a Binary Tree of type integer, a target node, and an integer value K.
// Print the data of all nodes that have a distance K from the target node. The order in which they would be printed will not matter.
void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k)
{
    int ans = printnodesAtDistanceK(root, k, node);
    return;
}

// Given a binary search tree and an integer S, find pair of nodes in the BST which sum to S. You can use extra space of the order of O(log n).
void printNodesSumToS(BinaryTreeNode<int> *root, int sum) {
    
    vector<int> array;
    
    makeArray(root, array);
    
    sort(array.begin(), array.end());
    
    printPairs(array, 0, array.size()-1, sum);
    
    return;
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