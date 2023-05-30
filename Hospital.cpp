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
    cout << "alta_pacient " << P;
    if(not Pacients.find(P).first and gravetat >= 1 and gravetat <= 3) {
        Pacients.insert(P);
        LlistaEspera.push(P);
    } else cout << "  error" << endl;
}


void Hospital::baixa_pacient(){
    string nom;
    cin >> nom;
	cout << nom << endl;
    Pacient P(nom);
    pair<bool,Pacient> par = Pacients.find(P);
    if(par.first) {
        Pacients.remove(par.second);
        LlistaEspera.remove(par.second);
        for(unsigned int i = 0; i<Doctors.size(); ++i){
            Doctors[i].remove(par.second);
        }
    }
    else cout << " error" << endl;
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
	cout << name << " " << estat << endl; 
    if (estat < 1 or estat > 3 or not par.first) {
        cout << "  error" << endl; 
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
    cout << "alta_doctor " << d.getName() << endl;
    if(find_doctor(d.getName()).first) {
        cout << "  error" << endl;
        return;
    }
    Doctors.push_back(d);
}

void Hospital::programar_visita() {
    string pname;
    cin >> pname;
    string dname;
    cin >> dname;
    Data d;
    cin >> d;
	cout << pname << " " << dname << " ";
	d.print(); 
		
    Pacient p(pname);
    pair<bool,Pacient> ppar = Pacients.find(p);
    if (not ppar.first) {
        cout << "  error" << endl;
        return;
    }
    pair<bool, int> dpar = find_doctor(dname);
    if (not dpar.first) {
        cout << "  error" << endl;
        return;        
    }
    Visita v(d,ppar.second);
    Doctors[dpar.second].programar_visita(v);
}

void Hospital::mostrar_programacio_visites() {
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
	cout << pname << " " << dname << " ";
	d.print(); 
	
	pair<bool, int> find = find_doctor(dname);
    if (not find.first) {
        cout << "  error" << endl;
        return;
    }
    Visita v(d, p);
    Doctors[find.second].remove_visit(v);

}

void Hospital::tractar_seguent_pacient(){
    if (not LlistaEspera.empty()) LlistaEspera.pop();        
    else cout << " error" << endl;
}
