#ifndef HOSPITAL_HPP
#define HOSPITAL_HPP
#include <iostream>
#include <list>
#include "BST.hpp"
#include "Pacient.hpp"
#include "Doctor.hpp"
#include "Data.hpp"
#include "PriorityQueue.hpp"
#include "Visita.hpp"

using namespace std;

class Hospital { 
    private:
        BST<Pacient> Pacients;
        BST<Doctor> Doctors;
        list<string> LlistaEspera;
    public:
        void alta_pacient(string nom, int edat, string motiu, int gravetat){
            Pacient P(nom,edat,motiu,gravetat);
            bool repetit;
            
            if(Pacients.find(P).first){

            }
            Pacients.insert(P);
        }

        void baixa_pacient(string nom){

        }
};
#endif