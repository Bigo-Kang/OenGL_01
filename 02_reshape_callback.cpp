#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

#define _WINDOW_WIDTH 300
#define _WINDOW_HEIGHT 300

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT); // init color buffer
    glColor3f(0.5, 0.5, 0.5); // gray
    glBegin(GL_POLYGON); // square
        glVertex3f(-0.5, -0.5, 0.0); // left bottom
        glVertex3f(0.5,-0.5,0.0); //
        glVertex3f(0.5,0.5,0.0);
        glVertex3f(-0.5, 0.5,0.0);
    glEnd();
    glFlush();
}

void MyReshape(int NewWidth, int NewHeight){
    glViewport(0, 0, NewWidth, NewHeight);
    GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)_WINDOW_WIDTH;
    GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)_WINDOW_HEIGHT;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor,
            -1.0 * HeightFactor, 1.0 * HeightFactor, -1.0, 1.0);
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(_WINDOW_WIDTH, _WINDOW_HEIGHT);
    glutInitWindowPosition(0,0);
    glutCreateWindow("OpenGL Drawing Example");
    glClearColor(1.0,1.0,1.0,1.0); // init white

    glutDisplayFunc(MyDisplay);
    glutReshapeFunc(MyReshape);

    glutMainLoop();
    return 0;
}