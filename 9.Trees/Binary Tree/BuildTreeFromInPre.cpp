#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"

using namespace std;

BinaryTreeNode<int> *buildTreeRec(int *preorder, int preS, int preE, int *inorder, int inS, int inE)
{

    if (inE < inS)
    {
        return nullptr;
    }

    int rootData = preorder[preS];
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    int rootIndexInorder = inS;
    while (inorder[rootIndexInorder] != rootData)
    {
        rootIndexInorder++;
    }

    int lpres = preS + 1;
    int lins = inS;
    int line = rootIndexInorder - 1;
    int lpree = line - lins + lpres;

    root->left = buildTreeRec(preorder, lpres, lpree, inorder, lins, line);

    int rpres = lpree + 1;
    int rpree = preE;
    int rins = rootIndexInorder + 1;
    int rine = inE;

    root->right = buildTreeRec(preorder, rpres, rpree, inorder, rins, rine);

    return root;
}

BinaryTreeNode<int> *buildTree(int *preorder, int preLength, int *inorder, int inLength)
{
    return buildTreeRec(preorder, 0, preLength - 1, inorder, 0, inLength - 1);
}

BinaryTreeNode<int> *takeInput()
{
    int rootData;
    cin >> rootData;
    if (rootData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1)
        {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1)
        {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL)
        {
            if (q.empty())
            {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL)
        {
            q.push(first->left);
        }
        if (first->right != NULL)
        {
            q.push(first->right);
        }
    }
}

int main()
{
    cout << "Enter number of nodes in the tree: ";
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];

    cout << "Enter preorder elements: ";
    for (int i = 0; i < size; i++)
        cin >> pre[i];
    
    cout << "Enter inorder elements: ";
    for (int i = 0; i < size; i++)
        cin >> in[i];

    BinaryTreeNode<int> *root = buildTree(pre, size, in, size);

    cout << "Tree constructed:\n";
    printLevelATNewLine(root);
    cout << endl;
}