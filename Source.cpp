#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>
#include <stddef.h>

using namespace std;

string stringScramble(const string word) {
    if (word.length() <= 3) {

        return word;
    }

    string scrambled = word; 
    int pos1, pos2;

    do {
        pos1 = 1 + rand() % (word.length() - 2); 
        pos2 = 1 + rand() % (word.length() - 2); 
    } while (pos1 == pos2); 

    char temp = scrambled[pos1];
    scrambled[pos1] = scrambled[pos2];
    scrambled[pos2] = temp;

    return scrambled;
}

int main() {
    srand(time(0)); 

    string line;
    cout << "Enter a line of text: ";
    getline(cin, line);

    vector<string> words;
    size_t pos = 0;
    while ((pos = line.find(' ', pos)) != string::npos) {
        string word = line.substr(0, pos);
        cout << "*" << word << "*" << endl;
        words.push_back(word);
        line.erase(0, pos + 1); 
        pos = 0;
    }
    words.push_back(line);

    for (const string word : words) {
        string scrambledWord = stringScramble(word);
        cout << scrambledWord << " ";
    }
      
    cout << endl;
     
    return 0;
}