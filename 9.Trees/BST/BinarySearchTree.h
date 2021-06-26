#include <iostream>
#include "BinaryTreeNode.h"
using namespace std;

class BST {
    // Define the data members
    BinaryTreeNode<int> *root;
    
    void print(BinaryTreeNode<int> *node) {
        if (node == nullptr) {
            return;
        }
        
        cout << node->data << ":";
        
        if (node->left != nullptr) {
            cout << "L:" << node->left->data << ",";
        }
                
        if (node->right != nullptr) {
            cout << "R:" << node->right->data;
        }
        
        cout << endl;
        
        print(node->left);
        print(node->right);
    }

    // Complexity: O(h), because one comparison done per level
    bool search(BinaryTreeNode<int> *node, int data) {
        if (node == nullptr) {
            return false;
        }
        
        if (data == node->data) {
            return true;
        }
        
        else if (data < node->data) {
            return search(node->left, data);
        }
        
        return search(node->right, data);
    }
    
    // Complexity: O(h), because one comparison done per level
    BinaryTreeNode<int> *insert(BinaryTreeNode<int> *node, int data) {
        if (node == nullptr) {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        
        if (data <= node->data) {
            node->left = insert(node->left, data);
            return node;
        }
        
        node->right = insert(node->right, data);
        return node;
    }
    
    BinaryTreeNode<int> *minimum(BinaryTreeNode<int> *node) {
        if (node == nullptr) {
            return nullptr;
        }
        
        BinaryTreeNode<int> *smallerOutput = minimum(node->left);
        
        if (smallerOutput == nullptr) {
            return node;
        }
        
        return smallerOutput;
    }
    
    BinaryTreeNode<int> *remove(BinaryTreeNode<int> *node, int data) {
        if (node == nullptr) {
            return nullptr;
        }
        
        if (data < node->data) {
            node->left = remove(node->left, data);
            return node;
        }
        
        else if (data > node->data) {
            node->right = remove(node->right, data);
            return node;
        }
        
        else if (data == node->data) {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            
            else if (node->left == nullptr) {
                BinaryTreeNode<int> *rightChild = node->right;
                node->right = nullptr;
                // Will not delete the whole right subtree because we break that connection in the statement above
                delete node;
                return rightChild;
            }
            
            else if (node->right == nullptr) {
                BinaryTreeNode<int> *leftChild = node->left;
                node->left = nullptr;
                // Will not delete the whole left subtree because we break that connection in the statement above
                delete node;
                return leftChild;
            }
            
            BinaryTreeNode<int> *rightMin = minimum(node->right);
            node->data = rightMin->data;
            node->right = remove(node->right, rightMin->data);
            return node;
        }

        return nullptr;
    }
    
   public:

	/*----------------- Public Functions of BST -----------------*/

    BST() { 
        root = nullptr;
    }
    
    void remove(int data) { 
        root = remove(root, data);
        return;
    }

    void print() { 
        print(root);
        return;
    }

    void insert(int data) { 
        this->root = insert(this->root, data);
        return;
    }

    bool search(int data) {
		return search(root, data); 
    }

    ~BST() {
        delete root;
    }
};