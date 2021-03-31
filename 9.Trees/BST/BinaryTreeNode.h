template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }

    ~BinaryTreeNode() {
        // NOTE: If left and/or right is nullptr, "delete nullptr" is ignored, it doesn't cause any errors 
        delete left;
        delete right;
    }
};