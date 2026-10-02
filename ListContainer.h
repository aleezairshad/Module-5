#pragma once

#include <iostream>
#include <list>
#include <string>
#include <fstream>
#include "VectorContainer.h"

using namespace std;

class ListContainer
{
private:
    list<Record> data;

    bool readFile(const string& fileName, bool pushToFront);

public:
    ListContainer();

    void clear();
    void resize(int n);
    void pushFront(const Record& entry);
    void popFront();
    Record front() const;
    void pushBack(const Record& entry);
    void popBack();
    Record back() const;

    int size() const;
    bool empty() const;
    bool readFileFront(const string& fileName);
    bool readFileBack(const string& fileName);
    void display() const;
    void displayRecord(const Record& entry) const;

    void displayBegin() const;
    void displayEnd() const;
    void displayForward() const;
    void displayRBegin() const;
    void displayREnd() const;
    void displayReverse() const;
    void eraseAfterBegin();
    void eraseAll();
    void insertAfterBegin(const Record& entry);
    void swap(ListContainer& other);
    void sort();
    const void* getBeginAddress() const;
    const void* getEndAddress() const;
    const void* getAddressAfterBegin() const;
};
