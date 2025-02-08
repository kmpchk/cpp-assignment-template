#include <hw05.h>
#include <cctype>  

VecOfStr hw05(const VecOfStr& strings)
{
  
  auto is_palindrome = [](const std::string& str) {
    std::string filtered;
    
    for (const auto& c : str) {
      if (std::isalpha(c)) {                 
        filtered.push_back(std::tolower(c));  
      }
    }

    
    std::size_t left = 0;
    std::size_t right = filtered.size() - 1;  
    while (left < right) {
      if (filtered[left] != filtered[right]) {
        return false; 
      }
      left++;
      right--;
    }
    return true; 
  };

  VecOfStr result;
  for (const auto& str : strings) {
    if (is_palindrome(str)) {
      result.push_back(str);
    }
  }
  return result;
}
