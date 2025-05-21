#include <iostream>

class Singleton {
private:
    // Приватный конструктор
    Singleton() {
        std::cout << "Singleton создан\n";
    }

    // Удаляем копирование и присваивание
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

public:
    // Глобальная точка доступа
    static Singleton& getInstance() {
        static Singleton instance;  // Гарантированно инициализируется один раз (C++11+)
        return instance;
    }

    void doSomething() {
        std::cout << "Метод Singleton\n";
    }
};

int main() {
    Singleton& s1 = Singleton::getInstance();
    Singleton& s2 = Singleton::getInstance();

    s1.doSomething();

    // Проверка: это один и тот же объект
    std::cout << std::boolalpha << (&s1 == &s2) << std::endl; // true

    return 0;
}
