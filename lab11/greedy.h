#ifndef DSA2_GREEDY_H
#define DSA2_GREEDY_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Patient {
    string name;
    int time;
};

struct Film {
    string title;
    int start;
    int end;
};

vector<Patient> readPatientsFromFile(char *filename);
void printPatients(vector<Patient> patients);
void displayTimetable(vector<Patient> patients);

vector<int> readBanknotesFromFile(char *filename);
void printBanknotes(vector<int> banknotes);
void greedyBanknotes(vector<int> banknotes);

vector<Film> readFilmsFromFile(char *filename);
void printFilms(vector<Film> films);
vector<Film> generateProgram(vector<Film> films);

#endif //DSA2_GREEDY_H
