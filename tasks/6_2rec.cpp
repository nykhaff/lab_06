// 6_2rec.cpp
// Войтович Богдан
// Лабораторна робота № 6.2
// Опрацювання одновимірних масивів ітераційними та рекурсивними способами
// Варіант 3

#include <iomanip>
#include <iostream>

using namespace std;

void enter_elements(int* arr, const int size, int i) {
  if (i >= size) {
    return;
  }

  if (i == 0) {
    cout << "\n";
  }

  cout << "a[" << i << "] ";
  cin >> arr[i];

  enter_elements(arr, size, i + 1);
}

void print(const int* arr, const int size, int i) {
  if (i >= size) {
    return;
  }

  cout << setw(5) << arr[i];

  print(arr, size, i + 1);
}

int count_odd(const int* arr, const int size, int i) {
  int count = 0;

  if (i >= size) {
    return 0;
  } else if (arr[i] % 2 != 0) {
    count = 1;
  }

  return count + count_odd(arr, size, i + 1);
}

#ifndef TEST_MODE
int main() {
  int n;
  cout << "n = ";
  cin >> n;

  int a[n] = {};
  enter_elements(a, n, 0);

  print(a, n, 0);
  cout << "\nOdd numbers: " << count_odd(a, n, 0);

  return 0;
}
#endif