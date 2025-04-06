#ifndef IKILIARAMAAGACLARI_HPP
#define IKILIARAMAAGACLARI_HPP

struct TreeNode {
    char value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char val) : value(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    TreeNode* root;
    BinaryTree() : root(nullptr) {}
    void insert(char value);
private:
    TreeNode* insertRec(TreeNode* node, char value);
};

#endif
