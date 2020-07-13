#include<math.h>
#include <GL/glut.h>

// Define relevant variables.
static double r = 0.25;
static double l = 0.25;
static double m = 0.1;
static double lu = 0.25, ld = 0.19, lm = -0.8;
static double ru = 0.25, rd = 0.19, rm = 0.8;
static double ml = 0.0;
const float DEG2RAD = 3.14159 / 180;

// Draw scene.
void display(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Black and opaque
    glClear(GL_COLOR_BUFFER_BIT);
    glPolygonMode(GL_FRONT, GL_FILL);//glPolygonMode controls the interpretation of polygons for rasterization

    glColor3f(0.0f, 0.7f, 0.0f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        //convert degrees into radians
        float degInRad = i * DEG2RAD;
        glVertex2f(cos(degInRad) * r + 0.5, sin(degInRad) * r + 0.5);
    }
    glEnd();

    glColor3f(0.0f, 0.0f, 0.6f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        //convert degrees into radians
        float degInRad = i * DEG2RAD;
        glVertex2f(cos(degInRad) * l - 0.5, sin(degInRad) * l + 0.5);
    }
    glEnd();

    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        //convert degrees into radians
        float degInRad = i * DEG2RAD;
        glVertex2f(cos(degInRad) * m + ml, sin(degInRad) * m + 0.1);
    }
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(lm, lu);
    glVertex2f(rm, ru);
    glVertex2f(rm, rd);
    glVertex2f(lm, ld);
    glEnd();
    glFlush();
}

// Define timer function.
void timer_function(int value)
{
    static bool flag = true;
    static int count = 5;
    if (count == 10)
    {
        flag = false;
    }
    if (count == 0) {
        flag = true;
    }if (flag)
    {
        r += 0.007;
        ru -= 0.01;
        rd -= 0.01;

        l -= 0.007;
        lu += 0.01;
        ld += 0.01;

        ml -= 0.015;
        count++;
    }
    else
    {
        r -= 0.007;
        ru += 0.01;
        rd += 0.01;

        l += 0.007;
        lu -= 0.01;
        ld -= 0.01;

        ml += 0.015;
        count--;
    }
    glutPostRedisplay();
    glutTimerFunc(200, timer_function, 0);
}

// Define reshape function.
void reshapeFunc(int w, int h) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Define main function.
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Swing Bench - SWE1809342 / Cai Shuxian");
    glutDisplayFunc(display);
    glutReshapeFunc(reshapeFunc);
    glutTimerFunc(1, timer_function, 0);
    glutMainLoop();
    return 0;
}
