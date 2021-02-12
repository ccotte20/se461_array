// Honor Pledge:
// I pledge that I have neither given nor 
// received any help on this assignment.
// Clark Otte

#include "Array.h"

#include <stdexcept>
#include <iostream>

#define DEFAULT_SIZE 10

Array::Array (void) : data_(new char[DEFAULT_SIZE]), cur_size_(DEFAULT_SIZE), max_size_(DEFAULT_SIZE)
{
	
}

Array::Array (size_t length) : data_(new char[length]), cur_size_(length), max_size_(length)
{

}

Array::Array (size_t length, char fill) : data_(new char[length]), cur_size_(length), max_size_(length)
{
	for(int i=0; i<this->cur_size_; i++)
	{
		this->data_[i]=fill;
	}
}

Array::Array (const Array & arr) : data_(new char[arr.size()]), cur_size_(arr.size()), max_size_(arr.max_size())
{
	this->resize(arr.size());
	for(int i=0; i<this->cur_size_; i++)
	{
		this->data_[i]=arr[i];
	}
}

Array::~Array (void)
{
	delete [] data_;
}

const Array & Array::operator = (const Array & rhs)
{
	this->resize(rhs.size());
	for(int i=0; i<this->cur_size_; i++)
	{
		this->data_[i]=rhs[i];
	}
}

char & Array::operator [] (size_t index)
{
	if(index > this->cur_size_)
	{
		throw std::out_of_range("Out of Range");
	}
	else
	{
		return this->data_[index];
	}
}

const char & Array::operator [] (size_t index) const
{
	if(index > this->cur_size_)
	{
		throw std::out_of_range("Out of Range");
	}
	else
	{
		return this->data_[index];
	}
}

char Array::get (size_t index) const
{
	if(index > this->cur_size_)
	{
		throw std::out_of_range("Out of Range");
	}
	else
	{
		return this->data_[index];
	}
}

void Array::set (size_t index, char value)
{
	if(index > this->cur_size_)
	{
		throw std::out_of_range("Out of Range");
	}
	else
	{
		this->data_[index]=value;
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
	for(int i=0; i<this->cur_size_; i++)
	{
		if(this->data_[i]==ch)
		{
			return i;
		}
	}
	return -1;
}

int Array::find (char ch, size_t start) const
{
	if(start > this->cur_size_)
	{
		throw std::out_of_range("Out of Range");
	}
	else
	{
		int i = static_cast<int>(start);
		for(i; i<this->cur_size_; i++)
		{
			if(this->data_[i]==ch)
			{
				return i;
			}
		}
		return -1;
	}
}

bool Array::operator == (const Array & rhs) const
{
	if(this->cur_size_!=rhs.size())
	{
		return false;
	}
	else
	{
		for(int i=0; i<this->cur_size_; i++)
		{
			if(this->data_[i]!=rhs[i])
			{
				return false;
			}
		}
		return true;
	}
}

bool Array::operator != (const Array & rhs) const
{
	if(this->cur_size_!=rhs.size())
	{
		return true;
	}
	else
	{
		for(int i=0; i<this->cur_size_; i++)
		{
			if(this->data_[i]!=rhs[i])
			{
				return true;
			}
		}
		return false;
	}
}

void Array::fill (char ch)
{
	for(int i=0; i<this->cur_size_; i++)
	{
		this->data_[i]=ch;
	}
}