//Name: Hany, Aleeza, and Thanh
// Date: 10/05/2026
// Description: Module 5 - Linked List 

#include <iostream>
#include <iomanip>
#include "input.h"
#include "VectorContainer.h"
#include "ListContainer.h"
#include "Application.h"    

using namespace std;
// Function prototypes
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

//precondition: none
//postcondition: Displays the main menu options and prompts the user to select an option. Returns the selected option as a character.
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

//precondition: none
//postcondition: Displays the vector container menu and allows the user to perform various operations on a VectorContainer object. The user can choose from options such as clearing the vector, reserving capacity, resizing, reading from a file, adding/removing elements, accessing elements, iterating through the vector, erasing elements, inserting new entries, swapping contents with another vector, and sorting the vector. The function continues to display the menu until the user chooses to return to the main menu.
void vectorContainer() 
{
	bool running = true;
	char option;
    const int ONE = 1, ZERO = 0;

	VectorContainer numbers; // Create an instance of VectorContainer to store Record objects
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
			numbers.clear(); // Clear the vector
            cout << "\n\tThe vector has been cleared.\n\n";
            system("pause");
            break;
        }
        case 'B':
        {
            int capacity = inputInteger("\n\t\tEnter the capacity(1..100): ", 1, 100);
			numbers.reserve(capacity); // Reserve capacity for the vector
            cout << "\n\t\tThe vector has been reserved " << capacity << " elements.\n\n";
            system("pause");
            break;
        }
        case 'C':
        {
            int newSize = inputInteger("\n\t\tEnter the new size(1..100): ", 1, 100);
			numbers.resize(newSize); // Resize the vector to the new size
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
                numbers.display(); // Display the vector
                cout << "\n";
            }
            system("pause");
            break;
        }


        case 'E':
        {
            if (numbers.empty())
            {
                cout << "\n\tThe vector is empty.";
            }
            else
            {
                int index = numbers.size() - ONE;
                Record removed = numbers.back(); // Get the last element
                numbers.popBack(); // Remove the last element
				// Display the removed element and its index
                cout << "\n\tElement, [" << index << "]: " << removed.first << ' ' << removed.second << ' ' << removed.number << ", has been removed from the vector.";
				numbers.display(); // Display the updated vector
            }

            cout << "\n\n";
            system("pause");
            break;
        }
        case 'F':
        {
            if (numbers.empty())
            {
                cout << "\n\tThe vector is empty.";
            }
            else
            {
				Record first = numbers.front(); // Get the first element
				int index = 0;
				// Display the first element and its index
				cout << "\n\tThe element from the front of the vector: [" << index << "] " << first.first << ' ' << first.second << ' ' << first.number;
            }
            cout << "\n\n";
            system("pause");
			break;
        } 
        case 'G':
        {
            if (numbers.empty())
            {
                cout << "\n\tThe vector is empty.";
            }
            else
            {
				Record last = numbers.back(); // Get the last element
				int index = numbers.size() - ONE; // Calculate the index of the last element
				// Display the last element and its index
                cout << "\n\tThe element from the back of the vector: [" << index << "] " << last.first << ' ' << last.second << ' ' << last.number;
            }
            cout << "\n\n";
			system("pause");
            break;
		}

        case 'H':
        {
            if (numbers.empty())
            {
                cout << "\n\tThe vector is empty.";
            }
            else
            {
                int index = inputInteger("\n\tEnter the index(0.." + to_string(numbers.size() - ONE) + "): ", ZERO, numbers.size() - ONE);
				Record recordAt = numbers.at(index); // Get the element at the specified index using at()
				Record recordBracket = numbers[index]; // Get the element at the specified index using operator[]
				// Display the elements retrieved using both methods
                cout << "\n\t\tvector.at(" << index << "): " << recordAt.first << ' ' << recordAt.second << ' ' << recordAt.number;
				// Display the element retrieved using operator[]
                cout << "\n\t\tvector[" << index << "]: " << recordBracket.first << ' ' << recordBracket.second << ' ' << recordBracket.number;
            }
            cout << "\n\n";
            system("pause");
            break;
        }
        case 'I':
        {
            if (numbers.empty())
            {
                cout << "\n\tThe vector is empty.";
            }
            else
            {
                cout << "\n\tThe iterator referring the first element: ";
				numbers.displayBegin(); // Display the iterator referring to the first element
            }
            cout << "\n\n";
            system("pause");
            break;
        }

        case 'J':
        {
            if (numbers.empty())
            {
                cout << "\n\tThe vector is empty.";
            }
            else
            {
                cout << "\n\tThe iterator referring to the past-the-end element: ";
				numbers.displayEnd(); // Display the iterator referring to the past-the-end element
                
			}
            cout << "\n\n";
            system("pause");
            break;
        }
        case 'K':
        {
            if (numbers.empty())
            {
                cout << "\n\tThe vector is empty.";
            }
            else
            {
                cout << "\n\tUsing begin() and end(), the vector contains:";
				numbers.displayForward(); // Display all elements in the vector using begin() and end()
            }
            cout << "\n\n";
            system("pause");
            break;
        }
        case 'L':
        {
            if (numbers.empty())
            {
                cout << "\n\tThe vector is empty.";
            }
            else
            {
                cout << "\n\tThe reverse iterator pointing to the last element: ";
				numbers.displayRBegin(); // Display the reverse iterator pointing to the last element
            }
            cout << "\n\n";
            system("pause");
            break;
        }
        case 'M':
        {
            if (numbers.empty())
            {
                cout << "\n\tThe vector is empty.\n";
            }
            else
            {
                cout << "\n\tThe reverse iterator pointing to the theoretical element preceding " << "the first element in the vector: ";
				numbers.displayREnd(); // Display the reverse iterator pointing to the theoretical element preceding the first element
            }
            cout << "\n\n";
            system("pause");
            break;
        }
        case 'N':
        {
            if (numbers.empty())
            {
                cout << "\n\tThe vector is empty.\n";
            }
            else
            {
                cout << "\n\tUsing rbegin() and rend(), the vector contains reversed elements:";
				numbers.displayReverse(); // Display all elements in the vector in reverse order using rbegin() and rend()
                cout << "\n";
            }

            cout << "\n";
            system("pause");
            break;
        }
        case 'O':
        {
            if (numbers.empty())
            {
                cout << "\n\tThe vector is empty.\n";
            }
            else if (numbers.size() > 1)
            {
				const void* address = numbers.getAddress(1); // Get the address of the element after the begin iterator

                cout << "\n\tAn element after the begin iterator " << address << " has been removed.";
				numbers.erase(1); // Remove the element after the begin iterator
            }
            else
            {
                cout << "\n\tThere is no element after the begin iterator.";
            }
            cout << "\n\n";
            system("pause");
            break;
        }

        case 'P':
        {
			numbers.erase(0, numbers.size()); // Remove all elements from the vector
            cout << "\n\n";
            system("pause");
            break;
        }
        case 'Q':
        {
			string name; // Declare a string variable to store the student's name 
			string level; // Declare a string variable to store the student's level
			int levelNumber; // Declare an integer variable to store the student's level number
			double gpa; // Declare a double variable to store the student's GPA
            if (numbers.empty())
            {
                cout << "\n\tThe vector is empty.\n";
            }
            else
            {

                name = inputString("\n\tEnter a new student name: ", true);
				//name += ","; // Append a comma to the name

                levelNumber = inputInteger("\tEnter the his/her level (1-Freshman, 2-Sophmore, 3-Junior, or 4-Senior): ", 1, 4);
				// Use a switch statement to determine the student's level based on the level number
                switch (levelNumber)
                {
                case 1:
                    level = "Freshman";
                    break;
                case 2:
                    level = "Sophmore";
                    break;
                case 3:
                    level = "Junior";
                    break;
                case 4:
                    level = "Senior";
                    break;
                }
				// Prompt the user to enter the student's GPA and validate it within the range of 0.0 to 4.0
                gpa = inputDouble("\tEnter his/her GPA (0.0..4.0): ", 0.0, 4.0);
                Record entry(name, level, gpa);
				numbers.insert(1, entry); // Insert the new student record after the begin iterator (at index 1)
                cout << "\n\tThe new element has been inserted after the begin iterator.";
            }
            cout << "\n\n";
            system("pause");
            break;
        }
        case 'R':
        {
			VectorContainer v2; // Create a new VectorContainer object v2
            cout << "\n\tvector (v2) is initially empty.";
			numbers.swap(v2); // Swap the contents of vector (v1) with vector (v2)
            cout << "\n\n\tvector (v1) is empty after swapped with vector (v2).";
            cout << "\n\n\tvector (v2) after swapped with vector (v1).";
            if (v2.empty())
            {
                cout << "\n\tThe vector (v2) is empty.";
            }
            else
            {
				v2.displaySwap(); // Display the contents of vector (v2) after the swap
			}
            cout << "\n\n";
            system("pause");
            break;
        }
        case 'S':
        {
            if (numbers.empty())
            {
                cout << "\n\tThe vector is empty.";
            }
            else
            {
				numbers.sort(); // Sort the vector using selection sort
				numbers.displaySwap(); // Display the sorted vector
            }

            cout << "\n\n";
            system("pause");
            break;
        }

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

