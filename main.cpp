#include <iostream>
#include <vector>
#include "Stemmer.h"
#include "Indexer.h"
#include "TFIDF.h"
#include "Similarity.h"

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
    doc1.tokens= {"machine", "data"};
    doc1.buildTermFrequency();

    Document doc2(3, "Konz2");
    doc2.tokens = {"network", "system"};
    doc2.buildTermFrequency();

    Indexer indexer;
    indexer.addDocument(doc);
    indexer.addDocument(doc1);
    indexer.computeDocumentFrequency();

    TFIDF::compute(indexer);

    const auto& docs= indexer.getDocuments();

    double sim= Similarity::cosine(docs[0], docs[1]);

    for(const auto& doc: indexer.getDocuments()){
        cout<< "Doc "<< doc.id<< endl;
        for(const auto& pair: doc.tfidf) {
            cout<< pair.first<< " -> "<< pair.second<< endl;
        }
        cout<< endl;
    }

    for(const auto& pair: indexer.getDF()){
        cout<< pair.first<< " -> "<< pair.second<< endl;
    }

    for (const auto& doc : indexer.getDocuments()) {
        cout << "Doc " << doc.id << endl;
        for (const auto& pair : doc.tfidf) {
            cout << pair.first << " -> " << pair.second << endl;
        }
        cout << endl;
    }

    cout<< "Cosine Similarity= "<< sim<< endl;

    return 0;
}