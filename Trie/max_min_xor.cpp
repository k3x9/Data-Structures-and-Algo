//head : head node of Btrie
//bin : vector -> binary representation of int x (32-bits) (for which we need to find maximum or minimum xor)
//index : current index of vector (0-indexed)

// arr = [3,5,2,6,8,29,0]
// x = 6
//Objective to find max(arr[i] ^ x) or min(arr[i] ^ x)

int maximum(node* head, vector<int> &bin, int index){
	if(index == 32) return 0;
	int ans = (int)(1<<(31-index));
	if(bin[index] == 1){
		if(head->left != NULL) return ans + maximum(head->left, bin, index+1);
		return maximum(head->right, bin, index+1);
	}
	if(head->right != NULL) return ans + maximum(head->right, bin, index+1);
	return maximum(head->left, bin, index+1);
}
//O(h)
//h = height of trie = 32

int minimum(node* head, vector<int> &bin, int index){
	if(index == 32) return 0;
	int ans = (int)(1<<(31-index));
	if(bin[index] == 0){
		if(head->left != NULL) return minimum(head->left, bin, index+1);
		return ans + minimum(head->right, bin, index+1);
	}
	if(head->right != NULL) return minimum(head->right, bin, index+1);
	return ans + minimum(head->left, bin, index+1);
}
//O(h)
//h = height of trie = 32
