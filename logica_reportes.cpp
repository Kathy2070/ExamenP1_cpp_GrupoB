#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>  
using namespace std;

//ordenar viajes rendimento (metodo burbuja)
void ordenarViajesPorRendimiento(vector<Viaje> &viajes) {
    int n = viajes.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (viajes[j].calcularRendimiento() > viajes[j+1].calcularRendimiento()) {
                Viaje temp = viajes[j];
                viajes[j] = viajes[j+1];
                viajes[j+1] = temp;
            }
        }
    }
    cout << "Viajes ordenados por rendimiento (menor a mayor).\n";
}
//busqueda de placa
void buscarPorPlaca(const vector<Vehiculo> &vehiculos, const vector<Viaje> &viajes, string placa) {
    bool encontrado = false;
    cout << "\n--- Vehiculos con placa " << placa << " ---\n";
    for (int i = 0; i < vehiculos.size(); i++) {
        if (vehiculos[i].getPlaca() == placa) {
            vehiculos[i].mostrarDatos();
            encontrado = true;
        }
    }
    cout << "\n--- Viajes con placa " << placa << " ---\n";
    for (int i = 0; i < viajes.size(); i++) {
        if (viajes[i].getPlacaVehiculo() == placa) {
            viajes[i].mostrarDatos();
            encontrado = true;
        }
    }
    if (!encontrado) cout << "No se encontraron resultados para la placa: " << placa << endl;
}
//busqueda de chofer con recursividad
void buscarChoferRecursivo(const vector<Viaje> &viajes, string chofer, int indice, bool &encontrado) {
    if (indice >= viajes.size()) return;
    if (viajes[indice].getChofer() == chofer) {
        viajes[indice].mostrarDatos();
        encontrado = true;
    }
    buscarChoferRecursivo(viajes, chofer, indice + 1, encontrado);
}

void buscarPorChofer(const vector<Viaje> &viajes, string chofer) {
    bool encontrado = false;
    cout << "\n--- Viajes del chofer " << chofer << " (búsqueda recursiva) ---\n";
    buscarChoferRecursivo(viajes, chofer, 0, encontrado);
    if (!encontrado) cout << "No se encontraron viajes para el chofer: " << chofer << endl;
}
// reporte de viajes criticos
void reporteCriticos(const vector<Viaje> &viajes) {
    bool hayCriticos = false;
    cout << "\n--- Viajes críticos (rendimiento < 5 km/l) ---\n";
    for (int i = 0; i < viajes.size(); i++) {
        if (viajes[i].calcularRendimiento() < 5) {
            viajes[i].mostrarDatos();
            hayCriticos = true;
        }
    }
    if (!hayCriticos) cout << "No hay viajes críticos.\n";
}
// añadan estos casos al switch de la clase main por favor, el del ahorcado
 /* case 5:
            if(viajes.empty()) cout << "No hay viajes.\n";
            else ordenarViajesPorRendimiento(viajes);
            break;
        case 6: {
            string placa;
            cout << "Ingrese placa: "; cin >> placa;
            buscarPorPlaca(vehiculos, viajes, placa);
            break;
        }
        case 7: {
            string chofer;
            cout << "Ingrese chofer: "; cin >> chofer;
            buscarPorChofer(viajes, chofer);
            break;
        }
        case 8:
            reporteCriticos(viajes);
            break;
        case 0:
            cout << "Saliendo...\n";
            break;
        default:
            cout << "Opción no válida.\n";
    } */
