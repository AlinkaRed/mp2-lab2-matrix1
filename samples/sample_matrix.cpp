// ННГУ, ВМК, Курс "Методы программирования-2", С++, ООП
//
// sample_matrix.cpp - Copyright (c) Гергель В.П. 07.05.2001
//   Переработано для Microsoft Visual Studio 2008 Сысоевым А.В. (20.04.2015)
//
// Тестирование верхнетреугольной матрицы

#include <iostream>
#include "utmatrix.h"
//---------------------------------------------------------------------------
void main()
{
  /*TMatrix<int> a(5), b(5), c(5);
  int i, j;
  setlocale(LC_ALL, "Russian");
  cout << "Тестирование программ поддержки представления треугольных матриц"
    << endl;
  for (i = 0; i < 5; i++)
    for (j = 0; j < 5; j++ )
    {
      a[i][j] =  i + j;
      b[i][j] = (i * 10 + j) * 100;
    }
  c = a + b;
  cout << "Matrix a = " << endl << a << endl;
  cout << "Matrix b = " << endl << b << endl;
  cout << "Matrix c = a + b" << endl << c << endl;*/
  TVector<int> a(5), b(5), c(5);
  int s;
  setlocale(LC_ALL, "Russian");
  cout << "Тестирование программ поддержки представления векторов и операций над ними"
    << endl;
  for (int i = 0; i < 5; i++) {
      a[i] = i + 1;
      b[i] = (i + 1) * 2;
  }
  cout << "Vector a = " << endl << a << endl;
  cout << "Vector b = " << endl << b << endl;
  c = a + 5;
  cout << "Vector c = a + 5" << endl << c << endl;
  c = a - 5;
  cout << "Vector c = a - 5" << endl << c << endl;
  c = a * 5;
  cout << "Vector c = a * 5" << endl << c << endl;
  c = a + b;
  cout << "Vector c = a + b" << endl << c << endl;
  c = a - b;
  cout << "Vector c = a - b" << endl << c << endl;
  s = a * b;
  cout << "s = a * b" << endl << s << endl;
}
//---------------------------------------------------------------------------
