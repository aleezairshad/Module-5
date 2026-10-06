#include "VectorContainer.h"

// Constructor
//precondition: The VectorContainer class is defined with a private member variable data, which is a vector of Record objects. The constructor initializes the data vector to an empty state.
//postcondition: An instance of the VectorContainer class is created, and the data vector is initialized to an empty state, ready to store Record objects.
VectorContainer::VectorContainer()
{
}

// A. clear()
//precondition: The VectorContainer class has a private member variable data, which is a vector of Record objects. The clear() function is called on an instance of the VectorContainer class.
//postcondition: All elements in the data vector are removed, and the vector is left in an empty state. Any memory allocated for the elements is released, and the size of the vector becomes zero.
void VectorContainer::clear()
{
    data.clear();
}

// B. reserve(n)
//precondition: The VectorContainer class has a private member variable data, which is a vector of Record objects. The reserve(int n) function is called on an instance of the VectorContainer class with a positive integer n as an argument.
//postcondition: The capacity of the data vector is increased to at least n elements. If the current capacity is already greater than or equal to n, no changes are made. The size of the vector remains unchanged, and any existing elements are preserved.
void VectorContainer::reserve(int n)
{
    data.reserve(n);
}

// C. resize(n)
//precondition: The VectorContainer class has a private member variable data, which is a vector of Record objects. The resize(int n) function is called on an instance of the VectorContainer class with a non-negative integer n as an argument.
//postcondition: The size of the data vector is changed to n. If n is greater than the current size, additional default-inserted Record elements are appended. If n is less than the current size, the vector is reduced to its first n elements.
void VectorContainer::resize(int n)
{
    data.resize(n);
}

// D. push_back(e)
//precondition: The VectorContainer class has a private member variable data, which is a vector of Record objects. The pushBack(const Record& entry) function is called on an instance of the VectorContainer class with a Record object entry as an argument.
//postcondition: The Record object entry is added to the end of the data vector. The size of the vector increases by one, and the new element is accessible at the last index of the vector.
void VectorContainer::pushBack(const Record& entry)
{
    data.push_back(entry);
}


// E. pop_back()
//precondition: The VectorContainer class has a private member variable data, which is a vector of Record objects. The popBack() function is called on an instance of the VectorContainer class.
//postcondition: The last element of the data vector is removed. If the vector is empty, no action is taken. The size of the vector decreases by one, and the last element is no longer accessible.
void VectorContainer::popBack()
{
    if (!data.empty())
    {
        data.pop_back();
    }
}

// F. front()
//precondition: The VectorContainer class has a private member variable data, which is a vector of Record objects. The front() function is called on an instance of the VectorContainer class.
//postcondition: The first element of the data vector is returned. If the vector is empty, a default Record object is returned.
Record VectorContainer::front() const
{
    if (!data.empty())
    {
        return data.front();
    }

    return Record();
}

// G. back()
//precondition: The VectorContainer class has a private member variable data, which is a vector of Record objects. The back() function is called on an instance of the VectorContainer class.
//postcondition: The last element of the data vector is returned. If the vector is empty, a default Record object is returned.
Record VectorContainer::back() const
{
    if (!data.empty())
    {
        return data.back();
    }

    return Record();
}

// H. at()
//precondition: The VectorContainer class has a private member variable data, which is a vector of Record objects. The at(int index) function is called on an instance of the VectorContainer class with an integer index as an argument.
//postcondition: The Record object at the specified index in the data vector is returned. If the index is out of bounds (negative or greater than or equal to the size of the vector), a default Record object is returned.
Record VectorContainer::at(int index) const
{
    if (index >= 0 && index < static_cast<int>(data.size()))
    {
        return data.at(index);
    }

    return Record();
}

// precondition: The VectorContainer class has a private member variable data, which is a vector of Record objects. The operator[](int index) function is called on an instance of the VectorContainer class with an integer index as an argument.
// postcondition: The Record object at the specified index in the data vector is returned. If the index is out of bounds (negative or greater than or equal to the size of the vector), a default Record object is returned.
Record VectorContainer::operator[](int index) const
{
    if (index >= 0 && index < static_cast<int>(data.size())) //
    {
        return data[index];
    }
    return Record();
}


