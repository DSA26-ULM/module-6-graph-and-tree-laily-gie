#include <iostream>
#include <vector>
#include <map>

int main() {
    int jumlahNode, jumlahEdge;
    std::cin >> jumlahNode;

    std::vector<char> daftarNode(jumlahNode);
    std::map<char, int> petaIndeks;

    for (int i = 0; i < jumlahNode; ++i) {
        std::cin >> daftarNode[i];
        petaIndeks[daftarNode[i]] = i;
    }

    std::vector<std::vector<int>> matriksBobot(jumlahNode, std::vector<int>(jumlahNode, 0));
    std::cin >> jumlahEdge;

    for (int i = 0; i < jumlahEdge; ++i) {
        char nodeU, nodeV; 
        int bobot;
        std::cin >> nodeU >> nodeV >> bobot;
        matriksBobot[petaIndeks[nodeU]][petaIndeks[nodeV]] = bobot;
    }

    std::cout << "Adjacency Matrix:" << std::endl;
    std::cout << " ";
    for (int i = 0; i < jumlahNode; ++i) {
        std::cout << " " << daftarNode[i];
    }
    
    std::cout << std::endl;
    for (int i = 0; i < jumlahNode; ++i) {
        std::cout << daftarNode[i];
        for (int j = 0; j < jumlahNode; ++j) {
            std::cout << " " << matriksBobot[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}