#include"Shablon_objects.h"
#include"Line.h"
#include<iostream>
using namespace std;
template <class T>
class Triangle :public Shablon_Objects
{
protected:
  int height;
  T** massiv;

public:
  Triangle();
  Triangle(int _height, T stil);
  Triangle(const Triangle& triangle);
  ~Triangle();
  int GetHeight();
  T GetStil();
  void SetHeight(int _height);
  float Ploshad() override;
  ostream& print(ostream& os) override;
  bool operator ==(const Triangle& other);
  Triangle<T> operator=(const Triangle<T>& other);
  void Function(T stil);
};


inline Triangle<char>::Triangle()
{
  height = 3;
  this->Function('*');
}

template<class T>
inline Triangle<T>::Triangle(int _height, T stil)
{
  height = _height + 1;
  this->Function(stil);
}

template<class T>
inline Triangle<T>::Triangle(const Triangle& triangle)
{
  if (massiv != 0)
  {
    for (int i = 0; i < height; i++)
      delete[] massiv[i];
    delete[] massiv;
  }
  height = triangle.height;
  this->Function(triangle.GetStil());
}

template<class T>
inline Triangle<T>::~Triangle()
{
  if (massiv != 0)
  {
    for (int i = 0; i < height; i++)
    {
      massiv[i] = 0;
      delete[] massiv[i];
    }
    massiv = 0;
    delete[] massiv;
    height = 0;
  }
}

template<class T>
inline int Triangle<T>::GetHeight()
{
  return height - 1;
}

template<class T>
inline T Triangle<T>::GetStil()
{
  if (massiv != 0)
  {
    return massiv[0][0];
  }
  else throw - 1;
}

template<class T>
inline void Triangle<T>::SetHeight(int _height)
{
  height = _height;
}

template<class T>
inline float Triangle<T>::Ploshad()
{
  return ((height - 1) * (height - 1)) / 2;
}

template<class T>
inline ostream& Triangle<T>::print(ostream& os)
{
  for (int i = 0; i < height; i++)
  {
    for (int j = 0; j < i; j++)
      os << massiv[i][j];
    os << endl;
  }
  return os;
}

template<class T>
inline bool Triangle<T>::operator==(const Triangle& other)
{
  if (height == other.height && massiv[0][0] == other.massiv[0][0])
    return true;
  return false;
}

template<class T>
inline Triangle<T> Triangle<T>::operator=(const Triangle<T>& other)
{
  if (*this == other)
  {
    return *this;
  }
  if (massiv != 0)
  {
    for (int i = 0; i < height; i++)
    {
      massiv[i] = 0;
      delete[] massiv[i];
    }
    massiv = 0;
    delete[] massiv;
  }
  height = other.height;
  this->Function(other.GetStil());
  return *this;
}

template<class T>
inline void Triangle<T>::Function(T stil)
{
  massiv = new T * [height];
  for (int i = 0; i < height; i++)
    massiv[i] = new T[height];


  for (int i = 0; i < height; i++)
    for (int j = 0; j < i; j++)
      massiv[i][j] = stil;
}
