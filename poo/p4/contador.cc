#include "contador.h"


Contador:: Contador(int num, int min, int max){

	it_=0;

	if(num > max || num < min)
    {
 		setMax(1000);
  		setMin(0);
  		setNum(0);
  		it_++;
  		Nit_.push_back(Num_);
    }

	else if(max<=min)
    {
  		setMax(1000);
  		setMin(0);
  		setNum(0);
  		it_++;
		Nit_.push_back(Num_);
	}

	else
    {
  		setMax(max);
  		setMin(min);
  		setNum(num);
  		it_++;
		Nit_.push_back(Num_);
	}

}

Contador Contador::operator =(Contador cont)
{
	setNum( cont.get() );
	setMin( cont.getMin() );
	setMax( cont.getMax() );
	it_++;
	Nit_.push_back(Num_);
	return *this;
}

Contador Contador::operator =(const int &num){

	if(num < Min_)
    {
		setNum(Min_);
		it_++;
		Nit_.push_back(Num_);
	}
	
	else if (num > getMax())
    {	
		setNum(Max_);
		it_++;
		Nit_.push_back(Num_);
	}
	
	else{
		setNum(num);
		it_++;
		Nit_.push_back( Num_ );
	}

	return *this;
}

Contador Contador::operator ++(void)//++ prefijo
{
	if(Num_ < Max_)
    {
		Num_++;
		it_++;
	}
	return *this;
}

Contador Contador::operator ++(int)//++ sufijo
{
	Contador t = *this;

	if(Num_ < Max_)
    {
		Num_++;
		it_++;
	}

	Nit_.push_back(Num_);
	return t;
}

Contador Contador::operator --(void)//-- prefijo
{	
	if(Num_ > Min_)
    {
		Num_--;
		it_++;

	}
	return *this;
}

Contador Contador::operator --(int)//-- sufijo
{
	Contador t = *this;
	if(Num_ > Min_)
    {
		Num_--;
		it_++;
	}

	Nit_.push_back(Num_);
	return t;
}

Contador Contador::operator +(int x){//c+a

	if((Num_+x) < Max_ )
    {
		Num_ = Num_+x;
	}

	else
    {
		Num_ = Max_;
	}

	it_++;
	Nit_.push_back(Num_);
	return *this;
}

Contador operator +(int x, Contador cont){//a+c

	Contador auxil(cont);
	
	if( (auxil.get() + x) < auxil.getMax())
    {
		auxil.setNum(auxil.get() + x);
	}
	
	else
    {
		auxil.setNum(auxil.getMax() );
	}
	
	auxil.it_++;
	auxil.Nit_.push_back(auxil.Num_);
	return auxil;
}

Contador Contador::operator -(int x)//c-a
{
	if((Num_-x) > Min_)
    {
		Num_ = Num_-x;
	}
	
	else
    {
		Num_ = Min_;
	}

	it_++;
	Nit_.push_back(Num_);
	return *this;

}

Contador operator -(int x, Contador cont)//a-c
{
	Contador auxil(cont);

	if((x-auxil.get()) > auxil.getMin())
    {
		auxil.setNum(x-auxil.get());
	}
	
	else
    {
		auxil.setNum(auxil.getMin());
	}

	auxil.it_++;
	auxil.Nit_.push_back(auxil.Num_);
	return auxil;
}

bool Contador::undo(int n)
{
	int a;

	if(n > (it_ - 1) || n<1)
    {
        return false;
    }

	else
    {
		for(a=0; a<it_ -1; a++)
        {
			Nit_.pop_back(); 
			Num_ = Nit_.back();
		}
		return true;
	}
}