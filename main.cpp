#include "package.hpp"
#include "post.cpp"
using namespace std;
using namespace PACK;
int main() {
    post post;
    pack* arr = nullptr;
    int count = 0;
    int a;
    do {
        cout << "1. Отправить посылку\n";
        cout << "2. Добавить отделение\n";
        cout << "3. Удалить отделение\n";
        cout << "4. Узнать информацию о отделении\n";
        cout << "5. Отследить посылку по трек номеру\n";
        cout << "6. Выдать посылку\n";
        cout << "7.Пропуск времени \n";
        cout << "0. Выйти\n";
        cin >> a;
        switch (a) {
            case 1:
                send(arr, count); // Функция отправки посылки (должна быть определена)
                break;
            case 2:
                post.addpost();
                break;
            case 3:
                post.delpost();
                break;
            case 4:
                post.display();
                break;
            case 5:
                trackPackage(arr, count); // Функция отслеживания посылки (должна быть определена)
                break;
            case 6:
                give(arr, count); // Функция выдачи посылки (должна быть определена)
                break;
            case 7: 
                advanceTime(arr, count);
                break;
            case 0:
                cout << "Выход из программы." << endl;
                save(arr, count);
                post.savePosts(); // Предполагаемый метод сохранения отделений
                delete[] arr;
                break;
            default:
                cout << "Неверный ввод. Пожалуйста, попробуйте снова." << endl;
        }
    } while (a != 0);
    return 0;
}
