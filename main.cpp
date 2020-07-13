#include <GL/glut.h> 

const int numcontrolpts = 4;

GLfloat controlpts1[numcontrolpts][3] = {
   {-0.8, 0.3, 0.0}, {-0.9, -0.1, 0.0},{ 0.5, -0.4, 0.0}, { 0.9, 0.0, 0.0} };

GLfloat controlpts2[numcontrolpts][3] = {
   {-0.8, -0.3, 0.0}, {-0.9, 0.1, 0.0},{ 0.5, 0.4, 0.0}, { 0.9, 0.0, 0.0} };

GLfloat controlpts3[numcontrolpts][3] = {
   {-0.8, -0.3, 0.0}, {-0.8, -0.1, 0.0},{ -0.8, 0.1, 0.0}, { -0.8, 0.3, 0.0} };

GLfloat controlpts4[numcontrolpts][3] = {
   {-0.2, 0.05, 0.0}, {-0.2, -0.1, 0.0},{ 0.0, -0.15, 0.0}, { 0.0, 0.0, 0.0} };

GLfloat controlpts5[numcontrolpts][3] = {
   {-0.1, 0.0, 0.0}, {-0.1, -0.12, 0.0},{ 0.1, -0.2, 0.0}, { 0.1, -0.02, 0.0} };

int numdrawsegs = 52;         
const int startwinsize = 400; 

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMap1f(GL_MAP1_VERTEX_3,   
        0.0, 1.0,           
        3,                  
        numcontrolpts,     
        &controlpts1[0][0]); 
    glEnable(GL_MAP1_VERTEX_3);
    glMapGrid1d(numdrawsegs, 0.0, 1.0);
    glColor3d(0.0, 0.7, 0.0);
    glLineWidth(3.0);
    glEvalMesh1(GL_LINE, 0, numdrawsegs);

    glMap1f(GL_MAP1_VERTEX_3,
        0.0, 1.0,
        3,
        numcontrolpts,
        &controlpts2[0][0]);
    glEvalMesh1(GL_LINE, 0, numdrawsegs);

    glMap1f(GL_MAP1_VERTEX_3,
        0.0, 1.0,
        3,
        numcontrolpts,
        &controlpts3[0][0]);
    glEvalMesh1(GL_LINE, 0, numdrawsegs);

    glMap1f(GL_MAP1_VERTEX_3,
        0.0, 1.0,
        3,
        numcontrolpts,
        &controlpts4[0][0]);
    glEvalMesh1(GL_LINE, 0, numdrawsegs);

    glMap1f(GL_MAP1_VERTEX_3,
        0.0, 1.0,
        3,
        numcontrolpts,
        &controlpts5[0][0]);
    glEvalMesh1(GL_LINE, 0, numdrawsegs);

    glBegin(GL_LINE_STRIP);
    glVertex3f(0.5, -0.05, 0.0);
    glVertex3f(0.5, 0.05, 0.0);
    glVertex3f(0.6, 0.0, 0.0);
    glVertex3f(0.5, -0.05, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.665, 0.015, 0.0);
    glVertex3f(0.665, -0.015, 0.0);
    glVertex3f(0.695, -0.015, 0.0);
    glVertex3f(0.695, 0.015, 0.0);
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(startwinsize, startwinsize);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Bezier Curve - SWE1809342 / Cai Shuxian");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
