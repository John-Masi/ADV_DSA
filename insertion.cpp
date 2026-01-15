#include <iostream>
#include <array>

std::array<int , 6> insertion_sort(std::array<int, 6>& a) {
	int s{static_cast<int>(a.size())};

	for(int i = 1; i < s; i++){
		int key = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > key) {
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}

	return a;
}

void print_array(std::array<int ,6> a) {
	for(int i = 0; i < static_cast<int>(a.size()); i++) {
		std::cout << a[i] << '\n';
	}
}

int main() {
	std::array<int , 6> a = {5,2,4,6,1,3};

	std::array<int , 6> b = insertion_sort(a);

	print_array(b);
}