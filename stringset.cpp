/*
    Class Implementation File
    In this file the functions for the hash table class, StringSet, is implemented.
*/
#include "stringset.h"

//Default constructor that creates a table of size 4 and initilizes the variables accordingly.
Stringset::Stringset() : table(4), num_elems(0), size(4) {}

hash<string> hash_funct;// The built in hash function for strings is used.

//Used in test cases
vector<list<string>> Stringset::getTable() const
{
    return table;
}

//Used in test cases
int Stringset::getNumElems() const
{
    return num_elems;
}

//Used in test cases
int Stringset::getSize() const
{
    return size;
}
/* 
    The insertion function
    Takes a string as an input and inserts it into the hash table using the hash function declared above
    If the number of elements in the table exceeds the size of the table, a new table of double the 
    original size is created and the elements are inserted in the new table.
    Runtime complexity: O(1) if the size has not been reached, O(n) otherwise.
*/
void Stringset::insert(string word)
{
    if(find(word) == true) {} // If the word is already in the table don't add it
    else if(num_elems == size) {
        size = size*2; // The new size is two times the size before.
        vector<string> data; // A new vector to keep track of the elements in the list
        for(int i = 0; i < table.size();i++){ 
            for(list<string>::const_iterator it = table[i].begin(); it != table[i].end();it++){ // For every item in the list
                data.push_back(*it);
            }
        }
        table.clear(); // Clearing the table
        table.resize(size); // Resizing the table
        num_elems = 0; 
        for(int i = 0; i < data.size();i++){
            insert(data[i]); // Inserting every element back into the table.
        }
        insert(word); // Inserting the last word
        
    }
    else {
        int index = hash_funct(word) % size; // Hash the word and get the relevant index
        table[index].push_front(word); // Push the word into the table
        num_elems++;
    }
}
/*
    Find Function
    This function is used to find a string taken as a parameter in the hash table.
    The function finds the index to look for the string by hashing the string first.
    If the table is empty returns 0, if the word is not in the table returns false.
    Runtime complexity : O(n) n being the size of the list in the relevant index.
*/
bool Stringset::find(string word) const
{
    //If the table is empty return false.
    if(num_elems == 0) {
        return false;
    }
    else {
        int index_to_look = hash_funct(word) % size; // Hash the word to find the index to look
        for(list<string>::const_iterator it = table[index_to_look].cbegin(); it != table[index_to_look].cend();it++) {
            string tester = *it;
            if(tester == word){ // If a match is found return true
                return true;
            }
        }
        return false; // If the word is not in the table return false.
    }
}
/*
    Remove Function
    This function takes a string as a parameter to remove the given string.
    This function finds the index to look by hashing the string and removing the word if found.
    If the table is empty the function returns 0, if a match is not found nothing is done. 
    Runtime complexity: O(n) n being the size of the list in the relevant index.
*/
void Stringset::remove(string word)
{
    // If the table is empty, the function does not do anything.
    if(num_elems == 0) {}
    else {
        int index_to_look = hash_funct(word) % size; // Hash it to get the index to look for
        for(list<string>::const_iterator it = table[index_to_look].cbegin(); it != table[index_to_look].cend();it++) { 
            string tester = *it;
            if(tester == word){ // If a match is found erase it and end the loop
                table[index_to_look].erase(it);
                it = table[index_to_look].cend(); // The iterator is set to the last element of the list to end the loop.
                num_elems--;
            }
        }
    }
}
