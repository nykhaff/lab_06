// 6_3rec.cpp
// Войтович Богдан
// Лабораторна робота № 6.3
// Опрацювання одновимірних масивів за допомогою звичайних функцій та шаблонів
// Варіант 3

#include <iomanip>
#include <iostream>

using namespace std;

void print(const int* arr, const int size, int i) {
  if (i >= size) {
    return;
  }

  cout << setw(5) << arr[i];

  print(arr, size, i + 1);
}

template <typename T>
void print(const T* arr, const int size, int i) {
  if (i == 0) {
    cout << "\n\n";
  } else if (i >= size) {
    return;
  }

  cout << setw(5) << arr[i];

  print<T>(arr, size, i + 1);
}

int sum_even(const int* arr, const int size, int i) {
  int sum = 0;

  if (i >= size) {
    return 0;
  } else if (arr[i] % 2 == 0) {
    sum = arr[i];
  }

  return sum + sum_even(arr, size, i + 1);
}

template <typename T>
T sum_even(const T* arr, const int size, int i) {
  T sum = T();

  if (i >= size) {
    return T();
  }

  if (arr[i] % 2 == 0) {
    sum = arr[i];
  }

  return sum + sum_even<T>(arr, size, i + 1);
}

#ifndef TEST_MODE
int main() {
  int s1, s2, s3;
  const int n = 10;

  int a[n] = {1, 2, 3, 5, 7, 8, 40, 3, 65, 100};
  print(a, n, 0);
  s1 = sum_even(a, n, 0);
  cout << "\nsum_even(a, n, 0) = " << s1;

  s2 = sum_even<int>(a, n, 0);
  cout << "\nsum_even<int>(a, n, 0) = " << s2;

  long b[n] = {1, 2, 3, 5, 7, 8, 40, 3, 65, 100};
  print<long>(b, n, 0);
  s3 = sum_even<long>(b, n, 0);
  cout << "\nsum_even<long>(b, n, 0) = " << s3;
}
#endif