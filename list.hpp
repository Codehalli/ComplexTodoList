/*
 *  Purpose for program
 *  This programming project generates to do list
 *
 *  Programmer: Pranav Rao
 *  Date: Jan 30 2020
 *
 *  Honor Code: I have neither given nor received any unauthorized assistance with this program.
 */
#ifndef _LIST_H_ //include the defines
#define _LIST_H_

#include <stdexcept> //include libraries
#include "abstract_list.hpp"
#include "node.hpp"

template <typename T>
class List: public AbstractList<T>
{
public:

  // This function is the Constructor
  List();

  // This function is the Destructor
  ~List();
  
  //This function is the  Copy constructor
  List(const List & x);

  //This is the Copy assignment
  List& operator=(List x);

  //This function test if the list is empty
   bool isEmpty();

  //Number of items in the list
   std::size_t getLength();

   // insert at position in list
   bool insert(std::size_t position, const T& newEntry);

  // remove item at position
   bool remove(std::size_t position);

  // clear the list (remove all entries)
   void clear();
  
  // get value of item at position
   T getEntry(std::size_t position) throw(std::range_error);

  // set value at position
   void setEntry(std::size_t position, const T& newValue) throw(std::range_error);

private:
  Node<T> * ptrHead;
  int itemCount;

  Node<T>* getNodeAt(int position);
};
#include "list.txx"

#endif // _LIST_H_
