#ifndef VISITA_HPP
#define VISITA_HPP
#include "Data.hpp"
#include "Pacient.hpp"

using namespace std;

/** Representació d'una visita.
 *
 *  Consta d'una data i d'un pacient.
 */

class Visita {
	
	private:
		Data data;
		Pacient pacient;
	public:
		//-------------
		// Constructors
		//-------------
		
		Visita();

		/* Pre: cert */
		/* Post: crea una visita de data 'd' i pacient 'p' */
		Visita(const Data &d, const Pacient &p);
		
		//-----------
		// Consultors
		//-----------

		/* Pre: cert */
		/* Post: retorna la data de la visita paràmetre implícit */
		Data getData() const;
		
		/* Pre: cert */
		/* Post: retorna el pacient de la visita paràmetre implícit */
		Pacient getPacient() const;

		/* Pre: cert */
		/* Post: retorna un booleà que indica si el nom del pacient
		de la visita implícita és igual que la visita 'v' (True), 
		si no ho es retorna (False). */
		bool compare1(const Visita &v) const;

		/* Pre: cert */
		/* Post: retorna un booleà que indica si la data de la visita 
		implícita és menor que la visita 'v' (True), si no ho es retorna
		(False). */
		bool compare(const Visita &v) const;

		/* Pre: cert */
		/* Post: retorna un booleà que indica si la data i nom del
		   pacient de la visita del paràmetre implícit i de la 
		   visita 'v' rebuda són identiques (true) o no ho són (false) */
		bool operator==(const Visita& v) const;
		
	    /* Pre: cert */
        /* Post: s'han escrit al canal estàndard de sortida la data
		i el nom del pacient */
		friend ostream& operator<<(ostream &os, Visita &);

		/* Pre: estan preparats al canal estàndard d'entrada un pacient
		i una data. */
		/* Post: la visita passa a tenir els elements llegits pel canal
		   estàndard d'entrada.*/	
		friend istream& operator>>(istream &is, Visita &);


};
#endif