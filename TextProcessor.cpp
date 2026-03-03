#include "TextProcessor.h"
#include <regex>
#include <algorithm>
#include <cctype>

TextProcessor::TextProcessor(){
    loadStopwords();
}

void TextProcessor::loadStopwords(){
    std::string words[]= {
        "a", "an", "and", "are", "as", "at", "be", "by", "for", "from", "has", "he", "in", "is", "it", "of", "on", "that", "the", "to", "was", "will", "with", "the", "this", "but", "they", "have", "had", "what", "said", "each", "which", "she", "do", "how", "their", "if", "up", "out", "many", "then", "them", "these", "so", "some", "her", "would", "make", "like", "into", "him", "time", "two", "more", "very", "when", "come", "may", "way", "look", "use", "her", "than", "its", "now", "find", "long", "down", "day", "did", "get", "has", "him", "his", "how", "man", "new", "now", "old", "see", "two", "who", "boy", "did", "she", "use", "her", "way", "many", "oil", "sit", "set", "run", "eat", "far", "sea", "eye", "ago", "off", "too", "any", "say", "man", "try", "ask", "end", "why", "let", "put", "say", "she", "try", "way", "own", "say", "too", "old", "tell", "very", "when", "much", "would", "there", "their"
    };
}