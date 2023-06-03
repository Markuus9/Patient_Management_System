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

        /* Pre: cert */
		/* Post: retorna un pair amb un booleà el qual
        sera (true) si 'dname' es trobat, i un enter amb
        la posició del vector on s'ha trobat l'element,
        altrament retornara (false) i '-1' */
        pair<bool,int> find_doctor(string dname);
        
        /* Pre: cert */
		/* Post: elimina el pacient de la programació 
        dels doctors*/
        void remove(const Pacient&);

    public:

        /* Pre: al canal estàndard d'entrada hi ha la informació
        del pacient. */
		/* Post: afegeix un pacient al conjunt de pacients,
        només si els paràmetres pel canal estàndard
        entrada són correctes.*/
        void alta_pacient();

        /* Pre: al canal estàndard d'entrada hi ha la informació
        del doctor. */
		/* Post: afegeix un doctor al vector de doctors,
        només si els paràmetres pel canal estàndard
        entrada són correctes.*/
        void alta_doctor();

        /* Pre: al canal estàndard d'entrada hi ha un 
        string amb el nom del pacient. */
		/* Post: elimina el pacient del conjunt de pacients, 
        de la llista d'espera i de la programació
        dels doctors.*/
        void baixa_pacient();
 
        /* Pre: cert */
        /* Post: mostra pel canal estandar d'entrada de 
        sortida la llista d'espera amb l'informació de 
        cada pacient (nom, edat, motiu, gravetat).*/
        void llista_espera();

        /* Pre: al canal estàndard d'entrada hi ha un enter
        amb la informació del nou estat, i un string amb el 
        nom del pacient. */
        /* Post: si l'estat i el pacient llegits pel canal
        estàndard d'entrada són correctes, llavors el pacient
        passa a tenir l'estat llegit. */
        void modificar_estat_pacient();

        /* Pre: al canal estàndard d'entrada hi ha el nom d’un 
        pacient, el nom d’un doctor i una data. */
        /* Post: si el pacient i el doctor són 
        correctes s’afegeix una nova visita al doctor amb el 
        pacient i data indicats. */
        void programar_visita();

        /* Pre: cert */
        /* Post: si la llista d'espera no és buida, sinó, 
        s’elimina el primer pacient de la llista d’espera.*/
        void tractar_seguent_pacient();

        /* Pre: cert */
        /* Post: per cada doctor que hi hagi en el sistema, 
        s’escriu el seu nom i la llista de visites 
        (data i nom pacient) que t´e programades ordenada 
        per data.*/
        void mostrar_programacio_visites();

        /* Pre: pel canal estandar d'entrada hi ha dos strings,
        (nom pacient i doctor) i una data. */
        /* Post: si el pacient i el doctor son correctes s’elimina 
        la visita al doctor amb el pacient i data indicats.*/
        void cancelar_visita();
};
#endif