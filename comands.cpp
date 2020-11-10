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
            cout << "��������� ��� �������" << endl;
            return;
        }
		string command = "cd " + batsdir.string() + " && " + startdir.string();
        system(command.c_str());
        is_started = true;
    }

    void finish(){
        if (!is_started){
            cout << "��������� ��� ��������" << endl;
            return;
        }
        string command = "cd " + batsdir.string() + " && " + finishdir.string();
        system(command.c_str());
        is_started = false;
    }

    void open(){
        if (!is_started){
            cout << "��������� ��������" << endl;
            return;
        }
        string command = "start http://localhost:8080/Contester";
        system(command.c_str());
    }

    bool exit(){
        if (is_started){
            cout << "��������� ���������? (yes / no / cancel)" << endl;
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
        cout << "�������������� �������:" << endl;
        cout << "start\t\t- ��� ������� ����������." << endl;
        cout << "finish\t\t- ��� ���������� ����������." << endl;
        cout << "open\t\t- ��� �������� web �����." << endl;
        cout << "exit\t\t- ��� ������." << endl;
        cout << "cls\t\t- ��� ������� ������." << endl;
        cout << "help\t\t- ��� ������ ���� ���������." << endl;
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
    else if (s != "") cout << "����������� �������." << endl;
    return true;
}
