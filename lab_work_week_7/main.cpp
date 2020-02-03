#include "dependies.h"
#include "function _try.h"
#include "Stack_template.h"
#include"list_template.h"
#include"List_two_direction.h"
#include "binary_tree.h"

using namespace std;
int main() {
	Stack::Stack<int>a;
	a.Add(5);
	a.Add(10);
	a.Clear_all();
	a.Get_top();
	List::List<double>b;
	b.Add_To_Head(45.7);
	List_two_dicert::list_two_direcktion<char>q;
	q.Add_to_head('A');
	binary_tree::binary_tree qaz;
	return 0;
}