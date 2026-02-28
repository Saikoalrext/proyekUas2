#include "Stemmer.h"

using namespace std;

bool endsWith(const string& word, const string& suffix){
    if (suffix.size()> word.size()) return false;
    return word.compare(word.size()- suffix.size(), suffix.size(), suffix)== 0;
}

string Stemmer::stem(const string& word){
    if (isIndonesian(word))
    {
        return stemIndonesian(word);
    }
    return stemEnglish(word);
}

bool Stemmer::isIndonesian(const string& word){
    if (word.rfind("me", 0)== 0|| word.rfind("ber", 0)== 0|| word.rfind("ter", 0)== 0|| word.rfind("pe", 0)== 0) return true;

    if (word.size()> 3){
        if (endsWith(word, "kan")|| endsWith(word, "nya")|| endsWith(word, "lah")) return true;
    }
    
    return false;  
}

string Stemmer::stemIndonesian(const string& word){
    string w= word;

    if (w.size() > 4 && endsWith(w, "kan")) w= w.substr(0, w.size()-3);
    else if (w.size() > 4 && endsWith(w, "nya")) w= w.substr(0, w.size()-3);
    else if (w.size() > 4 && endsWith(w, "lah")) w= w.substr(0, w.size()-3);
    else if (w.size() > 4 && endsWith(w, "an")&& !endsWith(w, "lan")) w= w.substr(0, w.size()-2);
    
    if (w.rfind("meng", 0)== 0) w= w.substr(4);
    else if (w.rfind("men", 0)== 0) w= w.substr(3);
    else if (w.rfind("mem", 0)== 0) w= w.substr(3);
    else if (w.rfind("me", 0)== 0) w= w.substr(2);
    else if (w.rfind("ber", 0)== 0) w= w.substr(3);
    else if (w.rfind("ter", 0)== 0) w= w.substr(3);
    else if (w.rfind("pem", 0)== 0) w= w.substr(3);
    else if (w.rfind("pe", 0)== 0) w= w.substr(2);
    else if (w.rfind("di", 0)== 0) w= w.substr(2);

    return w;
}

string Stemmer::stemEnglish(const string& word){
    string w= word;
    
    if (w.size()> 4&& endsWith(w, "ies")) w= w.substr(0, w.size()- 3)+ "y";
    else if (w.size()> 4&& endsWith(w, "ing")) w= w.substr(0, w.size()- 3);
    else if (w.size()> 3&& endsWith(w, "ed")) w= w.substr(0, w.size()- 2);
    else if (w.size()> 3&& endsWith(w, "es")&& !endsWith(w, "ss")) w= w.substr(0, w.size()- 2);
    else if (w.size()> 3&& endsWith(w, "s")&& !endsWith(w, "us")&& !endsWith(w, "is")&& !endsWith(w, "ss")) w= w.substr(0, w.size()- 1);
    
    return w;
}