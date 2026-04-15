#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    vector<string> palabras = {"computadora", "programacion", "ahorcado", "visual", "teclado"};
    
    srand(time(0));
    string palabra = palabras[rand() % palabras.size()];
    
    string progreso(palabra.length(), '_');
    int intentos = 6;
    char letra;
    bool acierto;

    cout << "=== JUEGO DEL AHORCADO ===" << endl;

    while (intentos > 0 && progreso != palabra) {
        cout << "\nPalabra: ";
        for (char c : progreso) {
            cout << c << " ";
        }

        cout << "\nIntentos restantes: " << intentos;
        cout << "\nIngresa una letra: ";
        cin >> letra;

        acierto = false;

        for (int i = 0; i < palabra.length(); i++) {
            if (palabra[i] == letra && progreso[i] == '_') {
                progreso[i] = letra;
                acierto = true;
            }
        }

        if (!acierto) {
            intentos--;
            cout << "Letra incorrecta!" << endl;
        } else {
            cout << "Buen trabajo!" << endl;
        }
    }

    if (progreso == palabra) {
        cout << "\nFelicidades! Adivinaste la palabra: " << palabra << endl;
    } else {
        cout << "\nPerdiste. La palabra era: " << palabra << endl;
    }

    return 0;
}