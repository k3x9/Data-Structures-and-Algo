class Stack{
	private:
		struct node{
			int data;
			node *next = NULL;
		};
	public:
		int length = 0;
		node *head = NULL;
		void push(int element){
			node *n = new node;
			n->data = element;
			if(head) n->next = head;
			head = n;
			length++;
		}
		//O(1)

		void pop(){
			if(head == NULL) return;
			node *temp = head;
			head = head->next;
			free(temp);
			length--;
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
		
		int size(){
			return length;
		}
		//O(1)
};