// I. begin()
//precondition: The VectorContainer class has a private member variable data, which is a vector of Record objects. The displayBegin() function is called on an instance of the VectorContainer class.
//postcondition: The address of the first element in the data vector is displayed, along with the contents of that element. If the vector is empty, no output is produced.
void VectorContainer::displayBegin() const
{
    if (!data.empty())
    {
        vector<Record>::const_iterator it = data.begin();

        cout << static_cast<const void*>(&(*it)) << "(";
        displayRecord(*it);
        cout << ")";
    }
}

// J. end()
//precondition: The VectorContainer class has a private member variable data, which is a vector of Record objects. The displayEnd() function is called on an instance of the VectorContainer class.
//postcondition: The address of the past-the-end element in the data vector is displayed. If the vector is empty, no output is produced.
void VectorContainer::displayEnd() const
{
    if (!data.empty())
    {
        const Record* ptr = data.data() + data.size();
        cout << static_cast<const void*>(ptr);
    }
}

// K. begin() and end()
//precondition: The VectorContainer class has a private member variable data, which is a vector of Record objects. The displayForward() function is called on an instance of the VectorContainer class.
//postcondition: The addresses and contents of all elements in the data vector are displayed in order, from the first element to the last. If the vector is empty, no output is produced.
void VectorContainer::displayForward() const
{
    for (vector<Record>::const_iterator it = data.begin(); it != data.end(); ++it)
    {
        cout << "\n\t\t" << static_cast<const void*>(&(*it)) << " (";
        displayRecord(*it);
        cout << ")";
    }
}

// L. rbegin()
//precondition: The VectorContainer class has a private member variable data, which is a vector of Record objects. The displayRBegin() function is called on an instance of the VectorContainer class.
//postcondition: The address of the last element in the data vector is displayed, along with the contents of that element. If the vector is empty, no output is produced.
void VectorContainer::displayRBegin() const
{
    if (!data.empty())
    {
        vector<Record>::const_reverse_iterator it = data.rbegin();

		//cout << static_cast<const void*>(&it) << "("; // Display the address of the reverse iterator itself
		cout << static_cast<const void*>(&(*it)) << "("; // Display the address of the current element in the reverse iteration
        displayRecord(*it);
        cout << ")";
    }
}

// M. rend()
//precondition: The VectorContainer class has a private member variable data, which is a vector of Record objects. The displayREnd() function is called on an instance of the VectorContainer class.
//postcondition: The address of the theoretical element preceding the first element in the data vector is displayed. If the vector is empty, no output is produced.
void VectorContainer::displayREnd() const
{
    if (!data.empty())
    {
        vector<Record>::const_reverse_iterator it = data.rend();

		cout << static_cast<const void*>(&it); // Display the address of the reverse iterator itself
    }
}

// N. rbegin() and rend()
//precondition: The VectorContainer class has a private member variable data, which is a vector of Record objects. The displayReverse() function is called on an instance of the VectorContainer class.
//postcondition: The addresses and contents of all elements in the data vector are displayed in reverse order, from the last element to the first. If the vector is empty, no output is produced.
void VectorContainer::displayReverse() const
{
    for (vector<Record>::const_reverse_iterator it = data.rbegin(); it != data.rend(); ++it)
    {
		//cout << "\n\t\t" << static_cast<const void*>(&it) << " ("; // Display the address of the reverse iterator itself
		cout << "\n\t\t" << static_cast<const void*>(&(*it)) << " ("; // Display the address of the current element in the reverse iteration
        displayRecord(*it);
        cout << ")";
    }
}


