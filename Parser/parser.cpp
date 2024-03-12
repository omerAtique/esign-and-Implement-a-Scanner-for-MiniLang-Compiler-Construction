#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

#define SUCCESS 1
#define FAILED 0

int Program();
int Declaration();
int Assignment();
int Condition();
int Update();
int Print();
int DataType();
int Identifier();
int Arithmetic();
int Relational();
int Boolean();
int Number();
int elseIf();
int String();
int Literal();

const char *cursor;
std::string outputString;
std::string outputString1;

int main() {
    std::ifstream file("lexemes_output.txt"); 
    if (!file.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        
        outputString += line;
    }

    cursor = outputString.c_str(); 
    std::cout << "Inputted string: " << outputString << std::endl;
    std::cout << std::endl;
    std::cout << "Input          Action" << std::endl;
    std::cout << "--------------------------------" << std::endl;

    if (Program() && *cursor == '\0') {
        std::cout << "--------------------------------" << std::endl;
        std::cout << "String is successfully parsed" << std::endl;
        return 0;
    } else {
        std::cout << "--------------------------------" << std::endl;
        std::cout << "Error in parsing String" << std::endl;
        return 1;
    }
}

int Program() {
    printf("%-16s Program -> Declaration Declaration Assignment Condition Update Print\n", cursor);
    if(Declaration()){
        if(Declaration()){
            if(Assignment()){
                if(Condition()){
                    if(Update()){
                        if(Print()){
                            return SUCCESS;
                        }else{
                            return FAILED;
                        }
                    }else{
                        return FAILED;
                    }
                }else{
                    return FAILED;
                }
            }else{
                return FAILED;
            }
        }else{
            return FAILED;
        }
    }
    else{
        return FAILED;
    }
}

int Declaration() {
    if (DataType()) {
        printf("%-16s Decleration -> DataType Identifier '=' Literal ';'\n", cursor);
        if (Identifier()) { 
            if (*cursor == '='){
                cursor++;
                if(Literal())
                {
                    if(*cursor == ';')
                    {
                        cursor++;
                        return SUCCESS;
                    }else{
                        return FAILED;
                    }
                }else{
                    return FAILED;
                }
            }else{
                return FAILED;
            }
        } 
        else
            return FAILED;
    }
    else {
        printf("%-16s Declaration -> $\n", cursor);
        return SUCCESS;
    }    
}

int Assignment() {
    if (Identifier()) {
        printf("%-16s Assignment ->  Identifier '=' Arithmetic ';'\n", cursor);
        if (*cursor == '=') { 
            cursor++;
            if (Arithmetic()){
                if(*cursor == ';')
                {
                    cursor++;
                    return SUCCESS;
                }else{
                    return FAILED;
                }
            }else{
                return FAILED;
            }
        } 
        else{
            return FAILED;
        }
    }
    else{
        
        return FAILED;
    }
}

int Condition() {
    printf("%-16s Condition -> if ( Arithmetic relational  Literal ')' '{' PrintStatement '}'\n", cursor);
    if (*cursor == 'i') {
        cursor++;
        if (*cursor == 'f') {
            cursor++;
            if (*cursor == '('){
                cursor++;
                if (Arithmetic()) {
                    if (Relational()) {
                        if (Literal()) {
                            if (*cursor == ')') {
                                cursor++;
                                if (*cursor == '{'){
                                    cursor++;
                                    if(Print()){
                                        if(*cursor == '}'){
                                            cursor++;
                                            return SUCCESS;
                                        }else{
                                            return FAILED;
                                        }
                                    }
                                    else{
                                        return FAILED;
                                    }
                                }
                                else{
                                    return FAILED;
                                }
                            }else{
                                return FAILED;
                            }
                        }else{
                            return FAILED;
                        }
                    }else{
                        return FAILED;
                    }
                }else{
                    return FAILED;
                }
            }else{
                return FAILED;
            }
        }else{
            return FAILED;
        }
    }
    else if(elseIf()){
        return SUCCESS;
    }
    else
    {
        return FAILED;
    }

}

