#define _USE_MATH_DEFINES
#include "Functii.h"



int main()
{

    setlocale(LC_ALL, "Russian");//подключаем русский язык


    std::string input;//создаем строку для ввода


    std::cout << "Константы\n";
    std::cout << "pi = 3.14....\n";
    std::cout << "e = 2.7....\n";
    std::cout << "----------------\n";
    std::cout << "Возможности:\n";
    std::cout << "sqrt(), sin(), cos(), tan(), ctg(), exp()\n";
    std::cout << "Переменная x (только прописная)\n";
    std::cout << "Целые числа с точкой(не с запятой!)\n";

    getline(std::cin, input);

    if (error(input))//проверка на ошибки со скобками
    {
        std::cout << "Синтаксическая ошибка";
        return 0;
    }
   
    /////
   // int buf1 = input.find('x');//находим иксы...
    int buf1 = std::string::npos;
   
        if (buf1 == std::string::npos)
            buf1 = input.find("(x");
        if (buf1 == std::string::npos)
            buf1 = input.find("-x");
        if (buf1 == std::string::npos)
            buf1 = input.find("+x");
        if (buf1 == std::string::npos)
            buf1 = input.find("*x");
        if (buf1 == std::string::npos)
            buf1 = input.find("/x");
        if (buf1 == std::string::npos)
            buf1 = input.find("x)");
        if (buf1 == std::string::npos)
            buf1 = input.find("x-");
        if (buf1 == std::string::npos)
            buf1 = input.find("x+");
        if (buf1 == std::string::npos)
            buf1 = input.find("x*");
        if (buf1 == std::string::npos)
            buf1 = input.find("x/");
        if (buf1 == std::string::npos)
            buf1 = input.find("^x");
        if (buf1 == std::string::npos)
            buf1 = input.find("x^");
        if (buf1 == std::string::npos)
            buf1 = input.find(" x");
        if (buf1 == std::string::npos)
            buf1 = input.find("x ");
    
    float x;
    if (buf1 != std::string::npos)
    {
        std::cout << "Введите Х\n";
        std::cin >> x;
    }
    /////

    while (buf1 != std::string::npos)//...и меняем их на наше введенное число
    {
        if (buf1 == 0)
            input.replace(buf1, 1, '(' + std::to_string(x) + ')');
        else
            input.replace(buf1+1, 1, '(' + std::to_string(x) + ')');
        
        buf1 = std::string::npos;

        if (buf1 == std::string::npos)
            buf1 = input.find("(x");
        if (buf1 == std::string::npos)
            buf1 = input.find("-x");
        if (buf1 == std::string::npos)
            buf1 = input.find("+x");
        if (buf1 == std::string::npos)
            buf1 = input.find("*x");
        if (buf1 == std::string::npos)
            buf1 = input.find("/x");
        if (buf1 == std::string::npos)
            buf1 = input.find("x)");
        if (buf1 == std::string::npos)
            buf1 = input.find("x-");
        if (buf1 == std::string::npos)
            buf1 = input.find("x+");
        if (buf1 == std::string::npos)
            buf1 = input.find("x*");
        if (buf1 == std::string::npos)
            buf1 = input.find("x/");
        if (buf1 == std::string::npos)
            buf1 = input.find("^x");
        if (buf1 == std::string::npos)
            buf1 = input.find("x^");
        if (buf1 == std::string::npos)
            buf1 = input.find(" x");
        if (buf1 == std::string::npos)
            buf1 = input.find("x ");
    }
    
    
    int buf = input.find("exp");
    while (buf != std::string::npos)
    {
        std::string sub = trigonometry(input, buf);
        float res = counter(sub);
        if (res < 0)
        {
            std::cout << "Синтаксическая ошибка";
            break;
        }
        input.replace(buf, sub.length() + 3, std::to_string(std::exp(res)));
        buf = input.find("exp");
    }
    /////
      buf = input.find("sqrt");
    while (buf != std::string::npos)
    {
        std::string sub = trigonometryforsqrt(input, buf);
        float res = counter(sub);
        if (res < 0)
        {
            std::cout << "Синтаксическая ошибка";
            return 0;
        }
        input.replace(buf, sub.length() + 3, std::to_string(std::sqrt(res)));
        buf = input.find("sqrt");
    }

    //////
    buf = input.find("sin");
    while (buf != std::string::npos)
    {
        std::string sub = trigonometry(input, buf);
        input.replace(buf, sub.length() + 3, '(' + std::to_string(std::sin(counter(sub))) + ')');
        buf = input.find("sin");
    }
    //////
    buf = input.find("tan");
    while (buf != std::string::npos)
    {
        std::string sub = trigonometry(input, buf);
        input.replace(buf, sub.length() + 3, '(' + std::to_string(std::tan(counter(sub))) + ')');
        buf = input.find("tan");
    }
    /////
    buf = input.find("cos");
    while (buf != std::string::npos)
    {
        std::string sub = trigonometry(input, buf);
        input.replace(buf, sub.length() + 3, '(' + std::to_string(std::cos(counter(sub))) + ')');
        buf = input.find("cos");
    }
    /////

    buf = input.find("ctg");
    while (buf != std::string::npos)
    {
        std::string sub = trigonometry(input, buf);
        input.replace(buf, sub.length() + 3, '(' + std::to_string(std::tan(M_PI / 2 - counter(sub))) + ')');
        buf = input.find("ctg");
    }
    /////

  
    std::cout << counter(input);
}
