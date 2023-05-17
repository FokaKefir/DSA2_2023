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

void task3() {
    vector<Film> films = readFilmsFromFile("program.txt");
    //printFilms(films);
    vector<Film> pFilms = generateProgram(films);
    printFilms(pFilms);
}

int main() {
    task3();
}