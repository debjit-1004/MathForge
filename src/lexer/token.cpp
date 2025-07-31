/**
 * @file token.cpp
 * @brief Token implementation
 */

#include "mathforge/lexer/token.hpp"
#include <unordered_map>

namespace mathforge::lexer {

const std::unordered_map<std::string, TokenType> TokenUtils::keywords_ = {
    {"theorem", TokenType::THEOREM},
    {"lemma", TokenType::LEMMA},
    {"proof", TokenType::PROOF},
    {"QED", TokenType::QED},
    {"assume", TokenType::ASSUME},
    {"let", TokenType::LET},
    {"by", TokenType::BY},
    {"therefore", TokenType::THEREFORE},
    {"hence", TokenType::HENCE},
    {"since", TokenType::SINCE},
    {"given", TokenType::GIVEN},
    {"if", TokenType::IF},
    {"then", TokenType::THEN},
    {"else", TokenType::ELSE},
    {"case", TokenType::CASE},
    {"induction", TokenType::INDUCTION},
    {"base", TokenType::BASE},
    {"step", TokenType::STEP},
    {"set", TokenType::SET},
    {"function", TokenType::FUNCTION},
    {"relation", TokenType::RELATION},
    {"real", TokenType::REAL},
    {"integer", TokenType::INTEGER},
    {"natural", TokenType::NATURAL},
    {"rational", TokenType::RATIONAL}
};

const std::unordered_map<TokenType, int> TokenUtils::precedence_ = {
    {TokenType::OR, 1},
    {TokenType::AND, 2},
    {TokenType::NOT, 3},
    {TokenType::IMPLIES, 4},
    {TokenType::IFF, 4},
    {TokenType::EQUALS, 5},
    {TokenType::NOT_EQUALS, 5},
    {TokenType::LESS_THAN, 5},
    {TokenType::GREATER_THAN, 5},
    {TokenType::LESS_EQUAL, 5},
    {TokenType::GREATER_EQUAL, 5},
    {TokenType::ELEMENT_OF, 6},
    {TokenType::NOT_ELEMENT_OF, 6},
    {TokenType::SUBSET, 6},
    {TokenType::PROPER_SUBSET, 6},
    {TokenType::SUPERSET, 6},
    {TokenType::UNION, 7},
    {TokenType::INTERSECTION, 7},
    {TokenType::SET_MINUS, 7},
    {TokenType::PLUS, 8},
    {TokenType::MINUS, 8},
    {TokenType::MULTIPLY, 9},
    {TokenType::DIVIDE, 9},
    {TokenType::POWER, 10}
};

std::string TokenUtils::tokenTypeToString(TokenType type) {
    switch (type) {
        case TokenType::IDENTIFIER: return "IDENTIFIER";
        case TokenType::NUMBER: return "NUMBER";
        case TokenType::STRING: return "STRING";
        case TokenType::PLUS: return "PLUS";
        case TokenType::MINUS: return "MINUS";
        case TokenType::MULTIPLY: return "MULTIPLY";
        case TokenType::DIVIDE: return "DIVIDE";
        case TokenType::POWER: return "POWER";
        case TokenType::EQUALS: return "EQUALS";
        case TokenType::NOT_EQUALS: return "NOT_EQUALS";
        case TokenType::LESS_THAN: return "LESS_THAN";
        case TokenType::GREATER_THAN: return "GREATER_THAN";
        case TokenType::LESS_EQUAL: return "LESS_EQUAL";
        case TokenType::GREATER_EQUAL: return "GREATER_EQUAL";
        case TokenType::AND: return "AND";
        case TokenType::OR: return "OR";
        case TokenType::NOT: return "NOT";
        case TokenType::IMPLIES: return "IMPLIES";
        case TokenType::IFF: return "IFF";
        case TokenType::ELEMENT_OF: return "ELEMENT_OF";
        case TokenType::NOT_ELEMENT_OF: return "NOT_ELEMENT_OF";
        case TokenType::SUBSET: return "SUBSET";
        case TokenType::PROPER_SUBSET: return "PROPER_SUBSET";
        case TokenType::SUPERSET: return "SUPERSET";
        case TokenType::UNION: return "UNION";
        case TokenType::INTERSECTION: return "INTERSECTION";
        case TokenType::SET_MINUS: return "SET_MINUS";
        case TokenType::FORALL: return "FORALL";
        case TokenType::EXISTS: return "EXISTS";
        case TokenType::LEFT_PAREN: return "LEFT_PAREN";
        case TokenType::RIGHT_PAREN: return "RIGHT_PAREN";
        case TokenType::LEFT_BRACKET: return "LEFT_BRACKET";
        case TokenType::RIGHT_BRACKET: return "RIGHT_BRACKET";
        case TokenType::LEFT_BRACE: return "LEFT_BRACE";
        case TokenType::RIGHT_BRACE: return "RIGHT_BRACE";
        case TokenType::COMMA: return "COMMA";
        case TokenType::SEMICOLON: return "SEMICOLON";
        case TokenType::COLON: return "COLON";
        case TokenType::DOT: return "DOT";
        case TokenType::THEOREM: return "THEOREM";
        case TokenType::LEMMA: return "LEMMA";
        case TokenType::PROOF: return "PROOF";
        case TokenType::QED: return "QED";
        case TokenType::ASSUME: return "ASSUME";
        case TokenType::LET: return "LET";
        case TokenType::BY: return "BY";
        case TokenType::THEREFORE: return "THEREFORE";
        case TokenType::HENCE: return "HENCE";
        case TokenType::SINCE: return "SINCE";
        case TokenType::GIVEN: return "GIVEN";
        case TokenType::IF: return "IF";
        case TokenType::THEN: return "THEN";
        case TokenType::ELSE: return "ELSE";
        case TokenType::CASE: return "CASE";
        case TokenType::INDUCTION: return "INDUCTION";
        case TokenType::BASE: return "BASE";
        case TokenType::STEP: return "STEP";
        case TokenType::SET: return "SET";
        case TokenType::FUNCTION: return "FUNCTION";
        case TokenType::RELATION: return "RELATION";
        case TokenType::REAL: return "REAL";
        case TokenType::INTEGER: return "INTEGER";
        case TokenType::NATURAL: return "NATURAL";
        case TokenType::RATIONAL: return "RATIONAL";
        case TokenType::NEWLINE: return "NEWLINE";
        case TokenType::INDENT: return "INDENT";
        case TokenType::DEDENT: return "DEDENT";
        case TokenType::END_OF_FILE: return "END_OF_FILE";
        case TokenType::INVALID: return "INVALID";
        default: return "UNKNOWN";
    }
}

bool TokenUtils::isMathOperator(TokenType type) {
    return type >= TokenType::PLUS && type <= TokenType::GREATER_EQUAL;
}

bool TokenUtils::isLogicalOperator(TokenType type) {
    return type >= TokenType::AND && type <= TokenType::IFF;
}

bool TokenUtils::isSetOperator(TokenType type) {
    return type >= TokenType::ELEMENT_OF && type <= TokenType::SET_MINUS;
}

bool TokenUtils::isQuantifier(TokenType type) {
    return type == TokenType::FORALL || type == TokenType::EXISTS;
}

bool TokenUtils::isKeyword(TokenType type) {
    return type >= TokenType::THEOREM && type <= TokenType::RATIONAL;
}

TokenType TokenUtils::getKeywordType(const std::string& word) {
    auto it = keywords_.find(word);
    return (it != keywords_.end()) ? it->second : TokenType::IDENTIFIER;
}

int TokenUtils::getOperatorPrecedence(TokenType type) {
    auto it = precedence_.find(type);
    return (it != precedence_.end()) ? it->second : 0;
}

} // namespace mathforge::lexer