// O. erase(it)
//precondition: The VectorContainer class has a private member variable data, which is a vector of Record objects. The erase(int index) function is called on an instance of the VectorContainer class with an integer index as an argument.
//postcondition: The element at the specified index in the data vector is removed. If the index is out of bounds (negative or greater than or equal to the size of the vector), no action is taken. The size of the vector decreases by one, and the elements after the removed element are shifted to fill the gap.
void VectorContainer::erase(int index)
{
    if (index >= 0 && index < static_cast<int>(data.size()))
    {
        vector<Record>::iterator it = data.begin() + index;

        data.erase(it);
    }
}

// P. erase(start_it, end_it)
//precondition: The VectorContainer class has a private member variable data, which is a vector of Record objects. The erase(int startIndex, int endIndex) function is called on an instance of the VectorContainer class with two integer indices as arguments.
//postcondition: All elements in the data vector from the specified startIndex (inclusive) to endIndex (exclusive) are removed. If the indices are out of bounds or invalid (startIndex >= endIndex), no action is taken. The size of the vector decreases by the number of removed elements, and the elements after the removed range are shifted to fill the gap.
void VectorContainer::erase(int startIndex, int endIndex)
{
    if (data.empty())
    {
        cout << "\n\tThe vector is empty.";
        return;
    }

    if (startIndex >= 0 && endIndex <= static_cast<int>(data.size()) && startIndex < endIndex)
    {
        vector<Record>::iterator start_it = data.begin() + startIndex;
        vector<Record>::iterator end_it = data.begin() + endIndex;
		// Save the address of the start iterator BEFORE erase()
        const void* startAddress = &(*start_it);
		// Save the address of the end iterator BEFORE erase()
        const void* endAddress = static_cast<const void*>(data.data() + endIndex);
        cout << "\n\tAll elements starting at begin iterator " << startAddress << " and going up to end iterator " << endAddress << " have been removed.";
        data.erase(start_it, end_it);
    }
}

// Q. insert(it, entry)
// precondition: The VectorContainer class has a private member variable data, which is a vector of Record objects. The insert(int index, const Record& entry) function is called on an instance of the VectorContainer class with an integer index and a Record object entry as arguments.
// postcondition: The Record object entry is inserted into the data vector at the specified index. If the index is out of bounds (negative or greater than the size of the vector), no action is taken. The size of the vector increases by one, and the elements after the inserted element are shifted to make room.
void VectorContainer::insert(int index, const Record& entry)
{
    if (index >= 0 && index <= static_cast<int>(data.size()))
    {
        vector<Record>::iterator it = data.begin() + index;
        data.insert(it, entry);
    }
}

// R. swap()
//precondition: The VectorContainer class has a private member variable data, which is a vector of Record objects. The swap(VectorContainer& other) function is called on an instance of the VectorContainer class with another VectorContainer object other as an argument.
//postcondition: The contents of the data vector in the current instance are exchanged with the contents of the data vector in the other instance. After the swap, the current instance contains the elements that were previously in the other instance, and vice versa. The sizes and capacities of both vectors are also swapped.
void VectorContainer::swap(VectorContainer& other)
{
    data.swap(other.data);
} 

// Display vector elements after swap
//precondition: The VectorContainer class has a private member variable data, which is a vector of Record objects. The displaySwap() function is called on an instance of the VectorContainer class.
//postcondition: The addresses and contents of all elements in the data vector are displayed in order, from the first element to the last. If the vector is empty, no output is produced.
void VectorContainer::displaySwap() const
{
    for (int i = 0; i < static_cast<int>(data.size()); i++)
    {
        cout << "\n\t\t[" << i << "] ";
        displayRecord(data[i]);
    }
}

// S. sort() - Selection Sort
//precondition: The VectorContainer class has a private member variable data, which is a vector of Record objects. The sort() function is called on an instance of the VectorContainer class.
//postcondition: The elements in the data vector are sorted in ascending order based on the first string of each Record object. The sorting is performed using the selection sort algorithm, which repeatedly finds the minimum element from the unsorted portion of the vector and swaps it with the first unsorted element. After sorting, the elements in the vector are arranged in order based on their first string values.
void VectorContainer::sort()
{
    for (int i = 0; i < static_cast<int>(data.size()) - 1; i++)
    {
        int minIndex = i;

        // Find the smallest name
        for (int j = i + 1; j < static_cast<int>(data.size()); j++)
        {
            if (data[j].first < data[minIndex].first)
            {
                minIndex = j;
            }
        }

        // Swap the records
        if (minIndex != i)
        {
            Record temp = data[i];
            data[i] = data[minIndex];
            data[minIndex] = temp;
        }
    }
}

