#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"

using namespace std;

BinaryTreeNode<int> *buildTreeRec(int *postorder, int posS, int posE, int *inorder, int inS, int inE)
{
    if (posE < posS || inE < inS)
    {
        return nullptr;
    }

    int rootData = postorder[posE];
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

    int rootIndexInorder = inS;
    while (inorder[rootIndexInorder] != rootData)
    {
        rootIndexInorder++;
    }

    int lposts = posS;
    int lins = inS;
    int line = rootIndexInorder - 1;
    int lposte = line - lins + lposts;

    root->left = buildTreeRec(postorder, lposts, lposte, inorder, lins, line);

    int rposts = lposte + 1;
    int rposte = posE - 1;
    int rins = rootIndexInorder + 1;
    int rine = inE;

    root->right = buildTreeRec(postorder, rposts, rposte, inorder, rins, rine);

    return root;
}

BinaryTreeNode<int> *buildTree(int *postorder, int postLength, int *inorder, int inLength)
{
    return buildTreeRec(postorder, 0, postLength - 1, inorder, 0, inLength - 1);
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
    int *post = new int[size];
    int *in = new int[size];

    cout << "Enter postorder elements: ";
    for (int i = 0; i < size; i++)
        cin >> post[i];

    cout << "Enter inorder elements: ";
    for (int i = 0; i < size; i++)
        cin >> in[i];

    BinaryTreeNode<int> *root = buildTree(post, size, in, size);

    cout << "Tree constructed:\n";
    printLevelATNewLine(root);
    cout << endl;
}