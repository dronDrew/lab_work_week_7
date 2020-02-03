#pragma once
#include "dependies.h"
namespace Stack {
	template<typename T>
	class Stack {
	protected:
		class Element {
		public:
			T data;
			Element* next;
			Element(T data);//done
		};
		Element* Top;
		int Index;
	public:
		Stack();
		void Add(T data);//done
		void Clear_all();
		void Pop();//done
		T Get_top();//done
	};
}
	template<typename T>
	Stack::Stack<T>::Element::Element(T data) {
		this->data = data;
		this->next = nullptr;
	}
	template<typename T>
	Stack::Stack<T>::Stack() {
		this->Top = nullptr;
		this->Index = 8;
	}
	template<typename T>
	void Stack::Stack<T>::Add(T data) {
		if (this->Index == 8) {
			this->Top = new Element(data);
			this->Index--;
		}
		else
		{
			try
			{
				if (this->Index <= 0) {
					throw Index;
				}
				Element* point = this->Top;
				while (point->next != nullptr)
				{
					point = point->next;
				}
				point->next = new Element(data);
				this->Index--;
			}
			catch (int)
			{
				std::cout << "Stack Overflow\n";
				return;
			}
		}
	}
	template<typename T>
	void Stack::Stack<T>::Pop() {
		try
		{

			if (this->Index >= 8)
			{
				throw this->Index;
			}
			if (this->Top->next == nullptr) {
				Element* point = this->Top;
				delete point;
				point = nullptr;
				this->Top = point;
				this->Index++;
			}
			else
			{
				Element* point = this->Top;
				while (point->next->next != nullptr)
				{
					point = point->next;
				}
				delete point->next;
				point->next = nullptr;
				this->Index++;
			}

		}
		catch (int)
		{
			std::cout << "No Element to deleting in stack\n";
			return;
		}
	}
	template<typename T>
	T Stack::Stack<T> ::Get_top() {
		try
		{
			if (this->Top == nullptr)
			{
				throw 1;
			}
			if (this->Index == 7) {
				return this->Top->data;
			}
			else
			{
				Element* point = this->Top;
				while (point->next != nullptr)
				{
					point = point->next;
				}
				return point->data;
			}

		}
		catch (int)
		{
			std::cout << "your stack is empty\n";
			return 0;
		}

	}
	template<typename T>
	void Stack::Stack<T> ::Clear_all() {
		while (this->Top != nullptr)
		{
			this->Pop();
		}
	}
