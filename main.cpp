#include <Windows.h>
#include <GL/glut.h>
#include <GL/gl.h>

// Define relevant variables.
double x1 = 280.0;
double y1 = 300.0;
double x2 = 360.0;
double y2 = 300.0;
double x3 = 320.0;
double y3 = 200.0;

float red = 0.0, green = 0.0, blue = 0.0;

// Initialization.
void myInit(void) {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
}

// Draw triangle.
void myDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(red, green, blue);
	glBegin(GL_TRIANGLES);
	glVertex3f(x1, y1, 0);
	glVertex3f(x2, y2, 0);
	glVertex3f(x3, y3, 0);
	glEnd();
	glFlush();
}

// Define general keyboard function.
void myKeyboard(unsigned char theKey, int mouseX, int mouseY) {
	switch (theKey)
	{
	case 'a':
		red = 0.6; // Change color to red.
		blue = 0.0;
		green = 0.0;
		break;
	case 's':
		red = 0.0;
		green = 0.6; // Change color to green.
		blue = 0.0;
		break;
	case 'd':
		red = 0.0;
		green = 0.0;
		blue = 0.6; // Change color to blue.
		break;
	case 27:
		exit(0);
		break;
	}
	glutPostRedisplay();
}

// Define special keyboard function to move triangle.
void specialKey(int key, int x, int y) {
	switch (key)
	{
	case GLUT_KEY_UP:
		y1 += 5;
		y2 += 5;
		y3 += 5;
		break;
	case GLUT_KEY_DOWN:
		y1 -= 5;
		y2 -= 5;
		y3 -= 5;
		break;
	case GLUT_KEY_LEFT:
		x1 -= 5;
		x2 -= 5; 
		x3 -= 5;
		break;
	case GLUT_KEY_RIGHT:
		x1 += 5;
		x2 += 5;
		x3 += 5;
		break;
	}
	glutPostRedisplay();
}

// Define main function.
int main(int argc, char** argv) {

	glutInit(&argc, argv);
	
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Keys & Letters Action on Triangle - SWE1809342 / Cai Shuxian");
	glutDisplayFunc(myDisplay);
	glutKeyboardFunc(myKeyboard);
	glutSpecialFunc(specialKey);
	myInit();
	glutMainLoop();
	return 0;
}