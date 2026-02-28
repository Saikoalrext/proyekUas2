#include "Indexer.h"
#include <unordered_set>

using namespace std;

void Indexer::addDocument(const Document& doc){
    documents.push_back(doc);
}

void Indexer::computeDocumentFrequency(){
    documentFrequency.clear();

    for (const auto& doc: documents){
        unordered_set<string> uniqueTerms;

        for (const auto& pair: doc.termFrequency){
            uniqueTerms.insert(pair.first);
        }

        for (const auto& term: uniqueTerms){
            documentFrequency[term]++;
        }
    }
}

const vector<Document>& Indexer::getDocuments() const{
    return documents;
}

const unordered_map<string, int>& Indexer::getDF() const{
    return documentFrequency;
}