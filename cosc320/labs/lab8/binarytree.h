/*
 *Florent Dondjeu Tschoufack
 *COSC 320-002
 *lab8
 *binarytree.h
 *Mar 28, 2020
 */

#ifndef BTREE_H
#define BTREE_H

class BinaryTree
{
  private:
    struct TreeNode
    {
      int key;
      TreeNode* left;
      TreeNode* right;
      TreeNode* parent;
    };

    TreeNode* root;

    //for deconstructor
    //deletes every nodes in the tree
    void dec(TreeNode*);

    //private function for search
    //return value is a node
    TreeNode* search_(int);

    //private function for minimun
    //return value is a node
    TreeNode* minimum_(TreeNode*);

    //private function for maximum
    //return value is a node
    TreeNode* maximum_(TreeNode*);

    //private function for successor
    //return value is a node
    TreeNode* successor_(TreeNode*);

    //uses for changing nodes position during deletion
    //so that the binary tree rules are still in effect
    void transplant(TreeNode*,TreeNode*);

    //private function for inorder
    //prints binary tree in inorder
    void inorder_(TreeNode*);

    //private function for print
    //prints binary tree in preorder
    void print_(TreeNode*);

  public:

    //default constructor
    BinaryTree();

    //constructor
    BinaryTree(int);
   
    //deconstructor
    ~BinaryTree();
   
    //adds a new key to the tree
    void insert(int);

    //searchss for a specific node is the tree
    void search(int);

    //seearch function used for data collection
    //output "Erro!" if node is not find
    void search_timing(int);

    //returns the smallest key in the tree
    int minimum();

    //returns the largest key in the tree
    int maximum();

    //returns the samllest key in the tree larger than k
    int successor(int);

    //deletes a given key in the tree, if it exits
    void Delete(int);
    
    //prints tree in ascending order
    void inorder();

    //prints the tree in descending order
    void print();
};

#endif
