#ifndef PATIENTFUNCTIONS_H
#define PATIENTFUNCTIONS_H

#include <string>

using namespace std;

struct Patient
{
    int id;
    string name;
    int age;
    string gender;
    string diagnosis;
};

void addPatient(Patient* patients, int& count);

void displayPatients(Patient* patients, int count);

int binarySearch(Patient* patients, int count, int searchID);

void updatePatient(Patient* patients, int count);

void savePatients(Patient* patients, int count);

void loadPatients(Patient* patients, int& count);


#endif
