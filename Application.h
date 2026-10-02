#pragma once
#include <iostream>
#include <vector>

using namespace std;

class Application
{
private:
	vector<int> data; // Vector to store integers
	void selectionSort(vector<int>& temp) const; // Sorts the elements of the temp vector in ascending order using selection sort
	bool binarySearch(const vector<int>& temp, int number) const; // Performs a binary search on the sorted temp vector to check if the specified number exists in the vector

public:
	Application(); // Constructor
	void add(int number); // Adds an integer to the data vector
	bool remove(int number); // Removes an integer from the data vector if it exists, returns true if removed, false otherwise
    void display() const; // Displays the contents of the data vector
    void displayFrequencies() const; // Displays the frequencies of each integer value in the data vector
    bool empty() const; // Checks if the data vector is empty
};


