#include <GL/glut.h>
//#include <GL/gl.h>
#include <GL/glu.h>



#define _WINDOW_WIDTH 800
#define _WINDOW_HEIGHT 800

GLfloat defaultCube[8][3] = {{-0.25,-0.25,0.25},{-0.25,0.25,0.25},{0.25,0.25,0.25},{0.25,-0.25,0.25},
                            {-0.25,-0.25,-0.25},{-0.25,0.25,-0.25},{0.25,0.25,-0.25},{0.25,-0.25,-0.25}};
GLfloat MyColors[8][3] = {{0.2,0.2,0.2},{1.0,0.0,0.0},{1.0,1.0,0.0},{0.0,1.0,0.0},
                          {0.0,0.0,1.0},{1.0,0.0,1.0},{1.0,1.0,1.0},{0.0,1.0,1.0}};


void drawCube(GLfloat size, GLfloat x, GLfloat y, GLfloat z){
    GLfloat myCube[8][3];
    for (int i=0; i<8; i++){
            myCube[i][0] = size * defaultCube[i][0] + x;
            myCube[i][1] = size * defaultCube[i][1] + y;
            myCube[i][2] = size * defaultCube[i][2] + z;
    }
    int idx[6][4] = {{0,3,2,1},{2,3,7,6},{7,4,5,6},
                     {1,2,6,5},{0,3,7,4},{0,4,5,1}};

    for (int i=0; i<6; i++){
        int idx0 = idx[i][0];
        int idx1 = idx[i][1];
        int idx2 = idx[i][2];
        int idx3 = idx[i][3];

        glBegin(GL_POLYGON);
        glColor3fv(MyColors[idx0]); glVertex3fv(myCube[idx0]);
        glColor3fv(MyColors[idx1]); glVertex3fv(myCube[idx1]);
        glColor3fv(MyColors[idx2]); glVertex3fv(myCube[idx2]);
        glColor3fv(MyColors[idx3]); glVertex3fv(myCube[idx3]);
        glEnd();

    }
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT); //clear

    drawCube(0.2, 0,0,0);
    drawCube(0.2, 0.7,0,0);
    drawCube(0.2, 0,0.8,0);
    drawCube(0.2, 0.8,0.8,0.8);

    glFlush();
}

void reshape(int width, int height) {
    glViewport(0,0,width, height);
    GLfloat f_w = (GLfloat) width / (GLfloat)_WINDOW_WIDTH;
    GLfloat f_h = (GLfloat) height / (GLfloat)_WINDOW_HEIGHT;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0 * f_w, 1.0 * f_w, -1.0 * f_h, 1.0 * f_h, -2, 2);

//    gluLookAt(0.5,0.5,1,0,0,0,0,-1,0);


}


int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(_WINDOW_WIDTH,_WINDOW_HEIGHT);
    glutCreateWindow("cube");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}