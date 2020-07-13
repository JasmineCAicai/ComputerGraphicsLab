#include <gl/glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool fullscreen = false;
float x1, y11, x2, y2;

// Initialization.
bool init()
{
	glClearColor(0.93f, 0.93f, 0.93f, 0.0f); // Define background color.
	return true;
}

// Draw scene.
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	int PI = 3.14159265;
	float r = 0.07f * 2;
	if (x1 + r > 1.0f || x1 - r < -1.0f)
	{
		x2 *= -1;
	}
	if (y11 + r > 1.0f || y11 - r < -1.0f)
	{
		y2 *= -1;
	}
	x1 += x2*0.02;
	y11 += y2*0.02;

	glColor3f(1.0f, 0.0f, 0.0f); // Define ball color.

	// Draw ball.
	glBegin(GL_POLYGON);
	for (float angle = 0; angle < 360; angle += 5)
	{
		float xc = sin(angle * PI / 180) * r;
		float yc = cos(angle * PI / 180) * r;
		glVertex3f(xc + x1, yc + y11, 0.0f);
	}
	glEnd();

	glutSwapBuffers();
	glutPostRedisplay();
}

// Define main function.
int main(int argc, char* argv[])
{
	srand(time(NULL));
	int step = 10;
	x1 = (rand() % step) / step - 0.5f;
	y11 = (rand() % step) / step - 0.5f;
	x2 = 0.0655f;
	y2 = 0.0555f;
	glutInit(&argc, argv);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(500, 500);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutCreateWindow("Lab 10 - Bouncing Ball / SWE1809342 CAI SHUXIAN");
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
