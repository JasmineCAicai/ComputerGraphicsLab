#include <Windows.h>
#include <GL/gl.h>
#include <GL/glut.h>

static int year = 0;

// Initialization.
void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}

// Draw scene.
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 0.0);

	glPushMatrix();
	glutWireSphere(1.0, 10, 10); // draw the big object
	glRotatef((GLfloat)year, 0.0, 1.0, 0.0);
	glPopMatrix();

	glutSwapBuffers();
}

// Define reshape function.
void myReshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 2.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

// Define main function.
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(400, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Wire Object - SWE1809342 / Cai Shuxian");
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	myInit();
	glutMainLoop();
}
