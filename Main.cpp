#include <iostream>
#include "List.h"
#include <fstream>
#include "Queue.h"

int main() 
{
    ofstream fout;
    fout.open("output.txt");

    try
    {
        DoubleQueue a, b, c;
        a.input();
        cout << a.mean() << endl;
        fout << a << endl << endl;
        a.push(1);
        a.push(2);
        a.push(-3);
        fout << a << endl << endl;
        a.pop();
        fout << a << endl << endl;
        a.solve(b, c);
        fout << b << endl << c << endl << endl;

        IntQueue a1, b1, c1;
        a1.input();
        fout << a1 << endl << endl;
        a1.push(1);
        a1.push(-2);
        a1.push(-3);
        fout << a1 << endl << endl;
        a1.pop();
        fout << a1 << endl << endl;
        a1.solve(b1, c1, 2);
        fout << b1 << endl << c1 << endl << endl;
    }
    catch (queue_exception& e) 
    {
        e.queue_message();
    }

    fout << endl << endl;
    
    try 
    {
        DoubleList a;
        a.input();
        fout << a << endl << endl;
        a.push_back(a.s, a.f, 4);
        fout << a << endl << endl;
        a.push_front(a.s, a.f, 3);
        fout << a << endl << endl;
        a.pop_back(a.s, a.f);
        a.pop_front(a.s, a.f);
        fout << a << endl << endl;
        if (a.check(2, 16))
        {
            a.remove(5);
        }
        fout << a << endl << endl;

        CharList a1;
        a1.input();
        fout << a1 << endl << endl;
        a1.push_back(a1.s, a1.f, 'v');
        fout << a1 << endl << endl;
        a1.push_front(a1.s, a1.f, 'a');
        fout << a1 << endl << endl;
        a1.pop_back(a1.s, a1.f);
        a1.pop_front(a1.s, a1.f);
        fout << a1 << endl << endl;
        if (a1.check())
        {
            a1.remove();
        }
        fout << a1 << endl << endl;
    }
    catch (list_exception& e) 
    {
        e.list_message();
    }
    fout.close();
}
