#include "Grille.h"
Grille::Grille(int taille) {
	this->taille = taille;
	for (int i = 0; i < taille; i++)
	{
		for (int j = 0; j < taille; j++)
		{
			grille.push_back(Node(false, tuple<int, int>{i, j}));
		}
	}
	placerDebutFin();
};
Grille::Grille() {
	int taille = 8;
	this->taille = taille;
	for (int i = 0; i < taille; i++)
	{
		for (int j = 0; j < taille; j++)
		{
			grille.push_back(Node(false, tuple<int, int>{i, j}));
		}
	}
	placerDebutFin();
}
void Grille::afficher() {
	for (int i = 0; i < sqrt(grille.size()); i++)
	{
		for (int j = 0; j < sqrt(grille.size()); j++)
		{
			grille.at(i * sqrt(grille.size()) + j).afficherNode();
			cout << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}
void Grille::creerObstacle(int nbObstacle) {
	srand((unsigned int)time(NULL));
	for (int i = 0; i < nbObstacle; i++)
	{
		int pos = rand() % grille.size();
		if (grille.at(pos).isAnObstacle() || !grille.at(pos).setObstacle())
			i--;
	}
}
void Grille::placerDebutFin() {
	grille.at(sqrt(grille.size()) - 1).setEnd();
	end = grille.at(sqrt(grille.size()) - 1);
	grille.at((sqrt(grille.size()) - 1) * sqrt(grille.size())).setBeginning();
	begin = grille.at((sqrt(grille.size()) - 1) * sqrt(grille.size()));
}
Node Grille::getEnd() {
	return this->end;
}
Node Grille::getStart() {
	return this->begin;
}

vector<Node> Grille::getVoisins(Node node)
{
	vector<Node>voisins;
	tuple<int, int> pos = node.Pos;
	if (get<0>(pos) >= 0 && get<1>(pos) >= 0 && get<0>(pos) < taille && get<1>(pos) < taille)
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
			{
				if (get<0>(pos) - 1 + i >= 0 && get<1>(pos) - 1 + j >= 0 && get<0>(pos) - 1 + i < taille && get<1>(pos) - 1 + j < taille)
					if (get<0>(pos) - 1 + i != get<0>(pos) || get<1>(pos) - 1 + j != get<1>(pos))
						voisins.push_back(getNode(get<0>(pos) - 1 + i, get<1>(pos) - 1 + j));
			}
		}
	return voisins;
}
Node Grille::getNode(int ligne, int colonne) {
	return grille.at(ligne * taille + colonne);
}
Node Grille::getNode(tuple<int,int>coord) {
	return getNode(get<0>(coord), get<1>(coord));
}
void Grille::updateValue(Node node) {
	grille.at(distance(
		grille.begin(), find(grille.begin(), grille.end(), getNode(node.Pos))
	)) = node;
}
