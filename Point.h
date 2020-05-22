#include<iostream>
#include"Shablon_objects.h"
using namespace std;
template<class T>
class Point : public Shablon_Objects
{
protected:
  T tochka;
public:
  Point();
  Point(T _tochka);//передаёт любой параметр, который в абстрактном понимание выводится точкой в пространстве
  Point(const Point& _Point);
  ~Point();
  T Get();
  void Set(T _tochka);
  float Ploshad() override;
  ostream& print(ostream& os) override;
  bool operator ==(const Point& other);
  Point<T> operator=(const Point<T>& other);
};
template<class T>
Point<T>::Point()
{
  tochka = '.';
}
template<class T>
Point<T>::Point(T _tochka)//передаёт любой параметр, который в абстрактном понимание выводится точкой в пространстве
{
  tochka = _tochka;
}
template<class T>
Point<T>::Point(const Point& _Point)
{
  tochka = _Point.tochka;
}
template<class T>
T Point<T>::Get()
{
  return tochka;
}
template<class T>
Point<T>::~Point()
{
  tochka = 0;
}
template<class T>
void Point<T>::Set(T _tochka)
{
  tochka = _tochka;
}
template<class T>
float Point<T>::Ploshad()
{
  return 0;
}
template<class T>
bool Point<T>::operator ==(const Point& other)
{
  if (tochka == other.tochka)
  {
    return true;
  }
  else false;
}

template<class T>
Point<T> Point<T>::operator=(const Point<T>& other)//в абстрактном понимание, точка-это любой введённый тип данных соответствующий одному объекту
{
  if (*this == other)
  {
    return *this;
  }
  tochka = other.tochka;
  return *this;
}
template<class T>
ostream& Point<T>::print(ostream& os)
{
  os << this->Get();
  return os;
}