#include <stdio.h>
#include <iostream>

using namespace std;

template <typename type> class Queue 
{
    type* val;
    int size;
    int s, f;
public:
    Queue();
    bool empty();
    void push(type x);
    void input();
    Queue ftol();
    type pop();
    friend ostream& operator << (ostream& fout, Queue<type>& v) 
    {
        Queue<type> a;
        while (!(v.empty()))
        {
            type t = v.pop();
            a.push(t);
            fout << (t) << " ";
        }
        v = a.ftol();
        return fout;
    }
};

class DoubleQueue : public Queue<double>
{
public:
    DoubleQueue() : Queue<double>()
    {
    
    }
    void solve(DoubleQueue& a, DoubleQueue& b);
    double mean();
};

class IntQueue : public Queue<int> 
{
public:
    IntQueue() : Queue<int>()
    {
    
    }
    void solve(IntQueue& a, IntQueue& b, int d);
};

extern template class Queue<int>;
extern template class Queue<double>;

class queue_exception 
{
public:
    virtual void queue_message() = 0;
};

class empty_queue : public queue_exception 
{
public:
    empty_queue() 
    {
    
    };
    void queue_message() override;
};

class empty_exception : public queue_exception
{
public:
    empty_exception()
    {

    };
    void queue_message() override;
};