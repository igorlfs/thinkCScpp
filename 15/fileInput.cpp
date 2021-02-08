#include <fstream>
#include <iostream>
using namespace std;
int main() {
    string fileName = "steam";
    ifstream infile(fileName);
    if (infile.good() == false) {
        cout << "Unable to open file named " << fileName;
        exit(1);
    }
    string line;
    while (true) {
        getline(infile, line);
        if (infile.eof() == true) break;
        cout << line << endl;
    }
    return 0;
}
