#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

/* Global variables */
char title[] = "3D Triangle Shape Animination - SWE1809342 / Cai Shuxian";
GLfloat anglePyramid = 0.0f;  // Rotational angle for pyramid
GLint angle = 0;

static float m = 1.4 / 4.0;

static float r_xl = -1.0, r_yl = -1.0, r_zl = 1.0;
static float r_xr = 1.0, r_yr = -1.0, r_zr = 1.0;

static float b_xl = 1.0, b_yl = -1.0, b_zl = 1.0;
static float b_xr = 1.0, b_yr = -1.0, b_zr = -1.0;

static float g_xr = 1.0, g_yr = -1.0, g_zr = -1.0;
static float g_xl = -1.0, g_yl = -1.0, g_zl = -1.0;

static float y_xl = -1.0, y_yl = -1.0, y_zl = -1.0;
static float y_xr = -1.0, y_yr = -1.0, y_zr = 1.0;

/* Initialize OpenGL Graphics */
void initGL() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glClearDepth(1.0f);                   // Set background depth to farthest
    glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling 9 early pixel elimination based on depth, a method that provides an increase in performance)
    glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
    glShadeModel(GL_SMOOTH);   // Enable smooth shading
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}
/* Handler for window-repaint event. Called back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix
    // Render a pyramid consists of 4 triangles
    glLoadIdentity();                  // Reset the model-view matrix
    glTranslatef(0.0f, 0.0f, -6.0f);  // Move left and into the screen
    glRotatef(angle, 0, 1, 0);

    glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
       // Front
    glColor3f(1.0f, 0.0f, 0.0f);     // Red
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(r_xl, r_yl, r_zl);
    glVertex3f(r_xr, r_yr, r_zr);

    // Right
    glColor3f(0.0f, 0.0f, 1.0f);     // Blue
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(b_xl, b_yl, b_zl);
    glVertex3f(b_xr, b_yr, b_zr);

    // Back
    glColor3f(0.0f, 1.0f, 0.0f);     // Green
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(g_xr, g_yr, g_zr);
    glVertex3f(g_xl, g_yl, g_zl);

    // Left
    glColor3f(1.0f, 1.0f, 0.0f);       // Yellow
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(y_xl, y_yl, y_zl);
    glVertex3f(y_xr, y_yr, y_zr);
    glEnd();   // Done drawing the pyramid

    glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)

}

// Define timer function.
void timer_function(int value) {
    
    if (angle == 360) angle = 0;
    angle += 30;

    glutPostRedisplay();
    glutTimerFunc(600, timer_function, 0);
}

/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
    if (height == 0) height = 1;                // To prevent divide by 0
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    // Set the viewport to cover the new window
    glViewport(0, 0, width, height);

    // Set the aspect ratio of the clipping volume to match the viewport
    glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
    glLoadIdentity();             // Reset
    // Enable perspective projection with fovy, aspect, zNear and zFar
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
    glutInit(&argc, argv);            // Initialize GLUT
    glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
    glutInitWindowSize(640, 480);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow(title);          // Create window with the given title
    glutDisplayFunc(display);       // Register callback handler for window re-paint event
    glutTimerFunc(1, timer_function, 0);
    glutReshapeFunc(reshape);       // Register callback handler for window re-size event
    initGL();                       // Our own OpenGL initialization
    glutMainLoop();                 // Enter the infinite event-processing loop
    return 0;
}
