#include<iostream>
#include<vector>
#include<queue>     //Implementation code for queue is already present in repo.
using namespace std;

void bfs(int *adj_mat,int n){
  int vis[n+1]={};  //visiting array(initially all elements is 0)
  queue<int> q;
  int curr_node=1;
  
  //code part before visiting the current node
  q.push(curr_node);
  vis[curr_node] = 1;

  while(!q.empty()){
    curr_node = q.front();
    q.pop();
    
    for(int i=0;i<=n;i++){
      if(*(adj_mat + curr_node*(n+1) + i) == 1 && vis[i] == 0){

        // code before visiting new node

        q.push(i);
        vis[i] = 1;
      }
    }
  }

  //code after visiting all connected nodes
}

int main(){
  int n;    //Number of nodes
  int m;    //Number of edges
  cin>>n>>m;
  int adj_mat[n+1][n+1] = {}; //1 indexing (initially elements of this array is 0)

  bfs(*adj_mat,n); //O(N^2)
}
