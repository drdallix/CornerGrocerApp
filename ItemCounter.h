/*
 * Student: Dallas Roberts 
 * Class: CS204 c++
 * CornerGrocer.cpp
 *
 */
#pragma once
#ifndef ITEMCOUNTER_H
#define ITEMCOUNTER_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class ItemCounter {
private: 
	   const int WIDTH = 16;
	   map < string, int > itemMap;
	   string word;
	   string searchTerm;

	   string nCharString(int length, char character);
	   int searchItem(string searchTerm);
public: 
	  void loadData(string fileName);
	  void PrintFrequencyList();
	  void PrintHistogram();
	  void backupData(string fileName);
	  void PrintSearchTerm();
};

#endif // ITEMCOUNTER_H