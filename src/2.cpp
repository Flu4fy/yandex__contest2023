#include<bits/stdc++.h>
#include<exception>
using namespace std;

class DinMass
{
	public:
		int length; 
		int* dinmass;
		DinMass();
		DinMass(int size); 
		DinMass(const DinMass& tmp); 
		void DinMass_Add_Subt(const DinMass& tmp, int k);
		void DinMass_Output();
		int DinMass_Getter(int number); 
		void DinMass_Setter(int number, int value); 
		void DinMass_PushBack(int value); 
		~DinMass();	
};

DinMass::DinMass()
{
	length = 0;
	dinmass = nullptr;
} 

DinMass::DinMass(int size) 
{
	if(dinmass == 0)
	{
		length = 0;
		dinmass = nullptr;
	}
	else
	{
		length = size;
		dinmass = new int[length];
	}
}

DinMass::DinMass(const DinMass& tmp) 
{
	int i;
	length = tmp.length;
	dinmass = new int[length];
	for(i = 0; i < length; i++)
	{
		dinmass[i] = tmp.dinmass[i];
	}
}

void DinMass::DinMass_Add_Subt(const DinMass& tmp, int k)
{
	int i;
	if(k == 0)
	{
		if(tmp.length < length)
		{
			for(i = 0; i < tmp.length; i++)
			{
				dinmass[i] += tmp.dinmass[i];
			}
		}
		else
		{
			for(i = 0; i < length; i++)
			{
				dinmass[i] += tmp.dinmass[i];
			}
		}
	}
	else
	{
		if(tmp.length < length)
		{
			for(i = 0; i < tmp.length; i++)
			{
				dinmass[i] -= tmp.dinmass[i];
			}
		}
		else
		{
			for(i = 0; i < length; i++)
			{
				dinmass[i] -= tmp.dinmass[i];
			}
		}
	}
}

void DinMass::DinMass_Output()
{
	int i;
	if(length != 0)
	{
		for(i = 0; i < length; i++)
		{
			cout << dinmass[i] << " ";
		}
		cout << "\n"; 
	}
}

int DinMass::DinMass_Getter(int number)
{
	if(number + 1 <= length and number >= 0)
	{
		return dinmass[number];
	} 
	throw "std:out_of_range:get";
}

void DinMass::DinMass_Setter(int number, int value)
{
	if(number + 1 <= length and number >= 0)
	{
		if(value >= -100 and value <= 100)
		{
			dinmass[number] = value;
		} 
		else
		{
			throw "std:invalid_argument:set";
		} 
	}
	else
	{
		throw "std:out_of_range:set";
	} 
}

void DinMass::DinMass_PushBack(int value)
{
	int i;
	if(value >= -100 and value <= 100)
	{
		int tmp_length = length + 1;
		int* tmp_dinmass = new int[tmp_length];
		if(dinmass != 0)
		{
			for(i = 0; i < length; i++)
			{
				tmp_dinmass[i] = dinmass[i];
			}
			dinmass = tmp_dinmass;
		}
		else dinmass = new int[tmp_length];
		length = tmp_length;
		dinmass[length - 1] = value;
	}
	else
	{
		throw "std:invalid_argument:push_back";
	} 
}

DinMass::~DinMass()
{
	delete[] dinmass;
}

int main(){
	int n, i, N;
	int size1, size2;
	cin >> size1;
	DinMass dinmass1;
	if(size1 != 0)
	{
		for(i = 0; i < size1; i++)
		{
			int x;
			cin >> x;
			dinmass1.DinMass_PushBack(x);
		}
	}
	cin >> size2;
	DinMass dinmass2;
	if(size2 != 0)
	{
		for(i = 0; i < size2; i++)
		{
			int x;
			cin >> x;
			dinmass2.DinMass_PushBack(x);
		}
	}
	cin >> N;
	int count = 0;
	while(count < N)
	{
		count++;
		int num_com, num_dinmass;
		cin >> num_com >> num_dinmass;
		if(num_com == 1)
		{
			int num_elem;
			cin >> num_elem;
			try{
				if(num_dinmass == 1) cout << dinmass1.DinMass_Getter(num_elem) << "\n";
				else{
					cout << dinmass2.DinMass_Getter(num_elem) << "\n";
				} 
			}
			catch (const char* error_message){
				cout << error_message << "\n";
			}
		}
		if(num_com == 2)
		{
			int num_elem, num_val;
			cin >> num_elem >> num_val;
			try
			{
				if(num_dinmass == 1) dinmass1.DinMass_Setter(num_elem, num_val);
				else dinmass2.DinMass_Setter(num_elem, num_val);
			}
			catch (const char* error_message)
			{
				cout << error_message << "\n";
			}
		}
		if(num_com == 3)
		{
			int num_val;
			cin >> num_val;
			try
			{
				if(num_dinmass == 1) dinmass1.DinMass_PushBack(num_val);
				else dinmass2.DinMass_PushBack(num_val);
			}
			catch (const char* error_message)
			{
				cout << error_message << "\n";
			}
		}
		if(num_com == 4)
		{
			if(num_dinmass == 1) dinmass1.DinMass_Output();
			else dinmass2.DinMass_Output();
		}
		if(num_com == 5 or num_com == 6)
		{
			if(num_dinmass == 1) dinmass1.DinMass_Add_Subt(dinmass2, num_com % 5);
			else dinmass2.DinMass_Add_Subt(dinmass1, num_com % 5);
		}
	}
}