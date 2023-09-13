// bellmen ford

#include <bits/stdc++.h>
using namespace std;
/*
    start u= edge[i][0];
    end  v= edge[i][1];
    value w= edge[i][2];
*/
const int u = 0, v = 1, w = 2;

//print path
void findPre(int path[], int ver)
{
    if (ver != 0)
    {
        findPre(path, path[ver]);
    }
    cout << ver << " -> ";
}


void bellmen_ford(int edges[][3], int noOfEdges, int noOfVertex, int sourse)
{
    int distance[noOfVertex];
    // init with max value 999999
    fill(distance, distance + noOfVertex, 999999);
    // init sourse with 0 distance
    distance[sourse] = 0;

    int path[noOfVertex];

    // relax all edge with edges noOfVertex-1

    for (int k = 0; k < noOfVertex - 1; k++)
    {
        for (int i = 0; i < noOfEdges; i++)
        {
            if (distance[edges[i][v]] > (distance[edges[i][u]] + edges[i][w]))
            {
                distance[edges[i][v]] = distance[edges[i][u]] + edges[i][w];
                path[edges[i][v]] = edges[i][u];
            }
        }
    }

//Check for negative weight cycles
    for (int i = 0; i < noOfEdges; i++)
    {
        if (distance[edges[i][v]] > (distance[edges[i][u]] + edges[i][w]))
        {
            cout << "Graph contains negative weight cycle." << endl;
            return;
        }
    }
//print distance
    cout<<"\n\n Pathis"<<"\n\nVertex\tvalue\tpath"<<endl;
    for (int i = 0; i < noOfVertex; i++)
    {
        cout<<i<<"\t"<<distance[i]<<"\t\t";
        findPre(path,i);
        cout<<endl;
    }

}

int main(int argc, char const *argv[])
{
    int noOfEdge,noOfVertex;


    cout<<"Enter no of Vertex ";
    cin>>noOfVertex;

    cout<<"Enter no of edges ";
    cin>>noOfEdge;

    int edges[noOfEdge][3];

    for (int i = 0; i < noOfEdge; i++)
    {
        cout<<"Enter Edge "<<endl;
        cin>>edges[i][0]>>edges[i][1]>>edges[i][2];
    }
    cout<<endl;
    bellmen_ford(edges,noOfEdge,noOfVertex,0);

    return 0;
}
