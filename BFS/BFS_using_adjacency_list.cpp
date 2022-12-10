#include<iostream>
#include<vector>
#include<queue>     //Implementation code for queue is already present in repo.
using namespace std;

void bfs(vector<int> adj_lis[],int n){
  int vis[n+1]={};  //visiting array(initially all elements is 0)
  queue<int> q;
  int curr_node=1;
  
  //code part before visiting the current node
  q.push(curr_node);
  vis[curr_node] = 1;

  while(!q.empty()){
    curr_node = q.front();
    q.pop();

    for(auto i : adj_lis[curr_node]){
      if(vis[i] == 0){

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
  vector<int> adj_lis[n+1]; //making array of vector

  bfs(adj_lis,n); //O(N + M)
}
