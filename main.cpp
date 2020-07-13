#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <math.h>

// Define relevant variables.
int circle_points = 100;
GLfloat ylocation = 0.0f;
GLfloat rotateobject = 0.0f;
GLfloat ballX = 0.0f;
GLfloat ballY = 0.0f;
int refreshMills = 15; // refresh interval in milliseconds [NEW]
void circle(float x, float y, float angle);

// Initialization.
void initGL()
{
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque

}

// Draw scene.
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(ballX, ballY, 0.0f);
    glRotatef(rotateobject, 0.0f, 0.0f, 1.0f);

    //glRotatef(rotateobject, 0.0f, 0.0f, 1.0f);
    glPolygonMode(GL_FRONT, GL_FILL);

    glRotatef(90, 0, 0, 1);
    glColor3f(0.0, 0.0, 1.0);   //blue
    circle(0.3, 0.3, 180);

    glRotatef(90, 0, 0, 1);
    glColor3f(0.0, 1.0, 0.0);   //green
    circle(0.3, 0.3, 135);

    glRotatef(90, 0, 0, 1);
    glColor3f(1.0, 1.0, 0.0); // yellow
    circle(0.3, 0.3, 90);

    glRotatef(90, 0, 0, 1);
    glColor3f(1.0, 0.0, 0.0); // red
    circle(0.3, 0.3, 45);

    glColor3f(1.0, 1.0, 1.0);   //white
    circle(0.1, 0.1, 360);

    glLoadIdentity();
    glEnd();
    glFlush();
    glutPostRedisplay();

    rotateobject += 0.05f;
}

// Define special keyboard function.
void keyboard(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        ballY = ballY + 0.05f;
        glutPostRedisplay();
        break;
    case GLUT_KEY_DOWN:
        ballY = ballY - 0.05f;
        glutPostRedisplay();
        break;
    case GLUT_KEY_LEFT:
        ballX = ballX - 0.05f;
        glutPostRedisplay();
        break;
    case GLUT_KEY_RIGHT:
        ballX = ballX + 0.05f;
        glutPostRedisplay();
        break;
    }
}

// Define general keyboard function.
void keyPressed(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:  // Escape Key -- good way to quit
        exit(0);  // Quit
        break;
    }
}

// Define main function.
int main(int argc, char** argv) {
    glutInitWindowSize(600, 600);   // Set the window's initial width & height
    glutInit(&argc, argv);          // Initialize GLUT
    glutCreateWindow("Lab8 2D Animation (Logo) - SWE1809342 / Cai Shuxian");  // Create window with the given title
    glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    initGL();                       // Our own OpenGL initialization
    glutSpecialFunc(keyboard);       //keyboard call back function
    glutKeyboardFunc(keyPressed);    //Press Esc will terminate the program
    glutMainLoop();                 // Enter the event-processing loop
    return 0;
}

// Draw circle.
void circle(float x, float y, float angle)
{
    glBegin(GL_POLYGON);
    glVertex3f(0, 0, 0.5);
    float theta = 0;
    for (int i = 0; i <= angle; i++)
    {
        theta = 3.142 * 2 / 180 * i;
        glVertex3f(x * cos(theta), y * sin(theta), 0);
    }

    glEnd();
}
