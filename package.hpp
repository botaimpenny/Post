#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
using namespace PACK{

class pack {
    std::string _sendname;//имя отправителя
    std::string _getname;//имя получателя
    std::string _from; //откуда отправляется
    std::string _to;//куда отправляется
    int _weight;//вес посылки
    int _id; //трек номер
    int _distanceCovered;

public:
    pack() : _distanceCovered(0) {} // Инициализация пройденного расстояния
    pack(std::string sendname, std::string getname, std::string from, std::string to, int weight, int id);
    std::string sendname();
    std::string getname();
    std::string from();
    std::string to();
    int weight();
    int id();
    int distanceCovered() { return _distanceCovered; } // Метод для получения пройденного расстояния
    void advanceDistance() { _distanceCovered++; } // Метод для увеличения пройденного расстояния
    friend std::ostream& operator << (std::ostream & out, const pack& p);
    friend std::istream& operator >> (std::istream & in, pack& p);
    void setGetname(const std::string& getname) { _getname = getname; }
    void setSendname(const std::string& sendname) { _sendname = sendname; }
    void setFrom(const std::string& from) { _from = from; }
    void setTo(const std::string& to) { _to = to; }
    void setWeight (int weight) { _weight = weight; }
    void setId(int id) { _id = id; }
};
std::ostream& operator << (std::ostream & out, const pack& p);
std::istream& operator >> (std::istream & in, pack& p);
pack *load(int &count);
pack *create(int &count);
void save(pack *arr, int count);
void add(pack **arr, int *count);
void del(pack *arr, int *count);
void edit(pack *arr, int count);
void search(pack *arr, int count);
void showList(pack *arr, int count);
void give(pack* arr, int* count);
void trackPackage(pack* arr, int count, post& post); // Объявление функции отслеживания
void advanceTime(pack* arr, int count); // Объявление функции прокрутки времени

}
