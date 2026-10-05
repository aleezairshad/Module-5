#include "ListContainer.h"

// Constructor
//precondition: none
//postcondition: Creates an empty list of Record objects.
ListContainer::ListContainer()
{
}

// A. clear()
//precondition: none
//postcondition: All elements are destroyed and the list is empty.
void ListContainer::clear()
{
    data.clear();
}

// B. resize(n)
//precondition: n is a non-negative integer
//postcondition: The list contains n elements. Extra default Records are added or extra elements are removed.
void ListContainer::resize(int n)
{
    data.resize(n);
}

// C. push_front(e)
//precondition: entry is a valid Record
//postcondition: entry is added at the front of the list.
void ListContainer::pushFront(const Record& entry)
{
    data.push_front(entry);
}

// D. pop_front()
//precondition: none
//postcondition: The first element is removed if the list is not empty.
void ListContainer::popFront()
{
    if (!data.empty())
    {
        data.pop_front();
    }
}

// E. front()
//precondition: none
//postcondition: Returns the first element, or a default Record if the list is empty.
Record ListContainer::front() const
{
    if (!data.empty())
    {
        return data.front();
    }

    return Record();
}

// F. push_back(e)
//precondition: entry is a valid Record
//postcondition: entry is added at the end of the list.
void ListContainer::pushBack(const Record& entry)
{
    data.push_back(entry);
}

// G. pop_back()
//precondition: none
//postcondition: The last element is removed if the list is not empty.
void ListContainer::popBack()
{
    if (!data.empty())
    {
        data.pop_back();
    }
}

//precondition: none
//postcondition: Returns the last element, or a default Record if the list is empty.
Record ListContainer::back() const
{
    if (!data.empty())
    {
        return data.back();
    }

    return Record();
}

//precondition: none
//postcondition: Returns the number of elements in the list.
int ListContainer::size() const
{
    return static_cast<int>(data.size());
}

//precondition: none
//postcondition: Returns true if the list is empty, false otherwise.
bool ListContainer::empty() const
{
    return data.empty();
}

//precondition: entry is a valid Record
//postcondition: Displays the contents of the Record entry in the format "first, second, number".
void ListContainer::displayRecord(const Record& entry) const
{
    cout << entry.first << ", " << entry.second << ", " << entry.number;
}

//precondition: none
//postcondition: Displays the number of elements in the list and the contents of each Record in the list.
void ListContainer::display() const
{
    cout << "\n\tThe list now has " << data.size() << " elements.\n";

    for (list<Record>::const_iterator it = data.begin(); it != data.end(); ++it)
    {
        cout << "\n\t\t";
        displayRecord(*it);
    }

    cout << "\n";
}

//precondition: fileName is a valid string representing the name of the input file, pushToFront is a boolean indicating whether to push elements to the front or back of the list
//postcondition: Reads the input file and adds each Record to the list, either at the front or back based on pushToFront. Returns true if successful, false if the file cannot be opened.
bool ListContainer::readFile(const string& fileName, bool pushToFront)
{
    ifstream inputFile(fileName);

    if (!inputFile)
    {
        return false;
    }

    string first;
    string second;
    int number;

    while (inputFile >> first >> second >> number)
    {
        if (!first.empty() && first.back() == ',')
        {
            first.pop_back();
        }
        if (!second.empty() && second.back() == ',')
        {
            second.pop_back();
        }

        Record entry(first, second, number);

        if (pushToFront)
        {
            data.push_front(entry);
        }
        else
        {
            data.push_back(entry);
        }
    }

    inputFile.close();
    return true;
}

//precondition: fileName is a valid string representing the name of the input file
//postcondition: Reads the input file and adds each Record to the front of the list. Returns true if successful, false if the file cannot be opened.
bool ListContainer::readFileFront(const string& fileName)
{
    return readFile(fileName, true);
}

//precondition: fileName is a valid string representing the name of the input file
//postcondition: Reads the input file and adds each Record to the back of the list. Returns true if successful, false if the file cannot be opened.
bool ListContainer::readFileBack(const string& fileName)
{
    return readFile(fileName, false);
}

//precondition: none
//postcondition: Returns the address of the first element in the list, or nullptr if the list is empty.
const void* ListContainer::getBeginAddress() const
{
    if (data.empty())
    {
        return nullptr;
    }

    return static_cast<const void*>(&(*data.begin()));
}

