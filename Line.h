#include "Shablon_objects.h"
#include<iostream>
using namespace std;
template <class T>
class Line :public Shablon_Objects
{
protected:
  int razmer;
  T* massiv;
public:
  Line();
  Line(int _razmer, T* _massiv);
  Line(int _razmer, T forma);
  Line(const Line& _Line);
  ~Line();
  int Get_Razmer();
  T Get_Massiv();
  void Set_Razmer(int _razmer);
  void Set_Massiv(int _razmer, T* _massiv);
  float Ploshad() override;
  ostream& print(ostream& os) override;
  bool operator ==(const Line& other);
  Line<T> operator=(const Line<T>& other);
};

template<class T>
Line<T>::Line()
{
  razmer = 2;
  massiv = new char[2];
  for (int i = 0; i < razmer; i++)
  {
    massiv[i] = "*";
  }
}

template<class T>
inline Line<T>::Line(int _razmer, T* _massiv)
{
  razmer = _razmer;
  massiv = new char[razmer];
  for (int i = 0; i < razmer; i++)
  {
    massiv[i] = _massiv[i];
  }
}

template<class T>
inline Line<T>::Line(int _razmer, T forma)
{
  razmer = _razmer;
  massiv = new T[razmer];
  for (int i = 0; i < razmer; i++)
  {
    massiv[i] = forma;
  }
}

template<class T>
inline Line<T>::Line(const Line& _Line)
{
  razmer = _Line.razmer;
  if (massiv != 0)
  {
    massiv = 0;
    delete[] massiv;
  }
  massiv = new T[razmer];
  for (int i = 0; i < razmer; i++)
  {
    massiv[i] = _Line.massiv[i];
  }
}

template<class T>
inline Line<T>::~Line()
{
  if (this->massiv != 0)
  {
    razmer = 0;
    massiv = 0;
    delete[] massiv;
  }
}

template<class T>
inline int Line<T>::Get_Razmer()
{
  return razmer;
}

template<class T>
inline T Line<T>::Get_Massiv()
{
  return massiv;
}

template<class T>
inline void Line<T>::Set_Razmer(int _razmer)
{
  razmer = _razmer;
}

template<class T>
inline void Line<T>::Set_Massiv(int _razmer, T* _massiv)
{
  razmer = _razmer;
  if (massiv != 0)
  {
    massiv = 0;
    delete[] massiv;
  }
  massiv = new T[razmer];
  for (int i = 0; i < razmer; i++)
  {
    massiv[i] = _massiv[i];
  }
}

template<class T>
Line<T> Line<T>::operator=(const Line<T>& other)
{
  if (*this == other)
  {
    return *this;
  }
  massiv = 0;
  delete[] massiv;
  razmer = other.razmer;
  massiv = new T[razmer];
  for (int i = 0; i < razmer; i++)
  {
    massiv[i] = other.massiv[i];
  }
  return *this;
}

template<class T>
inline float Line<T>::Ploshad()
{
  return 0.0f;
}

template<class T>
inline ostream& Line<T>::print(ostream& os)
{
  for (int i = 0; i < razmer; i++)
  {
    os << massiv[i];
  }
  os << endl;
  return os;
}

template<class T>
inline bool Line<T>::operator==(const Line& other)
{
  int kol = 0;
  if (razmer = other.razmer)
  {
    for (int i = 0; i < razmer; i++)
    {
      kol = kol + 1;
    }
  }
  if (kol == razmer)
  {
    return true;
  }
  else return false;
}
