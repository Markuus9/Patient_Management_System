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
        Queue<Pacient> LlistaEspera;
    public:
        void alta_pacient();

        void baixa_pacient();

        void llista_espera();

        void modificar_estat_pacient();
};
#endif