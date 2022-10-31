class Queue{
	private:
		struct node{
			int data;
			node *next = NULL;
		};
	public:
		int length = 0;
		node *head = NULL;
		node *end = NULL;

		void push(int element){
			node *n = new node;
			n->data = element;
			if(head == NULL) head = n;
			if(end) end->next = n;
			end = n;
			length++;
		}
		//O(1)

		void pop(){
			if(!head) return;
			node *temp = head;
			head = head->next;
			if(temp == end) end=NULL;
			free(temp);
			length--;
		}
		//O(1)

		int front(){
			if(head) return head->data;
			return -1;
		}
		//O(1)

		int back(){
			if(end) return end->data;
			return -1;
		}
		//O(1)

		int size(){
			return length;
		}
		//O(1)

		int isempty(){
			return length==0;
		}
		//O(1)
};
