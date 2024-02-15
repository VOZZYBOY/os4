#include <iostream>
#include <dlfcn.h>

int main(){
    std::cout << "'0' - переключение реализации контрактов (по умолчанию 1 реализация). " << "\n"
    << "'1' - вызов функции подсчёта НОД для двух натуральных чисел." << "\n"
    << "'2' - вызов функции рассчета значения числа Пи при заданной длине ряда (K)." << "\n"
    << "'3' - окончание работы программы." << "\n" << "\n"
    << "Введите номер команды: ";

    int num;
    std::cin >> num;

    int lib = 1;
    auto swi = dlopen("./liblib1.so", RTLD_LAZY);

    char* error;
    error = dlerror();
    if (error != 0){
        std::cout << error << "\n";
        return -1;
    }

    int (*GCF)(int, int);
    GCF = reinterpret_cast<decltype(GCF)>(dlsym(swi, "GCF"));
    error = dlerror();
    if (error != 0){
        std::cout << error << "\n";
        return -1;
    }

    float (*Pi)(int);
    Pi = reinterpret_cast<decltype(Pi)>(dlsym(swi, "Pi"));
    error = dlerror();
    if (error != 0){
        std::cout << error << "\n";
        return -1;
    }

    while (num != 3){
        switch (num){

            case 0:
                dlclose(swi);
                error = dlerror();
                if (error != 0){
                    std::cout << error << "\n";
                    return -1;
                }

                switch (lib){
                    
                    case 1:
                        std::cout << "Переключено на реализацию 2. " << "\n" << "\n";
                        lib = 2;
                        swi = dlopen("./liblib2.so", RTLD_LAZY);
                        break;

                    case 2:
                        std::cout << "Переключено на реализацию 1. " << "\n" << "\n";
                        lib = 1;
                        swi = dlopen("./liblib1.so", RTLD_LAZY);
                        break;
                }

                char* error;
                error = dlerror();
                if (error != 0){
                    std::cout << error << "\n";
                    return -1;
                }

                GCF = reinterpret_cast<decltype(GCF)>(dlsym(swi, "GCF"));
                error = dlerror();
                if (error != 0){
                    std::cout << error << "\n";
                    return -1;
                }

                Pi = reinterpret_cast<decltype(Pi)>(dlsym(swi, "Pi"));
                error = dlerror();
                if (error != 0){
                    std::cout << error << "\n";
                    return -1;
                }

                std::cout << "Введите номер команды: ";
                std::cin >> num;
                break;

            case 1:
                int A, B;
                std::cout << "Введите два натуральных числа: ";
                std::cin >> A >> B;

                std::cout << "НОД(" << A << "," << B << ") = " << GCF(A, B) << "\n" << "\n"
                << "Введите номер команды: ";
                std::cin >> num;
                break;

            case 2:
                int K;
                std::cout << "Введите длину ряда K: ";
                std::cin >> K;

                std::cout << "Число Пи при K = " << K << ": " << Pi(K) << "\n" << "\n"
                << "Введите номер команды: ";

                std::cin >> num;
                break;

            default:
                std::cout << "Команды с таким номером нет." << "\n";
                return -1;
        }
    }

    dlclose(swi);
    error = dlerror();
    if (error != 0){
        std::cout << error << "\n";
        return -1;
    }
    return 0;
}