#include "IkiliAramaAgaclari.hpp"

TreeNode* BinaryTree::insertRec(TreeNode* node, char value) {
    if (!node) return new TreeNode(value);
    if (value < node->value)
        node->left = insertRec(node->left, value);
    else if (value > node->value)
        node->right = insertRec(node->right, value);
    return node;
}

void BinaryTree::insert(char value) {
    root = insertRec(root, value);
}
