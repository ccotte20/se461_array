// Honor Pledge:
// I pledge that I have neither given nor 
// received any help on this assignment.
// Clark Otte

#include "Array.h"

// Dr. Ryan: We want to place these in the Header file to avoid multiple inclusion.
//			 The Header Guard will protect it - here it is has no protection.
// Fixed: #include <stdexcept>/<iostream> moved to Array.h
#define DEFAULT_SIZE 10

Array::Array (void) : data_(new char[DEFAULT_SIZE]), cur_size_(DEFAULT_SIZE), max_size_(DEFAULT_SIZE)
{
	
}

// Dr. Ryan: We need to check to make sure that the user has not specified an Array of size 0 here - thus
//			 we will have to use the Constructors body in this instance.
// Fixed: moved initializations to body and added check for nonzero/nonnegative size 
Array::Array (size_t length)
{
	if(length > 0)
	{
		this->data_ = new char[length];
		this->cur_size_ = length;
		this->max_size_ = length;
	}
}

Array::Array (size_t length, char fill)
{
	// Dr. Ryan: Why not use the Fill Method we have in this class to do this work for us - avoid code
	//			 duplication.
	// Fixed: moved initializations to body, addded check for nonzero/nonnegative size, and used fill method
	if(length > 0)
	{
		this->data_ = new char[length];
		this->cur_size_ = length;
		this->max_size_ = length;
		this->fill(fill);
	}
}

Array::Array (const Array & arr) : data_(new char[arr.size()]), cur_size_(arr.size()), max_size_(arr.max_size())
{
	// Dr. Ryan: Will it ALWAYS need to be resized - otherwise we are doing unnecessary work.
	// Fixed: removed call to resize method, already initialized to correct size
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
	// Dr. Ryan: Always check for self assignment first.
	// Fixed: Added check to see if rhs is not equal to this array
	
	// Dr. Ryan: Will it ALWAYS need to be resized - otherwise we are noing unnecessary work.
	// Fixed: used dynamic memory to set equal
	if(this!= &rhs)
	{
		delete [] data_;
		this->cur_size_ = rhs.size();
		this->max_size_ = rhs.max_size();
		this->data_ = new char[this->cur_size_];
		
		for(int i=0; i<this->cur_size_; i++)
		{
			this->data_[i]=rhs[i];
		}
	}
}

char & Array::operator [] (size_t index)
{
	if(0 <= index && index < this->cur_size_)
	{
		return this->data_[index];
	}
	else
	{
		throw std::out_of_range("Out of Range");
	}
}

const char & Array::operator [] (size_t index) const
{
	if(0 <= index && index < this->cur_size_)
	{
		return this->data_[index];
	}
	else
	{
		throw std::out_of_range("Out of Range");
	}
}

char Array::get (size_t index) const
{
	if(0 <= index && index < this->cur_size_)
	{
		return this->data_[index];
	}
	else
	{
		throw std::out_of_range("Out of Range");
	}
}

void Array::set (size_t index, char value)
{
	if(0 <= index && index < this->cur_size_)
	{
		this->data_[index]=value;
	}
	else
	{
		throw std::out_of_range("Out of Range");
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
	// Dr. Ryan: Why not just use the method below here and just pass '0' as the starting point?
	//			 That way we can reuse code - work smarter not harder!
	// Fixed: Called find method with start of zero
	find(ch, 0);
}

int Array::find (char ch, size_t start) const
{
	if(0 <= start && start < this->cur_size_)
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
	else
	{
		throw std::out_of_range("Out of Range");
	}
}

bool Array::operator == (const Array & rhs) const
{
	// Dr. Ryan: Always check for self-comparison first.
	// Fixed: Check to see if rhs is pointing to the same thing as this
	if(this == &rhs)
	{
		return true;
	}
	else if(this->cur_size_!=rhs.size())
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
	// Dr. Ryan: Why don't we just call the above method and negate the result here?
	// Fixed: returned negated result of '==' method
	
	return !(*this==rhs);
}

void Array::fill (char ch)
{
	for(int i=0; i<this->cur_size_; i++)
	{
		this->data_[i]=ch;
	}
}