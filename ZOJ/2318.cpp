#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

// CODE AND EXPLANATION is by marat.snowbear ( http://codeforces.com/profile/marat.snowbear )

//We have circular islands of different radius and a circular ship or radius r. Notice that if we shrink the ship into a point by decreasing its radius by r and increase all the islands' radius by r, the problem doesn't change.
//Now, after altering the radius of islands, if two islands intersect, then it is not possible to go between them (two circles touching allows ship to pass through ). So if we imagine each of the center of islands as nodes, and add a line between two nodes only if the corresponding circles intersect, then we get a planer graph. The ship cannot pass through any edges of this graph.
//So, if the ship is inside any polygon, then it cannot escape. Otherwise it can. How do we check if a point is inside a polygon? We can use circular line sweep and dfs to solve the sub-problem. Start from a node and imagine that there is a special line, SweepLine, connecting the ship and the current node. We are going to track how much SweepLine has rotated when visiting each node.
//Assign the starting node angle 0. Now move to its neighbors that are not visited yet and and while moving from i->j assign, visit[j] = visit[i] + angle[i][j]. angle[i][j] is the directed angle between the vector (i-ship) and (j-ship). And when moving to a node that has already been visited, simply check the difference between the current angle SweepLine and when the node was visited the first time. Let d = CurAngle-visit[target]. If d is 2*pi<=d or d<=-2*pi, then the SweepLine has rotated completely when traversing a cycle, and ship is trapped.
struct point {
	double x, y, r;

	static point read() {
		double y; cin >> y;
		double x; cin >> x;
		double r; cin >> r;

		return { x , y ,r };
	}
};

double get_distance(const point &p1, const point &p2) {
	auto dx = p1.x - p2.x;
	auto dy = p1.y - p2.y;
	return sqrt(dx * dx + dy * dy);
}

const double eps = 1e-10;
const double PI = atan2(0, -1);

double get_rotation_angle(const point &p1, const point &p2) {
	double angle1 = atan2(p1.y, p1.x);
	double angle2 = atan2(p2.y, p2.x);
	angle2 -= angle1;

	if (angle2 > PI) angle2 -= 2 * PI;
	if (angle2 < -PI) angle2 += 2 * PI;
	return angle2;
}

bool can_get_through_the_edges(vector<point> &points, vector<vector<int>> &edges, double ship_radius) {
	int n = points.size();
	vector<double> angle_to_point(n);
	vector<bool> visited(n);

	for (int root = 0 ; root < n ; root++) if (!visited[root]) {
		vector<int> order = { root };
		visited[root] = true;
		angle_to_point[root] = 0;

		for (int i = 0 ; i < order.size() ; i++) {
			int v = order[i];
			for (auto c : edges[v]) {
				if (visited[c]) {
					auto res_angle = angle_to_point[v] + get_rotation_angle(points[v], points[c]) - angle_to_point[c];
					if (fabs(res_angle) > eps) return false;
				} else {
					visited[c] = true;
					angle_to_point[c] = angle_to_point[v] + get_rotation_angle(points[v], points[c]);
					order.push_back(c);
				}
			}
		}
	}

	return true;
}

int main() {
	freopen("out.in", "rt", stdin);
	freopen("out.out", "wt", stdout);

	int n; cin >> n;
	vector<point> ps(n);
	for (int i = 0 ; i < n ; i++) ps[i] = point::read();

	auto ship = point::read();

	for (auto &p : ps) {
		p.x -= ship.x;
		p.y -= ship.y;
		p.r  += ship.r;
	}

	vector<vector<int>> edges(n);
	for (int i = 0 ; i < n ; i++) for (int j = i + 1 ; j < n ; j++) {
		auto dist = get_distance(ps[i], ps[j]);
		if (dist < ps[i].r + ps[j].r - eps) {
			edges[i].push_back(j);
			edges[j].push_back(i);
		}
	}

	cout << ( can_get_through_the_edges(ps, edges, ship.r) ? "YES" : "NO");
}
