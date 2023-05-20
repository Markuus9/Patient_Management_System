#include "Hospital.hpp"

void Hospital::alta_pacient(){
    Pacient P;
    cin >> P;
    if(not Pacients.find(P).first) {
        Pacients.insert(P);
        LlistaEspera.push(P);
    } else cerr << "  Error: Pacient ja existent" << endl;
}


void Hospital::baixa_pacient(){
    string nom;
    cin >> nom;
    Pacient P(nom);
    if(Pacients.find(P).first) Pacients.remove(P);
    else cerr << " Error: Pacient no existent" << endl;
}


void Hospital::llista_espera(){
    cout << LlistaEspera;
}