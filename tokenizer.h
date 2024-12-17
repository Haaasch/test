//
// Created by lukas on 30.11.2024.
//

#ifndef ITERATOREN_TOKENIZER_H
#define ITERATOREN_TOKENIZER_H


#include <string>
#include <vector>
#include <sstream>

class Tokenizer {
public:
    // Constructor: initialize the tokenizer with a string and a delimiter
    Tokenizer(const std::string& input, char delimiter)
            : str(input), delim(delimiter) {}

    // Method to tokenize and return a vector of tokens
    std::vector<std::string> tokenize() {
        std::vector<std::string> tokens;
        std::stringstream ss(str);
        std::string token;

        while (std::getline(ss, token, delim)) {
            tokens.push_back(token);
        }

        return tokens;
    }

private:
    std::string str; // The string to tokenize
    char delim;      // The delimiter to use for splitting
};





#endif //ITERATOREN_TOKENIZER_H
