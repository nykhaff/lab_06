// lab_06_1.cpp
// Войтович Богдан
// Лабораторна робота № 6.1
// Пошук елементів одновимірного масиву ітераційним та рекурсивним способом
// Варіант 3

#include <time.h>

#include <cmath>
#include <iostream>

using namespace std;

void iter_fill(int* arr, const int size) {
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % 66 - 50;
  }
}

void iter_print(const int* arr, const int size) {
  cout << "\n{";
  for (int i = 0; i < size; i++) {
    if (i != size - 1) {
      cout << arr[i] << ", ";
    } else {
      cout << arr[i] << "}\n";
    }
  }
}

int iter_count(int* arr, const int size) {
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] < 0 || arr[i] % 2 != 0) {
      count++;
    }
  }

  return count;
}

int iter_sum(int* arr, const int size) {
  int sum = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] < 0 || arr[i] % 2 != 0) {
      sum += arr[i];
    }
  }

  return sum;
}

void iter_replace(int* arr, const int size) {
  for (int i = 0; i < size; i++) {
    if (arr[i] < 0 || arr[i] % 2 != 0) {
      arr[i] = 0;
    }
  }
}

void rec_fill(int* arr, const int size, int i = 0) {
  if (i >= size) {
    return;
  }

  arr[i] = rand() % 66 - 50;
  rec_fill(arr, size, i + 1);
}

void rec_print(const int* arr, const int size, int i = 0) {
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

  rec_print(arr, size, i + 1);
}

int rec_count(const int* arr, const int size, int i = 0) {
  int count = 0;

  if (i >= size) {
    return 0;
  } else if (arr[i] < 0 || arr[i] % 2 != 0) {
    count = 1;
  }

  return count + rec_count(arr, size, i + 1);
}

int rec_sum(const int* arr, const int size, int i = 0) {
  int sum = 0;

  if (i >= size) {
    return 0;
  } else if (arr[i] < 0 || arr[i] % 2 != 0) {
    sum = arr[i];
  }

  return sum + rec_sum(arr, size, i + 1);
}

void rec_replace(int* arr, const int size, int i = 0) {
  if (i >= size) {
    return;
  } else if (arr[i] < 0 || arr[i] % 2 != 0) {
    arr[i] = 0;
  }

  return rec_replace(arr, size, i + 1);
}

int main() {
  int count, sum, size = 24;
  int a[size] = {};

  srand((unsigned)time(NULL));

  // ітераційно
  iter_fill(a, size);
  iter_print(a, size);

  count = iter_count(a, size);
  sum = iter_sum(a, size);
  cout << "\nCount: " << count << "\nSum: " << sum;

  iter_replace(a, size);
  iter_print(a, size);

  // рекурсивно
  rec_fill(a, size);
  rec_print(a, size);

  count = rec_count(a, size);
  sum = rec_sum(a, size);
  cout << "\nCount: " << count << "\nSum: " << sum;

  rec_replace(a, size);
  rec_print(a, size);

  return 0;
}