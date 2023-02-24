/*
 * Student: Dallas Roberts 
 * Class: CS204 c++
 * CornerGrocer.cpp
 *
 */

#include <iostream>
#include <fstream>
#include <map>
#include <string>

#include "ItemCounter.h"
#include "Menu.h"

int main() {
	// Create an instance of the Item class with the input file name "CS210_Project_Three_Input_File.txt"
	ItemCounter itemList;
	itemList.loadData("CS210_Project_Three_Input_File.txt");

	// Call the "WriteBackup" method with the file name "frequency.dat"
	itemList.backupData("frequency.dat");

	// Call the Menu::display method to start the menu loop, passing a pointer to the itemList object
	Menu::display(itemList);

	//return 0 to quit successfully
	return 0;
}