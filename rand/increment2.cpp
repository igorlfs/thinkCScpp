#include <iostream>
using namespace std;
struct Time {
   int hour, minute;
   double second;
};
double convertToSeconds(const Time& t) {
   int minutes = t.hour * 60 + t.minute;
   double seconds = minutes * 60 + t.second;
   return seconds;
}
Time makeTime(double secs) {
   Time time;
   time.hour = int(secs / 3600.0);
   secs -= time.hour * 3600.0;
   time.minute = int(secs / 60.0);
   secs -= time.minute * 60;
   time.second = secs;
   return time;
}
Time increment(Time& time, double secs) {
   double seconds = convertToSeconds(time) + secs;
   return makeTime(seconds);
}
int main() {
   struct Time time;
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
   time = increment(time, s);
   cout << time.hour << ":" << time.minute << ":" << time.second << endl;
   return 0;
}
