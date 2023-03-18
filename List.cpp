#include "List.h"

template class List<double>;
template class List<char>;

template <typename type> List<type>::List() 
{
    next = NULL;
    pr = NULL;
}

template <typename type> List<type>::List(type x) 
{
    this->val = x;
    this->next = NULL;
    this->pr = NULL;
}

template <typename type> bool List<type>::empty(List* a)
{
    return (a == NULL);
}

template <typename type> type List<type>::get_val() 
{
    return (this->val);
}

template <typename type> List<type>* List<type>::get_next() 
{
    return (this->next);
}

template <typename type> List<type>* List<type>::get_pr() 
{
    return (this->pr);
}

template <typename type> void List<type>::push_back(List*& s, List*& f, type x) 
{
    List* a = s;
    if (empty(a)) 
    {
        List* b = new List(x);
        s = b;
        f = b;
    }
    else 
    {
        while (a != f)
        {
            a = a->next;
        }
        a->next = new List(x);
        a->next->pr = a;
        f = a->next;
    }
}

template <typename type> void List<type>::push_after(List*& s, List*& f, List*& x, type add) 
{
    List* a = s;
    while (a != x)
    {
        if (empty(a))
        {
            throw(empty_list());
        }
        a = a->next;
    }
    List* b = a->next;
    a->next = new List(add);
    a->next->pr = a;
    a->next->next = b;
    b->pr = a->next;
}

template <typename type> void List<type>::push_front(List*& s, List*& f, type x) 
{
    List* a = new List(x);
    if (empty(s)) 
    {
        s = a;
        f = a;
    }
    else 
    {
        a->next = s;
        s->pr = a;
        s = a;
    }
}

template <typename type> void List<type>::pop_front(List*& s, List*& f) 
{
    if (!empty(s)) 
    {
        s = s->next;
        s->pr = NULL;
    }
    else 
    {
        throw(empty_list());
    }
}

template <typename type> void List<type>::pop_curr(List*& s, List*& f, List*& b) 
{
    if (!empty(s)) 
    {
        if (b == f) 
        {
            pop_back(s, f);
        }
        else if (b == s) 
        {
            pop_front(s, f);
        }
        else  
        {
            b->pr->next = b->next;
            b->next->pr = b->pr;
            _empty(b);
        }
    }
    else 
    {
        throw(empty_list());
    }
}

template <typename type> void List<type>::pop_back(List*& s, List*& f)
{
    List* a = s;
    if (!empty(a))
    {
        while (a != f)
        {
            a = a->next;
        }
        f = a->pr;
        if (a->pr == NULL)
        {
            s = NULL;
        }
        else
        {
            f->next = NULL;
        }
    }
    else
    {
        throw(empty_list());
    }
}

void CharList::input() 
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        char a;
        cin >> a;
        push_back(s, f, a);
    }
}

void DoubleList::input()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        double a;
        cin >> a;
        push_back(s, f, a);
    }
}

bool CharList::check() 
{
    List* a = s;
    int kd = 0, kc = 0;
    char curr;
    while (!empty(a)) 
    {
        curr = (*a).get_val();
        if (curr >= '0' && curr <= '9')
        {
            kd++;
        }
        else
        {
            kc++;
        }
        a = (*a).get_next();
    }
    return (kd*3>(kd+kc));
}

void CharList::remove() 
{
    List* a = s;
    while (!empty(a)) 
    {
        if (((*a).get_val() >= 'a' && (*a).get_val() <= 'z') || ((*a).get_val() >= 'à' && (*a).get_val() <= 'ÿ'))
        {
            List* b = (*a).get_pr();
            pop_curr(s, f, a);
            if (!empty(b)) a = b;
            else a = s;
        }
        else
        {
            a = (*a).get_next();
        }
    }
}

bool DoubleList::check(int a, int b) 
{
    List* p = s;
    if (empty(p))
    {
        throw(empty_list());
    }
    double max = (*p).get_val();
    p = (*p).get_next();
    while (!empty(p)) 
    {
        if ((*p).get_val() > max) 
        {
            max = (*p).get_val();
            p = (*p).get_next();
        }
        else
        {
            p = (*p).get_next();
        }
    }
    return ((max > a && max < b) || (max < a && max > b));
}

void DoubleList::remove(double k) 
{
    List* a = s;
    while (!empty(a)) 
    {
        if (((*a).get_val()) > k)
        {
            List* b = (*a).get_pr();
            pop_curr(s, f, a);
            if (!empty(b)) a = b;
            else a = s;
        }
        else
        {
            a = (*a).get_next();
        }
    }
}

void empty_list::list_message() 
{
    cout << "List is empty!" << endl;
}
