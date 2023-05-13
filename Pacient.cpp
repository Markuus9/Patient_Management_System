#include "Pacient.hpp"

//-------------
// Constructors
//-------------
		
Pacient::Pacient(){

}
	
Pacient::Pacient(string nom){
	this->nom = nom;
}


Pacient::Pacient(string nom, int edat, string motiu, int gravetat){
	this->nom = nom;
	this->edat = edat;
	this->motiu = motiu;
	this->gravetat = gravetat;
}

//-------------
// Modificadors
//-------------

void Pacient::actualitzaEstat(int gravetat){
	this->gravetat = gravetat;
}

//-----------
// Consultors
//-----------

string Pacient::getNom() const{
	return nom;
}

int Pacient::getEdat() const{
	return edat;
}

string Pacient::getMotiu() const{
	return motiu;
}

int Pacient::getGravetat() const{
	return gravetat;
}

bool Pacient::compare(const Pacient &p) const{
	bool resultat;
	if(gravetat<p.gravetat){
		resultat = true;
	} else {
		resultat = false;
	}
	return resultat;
}

// PODEU AFEGIR ELS MÈTODES QUE NECESSITEU


//-----------
// L/E
//-----------
			
istream& operator>>(istream &is, Pacient &p){

}

ostream& operator<<(ostream &os, const Pacient &p){

}