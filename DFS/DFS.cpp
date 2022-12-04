#include<iostream>
using namespace std;

void dfs(int *adj_mat,int n,int node,int vis[]){
	if(vis[node] == 1) return;

	//code part before visiting the current node

	vis[node] = 1;
	for(int i=0;i<=n;i++){
		if(*(adj_mat + (n+1)*node + i) == 1){

			//code part before going to next node

			dfs(adj_mat,n,i,vis);

			//code part after visiting next node
		}
	}
}

int main(){
	int n;  	//Number of nodes
	int m;		//Number of edges
	cin>>n>>m;
	int adj_mat[n+1][n+1]={};	//1 indexing (initially elements of this array is 0)
	int vis[n+1]={};	//Visited array (initially elements of this array is 0)
	int curr_node = 1;
	dfs(*adj_mat,n,curr_node,vis);
}
