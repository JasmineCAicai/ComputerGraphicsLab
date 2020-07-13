#include <GL/glut.h>

// Draw grid.
void display(void)
{
	glColor3f(1.0, 0.0, 0.0);

	gluOrtho2D(0.0, 100.0, 0.0, 150.0);
	glBegin(GL_LINES);
	for (int i = 10; i <= 52; i += 10.5)
	{
		glVertex2i(i, 10);
		glVertex2i(i, 50);
	}
	glEnd();

	glBegin(GL_LINES);
	for (int i = 10; i <= 50; i += 10)
	{
		glVertex2i(10, i);
		glVertex2i(50, i);
	}
	glEnd();
	glFlush();
}

// Define main function.
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(30, 30);
	glutCreateWindow("Grid - SWE1809342 / Cai ShuXian");
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}