// 6_3it.cpp
// Войтович Богдан
// Лабораторна робота № 6.3
// Опрацювання одновимірних масивів за допомогою звичайних функцій та шаблонів
// Варіант 3

#include <iomanip>
#include <iostream>

using namespace std;

void print(const int* arr, const int size) {
  cout << "\n\n";
  for (int i = 0; i < size; i++) {
    cout << setw(5) << arr[i];
  }
}

template <typename T>
void print(const T* arr, const int size) {
  cout << "\n\n";
  for (int i = 0; i < size; i++) {
    cout << setw(5) << arr[i];
  }
}

int sum_even(const int* arr, const int size) {
  int sum = 0;

  for (int i = 0; i < size; i++) {
    if (arr[i] % 2 == 0) {
      sum += arr[i];
    }
  }

  return sum;
}

template <typename T>
T sum_even(const T* arr, const int size) {
  T sum = T();

  for (int i = 0; i < size; i++) {
    if (arr[i] % 2 == 0) {
      sum += arr[i];
    }
  }

  return sum;
}

#ifndef TEST_MODE
int main() {
  int s1, s2, s3;
  const int n = 10;

  int a[n] = {1, 2, 3, 5, 7, 8, 40, 3, 65, 100};
  print(a, n);
  s1 = sum_even(a, n);
  cout << "\nsum_even(a, n) = " << s1;

  s2 = sum_even<int>(a, n);
  cout << "\nsum_even<int>(a, n) = " << s2;

  long b[n] = {1, 2, 3, 5, 7, 8, 40, 3, 65, 100};
  print<long>(b, n);
  s3 = sum_even<long>(b, n);
  cout << "\nsum_even<long>(b, n) = " << s3;
}
#endif