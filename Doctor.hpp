// Ha de representar un doctor amb el seu conjunt de visites programades 
// i oferir els m`etodes necessaris per poder-hi operar
#ifndef DOCTOR_HPP
#define DOCTOR_HPP
#include <iostream>
#include "PriorityQueue.hpp"
#include "Visita.hpp"

using namespace std;

class Doctor { 
    private:
        string name;
        Queue<Visita> Visitas;
    public:

        Doctor();

        Doctor(const Doctor &);
        
        Doctor(string);
        
        ~Doctor();

        void programar_visita(const Visita &);

        string getName();

        void remove(const Pacient&);

        void remove_visit(const Visita &);
        
        friend istream& operator>>(istream &, Doctor &);
        
        friend ostream& operator<<(ostream &, Doctor &);
};
#endif