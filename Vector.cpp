#include "Vector.h"

#include <stdexcept>

template <typename T>
Vector<T>::Vector()
	: m_arr(nullptr)
	, m_size(0)
	, m_capacity(0)
{
}

template <typename T>
Vector<T>::Vector(size_t initCapacity) 
	: m_size(0)
	, m_capacity(initCapacity)
{
	m_arr = new T[m_capacity];
}

template <typename T>
Vector<T>::Vector(const Vector<T>& vec)
	: m_size(vec.m_size)
	, m_capacity(vec.m_capacity)
{
	m_arr = new T[m_capacity];
	for (size_t i = 0; i < m_size; ++i) {
		m_arr[i] = vec.m_arr[i];
	}
}

template <typename T>
Vector<T>::~Vector()
{
	delete[] m_arr;
}

template <typename T>
void Vector<T>::push_back(const T& value)
{
	if (m_size == m_capacity)
	{
		m_capacity *= 2;
		T* tmp = new T[m_capacity];
		for (size_t i = 0; i < m_size; ++i) {
			tmp[i] = m_arr[i];
		}
		delete[] m_arr;
		m_arr = tmp;
		tmp = nullptr;
	}
	m_arr[m_size++] = value;
}

template <typename T>
void Vector<T>::pop_back()
{
	if (!empty()) {
		--m_size;
	}
	else {
		throw std::out_of_range("pop_back() called on an empty vector");
	}
}

template <typename T>
void Vector<T>::insert(size_t pos, const T& value)
{
	if (pos >= m_size) {
		throw std::out_of_range("Index out of bounds");
	}
	else {
		m_arr[pos] = value;
	}
}

template <typename T>
void Vector<T>::erase(size_t pos) 
{
	if (pos >= m_size) {
		throw std::out_of_range("Index out of bounds");
	}

	for (size_t i = pos; i < m_size - 1; ++i) {
		m_arr[i] = m_arr[i + 1];
	}

	--m_size;
}

template <typename T>
void Vector<T>::clear()
{
	delete[] m_arr;
	m_arr = nullptr;
	m_size = 0;
	m_capacity = 0;
}

template <typename T>
size_t Vector<T>::size() const
{
	return m_size;
}

template <typename T>
size_t Vector<T>::capacity() const
{
	return m_capacity;
}

template <typename T>
bool Vector<T>::empty() const
{
	return m_size == 0;
}

template <typename T>
void Vector<T>::reserve(size_t new_cap)
{
	if (new_cap > m_capacity) {
		T* tmp = new T[new_cap];
		for (size_t i = 0; i < m_size; ++i) {
			tmp[i] = m_arr[i];
		}
		m_capacity = new_cap;
		delete[] m_arr;
		m_arr = tmp;
		tmp = nullptr;
	}
}

template <typename T>
void Vector<T>::shrink_to_fit()
{
	if (m_size < m_capacity) {
		T* tmp = new T[m_size];
		for (size_t i = 0; i < m_size; ++i) {
			tmp[i] = m_arr[i];
		}
		delete[] m_arr;
		m_arr = tmp;
		m_capacity = m_size;
	}
}

template <typename T>
T& Vector<T>::at(size_t index) const
{
	if (index >= m_size) {
		throw std::out_of_range("Index out of bounds");
	}
	return m_arr[index];
}

template <typename T>
T& Vector<T>::front() const
{
	if (!empty())
	{
		return m_arr[0];
	}
	else {
		throw std::out_of_range("front() called on an empty vector");
	}
}

template <typename T>
T& Vector<T>::back() const
{
	if (!empty())
	{
		return m_arr[m_size - 1];
	}
	else {
		throw std::out_of_range("back() called on an empty vector");
	}
}

template <typename T>
T* Vector<T>::data() const
{
	return m_arr;
}

template <typename T>
T& Vector<T>::operator[](size_t index) {
	if (index >= m_size) {
		throw std::out_of_range("Index out of bounds");
	}
	return m_arr[index];
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const {
	if (index >= m_size) {
		throw std::out_of_range("Index out of bounds");
	}
	return m_arr[index];
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& vec)
{
	if (*this != vec) {
		delete[] m_arr;
		m_size = vec.m_size;
		m_capacity = vec.m_capacity;
		m_arr = new T[m_capacity];
		for (size_t i = 0; i < m_size; ++i) {
			m_arr[i] = vec.m_arr[i];
		}
	}
	return *this;
}

template <typename T>
bool Vector<T>::operator==(const Vector<T>& vec) const
{
	if(m_size != vec.m_size) {
		return false;
	}

	for (size_t i = 0; i < m_size; ++i) {
		if (m_arr[i] != vec.m_arr[i]) {
			return false;
		}
	}

	return true;
}

template <typename T>
bool Vector<T>::operator!=(const Vector<T>& vec) const
{
	return !(*this == vec);
}

template class Vector<int>;