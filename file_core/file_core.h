#ifndef FILE_CORE_H
#define FILE_CORE_H

#include <cstring>
#include <fstream>

using namespace std;

class File {
protected:
    fstream file;
    char *_name = nullptr;
public:
    File(const char *name) {
        if(name != nullptr) {
            _name = new char[strlen(name) + 1];
            strcpy(_name, name);
            file.open(_name);
        }
    }
    virtual ~File() {
        if(file.is_open()) {
            file.close();
        }
    }

    virtual int updateFName(const char* name) = 0;
    virtual int openFile(ios_base::openmode mode, const char* name = nullptr) = 0;
    virtual int closeFile() = 0;
    virtual void writeFile(const char* data) = 0;
    virtual string readFile() = 0;

};

class FileSystem : public File {
public:
    explicit FileSystem(const char *name): File(name) {}

    int updateFName(const char *name) override {
        if(name != nullptr) {
            try {
                _name = new char[strlen(name) + 1];
                strcpy(_name, name);
                file.open(_name);
            }catch (exception &e) {
                cerr << e.what() << endl;
            }
        }
        return file.is_open();
    }
    int openFile(const ios_base::openmode mode, const char* name = nullptr) override {
        if(!file.is_open()) {
            if(name == nullptr) {
                try {
                    file.open(_name, mode);
                } catch (exception &e) {
                    cout << e.what() << endl;
                }
            } else {
                return updateFName(name);
            }
        }
        return file.is_open();
    }
    int closeFile() override {
        if(file.is_open()) {
            file.close();
        }
        return !file.is_open();
    }
    void writeFile(const char* data) override {
        if(!file.is_open()) {
            try {
                file.open(_name, ios_base::app);
            } catch (exception &e) {
                cout << e.what() << endl;
            }
        }
        file.write(data, strlen(data));
    }
    string readFile() override {
        if(!file.is_open()) {
            try {
                file.open(_name, ios_base::in);
            }catch (exception &e) {
                cout << e.what() << endl;
            }
        }
        string data;
        string line;
        while(std::getline(file, line)) {
            data += line + "\n";
        }
        return data;
    }
};

#endif //FILE_CORE_H
