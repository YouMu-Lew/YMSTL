
#pragma once
#include "Utils.h"

namespace ymstl {
	template <class Ty>
	const static void sort(Ty& list) {
		bubbleSort(list.begin(), list.end());
	}

	template <class Iter>
	const static void sort(Iter _first, Iter _last) {
		bubbleSort(_first, _last);
	}

	template <class Iter, class Comp>
	const static void sort(Iter _first, Iter _last, Comp _comp) {
		bubbleSort(_first, _last, _comp);
	}

	/// @brief 冒泡排序
	/// @tparam Iter
	/// @tparam Compare
	/// @param _begin begin iterator
	/// @param _end end iterator
	/// @param comp comp algotithm
	template <typename Iter, typename Compare>
	const static void bubbleSort(Iter _begin, Iter _end, Compare comp) {
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
	const static void bubbleSort(Iter _begin, Iter _end) {
		bubbleSort(_begin, _end, less);
	}

	/// <summary>
	/// 选择排序
	/// </summary>
	/// <typeparam name="Iter"></typeparam>
	/// <typeparam name="Compare"></typeparam>
	template <typename Iter, typename Compare>
	const static void selectionSort(Iter _begin, Iter _end, Compare comp) {
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
	const static void selectionSort(Iter _begin, Iter _end) {
		selectionSort(_begin, _end, less);
	}

	/// <summary>
	/// 插入排序
	/// </summary>
	/// <typeparam name="Iter"></typeparam>
	/// <typeparam name="Compare"></typeparam>
	/// <param name="_begin"></param>
	/// <param name="_end"></param>
	/// <param name="comp"></param>
	template <typename Iter, typename Compare>
	const static void insertionSort(Iter _begin, Iter _end, Compare comp) {
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
	const static void insertionSort(Iter _begin, Iter _end) {
		insertionSort(_begin, _end, less);
	}

	template <typename Iter, typename Compare>
	const static void quickSort(Iter _begin, Iter _end, Compare _comp) {
		if (_end - _begin == 1) return;
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
	const static void quickSort(Iter _begin, Iter _end) {
		quickSort(_begin, _end, less);
	}

};  // namespace ymstl