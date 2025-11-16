template <class T> 
class point {
    T x, y;
public:
    point(T abs, T ord) { x = abs; y = ord; }
    void affiche();
};

template <class T> 
void point<T>::affiche() {
    cout << "Coordonnees : " << static_cast<int>(x) << " " << static_cast<int>(y) << "\n";
}