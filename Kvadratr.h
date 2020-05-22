#include"Shablon_objects.h"
#include<iostream>
using namespace std;
template <class T>
class Kvadrat :public Shablon_Objects
{
protected:
  int storona;
  T** massiv;
public:
  Kvadrat();
  Kvadrat(int _storona, T stil);
  Kvadrat(const Kvadrat& kvadrat);
  ~Kvadrat();
  int Get_Storona();
  T Get_Still();//получить то чем заполнем квадрат(какими данными)
  void Set_Storona(int _storona);
  void Set_Stil(T stil);//поменять то чем заполнен квадрат
  float Ploshad() override;
  ostream& print(ostream& os) override;
  bool operator ==(const Kvadrat& other);
  Kvadrat<T> operator=(const Kvadrat<T>& other);
  void Function(T stil);//установка памяти и запалнение массива внутри квадрата
};

template<class T>
inline Kvadrat<T>::Kvadrat()
{
  storona = 2;
  this->Function('*');

}

template<class T>
inline Kvadrat<T>::Kvadrat(int _storona, T stil)
{
  storona = _storona;
  this->Function(stil);
}

template<class T>
inline Kvadrat<T>::Kvadrat(const Kvadrat& kvadrat)
{
  storona = kvadrat.storona;
  if (massiv != 0)
  {
    for (int i = 0; i < storona; i++)
    {
      massiv[i] = 0;
      delete[] massiv[i];
    }
    massiv = 0;
    delete[] massiv;
  }
  this->Function(kvadrat.Get_Still());
}

template<class T>
inline Kvadrat<T>::~Kvadrat()
{
  if (massiv != 0)
  {
    for (int i = 0; i < storona; i++)
    {
      massiv[i] = 0;
      delete[] massiv[i];
    }
    massiv = 0;
    delete[] massiv;
    storona = 0;
  }
}

template<class T>
inline int Kvadrat<T>::Get_Storona()
{
  return storona;
}

template<class T>
inline T Kvadrat<T>::Get_Still()
{
  if (massiv != 0)
  {
    return (massiv[0][0]);
  }
  else throw - 1;
}

template<class T>
inline void Kvadrat<T>::Set_Storona(int _storona)
{
  storona = _storona;
}

template<class T>
inline void Kvadrat<T>::Set_Stil(T stil)
{
  if (massiv != 0)
  {
    for (int i = 0; i < storona; i++)
      for (int j = 0; j < storona; j++)
        massiv[i][j] = stil;
  }
  else throw - 1;
}

template<class T>
inline float Kvadrat<T>::Ploshad()
{
  return (storona * storona);
}

template<class T>
inline ostream& Kvadrat<T>::print(ostream& os)
{
  for (int i = 0; i < storona; i++)
  {
    for (int j = 0; j < storona; j++)
      os << massiv[i][j];
    os << endl;
  }
  return os;
}

template<class T>
inline bool Kvadrat<T>::operator==(const Kvadrat& other)
{
  if (storona == other.storona && massiv[0][0] == other.massiv[0][0])
  {
    return true;
  }
  return false;
}

template<class T>
inline Kvadrat<T> Kvadrat<T>::operator=(const Kvadrat<T>& other)
{
  if (*this == other)
  {
    return *this;
  }
  if (massiv != 0)
  {
    for (int i = 0; i < storona; i++)
    {
      massiv[i] = 0;
      delete[] massiv[i];
    }
    massiv = 0;
    delete[] massiv;
  }
  storona = other.storona;
  this->Function(other.Get_Still());
  return *this;
}

template<class T>
inline void Kvadrat<T>::Function(T stil)
{
  massiv = new T * [storona];
  for (int i = 0; i < storona; i++)
    massiv[i] = new T[storona];

  for (int i = 0; i < storona; i++)
    for (int j = 0; j < storona; j++)
      massiv[i][j] = stil;
}
