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
          h.alta_pacient();
        } 
        else if (inst == "baixa_pacient") {
          h.baixa_pacient();
			// completar el codi

        } else if (inst == "alta_doctor") {
            h.alta_doctor();
			// completar el codi

        } else if (inst == "llista_espera") {
          h.llista_espera();
        }
        
         else if (inst == "modificar_estat_pacient") {
          h.modificar_estat_pacient();
        }

        else if(inst == "mostrar_doctors") {
          h.mostrar_doctors();
        }

        else if(inst == "programar_visita") {
          h.programar_visita();
        }
		// ...
		// completar el codi
		// ...
    }
    cout << "fi" << endl;
}