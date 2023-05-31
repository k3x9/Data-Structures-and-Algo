//32-bit Binary Trie for bitwise operations
struct node{
	struct node* left = NULL;
	struct node* right = NULL;
};

class Btrie{
public:
	node* head = new node;

	void insert(int x){
		vector<int> bin = binary(x);
		node* temp = head;

		for(int i=0;i<bin.size();i++){

			//0 -> left
			//1 -> right

			if(bin[i] == 0){
				if(temp->left == NULL){
					node* n = new node;
					temp->left = n;
				}
				temp = temp->left;
			}
			else{
				if(temp->right == NULL){
					node* n = new node;
					temp->right = n;
				}
				temp = temp->right;
			}
		}
	}

	//Convert decimal to binary
	vector<int> binary(int x){
		vector<int> bin;
		while(x){
			bin.push_back(x%2);
			x /= 2;
		}

		//Adding zeros to make it 32-bits
		for(int i=bin.size()+1; i<=32; i++){
			bin.push_back(0);
		}

		reverse(bin.begin(), bin.end());
		return bin;
	}
};
