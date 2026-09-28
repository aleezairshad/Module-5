//Name: Hany, Aleeza, and Thanh
// Date: 9/30/2026
// Description: Module 5 - Linked List 

#include <iostream>
#include <iomanip>
#include "input.h"
#include "VectorContainer.h"

using namespace std;

char menuOption();

void vectorContainer();
void listContainer();
void application();

int main() 
{
	bool running = true;
	char option;

    while (running) 
    {
        system("cls");

        option = menuOption();
        switch (option) 
        {
            case '1':
				vectorContainer();
                
                break;
            case '2':
				listContainer();
                
                break;
            case '3':
				application();

                break;
            case '0':
                cout << "Exiting the program.\n";
                running = false;
                break;
            default:
                cout << "Invalid option. Please try again.\n";
                break;
        }
	}

	return 0;
}


char menuOption() 
{
    cout << "\tCMPR131 Chapter 5: Vector and List Container by Hany, Aleeza, and Thanh (09/30/2026)\n";
    cout << "\t" << string(105, char(205));
    cout << "\n\t\t1> Vector container";
    cout << "\n\t\t2> List container";
    cout << "\n\t\t3> Application using Vector and/or List container\n";
    cout << "\t" << string(105, char(196));
    cout << "\n\t\t0 > Exit\n";
    cout << "\t" << string(105, char(205));

    char option = toupper(inputChar("\n\t\toption: ", static_cast<string>("1,2,3,0")));
    return option;
}


void vectorContainer() 
{
	bool running = true;
	char option;

    VectorContainer numbers; 

    while (running)
    {
		system("cls");
		cout << "\tVectors are sequence containers representing arrays that can change in size.\n";
        cout << "\n\t1> Vector's member functions";
		cout << "\n\t" << string(105, char(205));
		cout << "\n\t\tA> clear() - Removes all elements from the vector (which are destroyed)";
		cout << "\n\t\tB> reserve(n) - Requests that the vector capacity be at least enough to contain n elements";
		cout << "\n\t\tC> resize(n) - Resizes the container so that it contains n elements";
		cout << "\n\t\tD> Read input.dat and push_back(e) - Adds a new element at the end of the vector";
		cout << "\n\t\tE> pop_back() - Removes the last element in the vector";
		cout << "\n\t\tF> front() - Returns a reference to the first element in the vector";
		cout << "\n\t\tG> back() - Returns a reference to the last element in the vector";
		cout << "\n\t\tH> index using at() or []) - Returns a reference to the element at position n in the vector";
		cout << "\n\t\tI> begin() - Returns an iterator pointing to the first element in the vector";
		cout << "\n\t\tJ> end() Returns an iterator referring to the past-the-end element in the vector";
		cout << "\n\t\tK> Using iterator begin() and end() returns all elements in the vector";
		cout << "\n\t\tL> rbegin() - Returns a reverse iterator pointing to the last element in the vector";
		cout << "\n\t\tM> rend() - Returns a reverse iterator pointing to the theoretical element preceding the first";
        cout << "\n\t\t\t    element in the vector";
		cout << "\n\t\tN> Using iterator rbegin() and rend() returns all elements in the vector";
		cout << "\n\t\tO> erase(it) - Removes from the vector a single element(using an iterator)";
		cout << "\n\t\tP> erase(start_it,end_it) - Removes from the vector a range of elements( using iterators)";
		cout << "\n\t\tQ> insert(it, entry) - Insert a new entry at the iterator.";
		cout << "\n\t\tR> swap() - Exchanges the content of the container by another vector's content of the same type";
		cout << "\n\t\tS> Sort - Sorts the vector.";
		cout << "\n\t" << string(105, char(196));
		cout << "\n\t\t0> return";
		cout << "\n\t" << string(105, char(205));

		option = toupper(inputChar("\n\t\tOption: ", static_cast<string>("A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,0")));

        switch (option)
        {
        case 'A':
        {
            numbers.clear();

            cout << "\n\tThe vector has been cleared.\n\n";

            system("pause");
            break;
        }
        case 'B':
        {
            int capacity = inputInteger("\n\t\tEnter the capacity(1..100): ", 1, 100);

            numbers.reserve(capacity);

            cout << "\n\t\tThe vector has been reserved " << capacity << " elements.\n\n";

            system("pause");
            break;
        }
        case 'C':
        {
            int newSize = inputInteger("\n\t\tEnter the new size(1..100): ", 1, 100);
            numbers.resize(newSize);
            cout << "\n\t\tThe vector has been resized to " << newSize << " elements.\n\n";
            system("pause");
            break;
        }
        case 'D':
        {
            string fileName = "INPUT.DAT";

            if (!numbers.readFile(fileName))
            {
                cout << "\n\tThe input file, " << fileName << ", does not exist.\n\n";
            }
            else
            {
                numbers.display();
                cout << "\n";
            }

            system("pause");
            break;
        }


        case 'E':
            cout << "pop_back() selected.\n";
            break;
        case 'F':
            cout << "front() selected.\n";
            break;
        case 'G':
            cout << "back() selected.\n";
            break;
        case 'H':
            cout << "index using at() or [] selected.\n";
            break;
        case 'I':
            cout << "begin() selected.\n";
            break;
        case 'J':
            cout << "end() selected.\n";
            break;
        case 'K':
            cout << "Using iterator begin() and end() returns all elements in the vector selected.\n";
            break;
        case 'L':
            cout << "rbegin() selected.\n";
            break;
        case 'M':
            cout << "rend() selected.\n";
            break;
        case 'N':
            cout << "Using iterator rbegin() and rend() returns all elements in the vector selected.\n";
            break;
        case 'O':
            cout << "erase(it) selected.\n";
            break;
        case 'P':
            cout << "erase(start_it,end_it) selected.\n";
            break;
        case 'Q':
            cout << "insert(it, entry) selected.\n";
            break;
        case 'R':
            cout << "swap() selected.\n";
            break;
        case 'S':
            cout << "Sort selected.\n";
            break;
        case '0':
            running = false;
            cout << "\n";
			system("pause");
            break;
        default:
            cout << "Invalid option. Please try again.\n";
            break;
        }
    }

}


