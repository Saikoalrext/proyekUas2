#ifndef INDEXER_H
#define INDEXER_H

#include "Document.h"
#include <vector>
#include <unordered_map>
#include <string>

class Indexer{
private:
    std::vector<Document> documents;
    std::unordered_map<std::string, int> documentFrequency;

public:
    void addDocument(const Document& doc);
    void computeDocumentFrequency();

    const std::vector<Document>& getDocuments() const;
    const std::unordered_map<std::string, int>& getDF() const;
};

#endif