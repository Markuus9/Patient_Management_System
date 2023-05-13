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
            
			// completar el codi

        } else if (inst == "baixa_pacient") {
            
			// completar el codi

        } else if (inst == "alta_doctor") {
            
			// completar el codi

        } 
		// ...
		// completar el codi
		// ...
    }
    cout << "fi" << endl;
}