void listContainer()
{
    bool running = true;
    char option;

    while (running)
    {
        system("cls");
        cout << "\tLists are sequence containers that allow constant time insert and erase operations anywhere within the\n";
        cout << "\tsequence, and iteration in both directions.";
        cout << "\n\n\t2> List container";
        cout << "\n\t" << string(105, char(205));
		cout << "\n\t\tA> clear() - Destroys all elements from the list";
		cout << "\n\t\tB> resize(n) - Changes the list so that it contains n elements";
		cout << "\n\t\tC> Read input.dat and push_front(e) - Adds a new element at the front of the list";
		cout << "\n\t\tD> pop_front() - Deletes the first element";
		cout << "\n\t\tE> front() - Accesses the first element";
		cout << "\n\t\tF> Read input.dat and push_back(e) - Adds a new element at the end of the list";
		cout << "\n\t\tG> pop_back() - Delete the last element";
		cout << "\n\t\tH> back() Accesses the last element";
		cout << "\n\t\tI> begin() - Returns an iterator refereing to the first element in the list";
		cout << "\n\t\tJ> end() Returns an iterator referring to the past-the-end element in the list";
		cout << "\n\t\tK> Using iterator begin() and end() returns all elements in the list";
		cout << "\n\t\tL> rbegin() - Returns a reverse iterator pointing to the last element in the list";
        cout << "\n\t\tM> rend() - Returns a reverse iterator pointing to the element preceding the first element";
		cout << "\n\t\t\t    in the list";
		cout << "\n\t\tN> Using iterator rbegin() and rend() returns all elements in the list";
		cout << "\n\t\tO> erase(it) - Removes from the vector a single element(using an iterator)";
		cout << "\n\t\tP> erase(start_it,end_it) - Removes from the vector a range of elements( using iterators)";
		cout << "\n\t\tQ> insert(it, entry) - Insert a new entry at the iterator.";
		cout << "\n\t\tR> swap() - Exchanges the content of the container by another list's content of the same type";
		cout << "\n\t\tS> Sort - Sorts the list.";
		cout << "\n\t" << string(105, char(196));
		cout << "\n\t\t0> return";
		cout << "\n\t" << string(105, char(205));
		option = toupper(inputChar("\n\t\tOption: ", static_cast<string>("A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,0")));

        switch (option)
        {
            case 'A':
            cout << "clear() selected.\n";
			break;
            case 'B':
				cout << "resize(n) selected.\n";
                break;
            case 'C':
                cout << "Read input.dat and push_front(e) selected.\n";
                break;
            case 'D':
                cout << "pop_front() selected.\n";
                break;
            case 'E':
                cout << "front() selected.\n";
                break;
            case 'F':
                cout << "Read input.dat and push_back(e) selected.\n";
                break;
            case 'G':
                cout << "pop_back() selected.\n";
                break;
            case 'H':
                cout << "back() selected.\n";
                break;
            case 'I':
                cout << "begin() selected.\n";
                break;
            case 'J':
                cout << "end() selected.\n";
                break;
            case 'K':
                cout << "Using iterator begin() and end() returns all elements in the list selected.\n";
                break;
            case 'L':
                cout << "rbegin() selected.\n";
                break;
            case 'M':
                cout << "rend() selected.\n";
                break;
            case 'N':
                cout << "Using iterator rbegin() and rend() returns all elements in the list selected.\n";
                break;
            case 'O':
                cout << "erase(it) selected.\n";
                break;
            case 'P':
                cout << "erase(start_it,end_it) selected.\n";
                break;
            case 'Q':
                cout << "insert(it, entry) selected.\n";
                break;
            case 'R':
                cout << "swap() selected.\n";
                break;
            case 'S':
				cout << "Sort selected.\n";
                break;
            case '0':
                running = false;
				cout << "\n";
				system("pause");
                break;
            default:
                cout << "Invalid option. Please try again.\n";
				break;
        }
       
    }
}


void application()
{
    bool running = true;
    char option;
    while (running)
    {
        system("cls");
        cout << "\t3> Application using Vector and/or List container\n";
        cout << "\t" << string(105, char(205));
        cout << "\n\t\tA> Add an integer";
        cout << "\n\t\tB> Delete an integer";
        cout << "\n\t\tC> Display input integers";
        cout << "\n\t\tD> Display frequencies of integers";
        cout << "\n\t" << string(105, char(196));
        cout << "\n\t\t0> return";
        cout << "\n\t" << string(105, char(205));
        option = toupper(inputChar("\n\t\tOption: ", static_cast<string>("A,B,C,D,0")));
        switch (option)
        {
            case 'A':
                cout << "Add an integer selected.\n";
                break;
            case 'B':
                cout << "Delete an integer selected.\n";
                break;
            case 'C':
                cout << "Display input integers selected.\n";
                break;
            case 'D':
                cout << "Display frequencies of integers selected.\n";
                break;
            case '0':
                running = false;
                cout << "\n";
                system("pause");
                break;
            default:
                cout << "Invalid option. Please try again.\n";
                break;
        }
    }
}
