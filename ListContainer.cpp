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

Record ListContainer::back() const
{
    if (!data.empty())
    {
        return data.back();
    }

    return Record();
}

int ListContainer::size() const
{
    return static_cast<int>(data.size());
}

bool ListContainer::empty() const
{
    return data.empty();
}

void ListContainer::displayRecord(const Record& entry) const
{
    cout << entry.first << ", " << entry.second << ", " << entry.number;
}

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

bool ListContainer::readFileFront(const string& fileName)
{
    return readFile(fileName, true);
}

bool ListContainer::readFileBack(const string& fileName)
{
    return readFile(fileName, false);
}

const void* ListContainer::getBeginAddress() const
{
    if (data.empty())
    {
        return nullptr;
    }

    return static_cast<const void*>(&(*data.begin()));
}

const void* ListContainer::getEndAddress() const
{
    list<Record>::const_iterator it = data.end();
    return static_cast<const void*>(it._Ptr);
}

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

void ListContainer::displayEnd() const
{
    if (!data.empty())
    {
        cout << getEndAddress();
    }
}

void ListContainer::displayForward() const
{
    for (list<Record>::const_iterator it = data.begin(); it != data.end(); ++it)
    {
        cout << "\n\t\t" << static_cast<const void*>(&(*it)) << " (";
        displayRecord(*it);
        cout << ")";
    }
}

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

void ListContainer::displayREnd() const
{
    if (!data.empty())
    {
        list<Record>::const_reverse_iterator it = data.rend();
        cout << static_cast<const void*>(&it);
    }
}

void ListContainer::displayReverse() const
{
    for (list<Record>::const_reverse_iterator it = data.rbegin(); it != data.rend(); ++it)
    {
        cout << "\n\t\t" << static_cast<const void*>(&(*it)) << " (";
        displayRecord(*it);
        cout << ")";
    }
}

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

void ListContainer::insertAfterBegin(const Record& entry)
{
    if (data.empty())
    {
        data.insert(data.begin(), entry);
        return;
    }

    list<Record>::iterator it = data.begin();
    ++it;
    data.insert(it, entry);
}

void ListContainer::swap(ListContainer& other)
{
    data.swap(other.data);
}

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
