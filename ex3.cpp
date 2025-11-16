// main.cpp
#include <iostream>

using namespace std;

// Fonction qui prend un vectok par valeur (test du constructeur par recopie)
void testTransmissionParValeur(vectok v) {
    cout << "Dans testTransmissionParValeur - Taille: " << v.taille() << endl;
    cout << "Contenu: ";
    v.afficher();
    
    // Modification locale
    v[0] = 999;
    cout << "Après modification locale: ";
    v.afficher();
}

// Fonction qui retourne un vectok (test du constructeur par recopie)
vectok creerVecteur() {
    vectok v(3);
    v[0] = 100;
    v[1] = 200;
    v[2] = 300;
    return v;
}

int main() {
    cout << "=== TEST DE LA CLASSE vectok ===" << endl << endl;
    
    // Test 1: Construction et accès basique
    cout << "1. Construction basique:" << endl;
    vectok v1(5);
    for (int i = 0; i < v1.taille(); i++) {
        v1[i] = i * 10;
    }
    cout << "v1: ";
    v1.afficher();
    cout << "Taille de v1: " << v1.taille() << endl << endl;
    
    // Test 2: Constructeur par recopie
    cout << "2. Test du constructeur par recopie:" << endl;
    vectok v2 = v1; // Appel du constructeur par recopie
    cout << "v2 (copie de v1): ";
    v2.afficher();
    
    // Modification de la copie pour vérifier l'indépendance
    v2[0] = 999;
    cout << "v2 après modification: ";
    v2.afficher();
    cout << "v1 original (doit être inchangé): ";
    v1.afficher();
    cout << endl;
    
    // Test 3: Opérateur d'affectation
    cout << "3. Test de l'opérateur d'affectation:" << endl;
    vectok v3(3);
    v3[0] = 1; v3[1] = 2; v3[2] = 3;
    cout << "v3 avant affectation: ";
    v3.afficher();
    
    v3 = v1; // Affectation
    cout << "v3 après v3 = v1: ";
    v3.afficher();
    
    // Test d'auto-affectation
    v3 = v3;
    cout << "v3 après auto-affectation: ";
    v3.afficher();
    cout << endl;
    
    // Test 4: Transmission par valeur
    cout << "4. Test de transmission par valeur:" << endl;
    cout << "v1 avant appel: ";
    v1.afficher();
    testTransmissionParValeur(v1);
    cout << "v1 après appel (doit être inchangé): ";
    v1.afficher();
    cout << endl;
    
    // Test 5: Retour par valeur
    cout << "5. Test de retour par valeur:" << endl;
    vectok v4 = creerVecteur();
    cout << "v4 (retour de fonction): ";
    v4.afficher();
    cout << endl;
    
    // Test 6: Affectation avec tailles différentes
    cout << "6. Test d'affectation avec tailles différentes:" << endl;
    vectok v5(2);
    v5[0] = 77; v5[1] = 88;
    cout << "v5 avant: ";
    v5.afficher();
    
    v5 = v1; // v1 a taille 5, v5 a taille 2
    cout << "v5 après v5 = v1: ";
    v5.afficher();
    cout << "Taille de v5: " << v5.taille() << endl;
    
    return 0;
}