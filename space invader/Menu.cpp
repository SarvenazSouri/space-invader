//implementation of the menu class
#include "Menu.h"

Menu::Menu(string title, string* choiceList, int nbItem, int startLine, int startColumn){
	this->_title=title;
	this->_choiceList = new string[nbItem];
	for(int i=0;i<nbItem;i++){
		this->_choiceList[i]=choiceList[i];
	}
	choiceList;
	this->_nbItem= nbItem;
	this->cornerUL.X= startColumn;
	this->cornerUL.Y= startLine;
	//initialising the positions
	init();
}

void Menu::init(){
	//initialisation of the positions and the choice
	this->choice=1;
	this->_currentPos.X = cornerUL.X;
	this->_currentPos.Y = cornerUL.Y+2;
	this->_firstPos= _currentPos;
	this->_lastPos= _firstPos;
	this->_lastPos.Y= _firstPos.Y+2*(_nbItem-1);
}

Menu::~Menu(){
	delete []this->_choiceList;

}

int Menu::displayMenu(){
	
	COORD nextPos=_currentPos;
	//draw the menu
	gotoXY(cornerUL);
	cout<<_title<<endl;
	for(int i=0; i<_nbItem;i++){
		gotoXY(cornerUL.X+4, _firstPos.Y+(2*i));
		cout<<_choiceList[i]<<endl;
	}
	//get arrow input
	int key;
	//move(_currentPos, _firstPos);
	move(_currentPos, _currentPos);
	do{	
		nextPos=_currentPos;
		key=_getch();
		if(key==224){
			key= _getch();
		}
		//move
		switch(key){
		case 80:	//down key
			if(_currentPos.Y==_lastPos.Y) //if we are already down
			{
				move(_currentPos, _firstPos);
				_currentPos = _firstPos;
				choice=1;
			}
			else
			{
				nextPos.Y+=2;
				move(_currentPos, nextPos);
				_currentPos.Y+=2;
				choice++;
			}
			break;	
		case 72:	//up key
			if(_currentPos.Y==_firstPos.Y) //if we are already up
			{
				move(_currentPos,_lastPos);
				_currentPos=_lastPos;
				choice=_nbItem;
			}
			else
			{
				nextPos.Y-=2;
				move(_currentPos, nextPos);
				_currentPos.Y-=2;
				choice--;
			}
			break;
		}

	}while(key !=13);
	//return the choice
	
return choice;
}


void Menu::move(COORD origin, COORD target){
	//erase
	gotoXY(origin);
	cout<<"   "<<endl;
	//draw
	gotoXY(target);
	cout<<"-->"<<endl;
}


int Menu::getMaxSize(){
	return 0;
}


void Menu::gotoXY(COORD pos){
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}


void Menu::gotoXY(int c, int l){
	COORD coord;
	coord.X=c;
	coord.Y=l;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
