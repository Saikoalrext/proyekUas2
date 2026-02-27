#include "Stemmer.h"

using namespace std;

string Stemmer::stem(const string& word){
    if (isIndonesian(word))
    {
        return stemIndonesia(word);
    }
    else stemEnglish(word);
}

bool Stemmer::isIndonesian(const string&word){
    if (word.rfind("me", 0)== 0|| word.rfind("ber", 0)== 0|| word.rfind("ter", 0)== 0|| word.rfind("pe", 0)== 0) return true;

    if (word.size()>= 3 && word.substr(word.size()- 3)== "kan")
    if (word.size()>= 3 && word.substr(word.size()- 3)== "nya")
    if (word.size()>= 3 && word.substr(word.size()- 3)== "lah")

    return false;  
}