#include"Point.h"
#include"Shablon_objects.h"
#include"Line.h"
#include"Krug.h"
#include"Kvadratr.h"
#include"Pryamougolnik.h"
#include"triangle.h"
#include<iostream>
#include<stdlib.h>
#include"Cube.h"

class Container
{
protected:
  Shablon_Objects** massiv;
  int size;
public:
  Container();
  ~Container();
  Shablon_Objects* operator[](const int i);
  template <class T>
  void Add(T& other);//äîáàâëåíèå íîâîãî îáúåêòà
  template <class T>
  void Delete(T& other);//óäàëèòü ñóùåñòâóþùèé îáúåêò
  void out_object(int i);//îòîáðàçèòü âûáðàííûé îáúåêò
  friend ostream& operator<<(ostream& out, Container& other);//îòîáðàçèòü âñå èìåþùèåñÿ îáúåêòû
};

Container::Container()
{
  massiv = 0;
  size = 0;
}
Container::~Container()
{
  if (massiv != 0)
  {
    massiv = 0;
    delete[] massiv;
  }
  size = 0;
}

Shablon_Objects* Container::operator[](const int i)
{
  return massiv[i];
}

void Container::out_object(int i)//îòîáðàçèòü âûáðàííûé îáúåêò
{
  cout << *(massiv[i]);
}

ostream& operator<<(ostream& out, Container& other)//îòîáðàçèòü âñå èìåþùèåñÿ îáúåêòû
{
  for (int i = 0; i < other.size; i++)
  {
    out << *(other[i]) << endl;
  }
  return out;
}



template<class T>
inline void Container::Add(T& other)//äîáàâëåíèå íîâîãî îáúåêòà
{
  Shablon_Objects** objects = new Shablon_Objects * [size];
  for (int i = 0; i < size; i++)
  {
    objects[i] = massiv[i];
  }
  massiv = 0;
  delete[]massiv;
  size++;
  massiv = new Shablon_Objects * [size];
  for (int i = 0; i < size - 1; i++)
  {
    massiv[i] = objects[i];
  }
  massiv[size - 1] = (&other);
  objects = 0;
  delete[]objects;
}

template<class T>
inline void Container::Delete(T& other)//óäàëèòü ñóùåñòâóþùèé îáúåêò
{
  Shablon_Objects** objects = new Shablon_Objects * [size];
  int j = 0;
  int k = 0;
  for (int i = 0; i < size; i++)
  {
    if (massiv[i] == &other)
    {
      k = 1;
    }
    else
    {
      objects[j] = massiv[i];
      j++;
    }
  }
  if (k == 0)
    throw - 1;
  delete[] massiv;
  massiv = new Shablon_Objects * [size - 1];
  size = size - 1;
  for (int i = 0; i < size; i++)
    massiv[i] = objects[i];
  delete objects;
}
