// Ha de representar un doctor amb el seu conjunt de visites programades 
// i oferir els m`etodes necessaris per poder-hi operar
#ifndef DOCTOR_HPP
#define DOCTOR_HPP
#include <iostream>
#include "PriorityQueue.hpp"
#include "Visita.hpp"

using namespace std;

class Doctor { 
    private:
        string name;
        Queue<Visita> Visitas;
    public:

        /* Pre: cert*/
        /* Post: El resultat es un doctor sense cap element*/
        Doctor();

        /* Pre: cert*/
        /* Post: El resultat es un doctor copia del doctor rebut. */
        Doctor(const Doctor &);
        
        /* Pre: cert*/
        /* Post: El resultat es un doctor amb el nom rebut per parametre.*/
        Doctor(string);
        
        /* esborra automàticament els objectes locals
	    en sortir d'un àmbit de visibilitat */
        ~Doctor();

        /* Pre: cert*/
        /* Post: Guarda a la cua de prioritat la visita rebuda per parametre.*/
        void programar_visita(const Visita &);

        /* Pre: cert*/
        /* Post: Retorna el nom del doctor.*/
        string getName();

        /* Pre: El parametre es un pacient no buit*/
        /* Post: Si s'ha trobat, elimina el pacient i totes les seves visites de la cua
            de prioritat que tenene com a parametre el mateix nom de pacient.*/
        void remove(const Pacient&);

        /* Pre: El parametre rebut es una visita no vuida.*/
        /* Post: S'ha esborrat la visita de la cua de prioritat de visites si es troba,
            en cas contrari mostra un missatje d'error pel canal estandar de sortida.*/
        void remove_visit(const Visita &);

		//-----------
		// L/E
		//-----------        
        
        /* Pre: el parametre es un doctor buit; el canal estàndard d'entrada els elements
            d'un doctor.*/
        /* Post: parametre implícit = parametre rebut.*/
        friend istream& operator>>(istream &, Doctor &);

        /* Pre: cert */
        /* Post: s'han escrit al canal estàndard de sortida els elements
            del doctor rebut */        
        friend ostream& operator<<(ostream &, Doctor &);
};
#endif

