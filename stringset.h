/*
    Class Declaration File
    String Set class is the class the wordlist is going to be stored in using a hash table.
*/
#pragma once

#include <string>
#include <vector>
#include <list>
#include <iostream>

using namespace std;

//Stringset class
class Stringset
{
    private:
        vector<list<string>> table; // The hash table using the chaining collusion resolution
        int num_elems; // Number of elements
        int size; // Size of the table
    public:
        Stringset(); // Default constructor
        vector<list<string>> getTable() const;
        int getNumElems() const;
        int getSize() const;
        void insert(string word);
        bool find(string word) const;
        void remove(string word);
        void printList();
};