#pragma once
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

class TextProcessor
{
public:
    TextProcessor();

    std::vector<std::string> tokenize(const std::string& text);
    void removeStopwords(std::vector<std::string>& tokens);
    std::unordered_map<std::string, int> buildTermFreq(const std::vector<std::string>& tokens);
private:
    std::unordered_set<std::string> stopwords_en;
    std::unordered_set<std::string> stopwords_id;
    void loadStopwords();
};