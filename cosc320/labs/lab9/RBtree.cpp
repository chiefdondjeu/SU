/*
 *Florent Dondjeu Tschoufack
 *Cosc 320 - 002
 *lab 9
 *RBtree.cpp
 *Apr 6, 2020
 */

#include "RBtree.h"

#define RESET "\033[00m"
#define RD "\033[31m"

//nil will be used instead of NULL for efficiency
RBTree::TreeNode* const RBTree::nil = new TreeNode({0,BLACK,nullptr,nullptr, nullptr});

RBTree::RBTree()
{
  root = nil;
}

//private
void RBTree::dec(TreeNode* rt)
{
  if(rt != nil)
  {
    dec(rt->left);
    dec(rt->right);
    delete rt;
  }
}

RBTree::~RBTree()
{
  dec(root);
}

//priavte
void RBTree::left_rotate(TreeNode* x)
{
  TreeNode* y = x->right;
  x->right = y->left;

  if(y->left != nil)
    y->left->parent = x;

  y->parent = x->parent;
  if(x->parent == nil)
    root = y;
  else if(x == x->parent->left)
    x->parent->left = y;
  else x->parent->right = y;

  y->left = x;
  x->parent = y;
}

//private
void RBTree::right_rotate(TreeNode* x)
{
  TreeNode* y = x->left;

  x->left = y->right;
  if(y->right != nil)
    y->right->parent = x;

  y->parent = x->parent;
  if(x->parent == nil)
    root = y;
  else if(x == x->parent->right)
    x->parent->right = y;
  else x->parent->left = y;

  y->right = x;
  x->parent = y;
}

//private
void RBTree::insert_fixup(TreeNode* z)
{
  while(z->parent->color == RED)
{
    if(z->parent == z->parent->parent->left)
    {
      TreeNode* y =  z->parent->parent->right;
      if(y->color == RED)
      {
        z->parent->color = BLACK;
        y->color = BLACK;
        z->parent->parent->color = RED;
        z = z->parent->parent;
      }
      else
      {
        if(z == z->parent->right)
        {
          z = z->parent;
          left_rotate(z);
        }
        z->parent->color = BLACK;
        z->parent->parent->color = RED;
        right_rotate(z->parent->parent);
      }
    }
    else
    {
      TreeNode* y = z->parent->parent->left;
      if(y->color == RED)
      {
        z->parent->color = BLACK;
        y->color = BLACK;
        z->parent->parent->color = RED;
        z = z->parent->parent;
      }
      else
      { 
        if(z == z->parent->left)
        {
          z = z->parent;
          right_rotate(z);
        }
        z->parent->color = BLACK;
        z->parent->parent->color = RED;
        left_rotate(z->parent->parent);
      }
    }
  }
  root->color = BLACK;
}

void RBTree::insert(int k)
{
  TreeNode* z = new TreeNode;
  z->key = k;

  TreeNode* y = nil;
  TreeNode* x = root;
  while(x != nil)
  {
    y = x;
    if(z->key < x->key)
      x = x->left;
    else x = x->right;
  }

  z->parent = y;
  if(y == nil)
    root = z;
  else if(z->key < y->key)
    y->left = z;
  else y->right = z;
   
  z->left = nil;
  z->right = nil;
  z->color = RED;
  insert_fixup(z);
}

//private
RBTree::TreeNode* RBTree::search_(int k)
{
  TreeNode* x = root;
  while(x != nil && k != x->key)
  {
    if(k < x->key)
      x = x->left;
    else x = x->right;
  }
  return x;
}

void RBTree::search(int k)
{
  if(search_(k) == nil)
    std::cout << k << " is not in the tree.\n";
  else std::cout << search_(k)->key << " is in the tree.\n";
}

//used to time search function
void RBTree::search_timing(int k)
{
  if(search_(k) == nil)
    std::cout << "ERROR!!! " << k << " not found.\n";
}

//private
RBTree::TreeNode* RBTree::minimum_(TreeNode* x)
{
  while(x->left != nil)
    x = x->left;
  return x;
}

int RBTree::minimum()
{
  if(minimum_(root) == nil)
    return -1;
  return minimum_(root)->key;
}

//private
RBTree::TreeNode* RBTree::maximum_(TreeNode* x)
{
  while(x->right != nil)
    x = x->right;
  return x;
}

