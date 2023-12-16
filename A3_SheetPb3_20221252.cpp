// File name: A3_SheetPb3_20221252.cpp
// Purpose: counting the frequency of each word in a text file and print the word and its frequency
// Author(s): Israa Mohamed Elsayed Mohamed
// ID(s): 20221252
// Section: S1,2
// Date: 9/12/2023
#include <iostream>
using namespace std;
#include <cctype>
#include <sstream>
#include <map>
#include <fstream>
string Word_cleand(string w) {
    string done;
    for (char c: w) {
        if (isalnum(c) || c == '-')
            done += ::tolower(c);
    }
    return done;
}
int main() {
    cout << "enter the name of the file :\n";
    string name;
    cin>>name;
    ifstream inputFile(name);
    if (!inputFile) {
        cout << "Failed to open the file.\n";
    }
    map<string, int> frequency_table;
    string sentence;
    while (getline(inputFile, sentence)) {
        string word;
        istringstream iss(sentence);
        while (iss >> word) {
            string clean = Word_cleand(word);
            if (!clean.empty()) {
                if (clean[0] == '-') {
                    frequency_table[clean.substr(1)]++;
                } else if (clean[clean.length() - 1] == '-') {
                    frequency_table[clean.substr(0, clean.length() - 1)]++;
                } else
                    frequency_table[clean]++;
            }


        }
    }

    inputFile.close();
    for (auto val:frequency_table){
        cout<<"word: "<<val.first<<" ---> "<<val.second<<"\n";
    }


}