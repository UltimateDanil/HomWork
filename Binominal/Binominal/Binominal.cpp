#include <iostream>

int fact(int nom) { // Функция возвращающая факториал
    if (nom == 0) {
        return 1;
    }
    else {
        return nom * fact(nom - 1);
    }
}

int get_ways(int elems, int group) { // Функция возвращающая количество возможных способов выбора элементов(elem) aka k из группы (group) aka n
    return fact(group) / (fact(elems)*fact(group - elems));
}

int main()
{ // Красивый ввод\вывод данных
  // Для вычисления используются int, так что легко выйти за предел размера, чинить лень
    int elems;
    int group;

    std::cout << "Enter amount of elements chosen: ";
    std::cin >> elems;

    std::cout << "Enter the size of the chosen group: ";
    std::cin >> group;

    std::cout << "There is " << "\033[33m" << get_ways(elems, group) << "\033[0m" << " ways of choosing given amount of elements from group of given size";
    std::cin >> elems;
}

