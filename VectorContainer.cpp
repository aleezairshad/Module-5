#include "VectorContainer.h"


// Constructor
VectorContainer::VectorContainer()
{
}


// A. clear()
void VectorContainer::clear()
{
    data.clear();
}


// B. reserve(n)
void VectorContainer::reserve(int n)
{
    data.reserve(n);
}


// C. resize(n)
void VectorContainer::resize(int n)
{
    data.resize(n);
}


// D. push_back(e)
void VectorContainer::pushBack(const Record& entry)
{
    data.push_back(entry);
}


// E. pop_back()
void VectorContainer::popBack()
{
    if (!data.empty())
    {
        data.pop_back();
    }
}


// F. front()
Record VectorContainer::front() const
{
    if (!data.empty())
    {
        return data.front();
    }

    return Record();
}


// G. back()
Record VectorContainer::back() const
{
    if (!data.empty())
    {
        return data.back();
    }

    return Record();
}


// H. at()
Record VectorContainer::at(int index) const
{
    if (index >= 0 && index < static_cast<int>(data.size()))
    {
        return data.at(index);
    }

    return Record();
}


// I. begin()
void VectorContainer::displayBegin() const
{
    if (!data.empty())
    {
        vector<Record>::const_iterator it = data.begin();

        displayRecord(*it);
    }
}


// J. end()
void VectorContainer::displayEnd() const
{
    if (!data.empty())
    {
        vector<Record>::const_iterator it = data.end();

        // end() points one position past the last element.
        // Therefore, do NOT dereference it.
        cout << "end() points past the last element";
    }
}


// K. begin() and end()
void VectorContainer::displayForward() const
{
    int index = 0;

    for (vector<Record>::const_iterator it = data.begin();
        it != data.end();
        ++it)
    {
        cout << "\n\t[" << index << "]: ";
        displayRecord(*it);

        index++;
    }
}


// L. rbegin()
void VectorContainer::displayRBegin() const
{
    if (!data.empty())
    {
        vector<Record>::const_reverse_iterator it = data.rbegin();

        displayRecord(*it);
    }
}


// M. rend()
void VectorContainer::displayREnd() const
{
    if (!data.empty())
    {
        // rend() points before the first element.
        // Therefore, do NOT dereference it.
        cout << "rend() points before the first element";
    }
}


// N. rbegin() and rend()
void VectorContainer::displayReverse() const
{
    int index = static_cast<int>(data.size()) - 1;

    for (vector<Record>::const_reverse_iterator it = data.rbegin();
        it != data.rend();
        ++it)
    {
        cout << "\n\t[" << index << "]: ";
        displayRecord(*it);

        index--;
    }
}


// O. erase(it)
void VectorContainer::erase(int index)
{
    if (index >= 0 && index < static_cast<int>(data.size()))
    {
        vector<Record>::iterator it = data.begin() + index;

        data.erase(it);
    }
}


// P. erase(start_it, end_it)
void VectorContainer::erase(int startIndex, int endIndex)
{
    if (startIndex >= 0 &&
        endIndex <= static_cast<int>(data.size()) &&
        startIndex < endIndex)
    {
        vector<Record>::iterator startIt =
            data.begin() + startIndex;

        vector<Record>::iterator endIt =
            data.begin() + endIndex;

        data.erase(startIt, endIt);
    }
}


// Q. insert(it, entry)
void VectorContainer::insert(int index, const Record& entry)
{
    if (index >= 0 && index <= static_cast<int>(data.size()))
    {
        vector<Record>::iterator it =
            data.begin() + index;

        data.insert(it, entry);
    }
}


// R. swap()
void VectorContainer::swap(VectorContainer& other)
{
    data.swap(other.data);
}


// S. sort()
void VectorContainer::sort()
{
    std::sort(
        data.begin(),
        data.end(),
        [](const Record& left, const Record& right)
        {
            return left.number < right.number;
        }
    );
}


// Return vector size
int VectorContainer::size() const
{
    return static_cast<int>(data.size());
}


// Return vector capacity
int VectorContainer::capacity() const
{
    return static_cast<int>(data.capacity());
}


// Check if vector is empty
bool VectorContainer::empty() const
{
    return data.empty();
}


// Display one record
void VectorContainer::displayRecord(const Record& entry) const
{
    cout << entry.first << entry.second << entry.number;
}


// Display all vector elements
void VectorContainer::display() const
{
    cout << "\n\tThe vector now has " << data.size() << " elements.";

    for (int i = 0; i < static_cast<int>(data.size()); i++)
    {
        cout << "\n\t[" << i << "]: ";

        displayRecord(data[i]);
    }

    cout << "\n";
}

bool VectorContainer::readFile(const string& fileName)
{
    ifstream inputFile(fileName);

    if (!inputFile)
    {
        return false;
    }

    Record entry;

    while (inputFile >> entry.first >> entry.second >> entry.number)
    {
        data.push_back(entry);
    }

    inputFile.close();

    return true;
}