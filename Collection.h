/**
 * There is no Collection.cpp for this assignment.
 * Move all the functions from Collection.cpp to this file except Operator>> 
 * Covert the Collection class to a templated form. (Stress_ball should be replaced with typename "Obj".
 *   Stress_ball_colors and Stress_ball_sizes should be replaced with typename "F2").
 * This file has to be uploaded to mimir.
 */

#ifndef Collection_H
#define Collection_H
#include <string>
#include <iostream>
using namespace std;

enum class Sort_choice{bubble_sort, insertion_sort, selection_sort};

template<typename Obj, typename F1, typename F2>
class Collection {
	Obj* array;
    int size;
    int capacity;
	
	void resize() {
		if (capacity == 0) {
			capacity = 1;
			array = new Obj[1];
		} else {
			Obj* temp = new Obj[2 * capacity];
			
			for (int i = 0; i < capacity; ++i) {
				temp[i] = array[i];
			}
			
			capacity *= 2;
		
			delete[] array;
			
			array = temp;
			temp = nullptr;
		}
	};

public:
	Collection()
	: array(nullptr), size(0), capacity(0) {
		
	};

	Collection(int cap)
	: array(new Obj[cap]), size(0), capacity(cap) {
		this->make_empty();
	};

	Collection(const Collection& c)
	: array(new Obj[c.capacity]), size(c.size), capacity(c.capacity) {
		for (int i = 0; i < capacity; ++i) {
			array[i] = c.array[i];
		}
	};

	Collection& operator=(const Collection& c) {
		size = c.size;
		capacity = c.capacity;
		array = new Obj[capacity];
		
		for (int i = 0; i < c.capacity; ++i) {
			array[i] = c.array[i];
		}
		
		return *this;
	};

	~Collection() {
		delete[] array;
		size = 0;
		capacity = 0;
	};

	Collection(Collection&& c)
	: array(nullptr), size(0), capacity(0) {
		array = c.array;
		size = c.size;
		capacity = c.capacity;
		
		c.array = nullptr;
		c.size = 0;
		c.capacity = 0;
	};

	Collection& operator=(Collection&& c) {
		if (this != &c) {
			delete[] array;
		}
		
		array = c.array;
		size = c.size;
		capacity = c.capacity;
		
		c.array = nullptr;
		c.size = 0;
		c.capacity = 0;
		
		return *this;
	};

	void insert_item(const Obj& sb) {
		if (size == capacity) {
			resize();
		}
		
		this->array[size] = sb;
		++size;
	};

	bool contains(const Obj& sb) const {
		for (int i = 0; i < this->size; ++i) {
			if (this->array[i] == sb) {
				return true;
			}
		}
		
		return false;
	};

	Obj remove_any_item() {
		if (this->is_empty()) {
			throw std::invalid_argument("Empty!");
		} else {
			std::srand(time(0));
			int index = rand() % (this->size - 1);
			
			Obj item = this->array[index];
			
			for (int i = index; i < size - 1; ++i) {
				this->array[i] = this->array[i + 1];
			}
			
			--size;
			
			return item;
		}
	};
	
	void remove_this_item(const Obj& sb) {
		bool is_there = false;
		
		if (this->contains(sb)) {
			is_there = true;
		}
		
		if (this->is_empty()) {
			throw std::invalid_argument("Empty!");
		}
		
		if (is_there) {
			int index = 0;
			for (int i = 0; i < size; ++i) {
				if (this->array[i] == sb) {
					index = i;
					break;
				}
			}
			
			for (int j = index; j < size - 1; ++j) {
				this->array[j] = this->array[j + 1];
			}
			
			--size;
		}
	};

	void make_empty() {
		this->array = nullptr;
		this->size = 0;
		this->capacity = 0;
	};

	bool is_empty() const {
		if (this->size == 0 && this->capacity == 0) {
			return true;
		}
		return false;
	};

	int total_items() const {
		return size;
	};

	int total_items(F2 s) const {
		int sum = 0;
		
		for (int i = 0; i < size; ++i) {
			if (array[i].get_size() == s) {
				++sum;
			}
		}
		
		return sum;
	};

	int total_items(F1 c) const {
		int sum = 0;
		
		for (int i = 0; i < size; ++i) {
			if (array[i].get_color() == c) {
				++sum;
			}
		}
		
		return sum;
	};

	void print_items() const {
		for (int i = 0; i < size; ++i) {
			std::cout << array[i];
		}
	};

	Obj& operator[](int i) {
		return array[i];
	};

	const Obj& operator[](int i) const {
		return array[i];
	};
	
};

template<typename Obj, typename F1, typename F2>
ostream& operator<<(ostream& os, const Collection<Obj, F1, F2>& c) {
	for (int i = 0; i < c.total_items(); ++i) {
		os << c[i];
	}
	
	return os;
}

template<typename Obj, typename F1, typename F2>
Collection<Obj, F1, F2> make_union(const Collection<Obj, F1, F2>& c1, const Collection<Obj, F1, F2>& c2) {
	Collection<Obj, F1, F2> c3;
	
	for (int i = 0; i < c1.total_items(); ++i) {
		c3.insert_item(c1[i]);
	}
	
	for (int j = 0; j < c2.total_items(); ++j) {
		c3.insert_item(c2[j]);
	}
	
	return c3;
}

template<typename Obj, typename F1, typename F2>
void swap(Collection<Obj, F1, F2>& c1, Collection<Obj, F1, F2>& c2) {
	Collection<Obj, F1, F2> temp;
	temp = move(c1);
	c1 = move(c2);
	c2 = move(temp);
}

template<typename Obj, typename F1, typename F2>
void sort_by_size(Collection<Obj, F1, F2>& c, Sort_choice sort) {
	int option = -1;
	
	switch (sort) {
		case static_cast<Sort_choice>(0): option = 0;
			break;
			
		case static_cast<Sort_choice>(1): option = 1;
			break;
			
		case static_cast<Sort_choice>(2): option = 2;
			break;
			
	}
	
	if (option == 0) {
		bool sorted = false;
		int changes = 0;
		Obj temp;
		
		while (sorted == false) {
			for (int i = 0; i < c.total_items() - 1; ++i) {
				if (c[i].get_size() > c[i + 1].get_size()) {
					temp = c[i];
					c[i] = c[i + 1];
					c[i + 1] = temp;
					++changes;
				}
			}
			
			if (changes == 0) {
				sorted = true;
			} else {
				changes = 0;
			}
		}
	}
	
	if (option == 1) {
		int j = 1;
		Obj temp;
			
		while (j < c.total_items()) {
			if (c[j].get_size() < c[j - 1].get_size()) {
				temp = c[j];
				c[j] = c[j - 1];
				c[j - 1] = temp;
				
				if (j != 1) {
					--j;
				}
			} else {
				++j;
			}
		}
	}
		
	if (option == 2) {
		int correct = 0;
		F2 min;
		int min_index = 0;
		int i = 0;
		Obj temp;
			
		while (correct < c.total_items()) {
			min = c[i].get_size();
			min_index = i;
			for (int j = i; j < c.total_items(); ++j) {
				if (c[j].get_size() < min) {
					min = c[j].get_size();
					min_index = j;
				}
			}
			
			if (min_index == i) {
				++correct;
			} else {
				temp = c[i];
				c[i] = c[min_index];
				c[min_index] = temp;
			}
			
			++i;
		}
	}
}
#endif