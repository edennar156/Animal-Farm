//
// Created by ise on 1/10/22.
//
#include <exception>
#ifndef FINALPROJECT_ERROR_H
#define FINALPROJECT_ERROR_H
using namespace std;
class CowException:public std::exception{
    const char* what() const noexcept override{return "Insert valid number of cow farms";

    };
};
class SheepException:public std::exception{
    const char* what() const noexcept override{return "Insert valid number of sheep farms";

    };
};
class ChickenException:public std::exception{
    const char* what() const noexcept override{return "Insert valid number of chicken farms";

    };
};
#endif //FINALPROJECT_ERROR_H