//precondition: none
//postcondition: Displays the list container menu and allows the user to perform various operations on a ListContainer object. The user can choose from options such as clearing the list, resizing, reading from a file, adding/removing elements, accessing elements, iterating through the list, erasing elements, inserting new entries, swapping contents with another list, and sorting the list. The function continues to display the menu until the user chooses to return to the main menu.
void listContainer()
{
    bool running = true;
    char option;
	ListContainer records; // Create an instance of ListContainer to store Record objects

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
        cout << "\n\t\tI> begin() - Returns an iterator referring to the first element in the list";
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
        {
            records.clear();
            cout << "\n\tThe list has been cleared.\n\n";
            system("pause");
            break;
        }
        case 'B':
        {
			// Prompt the user to enter the new size for the list
            int newSize = inputInteger("\n\tEnter the new size(1..100): ", 1, 100);
			records.resize(newSize); // Resize the list to the new size
            cout << "\n\tThe list has been resized to " << newSize << " elements.\n\n";
            system("pause");
            break;
        }
        case 'C':
        {
			// Read the input file and add each Record to the front of the list
            string fileName = "INPUT.DAT";
            if (!records.readFileFront(fileName))
            {
                cout << "\n\tThe input file, " << fileName << ", does not exist.\n\n";
            }
            else
            {
                records.display();
                cout << "\n";
            }
            system("pause");
            break;
        }
        case 'D':
        {
			// Remove the first element from the list
            if (records.empty())
            {
                cout << "\n\tThe list is empty.";
            }
            else
            {
                Record removed = records.front();
                records.popFront();
                cout << "\n\tFirst element, (";
                records.displayRecord(removed);
                cout << "), has been removed from the list.\n";
                records.display();
            }
            cout << "\n";
            system("pause");
            break;
        }
        case 'E':
        {
			// Access the first element from the list
            if (records.empty())
            {
                cout << "\n\tThe list is empty.";
            }
            else
            {
                Record first = records.front();
                cout << "\n\tFirst element from the list is (";
				records.displayRecord(first); // Display the first element
                cout << ").";
            }
            cout << "\n\n";
            system("pause");
            break;
        }
        case 'F':
        {
			// Read the input file and add each Record to the back of the list
            string fileName = "INPUT.DAT";
            if (!records.readFileBack(fileName))
            {
                cout << "\n\tThe input file, " << fileName << ", does not exist.\n\n";
            }
            else
            {
                records.display();
                cout << "\n";
            }
            system("pause");
            break;
        }
        case 'G':
        {
			// Remove the last element from the list
            if (records.empty())
            {
                cout << "\n\tThe list is empty.";
            }
            else
            {
                Record removed = records.back();
                records.popBack();
                cout << "\n\tLast element, (";
                records.displayRecord(removed);
                cout << "), has been removed from the list.\n";
                records.display();
            }
            cout << "\n";
            system("pause");
            break;
        }
        case 'H':
        {
			// Access the last element from the list
            if (records.empty())
            {
                cout << "\n\tThe list is empty.";
            }
            else
            {
                Record last = records.back();
                cout << "\n\tLast element from the list is (";
                records.displayRecord(last);
                cout << ").";
            }
            cout << "\n\n";
            system("pause");
            break;
        }
        case 'I':
        {
			// Access the first element from the list using an iterator
            if (records.empty())
            {
                cout << "\n\tThe list is empty.";
            }
            else
            {
                cout << "\n\tThe iterator referring the first element: ";
                records.displayBegin();
            }
            cout << "\n\n";
            system("pause");
            break;
        }
        case 'J':
        {
			// Access the past-the-end element from the list using an iterator
            if (records.empty())
            {
                cout << "\n\tThe list is empty.";
            }
            else
            {
                cout << "\n\tThe iterator referring to the past-the-end element: ";
                records.displayEnd();
            }
            cout << "\n\n";
            system("pause");
            break;
        }
        case 'K':
        {
			// Display all elements in the list using begin() and end() iterators
            if (records.empty())
            {
                cout << "\n\tThe list is empty.";
            }
            else
            {
                cout << "\n\tUsing begin() and end(), the list contains:";
                records.displayForward();
            }
            cout << "\n\n";
            system("pause");
            break;
        }
        case 'L':
        {
			// Access the last element from the list using a reverse iterator
            if (records.empty())
            {
                cout << "\n\tThe list is empty.";
            }
            else
            {
                cout << "\n\tThe iterator referring the reverse first element: ";
                records.displayRBegin();
            }
            cout << "\n\n";
            system("pause");
            break;
        }
        case 'M':
        {
			// Access the theoretical element preceding the first element from the list using a reverse iterator
            if (records.empty())
            {
                cout << "\n\tThe list is empty.";
            }
            else
            {
                cout << "\n\tThe iterator referring to the reverse past-the-end element: ";
                records.displayREnd();
            }
            cout << "\n\n";
            system("pause");
            break;
        }
        case 'N':
        {
			// Display all elements in the list in reverse order using rbegin() and rend() iterators
            if (records.empty())
            {
                cout << "\n\tThe list is empty.";
            }
            else
            {
                cout << "\n\tUsing rbegin() and rend(), the list contains:";
                records.displayReverse();
            }
            cout << "\n\n";
            system("pause");
            break;
        }
        case 'O':
        {
			// Remove the element after the begin iterator from the list
            if (records.empty())
            {
                cout << "\n\tThe list is empty.";
            }
            else if (records.size() > 1)
            {
                cout << "\n\tAn element after the begin iterator " << records.getBeginAddress() << " has been removed.";
                records.eraseAfterBegin();
            }
            else
            {
                cout << "\n\tThere is no element after the begin iterator.";
            }
            cout << "\n\n";
            system("pause");
            break;
        }
        case 'P':
        {
			// Remove all elements from the list
            if (records.empty())
            {
                cout << "\n\tThe list is empty.";
            }
            else
            {
                records.eraseAll();
            }
            cout << "\n\n";
            system("pause");
            break;
        }
        case 'Q':
        {
			// Prompt the user to enter a new student record and insert it after the begin iterator in the list
            string name;
            string level;
            int levelNumber;
            double gpa;

            name = inputString("\n\tEnter a new student name: ", true);
            //name += ",";
            levelNumber = inputInteger("\tEnter the his/her level (1-Freshman, 2-Sophmore, 3-Junior, or 4-Senior): ", 1, 4);
            switch (levelNumber)
            {
            case 1:
                level = "Freshman";
                break;
            case 2:
                level = "Sophmore";
                break;
            case 3:
                level = "Junior";
                break;
            case 4:
                level = "Senior";
                break;
            }

            gpa = inputDouble("\tEnter his/her GPA (0.0..4.0): ", 0.0, 4.0);
            Record entry(name, level, static_cast<int>(gpa));
            records.insertAfterBegin(entry);
           // cout << "\n\tThe new element has been inserted after the begin iterator.";
			cout << "\n\tThe new element has been inserted at the begin iterator.";
            cout << "\n\n";
            system("pause");
            break;
        }
        case 'R':
        {
			// Swap the contents of the list with another ListContainer's contents of the same type
            ListContainer l2;
            cout << "\n\tlist (l2) is initially empty.";
            records.swap(l2);
            cout << "\n\n\tlist (l1) is empty after swapped with list (l2).";
            cout << "\n\n\tlist (l2) now has " << l2.size() << " element(s).";
            cout << "\n\n";
            system("pause");
            break;
        }
        case 'S':
        {
			// Sort the list in ascending order based on the number field of the Record objects
            if (records.empty())
            {
                cout << "\n\tThe list is empty.";
            }
            else
            {
                records.sort();
                records.display();
            }
            cout << "\n\n";
            system("pause");
            break;
        }
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

//precondition: none
//postcondition: Displays the application menu and allows the user to perform various operations on an Application object that manages integers. The user can choose from options such as adding an integer, deleting an integer, displaying input integers, and displaying frequencies of integers.
void application()
{
    bool running = true;
    char option;
	Application numbers; // Create an Application object to manage integers
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
        {
			int number = inputInteger("\n\t\tAdd an integer: ", 0, 100); // Prompt the user to enter an integer between 0 and 100
			numbers.add(number); // Add the entered integer to the Application object
			cout << "\n\t\t" << number << " has been added to the vector.\n\n";
            system("pause");
            break;
        }
        case 'B':
        {
			// Check if the vector is empty before attempting to delete an integer
            if (numbers.empty())
            {
                cout << "\n\t\tVector is empty.";
            }
            else
            {
				int number = inputInteger("\n\t\tDelete an integer: ", 0, 100); // Prompt the user to enter an integer between 0 and 100 to delete
				// Attempt to remove the entered integer from the Application object
                if (!numbers.remove(number))
                {
                    cout << "\n\t\tVector does not contain " << number << ".";
                }
                else
                {
                    cout << "\n\t\t" << number << " has been removed from the vector.";
				}
            }
            cout << "\n\n";
            system("pause");
            break;
        }

        case 'C':
        {
			numbers.display(); // Display the input integers stored in the Application object
            cout << "\n\n";
            system("pause");
            break;
        }
        case 'D':
        {
			numbers.displayFrequencies(); // Display the frequencies of integers stored in the Application object
            cout << "\n\n";
            system("pause");
            break;
        }
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
