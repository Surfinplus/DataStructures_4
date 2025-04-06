#include <iostream>
#include <fstream>
#include "AnaMenu.hpp"
#include "DosyaIslemleri.hpp"
#include "TekYonluBagliListe.hpp"
#include "UIIslemleri.hpp"
#include "AgacIslemleri.hpp"
#include "IkiliAramaAgaclari.hpp"

using namespace std;

void AnaMenu() {
    ifstream inputFile("agaclar.txt");
    if (!inputFile) {
        cerr << "Error: Unable to open file agaclar.txt" << endl;
        return; // Dosya açılamadıysa menüden çık
    }

    LinkedList treeList;
    buildTreesAndList(inputFile, treeList);
    inputFile.close();

    int totalNodes = countListNodes(treeList);
    ListNode** nodes = nullptr;
    if (totalNodes > 0) {
        nodes = listToArray(treeList, totalNodes);
    }

    const int pageSize = 10; 
    int cursorIndex = 0;
    int pageStartIndex = 0;

    char command;
    system("cls");
    do {
        
        cout << "Displaying Linked List Information:\n";
        displayPageWithCursor(nodes, totalNodes, pageStartIndex, cursorIndex, pageSize);

        cout << "\nCurrent Tree (Node " << (totalNodes > 0 ? (cursorIndex+1) : 0) << "):\n";
        if (totalNodes > 0 && nodes[cursorIndex]->tree && nodes[cursorIndex]->tree->root) {
            printFancyTree(nodes[cursorIndex]->tree->root);
        } else {
            if (totalNodes == 0) 
                cout << "No tree.\n";
            else
                cout << "Empty tree.\n";
        }

        cout << "\nUse 'a' to move left, 'd' to move right, 's' to delete current node, 'w' to mirror current tree, 'q' to quit." << endl;
        command = getKey(); 

        if (command == 'a') {
            system("cls");
            if (totalNodes > 0 && cursorIndex > 0) {
                cursorIndex--;
            }
        } 
        else if (command == 'd') {
            system("cls");
            if (totalNodes > 0 && cursorIndex < totalNodes - 1) {
                cursorIndex++;
            }
        } 
        else if (command == 's') {
            system("cls");
            if (totalNodes > 0) {
                int nodeToDelete = cursorIndex;
                deleteNode(treeList, nodeToDelete);
                rebuildNodesArray(treeList, nodes, totalNodes);
                if (nodeToDelete > 0) {
                    cursorIndex = nodeToDelete - 1;
                } else {
                    cursorIndex = 0;
                }
                if (totalNodes == 0) {
                    cursorIndex = 0;
                }
                pageStartIndex = (cursorIndex / pageSize) * pageSize;
            }
        } 
        else if (command == 'w') {
            system("cls");
            if (totalNodes > 0 && nodes[cursorIndex]->tree && nodes[cursorIndex]->tree->root) {
                mirrorTree(nodes[cursorIndex]->tree->root);
            }
        }

        if (totalNodes > 0) {
            pageStartIndex = (cursorIndex / pageSize) * pageSize;
        } else {
            pageStartIndex = 0;
        }

        system("cls");

    } while (command != 'q');

    system("cls");
    cout << "!QUIT!\n";
    if (nodes) delete[] nodes;
}
