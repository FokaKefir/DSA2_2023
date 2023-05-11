#include <iostream>
#include "greedy.h"

using namespace std;

void task1() {
    vector<Patient> patients = readPatientsFromFile("beosztas.txt");
    //printPatients(patients);
    displayTimetable(patients);
}

void task2() {
    vector<int> banknotes = readBanknotesFromFile("penzek.txt");
    printBanknotes(banknotes);
    greedyBanknotes(banknotes);
}

int main() {
    task2();
}