/**
  @file alveoleslibres.cpp
  @brief Implémentation de la classe AlveolesLibre
  @version 1.0
  @author Levillain Dimitri
  @date 16/10/2018
  */
#include "alveoleslibres.h"

/**
 * @brief AlveolesLibres::AlveolesLibres
 * @param _nbRangees
 * @param _nbColonnes
 */
AlveolesLibres::AlveolesLibres(const short _rangee, const short _colonne)
{
    for(int i=1 ; i <= _rangee*_colonne ; i++)
    {
        push_back(i);
    }
    rangee = _rangee;
    colonne = _colonne;
}
/**
 * @brief ALveolesLibres::Libérer
 * @param _rangee n° de la rangée ou se trouvait le rouleau
 * @param _colonne n°de la colonne ou se trouvait le rouleau
 * @details Ajoute l'alvéoles dont les coordonnées sont passées
 *          en paramètre à l'ensemble des alvéoles libres
 */

void AlveolesLibres::Liberer(const short _rangee, const short _colonne)
{

}

/**
 * @brief AlveolesLibres::Reserver
 * @param _rangee n° de la rangée ou l'on va mettre le rouleau
 * @param _colonne n° de la colonne ou l'on va mettre le rouleau
 * @return
 */

bool AlveolesLibres::Reserver(short &_rangee, short &_colonne)
{
    bool valeurARetourne;
    //back();
    pop_back();
    return valeurARetourne;
}
