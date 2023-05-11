#include "greedy.h"

vector<Patient> readPatientsFromFile(char *filename) {
    ifstream fin(filename);
    if (!fin) {
        cout << "File open error!\n";
        exit(EXIT_FAILURE);
    }

    int n;
    fin >> n;
    vector<Patient> patients;

    string name1, name2;
    int time;
    while (fin >> name1 >> name2 >> time) {
        Patient p = {name1 + " " + name2, time};
        patients.push_back(p);
    }

    fin.close();

    return patients;
}

void printPatients(vector<Patient> patients) {
    for (Patient p : patients) {
        cout << p.name << " " << p.time << endl;
    }
    cout << endl;
}

void displayTimetable(vector<Patient> patients) {
    sort(patients.begin(), patients.end(), [](const Patient &p1, const Patient &p2) {
        return p1.time < p2.time;
    });
    //printPatients(patients);

    int mins = 8 * 60;
    for (Patient p : patients) {
        cout << p.name << " " << mins / 60 << " ora " << mins % 60 << " perc\n";
        mins += p.time;
    }
}

vector<int> readBanknotesFromFile(char *filename) {
    ifstream fin(filename);
    if (!fin) {
        cout << "File open error!\n";
        exit(EXIT_FAILURE);
    }

    int n;
    fin >> n;

    vector<int> banknotes;
    int banknote;
    while (fin >> banknote) {
        banknotes.push_back(banknote);
    }

    fin.close();
    return banknotes;
}

void printBanknotes(vector<int> banknotes) {
    for (const auto &note : banknotes) {
        cout << note << " ";
    }
    cout << endl;
}

void greedyBanknotes(vector<int> banknotes) {
    sort(banknotes.begin(), banknotes.end(), greater<int>());
    //printBanknotes(banknotes);
    vector<int> prod;

    int money;
    cout << "A beolvasott penzosszeg: ";
    cin >> money;
    for (int note : banknotes) {
        prod.push_back(money / note);
        money = money % note;
    }

    if (money > 0) {
        cout << "Nem lehet osszeallitani az osszeget\n";
        exit(EXIT_SUCCESS);
    }

    for (int i = 0; i < banknotes.size(); ++i) {
        cout << prod[i] << "x" << banknotes[i] << " ";
    }
    cout << endl;
}
