#include <iostream>
#include <vector>
#include "Stemmer.h"
#include "Indexer.h"

using namespace std;

int main(){
    Stemmer stemmer;

    vector<string> testWords= {"akan", "pembelajaran", "menggunakan", "dilakukan", "berjalan", "studies", "analysis", "learning", "tested", "books", "pass"};

    for (const auto& word: testWords){
        cout<< word<< " -> "<< stemmer.stem(word)<< "\n";
    }

    Document doc(1, "Konz");
    doc.tokens= {"machine", "learning", "machine"};
    doc.buildTermFrequency();

    Document doc1(2, "Konz1");
    doc1.tokens= {"learning", "data"};
    doc1.buildTermFrequency();

    Indexer indexer;
    indexer.addDocument(doc);
    indexer.addDocument(doc1);
    indexer.computeDocumentFrequency();

    for (const auto& pair: indexer.getDF()){
        cout<< pair.first<< " -> "<< pair.second<< "\n";
    }

    return 0;
}