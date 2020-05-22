#include"Shablon_objects.h"
#include"Kvadratr.h"
#include <iostream>
using namespace std;
template <class T>
class Cube : public Shablon_Objects
{
protected:
  int storona;
  T*** massiv;
public:
  Cube();
  Cube(int _storona, T stil);
  Cube(const Cube& cube);
  ~Cube();

  int GetStorona();
  T GetStil();
  void Set_Storona(int _storona);

  float Ploshad() override;
  ostream& print(ostream& os) override;

  bool operator ==(const Cube& other);
  Cube<T> operator=(const Cube<T>& other);
  void Function(T Stil); //установка памяти и запалнение массива внутри куба
};

template<class T>
inline Cube<T>::Cube()
{
  storona = 1;
  this->Function('*');
}

template<class T>
inline Cube<T>::Cube(int _storona, T stil)
{
  storona = _storona;
  this->Function(stil);
}

template<class T>
inline Cube<T>::Cube(const Cube& cube)
{
  if (massiv != 0)
  {
    for (int i = 0; i < storona; i++)
      for (int j = 0; j < storona; j++)
      {
        massiv[i][j] = 0;
        delete[] massiv[i][j];
      }
    for (int i = 0; i < storona; i++)
    {
      massiv[i] = 0;
      delete[] massiv[i];
    }
    massiv = 0;
    delete[] massiv;
  }
  storona = cube.storona;
  this->Function(cube.GetStil());
}

template<class T>
inline Cube<T>::~Cube()
{
  if (massiv != 0)
  {
    for (int i = 0; i < storona; i++)
      for (int j = 0; j < storona; j++)
      {
        massiv[i][j] = 0;
        delete[] massiv[i][j];
      }
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
inline int Cube<T>::GetStorona()
{
  return storona;
}

template<class T>
inline T Cube<T>::GetStil()
{
  if (massiv != 0)
  {
    return (massiv[0][0][0]);
  }
  else throw - 1;
}

template<class T>
inline void Cube<T>::Set_Storona(int _storona)
{
  storona = _storona;
}

template<class T>
inline float Cube<T>::Ploshad()
{
  return (storona * storona * 6);
}

template<class T>
inline ostream& Cube<T>::print(ostream& os)
{
  Kvadrat<T> tmp(storona, massiv[0][0][0]);
  tmp.print(os);
  return os;
}

template<class T>
inline bool Cube<T>::operator==(const Cube& other)
{
  if (storona == other.storona && massiv[0][0][0] == other.massiv[0][0][0])
    return true;
  return false;
}

template<class T>
inline Cube<T> Cube<T>::operator=(const Cube<T>& other)
{
  if (this == other)
  {
    return *this;
  }
  if (massiv != 0)
  {
    for (int i = 0; i < storona; i++)
      for (int j = 0; j < storona; j++)
      {
        massiv[i][j] = 0;
        delete[] massiv[i][j];
      }
    for (int i = 0; i < storona; i++)
    {
      massiv[i] = 0;
      delete[] massiv[i];
    }
    massiv = 0;
    delete[] massiv;
  }
  storona = other.storona;
  this->Function(other.GetStil());
  return *this;
}

template<class T>
inline void Cube<T>::Function(T Stil)
{
  massiv = new T * *[storona];
  for (int i = 0; i < storona; i++)
  {
    massiv[i] = new T * [storona];
    for (int j = 0; j < storona; j++)
      massiv[i][j] = new T[storona];
  }
  for (int i = 0; i < storona; i++)
    for (int j = 0; j < storona; j++)
      for (int l = 0; l < storona; l++)
        massiv[i][j][l] = Stil;
}
