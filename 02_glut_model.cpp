#include <GL/glut.h>
#include <GL/glu.h>

void mydisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
//    glutWireCube(0.4);
    glutWireSphere(0.4, 50, 20);
    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutCreateWindow("Test");
    glutDisplayFunc(mydisplay);
    glutMainLoop();

    return 0;
}
