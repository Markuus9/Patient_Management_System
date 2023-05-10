#include "Data.hpp"

//-------------
// Constructors
//-------------

Data::Data() {
}

Data::Data(int dia, int mes, int any) {
    this->dia = dia;
    this->mes = mes;
    this->any = any;
}

//-----------
// Consultors
//-----------

int Data::getDia() const {
    return dia;
}

int Data::getMes() const {
    return mes;
}

int Data::getAny() const {
    return any;
}

bool Data::operator==(const Data &data) {
	return dia == data.dia  and  mes == data.mes  and  any == data.any;
}

bool Data::operator<(const Data &data) {
	return dia < data.dia  or (dia == data.dia and mes < data.mes) or (dia == data.dia and mes == data.mes and any < data.any);
}

//-----------
// L/E
//-----------
		
istream& operator>>(istream &is, Data &data) {
	is >> data.dia >> data.mes >> data.any;
	return is;
}
		
ostream& operator<<(ostream &os, const Data &data) {
	os << data.dia << " " << data.mes << " " << data.any;
  return os;
}