#include <vector>
using namespace std;

// Trees can always be visualized as a root node having children which are also trees.
// Thus, almost all problems related to trees can be solved using recursion
template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children; // <T> can be omitted here because the parent node has type T, which will be assumed, by default

    TreeNode(T data)
    {
        this->data = data;
    }

    ~TreeNode()
    {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};