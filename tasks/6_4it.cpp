// 6_4it.cpp
// Войтович Богдан
// Лабораторна робота № 6.4
// Опрацювання та впорядкування одновимірних динамічних масивів
// Варіант 3

#include <time.h>

#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

void fill(int* arr, const int size) {
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % 7 - 3;
  }
}

void print(const int* arr, const int size) {
  cout << "\n\n";
  for (int i = 0; i < size; i++) {
    cout << setw(5) << arr[i];
  }
}

int calc_product(const int* arr, const int size) {
  int prod = 1;

  for (int i = 0; i < size; i++) {
    if (i % 2 == 0) {
      prod *= arr[i];
    }
  }

  return prod;
}

int sum_between_zeros(const int* arr, const int size) {
  int first_zero = -1, last_zero = -1, sum = 0;

  for (int i = 0; i < size; i++) {
    if (arr[i] == 0) {
      first_zero = i;
      break;
    }
  }

  for (int i = size - 1; i >= 0; i--) {
    if (arr[i] == 0) {
      last_zero = i;
      break;
    }
  }

  if (first_zero == -1 || last_zero == -1 || last_zero == first_zero ||
      last_zero - first_zero == 1) {
    return 0;
  }

  for (int i = first_zero + 1; i <= last_zero - 1; i++) {
    sum += arr[i];
  }

  return sum;
}

void transform(int* arr, const int size) {
  int* temp = new int[size];
  int k = 0;

  for (int i = 0; i < size; i++) {
    if (arr[i] >= 0) {
      temp[k] = arr[i];
      k++;
    }
  }

  for (int i = 0; i < size; i++) {
    if (arr[i] < 0) {
      temp[k] = arr[i];
      k++;
    }
  }

  for (int i = 0; i < size; i++) {
    arr[i] = temp[i];
  }

  delete[] temp;
}

#ifndef TEST_MODE
int main() {
  srand((unsigned)time(NULL));

  int n;

  cout << "n = ";
  cin >> n;

  int* a = new int[n];
  fill(a, n);
  print(a, n);

  cout << "\nProduct of elements with even indices: " << calc_product(a, n);
  cout << "\nSum of elements between first and last zeros: "
       << sum_between_zeros(a, n);

  transform(a, n);
  print(a, n);

  delete[] a;
  return 0;
}
#endif
