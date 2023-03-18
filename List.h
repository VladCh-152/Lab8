#include <stdio.h>
#include <iostream>
#include <fstream>

using namespace std;

template <typename type> class List 
{
    List* next;
    List* pr;
    type val;
public:
    List();
    List(type x);
    bool empty(List* a);
    void _empty(List*& a)
    {
        a = NULL;
    };
    type get_val();
    List* get_next();
    List* get_pr();
    void push_back(List*& s, List*& f, type x);
    void push_front(List*& s, List*& f, type x);
    void pop_back(List*& s, List*& f);
    void pop_curr(List*& s, List*& f, List*& b);
    void pop_front(List*& s, List*& f);
    void push_after(List*& s, List*& f, List*& x, type add);
};

class DoubleList : public List<double> 
{
public:
    List* s, * f;
    DoubleList()
    {
        _empty(s);
        _empty(f);
    };
    DoubleList(double x) : List<double>(x)
    {
        s = this;
        f = this;
    };

    bool check(int a, int b);
    void remove(double k);
    void input();
    friend ostream& operator<< (ostream& f, DoubleList& v)
    {
        List* a = v.s;
        while (!v.empty(a)) 
        {
            f << (*a).get_val() << " ";
            a = (*a).get_next();
        }
        return f;
    }
};

class CharList : public List<char> 
{
public:
    List* s, * f;
    CharList()
    {
        _empty(s);
        _empty(f);
    };
    CharList(char x) : List<char>(x)
    {
        s = this;
        f = this;
    };

    bool check();
    void remove();
    void input();
    friend ostream& operator<< (ostream& f, CharList& v)
    {
        List* a = v.s;
        while (!v.empty(a))
        {
            f << (*a).get_val() << " ";
            a = (*a).get_next();
        }
        return f;
    }
};

extern template class List<double>;
extern template class List<char>;

class list_exception 
{
public:
    virtual void list_message() = 0;
};

class empty_list : public list_exception 
{
public:
    empty_list() 
    {
    
    };
    void list_message() override;
};
