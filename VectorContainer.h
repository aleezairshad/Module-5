#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;


// Structure stored inside the vector
struct Record
{
    string first;
    string second;
    int number;

    // Default constructor
    Record()
    {
        first = "unknown";
        second = "unknown";
        number = 0;
    }

    // Constructor
    Record(string first, string second, int number)
    {
        this->first = first;
        this->second = second;
        this->number = number;
    }
};


class VectorContainer
{
private:
    vector<Record> data;

public:
    // Constructor
    VectorContainer();

    // A. clear()
    void clear();

    // B. reserve(n)
    void reserve(int n);

    // C. resize(n)
    void resize(int n);

    // D. push_back(e)
    void pushBack(const Record& entry);

    // E. pop_back()
    void popBack();

    // F. front()
    Record front() const;

    // G. back()
    Record back() const;

    // H. at()
    Record at(int index) const;

    // I. begin()
    void displayBegin() const;

    // J. end()
    void displayEnd() const;

    // K. begin() and end()
    void displayForward() const;

    // L. rbegin()
    void displayRBegin() const;

    // M. rend()
    void displayREnd() const;

    // N. rbegin() and rend()
    void displayReverse() const;

    // O. erase(it)
    void erase(int index);

    // P. erase(start_it, end_it)
    void erase(int startIndex, int endIndex);

    // Q. insert(it, entry)
    void insert(int index, const Record& entry);

    // R. swap()
    void swap(VectorContainer& other);

    // S. sort()
    void sort();

    // Other useful functions
    int size() const;
    int capacity() const;
    bool empty() const;
    bool readFile(const string& fileName);
    void display() const;
    void displayRecord(const Record& entry) const;
};