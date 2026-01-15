#include <vector>
#include <iostream>

void merge(std::vector<int>& array,int l,int m,int r) {
	int nL = m - l + 1;
	int nR = r - m;

	std::vector<int> LeftArr(nL);
	std::vector<int> RightArr(nR);

	for(int i = 0; i < nL; i++) {
		LeftArr[i] = array[l + i];
	}

	for(int j = 0; j < nR ; j++) {
		RightArr[j] = array[m + 1 + j];
	}

	int i = 0;
	int j = 0;
	int k = l;

	while(i < nL && j < nR) {
		if(LeftArr[i] <= RightArr[j]) {
			array[k] = LeftArr[i];
			i++;
		}
		else {
			array[k] = RightArr[j];
			j++;
		}

		k++;
	}

	while(i < nL) {
		array[k] = LeftArr[i];
		i++;
		k++;
	}

	while(j < nR) {
		array[k] = RightArr[j];
		j++;
		k++;
	}
}

void merge_sort(std::vector<int>& array,int l,int h) {
	if(l >= h) return;

	int mid = l+ (h-l) / 2;
	merge_sort(array,l,mid);
	merge_sort(array,mid+1,h);
	merge(array,l,mid,h);
}

void print_vector(std::vector<int>& v){
	for(auto& i: v){
		std::cout << i << '\n';
	}
}

int main() {
	std::vector<int> b = {100,18,56,20,67};
	int n = b.size();

	merge_sort(b,0,n-1);

	print_vector(b);

}