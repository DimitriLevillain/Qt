#ifndef ALVEOLESLIBRES_H
#define ALVEOLESLIBRES_H

#include <string>
#include <vector>

using namespace std;

typedef vector<int> PileEntiers;

class AlveolesLibres : public PileEntiers
{
public:
    AlveolesLibres(const short _rangee=10, const short _colonne=20);
    void Liberer(const short _rangee, const short _colonne);
    bool Reserver(short &_rangee, short &_colonne);
private:
    string references;
    short diametre;
    short rangee;
    short colonne;
};

#endif // ALVEOLESLIBRES_H
