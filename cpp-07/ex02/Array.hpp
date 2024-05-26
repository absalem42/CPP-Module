#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <class T>
class Array{
    private:
        unsigned int length;
        T *data;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array	&operator=(const Array &other);
        ~Array();
        
        unsigned int	size() const;

        T	&operator[](unsigned int index);
	    const T	&operator[](unsigned int index) const;

};

template <class T>
Array<T>::Array() : length(0), data(NULL) {}

template <class T>
Array<T>::Array(unsigned int n) : length(n), data(new T[n]()) {}

template <typename T>
Array<T>::Array(const Array& other) : length(other.length), data(new T[other.length]()) 
{
    for (unsigned int i = 0; i < length; ++i) 
    {
        data[i] = other.data[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) 
{
    if (this != &other) 
    {
        T* newData = new T[other.length]();
        for (unsigned int i = 0; i < other.length; ++i)
        {
            newData[i] = other.data[i];
        }
        delete[] data;
        data = newData;
        length = other.length;
    }
    return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) 
{
    if (index >= length) 
    {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const 
{
    if (index >= length) 
    {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

template <typename T>
unsigned int Array<T>::size() const 
{
    return length;
}

template <typename T>
Array<T>::~Array() 
{
    delete[] data;
}

#endif