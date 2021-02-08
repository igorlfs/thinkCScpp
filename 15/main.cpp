#include <fstream>
#include <iostream>
#include <vector>

#include "set.hpp"
using namespace std;
int distances[50][50];
int find(string s, char c, int i) {
    int l = s.length();
    while (i < l) {
        if (s[i] == c) return i;
        i = i + 1;
    }
    return -1;
}
int convertToInt(const string& s) {
    string digitString = "";
    int l = s.length();
    for (int i = 0; i < l; i++) {
        if (isdigit(s[i])) {
            digitString += s[i];
        }
    }
    return atoi(digitString.c_str());
}
void processLine(const string& line, Set* cities) {
    // the character we are looking for is a quotation mark
    char quote = '\"';
    // store the indices of the quotation marks in a vector
    vector<int> quoteIndex(4);
    // find the first quotation mark using the built-in find
    quoteIndex[0] = line.find(quote);
    // find the other quotation marks using the find from Chapter 7
    for (int i = 1; i < 4; i++) {
        quoteIndex[i] = find(line, quote, quoteIndex[i - 1] + 1);
    }
    // break the line up into substrings
    int len1 = quoteIndex[1] - quoteIndex[0] - 1;
    string city1 = line.substr(quoteIndex[0] + 1, len1);
    int len2 = quoteIndex[3] - quoteIndex[2] - 1;
    string city2 = line.substr(quoteIndex[2] + 1, len2);
    int len3 = line.length() - quoteIndex[2] - 1;
    string distString = line.substr(quoteIndex[3] + 1, len3);
    int dist = convertToInt(distString);
    int index1 = cities->add(city1);
    int index2 = cities->add(city2);
    distances[index1][index2] = dist;
    distances[index2][index1] = dist;
}
int main() {
    string fileName = "cities";
    ifstream infile(fileName);
    if (infile.good() == false) {
        cout << "Unable to open file" << endl;
        exit(1);
    }
    string line;
    Set cities(2);
    while (true) {
        getline(infile, line);
        if (infile.eof() == true) break;
        processLine(line, &cities);
    }
    for (int i = 0; i < cities.getNumElements(); i++) {
        cout << cities.getElement(i) << "\t";
        for (int j = 0; j <= i; j++) {
            cout << distances[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "\t";
    for (int i = 0; i < cities.getNumElements(); i++) {
        cout << cities.getElement(i) << "\t";
    }
    cout << endl;
    return 0;
}
