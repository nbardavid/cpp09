/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmergeme.Class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbardavi <nbabardavid@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 11:09:01 by nbardavi          #+#    #+#             */
/*   Updated: 2024/06/11 16:22:33 by nbardavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef RPM_CLASS_HPP
# define RPM_CLASS_HPP

#include <string>
#include <iostream>
#include <limits>
#include <utility>

template<typename T>
void printList(T list){
	typename T::const_iterator it;
	for (it = list.begin(); it != list.end(); ++it){
		std::cout << *it << ", ";
	}
	std::cout << std::endl;
}

template<typename Plist>
void printPair(const Plist& plist) {
	std::cout << "===" << std::endl;
    typename Plist::const_iterator it;
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
	size_t i = 1;

	if(end == 2) {
		if (plist[0].first < plist[1].first){
			std::pair<int, int> temp = plist[0];
			plist[0] = plist[1];
			plist[1] = temp;
		}
		return plist;
	}
	else{
		while(i < end){
			if(plist[i - 1].first < plist[i].first){
				std::pair<int, int> temp = plist[i - 1];
				plist[i - 1] = plist[i];
				plist[i] = temp;
			}
			i++;
		}
		return Rbubble_Sort<T, Plist>(plist, end - 1);
	}
}
template <typename T, typename Plist>
T pushFirst(T list, Plist plist){
	for (size_t i = 0; i < plist.size(); ++i){
		if (plist[i].first != -1){
			list.push_back(plist[i].first);
		}
	}
	return list;
}

template <typename T, typename Plist>
T pushSecond(T list, Plist plist){
	size_t j1 = 0;
	size_t j2 = 1;
	size_t j = 1;
	size_t count = 0;

	//push le premier car tj supp
	while(count < plist.size()){
		while(j > j2){
			//condition de l'autre
		}
	}
	return list;
}

template <typename T, typename Plist>
T Pmergeme(T list, Plist plist){
	typename T::const_iterator it;
    
	size_t null_size_t = std::numeric_limits<size_t>::max();
	bool toggle = true;
	size_t A = null_size_t;
	size_t B = null_size_t;

	it = list.begin();
	while(it != list.end()){
		if (toggle){ 
			B = *it; 
			A = null_size_t;
		}
		else A = *it;

		toggle = !toggle;
		++it;

		if (it == list.end() || toggle)
			plist.push_back(std::make_pair(A, B));
	}
	printList(list);
	// printPair(plist);
    plist = Rbubble_Sort<T, Plist>(plist, plist.size());
	list.clear();
	list = pushFirst<T, Plist>(list, plist);
	// list = pushSecond<T, Plist>(list, plist);
	printPair(plist);
	printList(list);
	return list;
}

#endif
