#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>
#include <vector>
#include <unordered_map>

class Document {
public:
    int id;
    std::string rawText;
    std::vector<std::string> tokens;
    std::unordered_map<std::string, int> termFrequency;
    std::unordered_map<std::string, double> tfidf;

    Document(int docId, const std::string& text);

    void buildTermFrequency();
};

#endif