#ifndef VECTOR_H
#define VECTOR_H

template <typename T>
class Vector
{
public:
	Vector(); // default ctor
	explicit Vector(size_t); // param ctor
	Vector(const Vector<T>&); // copy ctor
	inline ~Vector(); // dtor

	//Modifiers
	void push_back(const T&);
	void pop_back();
	void insert(size_t, const T&);
	void erase(size_t);
	void clear();

	// Capacity
	size_t size() const;   
	size_t capacity() const;
	bool empty() const;
	void reserve(size_t);
	void shrink_to_fit();

	// Element access
	T& at(size_t index) const;
	T& front() const;
	T& back() const;
	T* data() const;

	// opeators
	T& operator[](size_t);     
	const T& operator[](size_t) const;
	Vector<T>& operator=(const Vector<T>&);
	bool operator==(const Vector<T>&) const;
	bool operator!=(const Vector<T>&) const;

private:
	T* m_arr;
	size_t m_size;
	size_t m_capacity;
};

extern template class Vector<int>;

#endif // VECTOR_H