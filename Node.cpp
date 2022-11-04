#include "Node.h"

Node::Node(bool _obstacle, tuple<int, int> _pos)
{
	Obstacle = _obstacle;
	Pos = _pos;
	end = false;
	beginning = false;
	path = false;
}
Node::Node() {
}
void Node::afficherNode()
{
	if (end)cout << "E";
	else if (beginning) cout << "B";
	else if (path) cout << "P";
	else cout << Obstacle;
	/*cout <<"/" << get<0>(Pos) << get<1>(Pos);*/
}
bool Node::isAnObstacle() {
	return Obstacle;
}
bool Node::setObstacle() {
	if(!end && !beginning )
		this->Obstacle = true;
	return Obstacle;
}
void Node::setBeginning() {
	beginning = true;
}
void Node::setEnd() {
	end = true;
}

