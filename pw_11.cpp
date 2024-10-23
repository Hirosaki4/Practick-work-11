#include <iostream>
#include<Windows.h>
using namespace std;


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    //Завдання 1
    /*
    // Динамічне виділення пам'яті для змінної типу int
    int* number = new int;

    // Введення значення від користувача
    cout << "Введіть число: ";
    cin >> *number;

    // Додавання до числа 10 і виведення результату
    *number += 10;
    cout << "Число після додавання 10: " << *number << endl;

    // Звільнення пам'яті
    delete number;

    return 0;
}  */
    //Завдання 2
    /*
        int numStudents, numSubjects;

        // Введення кількості студентів і предметів
        cout << "Введіть кількість студентів: ";
        cin >> numStudents;

        cout << "Введіть кількість предметів: ";
        cin >> numSubjects;

        // Динамічне виділення пам'яті для зберігання оцінок
        int* grades = new int[numStudents * numSubjects];

        // Введення оцінок для кожного студента
        for (int i = 0; i < numStudents; i++) {
            cout << "Введіть оцінки для студента " << i + 1 << ": " << endl;
            for (int j = 0; j < numSubjects; j++) {
                cout << "Оцінка за предмет " << j + 1 << ": ";
                cin >> grades[i * numSubjects + j];
            }
        }

        // Обчислення та виведення середньої оцінки для кожного студента
        for (int i = 0; i < numStudents; i++) {
            int sum = 0;
            for (int j = 0; j < numSubjects; j++) {
                sum += grades[i * numSubjects + j];
            }
            cout << "Середня оцінка студента " << i + 1 << ": " << sum / numSubjects << endl;
        }

        // Звільнення динамічної пам'яті
        delete[] grades;

        return 0;
    }
    */
    //Завдання 3
    /*
        int numSeats;

        // Введення кількості місць в автобусі
        cout << "Введіть кількість місць в автобусі: ";
        cin >> numSeats;

        // Динамічне виділення пам'яті для масиву місць
        bool* seats = new bool[numSeats]; // true - місце зайняте, false - місце вільне

        // Ініціалізація всіх місць як вільних
        for (int i = 0; i < numSeats; i++) {
            seats[i] = false;
        }

        int option, seatNumber;

        do {
            // Виведення стану всіх місць
            cout << "Стан місць (0 - вільно, 1 - зайнято): " << endl;
            for (int i = 0; i < numSeats; i++) {
                cout << "Місце " << i + 1 << ": " << seats[i] << endl;
            }

            // Меню для користувача
            cout << "\nОберіть дію:\n";
            cout << "1 - Бронювати місце\n";
            cout << "2 - Відмінити бронювання місця\n";
            cout << "0 - Вийти\n";
            cout << "Ваш вибір: ";
            cin >> option;

            // Бронювання місця
            if (option == 1) {
                cout << "Введіть номер місця для бронювання (1 - " << numSeats << "): ";
                cin >> seatNumber;
                if (seatNumber < 1 || seatNumber > numSeats) {
                    cout << "Невірний номер місця!" << endl;
                }
                else if (seats[seatNumber - 1]) {
                    cout << "Місце вже зайняте!" << endl;
                }
                else {
                    seats[seatNumber - 1] = true;
                    cout << "Місце " << seatNumber << " заброньовано." << endl;
                }
            }
            // Відміна бронювання місця
            else if (option == 2) {
                cout << "Введіть номер місця для відміни бронювання (1 - " << numSeats << "): ";
                cin >> seatNumber;
                if (seatNumber < 1 || seatNumber > numSeats) {
                    cout << "Невірний номер місця!" << endl;
                }
                else if (!seats[seatNumber - 1]) {
                    cout << "Місце вже вільне!" << endl;
                }
                else {
                    seats[seatNumber - 1] = false;
                    cout << "Бронювання місця " << seatNumber << " скасовано." << endl;
                }
            }
        } while (option != 0);

        // Звільнення динамічної пам'яті
        delete[] seats;

        return 0;
    }
    */
     //Завдання додаткове
     /*#include <iostream>
#include <string>
using namespace std;

// Структура для зберігання інформації про товар
struct Product {
    string name;
    int quantity;
    double price;
};

// Функція для виведення списку товарів
void displayInventory(Product* inventory, int numProducts) {
    cout << "\nІнвентар магазину:\n";
    for (int i = 0; i < numProducts; i++) {
        cout << "Товар " << i + 1 << ": " << inventory[i].name 
             << ", Кількість: " << inventory[i].quantity 
             << ", Ціна: " << inventory[i].price << endl;
    }
}

// Функція для обчислення загальної вартості всіх товарів
double calculateTotalValue(Product* inventory, int numProducts) {
    double totalValue = 0;
    for (int i = 0; i < numProducts; i++) {
        totalValue += inventory[i].quantity * inventory[i].price;
    }
    return totalValue;
}

// Основна програма
int main() {
    int numProducts;

    // Введення кількості товарів
    cout << "Введіть кількість товарів: ";
    cin >> numProducts;

    // Динамічне виділення пам'яті для масиву товарів
    Product* inventory = new Product[numProducts];

    // Введення даних про кожен товар
    for (int i = 0; i < numProducts; i++) {
        cout << "\nВведіть дані про товар " << i + 1 << ":\n";
        cout << "Назва: ";
        cin >> inventory[i].name;
        cout << "Кількість: ";
        cin >> inventory[i].quantity;
        cout << "Ціна: ";
        cin >> inventory[i].price;
    }

    int option;
    do {
        // Виведення меню для користувача
        cout << "\nОберіть дію:\n";
        cout << "1 - Вивести інвентар\n";
        cout << "2 - Змінити кількість товару\n";
        cout << "3 - Обчислити загальну вартість інвентарю\n";
        cout << "0 - Вийти\n";
        cout << "Ваш вибір: ";
        cin >> option;

        // Виведення інвентарю
        if (option == 1) {
            displayInventory(inventory, numProducts);
        }
        // Зміна кількості товару
        else if (option == 2) {
            int productIndex, newQuantity;
            cout << "Введіть номер товару (1 - " << numProducts << "): ";
            cin >> productIndex;
            if (productIndex < 1 || productIndex > numProducts) {
                cout << "Невірний номер товару!" << endl;
            } else {
                cout << "Введіть нову кількість для товару " << productIndex << ": ";
                cin >> newQuantity;
                inventory[productIndex - 1].quantity = newQuantity;
                cout << "Кількість оновлено." << endl;
            }
        }
        // Обчислення загальної вартості інвентарю
        else if (option == 3) {
            double totalValue = calculateTotalValue(inventory, numProducts);
            cout << "Загальна вартість інвентарю: " << totalValue << " грн" << endl;
        }
    } while (option != 0);

    // Звільнення динамічної пам'яті
    delete[] inventory;

    return 0;
}
*/

