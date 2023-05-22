#include "Doctor.hpp"

//-------------
// Constructors
//-------------

Doctor::Doctor(){

}

//-------------
// Modificadors
//-------------

void Doctor::crear_visita(pair<Pacient,Data> visita){
	visites.insert(visita);
}

void Doctor::eliminar_visita(pair<Pacient,Data> visita){
	visites.remove(visita);
}

//-----------
// Consultors
//-----------

Data Doctor::getData(pair<Pacient,Data> visita){
	return visites.find(visita).second;
}

void Doctor::mostrar_visites(){

}

//-----------
// L/E
//-----------

istream& operator>>(istream &is, Doctor &D){
	is >> D.nom;
	return is;
}

ostream& operator<<(ostream &os, const Doctor &D){
	os << " " << D.nom << endl;
	// pensando como hacer esto
	// hay que imprimir un BST< pair<Paciente,Data> > entero.
	return os;
}

bool Doctor::operator==(const Doctor &D) const {
	return nom == D.nom;
}
