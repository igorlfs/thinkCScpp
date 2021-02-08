#ifndef SET
#define SET
#include <string>
#include <vector>
using namespace std;
class Set {
   private:
    vector<string> elements;
    int numElements;

   public:
    Set(int n);
    int getNumElements() const;
    string getElement(int i) const;
    int find(const string& s) const;
    int add(const string& s);
};
#endif
