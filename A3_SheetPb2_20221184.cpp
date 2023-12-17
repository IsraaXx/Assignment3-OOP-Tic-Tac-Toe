// File name: A3_SheetPb2_20221184.cpp.
// Purpose: problem 2 assignment 3, Document Similarity.
// Author: Nour Ahmed Abd El Aziz.
// ID: 20221184.
// Section: S1.
//======================================================================================================================
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;


// To remove all punctuations and let the characters only.
string removePunctuation(string& str) {
    string result;
    for (char c : str) {
        if (isalpha(c) || isspace(c)) {
            result.push_back(c);
        }
    }
    return result;
}

// To transform all characters to lower case.
string lowercase(const string& str) {
    string result;
    for (char c : str) {
        result.push_back(tolower(c));
    }
    return result;
}


// To check if the string is a file name or not.
bool isFile (string &fileName) {
    fstream File(fileName);
    return (File.is_open());
}



class StringSet {
private:
    vector <string> set;
    bool contains(const string& word) {
        return find(set.begin(), set.end(), word) != set.end();
    }
public:
    StringSet(string str) {
        if (isFile(str)) {
            ifstream file(str);
            string word, line;
            /*while (file >> word) {
                word = lowercase(removePunctuation(word));
                if (!word.empty()) {
                    set.push_back(word);
                }
            }*/
            while (!file.eof()) {
                getline(file, line);
                istringstream iss(line);
                while (iss.good()) {
                    iss >> word;
                    word = lowercase(removePunctuation(word));
                    set.push_back(word);
                    /*if (!word.empty()) {
                        set.push_back(word);
                    }*/
                }
            }
        }
        else {
            stringstream ss(str);
            string word;
            while (ss >> word) {
                word = lowercase(removePunctuation(word));
                if (!word.empty()) {
                    set.push_back(word);
                }
            }
        }
    }
    void add(string word);
    bool remove(string word);
    void clear();
    void count();
    void print();
};

//======================================================================================================================
void StringSet :: add(string word) {
    word = lowercase(removePunctuation(word));
    if (!contains(word)) {
        set.push_back(word);
    }
}


bool StringSet :: remove(string word) {
    word = lowercase(removePunctuation(word));
    auto it = find(set.begin(), set.end(), word);
    if (it != set.end()) {
        set.erase(it);
        return true;
    }
    return false;
}


void StringSet :: clear() {
    set.clear();
}


void StringSet :: count() {
    cout << "The size of the set of strings = " << set.size() << "\n\n";
}


void StringSet :: print() {
    for (auto & i : set)
        cout << i << ' ';
    cout << endl;
}


//======================================================================================================================
int main() {
    cout << "This is the 1st set of string.\n";
    StringSet set1("Chocolate ice cream, chocolate milk, and chocolate bars are delicious.");
    set1.count();

    set1.remove("milk");
    set1.count();

    set1.add("too");
    set1.add("Much");

    set1.print();
    set1.count();

    set1.clear();

    set1.count();
    set1.print();


    cout << "This is the 2nd set of string.\n";
    StringSet set2("TestFile"s);
    set1.count();

    set1.remove("chocolate milk");
    set1.count();

    set1.add("chocolate bars");

    set1.print();
    set1.count();

    set1.clear();

    set1.count();
    set1.print();

    return 0;
}

