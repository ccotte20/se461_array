// Honor Pledge:
// I pledge that I have neither given nor 
// received any help on this assignment.
// Clark Otte

#include "Array.h"
int main()
{
	Array a(8);
	a[3] = 20;
	
	Array b(10, 'b');
	a=b;
	
	for(int i=0; i<10; i++)
	{
		std::cout<<a[i]<<std::endl;
	}
	
	try
	{
		std::cout<<a[20]<<std::endl;
	}
	catch(std::exception ex)
	{
		std::cout<<"out of bounds"<<std::endl;
	}
	
	if(a==a)
	{
		std::cout<<"Yay"<<std::endl;
	}
	
	if(a==b)
	{
		std::cout<<"Yay"<<std::endl;
	}
	
	Array c;
	c.fill('c');
	
	if(a==c)
	{
		std::cout<<"oh no"<<std::endl;
	}
	else
	{
		std::cout<<"Not equal"<<std::endl;
	}
	
	if(a!=c)
	{
		std::cout<<"not equal either"<<std::endl;
	}
	
	c.resize(13);
	
	c[10]='z';
	c[11]='y';
	c[12]='x';
	
	c.set(5, 'b');
	std::cout<<c.get(5)<<std::endl;
	std::cout<<c.find('z', 5)<<std::endl;
	
	Array d(c);
	
	for(int i=0; i<d.size(); i++)
	{
		std::cout<<d[i]<<std::endl;
	}
	
	
	return 0;
}