#define _CRT_SECURE_NO_WARNINGS 1
#define gets gets_s
#include<bits/stdc++.h>
using namespace std;
const int maxn = (1 << 20) + 10;

void printDequeInt(deque<int>& d)
{
    deque<int>::iterator it = d.begin();
    for (; it != d.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;
}
void t1()
{
    deque<int>d1;

    d1.push_back(1);
    d1.push_back(2);
    d1.push_back(3);
    d1.push_front(4);
    d1.push_front(5);
    d1.push_front(6);
    printDequeInt(d1);

    cout << "大小：" << d1.size() << endl;

    d1.pop_front();
    printDequeInt(d1);

    d1.pop_back();
    printDequeInt(d1);

    d1.insert(d1.begin() + 1, 3, 100);
    printDequeInt(d1);
}

class Person
{
    friend void showPerson(vector<Person>& v);
    friend void playGame(vector<Person>& v);
public:
    Person(){}
    Person(string name, double score)
    {
        this->name = name;
        this->score = score;
    }
    ~Person(){}

private:
    string name;
    double score;
};

void createPerson(vector<Person>& v)
{
    string tmpName = "ABCDE";
    for (int i = 0; i < 5; i++) {
        string name = "选手";
        name += tmpName[i];
        v.push_back(Person(name, 0));
    }
}
void showPerson(vector<Person>& v)
{
    vector<Person>::iterator it = v.begin();
    for (; it != v.end(); it++) {
        cout << it->name << " " << it->score << endl;
    }
    cout << endl;
}
void playGame(vector<Person>& v)
{
    vector<Person>::iterator it = v.begin();
    for (; it != v.end(); it++) {
        deque<double>d;
        for (int i = 0; i < 10; i++) {
            d.push_back((double)(rand() % 41 + 60));
        }

        sort(d.begin(), d.end());
        d.pop_back();
        d.pop_front();

        it->score = (double)accumulate(d.begin(), d.end(), 0) / d.size();
    }
}
void t2()
{
    vector<Person>v;
    srand(time(NULL));
    createPerson(v);
    showPerson(v);
    playGame(v);
    showPerson(v);
}
int main()
{
    //t1();
    t2();
    return 0;
}