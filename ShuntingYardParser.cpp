//
// Created by twijg on 1/2/22.
//


#include "ShuntingYardParser.h"

AST* shuntingYardParser::shuntInfix(const std::vector<std::string>& expr) {
    std::stack<std::string> operatorstack;
    std::stack<Node*> treestack;
    std::deque<std::string> output;

    for (const std::string& ch : expr) {
        if (ch == "(") {
            operatorstack.push("(");
        } else if (ch == ")") {
            bool found = false;
            while (not operatorstack.empty() && operatorstack.top() != "(") {
                output.push_back(operatorstack.top());
                addNode(treestack, operatorstack.top());
                operatorstack.pop();

                found = true;
            }
            if (operatorstack.empty()) {
                while (!treestack.empty()) {
                    delete treestack.top();
                    treestack.pop();
                }
                // error, mismatchte haakjes
                throw std::invalid_argument("The expression has mismatched brackets.");
            }
            operatorstack.pop();
            if (not found && operatorstack.empty()) {
                while (!treestack.empty()) {
                    delete treestack.top();
                    treestack.pop();
                }
                // error, mismatchte haakjes
                throw std::invalid_argument("The expression has mismatched brackets.");
            }

        } else if (isOperator(ch)) {

            while (not operatorstack.empty() and isOperator(operatorstack.top()) and comparePrecedence(operatorstack.top(), ch) == higher) {
                output.push_back(operatorstack.top());
                addNode(treestack, operatorstack.top());

                operatorstack.pop();
            }
            operatorstack.push(ch);

        } else { // getal of variabele
            output.push_back(ch);
            addNode(treestack, ch);

        }
    }
    while(!operatorstack.empty()) {
        output.push_back(operatorstack.top());
        addNode(treestack, operatorstack.top());
        operatorstack.pop();
    }
    if (treestack.size() != 1) { // linkerhaakje te veel
        while (!treestack.empty()) {
            delete treestack.top();
            treestack.pop();
        }
        throw std::invalid_argument("The expression has mismatched brackets.");
    }
    return new AST(treestack.top());
}


bool shuntingYardParser::isOperator(const std::string& in) {
    if (std::find(operators.begin(), operators.end(), in) != operators.end()){
        return true;
    }
    return false;
}
/*
** Een methode om na te kijken of een string een getal is.
 * Ik ben niet zeker of dit de beste implementatie is, deze kan dus veranderd
 * worden en kan dus beter los staan van alle andere code.
 *
 * @return isGetal?
 *
bool shuntingYardParser::isNumber(const std::string& line) {
    char* p;
    strtol(line.c_str(), &p, 10);
    return *p == 0;
}
*/

shuntingYardParser::comp shuntingYardParser::comparePrecedence(const std::string& a, const std::string& b) {
    bool founda = false;
    bool foundb = false;
    for (auto v : precedence) {
        founda = (std::find(v.begin(), v.end(), a) != v.end());
        foundb = (std::find(v.begin(), v.end(), b) != v.end());
        if (founda and foundb) {
            return equal;
        }
        if (founda) {
            return higher;
        }
        if (foundb) {
            return lower;
        }
    }
    throw std::invalid_argument("One of the operators is not an operator." );
    //error, een van beide is geen operator
}


shuntingYardParser::shuntingYardParser() {
    this->operators = {"+", "*", "-", "/", "^"};
    this->precedence = {{"^"}, {"*", "/"}, {"+", "-"}};
}



std::vector<std::string> shuntingYardParser::splitExpression(const std::string& expr) {
    std::string opslag;
    std::vector<std::string> out;
    std::string tmp;
    for (char ch : expr) {
        tmp = ch; // overload
        if (ch == '(' or ch ==')' or isOperator(tmp)) {
            if (!opslag.empty()) {
                out.push_back(opslag);
            }
            opslag = "";
            out.push_back(tmp);
        } else {
            opslag += ch;
        }
    }
    if (!opslag.empty()) {
        out.push_back(opslag);
    }
    return out;
}


void shuntingYardParser::addNode(std::stack<Node*>& st, const std::string& value) {
    Node* tmp = new Node(value);

    if (isOperator(value)) {
        tmp->right = st.top();
        st.pop();
        tmp->left = st.top();
        st.pop();
    }
    st.push(tmp);
}



