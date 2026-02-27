#pragma once
#include <string>

class Stemmer {
public: 
    std::string stem(const std::string& word);

private:
    std::string stemEnglish(const std::string& word);
    std::string stemIndonesia(const std::string& word);

    bool isIndonesian(const std::string& word);
};