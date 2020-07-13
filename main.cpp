#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>

// Initialization.
void init(void)
{
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_shininess[] = { 100.0 };
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
    GLfloat white_light[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat Light_Model_Ambient[] = { 0.2, 0.2, 0.2, 1.0 };
    glShadeModel(GL_SMOOTH);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, Light_Model_Ambient);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

// Draw scene.
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Draw purple solid torus.
    glPushMatrix();
    glColor3f(1.0f, 0.0f, 0.6f);
    glRotatef(-40, 0.5, 0.5, 0);
    glScalef(1, 1, 3);
    glutSolidTorus(0.05, 0.5, 40, 200);
    glPopMatrix();

    // Draw yellow solid torus.
    glPushMatrix();
    glColor3f(1.0f, 1.0f, 0.0f);
    glRotatef(40, 0.5, 0.5, 0);
    glScalef(1, 1, 3);
    glTranslatef(-0.5, -0.5, 0);
    glutSolidTorus(0.05, 0.5, 40, 200);
    glPopMatrix();

    // Draw white solid torus.
    glPushMatrix();
    glColor3f(0.8f, 0.8f, 0.8f);
    glRotatef(70, 0.5, 0.5, 0);
    glScalef(1, 1, 3);
    glTranslatef(0.5, 0.5, 0);
    glutSolidTorus(0.05, 0.5, 40, 200);
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

// Define reshape function.
void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        glOrtho(-1.5, 1.5, -1.5 * (GLfloat)h / (GLfloat)w, 1.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
    else
        glOrtho(-1.5 * (GLfloat)w / (GLfloat)h, 1.5 * (GLfloat)w / (GLfloat)h, -1.5, 1.5, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Define main function.
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("3D circles - SWE1809342 / Cai Shuxian");
    init();
    glEnable(GL_COLOR_MATERIAL);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;
}
