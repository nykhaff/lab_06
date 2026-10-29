// 6_4rec.cpp
// Войтович Богдан
// Лабораторна робота № 6.4
// Опрацювання та впорядкування одновимірних динамічних масивів рекурсивним
// способом Варіант 3

#include <time.h>

#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

void fill(int* arr, const int size, int i) {
  if (i >= size) {
    return;
  }

  arr[i] = rand() % 7 - 3;

  fill(arr, size, i + 1);
}

void print(const int* arr, const int size, int i) {
  if (i >= size) {
    return;
  }

  cout << setw(5) << arr[i];

  print(arr, size, i + 1);
}

int even_i_product(const int* arr, const int size, int i) {
  if (i >= size) {
    return 1;
  }

  return arr[i] * even_i_product(arr, size, i + 2);
}

int find_first_zero(const int* arr, const int size, int i) {
  if (i >= size) {
    return -1;
  }

  if (arr[i] == 0) {
    return i;
  } else {
    return find_first_zero(arr, size, i + 1);
  }
}

int find_last_zero(const int* arr, const int size, int i) {
  if (i < 0) {
    return -1;
  }

  if (arr[i] == 0) {
    return i;
  } else {
    return find_last_zero(arr, size, i - 1);
  }
}

int sum_between_zeros(const int* arr, const int f, const int l) {
  if (f >= l - 1) {
    return 0;
  } else {
    return arr[f + 1] + sum_between_zeros(arr, f + 1, l);
  }
}

void transform(int* arr, const int size, int i, bool is_swapped) {
  if (i + 1 >= size) {
    if (is_swapped) {
      transform(arr, size, 0, false);
      return;
    } else {
      return;
    }
  }

  int temp;
  if (arr[i] < 0 && arr[i + 1] >= 0) {
    temp = arr[i];

    arr[i] = arr[i + 1];
    arr[i + 1] = temp;

    is_swapped = true;
  }

  transform(arr, size, i + 1, is_swapped);
}

#ifndef TEST_MODE
int main() {
  srand((unsigned)time(NULL));

  int n;

  cout << "n = ";
  cin >> n;

  int* a = new int[n];

  fill(a, n, 0);
  cout << "\n\n";
  print(a, n, 0);

  cout << "\nProduct of elements with even indices: "
       << even_i_product(a, n, 0);

  int first_zero = find_first_zero(a, n, 0);
  int last_zero = find_last_zero(a, n, n - 1);

  if (first_zero != -1 && last_zero != -1 && last_zero > first_zero) {
    cout << "\nSum of elements between first and last zeros: "
         << sum_between_zeros(a, first_zero, last_zero);
  } else {
    cout << "\nSum of elements between first and last zeros: less than 2 zeros "
            "found";
  }

  transform(a, n, 0, false);
  cout << "\nTransformed array:\n";
  print(a, n, 0);

  delete[] a;
  return 0;
}
#endif