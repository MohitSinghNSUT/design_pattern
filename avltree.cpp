
#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;
    int height;

    Node(int k)
    {
        key = k;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

class Avltree
{
public:
    Node *root;
    Avltree()
    {
        root = nullptr;
    }
    Node *leftRotate(Node *node)
    {
        //   a
        //     b
        //   c   d
        Node *newroot = node->right;
        Node *temp = newroot->left;
        newroot->left = node;
        node->right=temp;
    }
    Node *rightRotate(Node *node)
    {
        //      a
        //    b
        // c    d
        Node *newroot = node->left;
        Node *temp = newroot->right;
        newroot->right = node;
        node->left=temp;
    }
    int getHeight(Node *node)
    {
        if (node == nullptr)
            return 0;
        return node->height;
    }
    Node *insert(Node *node, int key)
    {
        if (node == nullptr)
        {
            return new Node(key);
        }
        if (key > node->key)
        {
            node->right = insert(node->right, key);
        }
        else
        {
            node->left = insert(node->left, key);
        }
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        int balance = getHeight(node->left) - getHeight(node->right);

        // left left
        //      A balance = 2  we need to rotate so we require right rotation also key<node->left->key ** make sure this is left-left case
        //     /
        //    B
        //   /
        //  C
        if (balance > 1 and node->left->key > key)
        {
            return rightRotate(node);
        }
        // right right
        //      A balance = -2  we need to rotate so we require left rotation also key>node->right->key ** make sure this is right-right case
        //        '\'
        //          B
        //          '\'
        //            C
        if (balance < -1 and node->right->key < key)
        {
            return leftRotate(node);
        }

        // left right
        //      A balance = 2  we need to rotate so we require right rotation also key<node->left->key ** make sure this is left-left case
        //       '\'
        //         B
        //        /
        //       C
        if (balance > 1 and node->left->key < key)
        {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        //  left right
        //      A balance = 2  we need to rotate so we require right rotation also key<node->left->key ** make sure this is left-left case
        //     /
        //    B                 change B  -> then to left rotate A like the left-left case
        //    '\'                     /
        //      C                    C
        if (balance < -1 and node->right->key > key)
        {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    }
};


