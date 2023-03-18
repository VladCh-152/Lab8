#include "Queue.h"

template <typename type> bool Queue<type>::empty() 
{
    return (f - s + 1) == 0;
}

template <typename type> Queue<type>::Queue()
{
    size = 0;
    s = 0;
    f = -1;
    val = new type[0];
}

template <typename type> void Queue<type>::push(type x) 
{
    if (f - s + 2 > size) 
    {
        size = 2 * size + 1;
        type* a = new type[size];
        for (int i = s; i <= f; i++) 
        {
            a[i] = val[i];
        }
        val = a;
    }
    f++;
    val[f] = x;
}

template <typename type> type Queue<type>::pop()
{
    if (!empty())
    {
        type ans = val[0];
        for (int i = 1; i <= f; i++)
        {
            val[i - 1] = val[i];
        }
        size--;
        f--;
        return ans;
    }
    else
    {
        throw(empty_queue());
    }
}

template <typename type> Queue<type> Queue<type>::ftol()
{
    Queue a;
    while (!empty())
    {
        a.push(this->pop());
    }
    return a;
}

template <typename type> void Queue<type>::input() 
{
    type curr;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        cin >> curr;
        push(curr);
    }
}

template class Queue<double>;
template class Queue<int>;

void DoubleQueue::solve(DoubleQueue& a, DoubleQueue& b)
{
    while (!empty()) 
    {
        double curr = pop();
        if (curr > 0) 
        {
            a.push(curr);
        }
        if (curr < 0)
        {
            b.push(curr);
        }
    }
}

void IntQueue::solve(IntQueue& a, IntQueue& b, int d)
{
    while (!empty()) 
    {
        int curr = pop();
        if (curr % d == 0) 
        {
            a.push(curr);
        }
        else 
        {
            b.push(curr);
        }
    }
}

double DoubleQueue::mean()
{
    DoubleQueue p = *this;
    double s = 0;
    int k = 0;
    while (!p.empty())
    {
        double curr = p.pop();
        if (curr > 0)
        {
            s += curr;
            k++;
        }
    }
    if (k == 0)
    {
        throw(empty_exception());
    }
    return s / k;
}

void empty_queue::queue_message() 
{
    cout << "Queue is empty!" << endl;
}

void empty_exception::queue_message()
{
    cout << "There is no positive element!" << endl;
}