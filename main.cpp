#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

enum TokenType {
    INTEGER,
    BOOLEAN,
    IDENTIFIER,
    OPERATOR,
    KEYWORD,
    LITERAL,
    COMMENT,
    ERROR,
    DATATYPE
};


struct Token {
    TokenType type;
    string lexeme;
};

bool isValidIdentifierChar(char c) {
    return isalnum(c) || c == '_';
}


vector<Token> scanMiniLang(const string& filename) {
    ifstream inputFile(filename);
    vector<Token> tokens;

    if (!inputFile.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return tokens;
    }

    string line;
    while (getline(inputFile, line)) {

        for (size_t i = 0; i < line.size(); ++i) {
            
           char currentChar = line[i];
            // Scanner rules below

            // Space
            if (isspace(currentChar))
                continue;
            // Integers
            if (isdigit(currentChar)) {
                string integerToken;
                while (isdigit(currentChar)) {
                    integerToken += currentChar;
                    i++;
                    currentChar = line[i];
                }
                tokens.push_back({INTEGER, integerToken});
                i--; 
                continue;
            }
            
            // Identifiers or keywords or boolean literals or datatypes
            if (isalpha(currentChar) || currentChar == '_') {
                string identifierToken;
                while (isValidIdentifierChar(currentChar)) {
                    identifierToken += currentChar;
                    i++;
                    currentChar = line[i];
                }

                
                if (identifierToken == "if" || identifierToken == "else" || identifierToken == "print") {
                    tokens.push_back({KEYWORD, identifierToken});
                } else if (identifierToken == "true" || identifierToken == "false") {
                    tokens.push_back({LITERAL, identifierToken});
                } else if (identifierToken == "int" || identifierToken == "bool") {
                    tokens.push_back({DATATYPE, identifierToken}); 
                } else {
                    tokens.push_back({IDENTIFIER, identifierToken});
                }
                i--;
                continue;
            }

            // Comments
            if (currentChar == '/') {
                if (i + 1 < line.size() && line[i + 1] == '/') {
                    string commentToken = line.substr(i);
                    tokens.push_back({COMMENT, commentToken});
                    break; 
                }
            }

            // Operators
            if (currentChar == '+' || currentChar == '-' || currentChar == '*' || currentChar == '/' || currentChar == '=' || currentChar == '!' || currentChar == '<' || currentChar == '>') {
                string operatorToken;
                operatorToken += currentChar;
                if (i + 1 < line.size() && (line[i + 1] == '=' || line[i + 1] == '=')) {
                    operatorToken += line[i + 1];
                    i++;
                }
                tokens.push_back({OPERATOR, operatorToken});
                continue;
            }


            tokens.push_back({ERROR, string(1, currentChar)});
            
        }
    }

    inputFile.close();
    return tokens;
}


void printTokens(const vector<Token>& tokens) {
    for (const auto& token : tokens) {
        cout << "Token type: " << token.type << ", Lexeme: " << token.lexeme << endl;
    }
}

int main() {
    string filename = "example.minilang"; 
    vector<Token> tokens = scanMiniLang(filename);
    printTokens(tokens);
    return 0;
}
