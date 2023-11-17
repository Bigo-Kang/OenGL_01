#include <GL/glut.h>

#define _WINDOW_WIDTH 500
#define _WINDOW_HEIGHT 500

void reshape(int,int);
void display();
void drawAxis();
void drawArrow();
void drawBody();
void drawUpperArm(GLfloat);
void drawLowerArm(GLfloat);
void drawCuboid(GLfloat,GLfloat, GLfloat);

void drawHand();

void drawFinger1();

void drawFinger2();

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
//    drawAxis();
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    drawBody();
    drawUpperArm(30);
    drawLowerArm(70);
    drawHand();

    glPushMatrix();
    drawFinger1();
    glPopMatrix();

    glPushMatrix();
    drawFinger2();
    glPopMatrix();

////    glScalef(2,1,1);
//    glRotatef(30,0,0,1);
//    glTranslatef(0.3,0,0);
////    glRotatef(30,0,0,1);
//    glScalef(2,1,1);
//    glutWireCube(0.2);

    glFlush();
}

void drawFinger2() {
    glRotatef(30,0,0,1);
    glTranslatef(0.15,0,0);
    drawCuboid(0.1,0.05,0.05);
}

void drawFinger1() {
    glTranslatef(0.15,0,0);
    drawCuboid(0.1,0.05,0.05);
}

void drawHand() {
    glTranslatef(0.35,0,0);
    glutWireSphere(0.1, 15,15);
    drawAxis();
}

// 직육면체를 그리는 함수
void drawCuboid(GLfloat sx, GLfloat sy, GLfloat sz) {
    glPushMatrix();
        glScalef(sx,sy,sz);
        glutWireCube(1);
    glPopMatrix();
}

void drawLowerArm(GLfloat angle) {
//    drawAxis();
    glTranslatef(0.25,0,0);
    glRotatef(angle,0, 0, 1);
    glTranslatef(0.25,0,0);
//    drawAxis();
    drawCuboid(0.5,0.2,0.2);
}

void drawUpperArm(GLfloat angle){
    glTranslatef(0.25,0.4,0);
    glRotatef(angle,0,0,1);
    glTranslatef(0.25,0,0);

    drawCuboid(0.5,0.2,0.2);
}
void drawBody() {
    glPushMatrix();
    glScalef(2,4,1);
    glutWireCube(0.25);
    glPopMatrix();
}

void drawAxis() {
    glColor3f(1,1,1);

    drawArrow();

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