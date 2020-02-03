#pragma once
#include "List_two_direction.h"
namespace List_two_dicert {
	template<typename T>
	class list_two_direcktion
	{
		class Element {
		public:
			T data;
			Element* privios;
			Element* next;
			Element(T data);
		};
	public:
		Element* elem;
		list_two_direcktion();
		void Add_to_head(T data);//done
		void Add_to_tail(T data);//done
		void Add_to_position(int position, T data);//done
		void Delete_from_head();//done
		void Delete_from_tail();//done
		void Delete_from_position(int position);//done
		void Delete_all();//done
		int Search(T key);//done
		int Search_and_replace(int position, T key, T keyforreplace);//done
		void Direction_swap();//done
		void Show();//done
	};
}
template<typename T>
List_two_dicert::list_two_direcktion<T>::Element::Element(T data) {
	this->data = data;
	this->next = nullptr;
	this->privios = nullptr;
}
template<typename T>
List_two_dicert::list_two_direcktion<T>::list_two_direcktion() {
	this->elem = nullptr;
}
template<typename T>
void List_two_dicert::list_two_direcktion<T>::Show() {
	if (this->elem != nullptr) {
		Element* temp = this->elem;
		while (temp != nullptr)
		{
			std::cout << temp->data << std::endl;
			temp = temp->next;
		}
	}
}
template<typename T>
void List_two_dicert::list_two_direcktion<T>::Add_to_head(T data) {
	if (this->elem == nullptr) {
		this->elem = new Element(data);
	}
	else
	{
		Element* temp = this->elem;
		temp->privios = new Element(data);
		temp->privios->next = this->elem;
		this->elem = temp->privios;
	}
}
template<typename T>
void List_two_dicert::list_two_direcktion<T>::Add_to_tail(T data) {
	if (this->elem == nullptr) {
		this->elem = new Element(data);
	}
	else
	{
		Element* temp = this->elem;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = new Element(data);
		temp->next->privios = temp;
	}
}
template<typename T>
void List_two_dicert::list_two_direcktion<T>::Add_to_position(int position, T data) {
	if (position == 0) {
		this->Add_to_head(data);
	}
	else
	{
		int place{ 0 };
		Element* temp = this->elem;
		while ((place + 1) < position)
		{
			temp = temp->next;
			place++;
		}
		Element* temp2 = temp;
		temp = temp->next;
		if (temp == nullptr) {
			this->Add_to_tail(data);
		}
		else {
			Element* New_Node = new Element(data);
			New_Node->privios = temp2;
			New_Node->next = temp;
			temp->privios = New_Node;
			temp2->next = New_Node;
		}
	}
}
template<typename T>
void List_two_dicert::list_two_direcktion<T>::Delete_from_head() {
	if (this->elem->next == nullptr) {
		Element* temp = this->elem;
		delete temp;
		temp = nullptr;
		this->elem = temp;
	}
	else {
		Element* temp = this->elem;
		temp = temp->next;
		delete temp->privios;
		this->elem = temp;
	}
}
template<typename T>
void List_two_dicert::list_two_direcktion<T>::Delete_from_tail() {
	if (this->elem->next == nullptr) {
		Element* temp = this->elem;
		delete temp;
		temp = nullptr;
		this->elem = temp;
	}
	else
	{
		Element* temp = this->elem;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp = temp->privios;
		delete temp->next;
		temp->next = nullptr;

	}
}
template<typename T>
void List_two_dicert::list_two_direcktion<T>::Delete_all() {
	while (this->elem != nullptr)
	{
		this->Delete_from_head();
	}
}
template<typename T>
void List_two_dicert::list_two_direcktion<T>::Delete_from_position(int position) {
	if (position == 0) {
		this->Delete_from_head();
	}
	else
	{
		int place{ 0 };
		Element* temp = this->elem;
		while ((place + 1) < position)
		{
			temp = temp->next;
			place++;
		}
		Element* temp2 = temp;
		temp = temp->next->next;
		if (temp == nullptr) {
			this->Delete_from_tail();
		}
		else {
			delete temp2->next;
			temp2->next = temp;
			temp->privios = temp2;
		}
	}
}
template<typename T>
int List_two_dicert::list_two_direcktion<T>::Search(T key) {
	Element* temp = this->elem;
	int posis{ 0 };
	while (temp != nullptr)
	{
		if (temp->data == key) {
			return posis;
		}
		posis++;
		temp = temp->next;
	}
	return -1;
}
template<typename T>
int List_two_dicert::list_two_direcktion<T>::Search_and_replace(int position, T key, T keyforreplace) {
	int how_many_replaced{ 0 };
	int pos{ 0 };
	Element* temp = this->elem;
	while (temp != nullptr)
	{
		if (pos > position) {
			if (temp->data == key)
			{
				temp->data = keyforreplace;
				how_many_replaced++;
			}
		}
		pos++;
		temp = temp->next;
	}
	if (how_many_replaced == 0) {
		return -1;
	}
	else
	{
		return how_many_replaced;
	}
}
template<typename T>
void List_two_dicert::list_two_direcktion<T>::Direction_swap() {
	Element* temp = this->elem;
	Element* newlist;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	newlist = new Element(temp->data);
	this->Delete_from_tail();
	Element* point_to_new_list = newlist;
	while (this->elem != nullptr)
	{
		temp = this->elem;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		point_to_new_list->next = new Element(temp->data);
		point_to_new_list->next->privios = point_to_new_list->next;
		point_to_new_list = point_to_new_list->next;
		this->Delete_from_tail();
	}
	this->elem = newlist;
	newlist = nullptr;
}