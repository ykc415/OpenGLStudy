//
//  main.cpp
//  gl_example0
//
//  Created by SungHyunPark on 2018. 10. 3..
//  Copyright © 2018년 SungHyunPark. All rights reserved.
//

#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>

GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;

void MyDisplay() {
    
    glViewport(0, 0, 300, 300);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5, 0.5, 0.5);
    glBegin(GL_POLYGON);

    glVertex3f(TopLeftX/300.0, (300-TopLeftY)/300.0, 0.0);
    glVertex3f(TopLeftX/300.0, (300-BottomRightY)/300.0, 0.0);
    glVertex3f(BottomRightX/300.0, (300-BottomRightY)/300.0, 0.0);
    glVertex3f(BottomRightX/300.0, (300-TopLeftY)/300.0, 0.0);

    glEnd();
    glFlush();
}
void MyKeyboard(unsigned char KeyPressed, int X, int Y) {
    switch (KeyPressed) {
        case 'Q':
            exit(0);
            break;
        case 'q':
            exit(0);
            break;
        case 27:
            exit(0);
        default:
            break;
    }
}

void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
        TopLeftX = X;
        TopLeftY = Y;
        
        std::cout << X << "," << Y << std::endl;
    }
}

void MyMouseMove(GLint X, GLint Y) {
    BottomRightX = X;
    BottomRightY = Y;
    std::cout << X << "," << Y << std::endl;

    glutPostRedisplay();
}

int main(int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Drawing Example");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(MyDisplay);
    glutKeyboardFunc(MyKeyboard);
    glutMouseFunc(MyMouseClick);
    glutMotionFunc(MyMouseMove);
    glutMainLoop();
    
    return 0;
}
