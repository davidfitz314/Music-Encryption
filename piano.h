#ifndef _PIANO_H_
#define _PIANO_H_


#include <ctime>

//split the width of the screen into WK sections
const int WK = 7;
//split the height of the screen into HK sections
const int HK = 4;

class PianoKey
{
public:
	PianoKey();
	PianoKey(int id_in, char kColor_in, char cId_in);
	~PianoKey();
	int getId();
	char GetKColor();
	char GetCId();
	void SetId(int id_in);
	void SetKColor(double kColor_in);
	void PianoKeyPressed();
	void DrawPianoKey(int i, int j);
	void ResetPushed();
private:
	int id;
	char kColor;
	char cId;
	double kRed, kGreen, kBlue;
	bool pushed;
	std::time_t start;
	//something to label the sound
};

class Piano
{
public:
	Piano();
	~Piano();
	void DrawPiano();
	void Play(int index);
protected:
	PianoKey mPianoKeys[WK][HK];
};

#endif