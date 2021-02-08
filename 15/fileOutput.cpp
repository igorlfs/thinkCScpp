#include <fstream>
#include <iostream>
using namespace std;
int main() {
    ifstream infile("steam");
    ofstream outfile("test");
    if (infile.good() == false || outfile.good() == false) {
        cout << "Unable to open one of the files" << endl;
        exit(1);
    }
    string line;
    while (true) {
        getline(infile, line);
        if (infile.eof() == true) break;
        outfile << line << endl;
    }
    return 0;
}
