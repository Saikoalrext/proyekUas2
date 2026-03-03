#include "TFIDF.h"
#include <cmath>

using namespace std;

void TFIDF::compute(Indexer& indexer){
    auto& documents=const_cast<vector<Document>&>(indexer.getDocuments());
    const auto& df= indexer.getDF();

    int N= documents.size();

    for(auto& doc: documents){
        doc.tfidf.clear();

        for(const auto& pair: doc.termFrequency){
            const string& term= pair.first;
            int tf= pair.second;

            int docFreq= df.at(term);

            double idf= log((double)N/ docFreq);
            doc.tfidf[term]= tf* idf;
        }
    }
}