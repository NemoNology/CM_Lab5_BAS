#include <iostream>
#include <vector>
#include <iomanip>
#include <exception>


using namespace std;


// Функция для вывода 2D матрицы;
void Show_2D_Matrix(const vector<vector<double>>& a) {
    cout << "\n\n";
    for (unsigned short i = 0; i < a.size(); i++) {
        cout << "\t";
        for (unsigned short j = 0; j < a[i].size(); j++) {

            cout << setw(16) << setprecision(8) << a[i][j];

        }
        cout << endl;
    }
    cout << "\n\n";
}

// Функция для вывода 1D матрицы
void Show_1D_Matrix(const vector<double>& a) {
    cout << "\n\n";
    for (unsigned short i = 0; i < a.size(); i++) {

        cout << setprecision(8) << "\t" << setw(10) << a[i] << "\n";

    }
    cout << "\n\n";
}


// Функция для обнуления 2D матрицы
void Zeroing_2D_Matrix(vector<vector<double>>& a) {

    for (unsigned short i = 0; i < a.size(); i++) {
        for (unsigned short j = 0; j < a[i].size(); j++) {

            a[i][j] = 0;

        }
    }

}


// Функция для перестановки строк, при условии, что a[0][0] (На которое мы делим) = 0 
void Swith_Lines_a00(vector<vector<double>>& a) {


    static unsigned short i = 1; // Создаём статическую переменную для хранения индекса строки, с которой будем менять a[0] 

    if (i >= a.size()) { // При превышении размерности массива выбрасываем ошибку о неправильной матрице

        throw invalid_argument("Матрица не та...");

    }

    vector<double> temp(a.size());


    temp = a[0];
    a[0] = a[i];
    a[i] = temp;

    i++; // Увеличиваем i на единицу, чтобы при повторном вызове данного метода менять местами a[0] уже со следующей строкой
}

// Метод Халецкого;
void Method(const vector<vector<double>>& a) {


    // Создание 1Д\2Д матриц для записи B & T; Y матриц, а также для записи результатов (х)
    vector<double> x(a.size());
    vector<double> y(a.size());
    vector<double> с(a.size());
    vector<vector<double>> b = a;
    vector<vector<double>> t = a;


    // Обнуляем матрицы B & T
    Zeroing_2D_Matrix(b);
    Zeroing_2D_Matrix(t);


    // Вычисляем элементы матриц B & T

    // Вычисление b[i][0] & t[0]["j"]
    for (unsigned short i = 0; i < b.size(); i++) {

        b[i][0] = a[i][0];

        for (unsigned short j = 1; j < t.size(); j++) {

            t[0][j] = a[0][j] / b[0][0];

            /*for (unsigned short k = 1; k < a.size(); k++) {
                for (unsigned short m = 0; m < k; m++) {

                    b[i][k] = 

                }
            }*/

        }

        /*cout << "\n\tStep 1:\n\t\tB:\t(" + i  << ")";
        Show_2D_Matrix(b);
        cout << "\n\t\tT:\t(" + i << ")";
        Show_2D_Matrix(t);*/

    }

    for (unsigned short k = 1; k < a.size(); k++) {
        for (unsigned short i = k; i < a.size(); i++) {               // Просто иду по алгоритму в примере...

            b[i][k] = a[i][k];

            for (unsigned short m = 0; m < k; m++) {

                b[i][k] -= b[i][m] * t[m][k];

            }

        }

        if (k < a.size() - 1) {

            for (unsigned short j = k + 1; j < a.size(); j++) {        // Просто иду по алгоритму в примере...

                t[k][j] = a[k][j];

                for (unsigned short m = 0; m < k; m++) {

                    t[k][j] -= b[k][m] * t[m][j];

                }

                t[k][j] /= b[k][k];

            }
        }
    }



}


int main()
{



    // Мой массив
    // ##############################################################

    vector<vector<double>> mat = {
    {0.42, -0.72, 0.02, -0.28, 0.2, 0.66},
    {-0.67, 0.17, -0.86, 0.88, -0.88, 0.53},
    {0.14, -0.11, 0.86, -0.61, 0.61, 0.32},
    {0.83, -0.97, -0.29, -0.66, 0.7, -0.88},
    {0.91, -0.04, -0.41, -0.24, 0.09, 0.66} };

    // ##############################################################


    // Вызов метода
    cout << "\nInitial matrix:";
    Show_2D_Matrix(mat);

    // Проверка на a[0][0] = 0 // Не в методе, ибо там const принимаемая матрица
    try {

        while (mat[0][0] == 0) {

            Swith_Lines_a00(mat);

        }
    }

    catch (invalid_argument e) { // Ошибка

        cout << "\n\tВходная матрица не соответствует условиям метода!\n\ta[0][0] = 0!\n\n";
        return 0;

    }

    // Вывод результатов решения
    cout << "\nFinal response matrix";
    Method(mat);

    system("pause"); // Окончание программы
    return 0;
}