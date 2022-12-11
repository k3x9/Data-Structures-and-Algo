//Following is the implementation of MAX heap.
//For MIN heap : instead of same values, insert negative of values in MAX heap

class Heap{
  public:
    const static int MAX = 10000;

    int arr[MAX + 1];     //MAX + 1 size : For 1 indexing
    int n=1;


    int size(){
      return n-1;
    }
    //O(1)

    void swap(int node1 , int node2){
      int temp = arr[node1];
      arr[node1] = arr[node2];
      arr[node2] = temp;
    }   
    //O(1)

    void pop(){
      if(n == 1) return;    //Empty heap.

      swap(n-1,1);
      n--;

      heapDOWN(1);
    }
    //O(logN)

    int max(){
      return arr[1];      //Root element is maximum
    }
    //O(1)

    void insert(int element){
      if(n == MAX){
        cout<<"LIMIT EXCEED\n";
        return;
      }
      arr[n++] = element;
      heapUP(n-1);
    }   
    //O(logN)

    int find(int element){
      for(int i=1;i<n;i++){
        if(arr[i] == element) return i;
      }
      return -1;
    }   
    //O(N)

    void heapUP(int node){
      int parent = node/2;

      while(parent>=1 && arr[parent] < arr[node]){
        swap(parent,node);

        node = parent;
        parent = node/2;
      }
    }  
    //O(logN)

    void heapDOWN(int node){
      int child1 = 2*node, child2 = 2*node + 1;

      while(child1 < n){
        if(arr[node] < arr[child1] && (child2 >= n || arr[child1] > arr[child2])){
          swap(node,child1);

          node = child1;
        }
        else if(child2 < n && arr[node] < arr[child2] && arr[child2] > arr[child1]){
          swap(node,child2);

          node = child2;
        }
        else return;

        child1 = 2*node; child2 = 2*node + 1;
      }
    }   
    //O(logN)

    void print(){
      for(int i=1;i<n;i++){
        cout<<arr[i]<<" ";
      }
      cout<<"\n";
    }   
    //O(N)
};
