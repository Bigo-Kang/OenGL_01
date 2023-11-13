#include <GL/glut.h>

#define _WINDOW_HEIGHT 300
#define _WINDOW_WIDTH 300

GLfloat r = 1.0, g = 1.0, b = 1.0;
GLint pre_x = -1, pre_y = -1;

int mode = 0;


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
//    glViewport(0,0,100,100);
    if (mode == 0) {

    }
    else if (mode == 1)
        glutWireSphere(0.3,15,15);
    else if (mode == 2)
        glutWireTorus(0.2,0.5,15,15);
    else
        glutWireTeapot(0.3);

    glFlush();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
//    glutWireSphere(0.3, 15, 15);
    GLfloat f_w = (GLfloat) width / (GLfloat) _WINDOW_WIDTH;
    GLfloat f_h = (GLfloat) height / (GLfloat) _WINDOW_HEIGHT;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1 * f_w, 1 * f_w, -1 * f_h, 1 * f_h, -1, 1);
}

void mouseDrag(int x, int y) {
    GLint dx, dy;
    if(pre_x >=0 || pre_y >= 0) {
        dx = abs(x - pre_x);
        dy = abs(y - pre_y);
        GLint sum = dx + dy;
        if (sum > 5) {
            mode = (mode + 1) % 2;
            glutPostRedisplay();
        }
    }
    pre_x = x;
    pre_y = y;
}

void selectMenu(int value) {
    if(value == 2)
        exit(0);
}

void selectsubMenu(int value){
    mode = value;
    glutPostRedisplay();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutCreateWindow("Title");
    glutInitWindowSize(_WINDOW_WIDTH,_WINDOW_HEIGHT);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMotionFunc(mouseDrag);

    int subMenuID = glutCreateMenu(selectsubMenu);
        glutSetMenu(subMenuID);
        glutAddMenuEntry("Sphere", 1);
        glutAddMenuEntry("Torus", 2);
        glutAddMenuEntry("Teapot", 3);

    int mainMenuID = glutCreateMenu(selectMenu);
        glutSetMenu(mainMenuID);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
        glutAddSubMenu("3D Model", subMenuID);
        glutAddMenuEntry("Exit", 2);


    glutMainLoop();
    return 0;
}