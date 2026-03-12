#include <iostream>
#include <string>
#include <locale>
using namespace std; 

wstring func(const wstring& input) {
    wstring result;
    
    for (wchar_t c : input) {
        // Оставляем пробелы и буквенно-цифровые символы 
        if (c == L' ' || iswalnum(c)) {
            result += c;
        }
    }
    
    return result;
}

int main()  { // test
    // поддержка русского языка
    locale::global(std::locale("ru_RU.UTF-8"));
    
    wstring text;
    
    wcout << L"Введите строку: ";
    getline(std::wcin, text);
    
    wstring cleaned =  func(text);
    
    wcout << L"Очищенная строка: " << cleaned << std::endl;
    
    return 0;
}
