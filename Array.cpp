#include "Array.h"

#define DEFAULT_SIZE 10

Array::Array (void) : data_(new char[DEFAULT_SIZE]), cur_size_(DEFAULT_SIZE), max_size_(DEFAULT_SIZE)
{
	
}

Array::Array (size_t length) : data_(new char[length]), cur_size_(length), max_size_(length)
{

}

Array::Array (size_t length, char fill) : data_(new char[length]), cur_size_(length), max_size_(length)
{
	this->fill[fill];
}

Array::Array (const Array & arr) : data_(new char[arr->size()]), cur_size_(arr->size()), max_size_(arr->max_size())
{
	this=arr;
}

Array::~Array (void)
{
	delete [] data_;
}

const Array & Array::operator = (const Array & rhs)
{
	this->resize(rhs->size());
	for(int i=0; i<this->cur_size_; i++)
	{
		this->data_[i]=rhs[i];
	}
}

char & Array::operator [] (size_t index)
{
	try
	{
		return this->data_[index];
	}
	catch(std::out_of_range)
	{
		throw std::out_of_range();
	}
}

const char & Array::operator [] (size_t index) const
{
	try
	{
		return this->data_[index];
	}
	catch(std::out_of_range)
	{
		throw std::out_of_range();
	}
}

char Array::get (size_t index) const
{
	try
	{
		return this->data_[index];
	}
	catch(std::out_of_range)
	{
		throw std::out_of_range();
	}
}

void Array::set (size_t index, char value)
{
	try
	{
		this->data_(index)=value;
	}
	catch(std::out_of_range)
	{
		throw std::out_of_range();
	}
}

void Array::resize (size_t new_size)
{
	if (new_size == this->cur_size_)
	{
		return;
	}
	else if (new_size > this->cur_size_)
	{
		if ( new_size > this->max_size_)
		{
			char * temp = new char[new_size];
			
			for (int i=0; i < this->cur_size_; i++)
			{
				temp[i] = this->data_[i];
			}
			
			std::swap(temp, this->data_);
			
			this->cur_size_ = new_size;
			this->max_size_ = new_size;
			
			delete [] temp;
		}
		else
		{
			this->cur_size_ = new_size;
		}
	}
	else
	{
		this->cur_size_ = new_size;
	}
}

int Array::find (char ch) const
{

}

int Array::find (char ch, size_t start) const
{

}

bool Array::operator == (const Array & rhs) const
{

}

bool Array::operator != (const Array & rhs) const
{

}

void Array::fill (char ch)
{
	for(int i=0; i<this->cur_size_; i++)
	{
		this->data_[i]=ch;
	}
}
