#ifndef SIMILARITY_H
#define SIMILARITY_H

#include "Document.h"

class Similarity{
public:
    static double cosine(const Document& d1, const Document& d2);
};

#endif