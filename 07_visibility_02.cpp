#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

GLfloat camx = 0.5, camy = 1, camz = 1.5;
GLfloat cam2x = 0, cam2y = 0, cam2z = 0;
GLfloat cam_upx = 0, cam_upy = 1, cam_upz = 0;
void InitLight(){
    GLfloat mat_diffuse[] = {0.5,0.4,0.3,1.0};
    GLfloat mat_specular[] = {1.0,1.0,1.0,1.0};
    GLfloat mat_ambient[] = {0.5,0.4,0.3,1.0};
    GLfloat mat_shininess[] = {50.0};
    GLfloat light_specular[] = {1.0,1.0,1.0,1.0};
    GLfloat light_diffuse[] = {0.8,0.8,0.8,1.0};
    GLfloat light_ambient[] = {0.3,0.3,0.3,1.0};
    GLfloat light_position[] = {-3, 2, 3.0, 0.0};

    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}

void InitVisibility(){
    glEnable(GL_CULL_FACE);
    glFrontFace(GL_CW);
    glCullFace(GL_BACK);
    glEnable(GL_DEPTH_TEST);
}

void MyDisplay(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(camx,camy,camz,cam2x,cam2y,cam2z,cam_upx,cam_upy,cam_upz);
    glutSolidTeapot(0.2);
    glFlush();
}

//void MyReshape(int w, int h) {
//    glViewport(0,0,(GLsizei)w, (GLsizei)h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glOrtho(-1.0,1.0,-1.0,1.0,-1.0,2.0);
//}

void MyReshape(int width, int height) {
    GLfloat left = 0, bottom = 0;
    glViewport(left, bottom, width - left, height - bottom);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLfloat ratio = (float)(width - left) / (height - bottom);
    gluPerspective(40, ratio, 0.1, 10);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA|GLUT_DEPTH);
    glutInitWindowSize(700,700);
    glutInitWindowPosition(50,50);
    glutCreateWindow("OpenGL Sample");
    glClearColor(0.0,0.0,0.0,0.0);
    InitLight(); // adjust light
    InitVisibility();
    glutDisplayFunc(MyDisplay);
    glutReshapeFunc(MyReshape);
    glutMainLoop();
    return 0;
}