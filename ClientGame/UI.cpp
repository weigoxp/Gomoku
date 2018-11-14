#include "stdafx.h"
#include <fstream>
#include <iostream>

using namespace std;

class UI : public Renderable
{
	public:
	UI();
	void Start(){};
	void Stop();
	void Update(float dt);
	void Render();
	void ReceiveMessage(Message *message){}

	static TextActor* _output = NULL;
	static AngelUIHandle _choiceBox = NULL;

	protected:
	vector<Renderable*> _objects;
};


