#include <iostream>
#include <vector>
using namespace std;
static const int upperBound = 10;
static const int numValues = 20;
vector<int> randomVector(int n, int upperBound) {
   vector<int> vec(n);
   for (int i = 0; i < vec.size(); i++) {
      vec[i] = random() % upperBound;
   }
   return vec;
}
void printVector(const vector<int>& vec) {
   for (int i = 0; i < vec.size(); i++) {
      cout << vec[i] << " ";
   }
   cout << endl;
}
int main() {
   vector<int> vector = randomVector(numValues, upperBound);
   printVector(vector);
   return 0;
}
