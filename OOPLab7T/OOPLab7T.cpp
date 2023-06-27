#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

template<typename T>
void swapValues(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
void selectionSort(T arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swapValues(arr[i], arr[minIndex]);
        }
    }
}

template<>
void selectionSort<const char*>(const char* arr[], int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (strcmp(arr[j], arr[minIndex]) < 0)
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swapValues(arr[i], arr[minIndex]);
        }
    }
}

int main()
{
    // Введення даних з клавіатури
    int num1, num2;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    cout << "Initial values: " << num1 << ", " << num2 << endl;
    swapValues(num1, num2);
    cout << "Changed values: " << num1 << ", " << num2 << endl;

    // Введення даних з файлу
    ifstream inputFile("input.txt");
    if (inputFile.is_open())
    {
        int fileNum1, fileNum2;
        inputFile >> fileNum1 >> fileNum2;

        cout << "Initial values from file: " << fileNum1 << ", " << fileNum2 << endl;
        swapValues(fileNum1, fileNum2);
        cout << "Changed values from file: " << fileNum1 << ", " << fileNum2 << endl;

        inputFile.close();
    }
    else
    {
        cout << "Error opening file." << endl;
    }

    // Введення даних за допомогою датчика випадкових чисел
    srand(time(0)); // Ініціалізація генератора випадкових чисел
    int randNum1 = rand();
    int randNum2 = rand();

    cout << "Initial random values: " << randNum1 << ", " << randNum2 << endl;
    swapValues(randNum1, randNum2);
    cout << "Changed random values: " << randNum1 << ", " << randNum2 << endl;

    // Впорядкування масиву типу const char*
    const int charArraySize = 5;
    const char* charArray[charArraySize] = { "orange", "apple", "banana", "grape", "pear" };

    cout << "Initial char array values: ";
    for (int i = 0; i < charArraySize; ++i)
    {
        cout << charArray[i] << " ";
    }
    cout << endl;

    selectionSort(charArray, charArraySize);

    cout << "Sorted char array values: ";
    for (int i = 0; i < charArraySize; ++i)
    {
        cout << charArray[i] << " ";
    }
    cout << endl;

    return 0;
}