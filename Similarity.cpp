#include "Similarity.h"

#include <cmath>

using namespace std;

double Similarity::cosine(const Document& d1, const Document& d2){
    double dotProduct= 0.0;
    double norm1= 0.0;
    double norm2= 0.0;

    for(const auto& pair: d1.tfidf){
        const string& term= pair.first;
        double weight1= pair.second;

        norm1+= weight1* weight1;
        
        auto it= d2.tfidf.find(term);
        if (it!= d2.tfidf.end())
        {
            dotProduct+= weight1* it->second;
        }
    }

    for(const auto& pair: d2.tfidf){
        double weight2= pair.second;
        
        norm2+= weight2* weight2;
    }

    norm1= sqrt(norm1);
    norm2= sqrt(norm2);

    if (norm1== 0|| norm2== 0)
    {
        return 0.0;
    }
    
    return dotProduct/ (norm1* norm2);
}