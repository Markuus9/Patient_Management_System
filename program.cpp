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
			cout << inst << " ";
          h.baixa_pacient();
			// completar el codi

        } else if (inst == "alta_doctor") {
            h.alta_doctor();
			// completar el codi

        } else if (inst == "llista_espera") {
          cout << inst << endl;
          h.llista_espera();
        }
        
         else if (inst == "modificar_estat_pacient") {
			 cout << inst << " ";
          h.modificar_estat_pacient();
        }

        else if(inst == "mostrar_programacio_visites") {
          cout << inst << " " << endl; 
          h.mostrar_programacio_visites();
        }

        else if(inst == "programar_visita") {
			cout << inst << " ";
          h.programar_visita();
        }

        else if (inst == "cancellar_visita") {
			cout << inst << " ";
            h.cancelar_visita();
        }

        else if (inst == "tractar_seguent_pacient") {
          cout << inst << endl;
            h.tractar_seguent_pacient();
        } else {
          cout << inst << endl << "  error" << endl; 
        }
		// ...
		// completar el codi
		// ...
    }
    cout << "fi" << endl;
}