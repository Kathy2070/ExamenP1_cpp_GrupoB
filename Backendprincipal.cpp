#include <iostream>
#include <string>
using namespace std;

class Vehiculo {
private:
string placa;
string tipo;
double capacidadTanque;
double kilometraje;
string estado;

public:
Vehiculo() {
placa = "";
tipo = "";
capacidadTanque = 0;
kilometraje = 0;
estado = "";
}

Vehiculo(string p, string t, double cap, double km, string est) {
    if(p == "") p = "SIN_PLACA";
    if(cap <= 0) cap = 1;
    if(km < 0) km = 0;
    if(est == "") est = "desconocido";

    placa = p;
    tipo = t;
    capacidadTanque = cap;
    kilometraje = km;
    estado = est;
}

string getPlaca() {
    return placa;
}

string getTipo() {
    return tipo;
}

double getCapacidadTanque() {
    return capacidadTanque;
}

double getKilometraje() {
    return kilometraje;
}

string getEstado() {
    return estado;
}

void mostrarDatos() {
    cout << "Vehiculo - Placa: " << placa
         << ", Tipo: " << tipo
         << ", Capacidad tanque: " << capacidadTanque << " L"
         << ", Kilometraje: " << kilometraje << " km"
         << ", Estado: " << estado << endl;
}
};

class Viaje {
private:
string ruta;
double distancia;
double litrosAbastecidos;
double litrosConsumidos;
string chofer;
string placaVehiculo;

public:
Viaje() {
ruta = "";
distancia = 0;
litrosAbastecidos = 0;
litrosConsumidos = 0;
chofer = "";
placaVehiculo = "";
}

Viaje(string r, double d, double abastecido, double consumido, string c, string placa) {
    if(d <= 0) {
        d = 1;
    }
    if(abastecido < 0) {
        abastecido = 0;
    }
    if(consumido < 0) {
        consumido = 0;
    }
    if(consumido > abastecido) {
        consumido = abastecido;
    }
    if(c == "") c = "SIN_CHOFER";
    if(placa == "") placa = "SIN_PLACA";

    ruta = r;
    distancia = d;
    litrosAbastecidos = abastecido;
    litrosConsumidos = consumido;
    chofer = c;
    placaVehiculo = placa;
}

string getRuta() {
    return ruta;
}

double getDistancia() {
    return distancia;
}

double getLitrosAbastecidos() {
    return litrosAbastecidos;
}

double getLitrosConsumidos() {
    return litrosConsumidos;
}

string getChofer() {
    return chofer;
}

string getPlacaVehiculo() {
    return placaVehiculo;
}

double calcularRendimiento() {
    double rendimiento;
    if(litrosConsumidos <= 0) {
        rendimiento = 0;
    } else {
        rendimiento = distancia / litrosConsumidos;
    }
    return rendimiento;
}

void mostrarDatos() {
    cout << "Viaje - Ruta: " << ruta
         << ", Chofer: " << chofer
         << ", Placa: " << placaVehiculo
         << ", Distancia: " << distancia << " km"
         << ", Litros consumidos: " << litrosConsumidos
         << ", Rendimiento: " << calcularRendimiento() << " km/l" << endl;
}
};

int main() {
Vehiculo vehiculos[50];
Viaje viajes[50];
int contadorVehiculos = 0;
int contadorViajes = 0;
int opcion;

do {
    cout << "\n===== MENU PRINCIPAL =====\n";
    cout << "1. Registrar Vehiculo\n";
    cout << "2. Registrar Viaje\n";
    cout << "3. Mostrar Vehiculos\n";
    cout << "4. Mostrar Viajes\n";
    cout << "0. Salir\n";
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    if(opcion == 1) {
        string placa, tipo, estado;
        double capacidad, km;
        cout << "Ingrese placa: "; cin >> placa;
        cout << "Ingrese tipo: "; cin >> tipo;
        cout << "Ingrese capacidad de tanque: "; cin >> capacidad;
        cout << "Ingrese kilometraje: "; cin >> km;
        cout << "Ingrese estado: "; cin >> estado;

        vehiculos[contadorVehiculos] = Vehiculo(placa, tipo, capacidad, km, estado);
        contadorVehiculos++;
        cout << "Vehiculo registrado correctamente.\n";
    }
    else if(opcion == 2) {
        string ruta, chofer, placa;
        double distancia, abastecido, consumido;
        cout << "Ingrese ruta: "; cin >> ruta;
        cout << "Ingrese distancia (km): "; cin >> distancia;
        cout << "Ingrese litros abastecidos: "; cin >> abastecido;
        cout << "Ingrese litros consumidos: "; cin >> consumido;
        cout << "Ingrese chofer: "; cin >> chofer;
        cout << "Ingrese placa del vehiculo: "; cin >> placa;

        viajes[contadorViajes] = Viaje(ruta, distancia, abastecido, consumido, chofer, placa);
        contadorViajes++;
        cout << "Viaje registrado correctamente.\n";
    }
    else if(opcion == 3) {
        cout << "\n--- Lista de Vehiculos ---\n";
        for(int i=0; i<contadorVehiculos; i++) {
            vehiculos[i].mostrarDatos();
        }
    }
    else if(opcion == 4) {
        cout << "\n--- Lista de Viajes ---\n";
        for(int i=0; i<contadorViajes; i++) {
            viajes[i].mostrarDatos();
        }
    }

} while(opcion != 0);

cout << "Programa finalizado.\n";
return 0;
}