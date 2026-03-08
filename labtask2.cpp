#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
using namespace std;


// Function to check keyword
bool isKeyword(string word) {
    string keywords[] = {"int", "main", "return", "cout"};
    for (string k : keywords)
        if (word == k) return true;
    return false;
}

int main() {
    ifstream file("input.txt");
    string line, word;

    if (!file) {
        cout << "File not found!" << endl;
        return 1;
    }

    while (getline(file, line)) {
        stringstream ss(line);

        while (ss >> word) {

            // Keyword
            if (isKeyword(word))
                cout << word << " - Keyword" << endl;

            // Operator
            else if (word == "=" || word == "<<" || word == "+" || word == "-")
                cout << word << " - Operator" << endl;

            // Number
            else if (isdigit(word[0]))
                cout << word << " - Number" << endl;

            // String literal
            else if (word[0] == '"')
                cout << word << " - String" << endl;

            // Identifier
            else
                cout << word << " - Identifier" << endl;
        }

        // Check punctuation separately
        for (char ch : line) {
            if (ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == ';')
                cout << ch << " - Punctuation" << endl;
        }
    }

    file.close();
    return 0;
}
