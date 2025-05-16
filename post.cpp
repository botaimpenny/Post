#include "post.hpp"
#include "package.hpp"
using namespace std;
using namespace PACK;

void post::display() {
    string line;
    ifstream file("posts.txt");
    if (file.is_open()) {
    int n = 1;
        while (getline(file, line)) {
            istringstream iss(line); // Используем istringstream для разбора строки
            int index, x, y;
            vector<int> packs;
            // Читаем индекс, координаты и трек-номера
            iss >> index >> x >> y;
            // Читаем трек-номера посылок
            int trak;
            while (iss >> trak) {
                packs.push_back(trak);
            }
            // Выводим данные с подписями
            cout << n << ". Индекс почтового отделения: " << index << ", "
                 << "Координата X: " << x << ", "
                 << "Координата Y: " << y << ", ";
            for (size_t i = 0; i < packs.size(); i++) {
                cout << packs[i];
                if (i < packs.size() - 1) {
                    cout << ", "; // Добавляем запятую между трек-номерами
                }
            }
            cout << endl; // Переход на новую строку
            n++;
        }
         cout << "---------------" << endl;
        file.close();
    } else {
        cout << "Не удалось открыть файл." << endl;
    }
}

void post::addpost() {
	cout << "Введите название нового почтового отделения: ";
	cin >> _name;
	int index;
	cout << "Введите индекс нового почтового отделения: ";
	cin >> index; // Ввод индекса почтового отделения
	cout << "Введите координату X нового почтового отделения: ";
	cin >> _x; // Ввод координаты X
	cout << "Введите координату Y нового почтового отделения: ";
	cin >> _y; // Ввод координаты Y
	int n;
	cin >> n;
	ofstream file("posts.txt", ios::app);
	if (file.is_open()) {
		file << index << " " << _x << " " << _y << " "; // Запись индекса и координат
		for (int trak : _packs) {
			file << trak << " "; // Запись трек-номеров
		}
		file << endl; // Переход на новую строку
		file.close();
		cout << "Почтовое отделение добавлено успешно." << endl;
	}
	else {
		cout << "Не удалось открыть файл для записи." << endl;
	}
}

double PACK::post::distance(pack* arr, int count){
        ifstream file("packs.txt");
        if (file.is_open()) {
            int x1 = 0;
            int y1 = 0;
            int x2 = 0;
            int y2 = 0;
            string from;
            string to;
            int id;
            double dis;

            cout << "Введите трек номер: ";
            cin >> id;
            for (int i = 0; i < count; i++) {
                if (arr[i].id() == id) {
                    from = arr[i].from();
                    to = arr[i].to();
                }
            }
            file.close();
            ifstream file("posts.txt");
            if (file.is_open()){
                while (file >> _name >> _x >> _y) {
                    if (from == _name){
                        file.close();
                        x1 = _x;
                        y1 = _y;
                    }

                }
            }
            file.close();
            ifstream file1("posts.txt");
            if (file1.is_open()){
                while (file1 >> _name >> _x >> _y) {
                    if (to == _name){
                        file1.close();
                        x2 = _x;
                        y2 = _y;
                    }

                }
            }
            double totalDistance = 0.0;

            dis = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

            return totalDistance;
        }
}

void post::delpost(pack* arr, int count) {
    vector<string> lines;
    string line;

    ifstream in("posts.txt");
    while (getline(in, line)) {
        lines.push_back(line);
    }
    in.close();

    cout << "Список почтовых отделений:" << endl;
    for (size_t i = 0; i < lines.size(); ++i) {
        cout << i + 1 << ") " << lines[i] << endl;
    }

    cout << "Введите номер отделения для удаления: ";
    size_t num;
    cin >> num;

    if (num > 0 && num <= lines.size()) {
        istringstream iss(lines[num - 1]);
        int index, x, y;
        vector<int> packs;
        iss >> index >> x >> y;
        int trak;
        while (iss >> trak) {
            packs.push_back(trak);
        }

        for (int track : packs) {
            for (int i = 0; i < count; i++) {
                if (arr[i].id() == track) {
                    arr[i].setTo(arr[i].from());
                    cout << "Посылка с трек-номером " << track
                        << " отправлена обратно в отделение " << arr[i].from() << endl;
                }
            }
        }

        lines.erase(lines.begin() + num - 1);

        ofstream out("posts.txt");
        for (const auto& l : lines) {
            out << l << endl;
        }
        out.close();

        save(arr, count);
        cout << "Отделение успешно удалено. Все посылки отправлены обратно." << endl;
    }
    else {
        cout << "Неверный номер отделения." << endl;
    }
}
