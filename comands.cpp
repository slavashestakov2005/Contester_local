#include <iostream>
#include <clocale>
#include <fstream>
#include <filesystem>
#include "comands.h"

using namespace std;
namespace fs = std::filesystem;

namespace Commands{
    fs::path workdir, batsdir, startdir, finishdir;
    bool is_started = false;

    void start(){
        if (is_started){
            cout << "Контестер уже запущен" << endl;
            return;
        }
		string command = "cd " + batsdir.string() + " && " + startdir.string();
        system(command.c_str());
        is_started = true;
    }

    void finish(){
        if (!is_started){
            cout << "Контестер уже выключен" << endl;
            return;
        }
        string command = "cd " + batsdir.string() + " && " + finishdir.string();
        system(command.c_str());
        is_started = false;
    }

    void open(){
        if (!is_started){
            cout << "Контестер выключен" << endl;
            return;
        }
        string command = "start http://localhost:8080/Contester";
        system(command.c_str());
    }

    bool exit(){
        if (is_started){
            cout << "Выключить контестер? (yes / no / cancel)" << endl;
            string s;
            while(true){
                cout << "exit >> ";
                if (!getline(cin, s)){
                    cin.clear();
                    continue;
                }
                if (s == "yes"){
                    finish();
                    return  true;
                }
                if (s == "no"){
                    return true;
                }
                if (s == "cancel"){
                    return false;
                }
            }
        }
        return true;
    }

    void cls(){
        system("cls");
    }

    void help(){
        cout << "Поддерживаемые команды:" << endl;
        cout << "start\t\t- для запуска контестера." << endl;
        cout << "finish\t\t- для выключения контестера." << endl;
        cout << "open\t\t- для открытия web сайта." << endl;
        cout << "exit\t\t- для выхода." << endl;
        cout << "cls\t\t- для очистки вывода." << endl;
        cout << "help\t\t- для вывода этой подсказки." << endl;
    }
}

void Commands::init(char* program){
    workdir = fs::path(program).parent_path();
	batsdir = workdir / "apache-tomcat-9.0.27" / "bin";
    startdir = batsdir / "startup.bat";
    finishdir = batsdir / "shutdown.bat";
}

bool Commands::run(string s){
    if (s == "start") start();
    else if (s == "finish") finish();
    else if (s == "open") open();
    else if (s == "exit") return !exit();
    else if (s == "cls") cls();
    else if (s == "help") help();
    else if (s != "") cout << "Неизвестная команда." << endl;
    return true;
}
