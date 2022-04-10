
#include <iostream>
#include "Tank.h"
#include "MyTools.h"
#include <thread>
#include <chrono>
#include <future>

using namespace std;
using namespace MyTools;

bool Tank::isInside(double x1, double x2) const
{
	const double XBeg = x + 2;
	const double XEnd = x + width - 1;

	if (x1 < XBeg && x2 > XEnd)
	{
		return true;
	}

	if (x1 > XBeg && x1 < XEnd)
	{
		return true;
	}

	if (x2 > XBeg && x2 < XEnd)
	{
		return true;
	}

	return false;
}

void Tank::Draw() const
{
	MyTools::SetColor(CC_Brown);
	GotoXY(x, y - 3);
	cout << "    #####";
	GotoXY(x-2, y - 2);
	cout << "#######   #";
	GotoXY(x, y - 1);
	cout << "    #####";
	GotoXY(x,y);
	cout << " ###########";
	
	future<void> th(async(launch::async, &Tank::Tank_Messsage, this));
}

void Tank::Tank_Messsage() const {
	int x = rand() % 5;
	pMediator->Message(messages[x]);
	//std::this_thread::sleep_for(3000ms);
}

Tank::Tank() {
	messages.push_back("I'll kill you");
	messages.push_back("I'll find you");
	messages.push_back("I'll shoot you");
	messages.push_back("I'll burn you");
	messages.push_back("I'll break you");
}


