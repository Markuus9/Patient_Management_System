#include "Hospital.hpp"

void Hospital::alta_pacient(){
    Pacient P;
    cin >> P;
    if(not Pacients.find(P).first) {
        Pacients.insert(P);
        LlistaEspera.push(P);
    } else cerr << "  Error" << endl;
}


void Hospital::baixa_pacient(){
    string nom;
    cin >> nom;
    Pacient P(nom);
    pair<bool,Pacient> par = Pacients.find(P);
    if(par.first) {
        Pacients.remove(par.second);
        LlistaEspera.remove(par.second);
    } else {
        cerr << " Error" << endl;
    }
}

void Hospital::alta_doctor(){
    Doctor D;
    cin >> D;
    if(not Doctors.find(D).first){
        Doctors.insert(D);
    } else {
        cerr << " error" << endl;
    }
}

void Hospital::llista_espera(){
    cout << LlistaEspera;
}

void Hospital::tractar_seguent_pacient(){
    if(LlistaEspera.empty()==true){
        cerr << " error" << endl;
    } else {
        LlistaEspera.pop();
    }
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

void Hospital::programar_visita(){
    string nom;
    Doctor doctor;
    Data data;
    cin >> nom >> doctor >> data;
    Pacient pacient(nom);
    if (not Doctors.find(doctor).first or not Pacients.find(pacient).first) {
        pair<Pacient,Data> visita(pacient,data);
        Doctor copia = Doctors.find(doctor).second;
        doctor.crear_visita(visita);
        Doctors.setValue(copia, doctor);
    } else {
        cerr << " error" << endl;
    }
}

void Hospital::cancellar_visita(){
    string nom;
    Doctor doctor;
    Data data;
    cin >> nom >> doctor >> data;
    Pacient pacient(nom);
    pair<Pacient,Data> visita(pacient,data);
    if (Doctors.find(doctor).first and Pacients.find(pacient).first and data==Doctors.find(doctor).second.getData(visita)) {
       Doctor copia = Doctors.find(doctor).second;
       doctor.eliminar_visita(visita);
       Doctors.setValue(copia, doctor);
    } else {
        cerr << " error" << endl;
    }  
}

void Hospital::mostrar_programacio_visites(){
   Doctors.print();
}