// Return vector size
//precondition: The VectorContainer class has a private member variable data, which is a vector of Record objects. The size() function is called on an instance of the VectorContainer class.
//postcondition: The size of the data vector is returned as an integer value, representing the number of elements currently stored in the vector.
int VectorContainer::size() const
{
    return static_cast<int>(data.size());
}


// Return vector capacity
//precondition: The VectorContainer class has a private member variable data, which is a vector of Record objects. The capacity() function is called on an instance of the VectorContainer class.
//postcondition: The capacity of the data vector is returned as an integer value, representing the total number of elements that the vector can hold before needing to allocate more memory. This value may be greater than or equal to the size of the vector.
int VectorContainer::capacity() const
{
    return static_cast<int>(data.capacity());
}


// Check if vector is empty
//precondition: The VectorContainer class has a private member variable data, which is a vector of Record objects. The empty() function is called on an instance of the VectorContainer class.
//postcondition: A boolean value is returned, indicating whether the data vector is empty (true) or not (false). If the vector has no elements, it is considered empty.
bool VectorContainer::empty() const
{
    return data.empty();
}


// Display one record
//precondition: The VectorContainer class has a private member variable data, which is a vector of Record objects. The displayRecord(const Record& entry) function is called on an instance of the VectorContainer class with a Record object entry as an argument.
//postcondition: The contents of the Record object entry are displayed in the format "first second number", where first and second are strings and number is an integer. The output is sent to the standard output stream (cout).
void VectorContainer::displayRecord(const Record& entry) const
{
    //cout << entry.first << ' ' << entry.second << ' ' << entry.number;
	cout << entry.first << ", " << entry.second << ", " << entry.number;
}

// Display all vector elements
//precondition: The VectorContainer class has a private member variable data, which is a vector of Record objects. The display() function is called on an instance of the VectorContainer class.
//postcondition: The size of the data vector is displayed, followed by the contents of each Record object in the vector. Each element is displayed in the format "[index]: first second number", where index is the position of the element in the vector, and first, second, and number are the corresponding values from the Record object. The output is sent to the standard output stream (cout).
void VectorContainer::display() const
{
    cout << "\n\tThe vector now has " << data.size() << " elements.\n";

    for (int i = 0; i < static_cast<int>(data.size()); i++)
    {
        cout << "\n\t[" << i << "]: ";

        displayRecord(data[i]);
    }

    cout << "\n";
}

// precondition: The VectorContainer class has a private member variable data, which is a vector of Record objects. The readFile(const string& fileName) function is called on an instance of the VectorContainer class with a string fileName as an argument, representing the name of the input file to read.
// postcondition: The function attempts to open the specified input file. If the file is successfully opened, it reads each line of the file, extracting the first string, second string, and integer number from each line, and creates a Record object for each entry. Each Record object is then added to the data vector using push_back(). If the file cannot be opened, the function returns false. If the file is read successfully, the function returns true.
bool VectorContainer::readFile(const string& fileName)
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
        data.push_back(entry);
    }

    inputFile.close();
    return true;
}

//precondition: The VectorContainer class has a private member variable data, which is a vector of Record objects. The getAddress(int index) function is called on an instance of the VectorContainer class with an integer index as an argument.
//postcondition: The function returns a pointer to the Record object at the specified index in the data vector. If the index is out of bounds (negative or greater than or equal to the size of the vector), the function returns a nullptr. The returned pointer can be used to access the memory address of the Record object at the specified index.
const void* VectorContainer::getAddress(int index) const
{
    if (index >= 0 && index < static_cast<int>(data.size()))
    {
        return static_cast<const void*>(&data[index]);
    }

    return nullptr;
}