#pragma once

template<typename T>
class DynamicArray {
private:
	T * arr;
	unsigned size;
	unsigned capacity;

	//************************************
	// Method:    resize
	// FullName:  DynamicArray<T>::resize
	// Access:    private 
	// Returns:   void
	// Qualifier:
	//************************************
	void resize() {
		capacity *= 2;
		T* temp = new T[capacity];
		for (unsigned i = 0; i < size; i++) {
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
	}

	void copy(const DynamicArray<T>& other) {
		size = other.size;
		capacity = other.capacity;
		arr = new T[capacity];
		for (unsigned i = 0; i < size; i++) {
			arr[i] = other.arr[i];
		}
	}
public:
	DynamicArray() {
		size = 0;
		capacity = 20;
		arr = new T[capacity];
	}
	DynamicArray(const DynamicArray<T>& other) {
		copy(other);
	}
	DynamicArray& operator = (const DynamicArray<T>& other) {
		if (this != &other) {
			delete[] arr;
			copy(other);
		}
		return *this;
	}
	~DynamicArray() {
		for (unsigned int i = 0; i < size; i++)
		{


			delete arr[i];
		}
	}
	void unionWith(const DynamicArray<T>& other) {
		for (int i = 0; i < other.get_size(); i++)
		{
			this->push_back(other.get_ElementAtIndex(i));
		}

	}

	void push_back(const T& new_element) {
		if (size == capacity) {
			resize();
		}
		arr[size] = new_element;
		size++;
	}

	T& operator [] (unsigned i) {
		return arr[i];
	}
	T operator[](unsigned i) const {
		return arr[i];
	}

	unsigned get_size() const {
		return size;
	}
	T get_ElementAtIndex(unsigned i) const {
		return arr[i];
	}
	void remove_by_index(unsigned index) {
		for (unsigned i = index; i <= this->size - 1; i++) {
			arr[i] = arr[i + 1];
		}
		size--;
	}
};