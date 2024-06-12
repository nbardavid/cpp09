/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmergeme.Class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:09:01 by nbardavi          #+#    #+#             */
/*   Updated: 2024/06/12 15:29:32 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// #ifndef RPM_CLASS_HPP
// # define RPM_CLASS_HPP
//
// #include <iterator>
// #include <string>
// #include <iostream>
// #include <limits>
// #include <utility>
//
// template<typename T>
// void printList(T list){
// 	typename T::const_iterator it;
// 	for (it = list.begin(); it != list.end(); ++it){
// 		std::cout << *it << ", ";
// 	}
// 	std::cout << std::endl;
// }
//
// template<typename Plist>
// void printPair(const Plist& plist) {
// 	std::cout << "===" << std::endl;
//     typename Plist::const_iterator it;
//     for (it = plist.begin(); it != plist.end(); ++it) {
//         std::cout << it->first << ", ";
//     }
// 	std::cout << std::endl;
//     for (it = plist.begin(); it != plist.end(); ++it) {
//         std::cout << it->second << ", ";
//     }
// 	std::cout << std::endl;
// 	std::cout << "===" << std::endl;
// }
// // template <typename T, typename Plist>
// // Plist Rbubble_Sort(Plist plist, size_t end){
// // 	size_t i = 1;
// // 	
// //     typename Plist::iterator it = plist.begin();
// // 	if(end == 2) {
// // 		if (plist[0].first < plist[1].first){
// // 			std::pair<int, int> temp = plist[0];
// // 			plist[0] = plist[1];
// // 			plist[1] = temp;
// // 		}
// // 		return plist;
// // 	}
// // 	else{
// // 		while(i < end){
// // 			if(plist[i - 1].first < plist[i].first){
// // 				std::pair<int, int> temp = plist[i - 1];
// // 				plist[i - 1] = plist[i];
// // 				plist[i] = temp;
// // 			}
// // 			i++;
// // 		}
// // 		return Rbubble_Sort<T, Plist>(plist, end - 1);
// // 	}
// // }
//
// template <typename T, typename Plist>
// Plist Rbubble_Sort(Plist plist, size_t end){
// 	size_t i = 1;
// 	
//     typename Plist::iterator it = plist.begin();
//     typename Plist::iterator it2 = plist.begin();
// 	if(end == 2) {
// 		std::advance(it2, 1);
// 		if (it->first < it2->first){
// 			std::pair<int, int> temp = *it;
// 			*it = *it2;
// 			*it2 = temp;
// 		}
// 		return plist;
// 	}
// 	else{
// 		while(i < end){
// 			std::advance(it2, -1);
// 			if(it2->first < it->first){
// 				std::pair<int, int> temp = *it;
// 				*it = *it2;
// 				*it2 = temp;
// 			}
// 			i++;
// 		}
// 		return Rbubble_Sort<T, Plist>(plist, end - 1);
// 	}
// }
//
// template <typename T, typename Plist>
// T pushFirst(T list, Plist plist){
// 	typename Plist::iterator it;
//
// 	for (it = plist.begin(); it != plist.end(); ++it){
// 		if (it->first != -1){
// 			list.push_back(it->first);
// 		}
// 	}
// 	return list;
// }
//
// template <typename T>
// T insertNumber(T list, int nbr) {
//     int start = 0;
//     int end = list.size() - 1;
//     int mid;
//
//     while (start <= end) {
//         mid = (start + end) / 2;
//
//         if (list[mid] > nbr) {
//             start = mid + 1;
//         } else {
//             end = mid - 1;
//         }
//     }
//
//     list.insert(list.begin() + start, nbr);
// 	return list;
// }
// // template <typename T, typename Plist>
// // T pushSecond(T list, Plist plist){
// // 	size_t i = 0;
// // 	size_t count = 0;
// // 	const std::size_t tab[] = { 1, 3, 4, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763 };
// //
// // 	list.insert(list.begin(), plist[0].second);
// // 	count++;
// //
// // 	while(count < plist.size()){
// // 		size_t j = tab[i];
// // 		while(j > tab[i - 1] || count == 1){
// // 			list = insertNumber<T>(list, plist[j].second);
// // 			j--;
// // 			count++;
// // 		}
// // 		i++;
// // 	}
// // 	return list;
// // }
// template <typename T, typename Plist>
// T pushSecond(T list, Plist plist){
// 	size_t i = 0;
// 	size_t count = 0;
// 	const std::size_t tab[] = { 1, 3, 4, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763 };
//     
// 	typename Plist::iterator it;
//
// 	list.insert(list.begin(), plist.begin()->second);
// 	count++;
//
// 	while(count < plist.size()){
// 		size_t j = tab[i];
// 		while(j > tab[i - 1] || count == 1){
// 			it = plist.begin();
// 			std::advance(it, j);
// 			list = insertNumber<T>(list, it->second);
// 			j--;
// 			count++;
// 		}
// 		i++;
// 	}
// 	return list;
// }
//
// template<typename Plist>
// Plist sortPairs(Plist plist) {
//     typename Plist::iterator it;
//     for (it = plist.begin(); it != plist.end(); ++it) {
//         if (it->second < it->first) {
//             typename Plist::value_type::first_type temp = it->second;
//             it->second = it->first;
//             it->first = temp;
//         }
//     }
//     return plist;
// }
//
// template <typename T, typename Plist>
// T Pmergeme(T list, Plist plist){
// 	typename T::const_iterator it;
//     
// 	size_t null_size_t = std::numeric_limits<size_t>::max();
// 	bool toggle = true;
// 	size_t A = null_size_t;
// 	size_t B = null_size_t;
//
// 	it = list.begin();
// 	while(it != list.end()){
// 		if (toggle){ 
// 			B = *it; 
// 			A = null_size_t;
// 		}
// 		else A = *it;
//
// 		toggle = !toggle;
// 		++it;
//
// 		if (it == list.end() || toggle)
// 			plist.push_back(std::make_pair(A, B));
// 	}
// 	printList(list);
// 	plist = sortPairs<Plist>(plist);
//     plist = Rbubble_Sort<T, Plist>(plist, plist.size());
// 	list.clear();
// 	list = pushFirst<T, Plist>(list, plist);
// 	list = pushSecond<T, Plist>(list, plist);
// 	printPair(plist);
// 	printList(list);
// 	return list;
// }
//
// #endif
#ifndef RPM_CLASS_HPP
#define RPM_CLASS_HPP

#include <iterator>
#include <string>
#include <iostream>
#include <limits>
#include <utility>
#include <vector>
#include <algorithm>

template<typename T>
void printList(const T& list){
    typename T::const_iterator it;
    for (it = list.begin(); it != list.end(); ++it){
        std::cout << *it << ", ";
    }
    std::cout << std::endl;
}

template<typename Plist>
void printPair(const Plist& plist) {
    typename Plist::const_iterator it;
    std::cout << "===" << std::endl;
    for (it = plist.begin(); it != plist.end(); ++it) {
        std::cout << it->first << ", ";
    }
    std::cout << std::endl;
    for (it = plist.begin(); it != plist.end(); ++it) {
        std::cout << it->second << ", ";
    }
    std::cout << std::endl;
    std::cout << "===" << std::endl;
}

template <typename T, typename Plist>
Plist Rbubble_Sort(Plist plist, size_t end){
    if (end <= 1) {
        return plist;
    }

    size_t i;
    typename Plist::iterator it1, it2;
    for (i = 0; i < end - 1; ++i) {
        it1 = plist.begin();
        it2 = plist.begin();
        std::advance(it1, i);
        std::advance(it2, i + 1);
        if (it1->first < it2->first) {
            std::swap(*it1, *it2);
        }
    }

    return Rbubble_Sort<T, Plist>(plist, end - 1);
}

template <typename T, typename Plist>
T pushFirst(T list, const Plist& plist){
    typename Plist::const_iterator it;
    for (it = plist.begin(); it != plist.end(); ++it){
        if (it->first != -1){
            list.push_back(it->first);
        }
    }
    return list;
}

template <typename T>
T insertNumber(T list, int nbr) {
    typename T::iterator it = list.begin();
    typename T::iterator end = list.end();
    while (it != end && *it > nbr) {
        ++it;
    }
    list.insert(it, nbr);
    return list;
}

template <typename T, typename Plist>
T pushSecond(T list, const Plist& plist){
    size_t i = 0;
    size_t count = 0;
    const std::size_t tab[] = { 1, 3, 4, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763 };

    list.insert(list.begin(), plist.begin()->second);
    count++;

    while (count < plist.size()){
        size_t j = tab[i];
        while ((j > tab[i - 1] || count == 1) && count < plist.size()){
            typename Plist::const_iterator it = plist.begin();
            std::advance(it, j);
            list = insertNumber<T>(list, it->second);
            j--;
            count++;
        }
        i++;
    }
    return list;
}

template<typename Plist>
Plist sortPairs(Plist plist) {
    typename Plist::iterator it;
    for (it = plist.begin(); it != plist.end(); ++it) {
        if (it->second < it->first) {
            std::swap(it->first, it->second);
        }
    }
    return plist;
}

template <typename T, typename Plist>
T Pmergeme(T list, Plist plist){
    typename T::const_iterator it;
    bool toggle = true;
    int A = -1;
    int B = -1;

    for (it = list.begin(); it != list.end(); ++it) {
        if (toggle) { 
            B = *it; 
            A = -1;
        } else {
            A = *it;
        }

        toggle = !toggle;

        if (it == list.end() || toggle) {
            plist.push_back(std::make_pair(A, B));
        }
    }

    printList(list);
    plist = sortPairs(plist);
    plist = Rbubble_Sort<T, Plist>(plist, plist.size());
    list.clear();
    list = pushFirst<T, Plist>(list, plist);
    list = pushSecond<T, Plist>(list, plist);
    printPair(plist);
    printList(list);
    return list;
}

#endif
