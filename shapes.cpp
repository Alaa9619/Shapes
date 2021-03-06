// shapes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <iostream>
#include <stdlib.h> //Needed for "exit" function

  //Include OpenGL header files, so that we can use OpenGL
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

using namespace std;
void draw_pentagon();
void draw_hexagon();
void draw_heptagon();
void draw_octagon();
void draw_nonagon();
void draw_decagon();
//Called when a key is pressed
void handleKeypress(unsigned char key, //The key that was pressed
	int x, int y) {    //The current mouse coordinates
	switch (key) {
	case 27: //Escape key
		exit(0); //Exit the program
	}
}

//Initializes 3D rendering
void initRendering() {
	//Makes 3D drawing work when something is in front of something else
	glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h) {
	//Tell OpenGL how to convert from coordinates to pixel values
	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective


//Called when the window is resized
	//Set the camera perspective
	glLoadIdentity(); //Reset the camera
	gluPerspective(45.0,                  //The camera angle
		(double)w / (double)h, //The width-to-height ratio
		1.0,                   //The near z clipping coordinate
		200.0);                //The far z clipping coordinate
}

//Draws the 3D scene
void drawScene() {
	//Clear information from last draw
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective


	glPushMatrix();
	glColor3f(0.5f, 0.0f, 0.8f);
	draw_pentagon();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5f, 0.0f, 0.8f);
	draw_hexagon();
	glPopMatrix();



	glPushMatrix();
	glColor3f(0.5f, 0.0f, 0.8f);
	draw_heptagon();
	glPopMatrix();

	glutSwapBuffers(); //Send the 3D scene to the screen
}


int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500); //Set the window size

	//Create the window
	glutCreateWindow("Basic Shapes - videotutorialsrock.com");
	initRendering(); //Initialize rendering

	//Set handler functions for drawing, keypresses, and window resizes
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);

	glutMainLoop(); //Start the main loop.  glutMainLoop doesn't return.
	return 0; //This line is never reached
}



void draw_pentagon() {
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.6f, 0.6f, -5.0f);
	glVertex3f(0.0f, 1.0f, -5.0f);
	glVertex3f(0.6f, 0.6f, -5.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0.6f, 0.6f, -5.0f);
	glVertex3f(0.4f, 0.0f, -5.0f);
	glVertex3f(-0.4f, 0.0f, -5.0f);
	glVertex3f(-0.6f, 0.6f, -5.0f);
	glEnd();
}
void draw_hexagon() {
	glBegin(GL_QUADS);
	glVertex3f(-0.6f, 0.0f, -5.0f);
	glVertex3f(-0.4f, 0.4f, -5.0f);
	glVertex3f(0.4f, 0.4f, -5.0f);
	glVertex3f(0.6f, 0.0f, -5.0f);
	glEnd();

	glColor3f(0.5f, 0.0f, 0.8f);
	glBegin(GL_QUADS);
	glVertex3f(0.6f, 0.0f, -5.0f);
	glVertex3f(0.4f, -0.4f, -5.0f);
	glVertex3f(-0.4f, -0.4f, -5.0f);
	glVertex3f(-0.6f, 0.0f, -5.0f);
	glEnd();



}
void draw_heptagon() {
	glBegin(GL_TRIANGLES);
	glVertex3f(-0.6f, 0.8f, -5.0f);
	glVertex3f(0.0f, 1.0f, -5.0f);
	glVertex3f(0.6f, 0.8f, -5.0f);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(0.6f, 0.8f, -5.0f);
	glVertex3f(0.8f, 0.4f, -5.0f);
	glVertex3f(-0.8f, 0.4f, -5.0f);
	glVertex3f(-0.6f, 0.8f, -5.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(0.8f, 0.4f, -5.0f);
	glVertex3f(0.6f, 0.0f, -5.0f);
	glVertex3f(-0.6f, 0.0f, -5.0f);
	glVertex3f(-0.8f, 0.4f, -5.0f);
	glEnd();


}
void draw_octagon() {
	glBegin(GL_QUADS);
	glVertex3f(-0.6f, 0.6f, -5.0f);
	glVertex3f(-0.4f, 1.0f, -5.0f);
	glVertex3f(0.4f, 1.0f, -5.0f);
	glVertex3f(0.6f, 0.6f, -5.0f);
	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(0.6f, 0.6f, -5.0f);
	glVertex3f(0.6f, 0.2f, -5.0f);
	glVertex3f(-0.6f, 0.2f, -5.0f);
	glVertex3f(-0.6f, 0.6f, -5.0f);
	glEnd();
	glBegin(GL_QUADS);

	glVertex3f(0.6f, 0.2f, -5.0f);
	glVertex3f(0.4f, -0.2f, -5.0f);
	glVertex3f(-0.4f, -0.2f, -5.0f);
	glVertex3f(-0.6f, 0.2f, -5.0f);
	glEnd();
}
void draw_nonagon() {

	glBegin(GL_TRIANGLES); //Begin quadrilateral coordinates
	glVertex3f(-0.8f, 1.0f, -5.0f);
	glVertex3f(0.0f, 1.4f, -5.0f);
	glVertex3f(0.8f, 1.0f, -5.0f);
	glEnd();
	glBegin(GL_QUADS);

	glVertex3f(0.8f, 1.0f, -5.0f);
	glVertex3f(1.0f, 0.6f, -5.0f);
	glVertex3f(-1.0f, 0.6f, -5.0f);
	glVertex3f(-0.8f, 1.0f, -5.0f);
	glEnd();
	glBegin(GL_QUADS);

	glVertex3f(1.0f, 0.6f, -5.0f);
	glVertex3f(0.8f, 0.2f, -5.0f);
	glVertex3f(-0.8f, 0.2f, -5.0f);
	glVertex3f(-1.0f, 0.6f, -5.0f);
	glEnd();
	glBegin(GL_QUADS);

	glVertex3f(0.8f, 0.2f, -5.0f);
	glVertex3f(0.2f, 0.0f, -5.0f);
	glVertex3f(-0.2f, 0.0f, -5.0f);
	glVertex3f(-0.8f, 0.2f, -5.0f);
	glEnd();
}
void draw_decagon() {


	glBegin(GL_QUADS);

	glVertex3f(-1.0f, 0.4f, -5.0f);
	glVertex3f(-0.6f, 0.8f, -5.0f);
	glVertex3f(0.6f, 0.8f, -5.0f);
	glVertex3f(1.0f, 0.4f, -5.0f);
	glEnd();

	glBegin(GL_QUADS);
	glVertex3f(1.0f, 0.4f, -5.0f);
	glVertex3f(1.2f, 0.0f, -5.0f);
	glVertex3f(-1.2f, 0.0f, -5.0f);
	glVertex3f(-1.0f, 0.4f, -5.0f);

	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(1.2f, 0.0f, -5.0f);
	glVertex3f(1.0f, -0.4f, -5.0f);

	glVertex3f(-1.0f, -0.4f, -5.0f);
	glVertex3f(-1.2f, 0.0f, -5.0f);

	glEnd();
	glBegin(GL_QUADS);
	glVertex3f(1.0f, -0.4f, -5.0f);
	glVertex3f(0.6f, -0.8f, -5.0f);

	glVertex3f(-0.6f, -0.8f, -5.0f);
	glVertex3f(-1.0f, -0.4f, -5.0f);

	glEnd();
}





