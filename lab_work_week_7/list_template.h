#pragma once
#include"dependies.h"
namespace List {
    template<typename T>
    class List {
        class element {
        public:
            T data;
            element* next_elem;
            element(T data);
        };
    public:
        List();
        element* list_elem;
        void Add_To_Tail(T data);//done
        void Add_To_Head(T data);//done
        void Add_in_position(int position, T data);//done
        void Delete_from_head();//done
        void Delete_from_tail();//done
        void Delete_from_position(int position);//done
        void Delete_all();//done
        void Show();//done
        int Search(T key);//done
        int Search_and_replace(int position, T key);//done
        void direct_change();//done
    };
}
template<typename T>
List::List<T>::element::element(T data) {
    this->data = data;
}
template<typename T>
List::List<T>::List() {
    this->list_elem = nullptr;
}
template<typename T>
void List::List<T>::Add_To_Head(T data) {
    if (this->list_elem == nullptr) {
        this->list_elem = new element(data);
    }
    else {
        element* temp = new element(data);
        temp->next_elem = this->list_elem;
        this->list_elem = temp;
    }
}
template<typename T>
void List::List<T>::Add_To_Tail(T data) {
    if (this->list_elem == nullptr) {
        this->list_elem = new element(data);
    }
    else {
        element* temp = this->list_elem;
        while (temp->next_elem != nullptr) {
            temp = temp->next_elem;
        }
        temp->next_elem = new element(data);
    }
}
template<typename T>
void List::List<T>::Show() {
    if (this->list_elem == nullptr) {
        std::cout << "No in line element\n";
    }
    else {
        element* temp = this->list_elem;
        while (temp != nullptr) {
            std::cout << temp->data << std::endl;
            temp = temp->next_elem;
        }
    }
}
template<typename T>
int List::List<T>::Search(T key) {
    int res{ 0 };
    element* temp = this->list_elem;
    while (temp != nullptr) {
        if (temp->data == key) {
            return res;
        }
        res++;
        temp = temp->next_elem;
    }
    return -1;
}
template<typename T>
int List::List<T>::Search_and_replace(int position, T key) {
    int res{ 0 };
    int iter{ 0 };
    element* temp = this->list_elem;
    while (temp != nullptr) {
        if (iter == position) {
            temp->data = key;
            res++;
        }
        iter++;
        temp = temp->next_elem;
    }
    if (res == 0) {
        return -1;
    }
    else {
        return res;
    }
}
template<typename T>
void List::List<T>::Add_in_position(int position, T data) {
    int iter{ 0 };
    int quont{ 0 };
    element* temp = this->list_elem;
    while (temp != nullptr) {
        temp = temp->next_elem;
        quont++;
    }
    if (position >= quont) {
        this->Add_To_Tail(data);
    }
    if (position == 0) {
        this->Add_To_Head(data);
    }
    else {
        element* temp = this->list_elem;
        while (temp != nullptr) {
            if (iter == position) {
                element* newNode = new element(data);
                newNode->next_elem = temp;
                element* temp2 = this->list_elem;
                int res = iter;
                while (res > 1) {
                    temp2 = temp2->next_elem;
                    res--;
                }
                temp2->next_elem = newNode;
                break;
            }
            temp = temp->next_elem;
            iter++;
        }
    }
}
template<typename T>
void List::List<T>::Delete_from_head() {
    element* temp = this->list_elem;
    temp = temp->next_elem;
    element* temp2 = this->list_elem;
    delete temp2;
    temp2 = nullptr;
    this->list_elem = temp;
}
template<typename T>
void List::List<T>::Delete_from_tail() {
    element* temp = this->list_elem;
    while (temp->next_elem->next_elem != nullptr) {
        temp = temp->next_elem;
    }
    delete temp->next_elem;
    temp->next_elem = nullptr;
}
template<typename T>
void List::List<T>::Delete_from_position(int position) {
    if (position == 0) {
        this->Delete_from_head();
    }
    element* temp = this->list_elem;
    element* temp2 = this->list_elem;
    int iter{ 0 };
    while (iter != position) {
        temp = temp->next_elem;
        iter++;
    }
    temp = temp->next_elem;
    iter = 0;
    while ((iter + 1) != position) {
        temp2 = temp2->next_elem;
        iter++;
    }
    delete  temp2->next_elem;
    temp2->next_elem = temp;
}
template<typename T>
void List::List<T>::Delete_all() {
    element* temp = this->list_elem;
    while (temp->next_elem != nullptr) {
        this->Delete_from_head();
        temp = this->list_elem;
    }
    delete temp;
    temp = nullptr;
    this->list_elem = temp;
}
template<typename T>
void List::List<T>::direct_change() {
    element* temp = this->list_elem;
    if (temp->next_elem == nullptr) {

    }
    else {
        element* temp = this->list_elem;
        element* newline;
        while (temp->next_elem != nullptr) {
            temp = temp->next_elem;
        }
        newline = new element(temp->data);
        this->Delete_from_tail();
        element* tempnewline = newline;
        temp = this->list_elem;
        while (temp->next_elem != nullptr) {
            while (temp->next_elem != nullptr) {
                temp = temp->next_elem;
            }
            tempnewline->next_elem = new element(temp->data);
            tempnewline = tempnewline->next_elem;
            this->Delete_from_tail();
            temp = this->list_elem;
        }
        tempnewline->next_elem = new element(temp->data);
        tempnewline = tempnewline->next_elem;
        this->Delete_all();
        this->list_elem = newline;
        newline = nullptr;
    }
}
