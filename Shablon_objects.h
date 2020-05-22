#include <iostream>
using namespace std;
class Shablon_Objects
{
public:
  virtual float Ploshad() = 0;
  virtual ostream& print(ostream& os) = 0;
  friend ostream& operator<<(ostream& os, Shablon_Objects& other)
  {
    return other.print(os);
  }
  bool operator > (Shablon_Objects& other)
  {
    if (Ploshad() > other.Ploshad())
      return true;
    return false;
  }
  bool operator < (Shablon_Objects& other)
  {
    if (Ploshad() < other.Ploshad())
      return true;
    return false;
  }
};
