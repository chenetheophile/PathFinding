#pragma once
#include <vector>
#include <string>
#include <math.h>
#include <random>
#include <iostream>
#include "Node.h"
using namespace std;
class Grille
{
private:
	vector<Node> grille;
	Node end;
	Node begin;
	int taille;
public:
	Grille();
	Grille(int taille);
	Node getNode(int ligne, int colonne);
	Node getNode(tuple<int, int>coord);
	void creerObstacle(int nbObstacle);
	void afficher();
	void placerDebutFin();
	void updateValue(Node node);
	Node getEnd();
	Node getStart();
	vector<Node> getVoisins(Node node);


};

