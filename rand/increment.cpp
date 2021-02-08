#include <iostream>
using namespace std;
struct Time {
   int hour, minute;
   double second;
};
typedef struct Time Tienpo;
void increment(Time& time, double secs) {
   time.second += secs;
   time.minute += (int)(time.second / 60.0);
   time.second = (int)time.second % 60;
   time.hour += time.minute / 60;
   time.minute %= 60;
}
int main() {
   Tienpo time;
   cin >> time.hour;
   if (cin.good() == false) {
      cout << "Erro inserindo hora\n";
      return -1;
   }
   cin >> time.minute;
   if (cin.good() == false) {
      cout << "Erro inserindo minuto\n";
      return -1;
   }
   cin >> time.second;
   if (cin.good() == false) {
      cout << "Erro inserindo segundos\n";
      return -1;
   }
   double s;
   cin >> s;
   if (cin.good() == false) {
      cout << "Erro inserindo incremento\n";
      return -1;
   }
   increment(time, s);
   cout << time.hour << ":" << time.minute << ":" << time.second << endl;
   return 0;
}
