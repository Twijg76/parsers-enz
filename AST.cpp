#include "AST.h"
#include "Utilities.h"

void Node::Posthelper(std::vector<std::string>& out) const {
    if (left != nullptr) {
        left->Posthelper(out);
    }
    if (right != nullptr) {
        right->Posthelper(out);
    }
    out.emplace_back(value);

}
std::vector<std::string> AST::Posttraverse() {
    std::vector<std::string> out;
    root->Posthelper(out);
    return out;
}


AST::AST(Node* root) : root(root) {

}

AST::~AST() {
    delete root;
}

Node::Node(std::string value) {
    this->value = std::move(value);
    this->left = nullptr;
    this->right = nullptr;
}

Node::Node() {
    left = nullptr;
    right = nullptr;
}


Node::~Node() {
    delete left;
    delete right;
}
