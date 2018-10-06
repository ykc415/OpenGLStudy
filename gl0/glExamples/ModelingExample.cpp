//
//  ModelingExample.cpp
//  gl0
//
//  Created by SungHyunPark on 2018. 10. 6..
//  Copyright © 2018년 SungHyunPark. All rights reserved.
//


#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>

int FlatShaded = 0;
int WireFramed = 0;
 // flatshading과 wireframe을 토글링하기위하 부울 변수

int ViewX = 0;
int ViewY = 0;

void InitLight() {
    GLfloat mat_diffuse[] = {0.5, 0.4, 0.3, 1.0};
    GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat mat_ambient[] = {0.5, 0.4, 0.3, 1.0};
    GLfloat mat_shininess[] = {15.0};
    
    GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0};
    GLfloat light_diffuse[] = {0.8, 0.8, 0.8, 1.0};
    GLfloat light_ambient[] = {0.3, 0.3, 0.3, 1.0};
    GLfloat light_position[] = {-3, 6, 3.0, 0.0};
    
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
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

void MyMouseMove(GLint X, GLint Y, int a, int b) {
    // 마우스 움직임 X, Y 를 전역 변수인 ViewX, ViewY에 할당
    glutPostRedisplay();
}

void MyKeyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'q':
        case 'Q':
        case '\033':
            exit(0);
            break;
            
        case 's':
            if (FlatShaded) {
                FlatShaded = 0;
                glShadeModel(GL_SMOOTH);
            }
            else {
                FlatShaded = 1;
                glShadeModel(GL_FLAT);
            }
            glutPostRedisplay();
            break;
            
        // 여기에 와이어 프레임 토글링을 위한 코드를 삽입할 것
            // 위의 전역변수 Wireframed를 사용할것
    }
}

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
//    gluLookAt(0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 1.0, 1.0, 0.0);
    // 마우스 움직임에 따라 시점을 변화시키려면
    // MyMouseMove 함수에서 입력되는 변화량을 참고하여
    // gluLookAt 명령어 파라미터를 변경해볼것
    // 아래에 필요한 물체 드로잉 명령을 삽입할것
    glutSolidTeapot(0.2); // 예
    glFlush();
}

void MyReshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Drawing Example");
    glClearColor(0.4, 0.4, 0.4, 0.0);
    InitLight();
    glutDisplayFunc(MyDisplay);
    glutKeyboardFunc(MyKeyboard);
    glutMouseFunc(MyMouseMove);
    glutReshapeFunc(MyReshape);
    glutMainLoop();
    return 0;
}








