/*
 *Florent Dondjeu Tschoufack
 *Cosc 320 - 002
 *Lab 9
 *RBtree.h
 *Apr 6, 2020
 */

#ifndef RED_BLACK_TREE_H
#define RED_BLACK_TREE_H

#include <iostream>

enum color_t {RED, BLACK};

class RBTree
{
  private:
    struct TreeNode
    {
      int key;
      color_t color;
      TreeNode* left;
      TreeNode* right;
      TreeNode* parent;
    };

    TreeNode* root;

    void dec(TreeNode*);

    void left_rotate(TreeNode*);

    void right_rotate(TreeNode*);

    void insert_fixup(TreeNode*);

    TreeNode* search_(int);

    TreeNode* minimum_(TreeNode*);

    TreeNode* maximum_(TreeNode*);

    TreeNode* successor_(TreeNode*);

    void transplant(TreeNode*, TreeNode*);

    void Delete_fixup(TreeNode*);

    void inorder_(TreeNode*);

    void print_(TreeNode*);

  public:
    //make public so I can delete in main and program does no leak
    static TreeNode* const nil;

    RBTree();

    ~RBTree();

    void insert(int);

    void search(int);

    void search_timing(int);

    int minimum();

    int maximum();

    int successor(int);

    void Delete(int);

    void inorder();

    //prints in descending order
    void print();
};


#endif
