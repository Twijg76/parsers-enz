
#ifndef AST_H
#define AST_H


#include <string>
#include <vector>
#include <map>
#include <stdexcept>


/**
 * @class Node
 * @brief Represents an AST node.
 */
class Node {
public:
    /** The value of the node. */
    std::string value;
    /** The left child node. Can be nullptr. */
    Node* left;
    /** The right child node. Can be nullptr. */
    Node* right;


    /** Constructs a node with a value.
     *
     */
    explicit Node(std::string);

    /** Default constructor.
     *
     */
    Node();
    /** Destructor. Frees all memory of children as well.
     *
     */
    ~Node();

    /** Helperfunctie voor de post order traversal
     *
     * @param out
     */
    void Posthelper(std::vector<std::string> &out) const;
};

/**
 * @class AST
 * @brief Represents an abstract syntax tree for a mathematical expression.
 */
class AST {
public:
    /** Constructor by root pointer.
     *
     * @param root
     */
    explicit AST(Node* root);
    ~AST();

    /** Doet post order traversal en returnt RPN, in de vorm van een vector van strings.
     *
     * @return
     */
    std::vector<std::string> Posttraverse();

private:
    Node* root;
};

#endif