int elseIf() {
    printf("%-16s if_statement -> if ( boolean_expression ) { statementlist } else { statementlist }\n", cursor);
    if (*cursor == 'i') {
        cursor++;
        if (*cursor == 'f') {
            cursor++;
            if (*cursor == '('){
                cursor++;
                if (Arithmetic()) {
                    if (Relational()) {
                        if (Literal()) {
                            if (*cursor == ')') {
                                cursor++;
                                if (*cursor == '{'){
                                    cursor++;
                                    if(Print()){
                                        if(*cursor == '}'){
                                            cursor++;
                                            if (*cursor == 'e') {
                                                cursor++;
                                                if (*cursor == 'l') {
                                                    cursor++;
                                                    if (*cursor == 's') {
                                                        cursor++;
                                                        if (*cursor == 'e') {
                                                            cursor++;
                                                            if (*cursor == '{'){
                                                                cursor++;
                                                                if(Print()){
                                                                    if(*cursor == '}'){
                                                                        cursor++;
                                                                        return SUCCESS;
                                                                    }else{
                                                                        return FAILED;
                                                                    }
                                                                }
                                                                else{
                                                                    return FAILED;
                                                                }
                                                            }
                                                            else{
                                                                return FAILED;
                                                            }
                                                        }else{
                                                            return FAILED;
                                                        }
                                                    }else{
                                                        return FAILED;
                                                    }
                                                }else{
                                                    return FAILED;
                                                }
                                            }else{
                                                return FAILED;
                                            }
                                        }else{
                                            return FAILED;
                                        }
                                    }
                                    else{
                                        return FAILED;
                                    }
                                }
                                else{
                                    return FAILED;
                                }
                            }else{
                                return FAILED;
                            }
                        }else{
                            return FAILED;
                        }
                    }else{
                        return FAILED;
                    }
                }else{
                    return FAILED;
                }
            }else{
                return FAILED;
            }
        }else{
            return FAILED;
        }
    }
    else{
        return FAILED;
    }
}

int Print() {
    printf("%-16s print_statement -> print ( Literal ) ;\n", cursor);
    if (*cursor == 'p') {
        cursor++;
        if (*cursor == 'r') {
            cursor++;
            if (*cursor == 'i') {
                cursor++;
                if (*cursor == 'n') {
                    cursor++;
                    if (*cursor == 't') {
                        cursor++;
                        if (*cursor == '('){
                            cursor++;
                        
                                if(String()){
                                    
                                        if(*cursor == ')'){
                                            cursor++;
                                            if(*cursor == ';'){
                                                cursor++;
                                                return SUCCESS;
                                            }
                                            else{
                                                return FAILED;
                                            }
                                        }else{
                                            return FAILED;
                                        }
                                    
                                }else{
                                    return FAILED;
                                }
                           
                        }else{
                            return FAILED;
                        }
                    }else{
                        return FAILED;
                    }
                }
                else{
                    return FAILED;
                }
            }
            else{
                return FAILED;
            }
        }
        else{
            return FAILED;
        }
    }
    else{
        return FAILED;
    }
}

int Boolean() {
    printf("%-16s boolean ->  'true' | 'false'\n", cursor);
    if (*cursor == 't') {
        cursor++;
        if (*cursor == 'r') {
            cursor++;
            if (*cursor == 'u') {
                cursor++;
                if (*cursor == 'e') {
                    cursor++;
                    return SUCCESS;
                }else{
                    return FAILED;
                }
            }else{
                return FAILED;
            }
        }else{
            return FAILED;
        }
    }else if(*cursor == 'f'){
        cursor++;
        if(*cursor == 'a'){
            cursor++;
            if(*cursor == 'l'){
                cursor++;
                if(*cursor == 's'){
                    cursor++;
                    if(*cursor == 'e'){
                        cursor++;
                        return SUCCESS;
                    }else{
                        return FAILED;
                    }
                }else{
                    return FAILED;
                }
            }else{
                return FAILED;
            }
        }else{
            return FAILED;
        }
    }else{
        return FAILED;
    }

}

int Number() {
    if (*cursor >= '0' && *cursor <= '9') {
        while (*cursor >= '0' && *cursor <= '9') {
            printf("%-16s Number -> [0-9]+\n", cursor);
            cursor++;
        }
        return SUCCESS;
    } else {
        return FAILED;
    }
}

int String() {
    if (*cursor == '"') {
        cursor++; 
        while ((*cursor >= 'a' && *cursor <= 'z') || (*cursor >= 'A' && *cursor <= 'Z') || (*cursor >= '0' && *cursor <= '9') || *cursor == ' ') {
            cursor++; 
        }
        if (*cursor == '"') {
            cursor++;
            printf("%-16s String -> '\"' [a-zA-Z0-9\\s]+ '\"'\n", cursor);
            return SUCCESS;
        } else {
            return FAILED; 
        }
    } else {
        return FAILED;
    }
}

