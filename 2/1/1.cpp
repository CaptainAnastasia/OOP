#include <iostream>
#include <iomanip>
#include <cmath>
#include "Vector.h"
#include "Matrix.h"
using namespace std;
/*Написать классы Vector и Matrix для хранения и обработки одномерных и двумерных массивов, соответственно. Реализовать задание 2 лабораторной работы №1
с помощью созданных классов. Все функции оформить в виде методов классов.
В коде отразить следующее:
Выделение и освобождение динамической памяти производить в конструкторах и деструкторах классов, соответственно.
 В классе Vector перегрузить оператор индексации []. В классе Matrix добавить методы T at(int i, int j) const и setAt(int i, int j, T val),
которые позволяют получить и установить значение элемента массива с индексом [i][j], T – это тип элементов массива по варианту (int или double).
 Перегрузить операторы инкремента и декремента (как префиксного, так и постфиксного). Смысл инкремента / декремента всего массива заключается в инкременте / декременте каждого элемента массива.*/


void Initialize(Matrix& matrix)
{
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            double el = sin(i - j) + cos(i + j);
            matrix.setAt(i, j, el);
        }
    }
}
void Process(Matrix& matrix)
{
    cout << setiosflags(ios::right);
    cout << "[";
    int k = 0;
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (i == 0 && j == 0)
                cout << setw(9) << matrix.at(i, j) << " ";
            else
                cout << setw(10) << matrix.at(i, j) << " ";
        }
        if (i != 4)
            cout << endl;
    }
    cout << setw(10) << "]";
    cout << endl << endl << "=>" << endl << endl;
}




void Transformation(Matrix& matrix, Vector& vector)
{
    int cnt = 0;
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 5; ++i)
        {
            vector[cnt] = matrix.at(i, j);
            cnt++;
        }
    }
}


int main()
{
    Matrix matrix(5,3);
    Initialize(matrix);
    Process(matrix);
    Vector vector(15);
    Transformation(matrix, vector);
    cout << "[ ";
    for (int i = 0; i < 15; ++i)
    {
        cout << vector[i] << " ";
    }
    cout << "]";
 
}
