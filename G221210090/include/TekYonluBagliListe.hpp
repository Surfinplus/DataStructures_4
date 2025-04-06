#ifndef TEKYONLUBAGLILISTE_HPP
#define TEKYONLUBAGLILISTE_HPP

#include "IkiliAramaAgaclari.hpp"

struct ListNode {
    BinaryTree* tree;
    ListNode* next;

    ListNode(BinaryTree* t) : tree(t), next(nullptr) {}
};

class LinkedList {
public:
    ListNode* head;
    LinkedList() : head(nullptr) {}
    void append(BinaryTree* tree);
};

int countListNodes(LinkedList &list);
ListNode** listToArray(LinkedList &list, int &totalNodes);
void deleteNode(LinkedList &list, int index); // Sildiğimiz node fonk buraya taşınabilir

#endif
