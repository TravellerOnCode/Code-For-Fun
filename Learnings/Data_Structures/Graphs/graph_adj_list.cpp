#include <iostream>
#include <list>
using namespace std;

class Graph
{
    int data;
    //Array of lists
    list<int> *l;

    public:
        Graph(int data)
        {
            this -> data = data;
            l = new list<int>[data];

        }

        void addEdge(int x,int y)
        {
            l[x].push_back(y);
            l[y].push_back(x);
        }
        void display()
        {
            for(int i=0;i<data;i++)
            {
                cout << "Vertex " << i << "-> ";
                for (int nbr:l[i])
                {
                    cout << nbr << ',';
                }
                cout << endl;
            }
        }
};

int main()
{
    Graph G(4);
    G.addEdge(0,1);
    G.addEdge(0,2);
    G.addEdge(2,3);
    G.addEdge(1,2);
    G.display();
    return 0;
}