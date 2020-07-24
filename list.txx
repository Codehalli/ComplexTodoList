/*
*  Purpose for program
*  This programming project generates to do list
*
*  Programmer: Pranav Rao
*  Date: Jan 30 2020
*
*  Honor Code: I have neither given nor received any unauthorized assistance with this program.
*/

//Commented all the function in list.txx

//Constructor
template <typename T>
List<T>::List(): ptrHead(nullptr), itemCount(0)
{}

//Destructor
template <typename T>
List<T>::~List()
{
    if (ptrHead != nullptr)
        delete [] ptrHead;
}

/* Copy Constructor(used template from the stack copy constructor)*/
template<typename T>
List<T>::List(const List& x )
{
    itemCount = x.itemCount;
    Node<T>* dummy = x.ptrHead;
    if (dummy == nullptr)
    {
        ptrHead = nullptr;
    }
    
    if(dummy != nullptr) //dummy as in temporary node
    {
        ptrHead = new Node<T>(dummy->getItem());
        dummy = dummy->getNext();
        Node<T>* nodes = ptrHead;
        
        while (dummy != nullptr)
        {
            Node<T>* newNode = new Node<T>(dummy->getItem());
            dummy = dummy->getNext();
            nodes->setNext(newNode);
            nodes = nodes->getNext();
        }
        nodes->setNext(nullptr);
    }
}

/** Copy assignment operator (used template from the stack copy constructor)*/
template<typename T>
List<T>& List<T>::operator=(List<T> x)
{
    //essentially the same as the copy constructor
    itemCount = x.itemCount;
    Node<T>* dummy = x.ptrHead;
    if (dummy == nullptr)
    {
        ptrHead = nullptr;
    }
    if(dummy != nullptr)
    {
        ptrHead = new Node<T>(dummy->getItem());
        dummy = dummy->getNext();
        Node<T>* nodes = ptrHead;
        
        while (dummy != nullptr) //while loop for not eqaul to pointer
        {
            Node<T>* newNode = new Node<T>(dummy->getItem());
            dummy = dummy->getNext();
            nodes->setNext(newNode);
            nodes = nodes->getNext();
        }
        nodes->setNext(nullptr);
    }
}

/**Empty function **/
template <typename T>
bool List<T>::isEmpty()
{
    return (ptrHead == nullptr);
}

/**Get  Lenght function **/
template <typename T>
std::size_t List<T>::getLength()
{
    return itemCount; //gets the amount items
}

/** Insert function **/
template <typename T>
bool List<T>::insert(std::size_t position, const T& newEntry)
{
    bool ableToInsert = (position >= 1) && (position <= itemCount + 1); //given
    
    if (ableToInsert)
    {
        // Create a new node containing the new entry
        Node<T>* newNodePtr = new Node<T>(newEntry);
        
        // Attach new node to chain
        if (position == 1)
        {
            // Insert new node at beginning of chain
            newNodePtr->setNext(ptrHead);
            ptrHead = newNodePtr;
        }
        else
        {
            // Find node that will be before new node
            Node<T>* prevPtr = getNodeAt(position - 1);
            
            newNodePtr->setNext(prevPtr->getNext());
            prevPtr->setNext(newNodePtr);
        }
        
        itemCount++; // Increase count of entries
    }
    
    return ableToInsert;
}

/**Remove method- TA approach **/
template <typename T>
bool List<T>::remove(std::size_t position)
{    
    bool canRemove = (position >= 1) && (position <= itemCount); //condition for canRemove
    
    if(canRemove)
    {
        Node<T>* delPtr = nullptr; //delet node = nullptr
        if(position == 1 && itemCount>1)
        {
            Node<T>* nextPtr = getNodeAt(position+1);
            ptrHead = nextPtr;
        }
        else if (position == 1 && itemCount == 1) {
            ptrHead = nullptr;
        }
        else if (position == itemCount)
        {
            Node<T>* prevPtr = getNodeAt(position - 1);
            prevPtr->setNext(nullptr);
        }
        else
        {
            Node<T>* nextPtr = getNodeAt(position + 1);
            Node<T>* prevPtr = getNodeAt(position - 1);
            
            prevPtr->setNext(nextPtr);
            
        }
        itemCount --;
    }

    return canRemove; //return canRemove
}

/** clear function **/
template <typename T>
void List<T>::clear()
{
    while (!isEmpty()) //checks if its empty
    {
        remove(itemCount); //removes the items
    }
    ptrHead = nullptr;
}


/** get entry **/
template <typename T>
T List<T>::getEntry(std::size_t position) throw(std::range_error)
{
    bool ableToGet = (position >= 1) && (position <= itemCount);
    if (ableToGet)
    {
        Node<T>* nodePtr = getNodeAt(position); //gets the position of the node
        return nodePtr->getItem();
    }
    else
        throw std::range_error("Invalid position!");
}

/** set entry function **/
template <typename T>
void List<T>::setEntry(std::size_t position, const T& newValue) throw(std::range_error)
{
    bool canSet = (position >= 1) && (position <= itemCount);
    
    if (canSet)
    {
        Node<T>* newNodePtr = new Node<T>(newValue);
        
        if (position == 1) //creating a new ptr head node
        {
            newNodePtr->setNext(ptrHead);
            ptrHead = newNodePtr;
        }
        else
        {
            //based on the index of the list
            Node<T>* prevPtr = getNodeAt(position - 1);
            prevPtr -> setNext(newNodePtr);
        }
    }
    else
    {
        //throws an error if the index is wrong location
        throw std::range_error("Invalid position");
    }
    
}

/**get the position of the node **/
template <typename T>
Node<T>* List<T>::getNodeAt(int position)
{
    Node<T>* curPtr = ptrHead;
    
    for (int skip = 1; skip < position; skip++) //provided resources
        curPtr = curPtr->getNext();             //stack overflow
    
    return curPtr;
}

