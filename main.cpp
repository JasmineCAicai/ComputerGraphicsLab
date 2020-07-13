#include <GL/glut.h>
// Define a 2 x 2 red and green checkered pattern using RGB colors.
#define y {0xff, 0xff, 0x00}
#define b {0x00, 0x00, 0xff}

GLubyte texture[][3] = { y, b,b, y, };
void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80, GLfloat(width) / height, 1, 40);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(2, -1, 5, 0, 0, 0, 0, 1, 0);
    glEnable(GL_TEXTURE_2D);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexImage2D(GL_TEXTURE_2D,
        0,                    // level 0
        3,                    // use only R, G, and B components
        2, 2,                 // texture has 2x2 texels
        0,                    // no border
        GL_RGB,               // texels are in RGB format
        GL_UNSIGNED_BYTE,     // color components are unsigned bytes
        texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
    glTexCoord2f(2, 2);      glVertex2f(-1, 1);
    glTexCoord2f(0, 2);      glVertex2f(-3, 1);
    glTexCoord2f(4, 0);      glVertex2f(-1, -1);
    glTexCoord2f(10, 0);     glVertex2f(-1, -3);
    //glTexCoord2f(0, 0);      
    glVertex2f(1, -1);
    glTexCoord2f(0, 2);      glVertex2f(2, -3);
    glTexCoord2f(2, 0);      glVertex2f(2, -1);
    glTexCoord2f(0, 6);      glVertex2f(4, 1);
    glTexCoord2f(1, 0);      glVertex2f(2, 1);
    glTexCoord2f(4, 4);      glVertex2f(1, 3);

    glEnd();
    glFlush();
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(520, 390);
    glutCreateWindow("Textured Sample - SWE1809342 / Cai Shuxian");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
}