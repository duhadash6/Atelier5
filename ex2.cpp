#include <iostream>
#include <stdexcept>
#include <limits>
using namespace std;

class Test {
public:
    static int tableau[];
    static const int taille = 10; // Taille fixe du tableau
    
public:
    static int division(int indice, int diviseur) {
        // Vérification de l'indice
        if (indice < 0 || indice >= taille) {
            throw out_of_range("Erreur : Indice hors limites. L'indice doit être entre 0 et " + to_string(taille - 1));
        }
        
        // Vérification de la division par zéro
        if (diviseur == 0) {
            throw invalid_argument("Erreur : Division par zéro impossible");
        }
        
        // Vérification de la division qui donnerait un résultat non entier
        // (optionnel, selon les besoins)
        if (tableau[indice] % diviseur != 0) {
            throw runtime_error("Erreur : La division ne donne pas un résultat entier");
        }
        
        return tableau[indice] / diviseur;
    }
};

int Test::tableau[] = {17, 12, 15, 38, 29, 157, 89, -22, 0, 5};
const int Test::taille;

int main() {
    int x, y;
    bool calculReussi = false;
    
    while (!calculReussi) {
        try {
            cout << "Entrez l'indice de l'entier à diviser: " << endl;
            cin >> x;
            
            // Vérification de l'entrée utilisateur
            if (cin.fail()) {
                cin.clear(); // Efface l'état d'erreur
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Vide le buffer
                throw invalid_argument("Erreur : Veuillez entrer un nombre entier valide");
            }
            
            cout << "Entrez le diviseur: " << endl;
            cin >> y;
            
            // Vérification de l'entrée utilisateur
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Erreur : Veuillez entrer un nombre entier valide");
            }
            
            cout << "Le résultat de la division est: " << endl;
            int resultat = Test::division(x, y);
            cout << resultat << endl;
            
            calculReussi = true; // Le calcul a réussi, on sort de la boucle
            
        } catch (const out_of_range& e) {
            cerr << e.what() << endl;
            cerr << "Veuillez réessayer." << endl << endl;
            
        } catch (const invalid_argument& e) {
            cerr << e.what() << endl;
            cerr << "Veuillez réessayer." << endl << endl;
            
        } catch (const runtime_error& e) {
            cerr << e.what() << endl;
            cerr << "Veuillez réessayer." << endl << endl;
            
        } catch (const exception& e) {
            cerr << "Erreur inattendue : " << e.what() << endl;
            cerr << "Arrêt du programme." << endl;
            return 1;
            
        } catch (...) {
            cerr << "Erreur inconnue." << endl;
            cerr << "Arrêt du programme." << endl;
            return 1;
        }
    }
    
    cout << "Calcul terminé avec succès!" << endl;
    return 0;
}