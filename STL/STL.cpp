#include <iostream>
#include <random>
#include<ctime>
#include <chrono>
#include <random>
#include<vector>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
class card
{
protected:
    int amount1;
};

class comcard : private card
{
    int money;
public:
    comcard()
    {
        amount1 = 0;
        money = 0;
    }
    comcard(int amount1, int money) {
        this->amount1 = amount1;
        this->money = money;
    }
    ~comcard() {}

    void SetM(int money)
    {
        this->money = money;
    }
    int GetM() { return money; }
    void SetAM(int amount1)
    {
        this->amount1 = amount1;
    }
    int GetAM()
    {
        return amount1;
    }

    friend int countcom(const comcard& arr);
};
int countcom(const comcard& arr)
{
    setlocale(LC_ALL, "Rus");
    int cc = 0;
    if (arr.amount1 == 0)
    {
        cout << "\nКарта этого типа имеет: " << arr.money << " денег на счету";
        cc++;
    }
    return cc;
}

class lgcard :public card
{
    int a;
public:
    lgcard()
    {
        a = 0;

        amount1 = 0;
    }

    int Geta() { a = 0; return a; }
    lgcard(int amount1, int a)
    {
        this->a = a;
        this->amount1 = amount1;
    }
    ~lgcard() {}
    int GetAm()
    {
        return amount1;
    }
    void SetAM(int amount)
    {
        this->amount1 = amount;
    }
    friend int countlg(lgcard& arr);

    friend void aaa();
};

void aaa()
{
    srand(time(NULL));

    vector<lgcard> myVector;
    vector<lgcard> reversedVector;

    for (int i = 0; i < 1000; i++) {
        lgcard obj(rand() % 10, rand() % 20);

        myVector.push_back(obj);
    }


    for (int i = myVector.size() - 1; i >= 0; i--) {
        reversedVector.push_back(myVector[i]);
    }

    int middleIndex = reversedVector.size() / 2;
    for (int i = 0; i < 500; i++) {
        lgcard zeroObj(rand() % 10, rand() % 20);
        reversedVector.insert(reversedVector.begin() + middleIndex, zeroObj);
    }

    int count = 0;
    for (const auto& obj : reversedVector) {
        if (obj.amount1 == 0) {
            count++;
        }
    }
    cout << "Количество карт без поездок: " << count;
    myVector.clear();
    reversedVector.clear();
    if (myVector.empty() && reversedVector.empty())
    {
        cout << "\nВекторы успешно очищены";
    }


}


int summa(int a)
{
    int c = 0;
    if (a == 0)
    {
        c++;
    }
    return c;
}

int randomm()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, 5);

    return dist(gen);
}

int task2(int size)
{
    int cc = 0;
    comcard a; lgcard b;
    lgcard* arr2 = new lgcard[size];
    comcard* arr1 = new comcard[size];

    for (int i = 0; i < size; i++)
    {
        arr1[i].SetAM(randomm());
        arr1[i].SetM(110);
    }

    for (int i = 0; i < size; i++)
    {
        arr2[i].SetAM(randomm());
    }

    for (int i = 0; i < size; i++)
    {
        cc += summa(arr1[i].GetAM());
    }

    for (int i = 0; i < size; i++)
    {
        cc += summa(arr2[i].GetAm());
    }
    delete[]arr1;
    delete[]arr2;

    return cc;
}
void task3()
{
    lgcard a;

}
void main()
{
    setlocale(LC_ALL, "Rus");
    lgcard a;
    task3();
    aaa();
    cout << "\nКоличество карт без поездок(из другого файла): " << task2(5);
    while (true)
    {
        int choice;
        cout << "\n\nМеню:" << endl;
        cout << "1. Вывод карт без поездок(наследуемое) " << endl;
        cout << "2. Вывод карт без поездок(из другого файла) " << endl;
        cout << "3. Завершить программу " << endl;
        cout << "4. Вывести вычесляемый показатель, используя векторы" << endl;

        cout << "\nВведите свой выбор: ";
        cin >> choice;
        while (cin.fail()) {
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Ошибка! Введите ЧИСЛО согласно номеру в меню: ";
            cin >> choice;
        }

        switch (choice)
        {
        case(1): { aaa(); break; }
        case(2): {cout << "\nКоличество карт без поездок(из другого файла): " << task2(5); break; }
        case(3): {task3(); break; }
        case(4): {exit(0); }
        }
    }
    setlocale(LC_ALL, "Rus");

}
