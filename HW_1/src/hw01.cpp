#include <hw01.h>

int hw01(int start, int end)
{
  int result = 0;
  if (start < 10 or end < 10)
  {
  return -1;
  }

  for (int i = start; i <= end; i++) {
    if(IsSimpleNum(i)) {
      result = result + (i % 10 + i / 10);
    }
  }
  return result;
}

bool IsSimpleNum(int num)
{
  for (int i = 2; i < num; i++)
  {
      if (num % i == 0) {
        return false;
      }
  }
  return true;
}