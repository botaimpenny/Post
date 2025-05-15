#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
namespace PACK {
class post {
    std::string _name;
    int _index//Индекс почтового отделения
    int _x;//Координата отделения по х
    int _y;//Координата отделения по у
    std::vector <int> _packs;//Список посылок внутри отделения
public:
    post() = default;
    post(int x, int y, std::vector <int> packs);
    friend std::ostream& operator << (std::ostream & out, post& p);
    friend std::istream& operator >> (std::istream & in, post& p);
    void display();
    void delpost();
    void addpost();
    double distance(pack* arr, int count);  // теперь принимает id
    double calculateRemainingTime(pack* arr, int count, int id); // Новая функция для расчета времени
}
std::ostream& operator << (std::ostream & out, const pack& p);
std::istream& operator >> (std::istream & in, pack& p);
