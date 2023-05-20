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

void Hospital::modificar_estat_pacient() {
    string name;
    cin >> name;
    Pacient p(name);
    pair<bool,Pacient> par = Pacients.find(p);
    int estat;
    cin >> estat;
    if (estat < 1 or estat > 3 or not par.first) {
        cerr << " Error" << endl;
        return;
    }
    LlistaEspera.remove(par.second);
    par.second.actualitzaEstat(estat);
    Pacients.setValue(p,par.second);
    LlistaEspera.push(par.second);
}