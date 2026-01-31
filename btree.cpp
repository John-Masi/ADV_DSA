#include <vector>
#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <cmath>


int _lchild(std::vector<int>& v, int i) {
	return (i * 2) + 1;
	
}


int _rchild(std::vector<int>& v, int i) {
	return (i * 2) + 2;	
}

void max_heapify(std::vector<int>& v,int i,int n) {
	int l = _lchild(v,i);
	int r = _rchild(v,i);
	int largest = i;
	if(l < n && v[l] > v[i]){
		largest = l;
	}

	if(r < n && v[r] > v[largest]) {
		largest = r;
	}

	if(largest != i){
		std::swap(v[i],v[largest]);
		max_heapify(v,largest,n);

	}

}

void max_heap(std::vector<int>& v) {
	int n = v.size();
	for(int i = std::floor(n / 2) - 1; i >= 0; i--){
		max_heapify(v,i,n);
	}
}

void print_vector(std::vector<int>& v) {
	for(auto& i: v) {
		std::cout << i;
	}
}

int main() {
	
	std::vector<int> v = {4,1,2,3,2,16,9,10,14,8,7};
	max_heap(v);

	print_vector(v);


}
