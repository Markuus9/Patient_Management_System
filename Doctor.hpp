// Ha de representar un doctor amb el seu conjunt de visites programades 
// i oferir els m`etodes necessaris per poder-hi operar
#ifndef DOCTOR_HPP
#define DOCTOR_HPP
#include <iostream>
#include "PriorityQueue.hpp"
#include "Pacient.hpp"
#include "Data.hpp"

using namespace std;

class Doctor { 
    private:
        string nom;
        BST< pair<Pacient,Data> > visites;
    public:

        //-------------
		// Constructors
		//-------------

		/* Pre: cert */
		/* Post: crea un doctor buit */		
		Doctor();

        //-------------
		// Modificadors
		//-------------

        /* Pre: cert */
		/* Post: afegeix una visita el doctor amb el nom del
           pacient i la data de visita. */	
        void crear_visita(pair<Pacient,Data> visita);

        /* Pre:  */
		/* Post: elimina una visita del doctor que coincideix amb el nom del
           pacient i la data de visita. */	
        void eliminar_visita(pair<Pacient,Data> visita);
        
        //-----------
		// Consultors
		//-----------

        Data getData(pair<Pacient,Data> visita);

        void mostrar_visites();
        
		//-----------
		// L/E
		//-----------

        /* Pre: esta preparat al canal estàndard d'entrada el valor
		   string. */
		/* Post: el doctor 'D' passa a tenir els valors llegits del canal
		   estàndard d'entrada com a nom. */	
        friend istream& operator>>(istream &is, Doctor &D);

        /* Pre: cert */
		/* Post: s'han escrit els atributs nom i visita, del
           doctor 'D' al canal estàndard de sortida */
		friend ostream& operator<<(ostream &os, const Doctor &D);

        bool operator==(const Doctor &D) const;

};
#endif
