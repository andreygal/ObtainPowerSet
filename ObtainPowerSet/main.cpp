#include <iostream>
#include <vector>
#include <list>

template<typename T>
std::vector<std::list<T>> PowerSet(std::list<T>& set) {
	std::list<T> empty;
	std::vector<std::list<T>> ps, ps_temp;
	//return when the stop condition is reached
	if (set.size() == 0) {
		ps.push_back(empty);
		return ps;
	}

	T temp = set.back();
	set.pop_back();
	//call PowerSet recursively on a set with one less element
	ps_temp = PowerSet(set);

	ps.insert(ps.end(), ps_temp.begin(), ps_temp.end());
	for (std::list<T>& i : ps_temp) {
		i.push_back(temp);
	}
	ps.insert(ps.end(), ps_temp.begin(), ps_temp.end());
	return ps;
}


int main() {
	std::list<int> set{ 1, 2, 3 };
	std::vector<std::list<int>> ps = PowerSet(set);
	//display the test case 
	for (std::list<int> i : ps) {
		std::list<int>::const_iterator it = i.cbegin();
		if (i.size() == 0)
			std::cout << "{ }" << std::endl;
		else {
			std::cout << "{ ";
			while (it != i.end()) {
				std::cout << *it << " ";
				it++;
			}
			std::cout << "}";
			std::cout << std::endl;
		}
	}
	system("pause");
	return 0; 
}