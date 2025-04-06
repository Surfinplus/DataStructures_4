#include <iostream>
#include <string>
#include <iomanip>
#include "AgacIslemleri.hpp"
using namespace std;
struct NodePos {
    TreeNode* node;
    int row;
    int col;
};

// Ağacı inorder gezip (row, col) atayan sayaç
static int inorderCounter = 0;

// Sağ kaydırma miktarı (sabiti istediğiniz kadar büyütebilirsiniz)
static const int SHIFT = 10;

static void assignPositions(TreeNode* root, NodePos* arr, int level) {
    if (!root) return;

    assignPositions(root->left, arr, level + 1);

    // row = derinliğe göre 3 kat
    arr[inorderCounter].row = level * 3;
    // col = inorder sırasına göre 3 kat, + SHIFT ekliyoruz
    arr[inorderCounter].col = inorderCounter * 3 + SHIFT;
    arr[inorderCounter].node = root;

    inorderCounter++;

    assignPositions(root->right, arr, level + 1);
}

static int findNodeIndex(NodePos* arr, int total, TreeNode* node) {
    for (int i = 0; i < total; i++) {
        if (arr[i].node == node) return i;
    }
    return -1;
}

static void drawConnections(TreeNode* root, NodePos* arr, int total, char** mat) {
    if (!root) return;
    int p = findNodeIndex(arr, total, root);
    if (p == -1) return;

    int pr = arr[p].row;
    int pc = arr[p].col;

    // For left child
    if (root->left) {
        int c = findNodeIndex(arr, total, root->left);
        if (c != -1) {
            int cc = arr[c].col;
            mat[pr + 1][pc] = '.';
            int start = (pc < cc) ? pc : cc;
            int end   = (pc < cc) ? cc : pc;
            for (int i = start; i <= end; i++) {
                mat[pr + 1][i] = '.';
            }
            mat[pr + 2][cc] = '.';
        }
    }

    // For right child
    if (root->right) {
        int c = findNodeIndex(arr, total, root->right);
        if (c != -1) {
            int cc = arr[c].col;
            mat[pr + 1][pc] = '.';
            int start = (pc < cc) ? pc : cc;
            int end   = (pc < cc) ? cc : pc;
            for (int i = start; i <= end; i++) {
                mat[pr + 1][i] = '.';
            }
            mat[pr + 2][cc] = '.';
        }
    }

    // Rekürsif devam
    drawConnections(root->left, arr, total, mat);
    drawConnections(root->right, arr, total, mat);
}

int treeHeight(TreeNode* root) {
    if (!root) return 0;
    int hl = treeHeight(root->left);
    int hr = treeHeight(root->right);
    return 1 + (hl > hr ? hl : hr);
}

int countNodes(TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void printFancyTree(TreeNode* root) {
    if (!root) {
        cout << "Empty tree.\n";
        return;
    }

    int total = countNodes(root);
    int h = treeHeight(root);

    if (total == 0) {
        cout << "Empty tree.\n";
        return;
    }

    // Önce NodePos dizisini doldur
    NodePos* arr = new NodePos[total];
    inorderCounter = 0;
    assignPositions(root, arr, 0);

    // rows: yükseklik * 3 + biraz pay
    int rows = h * 3 + 3;
    // cols: total * 3 + SHIFT (kaydırma) + biraz pay
    int cols = total * 3 + SHIFT + 3;

    // 2D mat bellek al
    char** mat = new char*[rows];
    for (int i = 0; i < rows; i++) {
        mat[i] = new char[cols];
        for (int j = 0; j < cols; j++) {
            mat[i][j] = ' ';
        }
    }

    // Düğümlerin değerlerini mat'e yerleştir
    for (int i = 0; i < total; i++) {
        mat[arr[i].row][arr[i].col] = arr[i].node->value; 
        // Eğer node->value int ise char'a çevirmeniz gerekir!
    }

    // Bağlantıları çiz
    drawConnections(root, arr, total, mat);

    // Her satırı, son boşlukları kırparak ekrana bas
    for (int i = 0; i < rows; i++) {
        int endPos = cols - 1;
        while (endPos >= 0 && mat[i][endPos] == ' ') endPos--;
        if (endPos < 0) {
            // Boş satır
            continue;
        }
        for (int j = 0; j <= endPos; j++) {
            cout << mat[i][j];
        }
            cout << "\n";
    }

    // Bellek temizliği
    for (int i = 0; i < rows; i++) {
        delete[] mat[i];
    }
    delete[] mat;
    delete[] arr;
}

// Ağaç değerini hesaplayan fonksiyon
int calculateTreeValue(TreeNode* node, bool isRoot, bool isLeftChild) {
    if (!node) return 0;

    int val = (int)node->value;
    if (!isRoot) {
        if (isLeftChild) {
            val *= 2; // Sol çocukta örnek işlem
        }
    }

    int leftVal  = calculateTreeValue(node->left,  false, true);
    int rightVal = calculateTreeValue(node->right, false, false);

    return val + leftVal + rightVal;
}

// Ağacı ayna görüntüsüne çeviren fonksiyon
void mirrorTree(TreeNode* &root) {
    if (!root) return;
    mirrorTree(root->left);
    mirrorTree(root->right);
    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
}
