#pragma once
#include "Utils.h"

namespace ymstl {
	template <class Ty>
	static void sort(Ty& list) {
		quickSort(list.begin(), list.end());
	}

	template <class Iter>
	static void sort(Iter _first, Iter _last) {
		quickSort(_first, _last);
	}

	template <class Iter, class Comp>
	static void sort(Iter _first, Iter _last, Comp _comp) {
		quickSort(_first, _last, _comp);
	}

	/// 冒泡排序
	/// 是一种稳定的排序算法
	/// 平均时间复杂度为 O(n^2)。
	template <typename Iter, typename Compare>
	static void bubbleSort(Iter _begin, Iter _end, Compare comp) {
		Iter right = _end;
		while (right - _begin > 1) {
			for (Iter i = _begin; i != right; ++i) {
				if (i == _begin)
					continue;
				if (comp(*i, *(i - 1))) {
					swap(*i, *(i - 1));
				}
			}
			right--;
		}
	}

	template <typename Iter>
	static void bubbleSort(Iter _begin, Iter _end) {
		bubbleSort(_begin, _end, less);
	}

	// 选择排序
	// 是不穩定的排序
	// 最优时间复杂度、平均时间复杂度和最坏时间复杂度均为 O(n^2)。
	template <typename Iter, typename Compare>
	static void selectionSort(Iter _begin, Iter _end, Compare comp) {
		Iter it = _begin, sel = _begin;
		while (_begin != _end) {
			while (it != _end) {
				if (comp(*it, *sel)) {
					sel = it;
				}
				++it;
			}
			swap(*_begin, *sel);
			++_begin;
			sel = _begin;
			it = sel;
		}
	}

	template <typename Iter>
	static void selectionSort(Iter _begin, Iter _end) {
		selectionSort(_begin, _end, less);
	}

	// 插入排序
	// 是穩定的排序算法
	// 最坏时间复杂度和平均时间复杂度都为 O(n^2)。
	template <typename Iter, typename Compare>
	static void insertionSort(Iter _begin, Iter _end, Compare comp) {
		Iter sortedIt = _begin;
		Iter cur = _begin + 1;
		while (_end - sortedIt > 1) {
			cur = sortedIt + 1;
			while (comp(*cur, *(cur - 1))) {
				swap(*cur, *(cur - 1));
				cur--;
				if (cur == _begin)break;
			}
			++sortedIt;
		}
	}

	template <typename Iter>
	static void insertionSort(Iter _begin, Iter _end) {
		insertionSort(_begin, _end, less);
	}

	// 快速排序
	// 是一种不稳定的排序算法
	// 最优时间复杂度和平均时间复杂度为 O(n\log n)，最坏时间复杂度为 O(n^2)。
	template <typename Iter, typename Compare>
	static void quickSort(Iter _begin, Iter _end, Compare _comp) {
		if (_end - _begin <= 1) return;
		Iter it = _begin, left = _begin, right = _end - 1;
		while (left != right) {
			++it;
			if (*it == *_begin) {
				continue;
			}
			if (_comp(*it, *_begin)) {
				swap(*left, *it);
				++left;
			}
			else {
				swap(*right, *it);
				--right;
			}
		}
		quickSort(_begin, left);
		quickSort(right, _end);
	}

	template <typename Iter>
	static void quickSort(Iter _begin, Iter _end) {
		quickSort(_begin, _end, less);
	}

};  // namespace ymstl