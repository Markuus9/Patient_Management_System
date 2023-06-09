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
	if(gravetat<p.gravetat)return true;
	return false;
}

// PODEU AFEGIR ELS MÈTODES QUE NECESSITEU


//-----------
// L/E
//-----------
			
istream& operator>>(istream &is, Pacient &p){
	is >> p.nom  >> p.edat >> p.motiu >> p.gravetat;
	return is;
}

ostream& operator<<(ostream &os, const Pacient &p){
	os << p.nom << "  " << p.edat << " " << p.motiu << " " << p.gravetat << endl;
	return os;
}

bool Pacient::operator<(const Pacient &p) const {
	return nom < p.nom;
}

bool Pacient::operator>(const Pacient &p) const {
	return nom > p.nom;
}

bool Pacient::operator==(const Pacient &p) const {
	return nom == p.nom;
}

