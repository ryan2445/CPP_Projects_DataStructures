//RYAN HOFFMAN - CS302 - PROJECT 6 - TRAVELLING SALESMAN PROBLEM (TSP)
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
#define V 5
#define MAX 999999

int tsp(int graph[][V], int s);

int main(){
    int s=0;
    int adjMatrix[][V]={{0, 218, 518, 704, 439}, {218, 0, 736, 808, 568}, {518, 736, 0, 840, 421}, {704, 808, 840, 0, 1125}, {439, 568, 421, 1125, 0}};
    int shortestPathLength=tsp(adjMatrix, s);
    int milesPerGallon = shortestPathLength/40;
    cout << "Shortest Path Length: " << shortestPathLength << " miles total (Costs " << milesPerGallon << " gallons of gasoline)" << endl;
    return 0;
}

int tsp(int graph[][V], int s){
    int minPath=MAX;
    vector<int> vertex;
    for(int i=0;i<V;i++){
        if(i!=s){
            vertex.push_back(i);
        }
    }
    do{
        int currentWeight=0;
        int k=s;
        for(int i=0; i<vertex.size(); i++){
            currentWeight+=graph[k][vertex[i]];
            k=vertex[i];
        }
        minPath=min(minPath, currentWeight);
    }while(std::next_permutation(vertex.begin(), vertex.end()));
    return minPath;
}
// int renoSF = 218;
// int renoSL = 518;
// int renoSeattle = 704;
// int renoVegas = 439;
// int SFSL = 736;
// int SFSeattle = 808;
// int SFVegas = 568;
// int SLSeattle = 840;
// int SLVegas = 421;
// int vegasSeattle = 1125;

// for(int i=0;i<5;i++){
//     for(int j=0;j<5;j++){
//         cout << adjMatrix[i][j] << " ";

//     }
//     cout << endl;
// }
