#include <iostream>
#include <queue>
#include <climits>
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
void printAtLevelK(TreeNode<int> *root, int k)
{
    if (root == nullptr)
    {
        return;
    }

    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        printAtLevelK(root->children[i], k - 1);
    }
}

int numNodes(TreeNode<int> *root)
{
    if (root == nullptr)
    {
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

    for (int i = 0; i < root->children.size(); i++)
    {
        ans += sumOfNodes(root->children[i]);
    }

    return ans;
}

TreeNode<int> *maxDataNode(TreeNode<int> *root)
{
    if (root == nullptr)
    {
        return root;
    }

    TreeNode<int> *maxNode = root;

    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *subMaxNode = maxDataNode(root->children[i]);
        if (subMaxNode->data > maxNode->data)
        {
            maxNode = subMaxNode;
        }
    }

    return maxNode;
}

// only root node exists => height = 1
int getHeight(TreeNode<int> *root)
{
    int subHeight = 0;

    for (int i = 0; i < root->children.size(); i++)
    {
        int tempHeight = getHeight(root->children[i]);
        if (tempHeight > subHeight)
        {
            subHeight = tempHeight;
        }
    }

    return (subHeight + 1);
}

int getLeafNodeCount(TreeNode<int> *root)
{
    if (root->children.size() == 0)
    {
        return 1;
    }

    int count = 0;

    for (int i = 0; i < root->children.size(); i++)
    {
        count += getLeafNodeCount(root->children[i]);
    }

    return count;
}

void preorder(TreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }

    cout << root->data << " ";
    for (int i = 0; i < root->children.size(); i++)
    {
        preorder(root->children[i]);
    }
}

void postorder(TreeNode<int> *root)
{
    if (root == nullptr)
    {
        return;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        postorder(root->children[i]);
    }

    cout << root->data << " ";
}

void deleteTree(TreeNode<int> *root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        deleteTree(root->children[i]);
    }

    delete root;
}

// -------------------------Additional functions-----------------------

// 1. Contains x
bool isPresent(TreeNode<int> *root, int x)
{
    if (root == nullptr)
    {
        return false;
    }

    if (root->data == x)
    {
        return true;
    }

    bool found = false;
    for (int i = 0; i < root->children.size(); i++)
    {
        if (isPresent(root->children[i], x))
        {
            found = true;
            break;
        }
    }

    return found;
}

// 2. Count nodes with data > x
int getLargeNodeCount(TreeNode<int> *root, int x)
{
    int ans = 0;

    if (root->data > x)
    {
        ans++;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        ans += getLargeNodeCount(root->children[i], x);
    }

    return ans;
}

// 3. Node with maximum child sum
class Pair
{
public:
    TreeNode<int> *root;
    int sum;

    Pair(TreeNode<int> *tn, int sum)
    {
        root = tn;
        this->sum = sum;
    }
};

Pair maxSumNodeRec(TreeNode<int> *root)
{
    if (root == nullptr)
    {
        Pair p(nullptr, 0);
        return p;
    }

    int curr_sum = root->data;

    for (int i = 0; i < root->children.size(); i++)
    {
        curr_sum += root->children[i]->data;
    }

    Pair maxPair(root, curr_sum);

    for (int i = 0; i < root->children.size(); i++)
    {
        Pair subAns = maxSumNodeRec(root->children[i]);
        if (subAns.sum > curr_sum)
        {
            maxPair.root = subAns.root;
            maxPair.sum = subAns.sum;
        }
    }

    return maxPair;
}

TreeNode<int> *maxSumNode(TreeNode<int> *root)
{
    Pair p = maxSumNodeRec(root);
    return p.root;
}

// 4. Structurally identical
bool areIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
{
    if (!root1 && !root2)
    {
        return true;
    }

    if ((!root1 && root2) || (root1 && !root2))
    {
        return false;
    }

    if ((root1->data != root2->data) || (root1->children.size() != root2->children.size()))
    {
        return false;
    }

    bool ans = true;

    for (int i = 0; i < root1->children.size(); i++)
    {
        ans = ans && areIdentical(root1->children[i], root2->children[i]);
        if (!ans)
        {
            return false;
        }
    }

    return ans;
}

// 5. Next larger than a given value
class Pair2
{
public:
    TreeNode<int> *tn;
    int diff;

    Pair2(TreeNode<int> *n, int d)
    {
        tn = n;
        diff = d;
    }
};

Pair2 doTaskRec(TreeNode<int> *root, Pair2 p, int x)
{
    if (!root)
    {
        return p;
    }

    int difference = (root->data - x);
    if (difference > 0 && difference < p.diff)
    {
        p.tn = root;
        p.diff = difference;
    }

    for (int i = 0; i < root->children.size(); i++)
    {
        Pair2 sub = doTaskRec(root->children[i], p, x);
        if (sub.diff < p.diff)
        {
            p = sub;
        }
    }

    return p;
}

TreeNode<int> *getNextLargerElement(TreeNode<int> *root, int x)
{
    Pair2 p(nullptr, INT_MAX);
    Pair2 ans = doTaskRec(root, p, x);
    return ans.tn;
}

// 6. Second largest element
TreeNode<int> *getLargestNode(TreeNode<int> *root, int x)
{

    TreeNode<int> *ans = root;

    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *subAns = getLargestNode(root->children[i], x);
        if (subAns->data > ans->data && subAns->data != x)
        {
            ans = subAns;
        }
    }

    return ans;
}

TreeNode<int> *getSecondLargestNode(TreeNode<int> *root)
{
    if (!root)
    {
        return root;
    }
    TreeNode<int> *maxNode = getLargestNode(root, INT_MIN);
    TreeNode<int> *secondMaxNode = getLargestNode(root, maxNode->data);

    if (maxNode->data == secondMaxNode->data)
    {
        return nullptr;
    }

    return secondMaxNode;
}

// 7. Replace with depth
void replaceRec(TreeNode<int> *root, int depth)
{
    root->data = depth;

    for (int i = 0; i < root->children.size(); i++)
    {
        replaceRec(root->children[i], depth + 1);
    }

    return;
}

void replaceWithDepthValue(TreeNode<int> *root)
{
    if (!root)
    {
        return;
    }

    replaceRec(root, 0);
}
// -------------------------Additional functions end-----------------------

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