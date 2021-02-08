#include <iostream>
using namespace std;
int countLetters(string str, char letter) {
   int length = str.length();
   int count = 0;
   int index = 0;
   while (index < length) {
      if (str[index] == letter) {
         count = count + 1;
      }
      index = index + 1;
   }
   return count;
}
int main() {
   string t;
   char l;
   cout << "Letra: ";
   getline(cin, t);
   l = t[0];
   string s;
   cout << "Palavra: ";
   getline(cin, s);
   cout << countLetters(s, l) << endl;
   return 0;
}
