#include <GL/glut.h>

#define _WINDOW_HEIGHT 300
#define _WINDOW_WIDTH 300

GLfloat r = 1.0, g = 1.0, b = 1.0;
GLint pre_x = -1, pre_y = -1;
int mode_visual = 1;
int mode = 0;


void display() {
    glClear(GL_COLOR_BUFFER_BIT);
//    glViewport(0,0,100,100);
    if(mode_visual == 1) {
        if (mode == 0)
            glutWireSphere(0.3, 15, 15);
        else if (mode == 1)
            glutWireTeapot(0.7);
    }
    else {

    }
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

void mouseBtn(int btn, int states, int x, int y) {
    if(btn==GLUT_LEFT_BUTTON && states == GLUT_UP) {
//        glColor3f(1,0,0);
        g = (g - 0.1) < 0 ? 0 : g - 0.1;
        b = (b - 0.1) < 0 ? 0 : b - 0.1;
        glColor3f(r,g,b);
    }
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

void winEntry(int state) {
    if ( state == GLUT_LEFT)
        mode_visual = 0;
    else
        mode_visual = 1;
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
    glutMouseFunc(mouseBtn);
    glutMotionFunc(mouseDrag);
    glutEntryFunc(winEntry);


    glutMainLoop();
    return 0;
}