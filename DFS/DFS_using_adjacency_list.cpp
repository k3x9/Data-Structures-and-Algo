#include<iostream>
#include<vector>
using namespace std;

void dfs(vector<int> adj_lis[],int n,int node,int vis[]){

  //code part before visiting the current node

  vis[node] = 1;
  for(auto i : adj_lis[node]){
    if(vis[i] == 0){

      //code part before going to next node

      dfs(adj_lis,n,i,vis);

      //code part after visiting next node
    }
  }
}

int main(){
  int n;    //Number of nodes
  int m;    //Number of edges
  cin>>n>>m;
  vector<int> adj_lis[n+1]; //making array of vector

  int vis[n+1]={};        //Visited array (initially elements of this array is 0)
  int curr_node = 1;
  dfs(adj_lis,n,curr_node,vis); //O(N + M)
}
