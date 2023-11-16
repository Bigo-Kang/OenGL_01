#include <GL/glut.h>

#define _WINDOW_WIDTH 500
#define _WINDOW_HEIGHT 500

void reshape(int,int);
void display();
void drawAxis();
void drawArrow();
void drawBody();
void drawUpperArm();


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(_WINDOW_WIDTH, _WINDOW_HEIGHT);
    glutCreateWindow("Title");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);


    glutMainLoop();
    return 0;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxis();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    drawBody();

    glPushMatrix();
    drawUpperArm();
    glPopMatrix();

////    glScalef(2,1,1);
//    glRotatef(30,0,0,1);
//    glTranslatef(0.3,0,0);
////    glRotatef(30,0,0,1);
//    glScalef(2,1,1);
//    glutWireCube(0.2);

    glFlush();
}

void drawBody() {
    glPushMatrix();
    glScalef(2,4,1);
    glutWireCube(0.25);
    glPopMatrix();
}

void drawUpperArm(){
    glTranslatef(0.25,0.4,0);
    glRotatef(30,0,0,1);
    glTranslatef(0.25,0,0);
    glScalef(2,0.8,0.8);
    glutWireCube(0.25);
}

void drawAxis() {
    glColor3f(1,1,1);

    drawArrow();
//    glRotatef(90,0,0,1);
//    drawArrow();
//    // 제자리로 돌아와야함 아니면 복합변환
//    glRotatef(-90,0,0,1);
//
//    glRotatef(90,1,0,0);
//    drawArrow();
//    glRotatef(-90,1,0,0);
    glPushMatrix();
    glRotatef(90,0,0,1);
    drawArrow();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-90,0,1,0);
    drawArrow();
    glPopMatrix();

}
void drawArrow() {
    glColor3f(1,1,1);
    glBegin(GL_LINES);
    glVertex3f(0,0,0);
    glVertex3f(0.2,0,0);
    glVertex3f(0.2,0,0);
    glVertex3f(0.14,0.06,0);
    glVertex3f(0.2,0,0);
    glVertex3f(0.14,-0.06,0);

//    glVertex3f(0,0,0);
//    glVertex3f(0,0.1,0);
//
//    glVertex3f(0,0,0);
//    glVertex3f(0,0,0.1);
    glEnd();
}

void reshape(int width, int height) {
    glViewport(0,0,width, height);
    GLfloat f_w = (GLfloat)width / (GLfloat)_WINDOW_WIDTH;
    GLfloat f_h = (GLfloat)height / (GLfloat)_WINDOW_HEIGHT;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0 * f_w, 1.0 * f_w, -1.0 * f_h, 1.0 * f_h, -2, 2);
//    gluLookAt(0.5,0.5,1,0,0,0,0,1,0);

}