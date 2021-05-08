#include<GL/glut.h>
#include<stdlib.h>

static int day = 0,
       month = 0,
       year = 0,
       yearMars = year + 1,
       yearVenus = year + 1,
       yearJupyter = year + 1,
       yearSaturn = year + 1,
       yearUranus = year + 1,
       yearNeptune = year + 1,
       yearMercury = year + 1 ;

void init() {

    glClearColor(0.0,0.0,0.0,0.0);
    glShadeModel(GL_FLAT);

}

void display(void) {

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glRotatef((GLfloat) year, 0.0,1.0,0.0);

    // Sun
    glColor3f(3.0,3.0,1.0);
    glutWireSphere(0.7,20,15);

    // Mercury
    glRotatef((GLfloat) yearMercury, 0.0,1.0,0.0);
    glTranslatef(0.9,0.0,0.0);
    glRotatef((GLfloat) day, 0.0,1.0,0.0);
    glutWireSphere(0.08,10,8);

    glPopMatrix();
    glPushMatrix();

    // Venus
    glRotatef((GLfloat) yearVenus, 0.0,1.0,0.0);
    glTranslatef(2.0,0.0,0.0);
    glRotatef((GLfloat) day, 0.0,1.0,0.0);
    glutWireSphere(0.1,10,8);

    glPopMatrix();
    glPushMatrix();

    // Earth
    glRotatef((GLfloat) year, 0.0,1.0,0.0);
    glTranslatef(3.0,0.0,0.0);
    glRotatef((GLfloat) day, 0.0,1.0,0.0);
    glutWireSphere(0.2,10,8);

    // Moon
    glTranslatef(1.0,0.0,0.0);
    glRotatef((GLfloat) month, 0.0,1.0,0.0);
    glutWireSphere(0.07,10,5);

    glPopMatrix();
    glPushMatrix();

    // Mars
    glRotatef((GLfloat) yearMars, 0.0,1.0,0.0);
    glTranslatef(6.0,0.0,0.0);
    glRotatef((GLfloat) day, 0.0,1.0,0.0);
    glutWireSphere(0.16,10,8);

    // Deimos
    glTranslatef(0.6,0.0,0.0);
    glRotatef((GLfloat) month, 0.0,1.0,0.0);
    glutWireSphere(0.05,10,5);

    glPopMatrix();
    glPushMatrix();

    // Jupyter
    glRotatef((GLfloat) yearJupyter, 0.0,1.0,0.0);
    glTranslatef(80.,0.0,0.0);
    glRotatef((GLfloat) day, 0.0,1.0,0.0);
    glutWireSphere(0.4,10,8);

    //Genimeds
    glTranslatef(0.6,0.0,0.0);
    glRotatef((GLfloat) month, 0.3,1.0,0.0);
    glutWireSphere(0.05,10,5);

    glPopMatrix();
    glPushMatrix();

    //Saturn
    glRotatef((GLfloat) yearSaturn, 0.0,1.0,0.0);
    glTranslatef(10.0,0.0,0.0);
    glutWireSphere(0.3,10,8);

    glPopMatrix();
    glPushMatrix();

    //Uranus
    glRotatef((GLfloat) yearUranus, 0.0,1.0,0.0);
    glTranslatef(11.6,0.0,0.0);
    glRotatef((GLfloat) day, 0.0,1.0,0.0);
    glutWireSphere(0.2,10,8);

    glPopMatrix();
    glPushMatrix();

    //Neptune
    glRotatef((GLfloat) yearNeptune, 0.0,1.0,0.0);
    glTranslatef(12.5,0.0,0.0);
    glRotatef((GLfloat) day, 0.0,1.0,0.0);
    glutWireSphere(0.2,10,8);

    glPopMatrix();
    glutSwapBuffers();

}

void reshape(int w, int h) {

    glMatrixMode(GL_PROJECTION);
    gluPerspective(50.0,w/(GLfloat)h,3.0,90.0);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(2.0,4.0,20.0,0.0,0.0,0.0,0.0,1.0,0.0);

}

void pushButton(unsigned char button, int x, int y) {

    switch ((button))
    {
    case 'a':
        year = (year + 6) % 360;
        day = (day + 10) %360;
        yearMars = (yearMars + 5) % 360;
        month = (month+30) % 360;
        yearJupyter = (yearJupyter + 4) % 360;
        yearSaturn = (yearSaturn + 3) % 360;
        yearUranus = (yearUranus + 2) % 360;
        yearNeptune = (yearNeptune + 1) % 360;
        yearMercury = (yearMercury + 8) % 360;
        glutPostRedisplay();
    
    default:
        break;
    }

}

int main(int agrc, char** argv) {

    glutInit(&agrc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(800,800);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Solar System Using OpenGL");
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(pushButton);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
    return 0;

}