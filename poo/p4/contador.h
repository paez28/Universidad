#ifndef CONTADOR_H
#define CONTADOR_H
#include <iostream>
#include <ctime>
#include <cmath>
#include <list>
#include <cstdlib>

using namespace std;


class Contador{

private:
    int Min_, Max_;
    int Num_;
    int it_;
    list <int> Nit_;

public:
  inline  void setMin(int min){Min_ = min;};
  inline  int getMin(){return Min_;};

  inline void setMax(int max){Max_= max;};
  inline int getMax(){return Max_;};

  inline void setNum(int num){Num_ = num;};
  inline int get(){return Num_;};

  inline int getIt(){return it_;};

  Contador(int num=0, int min=0, int max=1000);

  Contador operator =(Contador c);
  Contador operator =(const int &Num);
  Contador operator ++(void);
  Contador operator ++(int);
  Contador operator --(void);
  Contador operator --(int);
  Contador operator +(int x);
  friend Contador operator +(int x, Contador cont);
  Contador operator -(int x);
  friend Contador operator -(int x, Contador cont);

  bool undo(int n=1);

};

#endif