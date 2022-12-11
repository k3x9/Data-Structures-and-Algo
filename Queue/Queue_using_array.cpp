class Queue{
	public:
		#define MAX 10000

		int front_index = -1;
		int back_index = -1;
		int length = 0;
		int queue_arr[MAX];

		void push(int element){
			if(length == MAX) return;
			back_index = (back_index + 1)%MAX;		//For cyclic array
			queue_arr[back_index] = element;
			if(length == 0) front_index = back_index;
			length++;
		}
		//O(1)

		void pop(){
			if(length == 0) return;
			front_index = (front_index + 1)%MAX;
			length--;
		}
		//O(1)

		int front(){
			if(length == 0) return -1;
			return queue_arr[front_index];
		}
		//O(1)

		int back(){
			if(length == 0) return -1;
			return queue_arr[back_index];
		}
		//O(1)

		bool isempty(){
			return length == 0;
		}
		//O(1)

		bool isfull(){
			return length == MAX;
		}
		//O(1)

		int size(){
			return length;
		}
		//O(1)
};
