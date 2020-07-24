/*
 *  Purpose for program
 *  This programming project generates to do list
 *
 *  Programmer: Pranav Rao
 *  Date: Jan 30 2020
 *
 *  Honor Code: I have neither given nor received any unauthorized assistance with this program.
 */


//Provided Data structure code resources
#ifndef _SORTED_LIST_H_ //defines
#define _SORTED_LIST_H_

#include <cmath> //includes
#include <stdexcept>
#include "abstract_sorted_list.hpp"
#include "list.hpp"
using namespace std; //namespace

template <typename T> //sorted class
class SortedList: public AbstractSortedList<T>, private List<T>
{
public:

  // constructor
  SortedList();

  // destructor
  ~SortedList();

  // determine if a list is empty
  bool isEmpty();

  // return current length
  std::size_t getLength();

  // insert item at ordered position
  void insertSorted(const T& item);

  // remove first occurance of item
  bool removeSorted(const T& item);

  // remove item at position
  bool remove(std::size_t position);

  // remove items
  void clear();

  // get a copy of the item at position
  T getEntry(std::size_t position) throw(std::range_error);

  // get the position of the first occurance of item or negated position
  // where it would be inserted.
  int getPosition(const T& newValue);

private:
  List<T> * ptrList;
};

#include "sorted_list.txx" //includes

#endif // _SORTED_LIST_H_
