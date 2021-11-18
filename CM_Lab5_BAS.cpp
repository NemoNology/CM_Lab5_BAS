#include <iostream>
#include <vector>
#include <iomanip>


using namespace std;


// Функции для вывода:


// Функция для вывода 2D матрицы;
void Show_2D_Matrix(const vector<vector<double>>& a) {
    cout << "\n\n";
    for (unsigned short i = 0; i < a.size(); i++) {
        cout << "\t";
        for (unsigned short j = 0; j < a[i].size(); j++) {

            cout << setw(10) << setprecision(8) << a[i][j];

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



//##################################################################################################################

// Различные методы:


// Функция для обнуления 2D матрицы
void Zeroing_2D_Matrix(vector<vector<double>>& a) {

    for (unsigned short i = 0; i < a.size(); i++) {
        for (unsigned short j = 0; j < a[i].size(); j++) {

            a[i][j] = 0;

        }
    }

}


// Функция для проверки 0 в a[i][i]
short int Zero_Check_aii(const vector<vector<double>>& a) {

    for (unsigned short i = 0; i < a.size(); i++) {

        if (a[i][i] == 0) {

            return i;

        }
    }

    return -1;
}


// Функция для проверки 0 в a[0][0]
bool Zero_Check_a00(const vector<vector<double>>& a) {

    if (a[0][0] == 0) {

        return 1;

    }

    return 0;
}

// Функция для перестановки строк, при условии, что a[i][i] (На которое мы делим) = 0 
void Swith_Lines_aii(vector<vector<double>>& a, const short int sign) {



}


// Функция для перестановки строк, при условии, что a[0][0] (На которое мы делим) = 0 
void Swith_Lines_a00(vector<vector<double>>& a, bool sign) {


    if (sign == 1) {

        for (unsigned short i = 0; i < a.size(); i++) {

            if (a[i][0] != 0) {

                vector<double> temp(a[0].size());

                temp = a[0];
                a[0] = a[i];
                a[i] = temp;

            }
        }
    }

}

//################################################################################################################## 



//################################################################################################################## 

// Метод Халецкого;
void Method(const vector<vector<double>>& a) {


    // Создание 1Д\2Д матриц для записи B & T; Y матриц, а также для записи результатов (х)
    vector<double> x(a.size());
    vector<double> y(a.size());
    vector<vector<double>> b = a;
    vector<vector<double>> t = a;


    // Обнуляем матрицы B & T;
    Zeroing_2D_Matrix(b); 
    Zeroing_2D_Matrix(t);
    

    // Вычисляем элементы матриц B & T

    // Вычисление b[i][0] & t[0]["j"]
    for (unsigned short i = 0; i < b.size(); i++) {

        b[i][0] = a[i][0];

        if (i >= 1) {

            t[0][i] = a[0][i] / b[0][0];

        }

    }

    // Вычисление [i][k] & t[k]["j"]
    for (unsigned short k = 0; k < a.size(); k++) {

        for (unsigned short i = 0; i < a.size(); i++) {



        }

    }
    

}

//################################################################################################################## 



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

    // Проверка на a[0][0] = 0
    Swith_Lines_a00(mat, Zero_Check_a00(mat)); 

    // Вывод результатов решения
    cout << "\nFinal response matrix";   
    Method(mat);
    
    system("pause"); // Окончание программы
    return 0;
}