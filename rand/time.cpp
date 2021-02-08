#include <iostream>
using namespace std;
struct Time {
   int hour, minute;
   double second;
   void print();
   void increment(double secs);
   double convertToSeconds() const;
   bool after(const Time& time2) const;
   Time(double secs);
   Time(int h, int m, double s);
};
void Time::print() {
   Time time = *this;
   cout << hour << ":" << minute << ":" << second << endl;
}
void Time::increment(double secs) {
   second += secs;
   minute += (int)(second / 60.0);
   second = (int)second % 60;
   hour += minute / 60;
   minute %= 60;
}
double Time::convertToSeconds() const {
   int minutes = hour * 60 + minute;
   double seconds = minutes * 60 + second;
   return seconds;
}
bool Time::after(const Time& time2) const {
   if (hour > time2.hour) return true;
   if (hour < time2.hour) return false;
   if (minute > time2.minute) return true;
   if (minute < time2.minute) return false;
   if (second > time2.second) return true;
   return false;
}
Time::Time(double secs) {
   this->hour = int(secs / 3600.0);
   secs -= this->hour * 3600.0;
   this->minute = int(secs / 60.0);
   secs -= this->minute * 60.0;
   this->second = secs;
}
Time::Time(int h, int m, double s) {
   hour = h;
   minute = m;
   second = s;
}
int main() {
   /* Time currentTime = {9, 14, 30.0}; */
   /* Time currentTime(33270); */
   Time currentTime(9, 14, 30.0);
   currentTime.increment(600);
   currentTime.print();
   return 0;
}
