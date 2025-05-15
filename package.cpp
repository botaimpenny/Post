#include "post.hpp"
#include "package.hpp"
using namespace std;
using namespace PACK;

void give(pack* arr, int* count){
	int id;
	string nameTest;
	string name;
	cout << "Введите трек номер: ";
	cin >> id;
	for (int i = 0; i < *count; i++) {
    		if (arr[i].id() == id) {
        		nameTest = arr[i].getname();
    		}
	}
	cout << "Введите имя получателя: " << endl;
	cin >> name;
	if(name == nameTest){
    		cout << "Поссылка получена!" << endl;
    		int index = -1;
    		for (int i = 0; i < *count; i++) {
        		if (arr[i].id() == id) {
            			index = i;
           			break;
        		}
    		}

    		if (index == -1) {
        		cout << "Такого трек номера не существует " << endl;
        		return;
    		}

    		for (int i = index; i < *count - 1; i++) {
        		arr[i] = arr[i + 1];
    		}
    		(*count)--;
    		cout << "Посылка удалена." << endl;
	}
}

void PACK::trackPackage(pack* arr, int count, post& post) {
	int id;
	cout << "Введите трек номер посылки для отслеживания: ";
	cin >> id;
	// Найти посылку
	pack* pkg = nullptr;
	for (int i = 0; i < count; i++) {
		if (arr[i].id() == id) {
	   		 pkg = &arr[i];
	    		break;
		}
	}
	if (pkg == nullptr) {
		cout << "Посылка с таким трек номером не найдена." << endl;
		return;
	}
	// Получить координаты начальной и конечной точек
	double distanceToDestination = post.distance(arr, count); // Убедитесь, что distance правильно вызывается
	double timeRemaining = distanceToDestination; // Поскольку скорость равна 1 единице на единицу времени
	cout << "Время до пункта назначения: " << timeRemaining << " единиц времени." << endl;
	// Симуляция прохождения времени
	while (timeRemaining > 0) {
		cout << "Осталось времени: " << timeRemaining << " единиц времени." << endl;
		cout << "Нажмите Enter для прокрутки времени на 1 единицу...";
		cin.ignore();
		cin.get(); // Ожидание нажатия клавиши Enter
		timeRemaining -= 1; // Уменьшение времени на 1 единицу
	}
	cout << "Посылка достигла пункта назначения!" << endl;
}
void PACK::advanceTime(pack* arr, int count) {    
	for (int i = 0; i < count; i++) {
		arr[i].advanceDistance(); // Увеличиваем пройденное расстояние    
	}
	cout << "Время прокручено на 1 единицу." << endl;
}
