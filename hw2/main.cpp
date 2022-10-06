/*******************************************************
 * Homework 2: OpenGL                                  *
 *-----------------------------------------------------*
 * First, you should fill in problem1(), problem2(),   *
 * and problem3() as instructed in the written part of *
 * the problem set.  Then, express your creativity     *
 * with problem4()!                                    *
 *                                                     *
 * Note: you will only need to add/modify code where   *
 * it says "TODO".                                     *
 *                                                     *
 * The left mouse button rotates, the right mouse      *
 * button zooms, and the keyboard controls which       *
 * problem to display.                                 *
 *                                                     *
 * For Linux/OS X:                                     *
 * To compile your program, just type "make" at the    *
 * command line.  Typing "make clean" will remove all  *
 * computer-generated files.  Run by typing "./hw2"    *
 *                                                     *
 * For Visual Studio:                                  *
 * You can create a project with this main.cpp and     *
 * build and run the executable as you normally would. *
 *******************************************************/

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "freeglut-3.2.1/include/GL/freeglut.h"

using namespace std;

bool leftDown = false, rightDown = false;
int lastPos[2];
float cameraPos[4] = {0, 1, 4, 1};
int windowWidth = 640, windowHeight = 410;
double yRot = 0;
int curProblem = 4; // TODO: change this number to try different examples

float specular[] = {1.0, 1.0, 1.0, 1.0};
float shininess[] = {50.0};

void problem1() {
	// TODO: Your code here!

	glPushMatrix();
	glTranslatef(0, 5, 0);
	glutSolidTeapot(.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3, 4, 0);
	glutSolidTeapot(.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5, 2, 0);
	glutSolidTeapot(.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5, -2, 0);
	glutSolidTeapot(.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(3.5, -4.5, 0);
	glutSolidTeapot(.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -5, 0);
	glutSolidTeapot(.5);
	glPopMatrix();

	//-- These will all be converted to -x
	glPushMatrix();
	glTranslatef(-3, 4, 0);
	glutSolidTeapot(.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5, 2, 0);
	glutSolidTeapot(.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5, -2, 0);
	glutSolidTeapot(.5);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.5, -4.5, 0);
	glutSolidTeapot(.5);
	glPopMatrix();
}

void problem2() {
	// TODO: Your code here!
	for (int i = -6; i < 6; i += 2) {
		glPushMatrix();
		glTranslatef(i, 5, 0); // location of first teapot
		glutSolidTeapot(.5);   // Draw teapot
		glPopMatrix();
	}

	for (int j = -5; j < 5; j += 2) {
		glPushMatrix();
		glTranslatef(j, 4, 0); // location of first teapot
		glutSolidTeapot(.5);   // Draw teapot
		glPopMatrix();
	}

	for (int j = -4; j < 4; j += 2) {
		glPushMatrix();
		glTranslatef(j, 3, 0); // location of first teapot
		glutSolidTeapot(.5);   // Draw teapot
		glPopMatrix();
	}

	for (int j = -3; j < 3; j += 2) {
		glPushMatrix();
		glTranslatef(j, 2, 0);
		glutSolidTeapot(.5);
		glPopMatrix();
	}

	for (int j = -2; j < 2; j += 2) {
		glPushMatrix();
		glTranslatef(j, 1, 0);
		glutSolidTeapot(.5);
		glPopMatrix();
	}

	glPushMatrix();
	glTranslatef(-1, 0, 0);
	glutSolidTeapot(.5);
	glPopMatrix();
}

