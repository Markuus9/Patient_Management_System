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

bool Visita::compare1(const Visita &visita) const {
   return pacient.getNom()==visita.getPacient().getNom();

}

bool Visita::compare(const Visita &visita) const {
   if(data.getAny() < visita.data.getAny()) return true;
   if(data.getMes() < visita.data.getMes()) return true;
   if(data.getDia() < visita.data.getDia()) return true;
   return false;
}

ostream& operator<<(ostream &os, Visita &v) {
    os << v.data << " " << v.pacient.getNom() << endl;
    return os;
}

istream& operator>>(istream &is, Visita &v) {
    is >> v.pacient >> v.data;
    return is;
}

bool Visita::operator==(const Visita& v) const{
    return v.data == this->data and v.pacient.getNom() == this->pacient.getNom();
}