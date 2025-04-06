#include "DosyaIslemleri.hpp"
#include "IkiliAramaAgaclari.hpp"
using namespace std;
void buildTreesAndList(ifstream& file, LinkedList& list) {
    char line[256];
    while (file.getline(line, 256)) {
        BinaryTree* tree = new BinaryTree();
        for (int i = 0; line[i] != '\0'; ++i) {
            tree->insert(line[i]);
        }
        list.append(tree);
    }
}
