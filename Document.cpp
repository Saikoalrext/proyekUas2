#include "Document.h"

using namespace std;

Document::Document(int docId, const string& text): id(docId), rawText(text){}

void Document::buildTermFrequency(){
    for (const auto& token: tokens){
        termFrequency[token]++;
    }
}