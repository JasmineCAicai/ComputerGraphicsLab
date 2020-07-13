#include <GL/glut.h>
#include <cmath>

#define PI 3.14159265

// Define relevant variables.
static float radius = 0.05;
static float rx = -0.9; // Position about red ball on x-axis.
static float gx1 = -0.7, gx2 = -0.5; // Position about green balls on x-axis. 
static float yx1 = -0.3, yx2 = -0.1, yx3 = 0.1; // Position about yellow balls on x-axis.
static float bx1 = 0.1, bx2 = 0.3, bx3 = 0.5, bx4 = 0.7; // Position about blue balls on x-axis.
static int times = 0;

// Initialization.
void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
}

// Draw balls.
void createBall(float x, float y, float r, float g, float b) {
    glColor3f(r, g, b);
    glPolygonMode(GL_FRONT, GL_FILL);
    glBegin(GL_POLYGON);
    float t = 0.0;
    for (int i = 0; i < 52 * 3; i++) {
        glVertex3f(x + radius * cos(t), y + radius * sin(t), 0.0);
        t += 2 * PI / 52;
    }
    glEnd();
}

// Display scene.
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw red balls.
    createBall(rx, -0.8, 1.0, 0.0, 0.0);

    // Draw green balls.
    createBall(gx1, -0.6, 0.0, 1.0, 0.0);
    createBall(gx2, -0.6, 0.0, 1.0, 0.0);
    createBall(gx2, -0.8, 0.0, 1.0, 0.0);
    
    // Draw yellow balls.
    createBall(yx1, -0.4, 1.0, 1.0, 0.0);
    createBall(yx2, -0.4, 1.0, 1.0, 0.0);
    createBall(yx3, -0.4, 1.0, 1.0, 0.0);
    createBall(yx3, -0.6, 1.0, 1.0, 0.0);
    createBall(yx3, -0.8, 1.0, 1.0, 0.0);

    // Draw blue balls.
    createBall(bx1, -0.2, 0.0, 0.0, 1.0);
    createBall(bx2, -0.2, 0.0, 0.0, 1.0);
    createBall(bx3, -0.2, 0.0, 0.0, 1.0);
    createBall(bx4, -0.2, 0.0, 0.0, 1.0);
    createBall(bx4, -0.4, 0.0, 0.0, 1.0);
    createBall(bx4, -0.6, 0.0, 0.0, 1.0);
    createBall(bx4, -0.8, 0.0, 0.0, 1.0);

    glFlush();
}

//  Define timer function.
void timer(int value) {

    if (times < 39) {
        rx += 0.03;

        if (times < 32) {
            gx1 += 0.03;
            gx2 += 0.03;

            if (times < 19) {
                yx1 += 0.03;
                yx2 += 0.03;
                yx3 += 0.03;

                if (times < 5) {
                    bx1 += 0.03;
                    bx2 += 0.03;
                    bx3 += 0.03;
                    bx4 += 0.03;
                }
            }
        }
    }

    times++;

    glutPostRedisplay();
    glutTimerFunc(200, timer, 0);
}

// Define main function.
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Moving Balls - SWE1809342 / Cai Shuxian");
    glutDisplayFunc(display);
    glutTimerFunc(200, timer, 0);
    init();
    glutMainLoop();
}
