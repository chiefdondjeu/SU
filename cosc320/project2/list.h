/*
 *Florent Dondjeu Tschoufack
 *Cosc 320 - 002
 *Project 2
 *list.h
 *Mar 30, 2020
 */

#ifndef LIST_H
#define LIST_H

#include <iostream>

template <class T>
struct Node
{
  T data;
  Node<T>* next;
  Node<T>* prev;
};

template <class T>
class List
{
  private:

    int size;
    Node<T>* head;
    Node<T>* tail;

    //search for a specific item in the list
    Node<T>* search_(const T& v)
    {
      Node<T>* currNode = head->next;

      if(!head)
        return NULL;

      if(head->data == v)
        return head;

      while(currNode)
      {
        if(currNode->data == v)
          return currNode;
        currNode = currNode->next;
      }

      return NULL;
    }
  
  public:

    const Node<T>* iter;  //will act as our iter

    //constructor
    List()
    {
      size = 0;
      head = NULL;
      tail = NULL;
    }

    //deconstructor
    ~List()
    {
      Node<T>* curr = head;
      Node<T>* del;
      while(curr)
      {
        del = curr;
        curr = curr->next;
        delete del;   
      }
    }

    //add an item in the list
    void insert(const T& v)
    {
      Node<T>* newNode = new Node<T>();
      newNode->data = v;
      newNode->next = NULL;
      newNode->prev = NULL;

      //when no nodes
      if(!head)
      {
        head = newNode;
        tail = newNode;
        iter = head;    //
      }
      else
      {
        Node<T>* prevNode = tail;
        newNode->prev = prevNode;
        prevNode->next = newNode;
        tail = newNode;
      }
      size++;
    }

    //deletes an item from the list
    void remove(const T& v)
    {
      Node<T>* del = search_(v);
      Node<T>* succNode;
      Node<T>* prevNode;

      if(del)
      {
        //when one node
        if(del == head && del == tail)
        {
          delete del;
          head = tail = NULL;
          size--;
          iter = NULL;    //
          return;
        }

        //when its head
        if(del == head)
        {
          succNode = head->next;
          succNode->prev = NULL;
          head->next = NULL;
          head = succNode;
          iter = head;    //
        }

        //when its tail
        else if(del == tail)
        {
          prevNode = tail->prev;
          prevNode->next = NULL;
          tail->next = NULL;
          tail = prevNode;
        }

        //in the middle
        else 
        {
          succNode = del->next;
          prevNode = del->prev;
          succNode->prev = del->prev;
          prevNode->next = del->next;
          del->next = NULL;
          del->prev = NULL;
        }

        size--;
        delete del;
      }

    }

    //determine if element is in list
    bool find(const T& v)
    {
      if(search_(v))
        return true;
      else return false;
    }

    //reset iter position
    void reset_iter()
    {
      if(getsize() != 0)
        iter = head;
      else iter = NULL;
    }

    //prints content of the list
    void print()
    {
      Node<T>* cursor = head;
      while(cursor)
      {
        std::cout << cursor->data << " "; 
        cursor = cursor->next;
      }
      std::cout << std::endl;
    }

    //returns numner of element in list
    int getsize() const
    {
      return size;
    }

};

#endif
