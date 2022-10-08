#ifndef VECTOR
#define VECTOR
#include <iostream>
#include <string.h>

template <typename T>
class Vector
{
private:
	int m_size;
	uint m_capacity;
	T *vector;

	// Note this is a private method for helping us expand the Vector if need be.
	void expand(uint capacity)
	{
		this->m_capacity = capacity;
		this->vector = (T *)realloc(this->vector, m_capacity * sizeof(T));

		if (this->vector == NULL)
		{
			printf("Memory not allocated.\n");
			exit(1);
		}
	}

public:
	Vector()
	{
		this->m_size = 0;
		this->m_capacity = 10;
		this->vector = (T *)calloc(m_capacity, sizeof(T));

		if (vector == NULL)
		{
			printf("Memory not allocated.\n");
			exit(1);
		}
	}

	Vector(int size)
	{
		this->m_size = size;
		this->m_capacity = size * 2;
		this->vector = (T *)calloc(m_capacity, sizeof(T));

		if (this->vector == NULL)
		{
			printf("Memory not allocated.\n");
			exit(1);
		}
	}

	~Vector()
	{
		free(this->vector);
	}

	void push(T data)
	{
		std::cout << "Size:" << m_size << "\nCapacity:" << m_capacity << std::endl;

		if (m_size == (m_capacity - 1))
			this->expand(m_capacity * 2);

		this->vector[m_size] = data;
		this->m_size++;
	}

	void write(int index, T data)
	{
		this->vector[index] = data;
	}

	void insert(int index, T data)
	{
		if (m_size == (m_capacity - 1))
			this->expand(m_capacity * 2);

		for (int i = m_size; i > index; i--)
			this->vector[i] = this->vector[i - 1];

		this->vector[index] = data;
		this->m_size++;
	}

	int size() const
	{
		return this->m_size;
	}

	int capacity() const
	{
		return this->m_capacity;
	}

	void print() const
	{

		if (this->m_size > 0)
		{
			std::string elements = "[";

			for (int i = 0; i < this->m_size; i++)
			{
				if (i != this->m_size - 1)
				{
					elements += std::to_string(this->vector[i]) + ", ";
				}
				else
				{
					std::string str = std::to_string(this->vector[i]);
					elements += str;
				}
			}

			elements += "]\n";
			std::cout << elements;
		}
	}

	void print(std::ostream &stream) const
	{

		if (this->m_size > 0)
		{
			std::string elements = "[";

			for (int i = 0; i < this->m_size; i++)
			{
				if (i != this->m_size - 1)
				{
					elements += std::to_string(this->vector[i]) + ", ";
				}
				else
				{
					std::string str = std::to_string(this->vector[i]);
					elements += str;
				}
			}

			elements += "]\n";
			stream << elements;
		}
	}

	T operator[](int index) const
	{
		return this->vector[index];
	}

	T &operator[](int index)
	{
		return &this->vector[index];
	}

	friend std::ostream &operator<<(std::ostream &stream, const Vector<T> &vectorInput)
	{
		vectorInput.print(stream);

		return stream;
	}
};

#endif /* VECTOR */