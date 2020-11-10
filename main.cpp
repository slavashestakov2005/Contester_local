#include <iostream>
#include <clocale>
#include "comands.h"

using namespace std;

int main(int argc, char* argv[]){
    setlocale (LC_ALL,"rus");
    Commands::init(argv[0]);
    cout << "Добро пожаловать в приложение для запуска контестера!" << endl;
    cout << "Поддерживаемые команды:" << endl;
    cout << "start\t\t- для запуска контестера." << endl;
    cout << "finish\t\t- для выключения контестера." << endl;
    cout << "open\t\t- для открытия web сайта." << endl;
    cout << "exit\t\t- для выхода." << endl;
    cout << "cls\t\t- для очистки вывода." << endl;
    cout << "help\t\t- для вывода этой подсказки." << endl;
    string s;
    do{
        cout << ">>> ";
        if (!getline(cin, s)) cin.clear();
    }while(Commands::run(s));
    return 0;
}
