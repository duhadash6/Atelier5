#include <iostream>
using namespace std;

// Template de fonction pour calculer le carré
template <typename T>
T carre(const T& valeur) {
    return valeur * valeur;
}

int main() {
    // Tests avec différents types
    cout << "Carré de 5 (int): " << carre(5) << endl;
    cout << "Carré de 4.5 (double): " << carre(4.5) << endl;
    cout << "Carré de 3.2f (float): " << carre(3.2f) << endl;
    
    return 0;
}