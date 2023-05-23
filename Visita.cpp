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
   return pacient==visita.getPacient();
}

ostream& operator<<(ostream &os, Visita &v) {
    os << v.pacient << " " << v.data << endl;
    return os;
}

istream& operator>>(istream &is, Visita &v) {
    is >> v.pacient >> v.data;
    return is;
}

bool Visita::operator==(const Visita& v) const{
    return v.data == data and v.pacient == this->pacient;
}