#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <string.h>

using namespace std;

enum color_type { WHITE, GREY, BLACK };
enum piant_color { NO_COLOR, BLUE, RED };

class vertex {
private:
	color_type color;
	piant_color pcolor;
	vector<int> list;
public:
	vertex() {
		this->color = WHITE;
		this->pcolor = NO_COLOR;
	}
	void insert(int n) {
		this -> list.push_back(n);
	}
	void print() {
		for (unsigned i = 0; i < this->list.size(); ++i)
			cout << this->list[i] << " ";
		cout << endl;
	}
	void color_change(color_type color) {
		this->color = color;
	}
	void piant(piant_color color) {
		this->pcolor = color;
	}
	int list_len() {
		return this->list.size();
	}
	int get(int i) {
		return this->list[i];
	}
	color_type get_color() {
		return this->color;
	}
	piant_color get_pcolor() {
		return this->pcolor;
	}
};

bool bfs(vertex *);


int main() {
	string line;
	int row = 0;
	int rows = 0;
	vertex *vertex_list = new vertex[1024];
	while (cin >> row) {
		getline(cin, line, '\n');
		istringstream p_list;
		p_list.str(line);
		int num;
		while(p_list >> num){
			vertex_list[row].insert(num);
		}
		row++;
	}
	/*for (int i = 0; i < row; ++i) {
		cout << i << "->";
		vertex_list[i].print();
	}*/
	cout << "wo yi yue du guan yu chao xi de shuo ming" << endl;
	if (!bfs(vertex_list))
		cout << "no!" << endl;
	else
		for (int i = 0; i < row; ++i) {
			if (vertex_list[i].get_pcolor() == vertex_list[0].get_pcolor())
				cout << i << endl;
		}

	return 0;
}

bool bfs(vertex *arr) {
	arr[0].color_change(GREY);
	arr[0].piant(RED);
	queue<int> queNode;
	queNode.push(0);
	while (!queNode.empty()) {
		int w = queNode.front();
		piant_color w_color = arr[w].get_pcolor();
		queNode.pop();
		for (int i = 0; i < arr[w].list_len(); ++i) {
			int x = arr[w].get(i);
			if (arr[x].get_color() == WHITE) {
				arr[x].color_change(GREY);
				if (w_color == RED)
					arr[x].piant(BLUE);
				else
					arr[x].piant(RED);
				queNode.push(x);
			}
			else {
				if (arr[w].get_pcolor() == arr[x].get_pcolor())
					return false;
			}
		}
		arr[w].color_change(BLACK);
	}
	return true;
}