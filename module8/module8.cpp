#include "PatientFunctions.h"
#include <iostream>
#include <fstream>

using namespace std;

void addPatient(Patient* patients, int& count)
{
    if (count >= 100)
    {
        cout << "Patient list is full.\n";
        return;
    }

    cout << "Enter Patient ID: ";
    cin >> patients[count].id;
    cin.ignore();

    cout << "Enter Patient Name: ";
    getline(cin, patients[count].name);

    cout << "Enter Age: ";
    cin >> patients[count].age;
    cin.ignore();

    cout << "Enter Gender: ";
    getline(cin, patients[count].gender);

    cout << "Enter Diagnosis: ";
    getline(cin, patients[count].diagnosis);

    count++;

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (patients[i].id > patients[j].id)
            {
                Patient temp = patients[i];
                patients[i] = patients[j];
                patients[j] = temp;
            }
        }
    }

    cout << "Patient added successfully!\n";
}

void displayPatients(Patient* patients, int count)
{
    if (count == 0)
    {
        cout << "No patients found.\n";
        return;
    }

    for (int i = 0; i < count; i++)
    {
        cout << "\nPatient " << i + 1 << endl;
        cout << "ID: " << patients[i].id << endl;
        cout << "Name: " << patients[i].name << endl;
        cout << "Age: " << patients[i].age << endl;
        cout << "Gender: " << patients[i].gender << endl;
        cout << "Diagnosis: " << patients[i].diagnosis << endl;
    }
}

int binarySearch(Patient* patients, int count, int searchID)
{
    int left = 0;
    int right = count - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (patients[mid].id == searchID)
            return mid;

        if (patients[mid].id < searchID)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

void updatePatient(Patient* patients, int count)
{
    int id;

    cout << "Enter Patient ID to update: ";
    cin >> id;
    cin.ignore();

    int index = binarySearch(patients, count, id);

    if (index == -1)
    {
        cout << "Patient not found.\n";
        return;
    }

    cout << "Enter New Name: ";
    getline(cin, patients[index].name);

    cout << "Enter New Age: ";
    cin >> patients[index].age;
    cin.ignore();

    cout << "Enter New Gender: ";
    getline(cin, patients[index].gender);

    cout << "Enter New Diagnosis: ";
    getline(cin, patients[index].diagnosis);

    cout << "Patient updated successfully.\n";
}

void savePatients(Patient* patients, int count)
{
    ofstream file("patients.txt");

    if (!file)
    {
        cout << "Unable to save file.\n";
        return;
    }

    for (int i = 0; i < count; i++)
    {
        file << patients[i].id << endl;
        file << patients[i].name << endl;
        file << patients[i].age << endl;
        file << patients[i].gender << endl;
        file << patients[i].diagnosis << endl;
    }

    file.close();

    cout << "Patients saved successfully.\n";
}

void loadPatients(Patient* patients, int& count)
{
    ifstream file("patients.txt");

    if (!file)
        return;

    while (file >> patients[count].id)
    {
        file.ignore();

        getline(file, patients[count].name);

        file >> patients[count].age;
        file.ignore();

        getline(file, patients[count].gender);
        getline(file, patients[count].diagnosis);

        count++;
    }

    file.close();
}