void problem3() {
	// TODO: Your code here!

	for (int i = 10; i > -10; i--) {
		glPushMatrix();
		glTranslatef(-5, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
	for (int i = 10; i > -10; i--) {
		glPushMatrix();
		glTranslatef(-4, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
	for (int i = 9; i > -10; i--) {
		glPushMatrix();
		glTranslatef(-3, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
	for (int i = 9; i > -10; i--) {
		glPushMatrix();
		glTranslatef(-2, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
	for (int i = 8; i > -10; i--) {
		glPushMatrix();
		glTranslatef(-1, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
	for (int i = 8; i > -10; i--) {
		glPushMatrix();
		glTranslatef(0, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
	for (int i = 7; i > -10; i--) {
		glPushMatrix();
		glTranslatef(1, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
	for (int i = 7; i > -10; i--) {
		glPushMatrix();
		glTranslatef(2, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
	for (int i = 6; i > -10; i--) {
		glPushMatrix();
		glTranslatef(3, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
	for (int i = 6; i > -10; i--) {
		glPushMatrix();
		glTranslatef(4, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
	for (int i = 5; i > -10; i--) {
		glPushMatrix();
		glTranslatef(5, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
	for (int i = 5; i > -10; i--) {
		glPushMatrix();
		glTranslatef(6, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
	for (int i = 4; i > -10; i--) {
		glPushMatrix();
		glTranslatef(7, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
	for (int i = 4; i > -10; i--) {
		glPushMatrix();
		glTranslatef(8, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
	for (int i = 3; i > -10; i--) {
		glPushMatrix();
		glTranslatef(9, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
	for (int i = 3; i > -10; i--) {
		glPushMatrix();
		glTranslatef(10, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
	for (int i = 2; i > -10; i--) {
		glPushMatrix();
		glTranslatef(11, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
	for (int i = 2; i > -10; i--) {
		glPushMatrix();
		glTranslatef(12, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
	for (int i = 1; i > -10; i--) {
		glPushMatrix();
		glTranslatef(13, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
	for (int i = 1; i > -10; i--) {
		glPushMatrix();
		glTranslatef(14, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}

	for (int i = 0; i > -10; i--) {
		glPushMatrix();
		glTranslatef(15, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
	for (int i = 0; i > -10; i--) {
		glPushMatrix();
		glTranslatef(16, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}

	for (int i = -1; i > -10; i--) {
		glPushMatrix();
		glTranslatef(17, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
	for (int i = -1; i > -10; i--) {
		glPushMatrix();
		glTranslatef(18, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}

	for (int i = -2; i > -10; i--) {
		glPushMatrix();
		glTranslatef(19, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
	for (int i = -2; i > -10; i--) {
		glPushMatrix();
		glTranslatef(20, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
	for (int i = -3; i > -10; i--) {
		glPushMatrix();
		glTranslatef(21, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
	for (int i = -3; i > -10; i--) {
		glPushMatrix();
		glTranslatef(22, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}

	for (int i = -4; i > -10; i--) {
		glPushMatrix();
		glTranslatef(23, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}

	for (int i = -4; i > -10; i--) {
		glPushMatrix();
		glTranslatef(24, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
	for (int i = -5; i > -10; i--) {
		glPushMatrix();
		glTranslatef(25, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
	for (int i = -5; i > -10; i--) {
		glPushMatrix();
		glTranslatef(26, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
	for (int i = -6; i > -10; i--) {
		glPushMatrix();
		glTranslatef(27, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
	for (int i = -6; i > -10; i--) {
		glPushMatrix();
		glTranslatef(28, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}

	for (int i = -7; i > -10; i--) {
		glPushMatrix();
		glTranslatef(29, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
	for (int i = -7; i > -10; i--) {
		glPushMatrix();
		glTranslatef(30, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
	for (int i = -8; i > -10; i--) {
		glPushMatrix();
		glTranslatef(31, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
	for (int i = -8; i > -10; i--) {
		glPushMatrix();
		glTranslatef(32, i, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
}

void problem4() {
	// TODO: Your code here!

glBegin(GL_TRIANGLES);

  //-- tried making a rainbow but for some 
  //-- reason it wasn't changing color
  
 //glColor3f( 1, 0, 0 ); // red
glVertex2f( -0.6, 0 );
 //glColor3f( 0, 1, 0 ); // green
glVertex2f( 0.6, -0 );
// glColor3f( 0, 0, 1 ); // blue
glVertex2f( 0, -0.5);
  
  
glEnd();

  //-- created one side of the basket handle
	glPushMatrix();


	glTranslatef (0.45, 0.2, 0);
	glRotatef(-6, 0.0f, 0.0f, 1.0f);
	glPushMatrix();  

	
	glutSolidCube(0.2);
	glTranslatef (0, 0.3, 0);
	glutSolidCube(0.2);
	glTranslatef (0, 0.3, 0);
	glutSolidCube(0.2);
    glPopMatrix();
    glPopMatrix();

  
   //-- Here is the middle flaoting boxes to continue
  //-- the handles
	glPushMatrix();


	glTranslatef (0.15, 0.8, 0);
	glRotatef(-2, 0.0f, 0.0f, 1.0f);
	glPushMatrix();  

	
	glutSolidCube(0.2);
    glPopMatrix();
    glPopMatrix();

  
  
	glPushMatrix();

	glTranslatef (-0.15, 0.8, 0);
	glRotatef(2, 0.0f, 0.0f, 1.0f);
	glPushMatrix();  

	
	glutSolidCube(0.2);

    glPopMatrix();
    glPopMatrix();

  //-- This is the outside cube on the other side from the first code segment
	glPushMatrix();

	
	glTranslatef (-0.45, 0.2, 0);
	glRotatef(6, 0.0f, 0.0f, 1.0f);
	glPushMatrix(); 

	glutSolidCube(0.2);
	glTranslatef (0, 0.3, 0);

	glutSolidCube(0.2);
	glTranslatef (0, 0.3, 0);
	
	glutSolidCube(0.2);
    glPopMatrix();
    glPopMatrix();
}

void display() {
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glDisable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glBegin(GL_LINES);
	glColor3f(1, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(1, 0, 0); // x axis
	glColor3f(0, 1, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 1, 0); // y axis
	glColor3f(0, 0, 1);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 1); // z axis
	glEnd(/*GL_LINES*/);

	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
	glEnable(GL_LIGHT0);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, windowWidth, windowHeight);

	float ratio = (float)windowWidth / (float)windowHeight;
	gluPerspective(50, ratio, 1, 1000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(cameraPos[0], cameraPos[1], cameraPos[2], 0, 0, 0, 0, 1, 0);

	glLightfv(GL_LIGHT0, GL_POSITION, cameraPos);

	glRotatef(yRot, 0, 1, 0);

	if (curProblem == 1)
		problem1();
	if (curProblem == 2)
		problem2();
	if (curProblem == 3)
		problem3();
	if (curProblem == 4)
		problem4();

	glutSwapBuffers();
}

void mouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
		leftDown = (state == GLUT_DOWN);
	else if (button == GLUT_RIGHT_BUTTON)
		rightDown = (state == GLUT_DOWN);

	lastPos[0] = x;
	lastPos[1] = y;
}

void mouseMoved(int x, int y) {
	if (leftDown)
		yRot += (x - lastPos[0]) * .1;
	if (rightDown) {
		for (int i = 0; i < 3; i++)
			cameraPos[i] *= pow(1.1, (y - lastPos[1]) * .1);
	}

	lastPos[0] = x;
	lastPos[1] = y;
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
	curProblem = key - '0';
	if (key == 'q' || key == 'Q' || key == 27) {
		exit(0);
	}
	glutPostRedisplay();
}

void reshape(int width, int height) {
	windowWidth = width;
	windowHeight = height;
	glutPostRedisplay();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(windowWidth, windowHeight);
	glutCreateWindow("HW2");

	glutDisplayFunc(display);
	glutMotionFunc(mouseMoved);
	glutMouseFunc(mouse);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);

	glutMainLoop();

	return 0;
}
