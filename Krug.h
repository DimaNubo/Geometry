#include"Shablon_objects.h"
#include<iostream>
using namespace std;
template <class T>
class Krug :public Shablon_Objects
{
protected:
  int radius;
  T** massiv;
public:
  Krug();
  Krug(int _radius, T stil);//нужного радиуса с заданием того как будет выглядить круг
  Krug(const Krug& krug);
  ~Krug();
  int Get_Radius();
  T Get_Stil();//можно получить то чем заполняется круг
  void Set_Radius(int _radius);
  float Ploshad() override;
  ostream& print(ostream& os) override;
  bool operator ==(const Krug& other);
  Krug<T> operator=(const Krug<T>& other);
  void Function(T _stil);//для выделения памяти и установки нового массива(новой размерности)
};

template<class T>
inline Krug<T>::Krug()
{
  radius = 2;
  this->Function('*');
}
template<class T>
void Krug<T>::Function(T _stil)//для выделения памяти и установки нового массива(новой размерности)
{
  massiv = new T * [2 * radius - 1];
  for (int i = 0; i < 2 * radius - 1; i++)
    massiv[i] = new T[2 * radius];

  for (int i = 0; i < radius; i++)
    for (int j = radius - 1 - i; j < radius + i + 1; j++)
      massiv[i][j] = _stil;

  for (int i = radius; i < 2 * radius - 1; i++)
    for (int j = 1 + i - radius; j < 3 * radius - 1 - i; j++)
      massiv[i][j] = _stil;
}

template<class T>
inline Krug<T>::Krug(int _radius, T stil)
{
  radius = _radius;
  this->Function(stil);
}

template<class T>
inline Krug<T>::Krug(const Krug& krug)
{
  radius = krug.radius;
  if (massiv != 0)
  {
    for (int i = 0; i < 2 * radius - 1; i++)
    {
      massiv[i] = 0;
      delete[] massiv[i];
    }
    massiv = 0;
    delete[] massiv;
  }
  this->Function(krug.Get_Stil());
}

template<class T>
inline Krug<T>::~Krug()
{
  if (massiv != 0)
  {
    for (int i = 0; i < 2 * radius - 1; i++)
    {
      massiv[i] = 0;
      delete[] massiv[i];
    }
    massiv = 0;
    delete[] massiv;
  }
  radius = 0;
}

template<class T>
inline int Krug<T>::Get_Radius()
{
  return radius;
}

template<class T>
inline T Krug<T>::Get_Stil()
{
  if (massiv != 0)
  {
    return this->massiv[0][0];
  }
  else throw - 1;
}

template<class T>
inline void Krug<T>::Set_Radius(int _radius)
{
  radius = _radius;
}

template<class T>
inline float Krug<T>::Ploshad()
{
  return (radius * radius * 3.14);
}

template<class T>
inline ostream& Krug<T>::print(ostream& os)
{
  for (int i = 0; i < 2 * radius - 1; i++)
  {
    for (int j = 0; j < 2 * radius; j++)
    {
      if ((i < radius && j >= (radius - 1 - i) && j < (radius + i + 1)) || (i >= radius && i < (2 * radius - 1) && j >= (1 + i - radius) && j < (3 * radius - 1 - i)))
        os << massiv[i][j];
      else os << " ";
    }
    os << endl;
  }
  return os;
}

template<class T>
inline bool Krug<T>::operator==(const Krug& other)
{
  if (radius == other.Get_Radius)
  {
    if (massiv[radius][radius] == other.massiv[radius][radius])
    {
      return true;
    }
  }
  return false;
}

template<class T>
inline Krug<T> Krug<T>::operator=(const Krug<T>& other)
{
  if (*this == other)
  {
    return *this;
  }
  if (massiv != 0)
  {
    for (int i = 0; i < 2 * radius - 1; i++)
    {
      massiv[i] = 0;
      delete[] massiv[i];
    }
    massiv = 0;
    delete[] massiv;
  }
  radius = other.radius;
  this->Function(other.Get_Stil());
  return *this;
}
