#include <GL/glut.h>

#define _WINDOW_HEIGHT 300
#define _WINDOW_WIDTH 300

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
//    glViewport(0,0,100,100);
    glutWireSphere(0.3, 15, 15);

//    glViewport(0,100,100,100);
//    glutWireSphere(0.3, 15, 15);
//
//    glViewport(100,100,100,100);
//    glutWireSphere(0.3, 15, 15);

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

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutCreateWindow("Title");
    glutInitWindowSize(_WINDOW_WIDTH,_WINDOW_HEIGHT);
    glutDisplayFunc(display);

    glutReshapeFunc(reshape);
    glutMainLoop();
}