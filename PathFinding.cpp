// PathFinding.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <unordered_set>
#include "Grille.h"
using namespace std;
void debug(Node node,Grille grid) {
	cout << "Node: ";
	node.afficherNode();
	cout << " parent: ";
	grid.getNode(node.ParentPos).afficherNode();
	cout << endl;
}
int getDistance(Node A, Node B) {
	int xA = get<1>(A.Pos);
	int yA = get<0>(A.Pos);
	int xB = get<1>(B.Pos);
	int yB = get<0>(B.Pos);
	int distX = abs(xA - xB);
	int distY = abs(yA - yB);
	if (distX > distY) {
		return 14 * distY + 10 * (distX-distY);
	}
	else {
		return 14 * distX + 10 * (distY - distX);
	}
}
vector<Node> retracePath(Node start, Node end,Grille grid) {
	vector<Node> path;
	Node current = end;
	while (current != start) {
		current.path = true;
		path.push_back(current);
		current = grid.getNode(current.ParentPos);
	}
	reverse(path.begin(), path.end());
	return path;
}
void findPath(Grille grid) {
	Node start = grid.getStart();
	Node end = grid.getEnd();

	vector<Node> openSet;
	unordered_set<Node> closedSet;
	openSet.push_back(start);
	
	while (openSet.size() > 0) {
		Node current = openSet.at(0);

		for (int i = 1; i < openSet.size(); i++) {
			if (openSet.at(i).f_cost < current.f_cost || openSet.at(i).f_cost == current.f_cost && openSet.at(i).h_cost < current.h_cost){
				current = openSet.at(i);
			}
		}
		openSet.erase(find(openSet.begin(), openSet.end(), current));
		closedSet.insert(current);
		if (current.end) {
				vector<Node> path = retracePath(start, current,grid);
				for (Node node : path) {
					grid.updateValue(node);
				}
				grid.afficher();
			return;
		}
		for (Node neighbours : grid.getVoisins(current)) { 

			if (neighbours.isAnObstacle() || closedSet.find(neighbours)!=closedSet.end()) {
				continue;
			}
			int newMovementCostToNeighbour = current.g_cost + getDistance(current, neighbours);
			if (newMovementCostToNeighbour < neighbours.g_cost || find(openSet.begin(), openSet.end(), neighbours) == openSet.end()) {
				neighbours.g_cost = newMovementCostToNeighbour;
				neighbours.h_cost = getDistance(neighbours, end);
				neighbours.ParentPos = current.Pos;
				grid.updateValue(neighbours);
				if (find(openSet.begin(), openSet.end(), neighbours) == openSet.end()) {
					openSet.push_back(neighbours);
				}
			}
		}
	} 
	
}
int main()
{	
	unordered_set<Node> set;
    Grille grille;//get<1> = colonne get<0>=ligne
	grille.creerObstacle(10);
	grille.afficher();
	findPath(grille);
		

	
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
