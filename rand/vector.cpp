#include <iostream>
#include <vector>
using namespace std;
int main() {
   vector<int> array(4, 0);
   int size = array.size();
   for (int i = 0; i < size; i++) {
      cout << array[i] << endl;
   }
   return 0;
}
