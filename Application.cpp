#include "Application.h"


// Constructor
//precondition: The Application class is defined with a private member variable data, which is a vector of integers. The constructor initializes the data vector to an empty state.
Application::Application()
{
}

//precondition: The Application class has a private member variable data, which is a vector of integers. 
//postcondition: The integer number is added to the data vector.
void Application::add(int number)
{
    data.push_back(number);
}

//precondition: None
//postcondition: Returns true if the data vector is empty, otherwise returns false.
bool Application::empty() const
{
    return data.empty();
}

//precondition: The selectionSort function is called with a reference to a vector of integers temp as an argument.
//postcondition: The function sorts the elements of the temp vector in ascending order using the selection sort algorithm. The original data vector remains unchanged.
void Application::selectionSort(vector<int>& temp) const
{
	const int ONE = 1;
    for (int i = 0; i < static_cast<int>(temp.size()) - ONE; i++)
    {
        int minIndex = i;

        for (int j = i + ONE; j < static_cast<int>(temp.size()); j++)
        {
            if (temp[j] < temp[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            int hold = temp[i];
            temp[i] = temp[minIndex];
            temp[minIndex] = hold;
        }
    }
}

//precondition: The binarySearch function is called with a reference to a sorted vector of integers temp and an integer number as arguments.
bool Application::binarySearch(const vector<int>& temp, int number) const
{
	const int ONE = 1, TWO = 2;
    int left = 0;
    int right = static_cast<int>(temp.size()) - ONE;
    while (left <= right)
    {
        int middle = (left + right) / TWO;

        if (temp[middle] == number)
        {
            return true;
        }
        else if (number < temp[middle])
        {
            right = middle - ONE;
        }
        else
        {
            left = middle + ONE;
        }
    }

    return false;
}

//precondition: The remove function is called with an integer number as an argument. The data vector contains integers that may or may not include the specified number.
//postcondition: If the number is found in the data vector, it is removed and the function returns true. Otherwise, the function returns false.
bool Application::remove(int number)
{
    vector<int> temp = data;
    // Binary search requires sorted data
    selectionSort(temp);
    if (!binarySearch(temp, number))
    {
        return false;
    }
    // Remove from original vector
    for (vector<int>::iterator it = data.begin(); it != data.end(); ++it)
    {
        if (*it == number)
        {
            data.erase(it);
            return true;
        }
    }
    return false;
}

//precondition: The display function is called on an instance of the Application class.
//postcondition: The function displays the contents of the data vector. If the vector is empty, it displays "empty".
void Application::display() const
{
    cout << "\n\t\tcontainer: ";
    if (data.empty())
    {
        cout << "empty";
        return;
    }
	// Display all elements in the data vector
    for (int number : data)
    {
        cout << number << " ";
    }
}

//precondition: The displayFrequencies function is called on an instance of the Application class. 
//postcondition: The function displays the frequencies of each integer value in the data vector. If the vector is empty, it displays "empty".
void Application::displayFrequencies() const
{
    cout << "\n\t\tcontainer:";

    if (data.empty())
    {
        cout << " empty";
        return;
    }

    for (int value = 0; value <= 100; value++)
    {
        int frequency = 0;

        for (int number : data)
        {
            if (number == value)
            {
                frequency++;
            }
        }

        if (frequency > 0)
        {
            cout << "\n\t\t" << value << ": " << frequency;
        }
    }
}
