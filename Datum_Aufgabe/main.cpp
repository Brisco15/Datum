#include <iostream>
using namespace std;

// Function �berpruft, wenn ein Jahr schalte ist
bool schaltejahr(int jahr) {
    return (jahr % 4 == 0 && jahr % 100 != 0) || (jahr % 400 == 0);
}

// Function �berpruft, ob das Datum g�ltig ist
bool gueltigDatum(int tag, int monat, int jahr) {
    // �berpruft , ob das  jahr g�ltig ist
    if (jahr < 1) {
        return false;
    }

    // �berpruft , ob der  monat g�ltig ist
    if (monat < 1 || monat > 12) {
        return false;
    }

    // �berpruft , ob der tag g�ltig ist, basierend auf den monat
    if (monat == 1 || monat == 3 || monat == 5 || monat == 7 || monat == 8 || monat == 10 || monat == 12) {
        //  monatten mit 31 tags
        if (tag < 1 || tag > 31) {
            return false;
        }
    }
    else if (monat == 4 || monat == 6 || monat == 9 || monat == 11) {
        //  monats mit 30 tags
        if (tag < 1 || tag > 30) {
            return false;
        }
    }
    else if (monat == 2) {
        // Februar hat 28 tags, oder 29 tags wenn  schalte jahr
        if (schaltejahr(jahr)) {
            if (tag < 1 || tag > 29) {
                return false;
            }
        }
        else {
            if (tag < 1 || tag > 28) {
                return false;
            }
        }
    }

    // wenn alle ist okay, das Datum ist g�ltig
    return true;
}

int main() 
{
    int tag, monat, jahr;
    char nochmal;
    do
    {
     //Eingabe
        cout << "Geben Sie ein tag: ";
        cin >> tag;

       
        cout << "Geben Sie ein monat: ";
        cin >> monat;

        
        cout << "Geben Sie ein Jahr : ";
        cin >> jahr;

        //Verarbeitung und Ausgabe
        if (gueltigDatum(tag, monat, jahr)) {
            cout << "Datum ist g�ltig." << endl;
        }
        else {
            cout << "Datum ist nicht g�ltig." << endl;
        }

        cout << "nochmal ? j/n : " << endl;
        cin >> nochmal;
    } while (nochmal != 'n' && nochmal != 'N');
    return 0;
}
