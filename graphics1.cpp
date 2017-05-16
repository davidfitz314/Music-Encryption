// OpenGL/GLUT starter kit for Windows 7 and Visual Studio 2010
// Created spring, 2011
//
// This is a starting point for OpenGl applications.
// Add code to the "display" function below, or otherwise
// modify this file to get your desired results.
//
// For the first assignment, add this file to an empty Windows Console project
//		and then compile and run it as is.
// NOTE: You should also have glut.h,
// glut32.dll, and glut32.lib in the directory of your project.
// OR, see GlutDirectories.txt for a better place to put them.

#include <cmath>
#include <string>
using namespace std;
#include "encrypt.h"
#include "graphics.h"
#include "piano.h"

#include "glut.h"
#pragma once
// Global Variables (Only what you need!)
double screen_x = 1100;
double screen_y = 650;
bool cirOn = false;
bool cirB = false;
string new_key = "";

Piano mPiano;
MyEncrypt mEncrypt;
// 
// Functions that draw basic primitives
//
void DrawCircle(double x1, double y1, double radius)
{
	glBegin(GL_POLYGON);
	for(int i=0; i<32; i++)
	{
		double theta = (double)i/32.0 * 2.0 * 3.1415926;
		double x = x1 + radius * cos(theta);
		double y = y1 + radius * sin(theta);
		glVertex2d(x, y);
	}
	glEnd();
}

void DrawRectangle(double x1, double y1, double x2, double y2)
{
	glBegin(GL_QUADS);
	glVertex2d(x1,y1);
	glVertex2d(x2,y1);
	glVertex2d(x2,y2);
	glVertex2d(x1,y2);
	glEnd();
}

void DrawTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
	glBegin(GL_TRIANGLES);
	glVertex2d(x1,y1);
	glVertex2d(x2,y2);
	glVertex2d(x3,y3);
	glEnd();
}

void DrawLine(double x1, double y1, double x2, double y2)
{
	glBegin(GL_LINES);
	glVertex2d(x1,y1);
	glVertex2d(x2,y2);
	glEnd();
}

// Outputs a string of text at the specified location.
void DrawText(double x, double y, string string_in)
{
	void *font = GLUT_BITMAP_9_BY_15;

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
	
	int len, i;
	glRasterPos2d(x, y);
	
	for (i = 0; i < string_in.size(); i++) 
	{
		glutBitmapCharacter(font, string_in[i]);
	}

	
    glDisable(GL_BLEND);
}


//
// GLUT callback functions
//

// This callback function gets called by the Glut
// system whenever it decides things need to be redrawn.
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	
	glColor3d(0.55,0.27,0.08);
	DrawRectangle(-.25, -.25, WK+.25, (HK/2)+.25);

	if (cirB){
		glColor3d(1,0,1);
		DrawCircle(150,150,50);
	}
	
	glColor3d(0,0,0);
	DrawLine(.5, 3.59, WK-.5, 3.59); 
	DrawLine(.5, 3.49, WK-.5, 3.49); 
	DrawLine(.5, 3.39, WK-.5, 3.39); 
	DrawLine(.5, 3.29, WK-.5, 3.29); 
	DrawLine(.5, 3.19, WK-.5, 3.19); 
	//this key gets drawn and passed waits for a button press to encrypt
	DrawText(1, 3.6, new_key);

	glColor3d(1,1,1);
	DrawRectangle(0, 0, WK, HK/4);
	mPiano.DrawPiano();
	glutSwapBuffers();
	glutPostRedisplay(); // Force an animation
}


// This callback function gets called by the Glut
// system whenever a key is pressed.
void keyboard(unsigned char c, int x, int y)
{
	switch (c) 
	{
		case 27: // escape character means to quit the program
			exit(0);
			break;
		case 'b':
			if (cirOn){
				cirB = false;
				cirOn = false;
			} else {
				cirB = true;
				cirOn = true;
			}
			// do something when 'b' character is hit.
			break;
		case '1':
			mPiano.Play(0);
			new_key += "D";
			break;
		case '2':
			mPiano.Play(1);
			new_key += "E";
			break;
		case '3':
			mPiano.Play(2);
			new_key += "F";
			break;
		case '4':
			mPiano.Play(3);
			new_key += "G";
			break;
		case '5':
			mPiano.Play(4);
			new_key += "A";
			break;
		case '6':
			mPiano.Play(5);
			new_key += "B";
			break;
		case '7':
			mPiano.Play(6);
			new_key += "C";
			break;
		case 'e':
			mEncrypt.caesar(new_key);
			break;
		case 'd':
			mEncrypt.caesarDecrypt(new_key);
			break;
		default:
			return; // if we don't care, return without glutPostRedisplay()
	}

	glutPostRedisplay();
}


// This callback function gets called by the Glut
// system whenever the window is resized by the user.
void reshape(int w, int h)
{
	// Reset our global variables to the new width and height.
	screen_x = w;
	screen_y = h;

	// Set the pixel resolution of the final picture (Screen coordinates).
	glViewport(0, 0, w, h);

	// Set the projection mode to 2D orthographic, and set the world coordinates:
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 0, w, h);
	// go into 2D mode
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	double world_margin_x = 0.5;
	double world_margin_y = 0.5;
	gluOrtho2D(-world_margin_x,WK+world_margin_x, 
		-world_margin_y, HK+world_margin_y);
	glMatrixMode(GL_MODELVIEW);

}

// This callback function gets called by the Glut
// system whenever any mouse button goes up or down.
void mouse(int mouse_button, int state, int x, int y)
{
	if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
	{
	}
	if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_UP) 
	{
	}
	if (mouse_button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) 
	{
	}
	if (mouse_button == GLUT_MIDDLE_BUTTON && state == GLUT_UP) 
	{
	}
	glutPostRedisplay();
}

// Your initialization code goes here.
void InitializeMyStuff()
{
	//file to encrpy
	mEncrypt.SetInputFileNameE("none.txt");
	//file to decrypt
	mEncrypt.SetInputFileNameD("new.txt");
}


int main(int argc, char **argv)
{
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(screen_x, screen_y);
	glutInitWindowPosition(50, 50);

	int fullscreen = 0;
	if (fullscreen) 
	{
		glutGameModeString("800x600:32");
		glutEnterGameMode();
	} 
	else 
	{
		glutCreateWindow("This appears in the title bar");
	}

	glutDisplayFunc(display);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouse);

	glColor3d(0,0,0); // forground color
	glClearColor(1, 1, 1, 0); // background color
	InitializeMyStuff();

	glutMainLoop();

	return 0;
}
