// 6_2it.cpp
// Войтович Богдан
// Лабораторна робота № 6.2
// Опрацювання одновимірних масивів ітераційними та рекурсивними способами
// Варіант 3

#include <iomanip>
#include <iostream>

using namespace std;

void enter_elements(int* arr, const int size) {
  cout << "\n";
  for (int i = 0; i < size; i++) {
    cout << "a[" << i << "] ";
    cin >> arr[i];
  }
}

void print(const int* arr, const int size) {
  cout << "\n";
  for (int i = 0; i < size; i++) {
    cout << setw(5) << arr[i];
  }
}

int count_odd(const int* arr, const int size) {
  int count = 0;

  for (int i = 0; i < size; i++) {
    if (arr[i] % 2 != 0) {
      count++;
    }
  }

  return count;
}

#ifndef TEST_MODE
int main() {
  int n;
  cout << "n = ";
  cin >> n;

  int* a = new int[n];
  enter_elements(a, n);

  print(a, n);
  cout << "\nOdd numbers: " << count_odd(a, n);
}
#endif