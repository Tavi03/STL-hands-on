#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <queue>

using namespace std;

struct Problem {
    string name;
    string speciality;
    int durata, prioritate;
    bool operator<(const Problem& p) const{
        return this->prioritate < p.prioritate;
    }
};

struct Doctor {
    string id;
    string speciality;
    int numar_ore = 8;
};

Problem currentProblem;

bool matchesSpeciality(const Doctor& doctor) {
    return doctor.speciality == currentProblem.speciality;
}

int main() {
    ifstream inFile("HandsOn-Input.txt");

    int n, m;
    inFile >> n;

    
    priority_queue<Problem> problems_queue;
    for (int i = 0; i < n; i++) {
        Problem p;
        inFile >> p.name >> p.speciality >> p.durata >> p.prioritate;
        problems_queue.push(p);
    }

    inFile >> m;
    vector<Doctor> doctors(m);
    for (Doctor& d : doctors) {
        inFile >> d.id >> d.speciality;
    }

    while (!problems_queue.empty()) {
        Problem p = problems_queue.top();
        vector<Doctor>::iterator it = find_if(doctors.begin(), doctors.end(), [](p.durata) {
            return p.durata <= this->numar_ore;
            });
        problems_queue.pop();
    }


    //for (const Problem& p : problems) {
      //  currentProblem = p;
        //auto it = find_if(doctors.begin(), doctors.end(), matchesSpeciality);

        //if (it != doctors.end()) {
          //  cout << it->id << " " << p.name << endl;
           // doctors.erase(it);
        //}
    //}

    inFile.close();

    return 0;
}