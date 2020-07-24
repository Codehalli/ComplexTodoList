/*
 *  Purpose for program
 *  This programming project generates to do list
 *
 *  Programmer: Pranav Rao
 *  Date: Jan 30 2020
 *
 *  Honor Code: I have neither given nor received any unauthorized assistance with this program.
 */

//Provided data structure code
#ifndef _ABSTRACT_LIST_H_ //defines
#define _ABSTRACT_LIST_H_

template <typename T>
class AbstractList //abstract class
{
public:
  //to check if it is empty
  virtual bool isEmpty() = 0;

  //to get the lenght of the list
  virtual std::size_t getLength() = 0;

  //inserting an list
  virtual bool insert(std::size_t position, const T& item) = 0;

  // remove item from list
  virtual bool remove(std::size_t position) = 0;

  //clear funtction
  virtual void clear() = 0;

  // item position
  virtual T getEntry(std::size_t position) = 0;

  // set the value of the item at position using 0-based indexing
  virtual void setEntry(std::size_t position, const T& newValue) = 0;
};

#endif
