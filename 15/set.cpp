#include "set.hpp"

#include <iostream>
#include <vector>
using namespace std;
Set::Set(int n) {
    vector<string> temp(n);
    elements = temp;
    numElements = 0;
}
int Set::getNumElements() const { return numElements; }
string Set::getElement(int i) const {
    if (i < numElements) {
        return elements[i];
    } else {
        cout << "Set index out of range." << endl;
        exit(1);
    }
}
int Set::find(const string& s) const {
    for (int i = 0; i < numElements; i++) {
        if (elements[i] == s) return i;
    }
    return -1;
}
int Set::add(const string& s) {
    // if the element is already in the set, return its index
    int index = find(s);
    if (index != -1) return index;
    // if the vector is full, double its size
    if (numElements == elements.size()) {
        elements.resize(elements.size() * 2);
    }
    // add the new elements and return its index
    index = numElements;
    elements[index] = s;
    numElements++;
    return index;
}
