#pragma once
#include <tuple>
#include <iostream>
#include <string>

using namespace std;

class Node
{
private:
	bool Obstacle;
public:
	tuple<int, int> Pos;
	tuple<int, int> ParentPos;
	bool path;
	Node(bool _isAnObstacle, tuple<int, int> _pos);
	Node();
	void afficherNode();
	bool isAnObstacle();
	bool setObstacle();
	void setBeginning();
	void setEnd();
	int g_cost;
	int h_cost;
	int f_cost = g_cost + h_cost;
	bool end;
	bool beginning;
	bool
		operator ==(const Node& obj) const
	{
		if (to_string(get<0>(Pos)) + ',' + to_string(get<1>(Pos)) == to_string(get<0>(obj.Pos)) + ',' + to_string(get<1>(obj.Pos)))
			return true;
		else
			return false;
	}
	bool
		operator !=(const Node& obj) const
	{
		if (to_string(get<0>(Pos)) + ',' + to_string(get<1>(Pos)) != to_string(get<0>(obj.Pos)) + ',' + to_string(get<1>(obj.Pos)))
			return true;
		else
			return false;
	}
};
template<>
struct hash<Node>
{
	size_t
		operator()(const Node& obj) const
	{
		return hash<string>()(to_string(get<0>(obj.Pos)) + ',' + to_string(get<1>(obj.Pos)));
	}
};


