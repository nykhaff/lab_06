// 6_1it.cpp
// Войтович Богдан
// Лабораторна робота № 6.1
// Пошук елементів одновимірного масиву ітераційним та рекурсивним способом
// Варіант 3

#include <time.h>

#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

void fill(int* arr, const int size) {
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % 66 - 50;
  }
}

void print(const int* arr, const int size) {
  cout << "\n";
  for (int i = 0; i < size; i++) {
    cout << setw(5) << arr[i];
  }
}

int el_count(int* arr, const int size) {
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] < 0 || arr[i] % 2 != 0) {
      count++;
    }
  }

  return count;
}

int el_sum(int* arr, const int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] < 0 || arr[i] % 2 != 0) {
      sum += arr[i];
    }
  }

  return sum;
}

void replace(int* arr, const int size) {
  for (int i = 0; i < size; i++) {
    if (arr[i] < 0 || arr[i] % 2 != 0) {
      arr[i] = 0;
    }
  }
}

#ifndef TEST_MODE
int main() {
  int count, sum;
  const int size = 24;
  int a[size] = {};

  srand((unsigned)time(NULL));

  fill(a, size);
  print(a, size);

  count = el_count(a, size);
  sum = el_sum(a, size);
  cout << "\nCount: " << count << "\nSum: " << sum;

  replace(a, size);
  print(a, size);

  return 0;
}
#endif