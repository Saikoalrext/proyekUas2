#ifndef TFIDF_H
#define TFIDF_H

#include "Indexer.h"
#include <vector>
#include <string>

class TFIDF{
public:
    static void compute(Indexer& indexer);
};

#endif