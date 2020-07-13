#include <windows.h>
#include <gl/gl.h>
#include <gl/glut.h>

// Define relevant variables.
float rtrix, rtriy, rtriz;
float tquadx;
float tquady;
float CR = 0.8;
float CG = 0.8;
float CB = 0.8;

// Initialization.
void myInit(GLvoid) {
	glShadeModel(GL_SMOOTH);
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f); // Define background color.
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_COLOR_MATERIAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

// Draw scene.
void myDisplay(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glPushMatrix();
	glTranslatef(-1.5f, 0.0f, -6.0f);
	glRotatef(rtrix, 1.0f, 0.0f, 0.0f);
	glRotatef(rtriy, 0.0f, 1.0f, 0.0f);
	glRotatef(rtriz, 0.0f, 0.0f, 1.0f);

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f); //1st vertex
	glColor3f(0.2f, 0.2f, 0.2f);
	glVertex3f(-1.0f, -1.0f, 0.0f); //2nd vertex
	glColor3f(0.4f, 0.4f, 0.4f);
	glVertex3f(1.0f, -1.0f, 0.0f); //3rd vertex
	glColor3f(0.6f, 0.6f, 0.6f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glEnd();

	glLoadIdentity();
	glTranslatef(1.5f, 0.0f, -6.0f);
	glTranslatef(tquadx, tquady, 0.0f);
	glColor3f(CR, CG, CB);
	glutSolidCube(1);

	glPopMatrix();
	glutSwapBuffers();
}

// Define reshape function.
void myReshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (h == 0)
		gluPerspective(80, (float)w, 1.0, 5000);
	else
		gluPerspective(80, (float)w / (float)h, 1.0, 5000);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// Define general keyboard function.
void myKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'x':
		rtrix += 1.5f;
		break;
	case 'y':
		rtriy += 1.5f;
		break;
	case 'z':
		rtriz += 1.5f;
		break;
	case 27:
		exit(0);
		break;
	default:
		break;
	}
}

// Define special keyboard function.
void myArrow_keys(int a_keys, int x, int y) {
	switch (a_keys) {
	case GLUT_KEY_LEFT:
		tquadx -= 0.5f;
		break;
	case GLUT_KEY_RIGHT:
		tquadx += 0.5f;
		break;
	case GLUT_KEY_UP:
		tquady += 0.5f;
		break;
	case GLUT_KEY_DOWN:
		tquady -= 0.5f;
		break;
	default:
		break;
	}
}

// Define mouse interaction function to change color.
void myMouse(int btn, int state, int x, int y) {
	if (btn == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		CR = 0.5;
		CG = 0.0;
		CB = 0.0;
	}
	if (btn == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) {
		CR = 0.0;
		CG = 0.8;
		CB = 0.0;
	}
	if (btn == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		CR = 0.0;
		CG = 0.0;
		CB = 0.5;
	}
	myDisplay();
}

// Define main function.
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Lab5 Exercise - SWE1809342 / Cai Shuxian");
	glutDisplayFunc(myDisplay);
	glutReshapeFunc(myReshape);
	glutKeyboardFunc(myKeyboard);
	glutSpecialFunc(myArrow_keys);
	glutMouseFunc(myMouse);
	myInit();
	glutMainLoop();
	return 0;
}
