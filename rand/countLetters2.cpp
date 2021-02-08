#include <iostream>
using namespace std;
int find(string s, char c, int i) {
   while (i < s.length()) {
      if (s[i] == c) return i;
      i = i + 1;
   }
   return -1;
}
int countLetters(string str, char letter, int j) {
   int count = 0;
   int previous = find(str, letter, j);
   while (previous != -1) {
      previous = find(str, letter, previous + 1);
      count += 1;
   }
   return count;
}
int main() {
   char l;
   cout << "Letra: ";
   cin >> l;
   string s;
   cout << "Palavra: ";
   cin >> s;
   cout << "Começo: ";
   int j;
   cin >> j;
   cout << countLetters(s, l, j) << endl;
   return 0;
}
