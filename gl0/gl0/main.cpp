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

void MyDisplay() {
    
    glClear(GL_COLOR_BUFFER_BIT);
    glViewport(0, 0, 300, 300);
    glBegin(GL_POLYGON);
    
    glVertex3d(-0.5, -0.5, 0.0);
    glVertex3d(0.5, -0.5, 0.0);
    glVertex3d(0.5, 0.5, 0.0);
    glVertex3d(-0.5, 0.5, 0.0);
    
    glEnd();
    glFlush();
}

int main(int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(300, 300);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("OpenGL Drawing Example");
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    
    return 0;
}
