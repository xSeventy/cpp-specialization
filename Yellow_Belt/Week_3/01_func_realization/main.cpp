#include "sum_reverse_sort.h"
#include <algorithm> // Для std::sort() и std::reverse()

using namespace std;

// Функция сложения (оставляем без изменений)
int Sum(int x, int y) {
    return x + y;
}

// Оптимизированная функция реверса строки (O(n))
string Reverse(string s) {
    reverse(s.begin(), s.end());  // Используем стандартную функцию C++
    return s;
}

// Оптимизированная сортировка (O(n log n))
void Sort(vector<int>& nums) {
    sort(nums.begin(), nums.end());  // Быстрая сортировка (QuickSort + HeapSort)
}
