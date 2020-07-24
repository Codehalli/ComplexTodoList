/*
 *  Purpose for program
 *  This programming project generates to do list
 *
 *  Programmer: Pranav Rao
 *  Date: Jan 30 2020
 *
 *  Honor Code: I have neither given nor received any unauthorized assistance with this program.
 */

//Provided data strcuture code
#ifndef _ABSTRACT_SORTED_LIST_H_
#define _ABSTRACT_SORTED_LIST_H_

template <typename T>
class AbstractSortedList
{
  //checking if the list is empty
  virtual bool isEmpty() = 0;

  //returns current length
  virtual std::size_t getLength() = 0;

  // insterted an (ordered) item
  virtual void insertSorted(const T& item) = 0;

  // remove sorted item
  virtual bool removeSorted(const T& item) = 0;

  // remove item at position
  virtual bool remove(std::size_t position) = 0;

  // remove all items from the list
  virtual void clear() = 0;

  // function to the get the entery
  virtual T getEntry(std::size_t position) = 0;

  //function to get the positon
  virtual int getPosition(const T& newValue) = 0;

};

#endif // _ABSTRACT_SORTED_LIST_H_
