#include "Doctor.hpp"

Doctor::Doctor() {

}

Doctor::Doctor(const Doctor &d) {
    this->name = d.name;
    this->Visitas = d.Visitas;
}
        
Doctor::Doctor(string name) {
    this->name = name;
}
        
Doctor::~Doctor() {

}

void Doctor::programar_visita(const Visita &v) {
    Visitas.push(v);
}

string Doctor::getName() {
    return name;
}

void Doctor::remove(const Pacient& P){
    Data D;
    Visita aux(D,P);
    bool found = true;
    while (found){
        found = Visitas.removeEqual(aux);
    }
}

void Doctor::remove_visit(const Visita &v)
{
    int size = Visitas.size();
    Visitas.remove(v);
    if (Visitas.size() != size)  {
        cout << "  Error" << endl;
    }
}



istream& operator>>(istream &is, Doctor &d){
	is >> d.name;
	return is;
}

ostream& operator<<(ostream &os, Doctor &d) {
    os << " " << d.name << endl << d.Visitas;
    return os;
}

