#include "stdafx.h"
#include<iostream>
#include<vector>
#include<stack>
#include<map>
#include<deque>
#include<queue>

using namespace std;

class BinaryTree
{
public:
    int data;
    BinaryTree* left;
    BinaryTree* right;
};

class BinaryTreeUtlis
{
private:
    int Max(int a, int b)
    {
        if (a > b)
        {
            return a;
        }

        return b;
    }

    int GetDiameter(BinaryTree* root, int* diameter, int* height)
    {
        if (root == NULL)
        {
            *diameter = 0;
            *height = 0;
            return 0;
        }

        int dLeft = 0;
        int dRight = 0;
        int hLeft = 0;
        int hRight = 0;

        dLeft = GetDiameter(root->left, &dLeft, &hLeft);
        dRight = GetDiameter(root->right, &dRight, &hRight);
        *height = Max(hLeft, hRight) + 1;
        *diameter = Max(Max(dLeft, dRight), hLeft + hRight + 1);

        return *diameter;
    }

    BinaryTree* GetLCA(BinaryTree* root, int key1, int key2)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if (root->data == key1 || root->data == key2)
        {
            return root;
        }

        BinaryTree* leftLCA = GetLCA(root->left, key1, key2);
        BinaryTree* rightLCA = GetLCA(root->right, key1, key2);

        if (leftLCA != NULL && rightLCA != NULL)
        {
            return root;
        }

        if (leftLCA != NULL)
        {
            return leftLCA;
        }

        return rightLCA;
    }

    void PreOrder_Iterative(BinaryTree* root)
    {
        if (root == NULL)
        {
            return;
        }

        stack<BinaryTree*> S;
        S.push(root);

        while (!S.empty())
        {
            BinaryTree* current = S.top();
            S.pop();

            cout << current->data << " ";

            if (current->right != NULL)
            {
                S.push(current->right);
            }

            if (current->left != NULL)
            {
                S.push(current->left);
            }
        }
    }

    void PreOrder(BinaryTree* root)
    {
        if (root == NULL)
        {
            return;
        }

        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }

    void InOrder_Iterative(BinaryTree* root)
    {
        if (root == NULL)
        {
            return;
        }

        BinaryTree* current = root;
        stack<BinaryTree*> S;

        while (true)
        {
            while (current != NULL)
            {
                S.push(current);
                current = current->left;
            }

            if (!S.empty())
            {
                current = S.top();
                S.pop();
                cout << current->data << " ";
                current = current->right;
            }
            else
            {
                break;
            }
        }
    }

    void InOrder(BinaryTree* root)
    {
        if (root == NULL)
        {
            return;
        }

        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
    }

    void PostOrder_Iterative(BinaryTree* root)
    {
        if (root == NULL)
        {
            return;
        }

        stack<BinaryTree*> preOrderStack;
        stack<BinaryTree*> postOrderStack;
        preOrderStack.push(root);

        while (!preOrderStack.empty())
        {
            BinaryTree* current = preOrderStack.top();
            preOrderStack.pop();

            postOrderStack.push(current);

            if (current->left != NULL)
            {
                preOrderStack.push(current->left);
            }

            if (current->right != NULL)
            {
                preOrderStack.push(current->right);
            }
        }

        while (!postOrderStack.empty())
        {
            BinaryTree* current = postOrderStack.top();
            cout << current->data << " ";
            postOrderStack.pop();
        }
    }

    void PostOrder(BinaryTree* root)
    {
        if (root == NULL)
        {
            return;
        }

        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->data << " ";
    }

    bool isBST_Internal(BinaryTree* node, int& inorderPredecessor)
    {
        if (node == NULL)
        {
            return true;
        }

        bool isBST = isBST_Internal(node->left, inorderPredecessor);

        // left tree is not BST. return false.
        if (!isBST)
        {
            return isBST;
        }

        // If inorder predecessor >= current node data, return false
        if (inorderPredecessor >= node->data)
        {
            return false;
        }

        // For right sub tree, inorder predecessor will be the current node.
        inorderPredecessor = node->data;

        return isBST_Internal(node->right, inorderPredecessor);
    }

public:
    int Height(BinaryTree* root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int leftSubTreeHeight = Height(root->left);
        int rightSubTreeHeight = Height(root->right);
        return Max(leftSubTreeHeight, rightSubTreeHeight) + 1;
    }

    int Diameter(BinaryTree* root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int height = 0;
        int diameter = 0;
        return GetDiameter(root, &diameter, &height);
    }

    BinaryTree* LCA(BinaryTree* root, int key1, int key2)
    {
        /*
        if (root == NULL)
        {
            return NULL;
        }

        BinaryTree* key1Node = NULL;
        BinaryTree* key2Node = NULL;
        BinaryTree* lca = GetLCA(root, key1, key2);
        cout << "LCA of " << key1 << " and " << key2 << " is " << ((lca != NULL) ? (lca->data) : -1) << endl;
        return lca;
        //*/

        BinaryTree* lca = LCA_BST(root, key1, key2);
        cout << "LCA of " << key1 << " and " << key2 << " is " << ((lca != NULL) ? (lca->data) : -1) << endl;
        return lca;
    }

    BinaryTree* LCA_BST(BinaryTree* root, int key1, int key2)
    {
        if (root == NULL)
        {
            return NULL;
        }

        if ((key1 <= root->data && key2 >= root->data) || (key1 >= root->data && key2 <= root->data))
        {
            return root;
        }

        if (key1 < root->data && key2 < root->data)
        {
            return LCA_BST(root->left, key1, key2);
        }

        if (key1 > root->data && key2 > root->data)
        {
            return LCA_BST(root->right, key1, key2);
        }

        return NULL;
    }

    bool isBST(BinaryTree* root)
    {
        if (root == NULL)
        {
            return true;
        }

        BinaryTree* leftMost = root;
        while (leftMost->left != NULL)
        {
            leftMost = leftMost->left;
        }

        int inorderPredecessor = leftMost->data - 1;

        return isBST_Internal(root, inorderPredecessor);
    }

    void PrintPreOrder(BinaryTree* root)
    {
        cout << endl << "PreOrder recursive" << endl;
        PreOrder(root);
        cout << endl << "PreOrder iterative" << endl;
        PreOrder_Iterative(root);
    }

    void PrintInOrder(BinaryTree* root)
    {
        cout << endl << "InOrder recursive" << endl;
        InOrder(root);
        cout << endl << "InOrder iterative" << endl;
        InOrder_Iterative(root);
    }

    void PrintPostOrder(BinaryTree* root)
    {
        cout << endl << "PostOrder recursive" << endl;
        PostOrder(root);
        cout << endl << "PostOrder iterative" << endl;
        PostOrder_Iterative(root);
        cout << endl;
    }
};
