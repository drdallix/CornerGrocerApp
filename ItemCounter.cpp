/*
 * Student: Dallas Roberts
 * Class: CS204 c++
 * CornerGrocer.cpp
 *
 */#include "ItemCounter.h"

using namespace std;
//intilize private variables
map < string, int > itemMap;


/*
 *Loads data from the input filename to the itemMap
 *@param string fileName | takes in the name of the file as a string
 */
void ItemCounter::loadData(string fileName) {
    try {
        // Open input file stream
        ifstream inputFile(fileName);
        // String to hold each input line
        string inputString;

        // Load data from file into the map
        while (inputFile >> inputString) {
            // Increment the value if the item is already in the map
            itemMap[inputString]++;
        }
        // Close the input stream
        inputFile.close();
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        cout << "Unable to open or read from input file: " << fileName << endl;
    }
}


/*
 * @param Item that is being searched for
 * @return int -1 if not found | int value of the frequency of the searchTerm from the file.
 * @return 
 */
int ItemCounter::searchItem(string searchTerm) {
    // Check if the item exists in the map, returns the frequency from the itemMap
    if (itemMap.count(searchTerm) > 0) {

        return itemMap[searchTerm];
    }
    // if the item was not found, returns the string "Not Found"
    else {
        return -1;
    }
}

/*
 *Prints out a list of the items in alphabetical order and with their frequency.
 */
void ItemCounter::PrintFrequencyList() {
    // output a header for the list
    cout << "List of items and their frequency: " << endl;
    int i = 0;
    // use an auto iterator to go through the itemMap for each key and value
    for (auto it = itemMap.begin(); it != itemMap.end(); ++it) {
        i++;
        // iterate through preset colors
        int color = 31 + (i) % 6;
        // set the foreground color to the random number
        cout << "\033[" << color << "m";

        //calculate the right number of spaces so that all the numbers output together
        int numSpaces = WIDTH - it->first.length();
        //output the name followed by the right number of spaces to set the numbers to all start at the same point
        cout << it->first << " " << nCharString(numSpaces - 1, '=') << ">" << it->second << endl;
    }
    //set foreground color to default after List
    cout << "\033[0m";
    //output 3 new lines to keep output looking nice
    cout << endl << endl << endl;
}

/*
 * Function to print out a frequency histogram of the items in the itemMap dictionary
 */
void ItemCounter::PrintHistogram() {
    // Print a header for the histogram
    cout << "Histogram of items and their frequency: " << endl;

    // use an auto iterator to go through the itemMap for each key and value
    for (auto it = itemMap.begin(); it != itemMap.end(); ++it) {
        // output the name of the item followed by a space
        int numSpaces = WIDTH - it->first.length();

        //output the name followed by the right number of spaces to set the histogram to all start at the same point
        cout << it->first;
        cout << nCharString(numSpaces, ' ');

        // Print a number of asterisks equal to the frequency of the item
        for (int i = 0; i < it->second; i++) {
            // iterate through preset colors
            int color = 31 + (i) % 6;
            // set the foreground color to the random number
            cout << "\033[" << color << "m";
            cout << "*";
        }

        //set foreground color to default after histogram
        cout << "\033[0m";
        cout << endl;
        
    }
    //output 3 new lines to keep output looking nice
    cout << endl << endl << endl;
}
/*
 * Interactive search for item in list. Outputs the item and frequency or the appropriate error message.
 */
void ItemCounter::PrintSearchTerm() {
    try {
        // Prompt user to enter item to search for
        cout << "Enter item to search for: ";
        // Get line ensures that even if they enter something like "Peanut butter"
        // the extra word is searched for rather than being used as the next input.
        cin >> searchTerm;

        // Capitalize first letter to help users if they don't capitalize.
        searchTerm[0] = toupper(searchTerm[0]);

        // Clears the input if the user inputs more than one word.
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Uses searchItem method to output the total found or an error message if it wasn't found.
        if (searchItem(searchTerm) != -1) {
            cout << endl << endl << "The frequency of '" << searchTerm << "' is: " << searchItem(searchTerm) << endl;
        }
        else {
            cout << endl << endl << "Sorry but the search term '" << searchTerm << "' is not found." << endl;
        }
    }
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
    }
    //output 3 new lines to keep output looking nice
    cout << endl << endl << endl;
}

/*
 *@param string fileName | This should be the name of the backup file to save
 */
void ItemCounter::backupData(string fileName) {
    try {
        // Open output file stream
        ofstream outputFile(fileName);
        // Loop through data and save the name of the item and the frequency
        // on a separate line for each unique item in the map
        for (const auto& item : itemMap) {
            const auto& word = item.first;
            const auto& frequency = item.second;
            outputFile << word << " " << frequency << endl;
        }
        // Close the output stream
        outputFile.close();
    }
    //output an error message if there is a problem saving the backup file.
    catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        cout << "Unable to write to output file: " << fileName << endl;
    }
}


/* private method for making a string of the specified characterand length
 * @param int length takes length for charaters as an integer
 * @param char character takes the charater to generate the length of
 */
string ItemCounter::nCharString(int length, char character) {
    // Create an empty string
    string result = "";

    // use a for loop to add character until you hit the specified length
    for (int i = 0; i < length; i++) {
        result += character;
    }

    // Return the new string
    return result;
}