int RBTree::maximum()
{
  if(maximum_(root) == nil)
    return -1;
  return maximum_(root)->key;
}

//private
RBTree::TreeNode* RBTree::successor_(TreeNode* x)
{
  if(x->right != nil)
    return minimum_(x->right);

  TreeNode* y = x->parent;
  while(y != nil && x == y->right)
  {
    x = y;
    y = y->parent;
  }
  return y;
}

int RBTree::successor(int k)
{
  TreeNode* y = search_(k);
  if(y == nil)
    return -1;
  if(successor_(y) == nil)
    return -2;
  return successor_(y)->key;
}

//private
void RBTree::transplant(TreeNode* u, TreeNode* v)
{
  if(u->parent == nil)
    root = v;
  else if(u == u->parent->left)
    u->parent->left = v;
  else u->parent->right = v;

  v->parent = u->parent;
}

//private
void RBTree::Delete_fixup(TreeNode* x)
{
  while(x != root && x->color == BLACK)
  {
    if(x == x->parent->left)
    {
      TreeNode* w = x->parent->right;
      if(w->color == RED)
      {
        w->color = BLACK;
        x->parent->color = RED;
        left_rotate(x->parent);
        w = x->parent->right;
      }
      if(w->left->color == BLACK && w->right->color == BLACK)
      {
        w->color = RED;
        x = x->parent;
      }
      else
      {
        if(w->right->color == BLACK)
        {
          w->left->color = BLACK;
          w->color = RED;
          right_rotate(w);
          w = x->parent->right;
        }
        w->color = x->parent->color;
        x->parent->color = BLACK;
        w->right->color = BLACK;
        left_rotate(x->parent);
        x = root;
      }
    }
    else
    {
      TreeNode* w = x->parent->left;
      if(w->color == RED)
      {
        w->color = BLACK;
        x->parent->color = RED;
        right_rotate(x->parent);
        w = x->parent->left;
      }
      if(w->right->color == BLACK && w->left->color == BLACK)
      {
        w->color = RED;
        x = x->parent;
      }
      else
      {
        if(w->left->color == BLACK)
        {
          w->right->color = BLACK;
          w->color = RED;
          left_rotate(w);
          w = x->parent->left;
        }
        w->color = x->parent->color;
        x->parent->color = BLACK;
        w->left->color = BLACK;
        right_rotate(x->parent);
        x = root;
      }
    }
  }
  x->color = BLACK;
}

void RBTree::Delete(int k)
{
  TreeNode* z = search_(k);
  if(z == nil)
  {
    std::cout << k << " is not in tree.\n";
    return;
  }

  TreeNode* y = z;
  color_t yOrig = y->color;
  TreeNode* x;
  if(z->left == nil)
  {
    x = z->right;
    transplant(z,z->right);
  }
  else if(z->right == nil)
  {
    x = z->left;
    transplant(z,z->left);
  }
  else
  {
    y = minimum_(z->right);
    yOrig = y->color;
    x = y->right;
    if(y->parent == z)
      x->parent = y;
    else
    {
      transplant(y,y->right);
      y->right = z->right;
      y->right->parent = y;
    }
    transplant(z,y);
    y->left = z->left;
    y->left->parent = y;
    y->color = z->color;
  }

  delete z;
  if(yOrig == BLACK)
    Delete_fixup(x);

}

//private
void RBTree::inorder_(TreeNode* rt)
{
  if(rt != nil)
  {
    inorder_(rt->left);
    if(rt->color == RED)
      std::cout << RD << rt->key << RESET << " ";
    else std::cout << rt->key << " ";
    inorder_(rt->right);
  }
}

void RBTree::inorder()
{
  std::cout << "Root " << root->key <<"\t[ ";
  inorder_(root);
  std::cout << "]" <<  std::endl;
}

//private
void RBTree::print_(TreeNode* rt)
{
  if(rt != nil)
  {
    print_(rt->right);
    if(rt->color == RED)
      std::cout << RD << rt->key << RESET << " ";
    else std::cout << rt->key << " ";
    print_(rt->left);
  }
}

void RBTree::print()
{
  std::cout << "Descending [ ";
  print_(root);
  std::cout << "]"  << std::endl;
}
