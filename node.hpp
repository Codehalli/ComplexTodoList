/*
 *  Purpose for program
 *  This programming project generates to do list
 *
 *  Programmer: Pranav Rao
 *  Date: Jan 30 2020
 *
 *  Honor Code: I have neither given nor received any unauthorized assistance with this program.
 */

#ifndef _NODE //defines
#define _NODE

template<typename ItemType>
class Node //node class
{
 private:
  ItemType item; // data items
  Node<ItemType>* next; // This is pointer to the next node
 public:
  Node(); //node functions
  Node(const ItemType& anItem); //to see what data type of item
  Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
  void setItem(const ItemType& anItem); //get current item
  void setNext(Node<ItemType>* nextNodePtr); //set next item
  ItemType getItem() const ; //get Item
  Node<ItemType>* getNext() const ; //get next
}; // end Node header functions 

#include "node.txx" //includes
#endif
