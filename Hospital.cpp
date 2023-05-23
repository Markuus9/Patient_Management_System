#include "Hospital.hpp"

void Hospital::remove(const Pacient &p){
    unsigned int i = 0, size = Doctors.size();
    bool found = false;
    while (i < size and not found) {
        Doctors[i].remove(p);
    }
}

pair<bool,int> Hospital::find_doctor(string dname){
    unsigned int size = Doctors.size();
    for (unsigned int i = 0; i < size; ++i) 
        if (Doctors[i].getName() == dname) return make_pair(true,i);
    return make_pair(false, -1);
}

void Hospital::alta_pacient(){
    Pacient P;
    cin >> P;
    int gravetat = P.getGravetat();
    if(not Pacients.find(P).first and gravetat >= 1 and gravetat <= 3) {
        Pacients.insert(P);
        LlistaEspera.push(P);
    } else cout << "  Error" << endl;
}


void Hospital::baixa_pacient(){
    string nom;
    cin >> nom;
    Pacient P(nom);
    pair<bool,Pacient> par = Pacients.find(P);
    if(par.first) {
        Pacients.remove(par.second);
        LlistaEspera.remove(par.second);
        for(unsigned int i = 0; i<Doctors.size(); ++i){
            Doctors[i].remove(par.second);
        }
    }
    else cout << " Error" << endl;
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
        cout << " Error" << endl;
        return;
    }
    LlistaEspera.remove(par.second);
    par.second.actualitzaEstat(estat);
    Pacients.setValue(p,par.second);
    LlistaEspera.push(par.second);
}

void Hospital::alta_doctor() {
    Doctor d;
    cin >> d;
    if(find_doctor(d.getName()).first) {
        cout << "  Error" << endl;
        return;
    }
    Doctors.push_back(d);
}

void Hospital::programar_visita() {
    string pname;
    cin >> pname;
    Pacient p(pname);
    pair<bool,Pacient> ppar = Pacients.find(p);
    if (not ppar.first) {
        cout << "  Error" << endl;
        return;
    }
    string dname;
    cin >> dname;
    pair<bool, int> dpar = find_doctor(dname);
    if (not dpar.first) {
        cout << "  Error" << endl;
        return;        
    }
    Data d;
    cin >> d;
    Visita v(d,ppar.second);
    Doctors[dpar.second].programar_visita(v);
}

void Hospital::mostrar_doctors() {
    for(unsigned int i = 0; i < Doctors.size(); ++i) {
        cout << Doctors[i] << endl;
    }
}

void Hospital::cancelar_visita()
{
    string pname,dname;
    cin >> pname >> dname;
    Pacient p(pname);
    Data d;
    cin >> d;
    pair<bool, int> find = find_doctor(dname);
    if (not find.first) {
        cout << "  Error" << endl;
        return;
    }
    Visita v(d, p);
    Doctors[find.second].remove_visit(v);

}

void Hospital::tractar_seguent_pacient(){
    if (not LlistaEspera.empty()) LlistaEspera.pop();        
    else cout << " error" << endl;
}
