#include <iostream>
#include <stdexcept>
using namespace std;

class Stack {
private:
    int* data;
    int capacity;
    int top;
    
    // Empêcher l'affectation
    Stack& operator=(const Stack&) = delete;
    
public:
    // Constructeur
    Stack(int size = 20) : capacity(size), top(-1) {
        if (size <= 0) {
            throw invalid_argument("Taille de pile invalide");
        }
        data = new int[capacity];
    }
    
    // Constructeur par recopie
    Stack(const Stack& other) : capacity(other.capacity), top(other.top) {
        data = new int[capacity];
        for (int i = 0; i <= top; i++) {
            data[i] = other.data[i];
        }
    }
    
    // Destructeur
    ~Stack() {
        delete[] data;
    }
    
    // Opérateur << (empiler)
    Stack& operator<<(int value) {
        if (top >= capacity - 1) {
            throw overflow_error("Pile pleine");
        }
        data[++top] = value;
        return *this;
    }
    
    // Opérateur >> (dépiler)
    Stack& operator>>(int& value) {
        if (top < 0) {
            throw underflow_error("Pile vide");
        }
        value = data[top--];
        return *this;
    }
    
    // Opérateur ++ (test pile pleine)
    bool operator++() const {
        return top >= capacity - 1;
    }
    
    // Opérateur -- (test pile vide)
    bool operator--() const {
        return top < 0;
    }
    
    // Méthodes supplémentaires
    int getSize() const { return top + 1; }
    int getCapacity() const { return capacity; }
    
    // Affichage (pour debug)
    void afficher() const {
        cout << "Pile [";
        for (int i = 0; i <= top; i++) {
            cout << data[i];
            if (i < top) cout << ", ";
        }
        cout << "]" << endl;
    }
};

// Programme de test
int main() {
    try {
        // Test création et empilage
        Stack p(5);
        cout << "Création d'une pile de capacité 5" << endl;
        
        // Empilage multiple
        p << 10 << 20 << 30;
        cout << "Après empilage de 10, 20, 30:" << endl;
        p.afficher();
        
        // Test dépilage
        int a, b;
        p >> a >> b;
        cout << "Dépilage: " << a << ", " << b << endl;
        p.afficher();
        
        // Test pile pleine
        p << 40 << 50 << 60 << 70;
        cout << "Après nouvel empilage:" << endl;
        p.afficher();
        
        cout << "Pile pleine? " << (++p ? "Oui" : "Non") << endl;
        cout << "Pile vide? " << (--p ? "Oui" : "Non") << endl;
        
        // Test transmission par valeur
        Stack p2 = p; // Constructeur par recopie
        cout << "Copie de la pile:" << endl;
        p2.afficher();
        
    } catch (const exception& e) {
        cerr << "Erreur: " << e.what() << endl;
    }
    
    return 0;
}