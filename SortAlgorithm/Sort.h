
namespace ymstl {
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

/// @brief 冒泡排序
/// @tparam Iter
/// @tparam Compare
/// @param _begin
/// @param _end
/// @param comp
template <typename Iter, typename Compare>
void bubbleSort(Iter _begin, Iter _end, Compare comp) {
    Iter right = _end;
    while (right - _begin > 1) {
        for (Iter i = _begin; i != right; i++) {
            if (i == _begin)
                continue;
            if (!comp(*i, *(i - 1))) {
                swap(*i, *(i - 1));
            }
        }
        right--;
    }
}

template <typename Iter>
void bubbleSort(Iter _begin, Iter _end) {
    Iter right = _end;
    while (right - _begin > 1) {
        for (Iter i = _begin; i != right; i++) {
            if (i == _begin)
                continue;
            if (*i < *(i - 1)) {
                swap(*i, *(i - 1));
            }
        }
        right--;
    }
}

};  // namespace ymstl