#ifndef UIISLEMLERI_HPP
#define UIISLEMLERI_HPP

#include "TekYonluBagliListe.hpp"

// Kullanıcıdan tek bir karakter almak için
char getKey();


// Belirli bir sayfayı, imleç ile birlikte ekranda göstermek için
void displayPageWithCursor(ListNode** nodes, int totalNodes, int pageStartIndex, int cursorIndex, int pageSize);

// Bağlı listeden düğüm dizisini yeniden oluşturmak için
void rebuildNodesArray(LinkedList &treeList, ListNode** &nodes, int &totalNodes);

#endif
