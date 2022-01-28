/**
* Programme qui crée un dictionnaire en tant qu'array de strutures à partir d'un fichier texte et qui affiche le mot le plus du dictionnaire.
* \file   TD1_exercice_6.cpp
* \author Huy Viet Nguyen et Reda Rhanmouni (Section 5)
* \date   30 janvier 2022
* Créé le 23 janvier 2022
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct Mot 
{
    string orthographe;
    string nature;
    string definition;
};

int trouverNombreMotsDictionnaire();
vector<Mot> creerDictionnaire();
Mot trouverNomPlusLong(vector<Mot> dictionnaire);


int main()
{
    vector<Mot> dictionnaire = creerDictionnaire();
    Mot nomPlusLong = trouverNomPlusLong(dictionnaire);

    cout << nomPlusLong.orthographe << " (" << nomPlusLong.nature << ") : " << nomPlusLong.definition;

    return 0;
}


int trouverNombreMotsDictionnaire()
{
    std::ifstream fichier("dictionnaire.txt");
    std::string element;
    string ligne;
    int nombreMots = 0;

    while (std::getline(fichier, ligne))
    {
        nombreMots++;
    }

    return nombreMots;
}

vector<Mot> creerDictionnaire()
{
    std::ifstream fichier("dictionnaire.txt");
    std::string element;

    vector<Mot> dictionnaire;

    string mot;
    string nature;
    string definition;

    for (int i = 1; i <= trouverNombreMotsDictionnaire(); i++)
    {
        Mot nouveauMot;

        std::getline(fichier, mot, '\t');
        nouveauMot.orthographe = mot;

        std::getline(fichier, nature, '\t');
        nouveauMot.nature = nature;

        std::getline(fichier, definition, '\n');
        nouveauMot.definition = definition;

        dictionnaire.push_back(nouveauMot);
    }

    return dictionnaire;
}

Mot trouverNomPlusLong(vector<Mot> dictionnaire)
{   
    int nombreMots = trouverNombreMotsDictionnaire();
    Mot nomPlusLong = dictionnaire[0];

    for (int i = 1; i < nombreMots; i++)
    {
        if ((nomPlusLong.orthographe).size() > (dictionnaire[i].orthographe).size())
            continue;
        else
            nomPlusLong = dictionnaire[i];
    }

    return nomPlusLong;
}
