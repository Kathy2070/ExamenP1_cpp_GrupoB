#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// ===================== CLASE VEHICULO =====================
class Vehiculo {
private:
    string placa, tipo, estado;
    double capacidadTanque, kilometraje;

public:
    Vehiculo() {
        placa = "SIN_PLACA";
        tipo = "";
        estado = "desconocido";
        capacidadTanque = 1;
        kilometraje = 0;
    }

    Vehiculo(string p, string t, double cap, double km, string est) {
        placa = (p == "") ? "SIN_PLACA" : p;
        tipo = t;
        capacidadTanque = (cap <= 0) ? 1 : cap;
        kilometraje = (km < 0) ? 0 : km;
        estado = (est == "") ? "desconocido" : est;
    }

    string getPlaca() const { return placa; }

    void mostrarDatos() const {
        cout << "Vehiculo - " << placa << ", " << tipo
             << ", " << kilometraje << " km\n";
    }
};

// ===================== CLASE VIAJE =====================
class Viaje {
private:
    string ruta, chofer, placaVehiculo;
    double distancia, abastecido, consumido;

public:
    Viaje() {
        ruta = ""; distancia = 1;
        abastecido = consumido = 0;
        chofer = "SIN_CHOFER";
        placaVehiculo = "SIN_PLACA";
    }

    Viaje(string r, double d, double a, double c, string ch, string p) {
        ruta = r;
        distancia = (d <= 0) ? 1 : d;
        abastecido = (a < 0) ? 0 : a;
        consumido = (c < 0) ? 0 : c;
        if (consumido > abastecido) consumido = abastecido;
        chofer = (ch == "") ? "SIN_CHOFER" : ch;
        placaVehiculo = (p == "") ? "SIN_PLACA" : p;
    }

    string getChofer() const { return chofer; }
    string getPlacaVehiculo() const { return placaVehiculo; }

    double calcularRendimiento() const {
        if (consumido <= 0) return 0;
        return distancia / consumido;
    }

    void mostrarDatos() const {
        cout << "Viaje - " << ruta
             << ", Chofer: " << chofer
             << ", Placa: " << placaVehiculo
             << ", Rendimiento: " << calcularRendimiento() << " km/l\n";
    }
};

// ===================== FUNCIONES =====================
void ordenarViajesPorRendimiento(vector<Viaje> &viajes) {
    for (int i = 0; i < viajes.size() - 1; i++) {
        for (int j = 0; j < viajes.size() - i - 1; j++) {
            if (viajes[j].calcularRendimiento() > viajes[j+1].calcularRendimiento()) {
                swap(viajes[j], viajes[j+1]);
            }
        }
    }
    cout << "Ordenado correctamente.\n";
}

void buscarPorPlaca(const vector<Vehiculo> &vehiculos, const vector<Viaje> &viajes, string placa) {
    for (auto &v : vehiculos)
        if (v.getPlaca() == placa) v.mostrarDatos();

    for (auto &v : viajes)
        if (v.getPlacaVehiculo() == placa) v.mostrarDatos();
}

void buscarChoferRec(const vector<Viaje> &viajes, string chofer, int i) {
    if (i >= viajes.size()) return;
    if (viajes[i].getChofer() == chofer)
        viajes[i].mostrarDatos();
    buscarChoferRec(viajes, chofer, i+1);
}

void reporteCriticos(const vector<Viaje> &viajes) {
    for (auto &v : viajes)
        if (v.calcularRendimiento() < 5)
            v.mostrarDatos();
}

// ===================== CLASE AHORCADO =====================
class Ahorcado {
private:
    string palabra, progreso;
    int intentos;

public:
    Ahorcado(string p) {
        palabra = p;
        progreso = string(p.length(), '_');
        intentos = 6;
    }

    void mostrar() {
        cout << "\nPalabra: ";
        for (char c : progreso) cout << c << " ";
        cout << "\nIntentos: " << intentos << endl;
    }

    void jugar(char l) {
        bool ok = false;
        for (int i = 0; i < palabra.length(); i++) {
            if (palabra[i] == l) {
                progreso[i] = l;
                ok = true;
            }
        }
        if (!ok) intentos--;
    }

    bool fin() { return intentos == 0 || progreso == palabra; }

    void resultado() {
        if (progreso == palabra)
            cout << "Ganaste!\n";
        else
            cout << "Perdiste! Era: " << palabra << endl;
    }
};

// ===================== MAIN =====================
int main() {
    vector<Vehiculo> vehiculos;
    vector<Viaje> viajes;

    vector<string> palabras = {"auto", "viaje", "motor", "ruta"};
    srand(time(0));

    int op;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Registrar Vehiculo\n";
        cout << "2. Registrar Viaje\n";
        cout << "3. Mostrar Vehiculos\n";
        cout << "4. Mostrar Viajes\n";
        cout << "5. Ordenar Viajes\n";
        cout << "6. Buscar por Placa\n";
        cout << "7. Buscar por Chofer\n";
        cout << "8. Reporte Criticos\n";
        cout << "9. Jugar Ahorcado\n";
        cout << "0. Salir\n";
        cin >> op;

        if (op == 1) {
            string p,t,e; double c,k;
            cin >> p >> t >> c >> k >> e;
            vehiculos.push_back(Vehiculo(p,t,c,k,e));
        }
        else if (op == 2) {
            string r,ch,p; double d,a,c;
            cin >> r >> d >> a >> c >> ch >> p;
            viajes.push_back(Viaje(r,d,a,c,ch,p));
        }
        else if (op == 3)
            for (auto &v : vehiculos) v.mostrarDatos();

        else if (op == 4)
            for (auto &v : viajes) v.mostrarDatos();

        else if (op == 5)
            ordenarViajesPorRendimiento(viajes);

        else if (op == 6) {
            string p; cin >> p;
            buscarPorPlaca(vehiculos, viajes, p);
        }

        else if (op == 7) {
            string ch; cin >> ch;
            buscarChoferRec(viajes, ch, 0);
        }

        else if (op == 8)
            reporteCriticos(viajes);

        else if (op == 9) {
            string palabra = palabras[rand()%palabras.size()];
            Ahorcado juego(palabra);
            char l;
            while (!juego.fin()) {
                juego.mostrar();
                cin >> l;
                juego.jugar(l);
            }
            juego.resultado();
        }

    } while(op != 0);

    return 0;
}