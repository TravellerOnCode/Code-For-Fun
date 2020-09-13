#include <iostream>
#include <unordered_map>
using namespace std;

class Graph
{
    int data;
    //Array of lists
    unordered_map<string, list<pair<string,int>>> l;

    public:
    /*
        Graph(int data)
        {
            this -> data = data;
            //l = new list<int>[data];

        }*/

        void addEdge(string x,string y,bool bdir,int w)
        {
            l[x].push_back(make_pair(y,w)); //map of x
            if (bdir)
            {
                l[y].push_back(make_pair(x,w)); //map of x 

            }
        }
        void display()
        {

            for(auto p:l)
            {
                string city = p.first;
                list<pair<string,int>> nbrs = p.second;
                cout << "Vertex " << city << "-> ";
                for (auto nbr: nbrs)
                {
                    string dest = nbr.first;
                    int dist = nbr.second;

                    cout << dest << " " << dist << ", ";
                }
                cout << endl;


            }
            
        }
};

int main()
{
    Graph G;
    G.addEdge("A","B",true,20);
    G.addEdge("B","D",true,20);
    G.addEdge("A","C",true,20);
    G.addEdge("A","D",true,20);
    G.display();
    return 0;
}