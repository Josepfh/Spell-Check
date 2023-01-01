 /*
    Main File
    In this file, two necessary functions and a main function is implemented.
 */
 #include "stringset.h"
 #include <iostream>
 #include <fstream>
 
 //Function declarations
 void loadStringset(Stringset& words, string filename);
 vector<string> spellcheck(const Stringset& words, string word);
 
 // Main function
 int main()
 {
     Stringset wordlist;
     loadStringset(wordlist,"wordlist.txt"); // A word list of choice can be put here.
     return 0;
 }
 /*
    Load String Set Function
    This function takes a string set object and a file name to read and store the data in a hash table.
 */
 void loadStringset(Stringset& words, string filename){
    fstream reader; // Create a reader object
    reader.open(filename); // Open the file
    string helper; 

    while(reader>>helper) { //As long as there is another word keep reading it into helper string
        words.insert(helper); //Insert the word into the stringset
    }
    reader.close(); //Close the file
 }
 /*
    Spell Check Function
    This function takes a string set object and a word for which alternatives are to be found and returns a vector of strings.
    This function works by changing every single letter of the given word and checking if the changed word is in the hash table.
 */
 vector<string> spellcheck(const Stringset& words, string word){
    vector<string> result_string; // Create a vector to return
    for(int i = 0; i < word.size();i++) { //For every letter in the word
        string temp_word = word; 
        for(char helper = word[i]; helper <= 'z'; helper++){ // for the ith char in the word check if the word, the char of which is replaced, is in the string set
            temp_word[i] = helper;
            if(words.find(temp_word) && temp_word != word) result_string.push_back(temp_word); // If found push it back to the vector.
        }
        for(char helper = 'a'; helper < word[i]; helper++){ // for the ith char in the word check if the word, the char of which is replaced, is in the string set
            temp_word[i] = helper;
            if(words.find(temp_word) && temp_word != word) result_string.push_back(temp_word);// If found push it back to the vector.
        }

    }
    return result_string; // Returning the vector of alternative words
 }