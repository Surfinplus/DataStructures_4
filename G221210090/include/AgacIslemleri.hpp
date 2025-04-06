#ifndef AGACISLEMLERI_HPP
#define AGACISLEMLERI_HPP

#include "IkiliAramaAgaclari.hpp"

int treeHeight(TreeNode* root);
int countNodes(TreeNode* root);
void printFancyTree(TreeNode* root);
int calculateTreeValue(TreeNode* node, bool isRoot = true, bool isLeftChild = false);
void mirrorTree(TreeNode* &root);

#endif
