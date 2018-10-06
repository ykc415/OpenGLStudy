//
//  DisplayListExample.cpp
//  gl0
//
//  Created by SungHyunPark on 2018. 10. 6..
//  Copyright © 2018년 SungHyunPark. All rights reserved.
//

#include <iostream>
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>

int MyListID;

void MyCreateList() {
    MyListID = glGenLists(1);
    glNewList(MyListID, GL_COMPILE);
    glBegin(GL_POLYGON);
    
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.0);
    glVertex3f(0.5, -0.5, 0.0);
    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(-0.5, 0.5, 0.0);
    
    glEnd();
    glEndList();
}

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, 300, 300);
    glCallList(MyListID);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Drawing Example");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(MyDisplay);
    MyCreateList();
    glutMainLoop();
    return 0;
}
