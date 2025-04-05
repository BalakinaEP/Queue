#include <iostream>
#include <ctime>
#include "Node.h"
#include "Queue.h"

int getPositiveValue(const std::string message);

void checkPositive(const int value);

int main()
{
	setlocale(LC_ALL, "Russian");
	int workingTime = 
		getPositiveValue("Введите время работы в минутах: ");
	Queue myQueue;
	std::srand(std::time(0));
	int requestTime = rand() % 11;
	int serviceTime = rand() % 4 + 4; //случайное от 4 до 7
	int numberRequests = 0;
	myQueue.addNew();
	numberRequests++;
	int numberServicedRequests = 0;
	int numberNotServicedRequests = 0;
		for (int currentTime = requestTime;
		currentTime <= workingTime;)
	{
		requestTime = rand() % 11;
		
		if (std::min(requestTime, serviceTime) == requestTime)
		{
			numberRequests++;
			if (! myQueue.addNew())
			{
				numberNotServicedRequests++;
			}
			currentTime += requestTime;
			serviceTime -= requestTime;
			requestTime = rand() % 11;
			continue;
		}
		else
		{
			if (myQueue.deleteHead())
			{
				numberServicedRequests++;
			}
			currentTime += serviceTime;
			requestTime -= serviceTime;
			serviceTime = rand() % 4 + 14;
			continue;
		}
		
	}
	std::cout << "Число поступивших заявок: " <<
			numberRequests << std::endl;
	std::cout << "Число обслуженных заявок: " <<
			numberServicedRequests << std::endl;
	std::cout << "Число не обслуженных заявок: " <<
			numberNotServicedRequests << std::endl;
	return 0;
}

int getPositiveValue(const std::string message)
{
	std::cout << message;
	int value = 0;
	std::cin >> value;
	if (std::cin.fail())
	{
		throw ("Ошибочное значение");
	}
	checkPositive(value);
	return value;
}

void checkPositive(const int value)
{
	if (value <= 0)
	{
		throw ("Значение должно быть положительным");
	}
}
