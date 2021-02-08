#include <iostream>
using namespace std;
int main() {
   string word;
   cin >> word;
   int i = word.length() - 1;
   while (i >= 0) {
      cout << word[i];
      i -= 1;
   }
   cout << endl;
   return 0;
}
