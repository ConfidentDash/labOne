#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

std::string func(const std::string& input) {
    std::string result = input;
    
    // Используем алгоритм remove_if для удаления нежелательных символов
    result.erase(
        std::remove_if(result.begin(), result.end(), 
            [](char c) {
                // Оставляем пробелы и буквенно-цифровые символы
                // Удаляем всё остальное
                return !(c == ' ' || std::isalnum(c));
            }
        ),
        result.end()
    );
    
    return result;
}

int main() {
    std::string text;
    
    std::cout << "Введите строку: ";
    std::getline(std::cin, text);
    
    std::string cleaned = func(text);
    
    std::cout << "Очищенная строка: " << cleaned << std::endl;
    
    return 0;
}
