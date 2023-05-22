#include "Visita.hpp"

//-------------
// Constructors
//-------------

Visita::Visita(){

}

Visita::Visita(const Data &data, const Pacient &pacient) {
    this->data = data;
    this->pacient = pacient;
}

//-----------
// Consultors
//-----------

Data Visita::getData() const {
    return data;
}

Pacient Visita::getPacient() const {
    return pacient;
}

bool Visita::compare(const Visita &visita) const {
   if(data.getAny() < visita.data.getAny()) return true;
   if(data.getMes() < visita.data.getMes()) return true;
   if(data.getDia() < visita.data.getDia()) return true;
   return pacient.getNom() < visita.pacient.getNom();
}

ostream& operator<<(ostream &os, Visita &v) {
    os << v.pacient << " " << v.data << endl;
    return os;
}