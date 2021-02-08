#include <iostream>
using namespace std;
int main() {
   string suffix = "ack";
   char letter = 'J';
   while (letter <= 'Q') {
      if (letter == 'O' || letter == 'Q') {
         suffix = "uack";
      }
      cout << letter + suffix << endl;
      suffix = "ack";
      letter++;
   }
   return 0;
}
