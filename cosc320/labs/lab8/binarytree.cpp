/*
 *Florent Dondjeu Tschoufack
 *COSC 320-002
 *lab8
 *binarytree.cpp
 *Mar 28, 2020
 */

#include "binarytree.h"

#include <iostream>

//default constructor
BinaryTree::BinaryTree()
{
  root = NULL;
}

//constructor
BinaryTree::BinaryTree(int x)
{
  root = new TreeNode();
  root->key = x;
  root->left = NULL;
  root->right = NULL;
  root->parent = NULL;
}

//private
void BinaryTree::dec(TreeNode* rt)
{
  if(rt) //not equal to NULL
  {
    dec(rt->left);
    dec(rt->right);
    delete rt;
  }
}

//deconstructor
BinaryTree::~BinaryTree()
{
  dec(root);
}

void BinaryTree::insert(int v)
{
  TreeNode* z = new TreeNode();
  z->key = v;
  z->left = NULL;
  z->right = NULL;
  
  TreeNode* y = NULL;
  TreeNode* x = root;
  while(x)
  {
    y = x;
    if(z->key < x->key)
      x = x->left;
    else x = x->right;
  }
  z->parent = y;
  if(!y)
    root = z;
  else if(z->key < y->key)
    y->left = z;
  else y->right = z; 
}

//private
BinaryTree::TreeNode* BinaryTree::search_(int x)
{
  TreeNode* currNode = root;
  while(currNode)
  {
    if(x > currNode->key)
      currNode=currNode->right;
    else if(x < currNode->key)
      currNode=currNode->left;
    else break;
  }

  return currNode;
}

void BinaryTree::search(int x)
{
  if(!search_(x))
    std::cout << x << " is not in the Tree.\n";
  else std::cout << (search_(x))->key << " is in the tree.\n";
}

//used for data
void BinaryTree::search_timing(int x)
{
  if(!search_(x))
    std::cout << "Error!!";
}

//private
BinaryTree::TreeNode* BinaryTree::minimum_(TreeNode* rt)
{
  TreeNode* currNode = rt;
  if(!currNode)
    return NULL;
  
  while(currNode->left)
    currNode = currNode->left;

  return currNode;
}

int BinaryTree::minimum()
{
  if(!minimum_(root))
    return -1;

  return (minimum_(root))->key; 
}

//private
BinaryTree::TreeNode* BinaryTree::maximum_(TreeNode* rt)
{
  TreeNode* currNode = rt;
  if(!currNode)
    return NULL;

  while(currNode->right)
    currNode = currNode->right;

  return currNode;
}

int BinaryTree::maximum()
{
  if(!maximum_(root))
    return -1;

  return (maximum_(root))->key;
}

//private
BinaryTree::TreeNode* BinaryTree::successor_(TreeNode* x)
{
  if(x->right)
    return minimum_(x->right);

  TreeNode* y = x->parent;
  while(y && x == y->right)
  {
    x = y;
    y = y->parent;
  }

  return y;
}

int BinaryTree::successor(int k)
{
  TreeNode* u = search_(k);

  //if not in tree
  if(!search_(k))
    return -1;  //-1 for error print used in main
  
  //if no successor
  if(!successor_(u))
    return -2;
  
  return (successor_(u))->key;
}

//private
void BinaryTree::transplant(TreeNode* u, TreeNode* v)
{
  if(!u->parent)
    root = v;
  else if (u == u->parent->left)
    u->parent->left = v;
  else u->parent->right = v;

  if(v)
    v->parent = u->parent;
}

void BinaryTree::Delete(int i)
{
  TreeNode* z = search_(i);
  if(!z)
  { 
    std::cout << i << " is not in tree.\n";
    return;
  }

  if(!z->left)
  {
    transplant(z,z->right);
    delete z;
  }

  else if(!z->right)
  {
    transplant(z,z->left);
    delete z;
  }

  else
  {
    TreeNode* y =  minimum_(z->right);
    if(y->parent)
    {
      transplant(y,y->right);
      y->right = z->right;
      y->right->parent = y;
    }
    transplant(z,y);
    y->left = z->left;
    y->left->parent = y;
    delete z;
  }
}

//private
void BinaryTree::inorder_(TreeNode* rt)
{
  if(rt) //if not equal to NULL
  {
    inorder_(rt->left);
    std::cout << rt->key << " ";
    inorder_(rt->right);
  }

}

void BinaryTree::inorder()
{
  inorder_(root);
  std::cout << std::endl;
}

//private
void BinaryTree::print_(TreeNode* rt)
{
 if(rt)
 {
   print_(rt->right);
   std::cout << rt->key << " ";
   print_(rt->left);
 }
}

void BinaryTree::print()
{
  print_(root);
  std::cout << std::endl;
}
