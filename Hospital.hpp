#ifndef HOSPITAL_HPP
#define HOSPITAL_HPP
#include <iostream>
#include <vector>
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
        vector<Doctor> Doctors;
        Queue<Pacient> LlistaEspera;

        pair<bool,int> find_doctor(string);

    public:
        void alta_pacient();

        void alta_doctor();

        void baixa_pacient();

        void llista_espera();

        void modificar_estat_pacient();

        void programar_visita();

        void mostrar_doctors();
};
#endif