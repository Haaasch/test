//
// Created by lukas on 30.11.2024.
//
#include <map>
#include <iostream>
#include <string>
#include "tokenizer.h"
#include <exception>

using namespace std;

#ifndef ITERATOREN_WORDCOUNTER_H
#define ITERATOREN_WORDCOUNTER_H


class WordCounter {
public:
    WordCounter() = default;

    void count(string wordToCount){
    Tokenizer ja(wordToCount, ' ');
    vector<string> words = ja.tokenize();

    for(const auto& word : words){
        countMap[word]++;
    }
}
    void print(){
        if(countMap.empty()){
            throw invalid_argument("Die countMap ist leer");
        }
        for(const auto& pair : countMap){
            cout << pair.first << " " << pair.second << endl;
        }
    }

    friend ostream& operator<<(ostream& os, WordCounter& objekt);

    void remove(string toRemove){

        bool isPart = countMap.erase(toRemove);
        if(isPart==0){
            throw invalid_argument("Element ist nicht Teil der Map");
        }
    }

    void reset(){
        countMap.clear();
    }

    int getCount(string word){

        if(!countMap[word]){
            throw invalid_argument("Das Wort befindet sich nicht in der Map");
        }
        else
            return countMap[word];
    }

    int operator ()(string word){
        return getCount(word);
    }







private:
    map<string, int> countMap;
};


#endif //ITERATOREN_WORDCOUNTER_H
