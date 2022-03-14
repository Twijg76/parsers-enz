//
// Created by twijg on 1/2/22.
//

#ifndef SHUNTINGYARDPARSER_H
#define SHUNTINGYARDPARSER_H


#include "AST.h"
#include <string>
#include <stack>
#include <vector>
#include <memory>
#include <algorithm>

/** Een klasse die een shunting yard  parser van infix naar AST implementeert.
 *  Hoe werk ik met deze parser?
 *  Maak een nieuw object aan met shuntingYardParser().
 *  Gebruik splitExpression(string expr) om de correcte input te krijgen voor de parser.
 *  Gebruik shuntInfix(vector<string>) om een AST te krijgen.
 *  vb: AST tree = shuntInfix(splitExpression("3+(4*6)"));
 */
class shuntingYardParser {
public:
    /** Constructor, sets default values for the operators and the precedence.
     *
    */
    shuntingYardParser();

    /** Checks if the input argument is in the list of operators.
     *
     * @param in
     * @return
     */
    bool isOperator(const std::string&);

    /** Parse an infix expression to an AST using the Shunting Yard Algorithm
     * See: https://en.wikipedia.org/wiki/Shunting-yard_algorithm
     * Thanks to this comment: https://libreddit.kavin.rocks/r/learnprogramming/comments/3cybca/how_do_i_go_about_building_an_ast_from_an_infix/ct02uam/?context=3
     *
     * @param expr The expression in infix notation
     * @return AST
     */
    AST* shuntInfix(const std::vector<std::string>&);

    /** We splitsen een expressie op in alle stukjes (getallen, variabelen, operators) zodat de parser er mee overweg kan.
     *
     * @param expr
     * @return vector<string> stukjes
     */
    std::vector<std::string> splitExpression(const std::string& expr);

private:
    enum comp {higher, equal, lower};

    /** Add node to stack, houdt rekening met de wensen van de parser als het een operator is
     *
     * @param st
     * @param value
     */
    void addNode(std::stack<Node*> &st, const std::string &value);

    /** Compare the precedence from a and b
     *
     * @param a eerste operator
     * @param b tweede operator
     * @return enum equal if equal, higher if a > b and lower if a < b
     */
    comp comparePrecedence(const std::string &a, const std::string &b);

    std::vector<std::string> operators;
    std::vector<std::vector<std::string>> precedence; // Van hoog naar laag, hetzelfde is in hetzelfde element.
};

#endif
