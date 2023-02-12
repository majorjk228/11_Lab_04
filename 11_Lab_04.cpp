// Лабораторная работа №11(4), Вариант 3 (2 семестр).
//

#include <iostream>
#include <stack>
#include <vector>
#include "Time.h"
using namespace std;

typedef stack<Time>St;//стек
typedef vector<Time>Vec;//вектор

St make_stack(int n)
{
    St s;
    Time t;
    for (int i = 0; i < n; i++)
    {
        cin >> t;//ввод переменной
        s.push(t);//добавление ее в стек
    }
    return s;//вернуть стек как результат функции
}


//печать стека
void print_stack(St s)
{
    Vec v;
    while (!s.empty())//пока стек не пустой
    {
        cout << s.top() << endl;//вывод элемента в вершине стека

        //добавить в вектор элемент из конца очереди
        v.push_back(s.top());
        s.pop();//удаляем элемент из конца
    }
}

//копирует стек в вектор
Vec copy_stack_to_vector(St s)
{
    Vec v;
    while (!s.empty())//пока стек не пустой
    {
        //добавить в вектор элемент из вершиы стека
        v.push_back(s.top());
        s.pop();
    }
    return v; //вернуть вектор как результат функции
}
//копирует вектор в стек
St copy_vector_to_stack(Vec v)
{
    St s;
    for (int i = 0; i < v.size(); i++)
    {
        s.push(v[i]);//добавить в стек элемент вектора
    }
    return s; //вернуть стек как результат функции
}

//поиск максимального элемента в стеке
Time Max(St s)
{
    Time m = s.top();//переменной m присваиваем значение из вершины стека
    Vec v = copy_stack_to_vector(s);//копируем стек в вектор
    while (!s.empty())//пока стк не пустой
    {
        if (s.top() > m)m = s.top();//срвниваем m и элемнт в вершине стека
        s.pop();//удаляем элемент из стека
    }
    s = copy_vector_to_stack(v);//копиуем вектор в стек
    return m; //возвращаем m
}
//Удалить максимальный элемент из стека
void Delete_from_stack(St& s)
{
    Time m;//= Max(s);//находим максимальный элемент
    Vec v;
    Time t;
    while (!s.empty())//пока стек не пустой
    {
        t = s.top();//получаем элемент из вершины стека
        //если он не равен максимальному, заносим элемент в вектор
        //if (t != m)v.push_back(t); //---------Тут почему то выкидыает ошибку..... if (i != pos) v.push_back(t);
       // if (t != m)v.push_back(t);
        s.pop();//удаляем элемент из стека
    }
    s = copy_vector_to_stack(v);//копируем вектор в стек
}

//поиск минимального элемента
Time Min(St s)
{
    Time m = s.top();
    Vec v = copy_stack_to_vector(s);
    while (!s.empty())
    {
        if (s.top() < m)m = s.top();
        s.pop();
    }
    s = copy_vector_to_stack(v);
    return m;
}
//деление на минимальный
void Delenie(St& s)
{
    Time m = Min(s);//находим минимальный элемент
    Vec v;
    Time t;
    while (!s.empty())//пока стек не пустой
    {
        t = s.top(); //получаем элемент из вершины
            v.push_back(t / m);//делим t на минимальный и добавляем в вектор
        s.pop();//удаляем элемент из вершины
    }
    s = copy_vector_to_stack(v);//копируем вектор в стек
}

//добавление элемента в стек
void Add_to_stack(St& s, Time el)
{
    s.push(el);
}

//Удалить элемент из стека
void del_to_queue(St& s, int pos)
{
    int i = 1;
    Vec v;
    Time t;
    while (!s.empty())//пока стек не пустой
    {
        t = s.top();//получаем элемент из вершины стека
        //если он не равен максимальному, заносим элемент в вектор
        if (i != pos) v.push_back(t);
        s.pop();//удаляем элемент из стека
        i++;
    }
    s = copy_vector_to_stack(v);//копируем вектор в стек
}

int main()
{
    Time t;
    St s;
    int n;
    cout << "n?";
    cin >> n;
    s = make_stack(n);  //создать стек
    print_stack(s);     //печать стека

    cout << "Max: " << Max(s) << endl;

    cout << "del pos?";
    int pos;
    cin >> pos;//вводим позицию для добавления

    del_to_queue(s, pos);//добавление элемента
    print_stack(s);//печать стека

}


