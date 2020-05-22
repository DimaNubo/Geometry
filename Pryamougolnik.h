#include"Shablon_objects.h"
#include<iostream>
using namespace std;
template <class T>
class Pryamougolnik :public Shablon_Objects
{
protected:
  int dlina;
  int shirina;
  T** massiv;
public:
  Pryamougolnik();
  Pryamougolnik(int _dlina, int _shirina, T stil);
  Pryamougolnik(const Pryamougolnik& pryamougolnik);
  ~Pryamougolnik();
  int Get_Dlina();//
  int Get_Shirina();
  T Get_Still();//получить то чем заполнем прямоугольник(какими данными)
  void Set_Razmer(int _dlina, int _shirina);
  void Set_Stil(T stil);//поменять то чем заполнен прямоугольник
  float Ploshad() override;
  ostream& print(ostream& os) override;
  bool operator ==(const Pryamougolnik& other);
  Pryamougolnik<T> operator=(const Pryamougolnik<T>& other);
  void Function(T stil);//установка памяти и запалнение массива внутри квадрата
};

template<class T>
inline Pryamougolnik<T>::Pryamougolnik()
{
  dlina = 2;
  shirina = 3;
  this->Function('*');

}

template<class T>
inline Pryamougolnik<T>::Pryamougolnik(int _dlina, int _shirina, T stil)
{
  dlina = _dlina;
  shirina = _shirina;
  this->Function(stil);
}

template<class T>
inline Pryamougolnik<T>::Pryamougolnik(const Pryamougolnik& pryamougolnik)
{
  dlina = pryamougolnik.dlina;
  shirina = pryamougolnik.shirina;
  if (massiv != 0)
  {
    for (int i = 0; i < shirina; i++)
    {
      massiv[i] = 0;
      delete[] massiv[i];
    }
    massiv = 0;
    delete[] massiv;
  }
  this->Function(pryamougolnik.Get_Still());
}

template<class T>
inline Pryamougolnik<T>::~Pryamougolnik()
{
  if (massiv != 0)
  {
    for (int i = 0; i < shirina; i++)
    {
      massiv[i] = 0;
      delete[] massiv[i];
    }
    massiv = 0;
    delete[] massiv;
    dlina = 0;
    shirina = 0;
  }
}

template<class T>
inline int Pryamougolnik<T>::Get_Dlina()
{
  return dlina;
}

template<class T>
inline int Pryamougolnik<T>::Get_Shirina()
{
  return shirina;
}

template<class T>
inline T Pryamougolnik<T>::Get_Still()
{
  if (massiv != 0)
  {
    return (massiv[0][0]);
  }
  else throw - 1;
}

template<class T>
inline void Pryamougolnik<T>::Set_Razmer(int _dlina, int _shirina)
{
  dlina = _dlina;
  shirina = _shirina;
}

template<class T>
inline void Pryamougolnik<T>::Set_Stil(T stil)
{
  if (massiv != 0)
  {
    for (int i = 0; i < shirina; i++)
      for (int j = 0; j < dlina; j++)
        massiv[i][j] = stil;
  }
  else throw - 1;
}

template<class T>
inline float Pryamougolnik<T>::Ploshad()
{
  return (shirina * dlina);
}

template<class T>
inline ostream& Pryamougolnik<T>::print(ostream& os)
{
  for (int i = 0; i < shirina; i++)
  {
    for (int j = 0; j < dlina; j++)
      os << massiv[i][j];
    os << endl;
  }
  return os;
}

template<class T>
inline bool Pryamougolnik<T>::operator==(const Pryamougolnik& other)
{
  if (dlina == other.dlina && shirina == other.shirina && massiv[0][0] == other.massiv[0][0])
    return true;
  return false;
}

template<class T>
inline Pryamougolnik<T> Pryamougolnik<T>::operator=(const Pryamougolnik<T>& other)
{
  if (*this == other)
  {
    return *this;
  }
  if (massiv != 0)
  {
    for (int i = 0; i < shirina; i++)
    {
      massiv[i] = 0;
      delete[] massiv[i];
    }
    massiv = 0;
    delete[] massiv;
  }
  dlina = other.dlina;
  shirina = other.shirina;
  this->Function(other.Get_Still());
  return *this;
}

template<class T>
inline void Pryamougolnik<T>::Function(T stil)
{
  massiv = new T * [shirina];
  for (int i = 0; i < shirina; i++)
    massiv[i] = new T[dlina];

  for (int i = 0; i < shirina; i++)
    for (int j = 0; j < dlina; j++)
      massiv[i][j] = stil;
}
