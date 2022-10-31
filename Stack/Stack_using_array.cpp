class Stack{
	public:
		#define MAX 10000

		int top_index=-1;
		int stack_arr[MAX];

		void push(int element){
			if(top_index == MAX-1) return;	//Stack is full	
			stack_arr[++top_index]=element;
		}
		//O(1)

		void pop(){
			if(top_index == -1) return;  //Any stack empty response.
			top_index--;
		}
		//O(1)

		bool isempty(){
			return top_index == -1;
		}
		//O(1)

		int top(){
			if(top_index == -1) return -1; //Considering only positive integers are there in stack.
			return stack_arr[top_index];
		}
		//O(1)

		bool isFull(){
			return top_index == MAX-1;
		}
		//O(1)
		
		int size(){
			return top_index + 1;
		}
		//O(1)
};
