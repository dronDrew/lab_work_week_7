#pragma once
#include "dependies.h"
int Value_of_struing(std::string& a) {
	int res{ 0 };
	try
	{
		for (int i = 0; i < a.length(); i++)
		{
			res += int(a[i]);
			if (res>=INT_MAX)
			{
				throw res;
			}
		}
		
	}
	catch (int)
	{
		std::cout << "Int value overflow\n";
		return res;
	}
	
}
int Value_of_struing(const char * a) {
	int res{ 0 };
	try
	{
		for (int i = 0; i < std::strlen(a); i++)
		{
			res += int(a[i]);
			if (res >= INT_MAX)
			{
				throw res;
			}
		}
		return res;
	}
	catch (int)
	{
		std::cout << "Int value overflow\n";
		return res;
	}

}