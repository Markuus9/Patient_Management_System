#ifndef PACIENT_HPP
#define PACIENT_HPP
#include <string>
#include <iostream>

using namespace std;

/** Representació d'un pacient.
 *
 *  Consta de quatre atributs per emmagatzemar el nom (string),
 *  edat (enter), motiu de l'ingrés (string) i gravetat de 
 *  l'estat de salut (int) d'un pacient.
 */
 
class Pacient {
	
	private:
		string nom;
		int edat;
		string motiu;
		int gravetat;  // int gravetat;  // {alta=1, mitjana=2, baixa=3}
	
	public:
		//-------------
		// Constructors
		//-------------
		
		/* Pre: cert */
		/* Post: crea un pacient buit */		
		Pacient();
		
		/* Pre: cert */
		/* Post: crea un pacient de nom 'nom' */	
		Pacient(string nom);
		
		/* Pre: cert */
		/* Post: crea un pacient amb els valors de 'nom',
           'edat', 'motiu' i 'gravetat' rebuts per paràmetre */
		Pacient(string nom, int edat, string motiu, int gravetat);
		
		//-------------
		// Modificadors
		//-------------

		/* Pre: cert */
		/* Post: el valor de gravetat del pacient paràmetre 
		   implícit	passa a ser el valor de 'gravetat' */
		void actualitzaEstat(int gravetat);
		
		//-----------
		// Consultors
		//-----------

		/* Pre: cert */
		/* Post: retorna el nom del pacient paràmetre implicit */
		string getNom() const;

		/* Pre: cert */
		/* Post: retorna l'edat del pacient paràmetre implicit */
		int getEdat() const;

		/* Pre: cert */
		/* Post: retorna el motiu de l'ingrés del pacient paràmetre 
		   implicit */
		string getMotiu() const;

		/* Pre: cert */
		/* Post: retorna la gravetat de l'estat del pacient paràmetre
		   implicit */		
		int getGravetat() const;
		
		/* Pre: cert */
		/* Post: retorna un booleà que indica si l'estat de gravetat
		   del pacient paràmetre implícit és menor que el del pacient 'p' 
		   (true) o no ho és (false) */
		bool compare(const Pacient &p) const;


		// PODEU AFEGIR ELS MÈTODES QUE NECESSITEU
		
		
		//-----------
		// L/E
		//-----------
		
		/* Pre: estan preparats al canal estàndard d'entrada quatre valors
		   en aquest ordre - string, enter, string i enter */
		/* Post: el pacient 'p' passa a tenir els valors llegits del canal
		   estàndard d'entrada com a nom, edat, motiu i gravetat, 
		   respectivament */			
		friend istream& operator>>(istream &is, Pacient &p);
		
		/* Pre: cert */
		/* Post: s'han escrit els atributs nom, edat, motiu i gravetat del
           pacient 'p' al canal estàndard de sortida */
		friend ostream& operator<<(ostream &os, const Pacient &p);

		bool operator<(const Pacient &p) const;

		bool operator>(const Pacient &p) const;

		bool operator==(const Pacient &p) const;

};
#endif