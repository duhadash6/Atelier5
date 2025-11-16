#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <string>
#include <array>

// 1. Création du set d'entiers
std::set<int> createIntSet() {
    std::set<int> intSet;
    for (int i = 1; i <= 100; ++i) {
        intSet.insert(i);
    }
    return intSet;
}

// 2. Fonction de recherche avec set
bool searchInSet(const std::set<int>& mySet, int value) {
    return mySet.find(value) != mySet.end();
}

// 3. Fonction avec itérateurs de set
bool searchWithIterators(std::set<int>::iterator begin, 
                        std::set<int>::iterator end, 
                        int value) {
    for (auto it = begin; it != end; ++it) {
        if (*it == value) {
            return true;
        }
    }
    return false;
}

// 4. Version template avec itérateurs génériques
template<typename Iterator, typename T>
bool searchTemplate(Iterator begin, Iterator end, const T& value) {
    for (Iterator it = begin; it != end; ++it) {
        if (*it == value) {
            return true;
        }
    }
    return false;
}

int main() {
    // Test de la création du set
    std::set<int> mySet = createIntSet();
    std::cout << "Set créé avec " << mySet.size() << " éléments." << std::endl;
    
    // Test de la fonction avec set
    std::cout << "\nTest avec fonction set:" << std::endl;
    std::cout << "50 dans le set: " << searchInSet(mySet, 50) << std::endl;
    std::cout << "150 dans le set: " << searchInSet(mySet, 150) << std::endl;
    
    // Test avec itérateurs de set
    std::cout << "\nTest avec itérateurs set:" << std::endl;
    std::cout << "25 dans le set: " << searchWithIterators(mySet.begin(), mySet.end(), 25) << std::endl;
    
    // EXEMPLES D'APPEL AVEC LA VERSION TEMPLATE
    
    // 1. Vecteur de strings
    std::vector<std::string> stringVector = {"apple", "banana", "cherry", "date"};
    std::cout << "\nTest avec vecteur de strings:" << std::endl;
    std::cout << "'banana' trouvé: " << searchTemplate(stringVector.begin(), stringVector.end(), std::string("banana")) << std::endl;
    std::cout << "'orange' trouvé: " << searchTemplate(stringVector.begin(), stringVector.end(), std::string("orange")) << std::endl;
    
    // 2. Liste d'entiers
    std::list<int> intList = {10, 20, 30, 40, 50};
    std::cout << "\nTest avec liste d'entiers:" << std::endl;
    std::cout << "30 trouvé: " << searchTemplate(intList.begin(), intList.end(), 30) << std::endl;
    std::cout << "35 trouvé: " << searchTemplate(intList.begin(), intList.end(), 35) << std::endl;
    
    // 3. Tableau classique de float
    float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    int arraySize = sizeof(floatArray) / sizeof(floatArray[0]);
    std::cout << "\nTest avec tableau classique de float:" << std::endl;
    std::cout << "3.3 trouvé: " << searchTemplate(floatArray, floatArray + arraySize, 3.3f) << std::endl;
    std::cout << "6.6 trouvé: " << searchTemplate(floatArray, floatArray + arraySize, 6.6f) << std::endl;
    
    // Test supplémentaire avec le set original
    std::cout << "\nTest template avec set d'entiers:" << std::endl;
    std::cout << "75 trouvé: " << searchTemplate(mySet.begin(), mySet.end(), 75) << std::endl;
    std::cout << "200 trouvé: " << searchTemplate(mySet.begin(), mySet.end(), 200) << std::endl;
    
    return 0;
}