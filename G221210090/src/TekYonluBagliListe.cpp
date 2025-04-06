#include "TekYonluBagliListe.hpp"

void LinkedList::append(BinaryTree* tree) {
    ListNode* newNode = new ListNode(tree);
    if (!head) {
        head = newNode;
    } else {
        ListNode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int countListNodes(LinkedList &list) {
    int count = 0;
    ListNode* current = list.head;
    while (current) {
        count++;
        current = current->next;
    }
    return count;
}

ListNode** listToArray(LinkedList &list, int &totalNodes) {
    totalNodes = countListNodes(list);
    if (totalNodes == 0) return nullptr;

    ListNode** nodes = new ListNode*[totalNodes];
    ListNode* current = list.head;
    int index = 0;
    while (current) {
        nodes[index++] = current;
        current = current->next;
    }
    return nodes;
}

void deleteNode(LinkedList &list, int index) {
    if (!list.head) return;

    ListNode* current = list.head;
    ListNode* prev = nullptr;
    int i = 0;
    while (current && i < index) {
        prev = current;
        current = current->next;
        i++;
    }

    if (!current) return;

    delete current->tree;

    if (!prev) {
        list.head = current->next;
    } else {
        prev->next = current->next;
    }

    delete current;
}
