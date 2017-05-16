#include <Windows.h> 
#include <MMSystem.h>
#pragma comment(lib, "winmm.lib")
using namespace std;

#include "piano.h"
#include "graphics.h"
#include "glut.h"
#pragma once
//#include "sounds.cpp"

PianoKey::PianoKey()
{
	this->id = 0;
	this->kColor = 'w';
	this->cId = 'x';
	this->kRed = 1.0;
	this->kGreen = 1.0;
	this->kBlue = 1.0;
	this->pushed = false;
	
	
}

PianoKey::PianoKey(int id_in, char kColor_in, char cId_in)
{
	this->id = id_in;
	this->kColor = kColor_in;
	if (id == 0){
		this->cId = 'E';
	} 
	if (id == 1){
		this->cId = 'F';
	} 
	if (id == 2){
		this->cId = 'G';
	} 
	if (id == 3){
		this->cId = 'A';
	} 
	if (id == 4){
		this->cId = 'B';
	} 
	if (id == 5){
		this->cId = 'C';
	} 
	if (id == 6){
		this->cId = 'D';
	} 
}

PianoKey::~PianoKey()
{
	this->id = -1;
}

int PianoKey::getId()
{
	return this->id;
}

char PianoKey::GetKColor()
{
	return this->kColor;
}

char PianoKey::GetCId()
{
	return this->cId;
}

void PianoKey::SetId(int id_in)
{
	this->id = id_in;
	if (id == 0){
		this->cId = 'E';
	} 
	if (id == 1){
		this->cId = 'F';
	} 
	if (id == 2){
		this->cId = 'G';
	} 
	if (id == 3){
		this->cId = 'A';
	} 
	if (id == 4){
		this->cId = 'B';
	} 
	if (id == 5){
		this->cId = 'C';
	} 
	if (id == 6){
		this->cId = 'D';
	} 
}

void PianoKey::SetKColor(double kColor_in)
{
	this->kColor = kColor_in;
}

void PianoKey::PianoKeyPressed()
{
	//temporarily darken or lighten piano key color
	//play piano key sound
	this->start = time(nullptr);
	this->kRed = 0.6;
	this->kGreen = 0.6;
	this->kBlue = 0.9;
	this->pushed = true;

   
	if(this->cId == 'A'){
		PlaySound(TEXT("A-Note.wav"), NULL, SND_ASYNC|SND_FILENAME);
	}
	if(this->cId == 'B'){
		PlaySound(TEXT("B-Note.wav"), NULL, SND_ASYNC|SND_FILENAME);
	}
	if(this->cId == 'C'){
		PlaySound(TEXT("C-Note.wav"), NULL, SND_ASYNC|SND_FILENAME);
	}
	if(this->cId == 'D'){
		PlaySound(TEXT("D-Note.wav"), NULL, SND_ASYNC|SND_FILENAME);
	}
	if(this->cId == 'E'){
		PlaySound(TEXT("E-Note.wav"), NULL, SND_ASYNC|SND_FILENAME);
	}
	if(this->cId == 'F'){
		PlaySound(TEXT("F-Note.wav"), NULL, SND_ASYNC|SND_FILENAME);
	}
	if(this->cId == 'G'){
		PlaySound(TEXT("G-Note.wav"), NULL, SND_ASYNC|SND_FILENAME);
	}
	
}

void PianoKey::ResetPushed()
{
	time_t tempT = time(nullptr);
	if (tempT - this->start > .000001){
		//might need a slight pause
		this->kRed = 1.0;
		this->kGreen = 1.0;
		this->kBlue = 1.0;
		this->pushed = false;
	}
}

void PianoKey::DrawPianoKey(int i, int j)
{
	char *ctemp = &this->cId;
	

	if (i == 0 && j==1){
		return;
	}
	if (i == 4 && j==1){
		
		return;
	}
	if (j==1){
		glColor3d(0,0,0);
		DrawRectangle(i-.3,j,i+.3, j+0.9999);

		glColor3d(1, 1, 1);
		DrawLine(i-.3,j, i+.3,j);
		DrawLine(i-.3,j+0.9999, i+.3,j+0.9999);
		DrawLine(i-.3,j, i-.3,j+0.9999);
		DrawLine(i+.3,j, i+.3,j+0.9999);
		return;
		
	} else {
		glColor3d(this->kRed,this->kGreen,this->kBlue);
		DrawRectangle(i,j,i+1, j+2);

		glColor3ub(0, 0, 0);
		DrawLine(i,j, i+1,j);
		DrawLine(i,j+2, i+1,j+2);
		DrawLine(i,j, i,j+2);
		DrawLine(i+1,j, i+1,j+2);
		//DrawText(i+.5, j+.5, ctemp);

		
		if (this->pushed)
		{
			this->ResetPushed();
		}
		return;
	}
}

Piano::Piano()
{
	//do nothing constructor
}

Piano::~Piano()
{
	//do nothing for now deconstructor
}

void Piano::Play(int index)
{
	this->mPianoKeys[index][0].PianoKeyPressed();
}

void Piano::DrawPiano()
{

	for(int i=0; i<WK; i++)
		for(int j=0; j<(HK/2); j++)
		{
			mPianoKeys[i][j].SetId(i);
			mPianoKeys[i][j].DrawPianoKey(i,j);

		}
}