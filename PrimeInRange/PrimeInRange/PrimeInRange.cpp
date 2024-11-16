#include <iostream>

const int N = 1000;
int ray[N - 1];

void print_ray(int ray[]) {
    std::cout << "[ ";
    for (int i = 0; i < N; i++) {
        std::cout << ray[i] << ", ";
    }
    std::cout << ']';
}

void print_ray_not_zero(int ray[]) {
    std::cout << "[ ";
    for (int i = 0; i < N; i++) {
        if (ray[i] != 0){
            std::cout << ray[i] << ", ";
        }
    }
    std::cout << ']';
}


void _fill_array() {
    for (int i = 0; i< N-1; i++) {
        ray[i] = i + 2;
    }
}

void _go_through_number_id(int nombr_id) {
    if (ray[nombr_id] != 0)
    {
        for (int i = nombr_id + ray[nombr_id]; i < N - 1; i += ray[nombr_id]) {
            ray[i] = 0;
        }
    }
}

void _make_array() {
    _fill_array();
    for (int i = 0; i < 50; i++) {
        _go_through_number_id(i);
    }
}


bool is_prime(int nom) {
    _make_array();
    if (ray[nom - 2] != 0) {
        return true;
    }
    return false;
}
int main()
{
    int nom;
    std::cout << "\033[33m" << "Enter num in range of {2," << N << "} : ";
    std::cin >> nom;
    int color = (is_prime(nom) ? 32 : 31);
    std::cout << "\033[" << color << "m" << "Is prime: " << is_prime(nom) << "\033[0m" << std::endl;

}