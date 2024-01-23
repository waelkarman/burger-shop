
#include <iostream>
#include "book.hpp"
#include "shop.hpp"
#include <GL/glut.h>

using namespace std;

void displayMe(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glVertex3f(0.5, 0.0, 0.5);
        glVertex3f(0.5, 0.0, 0.0);
        glVertex3f(0.0, 0.5, 0.0);
        glVertex3f(0.0, 0.0, 0.5);
    glEnd();
    glFlush();
}

int main(int argv, char** args){

    // Test Book class
    Book m_book_a;
    Book m_book_b;
    Book m_book_c;
    m_book_a.setIsdn("987255324");
    m_book_a.setTitle("Il piccolo principe.");
    m_book_a.setPrice(55);

    m_book_b.setIsdn("982355324");
    m_book_b.setTitle("La guerra di piero.");
    m_book_b.setPrice(23);

    m_book_c.setIsdn("987267524");
    m_book_c.setTitle("Le mille e una notte.");
    m_book_c.setPrice(15);

    // Test Shop and Dbhelper class
    Shop m_shop;
    m_shop.insertISDN(m_book_a);
    m_shop.insertISDN(m_book_a);
    m_shop.insertISDN(m_book_a);
    m_shop.fetchAll();
    m_shop.insertISDN(m_book_b);
    m_shop.fetchAll();
    m_shop.insertISDN(m_book_c);
    m_shop.fetchAll();



    m_shop.removeISDN("982355324");
    m_shop.removeISDN("987267524");
    m_shop.fetchAll();    

    glutInit(&argv, args);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400, 300);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Hello world!");
    glutDisplayFunc(displayMe);
    glutMainLoop();

    return 0;
}