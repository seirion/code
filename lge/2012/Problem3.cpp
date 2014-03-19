#include <iostream>
#include <fstream>
#include <stack>


using namespace std;


#ifndef true
#define true 1
#endif

#ifndef false 
#define false 0
#endif

//////////////////////////////////////////////////////////////////////
const int NMAX = 30; 
const int MAX = 3000; 


//////////////////////////////////////////////////////////////////////
// function prototypes
void parseInput(const char *path);
void solveEach(ifstream &file);


class Graph {
public:
	Graph(int size);
	~Graph() {}
private:
	int _length[NMAX][NMAX];
	int _distance[NMAX];
	bool _set[NMAX];
	int _path[NMAX];
public:
	void findShortest(const int n, const int v);
	void addEdge(int u, int v, int w) {
        _length[u][v] = w;
        _length[v][u] = w;
    }
	void printVertex(const int n, const int v);
	int choose(const int n);
	void dijkstra(const int n, const int start);
    int sum(int n) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += _distance[i];
        }
        return sum;
    }
};

Graph::Graph(int size)
{ 
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
		    _length[i][j] = i == j ? 0 : MAX;
		}
    }
}


void Graph::printVertex(const int n, const int v)
{
	cout << "--------------------------------------------------------------------" << endl;

	for (int i = 0; i < n; i++)
	{
		if (i == v) continue;

		stack<int> s;
		cout << "v " << i << ": ";

		if (_distance[i] == MAX) {
			cout << "not connected" << endl;
			continue;
		}

		s.push(MAX);

		for (int j = i; j != v; j = _path[j])  {
			s.push(j);
        }

		cout << v;

		for (int j; (j = s.top()) != MAX; s.pop())
			cout << " -> " << j;

		cout << endl;
	}
}


int Graph::choose(const int n)
{
	int min = MAX;
	int minIndex = 0;

	for (int i = 0; i < n; i++)
	{
		if (!_set[i]) {
			if (min > _distance[i])
			{
				min = _distance[i];
				minIndex = i;
			}
		}
	}

	return minIndex;
}

void Graph::findShortest(const int n, const int v)
{
	for (int i = 0; i < n; i++) {
		_set[i] = false; 
		_distance[i] = _length[v][i]; 
		_path[i] = v;
	}
	
	_set[v] = true;
	_distance[v] = 0;

	for (int i = 0; i < n - 2; i++) { 
		int u = choose(n);
		_set[u] = true;

		for (int w = 0; w < n; w++) {
			if (!_set[w]) {
				if (_distance[u] + _length[u][w] < _distance[w]) {
					_distance[w] = _distance[u] + _length[u][w];
					_path[w] = u;
				}
			}
		}
	}
} 


void Graph::dijkstra(const int n, const int start)
{
	findShortest(n, start);
	//printVertex(n, start);
}


int main(int argc, char *argv[])
{
    if (argc != 2) {
        cout << "usage " << argv[0] << " \"input file\"" << endl;
        return -1;
    }

    parseInput(argv[1]);
    return 0;
}


/**
 * parse number data from a file
 */
void parseInput(const char *path)
{
    ifstream file(path);

    int num;
    file >> num;

    int i;
    for (i = 0; i < num; i++) {
        solveEach(file);
    }
}


void solveEach(ifstream &file)
{
    int N, M;
    file >> N >> M;

	Graph graph(N);
    int i, x, y, weight;
    for (i = 0; i < N; i++) {
        file >> x >> y >> weight;
		graph.addEdge(x, y, weight);
    }

    int min = MAX;
    int minIndex = -1;

    for (i = 0; i < N; i++) {
	    graph.dijkstra(N, i);
        int temp = graph.sum(N);
        if (temp < min) {
            min = temp;
            minIndex = i;
        }
    }

    cout << minIndex << endl;
}
