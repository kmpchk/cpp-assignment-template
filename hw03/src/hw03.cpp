#include <iostream>
#include <cstring> // std::memmove ve std::strlen kullanmak için

void hw03(char* str, const char* pattern) {
    // İşaretcilerin nullptr olup olmadığını kontrol ediyoruz
    if (str == nullptr || pattern == nullptr) {
        return; // Eğer ya da pattern nullptr ise, işlevi hemen sonlandırıyoruz
    }

    // str ve pattern'in uzunluğunu alıyoruz
    size_t str_len = std::strlen(str);
    size_t pattern_len = std::strlen(pattern);

    // Eğer str boşsa veya pattern'in uzunluğu str'nin uzunluğundan büyükse, işlem yapmadan çıkıyoruz
    if (str_len == 0 || pattern_len > str_len) {
        return;
    }

    // İlk olarak, pattern'in str içindeki ilk bulunduğu konumu arıyoruz
    char* found = std::strstr(str, pattern);

    // Eğer pattern str içinde bulunmuyorsa, işlem yapmadan çıkıyoruz
    if (found == nullptr) {
        return;
    }

    // İlk bulunan pattern'in str içindeki indisini hesaplıyoruz
    size_t index = found - str;

    // pattern'i str içinden silmek için std::memmove kullanıyoruz
    std::memmove(found, found + pattern_len, str_len - index - pattern_len + 1);
}

int main() {
    char str1[] = "Hello_World";
    hw03(str1, "World");
    std::cout << str1 << std::endl; // "Hello_" çıktısını verir

    char str2[] = "START_TEXT_END";
    hw03(str2, "TEXT");
    std::cout << str2 << std::endl; // "START__END" çıktısını verir

    char str3[] = "START_TEXT_END";
    hw03(str3, "BEGIN");
    std::cout << str3 << std::endl; // "START_TEXT_END" çıktısını verir

    char str4[] = "";
    hw03(str4, "aabbcc");
    std::cout << str4 << std::endl; // Boş bir çıktı verir

    char str5[] = "A";
    hw03(str5, "A");
    std::cout << str5 << std::endl; // Boş bir çıktı verir
    
    return 0;
}