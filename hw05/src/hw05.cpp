#include <hw05.h>
#include <cstring>
VecOfStr hw05(const VecOfStr& strings)
{
    VecOfStr new_strings;
    
    auto checkPali = [](std::string str){
        for(auto begin = str.begin(), end = str.end()-1; begin < end; ++begin, --end)
        {
            while(!isalnum(*begin)) ++begin;
            while(!isalnum(*end)) --end;
            if (toupper(*begin) != toupper(*end)) return false;
        }
        return true;
        
    };

    VecOfStr new_vector;
    for(const auto& string: strings){   
        if(checkPali(string)){
            new_vector.push_back(string);
        } 
    }
    return new_vector;
}
