/*
*  Purpose for program
*  This programming project generates to do list
*
*  Programmer: Pranav Rao
*  Date: Jan 30 2020
*
*  Honor Code: I have neither given nor received any unauthorized assistance with this program.
*/
//Data structure code provided
//Functions commented

/** Constructor **/
template <typename T>
SortedList<T>::SortedList()
{
    ptrList = new List<T>;
}

/** destructor **/
template <typename T>
SortedList<T>::~SortedList()
{
    clear(); //clears for the destructor
}

/** empty method **/
template <typename T>
bool SortedList<T>::isEmpty()
{
    return ptrList->isEmpty();
}

/** length method **/
template <typename T>
std::size_t SortedList<T>::getLength()
{
    return ptrList->getLength();
}

/** insert method **/
template <typename T>
void SortedList<T>::insertSorted(const T& item)
{
    //int position = fabs(getPosition(item));
    int position = std::abs(getPosition(item));
    //std::cout << "Item = " << item << " Position = " << position << std::endl;
    ptrList->insert(position,item);
}

/** remove method **/
template <typename T>
bool SortedList<T>::removeSorted(const T& item)
{
    int position = getPosition(item);
    
    if(position > 0)
        return ptrList->remove(position);
    
    return false;
}

/** remove postition **/
template <typename T>
bool SortedList<T>::remove(std::size_t position)
{
    return ptrList->remove(position); //removes the index
}

/**clear method **/
template <typename T>
void SortedList<T>::clear()
{
    ptrList->clear(); //self implementation used for clear
}

/** get entry  **/
template <typename T>
T SortedList<T>::getEntry(std::size_t position) throw(std::range_error)
{
    return ptrList->getEntry(position);
}

/** get position **/
template <typename T>
int SortedList<T>::getPosition(const T& newValue)
{
    //This was the missing function for extension
    int position = -(ptrList->getLength() + 1); //entry goes at the end of list by default for    ascending order
    
    T currentEntry;
    
    for(int i = 1; i <= ptrList->getLength(); i++)
    {
        currentEntry = ptrList->getEntry(i);
        
        //item is in list
        if(currentEntry == newValue)
        {
            position = i;
            break;
        }
        if(currentEntry > newValue)
        {
            position = -i;
            break;
        }
    }
    return position; //return the positon
}


