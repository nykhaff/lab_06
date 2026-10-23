// lab_06_1.cpp
// Войтович Богдан
// Лабораторна робота № 6.1
// Пошук елементів одновимірного масиву ітераційним та рекурсивним способом
// Варіант 3

#include <time.h>

#include <cstdlib>
#include <iostream>

using namespace std;

void fill(int* arr, const int size, int i) {
  if (i >= size) {
    return;
  }

  arr[i] = rand() % 66 - 50;
  fill(arr, size, i + 1);
}

void print(const int* arr, const int size, int i) {
  if (i == 0) {
    cout << "\n{";
  }

  if (i >= size) {
    cout << "}\n";
    return;
  }

  if (i == size - 1) {
    cout << arr[i];
  } else {
    cout << arr[i] << ", ";
  }

  print(arr, size, i + 1);
}

int el_count(const int* arr, const int size, int i) {
  int count = 0;

  if (i >= size) {
    return 0;
  } else if (arr[i] < 0 || arr[i] % 2 != 0) {
    count = 1;
  }

  return count + el_count(arr, size, i + 1);
}

int el_sum(const int* arr, const int size, int i) {
  int sum = 0;

  if (i >= size) {
    return 0;
  } else if (arr[i] < 0 || arr[i] % 2 != 0) {
    sum = arr[i];
  }

  return sum + el_sum(arr, size, i + 1);
}

void replace(int* arr, const int size, int i) {
  if (i >= size) {
    return;
  } else if (arr[i] < 0 || arr[i] % 2 != 0) {
    arr[i] = 0;
  }

  return replace(arr, size, i + 1);
}

#ifndef TEST_MODE
int main() {
  int count, sum;
  const int size = 24;
  int a[size] = {};

  srand((unsigned)time(NULL));

  fill(a, size, 0);
  print(a, size, 0);

  count = el_count(a, size, 0);
  sum = el_sum(a, size, 0);
  cout << "\nCount: " << count << "\nSum: " << sum;

  replace(a, size, 0);
  print(a, size, 0);

  return 0;
}
#endif