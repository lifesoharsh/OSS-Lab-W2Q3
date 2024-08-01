#include <iostream>
#include <sstream>
#include <unordered_map>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;


string cleanWord(const string& word) {
    string cleaned;
    for (char ch : word) {
        if (isalpha(ch)) {
            cleaned += tolower(ch);
        }
    }
    return cleaned;
}

int main() {
    string paragraph;
    unordered_map<string, int> wordCount;
    cout << "Enter a paragraph: ";
    getline(cin, paragraph);


    stringstream ss(paragraph);
    string word;

    while (ss >> word) {
        word = cleanWord(word);
        if (!word.empty()) {
            wordCount[word]++;
        }
    }

    cout << "Word frequencies:\n";
    for (const auto& pair : wordCount) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}