int DataType() {
    
    if (*cursor == 'i') {
        printf("%-16s DataType ->  'int'\n", cursor);
        cursor++;
        if (*cursor == 'n') {
            cursor++;
            if (*cursor == 't') {
                cursor++;
                return SUCCESS;
            }else{
                return FAILED;
            }
        }else{
            return FAILED;
        }
    }else if(*cursor == 'b'){
        printf("%-16s DataType -> 'boolean'\n", cursor);
        cursor++;
        if(*cursor == 'o'){
            cursor++;
            if(*cursor == 'o'){
                cursor++;
                if(*cursor == 'l'){
                    cursor++;
                    if(*cursor == 'e'){
                        cursor++;
                        if(*cursor == 'a'){
                            cursor++;
                            if(*cursor == 'n'){
                                cursor++;
                                return SUCCESS;
                            }else{
                                return FAILED;
                            }
                        }else{
                            return FAILED;
                        }
                    }else{
                        return FAILED;
                    }
                }else{
                    return FAILED;
                }
            }else{
                return FAILED;
            }
        }else{
            return FAILED;
        }
    }else if(*cursor == 's'){
        printf("%-16s DataType -> 'String'\n", cursor);
        cursor++;
        if(*cursor == 't'){
            cursor++;
            if(*cursor == 'r'){
                cursor++;
                if(*cursor == 'i'){
                    cursor++;
                    if(*cursor == 'n'){
                        cursor++;
                        if(*cursor == 'g'){
                            cursor++;
                            return SUCCESS;
                        }else{
                            return FAILED;
                        }
                    }else{
                        return FAILED;
                    }
                }else{
                    return FAILED;
                }
            }else{
                return FAILED;
            }
        }else{
            return FAILED;
        }
    }else{
        return FAILED;
    }

}

int Arithmetic() {
    if (Identifier()) {
        if (*cursor == '+') {
            printf("%-16s Arithmetic ->  Identifier '+' Identifier'\n", cursor);
            cursor++;
            if (Identifier()) {
                return SUCCESS;
            }else{
                return FAILED;
            }
        } else if (*cursor == '-') {
            printf("%-16s Arithmetic ->  Identifier '-' Identifier'\n", cursor);
            cursor++;
            if (Identifier()) {
                
                return SUCCESS;
            }else{
                return FAILED;
            }
        }else if (*cursor == '*') {
            printf("%-16s Arithmetic ->  Identifier '*' Identifier'\n", cursor);
            cursor++;
            if (Identifier()) {
                
                return SUCCESS;
            }else{
                return FAILED;
            }
        } else if (*cursor == '/') {
            printf("%-16s Arithmetic ->  Identifier '/' Identifier'\n", cursor);
            cursor++;
            if (Identifier()) {
                
                return SUCCESS;
            }else{
                return FAILED;
            }
        }  else {
            return FAILED;
        }
    } else {
        return FAILED;
    }
}

int Update() {
    if (Identifier()) {
        printf("%-16s Update ->  Identifier '=' Identifier RelationalOperator Literal ';'\n", cursor);
        if (*cursor == '=') { 
            cursor++;
            if (Identifier()){
                if (Relational()) {
                    if (Literal()){
                        if(*cursor == ';')
                        {
                            cursor++;
                            return SUCCESS;
                        }else{
                            return FAILED;
                        }
                    }else{
                        return FAILED;
                    }
                }else{
                    return FAILED;
                } 
            }else{
                return FAILED;
            }
        } 
        else{
            return FAILED;
        }
    }else{
        return FAILED;
    }
}

int Relational() {
    
    if (*cursor == '>') {
        cursor++;
        if (*cursor == '=') {
            printf("%-16s Relational ->  '>=''\n", cursor);
            cursor++;
            return SUCCESS;
        }else{
            return FAILED;
        }
    }if (*cursor == '<') {
        cursor++;
        if (*cursor == '=') {
            printf("%-16s Relational ->  '<=''\n", cursor);
            cursor++;
            return SUCCESS;
        }else{
            return FAILED;
        }
    }
    if (*cursor == '=') {
        cursor++;
        if (*cursor == '=') {
            printf("%-16s Relational ->  '==''\n", cursor);
            cursor++;
            return SUCCESS;
        }else{
            
            return FAILED;
        }
    }else{
        return FAILED;
    }

}

int Identifier() {
    if ((*cursor >= 'a' && *cursor <= 'z') || (*cursor >= 'A' && *cursor <= 'Z') || *cursor == '_') {
        printf("%-16s Identifier -> [a-zA-Z_][a-zA-Z0-9_]*\n", cursor);
        cursor++;
        while ((*cursor >= 'a' && *cursor <= 'z') || (*cursor >= 'A' && *cursor <= 'Z') || (*cursor >= '0' && *cursor <= '9') || *cursor == '_') {
            cursor++;
        }
        return SUCCESS;
    } else {
        return FAILED;
    }
}

int Literal() {
    if (Number() || Boolean() || String()) {
        printf("%-16s Literal -> Number | Boolean | String\n", cursor);
        return SUCCESS;
    } else {
        return FAILED;
    }
}
