#include <ctype.h>

#include <iostream>
using namespace std;
void stringtoUpper(string s) {
   for (int i = 0; i < s.length(); i++) {
      s[i] = toupper(s[i]);
   }
}
void stringToLower(string s) {
   for (int i = 0; i < s.length(); i++) {
      s[i] = tolower(s[i]);
   }
}
