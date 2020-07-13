#include <Windows.h>
#include <GL/glut.h>
#include <math.h>

// Initialization.
void initBackground(void) {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// Draw triangles.
void display(void) {
	double angle = 2 * 3.14 / 16;
	double angle1 = 0;

	glBegin(GL_TRIANGLES);

	for (int i = 0; i < 4; i++) {
		// Yellow triangles.
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2d(0.0, 0.0);
		glVertex2d(0.7 * cos(angle1), 0.7 * sin(angle1));
		angle1 += angle;
		glVertex2d(0.7 * cos(angle1), 0.7 * sin(angle1));

		// Red triangles.
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex2d(0.0, 0.0);
		glVertex2d(0.7 * cos(angle1), 0.7 * sin(angle1));
		angle1 += angle;
		glVertex2d(0.7 * cos(angle1), 0.7 * sin(angle1));

		// Green triangles.
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex2d(0.0, 0.0);
		glVertex2d(0.7 * cos(angle1), 0.7 * sin(angle1));
		angle1 += angle;
		glVertex2d(0.7 * cos(angle1), 0.7 * sin(angle1));

		// Blue triangles.
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex2d(0.0, 0.0);
		glVertex2d(0.7 * cos(angle1), 0.7 * sin(angle1));
		angle1 += angle;
		glVertex2d(0.7 * cos(angle1), 0.7 * sin(angle1));
	}

	glEnd();

	glFlush();
}

// Define main function.
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutCreateWindow("Multiple Triangles - SWE1809342 / Cai Shuxian");
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(400, 400);
	glutDisplayFunc(display);
	initBackground();
	glutMainLoop();
	return 0;
}