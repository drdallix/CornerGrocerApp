/*
 * Student: Dallas Roberts
 * Class: CS204 c++
 * CornerGrocer.cpp
 *
 */

#include "Menu.h"


using namespace std;

int Menu::GetInput() {
    int choice = -1;
    string inputString;
    //loop through until the user selects a number from the menu list.
    do {
        try {
            // Get the user's choice from the console
            cout << endl << "Please enter your selection from the menu as a number and press enter: ";
            //uses getline and stoi to ensure that if the user enters nothing an error is output and user is prompted to try again
            getline(cin, inputString);
            choice = stoi(inputString);

            // if the input failed, was blank or the selection was not within the menu options prints out a reminder error message reminding the user what the right value should be.
            if (cin.fail() || choice > MAXCHOICE || choice < 1) {
                throw runtime_error("Invalid input: Please enter a number 1 - " + to_string(MAXCHOICE));
                }
        }

        catch (const exception& e) {
            // If there is an exception, inform the user to make an appropriate selection, and clear the input stream, then it pauses before taking input again from user.
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits < streamsize > ::max(), '\n');
            system("pause");
        }
    } while (choice < 1 || choice > MAXCHOICE);


    return choice;
}

// Static method to display the menu
void Menu::display(ItemCounter& item) {
    int choice = 0;
    // Loop until the user selects the "Exit program" option
    do {
        // Display the menu options
        cout << "======================== MAIN MENU ========================" << endl;
        cout << "1. Search for a specific item" << endl;
        cout << "2. Print a list with the frequency of all items" << endl;
        cout << "3. Print a histogram of the frequency of all items" << endl;
        cout << "4. Exit program" << endl;

        //take the user input
        choice = GetInput();

        //output 3 new lines to keep output looking nice
        cout << endl << endl << endl;

        // Call the appropriate method from the Item class based on the user's choice
        switch (choice) {
            case 1: {
                item.PrintSearchTerm();
                break;
            }
            case 2: {
                item.PrintFrequencyList();
                break;
            }
            case 3: {
                item.PrintHistogram();
                break;
            }
            case MAXCHOICE: {
                cout << "Thank you for using Corner Grocer's inventory tool. Good bye! ";
                system("Pause");
                return;
            }
        
        }
        

        //pause terminal between entries to keep everything feeling responsive and give user time to use the data on screen.
        system("pause");

    } while (choice != MAXCHOICE);
};