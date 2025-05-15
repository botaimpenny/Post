#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
namespace PACK {
class post {
    std::string _name;
    int _index;//Индекс почтового отделения
    int _x;//Координата отделения по х
    int _y;//Координата отделения по у
    std::vector <int> _packs;//Список посылок внутри отделения
public:
    post() = default;
    post(int x, int y, std::vector <int> packs);
    friend std::ostream& operator<<(std::ostream &out, const post &p);
    friend std::istream& operator>>(std::istream &in, post &p);
    void display();
    void delpost();
    void addpost();
    double distance(pack* arr, int count);  // теперь принимает id
    double calculateRemainingTime(pack* arr, int count, int id); // Новая функция для расчета времени
};
std::ostream& operator<<(std::ostream &out, const post &p) {
    out << p._name << " " << p._index << " " << p._x << " " << p._y << " ";
    out << p._packs.size() << " ";
    for (int val : p._packs) {
        out << val << " ";
    }
    return out;
}

std::istream& operator>>(std::istream &in, post &p) {
    p._packs.clear();
    int packs_count;

    in >> p._name >> p._index >> p._x >> p._y >> packs_count;
    for (int i = 0; i < packs_count; ++i) {
        int val;
        in >> val;
        p._packs.push_back(val);
    }
    return in;
}
