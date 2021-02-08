#include <cstdlib>
#include <iostream>
#include <vector>
static const int upperBound = 10;
static const int numValues = 20;
using namespace std;
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
vector<int> histogram(vector<int>& vec, int bot, int top) {
   vector<int> histogram(upperBound, 0);
   for (int i = bot; i < top; i++) {
      int index = vec[i];
      histogram[index]++;
   }
   for (int i = 0; i < upperBound; i++) {
      cout << histogram[i] << endl;
   }
   return histogram;
}
int main() {
   vector<int> array = randomVector(numValues, upperBound);
   int bot = 5;
   int top = 8;
   histogram(array, bot, top);
   return 0;
}
