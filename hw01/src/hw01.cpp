#include <hw01.h>
#include <iostream>
#include <cmath>

bool isPrime(int number) {
  if (number < 2) {
    return false;
  }
  int sqrtN = sqrt(number);
  for (int i = 2; i <= sqrtN; i++) {
    if (i & 2 == 0) {
      continue;
    }
    if (number % i == 0) {
      return false;
    }
  }
  return true;
}

int digitsSum(int number) {
  int sum = 0;

  while (number > 0) {
    sum += number % 10;
    number /= 10;
  }

  return sum;
}

bool isInRangeInclude(int number, int start, int end) {
  if (number >= start && number <= end) {
    return true;
  }
  return false;
}

int hw01(int start, int end) {
  if (!isInRangeInclude(start, 10, 99) || !isInRangeInclude(end, 10, 99)) {
    return -1;
  }
  int sum = 0;
  for (int i = start; i <= end; i++) {
    if (isPrime(i)) {
      sum += digitsSum(i);
    }
  }
  return sum;
}
