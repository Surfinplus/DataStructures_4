#include "UIIslemleri.hpp"
#include "AgacIslemleri.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

char getKey() {
    char ch;
    // Basit tek karakter girişi
    cin >> ch;
    return ch;
}


void displayPageWithCursor(ListNode** nodes, int totalNodes, int pageStartIndex, int cursorIndex, int pageSize) {
    if (totalNodes == 0) {
        cout << "No nodes to display.\n\n\n\n";
        return;
    }

    int endIndex = pageStartIndex + pageSize;
    if (endIndex > totalNodes) endIndex = totalNodes;

    
    for (int i = pageStartIndex; i < endIndex; i++) {
        cout << setw(16) << right << nodes[i];
    }
        cout << "\n";

    // 2. satır: Her ağacın toplam değeri
    for (int i = pageStartIndex; i < endIndex; i++) {
        int totalValue = 0;
        if (nodes[i]->tree && nodes[i]->tree->root) {
            totalValue = calculateTreeValue(nodes[i]->tree->root, true, false);
        }
            cout << setw(16) << right << totalValue;
    }
        cout << "\n";

    
    for (int i = pageStartIndex; i < endIndex; i++) {
        if (nodes[i]->next)
            cout << setw(16) << right << nodes[i]->next;
        else
                cout << setw(16) << right << "0";
    }
        cout << "\n";

    
    for (int i = pageStartIndex; i < endIndex; i++) {
        if (i == cursorIndex)
            cout << setw(16) << right << "^^^^^^";
        else
            cout << setw(16) << right << "";
    }
        cout << "\n";
}

void rebuildNodesArray(LinkedList &treeList, ListNode** &nodes, int &totalNodes) {
    if (nodes) delete[] nodes;

    totalNodes = countListNodes(treeList);

    if (totalNodes > 0) {
        nodes = listToArray(treeList, totalNodes);
    } else {
        nodes = nullptr;
    }
}
