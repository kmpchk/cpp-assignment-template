#include <hw02.h>

std::string hw02(std::string input_str)
{
    std::string newString;
    for(int i = 0;i<input_str.length();i++) {
        if(input_str[i]==input_str[i+1]) {
            input_str.erase(i,1);
        }
    }

    newString = input_str;

    for (int i = 0;i < newString.length()-1;i++) {
        for (int n = i+1; n<newString.length();n++) {
            if(newString[i]==newString[n]) {
                newString.erase(n,1);
            }
        }
    }
    return newString;
}