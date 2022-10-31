class Stack{
	private:
		struct node{
			int data;
			node *next = NULL;
		};
	public:
		node *head = NULL;
		void push(int element){
			node *n = new node;
			n->data = element;
			if(head) n->next = head;
			head = n;
		}
		//O(1)

		void pop(){
			node *temp = head;
			head = head->next;
			free(temp);
		}
		//O(1)

		int top(){
			if(head) return head->data;
			return -1;
		}
		//O(1)

		bool isempty(){
			return head == NULL;
		}
		//O(1)
};