//precondition: none
//postcondition: Returns the address of the theoretical element following the last element in the list, or nullptr if the list is empty.
const void* ListContainer::getEndAddress() const
{
    list<Record>::const_iterator it = data.end();
    return static_cast<const void*>(it._Ptr);
}

//precondition: none
//postcondition: Returns the address of the second element in the list, or nullptr if the list has fewer than two elements.
const void* ListContainer::getAddressAfterBegin() const
{
    if (data.size() < 2)
    {
        return nullptr;
    }

    list<Record>::const_iterator it = data.begin();
    ++it;
    return static_cast<const void*>(&(*it));
}

//precondition: none
//postcondition: Displays the address and contents of the first element in the list, if it exists.
void ListContainer::displayBegin() const
{
    if (!data.empty())
    {
        list<Record>::const_iterator it = data.begin();

        cout << static_cast<const void*>(&(*it)) << "(";
        displayRecord(*it);
        cout << ")";
    }
}

//precondition: none
//postcondition: Displays the address of the theoretical element following the last element in the list, if the list is not empty.
void ListContainer::displayEnd() const
{
    if (!data.empty())
    {
        cout << getEndAddress();
    }
}

//precondition: none
//postcondition: Displays the addresses and contents of all elements in the list in order, from the first element to the last.
void ListContainer::displayForward() const
{
    for (list<Record>::const_iterator it = data.begin(); it != data.end(); ++it)
    {
        cout << "\n\t\t" << static_cast<const void*>(&(*it)) << " (";
        displayRecord(*it);
        cout << ")";
    }
}

//precondition: none
//postcondition: Displays the address and contents of the last element in the list, if it exists.
void ListContainer::displayRBegin() const
{
    if (!data.empty())
    {
        list<Record>::const_reverse_iterator it = data.rbegin();

        cout << static_cast<const void*>(&(*it)) << "(";
        displayRecord(*it);
        cout << ")";
    }
}

//precondition: none
//postcondition: Displays the address of the theoretical element preceding the first element in the list, if the list is not empty.
void ListContainer::displayREnd() const
{
    if (!data.empty())
    {
        list<Record>::const_reverse_iterator it = data.rend();
        cout << static_cast<const void*>(&it);
    }
}

//precondition: none
//postcondition: Displays the addresses and contents of all elements in the list in reverse order, from the last element to the first.
void ListContainer::displayReverse() const
{
    for (list<Record>::const_reverse_iterator it = data.rbegin(); it != data.rend(); ++it)
    {
        cout << "\n\t\t" << static_cast<const void*>(&(*it)) << " (";
        displayRecord(*it);
        cout << ")";
    }
}

//precondition: none
//postcondition: Removes the second element in the list, if it exists.
void ListContainer::eraseAfterBegin()
{
    if (data.size() < 2)
    {
        return;
    }

    list<Record>::iterator it = data.begin();
    ++it;
    data.erase(it);
}

//precondition: none
//postcondition: Removes all elements in the list and displays the addresses of the begin and end iterators before removal.
void ListContainer::eraseAll()
{
    if (data.empty())
    {
        return;
    }

    const void* startAddress = getBeginAddress();
    const void* endAddress = getEndAddress();
    cout << "\n\tAll elements starting at begin iterator " << startAddress
        << " and going up to end iterator " << endAddress << " have been removed.";
    data.erase(data.begin(), data.end());
}

//precondition: entry is a valid Record
//postcondition: Inserts the Record entry after the first element in the list. If the list is empty, entry is added as the first element.
void ListContainer::insertAfterBegin(const Record& entry)
{
    if (data.empty())
    {
        data.insert(data.begin(), entry);
        return;
    }

    list<Record>::iterator it = data.begin();
    //++it;
    data.insert(it, entry);
}

//precondition: other is a valid ListContainer
//postcondition: Exchanges the contents of the current list with the contents of the other list.
void ListContainer::swap(ListContainer& other)
{
    data.swap(other.data);
}

//precondition: none
//postcondition: Sorts the elements in the list in ascending order based on the first string of each Record using selection sort algorithm.
void ListContainer::sort()
{
    for (list<Record>::iterator i = data.begin(); i != data.end(); ++i)
    {
        list<Record>::iterator minIt = i;
        list<Record>::iterator j = i;
        ++j;

        for (; j != data.end(); ++j)
        {
            if (j->first < minIt->first)
            {
                minIt = j;
            }
        }

        if (minIt != i)
        {
            Record temp = *i;
            *i = *minIt;
            *minIt = temp;
        }
    }
}
