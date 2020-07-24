/*
*  Purpose for program
*  This programming project generates to do list
*
*  Programmer: Pranav Rao
*  Date: Jan 30 2020
*
*  Honor Code: I have neither given nor received any unauthorized assistance with this program.
*/

//Provide data structure code

template<typename ItemType>
Node<ItemType>::Node() : next(nullptr)  // end default constructor
{}

template<typename ItemType>
Node<ItemType>::Node(const ItemType& anItem) : item(anItem), next(nullptr) // end of constructor
{}

template<typename ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* nextNodePtr) : item(anItem), next(nextNodePtr) // end of 2nd constructor
{}

template<typename ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)// end setItem
{
  item = anItem;
}

template<typename ItemType>
void Node<ItemType>::setNext(Node<ItemType>* nextNodePtr)
{
  next = nextNodePtr;
} // end setNext

template<typename ItemType>
ItemType Node<ItemType>::getItem() const
{
  return item;
} // end getItem

template<typename ItemType>
Node<ItemType>* Node<ItemType>::getNext() const
{
  return next;
} // end getNext
