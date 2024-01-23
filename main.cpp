#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string specializare;

struct Doctor {
    string nume, specializare;
    string caz;
};

struct Pacient {
    string problema, specializare;
};

bool eLiber(Doctor doctor) {
    if ((doctor.caz == "") && (doctor.specializare == specializare)) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    ifstream inFile("HandsOn-Input.txt");

    vector<Pacient> pacienti;
    vector<Doctor> doctori;
    string name, speciality;

    int no_problems, no_doctors;

    inFile >> no_problems;
    for (int i = 0; i < no_problems; i++) {
        inFile >> name;
        inFile >> speciality;
        pacienti.push_back({ name, speciality });
    }

    inFile >> no_doctors;
    for (int i = 0; i < no_doctors; i++) {
        inFile >> name;
        inFile >> speciality;
        doctori.push_back({ name, speciality });
    }

    for (vector<Pacient>::iterator j = pacienti.begin(); j < pacienti.end(); j++) {
        specializare = j->specializare;
        vector<Doctor>::iterator it = find_if(doctori.begin(), doctori.end(), eLiber);
        if (it != doctori.end()) {
            it->caz = j->problema;
            cout << it->nume << " " << it->caz << "\n";
        }
    }

    return 0;
}