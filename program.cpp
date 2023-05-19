#include <iostream>
#include "Hospital.hpp"

using namespace std;

/** Programa principal
 *
 * main() crea l'hospital, fa la lectura d'instruccions i
 * l'escriptura de resultats. Les operacions estan definides i
 * implementades en les classes Hospital, Pacient, Doctor, Visita,
   Data, PriorityQueue i BST
 */

int main() {
	// Crear un hospital
	Hospital h;
	
	// Processar instruccions
    string inst;
    while ((cin >> inst) and (inst != "fi")) {
        if (inst == "alta_pacient") {
          Pacient p;
          cin >> p;
          h.alta_pacient(p);
        } else if (inst == "baixa_pacient") {
          string name;
          cin >> name;
          h.baixa_pacient(name);
			// completar el codi

        } else if (inst == "alta_doctor") {
            
			// completar el codi

        } else if (inst == "mostrar_llista") {
          h.mostar_llista();
        }
		// ...
		// completar el codi
		// ...
    }
    cout << "fi" << endl;
}