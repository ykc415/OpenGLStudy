////
////  TransformExample.cpp
////  gl0
////
////  Created by SungHyunPark on 2018. 10. 7..
////  Copyright © 2018년 SungHyunPark. All rights reserved.
////
//
//#include <iostream>
//#include <OpenGL/gl.h>
//#include <OpenGl/glu.h>
//#include <GLUT/glut.h>
//
//void MyDisplay() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glViewport(0, 0, 300, 300);
//    glColor3f(1.0, 0.0, 0.0);
//    
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    glRotatef(45.0, 0.0, 0.0, 1.0);
//    glTranslatef(0.6, 0.0, 0.0);
//    glutSolidCube(0.3);
//    glFlush();
//}
//
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_RGBA);
//    glutInitWindowSize(300, 300);
//    glutInitWindowPosition(0, 0);
//    glutCreateWindow("OpenGL Drawing Example");
//    glClearColor(1.0, 1.0, 1.0, 1.0);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);x
//    glutDisplayFunc(MyDisplay);
//    glutMainLoop();
//    return 0;
//}
