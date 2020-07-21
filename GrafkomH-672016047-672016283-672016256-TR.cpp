#include <windows.h>
#include <stdlib.h>
#include <gl/glut.h>

void init(void);
void tampil(void);
void mouse(int button, int state, int x, int y);
void ukuran(int, int);
void mouseMotion(int x, int y);

static float apoz = 0, wpoz = 0, spoz = 0, dpoz = 0, c = 0;


float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

void init(void)
{
    glClearColor(1.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth = 1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(9.0);
    glLineWidth(6.0f);
}

void tampil(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);
    glRotatef(apoz, 0.0f, 1.0f, 0.0f);
    glRotatef(dpoz, 0.0f, -1.0f, 0.0f);
    glRotatef(wpoz, -1.0f, 0.0f, 0.0f);
    glRotatef(spoz, 1.0f, 0.0f, 0.0f);
    glRotatef(c, 0.0f, 0.0f, 1.0f);
    glPushMatrix();
   
    //depan kiri
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(45.0, -20.0, 10.0);
    glVertex3f(70.0, 0.0, 20.0);
    glVertex3f(100.0, 0.0, 5.0);
    glVertex3f(90.0, -20.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(90.0, -20.0, 0.0);
    glVertex3f(103.0, 0.0, 0.0);
    glVertex3f(100.0, 0.0, 5.0);
    glVertex3f(90.0, -20.0, 0.0);
    glEnd();

    //depan kanan
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(45.0, -20.0, -10.0);
    glVertex3f(70.0, 0.0, -20.0);
    glVertex3f(100.0, 0.0, -5.0);
    glVertex3f(90.0, -20.0, 0.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(90.0, -20.0, 0.0);
    glVertex3f(103.0, 0.0, 0.0);
    glVertex3f(100.0, 0.0, -5.0);
    glVertex3f(90.0, -20.0, 0.0);
    glEnd();
    //kiri
    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(45.0, -20.0, 10.0);
    glVertex3f(70.0, 0.0, 20.0);
    glVertex3f(45.0, 0.0, 20.0);
    glVertex3f(45.0, -20.0, 10.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(45.0, -20.0, 10.0);
    glVertex3f(45.0, -5.0, 17.0);
    glVertex3f(-100.0, -5.0, 20.0);
    glVertex3f(-100.0, -20.0, 20.0);
    glEnd();
    //kanan
    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(45.0, -20.0, -10.0);
    glVertex3f(70.0, 0.0, -20.0);
    glVertex3f(45.0, 0.0, -20.0);
    glVertex3f(45.0, -20.0, -10.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(45.0, -20.0, -10.0);
    glVertex3f(45.0, -5.0, -17.0);
    glVertex3f(-100.0, -5.0, -20.0);
    glVertex3f(-100.0, -20.0, -20.0);
    glEnd();
    //depan
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 3.9);
    glVertex3f(60.0, 20.0, 17.0);
    glVertex3f(70.0, 0.0, 17.0);
    glVertex3f(70.0, 0.0, -17.0);
    glVertex3f(60.0, 20.0, -17.0);
    glEnd();
    //lt1dpn
    glBegin(GL_QUADS);
    glColor3f(0.9, 0.9, 0.9);
    glVertex3f(70.0, -2.0, 18.0);
    glVertex3f(70.0, -2.0, -18.0);
    glVertex3f(102.0, -2.0, 0.0);
    glVertex3f(102.0, -2.0, 0.0);
    glEnd();
    
    //kacca nahkoda
    glBegin(GL_QUADS);
    glColor3f(0.9, 3.9, 0.9);
    glVertex3f(58.0, 23.0, 22.0);
    glVertex3f(58.0, 20.0, 22.0);
    glVertex3f(58.0, 20.0, -22.0);
    glVertex3f(58.0, 23.0, -22.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.9, 3.9, 0.9);
    glVertex3f(60.0, 23.0, 22.0);
    glVertex3f(60.0, 20.0, 22.0);
    glVertex3f(60.0, 20.0, -22.0);
    glVertex3f(60.0, 23.0, -22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9, 3.9, 0.9);
    glVertex3f(58.0, 23.0, 22.0);
    glVertex3f(60.0, 23.0, 22.0);
    glVertex3f(60.0, 23.0, -22.0);
    glVertex3f(58.0, 23.0, -22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9, 3.9, 0.9);
    glVertex3f(58.0, 23.0, 22.0);
    glVertex3f(60.0, 23.0, 22.0);
    glVertex3f(60.0, 20.0, 22.0);
    glVertex3f(58.0, 20.0, 22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.9, 3.9, 0.9);
    glVertex3f(58.0, 23.0, -22.0);
    glVertex3f(60.0, 23.0, -22.0);
    glVertex3f(60.0, 20.0, -22.0);
    glVertex3f(58.0, 20.0, -22.0);
    glEnd();

    //kiri tengah dan kanan
    glBegin(GL_QUADS);
    glColor3f(3.9, 3.9, 0.9);
    glVertex3f(-95.0, 20.0, 17.0);
    glVertex3f(60.0, 20.0, 17.0);
    glVertex3f(70.0, 0.0, 17.0);
    glVertex3f(-104.0, 0.0, 17.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 3.9, 0.9);
    glVertex3f(-95.0, 20.0, -17.0);
    glVertex3f(60.0, 20.0, -17.0);
    glVertex3f(70.0, 0.0, -17.0);
    glVertex3f(-104.0, 0.0, -17.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 3.9, 0.9);
    glVertex3f(-94.0, 22.0, 17.0);
    glVertex3f(60.0, 22.0, 17.0);
    glVertex3f(60.0, 20.0, 17.0);
    glVertex3f(-95.0, 20.0, 17.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 3.9, 0.9);
    glVertex3f(-94.0, 22.0, -17.0);
    glVertex3f(60.0, 22.0, -17.0);
    glVertex3f(60.0, 20.0, -17.0);
    glVertex3f(-95.0, 20.0, -17.0);
    glEnd();
    //kaca nakdoda 2
    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(60.0, 26.0, 0.0);
    glVertex3f(60.0, 23.0, 0.0);
    glVertex3f(56.0, 23.0, 20.0);
    glVertex3f(56.0, 26.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(60.0, 26.0, 0.0);
    glVertex3f(60.0, 23.0, 0.0);
    glVertex3f(56.0, 23.0, -20.0);
    glVertex3f(56.0, 26.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(58.0, 26.0, 0.0);
    glVertex3f(58.0, 23.0, 0.0);
    glVertex3f(54.0, 23.0, 17.0);
    glVertex3f(54.0, 26.0, 17.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(58.0, 26.0, 0.0);
    glVertex3f(58.0, 23.0, 0.0);
    glVertex3f(54.0, 23.0, -17.0);
    glVertex3f(54.0, 26.0, -17.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(60.0, 26.0, 0.0);
    glVertex3f(58.0, 26.0, 0.0);
    glVertex3f(53.0, 26.0, 20.0);
    glVertex3f(56.0, 26.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(60.0, 26.0, 0.0);
    glVertex3f(58.0, 26.0, 0.0);
    glVertex3f(53.0, 26.0, -20.0);
    glVertex3f(56.0, 26.0, -20.0);
    glEnd();
    //nkd samaping + kaca samping kiri

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(20.0, 26.0, 20.0);
    glVertex3f(20.0, 23.0, 20.0);
    glVertex3f(56.0, 23.0, 20.0);
    glVertex3f(56.0, 26.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(20.0, 22.0, 20.0);
    glVertex3f(20.0, 20.0, 20.0);
    glVertex3f(50.0, 20.0, 20.0);
    glVertex3f(50.0, 22.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(20.0, 19.0, 20.0);
    glVertex3f(20.0, 16.0, 20.0);
    glVertex3f(50.0, 16.0, 20.0);
    glVertex3f(50.0, 19.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(20.0, 19.0, 20.0);
    glVertex3f(20.0, 16.0, 20.0);
    glVertex3f(56.0, 16.0, 20.0);
    glVertex3f(56.0, 19.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(20.0, 15.0, 20.0);
    glVertex3f(20.0, 12.0, 20.0);
    glVertex3f(60.0, 12.0, 20.0);
    glVertex3f(60.0, 15.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(20.0, 11.0, 20.0);
    glVertex3f(20.0, 8.0, 20.0);
    glVertex3f(62.0, 8.0, 20.0);
    glVertex3f(62.0, 11.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(20.0, 7.0, 20.0);
    glVertex3f(20.0, 4.0, 20.0);
    glVertex3f(64.0, 4.0, 20.0);
    glVertex3f(64.0, 7.0, 20.0);
    glEnd();

    //nkd samaping + kaca samping kanan
    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(20.0, 26.0, 20.0);
    glVertex3f(20.0, 23.0, 20.0);
    glVertex3f(56.0, 23.0, 20.0);
    glVertex3f(56.0, 26.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(20.0, 26.0, -20.0);
    glVertex3f(20.0, 23.0, -20.0);
    glVertex3f(56.0, 23.0, -20.0);
    glVertex3f(56.0, 26.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(20.0, 22.0, -20.0);
    glVertex3f(20.0, 20.0, -20.0);
    glVertex3f(50.0, 20.0, -20.0);
    glVertex3f(50.0, 22.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(20.0, 19.0, -20.0);
    glVertex3f(20.0, 16.0, -20.0);
    glVertex3f(50.0, 16.0, -20.0);
    glVertex3f(50.0, 19.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(20.0, 19.0, -20.0);
    glVertex3f(20.0, 16.0, -20.0);
    glVertex3f(56.0, 16.0, -20.0);
    glVertex3f(56.0, 19.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(20.0, 15.0, -20.0);
    glVertex3f(20.0, 12.0, -20.0);
    glVertex3f(60.0, 12.0, -20.0);
    glVertex3f(60.0, 15.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(20.0, 11.0, -20.0);
    glVertex3f(20.0, 8.0, -20.0);
    glVertex3f(62.0, 8.0, -20.0);
    glVertex3f(62.0, 11.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(20.0, 7.0, -20.0);
    glVertex3f(20.0, 4.0, -20.0);
    glVertex3f(64.0, 4.0, -20.0);
    glVertex3f(64.0, 7.0, -20.0);
    glEnd();

    //hiasan samping atas
    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(18.0, 26.0, -24.0);
    glVertex3f(18.0, 23.0, -24.0);
    glVertex3f(20.0, 23.0, -20.0);
    glVertex3f(20.0, 26.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(16.0, 26.0, -25.0);
    glVertex3f(16.0, 23.0, -25.0);
    glVertex3f(18.0, 23.0, -24.0);
    glVertex3f(18.0, 26.0, -24.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(14.0, 26.0, -25.0);
    glVertex3f(14.0, 23.0, -25.0);
    glVertex3f(16.0, 23.0, -25.0);
    glVertex3f(16.0, 26.0, -25.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(12.0, 26.0, -24.0);
    glVertex3f(12.0, 23.0, -24.0);
    glVertex3f(14.0, 23.0, -25.0);
    glVertex3f(14.0, 26.0, -25.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(10.0, 26.0, -20.0);
    glVertex3f(10.0, 23.0, -20.0);
    glVertex3f(12.0, 23.0, -24.0);
    glVertex3f(12.0, 26.0, -24.0);
    glEnd();

    //hiasan samping
    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(18.0, 15.0, -22.0);
    glVertex3f(18.0, 12.0, -22.0);
    glVertex3f(20.0, 12.0, -20.0);
    glVertex3f(20.0, 15.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(16.0, 15.0, -23.0);
    glVertex3f(16.0, 12.0, -23.0);
    glVertex3f(18.0, 12.0, -22.0);
    glVertex3f(18.0, 15.0, -22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(14.0, 15.0, -23.0);
    glVertex3f(14.0, 12.0, -23.0);
    glVertex3f(16.0, 12.0, -23.0);
    glVertex3f(16.0, 15.0, -23.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(12.0, 15.0, -22.0);
    glVertex3f(12.0, 12.0, -22.0);
    glVertex3f(14.0, 12.0, -23.0);
    glVertex3f(14.0, 15.0, -23.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(10.0, 15.0, -20.0);
    glVertex3f(10.0, 12.0, -20.0);
    glVertex3f(12.0, 12.0, -22.0);
    glVertex3f(12.0, 15.0, -22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(-92.0, 15.0, -20.0);
    glVertex3f(-94.0, 12.0, -20.0);
    glVertex3f(10.0, 12.0, -20.0);
    glVertex3f(10.0, 15.0, -20.0);
    glEnd();

    //hiasan samping 1
    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(18.0, 22.0, -22.0);
    glVertex3f(18.0, 20.0, -22.0);
    glVertex3f(20.0, 20.0, -20.0);
    glVertex3f(20.0, 22.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(16.0, 22.0, -23.0);
    glVertex3f(16.0, 20.0, -23.0);
    glVertex3f(18.0, 20.0, -22.0);
    glVertex3f(18.0, 22.0, -22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(14.0, 22.0, -23.0);
    glVertex3f(14.0, 20.0, -23.0);
    glVertex3f(16.0, 20.0, -23.0);
    glVertex3f(16.0, 22.0, -23.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(12.0, 22.0, -22.0);
    glVertex3f(12.0, 20.0, -22.0);
    glVertex3f(14.0, 20.0, -23.0);
    glVertex3f(14.0, 22.0, -23.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(10.0, 22.0, -20.0);
    glVertex3f(10.0, 20.0, -20.0);
    glVertex3f(12.0, 20.0, -22.0);
    glVertex3f(12.0, 22.0, -22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(-88.0, 22.0, -20.0);
    glVertex3f(-89.0, 20.0, -20.0);
    glVertex3f(10.0, 20.0, -20.0);
    glVertex3f(10.0, 22.0, -20.0);
    glEnd();

    //hiasan samping 2
    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(18.0, 19.0, -22.0);
    glVertex3f(18.0, 16.0, -22.0);
    glVertex3f(20.0, 16.0, -20.0);
    glVertex3f(20.0, 19.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(16.0, 19.0, -23.0);
    glVertex3f(16.0, 16.0, -23.0);
    glVertex3f(18.0, 16.0, -22.0);
    glVertex3f(18.0, 19.0, -22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(14.0, 19.0, -23.0);
    glVertex3f(14.0, 16.0, -23.0);
    glVertex3f(16.0, 16.0, -23.0);
    glVertex3f(16.0, 19.0, -23.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(12.0, 19.0, -22.0);
    glVertex3f(12.0, 16.0, -22.0);
    glVertex3f(14.0, 16.0, -23.0);
    glVertex3f(14.0, 19.0, -23.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(10.0, 19.0, -20.0);
    glVertex3f(10.0, 16.0, -20.0);
    glVertex3f(12.0, 16.0, -22.0);
    glVertex3f(12.0, 19.0, -22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(-89.0, 19.0, -20.0);
    glVertex3f(-91.0, 16.0, -20.0);
    glVertex3f(10.0, 16.0, -20.0);
    glVertex3f(10.0, 19.0, -20.0);
    glEnd();

    //hiasan samping 3
    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(18.0, 11.0, -22.0);
    glVertex3f(18.0, 8.0, -22.0);
    glVertex3f(20.0, 8.0, -20.0);
    glVertex3f(20.0, 11.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(16.0, 11.0, -23.0);
    glVertex3f(16.0, 8.0, -23.0);
    glVertex3f(18.0, 8.0, -22.0);
    glVertex3f(18.0, 11.0, -22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(14.0, 11.0, -23.0);
    glVertex3f(14.0, 8.0, -23.0);
    glVertex3f(16.0, 8.0, -23.0);
    glVertex3f(16.0, 11.0, -23.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(12.0, 11.0, -22.0);
    glVertex3f(12.0, 8.0, -22.0);
    glVertex3f(14.0, 8.0, -23.0);
    glVertex3f(14.0, 11.0, -23.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(10.0, 11.0, -20.0);
    glVertex3f(10.0, 8.0, -20.0);
    glVertex3f(12.0, 8.0, -22.0);
    glVertex3f(12.0, 11.0, -22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(-94.0, 11.0, -20.0);
    glVertex3f(-96.0, 8.0, -20.0);
    glVertex3f(10.0, 8.0, -20.0);
    glVertex3f(10.0, 11.0, -20.0);
    glEnd();

    //hiasan samping 4
    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(18.0, 7.0, -22.0);
    glVertex3f(18.0, 4.0, -22.0);
    glVertex3f(20.0, 4.0, -20.0);
    glVertex3f(20.0, 7.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(16.0, 7.0, -23.0);
    glVertex3f(16.0, 4.0, -23.0);
    glVertex3f(18.0, 4.0, -22.0);
    glVertex3f(18.0, 7.0, -22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(14.0, 7.0, -23.0);
    glVertex3f(14.0, 4.0, -23.0);
    glVertex3f(16.0, 4.0, -23.0);
    glVertex3f(16.0, 7.0, -23.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(12.0, 7.0, -22.0);
    glVertex3f(12.0, 4.0, -22.0);
    glVertex3f(14.0, 4.0, -23.0);
    glVertex3f(14.0, 7.0, -23.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(10.0, 7.0, -20.0);
    glVertex3f(10.0, 4.0, -20.0);
    glVertex3f(12.0, 4.0, -22.0);
    glVertex3f(12.0, 7.0, -22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(-97.0, 7.0, -20.0);
    glVertex3f(-95.0, 4.0, -20.0);
    glVertex3f(10.0, 4.0, -20.0);
    glVertex3f(10.0, 7.0, -20.0);
    glEnd();


    //hiasan samping atas kiri
    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(18.0, 26.0, 24.0);
    glVertex3f(18.0, 23.0, 24.0);
    glVertex3f(20.0, 23.0, 20.0);
    glVertex3f(20.0, 26.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(16.0, 26.0, 25.0);
    glVertex3f(16.0, 23.0, 25.0);
    glVertex3f(18.0, 23.0, 24.0);
    glVertex3f(18.0, 26.0, 24.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(14.0, 26.0, 25.0);
    glVertex3f(14.0, 23.0, 25.0);
    glVertex3f(16.0, 23.0, 25.0);
    glVertex3f(16.0, 26.0, 25.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(12.0, 26.0, 24.0);
    glVertex3f(12.0, 23.0, 24.0);
    glVertex3f(14.0, 23.0, 25.0);
    glVertex3f(14.0, 26.0, 25.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(10.0, 26.0, 20.0);
    glVertex3f(10.0, 23.0, 20.0);
    glVertex3f(12.0, 23.0, 24.0);
    glVertex3f(12.0, 26.0, 24.0);
    glEnd();


    //hiasan samping 1 kiri
    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(18.0, 22.0, 22.0);
    glVertex3f(18.0, 20.0, 22.0);
    glVertex3f(20.0, 20.0, 20.0);
    glVertex3f(20.0, 22.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(16.0, 22.0, 23.0);
    glVertex3f(16.0, 20.0, 23.0);
    glVertex3f(18.0, 20.0, 22.0);
    glVertex3f(18.0, 22.0, 22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(14.0, 22.0, 23.0);
    glVertex3f(14.0, 20.0, 23.0);
    glVertex3f(16.0, 20.0, 23.0);
    glVertex3f(16.0, 22.0, 23.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(12.0, 22.0, 22.0);
    glVertex3f(12.0, 20.0, 22.0);
    glVertex3f(14.0, 20.0, 23.0);
    glVertex3f(14.0, 22.0, 23.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(10.0, 22.0, 20.0);
    glVertex3f(10.0, 20.0, 20.0);
    glVertex3f(12.0, 20.0, 22.0);
    glVertex3f(12.0, 22.0, 22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(-88.0, 22.0, 20.0);
    glVertex3f(-88.0, 20.0, 20.0);
    glVertex3f(10.0, 20.0, 20.0);
    glVertex3f(10.0, 22.0, 20.0);
    glEnd();

    //hiasan samping 2 kiri
    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(18.0, 19.0, 22.0);
    glVertex3f(18.0, 16.0, 22.0);
    glVertex3f(20.0, 16.0, 20.0);
    glVertex3f(20.0, 19.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(16.0, 19.0, 23.0);
    glVertex3f(16.0, 16.0, 23.0);
    glVertex3f(18.0, 16.0, 22.0);
    glVertex3f(18.0, 19.0, 22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(14.0, 19.0, 23.0);
    glVertex3f(14.0, 16.0, 23.0);
    glVertex3f(16.0, 16.0, 23.0);
    glVertex3f(16.0, 19.0, 23.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(12.0, 19.0, 22.0);
    glVertex3f(12.0, 16.0, 22.0);
    glVertex3f(14.0, 16.0, 23.0);
    glVertex3f(14.0, 19.0, 23.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(10.0, 19.0, 20.0);
    glVertex3f(10.0, 16.0, 20.0);
    glVertex3f(12.0, 16.0, 22.0);
    glVertex3f(12.0, 19.0, 22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(-90.0, 19.0, 20.0);
    glVertex3f(-90.0, 16.0, 20.0);
    glVertex3f(10.0, 16.0, 20.0);
    glVertex3f(10.0, 19.0, 20.0);
    glEnd();

    //hiasan samping 3 kiri
    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(18.0, 11.0, 22.0);
    glVertex3f(18.0, 8.0, 22.0);
    glVertex3f(20.0, 8.0, 20.0);
    glVertex3f(20.0, 11.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(16.0, 11.0, 23.0);
    glVertex3f(16.0, 8.0, 23.0);
    glVertex3f(18.0, 8.0, 22.0);
    glVertex3f(18.0, 11.0, 22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(14.0, 11.0, 23.0);
    glVertex3f(14.0, 8.0, 23.0);
    glVertex3f(16.0, 8.0, 23.0);
    glVertex3f(16.0, 11.0, 23.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(12.0, 11.0, 22.0);
    glVertex3f(12.0, 8.0, 22.0);
    glVertex3f(14.0, 8.0, 23.0);
    glVertex3f(14.0, 11.0, 23.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(10.0, 11.0, 20.0);
    glVertex3f(10.0, 8.0, 20.0);
    glVertex3f(12.0, 8.0, 22.0);
    glVertex3f(12.0, 11.0, 22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(-94.0, 11.0, 20.0);
    glVertex3f(-94.0, 8.0, 20.0);
    glVertex3f(10.0, 8.0, 20.0);
    glVertex3f(10.0, 11.0, 20.0);
    glEnd();

    //hiasan samping 4 kiri
    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(18.0, 7.0, 22.0);
    glVertex3f(18.0, 4.0, 22.0);
    glVertex3f(20.0, 4.0, 20.0);
    glVertex3f(20.0, 7.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(16.0, 7.0, 23.0);
    glVertex3f(16.0, 4.0, 23.0);
    glVertex3f(18.0, 4.0, 22.0);
    glVertex3f(18.0, 7.0, 22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(14.0, 7.0, 23.0);
    glVertex3f(14.0, 4.0, 23.0);
    glVertex3f(16.0, 4.0, 23.0);
    glVertex3f(16.0, 7.0, 23.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(12.0, 7.0, 22.0);
    glVertex3f(12.0, 4.0, 22.0);
    glVertex3f(14.0, 4.0, 23.0);
    glVertex3f(14.0, 7.0, 23.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(10.0, 7.0, 20.0);
    glVertex3f(10.0, 4.0, 20.0);
    glVertex3f(12.0, 4.0, 22.0);
    glVertex3f(12.0, 7.0, 22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(-96.0, 7.0, 20.0);
    glVertex3f(-96.0, 4.0, 20.0);
    glVertex3f(10.0, 4.0, 20.0);
    glVertex3f(10.0, 7.0, 20.0);
    glEnd();

    //hiasan samping kiri
    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(18.0, 15.0, 22.0);
    glVertex3f(18.0, 12.0, 22.0);
    glVertex3f(20.0, 12.0, 20.0);
    glVertex3f(20.0, 15.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(16.0, 15.0, 23.0);
    glVertex3f(16.0, 12.0, 23.0);
    glVertex3f(18.0, 12.0, 22.0);
    glVertex3f(18.0, 15.0, 22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(14.0, 15.0, 23.0);
    glVertex3f(14.0, 12.0, 23.0);
    glVertex3f(16.0, 12.0, 23.0);
    glVertex3f(16.0, 15.0, 23.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(12.0, 15.0, 22.0);
    glVertex3f(12.0, 12.0, 22.0);
    glVertex3f(14.0, 12.0, 23.0);
    glVertex3f(14.0, 15.0, 23.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(10.0, 15.0, 20.0);
    glVertex3f(10.0, 12.0, 20.0);
    glVertex3f(12.0, 12.0, 22.0);
    glVertex3f(12.0, 15.0, 22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(-92.0, 15.0, 20.0);
    glVertex3f(-92.0, 12.0, 20.0);
    glVertex3f(10.0, 12.0, 20.0);
    glVertex3f(10.0, 15.0, 20.0);
    glEnd();

    //kaca belakang
    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(-94.0, 22.0, 17.0);
    glVertex3f(-94.0, 20.0, 17.0);
    glVertex3f(-94.0, 20.0, -17.0);
    glVertex3f(-94.0, 22.0, -17.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(-94.0, 15.0, 17.0);
    glVertex3f(-94.0, 12.0, 17.0);
    glVertex3f(-94.0, 12.0, -17.0);
    glVertex3f(-94.0, 15.0, -17.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(-94.0, 7.0, 17.0);
    glVertex3f(-94.0, 4.0, 17.0);
    glVertex3f(-94.0, 4.0, -17.0);
    glVertex3f(-94.0, 7.0, -17.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(-94.0, 11.0, 17.0);
    glVertex3f(-94.0, 8.0, 17.0);
    glVertex3f(-94.0, 8.0, -17.0);
    glVertex3f(-94.0, 11.0, -17.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(-94.0, 19.0, 17.0);
    glVertex3f(-94.0, 16.0, 17.0);
    glVertex3f(-94.0, 16.0, -17.0);
    glVertex3f(-94.0, 19.0, -17.0);
    glEnd();

    //Kaca nahkoda belakang tutp atas
    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-103.0, 26.0, 9.0);
    glVertex3f(-83.0, 26.0, 9.0);
    glVertex3f(-83.0, 26.0, -9.0);
    glVertex3f(-103.0, 26.0, -9.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-98.5, 26.0, -19.0);
    glVertex3f(-83.0, 26.0, -19.0);
    glVertex3f(-83.0, 26.0, -9.0);
    glVertex3f(-103.0, 26.0, -9.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-95.0, 26.0, -22.0);
    glVertex3f(-83.0, 26.0, -22.0);
    glVertex3f(-83.0, 26.0, -19.0);
    glVertex3f(-98.5, 26.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-98.5, 26.0, 19.0);
    glVertex3f(-83.0, 26.0, 19.0);
    glVertex3f(-83.0, 26.0, 9.0);
    glVertex3f(-103.0, 26.0, 9.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-95.0, 26.0, 22.0);
    glVertex3f(-83.0, 26.0, 22.0);
    glVertex3f(-83.0, 26.0, 19.0);
    glVertex3f(-98.5, 26.0, 19.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-95.0, 26.0, 20.0);
    glVertex3f(53.0, 26.0, 20.0);
    glVertex3f(53.0, 26.0, -20.0);
    glVertex3f(-98.5, 26.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(53.0, 26.0, 0.0);
    glVertex3f(58.0, 26.0, 0.0);
    glVertex3f(53.0, 26.0, -20.0);
    glVertex3f(53.0, 26.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(53.0, 26.0, 0.0);
    glVertex3f(58.0, 26.0, 0.0);
    glVertex3f(53.0, 26.0, 20.0);
    glVertex3f(53.0, 26.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-100.0, -18.0, 20.0);
    glVertex3f(45.0, -18.0, 11.0);
    glVertex3f(45.0, -18.0, -11.0);
    glVertex3f(-100.0, -18.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(45.0, -18.0, 11.0);
    glVertex3f(90.0, -18.0, 0.0);
    glVertex3f(90.0, -18.0, 0.0);
    glVertex3f(45.0, -18.0, -11.0);
    glEnd();


    //Kaca nahkoda belakang 
    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-103.0, 26.0, 9.0);
    glVertex3f(-103.0, 23.0, 9.0);
    glVertex3f(-103.0, 23.0, -9.0);
    glVertex3f(-103.0, 26.0, -9.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-98.5, 26.0, -19.0);
    glVertex3f(-98.5, 23.0, -19.0);
    glVertex3f(-103.0, 23.0, -9.0);
    glVertex3f(-103.0, 26.0, -9.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-95.0, 26.0, -22.0);
    glVertex3f(-95.0, 23.0, -22.0);
    glVertex3f(-98.5, 23.0, -19.0);
    glVertex3f(-98.5, 26.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-85.0, 26.0, -22.0);
    glVertex3f(-85.0, 23.0, -22.0);
    glVertex3f(-95.0, 23.0, -22.0);
    glVertex3f(-95.0, 26.0, -22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-85.0, 26.0, -22.0);
    glVertex3f(-85.0, 23.0, -22.0);
    glVertex3f(-83.0, 23.0, -20.0);
    glVertex3f(-83.0, 26.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(10.0, 26.0, -20.0);
    glVertex3f(10.0, 23.0, -20.0);
    glVertex3f(-83.0, 23.0, -20.0);
    glVertex3f(-83.0, 26.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-98.5, 26.0, 19.0);
    glVertex3f(-98.5, 23.0, 19.0);
    glVertex3f(-103.0, 23.0, 9.0);
    glVertex3f(-103.0, 26.0, 9.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-95.0, 26.0, 22.0);
    glVertex3f(-95.0, 23.0, 22.0);
    glVertex3f(-98.5, 23.0, 19.0);
    glVertex3f(-98.5, 26.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-85.0, 26.0, 22.0);
    glVertex3f(-85.0, 23.0, 22.0);
    glVertex3f(-95.0, 23.0, 22.0);
    glVertex3f(-95.0, 26.0, 22.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-85.0, 26.0, 22.0);
    glVertex3f(-85.0, 23.0, 22.0);
    glVertex3f(-83.0, 23.0, 20.0);
    glVertex3f(-83.0, 26.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(10.0, 26.0, 20.0);
    glVertex3f(10.0, 23.0, 20.0);
    glVertex3f(-83.0, 23.0, 20.0);
    glVertex3f(-83.0, 26.0, 20.0);
    glEnd();



    
    //rangka belakang 2
    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-103.0, 16.0, 4.0);
    glVertex3f(-103.0, 15.0, 4.0);
    glVertex3f(-103.0, 15.0, -4.0);
    glVertex3f(-103.0, 16.0, -4.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-101.5, 16.0, -12.0);
    glVertex3f(-101.5, 15.0, -12.0);
    glVertex3f(-103.0, 15.0, -4.0);
    glVertex3f(-103.0, 16.0, -4.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-97.0, 16.0, -17.0);
    glVertex3f(-97.0, 15.0, -17.0);
    glVertex3f(-101.5, 15.0, -12.0);
    glVertex3f(-101.5, 16.0, -12.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-101.5, 16.0, 12.0);
    glVertex3f(-101.5, 15.0, 12.0);
    glVertex3f(-103.0, 15.0, 4.0);
    glVertex3f(-103.0, 16.0, 4.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-97.0, 16.0, 17.0);
    glVertex3f(-97.0, 15.0, 17.0);
    glVertex3f(-101.5, 15.0, 12.0);
    glVertex3f(-101.5, 16.0, 12.0);
    glEnd();
    //rangka belakang 3
    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-106.0, 12.0, 4.0);
    glVertex3f(-106.0, 11.0, 4.0);
    glVertex3f(-106.0, 11.0, -4.0);
    glVertex3f(-106.0, 12.0, -4.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-103.5, 12.0, -12.0);
    glVertex3f(-103.5, 11.0, -12.0);
    glVertex3f(-106.0, 11.0, -4.0);
    glVertex3f(-106.0, 12.0, -4.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-98.0, 12.0, -17.0);
    glVertex3f(-98.0, 11.0, -17.0);
    glVertex3f(-103.5, 11.0, -12.0);
    glVertex3f(-103.5, 12.0, -12.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-103.5, 12.0, 12.0);
    glVertex3f(-103.5, 11.0, 12.0);
    glVertex3f(-106.0, 11.0, 4.0);
    glVertex3f(-106.0, 12.0, 4.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-98.0, 12.0, 17.0);
    glVertex3f(-98.0, 11.0, 17.0);
    glVertex3f(-103.5, 11.0, 12.0);
    glVertex3f(-103.5, 12.0, 12.0);
    glEnd();

    //rangka belakang 4
    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-109.0, 8.0, 4.0);
    glVertex3f(-109.0, 7.0, 4.0);
    glVertex3f(-109.0, 7.0, -4.0);
    glVertex3f(-109.0, 8.0, -4.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-105.5, 8.0, -12.0);
    glVertex3f(-105.5, 7.0, -12.0);
    glVertex3f(-109.0, 7.0, -4.0);
    glVertex3f(-109.0, 8.0, -4.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-99.0, 8.0, -17.0);
    glVertex3f(-99.0, 7.0, -17.0);
    glVertex3f(-105.5, 7.0, -12.0);
    glVertex3f(-105.5, 8.0, -12.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-105.5, 8.0, 12.0);
    glVertex3f(-105.5, 7.0, 12.0);
    glVertex3f(-109.0, 7.0, 4.0);
    glVertex3f(-109.0, 8.0, 4.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-99.0, 8.0, 17.0);
    glVertex3f(-99.0, 7.0, 17.0);
    glVertex3f(-105.5, 7.0, 12.0);
    glVertex3f(-105.5, 8.0, 12.0);
    glEnd();

    //rangka belakang 4
    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-112.0, 4.0, 4.0);
    glVertex3f(-112.0, 3.0, 4.0);
    glVertex3f(-112.0, 3.0, -4.0);
    glVertex3f(-112.0, 4.0, -4.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-107.5, 4.0, -12.0);
    glVertex3f(-107.5, 3.0, -12.0);
    glVertex3f(-112.0, 3.0, -4.0);
    glVertex3f(-112.0, 4.0, -4.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-100.0, 4.0, -17.0);
    glVertex3f(-100.0, 3.0, -17.0);
    glVertex3f(-107.5, 3.0, -12.0);
    glVertex3f(-107.5, 4.0, -12.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-107.5, 4.0, 12.0);
    glVertex3f(-107.5, 3.0, 12.0);
    glVertex3f(-112.0, 3.0, 4.0);
    glVertex3f(-112.0, 4.0, 4.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-100.0, 4.0, 17.0);
    glVertex3f(-100.0, 3.0, 17.0);
    glVertex3f(-107.5, 3.0, 12.0);
    glVertex3f(-107.5, 4.0, 12.0);
    glEnd();

    //rangka belakang 5
    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-115.0, 0.0, 4.0);
    glVertex3f(-115.0, -1.0, 4.0);
    glVertex3f(-115.0, -1.0, -4.0);
    glVertex3f(-115.0, 0.0, -4.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-109.5, 0.0, -12.0);
    glVertex3f(-109.5, -1.0, -12.0);
    glVertex3f(-115.0, -1.0, -4.0);
    glVertex3f(-115.0, 0.0, -4.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-102.0, 0.0, -17.0);
    glVertex3f(-102.0, -1.0, -17.0);
    glVertex3f(-109.5, -1.0, -12.0);
    glVertex3f(-109.5, 0.0, -12.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-109.5, 0.0, 12.0);
    glVertex3f(-109.5, -1.0, 12.0);
    glVertex3f(-115.0, -1.0, 4.0);
    glVertex3f(-115.0, 0.0, 4.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-102.0, 0.0, 17.0);
    glVertex3f(-102.0, -1.0, 17.0);
    glVertex3f(-109.5, -1.0, 12.0);
    glVertex3f(-109.5, 0.0, 12.0);
    glEnd();

    //rangka belakang 6
    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-118.0, -20.0, 4.0);
    glVertex3f(-118.0, -3.0, 4.0);
    glVertex3f(-118.0, -3.0, -4.0);
    glVertex3f(-118.0, -20.0, -4.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-111.5, -20.0, -13.0);
    glVertex3f(-111.5, -3.0, -13.0);
    glVertex3f(-118.0, -3.0, -4.0);
    glVertex3f(-118.0, -20.0, -4.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-100.0, -20.0, -20.0);
    glVertex3f(-100.0, -3.0, -20.0);
    glVertex3f(-111.5, -3.0, -13.0);
    glVertex3f(-111.5, -20.0, -13.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-111.5, -20.0, 13.0);
    glVertex3f(-111.5, -3.0, 13.0);
    glVertex3f(-118.0, -3.0, 4.0);
    glVertex3f(-118.0, -20.0, 4.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-100.0, -20.0, 20.0);
    glVertex3f(-100.0, -3.0, 20.0);
    glVertex3f(-111.5, -3.0, 13.0);
    glVertex3f(-111.5, -20.0, 13.0);
    glEnd();

    //rangka belakang 7
    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-122.0, -20.0, 9.0);
    glVertex3f(-122.0, -18.0, 9.0);
    glVertex3f(-122.0, -18.0, -9.0);
    glVertex3f(-122.0, -20.0, -9.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-118.5, -20.0, -15.0);
    glVertex3f(-118.5, -18.0, -15.0);
    glVertex3f(-122.0, -18.0, -9.0);
    glVertex3f(-122.0, -20.0, -9.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-100.0, -20.0, -20.0);
    glVertex3f(-100.0, -18.0, -20.0);
    glVertex3f(-118.5, -18.0, -15.0);
    glVertex3f(-118.5, -20.0, -15.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-118.5, -20.0, 15.0);
    glVertex3f(-118.5, -18.0, 15.0);
    glVertex3f(-122.0, -18.0, 9.0);
    glVertex3f(-122.0, -20.0, 9.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-100.0, -20.0, 20.0);
    glVertex3f(-100.0, -18.0, 20.0);
    glVertex3f(-118.5, -18.0, 15.0);
    glVertex3f(-118.5, -20.0, 15.0);
    glEnd();

    

    //rangka belakang 8 landasan blkng
    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-122.0, -20.0, 9.0);
    glVertex3f(-100.0, -20.0, 9.0);
    glVertex3f(-100.0, -20.0, -9.0);
    glVertex3f(-122.0, -20.0, -9.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-119.0, -20.0, -15.0);
    glVertex3f(-100.0, -20.0, -15.0);
    glVertex3f(-100.0, -20.0, -9.0);
    glVertex3f(-122.0, -20.0, -9.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-118.0, -20.0, -15.0);
    glVertex3f(-100.0, -20.0, -20.0);
    glVertex3f(-100.0, -20.0, -15.0);
    glVertex3f(-116.0, -20.0, -15.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-119.0, -20.0, 15.0);
    glVertex3f(-100.0, -20.0, 15.0);
    glVertex3f(-100.0, -20.0, 9.0);
    glVertex3f(-122.0, -20.0, 9.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-118.0, -20.0, 15.0);
    glVertex3f(-100.0, -20.0, 20.0);
    glVertex3f(-100.0, -20.0, 15.0);
    glVertex3f(-116.0, -20.0, 15.0);
    glEnd();

    //rangka belakang 8 landasan blkng atas
    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-122.0, -18.0, 9.0);
    glVertex3f(-100.0, -18.0, 9.0);
    glVertex3f(-100.0, -18.0, -9.0);
    glVertex3f(-122.0, -18.0, -9.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-119.0, -18.0, -15.0);
    glVertex3f(-100.0, -18.0, -15.0);
    glVertex3f(-100.0, -18.0, -9.0);
    glVertex3f(-121.0, -18.0, -9.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-118.0, -18.0, -15.0);
    glVertex3f(-100.0, -18.0, -20.0);
    glVertex3f(-100.0, -18.0, -15.0);
    glVertex3f(-116.0, -18.0, -15.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-119.0, -18.0, 15.0);
    glVertex3f(-100.0, -18.0, 15.0);
    glVertex3f(-100.0, -18.0, 9.0);
    glVertex3f(-121.0, -18.0, 9.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 0.9, 0.9);
    glVertex3f(-118.0, -18.0, 15.0);
    glVertex3f(-100.0, -18.0, 20.0);
    glVertex3f(-100.0, -18.0, 15.0);
    glVertex3f(-116.0, -18.0, 15.0);
    glEnd();


    // hiasannnnnn
    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(50.0, 22.0, -17.0);
    glVertex3f(51.0, 21.0, -17.0);
    glVertex3f(51.0, 21.0, -20.0);
    glVertex3f(50.0, 22.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(51.0, 21.0, -17.0);
    glVertex3f(51.0, 20.0, -17.0);
    glVertex3f(51.0, 20.0, -20.0);
    glVertex3f(51.0, 21.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(56.0, 19.0, -17.0);
    glVertex3f(57.0, 18.0, -17.0);
    glVertex3f(57.0, 18.0, -20.0);
    glVertex3f(56.0, 19.0, -20.0);
    glEnd();
   
    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(57.0, 18.0, -17.0);
    glVertex3f(57.0, 17.0, -17.0);
    glVertex3f(57.0, 17.0, -20.0);
    glVertex3f(57.0, 18.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(57.0, 17.0, -17.0);
    glVertex3f(56.0, 16.0, -17.0);
    glVertex3f(56.0, 16.0, -20.0);
    glVertex3f(57.0, 17.0, -20.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(60.0, 15.0, -17.0);
    glVertex3f(61.0, 14.0, -17.0);
    glVertex3f(61.0, 14.0, -20.0);
    glVertex3f(60.0, 15.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(61.0, 14.0, -17.0);
    glVertex3f(61.0, 13.0, -17.0);
    glVertex3f(61.0, 13.0, -20.0);
    glVertex3f(61.0, 14.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(61.0, 13.0, -17.0);
    glVertex3f(60.0, 12.0, -17.0);
    glVertex3f(60.0, 12.0, -20.0);
    glVertex3f(61.0, 13.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(62.0, 11.0, -17.0);
    glVertex3f(63.0, 10.0, -17.0);
    glVertex3f(63.0, 10.0, -20.0);
    glVertex3f(62.0, 11.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(63.0, 10.0, -17.0);
    glVertex3f(63.0, 9.0, -17.0);
    glVertex3f(63.0, 9.0, -20.0);
    glVertex3f(63.0, 10.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(63.0, 9.0, -17.0);
    glVertex3f(62.0, 8.0, -17.0);
    glVertex3f(62.0, 8.0, -20.0);
    glVertex3f(63.0, 9.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(64.0, 7.0, -17.0);
    glVertex3f(65.0, 6.0, -17.0);
    glVertex3f(65.0, 6.0, -20.0);
    glVertex3f(64.0, 7.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(65.0, 6.0, -17.0);
    glVertex3f(65.0, 5.0, -17.0);
    glVertex3f(65.0, 5.0, -20.0);
    glVertex3f(65.0, 6.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(65.0, 5.0, -17.0);
    glVertex3f(64.0, 4.0, -17.0);
    glVertex3f(64.0, 4.0, -20.0);
    glVertex3f(65.0, 5.0, -20.0);
    glEnd();

    // hiasannnnnn kiri
    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(50.0, 22.0, 17.0);
    glVertex3f(51.0, 21.0, 17.0);
    glVertex3f(51.0, 21.0, 20.0);
    glVertex3f(50.0, 22.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(51.0, 21.0, 17.0);
    glVertex3f(51.0, 20.0, 17.0);
    glVertex3f(51.0, 20.0, 20.0);
    glVertex3f(51.0, 21.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(56.0, 19.0, 17.0);
    glVertex3f(57.0, 18.0, 17.0);
    glVertex3f(57.0, 18.0, 20.0);
    glVertex3f(56.0, 19.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(57.0, 18.0, 17.0);
    glVertex3f(57.0, 17.0, 17.0);
    glVertex3f(57.0, 17.0, 20.0);
    glVertex3f(57.0, 18.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(57.0, 17.0, 17.0);
    glVertex3f(56.0, 16.0, 17.0);
    glVertex3f(56.0, 16.0, 20.0);
    glVertex3f(57.0, 17.0, 20.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(60.0, 15.0, 17.0);
    glVertex3f(61.0, 14.0, 17.0);
    glVertex3f(61.0, 14.0, 20.0);
    glVertex3f(60.0, 15.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(61.0, 14.0, 17.0);
    glVertex3f(61.0, 13.0, 17.0);
    glVertex3f(61.0, 13.0, 20.0);
    glVertex3f(61.0, 14.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(61.0, 13.0, 17.0);
    glVertex3f(60.0, 12.0, 17.0);
    glVertex3f(60.0, 12.0, 20.0);
    glVertex3f(61.0, 13.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(62.0, 11.0, 17.0);
    glVertex3f(63.0, 10.0, 17.0);
    glVertex3f(63.0, 10.0, 20.0);
    glVertex3f(62.0, 11.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(63.0, 10.0, 17.0);
    glVertex3f(63.0, 9.0, 17.0);
    glVertex3f(63.0, 9.0, 20.0);
    glVertex3f(63.0, 10.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(63.0, 9.0, 17.0);
    glVertex3f(62.0, 8.0, 17.0);
    glVertex3f(62.0, 8.0, 20.0);
    glVertex3f(63.0, 9.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(64.0, 7.0, 17.0);
    glVertex3f(65.0, 6.0, 17.0);
    glVertex3f(65.0, 6.0, 20.0);
    glVertex3f(64.0, 7.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(65.0, 6.0, 17.0);
    glVertex3f(65.0, 5.0, 17.0);
    glVertex3f(65.0, 5.0, 20.0);
    glVertex3f(65.0, 6.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(65.0, 5.0, 17.0);
    glVertex3f(64.0, 4.0, 17.0);
    glVertex3f(64.0, 4.0, 20.0);
    glVertex3f(65.0, 5.0, 20.0);
    glEnd();

    //hiasannnn blkang kanan
    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-88.0, 22.0, -17.0);
    glVertex3f(-98.0, 5.0, -17.0);
    glVertex3f(-98.0, 5.0, -20.0);
    glVertex3f(-88.0, 22.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-98.0, 5.0, -17.0);
    glVertex3f(-95.0, 4.0, -17.0);
    glVertex3f(-95.0, 4.0, -20.0);
    glVertex3f(-98.0, 5.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-95.0, 4.0, -17.0);
    glVertex3f(64.0, 4.0, -17.0);
    glVertex3f(64.0, 4.0, -20.0);
    glVertex3f(-95.0, 4.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-88.0, 22.0, -17.0);
    glVertex3f(50.0, 22.0, -17.0);
    glVertex3f(50.0, 22.0, -20.0);
    glVertex3f(-88.0, 22.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-88.0, 20.0, -17.0);
    glVertex3f(50.0, 20.0, -17.0);
    glVertex3f(50.0, 20.0, -20.0);
    glVertex3f(-88.0, 20.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-90.0, 19.0, -17.0);
    glVertex3f(56.0, 19.0, -17.0);
    glVertex3f(56.0, 19.0, -20.0);
    glVertex3f(-90.0, 19.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-92.0, 15.0, -17.0);
    glVertex3f(60.0, 15.0, -17.0);
    glVertex3f(60.0, 15.0, -20.0);
    glVertex3f(-92.0, 15.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-94.0, 11.0, -17.0);
    glVertex3f(62.0, 11.0, -17.0);
    glVertex3f(62.0, 11.0, -20.0);
    glVertex3f(-94.0, 11.0, -20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-96.0, 7.0, -17.0);
    glVertex3f(64.0, 7.0, -17.0);
    glVertex3f(64.0, 7.0, -20.0);
    glVertex3f(-96.0, 7.0, -20.0);
    glEnd();

    //hiasannnn blkang kiri
    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-88.0, 22.0, 17.0);
    glVertex3f(-98.0, 5.0, 17.0);
    glVertex3f(-98.0, 5.0, 20.0);
    glVertex3f(-88.0, 22.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-98.0, 5.0, 17.0);
    glVertex3f(-95.0, 4.0, 17.0);
    glVertex3f(-95.0, 4.0, 20.0);
    glVertex3f(-98.0, 5.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-95.0, 4.0, 17.0);
    glVertex3f(64.0, 4.0, 17.0);
    glVertex3f(64.0, 4.0, 20.0);
    glVertex3f(-95.0, 4.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-88.0, 22.0, 17.0);
    glVertex3f(50.0, 22.0, 17.0);
    glVertex3f(50.0, 22.0, 20.0);
    glVertex3f(-88.0, 22.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-88.0, 20.0, 17.0);
    glVertex3f(50.0, 20.0, 17.0);
    glVertex3f(50.0, 20.0, 20.0);
    glVertex3f(-88.0, 20.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-90.0, 19.0, 17.0);
    glVertex3f(56.0, 19.0, 17.0);
    glVertex3f(56.0, 19.0, 20.0);
    glVertex3f(-90.0, 19.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-92.0, 15.0, 17.0);
    glVertex3f(60.0, 15.0, 17.0);
    glVertex3f(60.0, 15.0, 20.0);
    glVertex3f(-92.0, 15.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-94.0, 11.0, 17.0);
    glVertex3f(62.0, 11.0, 17.0);
    glVertex3f(62.0, 11.0, 20.0);
    glVertex3f(-94.0, 11.0, 20.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-96.0, 7.0, 17.0);
    glVertex3f(64.0, 7.0, 17.0);
    glVertex3f(64.0, 7.0, 20.0);
    glVertex3f(-96.0, 7.0, 20.0);
    glEnd();

    //tiang sekoci
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(35.0, 0.0, -18.0);
    glVertex3f(35.0, -5.0, -18.0);
    glVertex3f(35.5, -5.0, -18.0);
    glVertex3f(35.5, 0.0, -18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(25.0, 0.0, -18.0);
    glVertex3f(25.0, -5.0, -18.0);
    glVertex3f(25.5, -5.0, -18.0);
    glVertex3f(25.5, 0.0, -18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(15.0, 0.0, -18.0);
    glVertex3f(15.0, -5.0, -18.0);
    glVertex3f(15.5, -5.0, -18.0);
    glVertex3f(15.5, 0.0, -18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(5.0, 0.0, -18.0);
    glVertex3f(5.0, -5.0, -18.0);
    glVertex3f(5.5, -5.0, -18.0);
    glVertex3f(5.5, 0.0, -18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-5.0, 0.0, -18.0);
    glVertex3f(-5.0, -5.0, -18.0);
    glVertex3f(-5.5, -5.0, -18.0);
    glVertex3f(-5.5, 0.0, -18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-15.0, 0.0, -18.0);
    glVertex3f(-15.0, -5.0, -18.0);
    glVertex3f(-15.5, -5.0, -18.0);
    glVertex3f(-15.5, 0.0, -18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-25.0, 0.0, -18.0);
    glVertex3f(-25.0, -5.0, -18.0);
    glVertex3f(-25.5, -5.0, -18.0);
    glVertex3f(-25.5, 0.0, -18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-35.0, 0.0, -18.0);
    glVertex3f(-35.0, -5.0, -18.0);
    glVertex3f(-35.5, -5.0, -18.0);
    glVertex3f(-35.5, 0.0, -18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-45.0, 0.0, -18.0);
    glVertex3f(-45.0, -5.0, -18.0);
    glVertex3f(-45.5, -5.0, -18.0);
    glVertex3f(-45.5, 0.0, -18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-55.0, 0.0, -18.0);
    glVertex3f(-55.0, -5.0, -18.0);
    glVertex3f(-55.5, -5.0, -18.0);
    glVertex3f(-55.5, 0.0, -18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-65.0, 0.0, -18.0);
    glVertex3f(-65.0, -5.0, -18.0);
    glVertex3f(-65.5, -5.0, -18.0);
    glVertex3f(-65.5, 0.0, -18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-75.0, 0.0, -18.0);
    glVertex3f(-75.0, -5.0, -18.0);
    glVertex3f(-75.5, -5.0, -18.0);
    glVertex3f(-75.5, 0.0, -18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-85.0, 0.0, -18.0);
    glVertex3f(-85.0, -5.0, -18.0);
    glVertex3f(-85.5, -5.0, -18.0);
    glVertex3f(-85.5, 0.0, -18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-95.0, -0.0, -18.0);
    glVertex3f(-95.0, -5.0, -18.0);
    glVertex3f(-95.5, -5.0, -18.0);
    glVertex3f(-95.5, -0.0, -18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-100.0, -2.7, -18.0);
    glVertex3f(-100.0, -5.0, -18.0);
    glVertex3f(-100.5, -5.0, -18.0);
    glVertex3f(-100.5, -2.7, -18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-96.0, -2.7, -18.0);
    glVertex3f(-96.0, -5.0, -18.0);
    glVertex3f(-96.5, -5.0, -18.0);
    glVertex3f(-96.5, -2.7, -18.0);
    glEnd();

    

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-97.5, -2.7, -18.0);
    glVertex3f(-97.5, -5.0, -18.0);
    glVertex3f(-98.0, -5.0, -18.0);
    glVertex3f(-98.0, -2.7, -18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-98.5, -2.7, -18.0);
    glVertex3f(-98.5, -5.0, -18.0);
    glVertex3f(-99.0, -5.0, -18.0);
    glVertex3f(-99.0, -2.7, -18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-98.0, -3.5, -18.0);
    glVertex3f(-98.0, -4.0, -18.0);
    glVertex3f(-98.5, -4.0, -18.0);
    glVertex3f(-98.5, -3.5, -18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-96.0, -1.5, -18.0);
    glVertex3f(-96.0, -2.0, -18.0);
    glVertex3f(-97.0, -2.0, -18.0);
    glVertex3f(-97.0, -1.5, -18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-98.0, -1.5, -18.0);
    glVertex3f(-98.0, -2.0, -18.0);
    glVertex3f(-100.0, -2.0, -18.0);
    glVertex3f(-100.0, -1.5, -18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-98.0, -0.5, -18.0);
    glVertex3f(-98.0, -1.0, -18.0);
    glVertex3f(-99.0, -1.0, -18.0);
    glVertex3f(-99.0, -0.5, -18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-99.2, -0.7, -18.0);
    glVertex3f(-99.2, -1.2, -18.0);
    glVertex3f(-100.0, -1.2, -18.0);
    glVertex3f(-100.0, -0.7, -18.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-95.5, -2.5, -18.0);
    glVertex3f(-95.5, -2.7, -18.0);
    glVertex3f(-100.5, -2.7, -18.0);
    glVertex3f(-100.5, -2.5, -18.0);
    glEnd();

    //tiang sekoci kiri
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(35.0, 0.0, 18.0);
    glVertex3f(35.0, -5.0, 18.0);
    glVertex3f(35.5, -5.0, 18.0);
    glVertex3f(35.5, 0.0, 18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(25.0, 0.0, 18.0);
    glVertex3f(25.0, -5.0, 18.0);
    glVertex3f(25.5, -5.0, 18.0);
    glVertex3f(25.5, 0.0, 18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(15.0, 0.0, 18.0);
    glVertex3f(15.0, -5.0, 18.0);
    glVertex3f(15.5, -5.0, 18.0);
    glVertex3f(15.5, 0.0, 18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(5.0, 0.0, 18.0);
    glVertex3f(5.0, -5.0, 18.0);
    glVertex3f(5.5, -5.0, 18.0);
    glVertex3f(5.5, 0.0, 18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-5.0, 0.0, 18.0);
    glVertex3f(-5.0, -5.0, 18.0);
    glVertex3f(-5.5, -5.0, 18.0);
    glVertex3f(-5.5, 0.0, 18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-15.0, 0.0, 18.0);
    glVertex3f(-15.0, -5.0, 18.0);
    glVertex3f(-15.5, -5.0, 18.0);
    glVertex3f(-15.5, 0.0, 18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-25.0, 0.0, 18.0);
    glVertex3f(-25.0, -5.0, 18.0);
    glVertex3f(-25.5, -5.0, 18.0);
    glVertex3f(-25.5, 0.0, 18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-35.0, 0.0, 18.0);
    glVertex3f(-35.0, -5.0, 18.0);
    glVertex3f(-35.5, -5.0, 18.0);
    glVertex3f(-35.5, 0.0, 18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-45.0, 0.0, 18.0);
    glVertex3f(-45.0, -5.0, 18.0);
    glVertex3f(-45.5, -5.0, 18.0);
    glVertex3f(-45.5, 0.0, 18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-55.0, 0.0, 18.0);
    glVertex3f(-55.0, -5.0, 18.0);
    glVertex3f(-55.5, -5.0, 18.0);
    glVertex3f(-55.5, 0.0, 18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-65.0, 0.0, 18.0);
    glVertex3f(-65.0, -5.0, 18.0);
    glVertex3f(-65.5, -5.0, 18.0);
    glVertex3f(-65.5, 0.0, 18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-75.0, 0.0, 18.0);
    glVertex3f(-75.0, -5.0, 18.0);
    glVertex3f(-75.5, -5.0, 18.0);
    glVertex3f(-75.5, 0.0, 18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-85.0, 0.0, 18.0);
    glVertex3f(-85.0, -5.0, 18.0);
    glVertex3f(-85.5, -5.0, 18.0);
    glVertex3f(-85.5, 0.0, 18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-95.0, -0.0, 18.0);
    glVertex3f(-95.0, -5.0, 18.0);
    glVertex3f(-95.5, -5.0, 18.0);
    glVertex3f(-95.5, -0.0, 18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-100.0, -2.7, 18.0);
    glVertex3f(-100.0, -5.0, 18.0);
    glVertex3f(-100.5, -5.0, 18.0);
    glVertex3f(-100.5, -2.7, 18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-96.0, -2.7, 18.0);
    glVertex3f(-96.0, -5.0, 18.0);
    glVertex3f(-96.5, -5.0, 18.0);
    glVertex3f(-96.5, -2.7, 18.0);
    glEnd();



    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-97.5, -2.7, 18.0);
    glVertex3f(-97.5, -5.0, 18.0);
    glVertex3f(-98.0, -5.0, 18.0);
    glVertex3f(-98.0, -2.7, 18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-98.5, -2.7, 18.0);
    glVertex3f(-98.5, -5.0, 18.0);
    glVertex3f(-99.0, -5.0, 18.0);
    glVertex3f(-99.0, -2.7, 18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-98.0, -3.5, 18.0);
    glVertex3f(-98.0, -4.0, 18.0);
    glVertex3f(-98.5, -4.0, 18.0);
    glVertex3f(-98.5, -3.5, 18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-96.0, -1.5, 18.0);
    glVertex3f(-96.0, -2.0, 18.0);
    glVertex3f(-97.0, -2.0, 18.0);
    glVertex3f(-97.0, -1.5, 18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-98.0, -1.5, 18.0);
    glVertex3f(-98.0, -2.0, 18.0);
    glVertex3f(-100.0, -2.0, 18.0);
    glVertex3f(-100.0, -1.5, 18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-98.0, -0.5, 18.0);
    glVertex3f(-98.0, -1.0, 18.0);
    glVertex3f(-99.0, -1.0, 18.0);
    glVertex3f(-99.0, -0.5, 18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-99.2, -0.7, 18.0);
    glVertex3f(-99.2, -1.2, 18.0);
    glVertex3f(-100.0, -1.2, 18.0);
    glVertex3f(-100.0, -0.7, 18.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-95.5, -2.5, 18.0);
    glVertex3f(-95.5, -2.7, 18.0);
    glVertex3f(-100.5, -2.7, 18.0);
    glVertex3f(-100.5, -2.5, 18.0);
    glEnd();
    //sekoci
    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(37.0, -3.0, -19.0);
    glVertex3f(37.0, -0.5, -19.0);
    glVertex3f(43.0, -0.5, -19.0);
    glVertex3f(43.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(27.0, -3.0, -19.0);
    glVertex3f(27.0, -0.5, -19.0);
    glVertex3f(33.0, -0.5, -19.0);
    glVertex3f(33.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(17.0, -3.0, -19.0);
    glVertex3f(17.0, -0.5, -19.0);
    glVertex3f(23.0, -0.5, -19.0);
    glVertex3f(23.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(7.0, -3.0, -19.0);
    glVertex3f(7.0, -0.5, -19.0);
    glVertex3f(13.0, -0.5, -19.0);
    glVertex3f(13.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(-3.0, -3.0, -19.0);
    glVertex3f(-3.0, -0.5, -19.0);
    glVertex3f(3.0, -0.5, -19.0);
    glVertex3f(3.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(-13.0, -3.0, -19.0);
    glVertex3f(-13.0, -0.5, -19.0);
    glVertex3f(-8.0, -0.5, -19.0);
    glVertex3f(-8.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(-23.0, -3.0, -19.0);
    glVertex3f(-23.0, -0.5, -19.0);
    glVertex3f(-18.0, -0.5, -19.0);
    glVertex3f(-18.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(-33.0, -3.0, -19.0);
    glVertex3f(-33.0, -0.5, -19.0);
    glVertex3f(-28.0, -0.5, -19.0);
    glVertex3f(-28.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(-43.0, -3.0, -19.0);
    glVertex3f(-43.0, -0.5, -19.0);
    glVertex3f(-38.0, -0.5, -19.0);
    glVertex3f(-38.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(-53.0, -3.0, -19.0);
    glVertex3f(-53.0, -0.5, -19.0);
    glVertex3f(-48.0, -0.5, -19.0);
    glVertex3f(-48.0, -3.0, -19.0);
    glEnd();

    
    
    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(-83.0, -3.0, -19.0);
    glVertex3f(-83.0, -0.5, -19.0);
    glVertex3f(-78.0, -0.5, -19.0);
    glVertex3f(-78.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(-93.0, -3.0, -19.0);
    glVertex3f(-93.0, -0.5, -19.0);
    glVertex3f(-88.0, -0.5, -19.0);
    glVertex3f(-88.0, -3.0, -19.0);
    glEnd();

    //sekoci kanan
    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(37.0, -3.0, 19.0);
    glVertex3f(37.0, -0.5, 19.0);
    glVertex3f(43.0, -0.5, 19.0);
    glVertex3f(43.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(27.0, -3.0, 19.0);
    glVertex3f(27.0, -0.5, 19.0);
    glVertex3f(33.0, -0.5, 19.0);
    glVertex3f(33.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(17.0, -3.0, 19.0);
    glVertex3f(17.0, -0.5, 19.0);
    glVertex3f(23.0, -0.5, 19.0);
    glVertex3f(23.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(7.0, -3.0, 19.0);
    glVertex3f(7.0, -0.5, 19.0);
    glVertex3f(13.0, -0.5, 19.0);
    glVertex3f(13.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(-3.0, -3.0, 19.0);
    glVertex3f(-3.0, -0.5, 19.0);
    glVertex3f(3.0, -0.5, 19.0);
    glVertex3f(3.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(-13.0, -3.0, 19.0);
    glVertex3f(-13.0, -0.5, 19.0);
    glVertex3f(-8.0, -0.5, 19.0);
    glVertex3f(-8.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(-23.0, -3.0, 19.0);
    glVertex3f(-23.0, -0.5, 19.0);
    glVertex3f(-18.0, -0.5, 19.0);
    glVertex3f(-18.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(-33.0, -3.0, 19.0);
    glVertex3f(-33.0, -0.5, 19.0);
    glVertex3f(-28.0, -0.5, 19.0);
    glVertex3f(-28.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(-43.0, -3.0, 19.0);
    glVertex3f(-43.0, -0.5, 19.0);
    glVertex3f(-38.0, -0.5, 19.0);
    glVertex3f(-38.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(-53.0, -3.0, 19.0);
    glVertex3f(-53.0, -0.5, 19.0);
    glVertex3f(-48.0, -0.5, 19.0);
    glVertex3f(-48.0, -3.0, 19.0);
    glEnd();



    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(-83.0, -3.0, 19.0);
    glVertex3f(-83.0, -0.5, 19.0);
    glVertex3f(-78.0, -0.5, 19.0);
    glVertex3f(-78.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 0.9);
    glVertex3f(-93.0, -3.0, 19.0);
    glVertex3f(-93.0, -0.5, 19.0);
    glVertex3f(-88.0, -0.5, 19.0);
    glVertex3f(-88.0, -3.0, 19.0);
    glEnd();
    //uung sekoci  s kanan
    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(43.0, -3.0, -17.0);
    glVertex3f(43.5, -2.0, -17.0);
    glVertex3f(43.5, -2.0, -19.0);
    glVertex3f(43.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(43.5, -2.0, -17.0);
    glVertex3f(43.5, -1.5, -17.0);
    glVertex3f(43.5, -1.5, -19.0);
    glVertex3f(43.5, -2.0, -19.0);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(43.0, -0.5, -17.0);
    glVertex3f(43.5, -1.5, -17.0);
    glVertex3f(43.5, -1.5, -19.0);
    glVertex3f(43.0, -0.5, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(33.0, -3.0, -17.0);
    glVertex3f(33.5, -2.0, -17.0);
    glVertex3f(33.5, -2.0, -19.0);
    glVertex3f(33.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(33.5, -2.0, -17.0);
    glVertex3f(33.5, -1.5, -17.0);
    glVertex3f(33.5, -1.5, -19.0);
    glVertex3f(33.5, -2.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(33.0, -0.5, -17.0);
    glVertex3f(33.5, -1.5, -17.0);
    glVertex3f(33.5, -1.5, -19.0);
    glVertex3f(33.0, -0.5, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(23.0, -3.0, -17.0);
    glVertex3f(23.5, -2.0, -17.0);
    glVertex3f(23.5, -2.0, -19.0);
    glVertex3f(23.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(23.5, -2.0, -17.0);
    glVertex3f(23.5, -1.5, -17.0);
    glVertex3f(23.5, -1.5, -19.0);
    glVertex3f(23.5, -2.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(23.0, -0.5, -17.0);
    glVertex3f(23.5, -1.5, -17.0);
    glVertex3f(23.5, -1.5, -19.0);
    glVertex3f(23.0, -0.5, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(13.0, -3.0, -17.0);
    glVertex3f(13.5, -2.0, -17.0);
    glVertex3f(13.5, -2.0, -19.0);
    glVertex3f(13.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(13.5, -2.0, -17.0);
    glVertex3f(13.5, -1.5, -17.0);
    glVertex3f(13.5, -1.5, -19.0);
    glVertex3f(13.5, -2.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(13.0, -0.5, -17.0);
    glVertex3f(13.5, -1.5, -17.0);
    glVertex3f(13.5, -1.5, -19.0);
    glVertex3f(13.0, -0.5, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(3.0, -3.0, -17.0);
    glVertex3f(3.5, -2.0, -17.0);
    glVertex3f(3.5, -2.0, -19.0);
    glVertex3f(3.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(3.5, -2.0, -17.0);
    glVertex3f(3.5, -1.5, -17.0);
    glVertex3f(3.5, -1.5, -19.0);
    glVertex3f(3.5, -2.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(3.0, -0.5, -17.0);
    glVertex3f(3.5, -1.5, -17.0);
    glVertex3f(3.5, -1.5, -19.0);
    glVertex3f(3.0, -0.5, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-8.0, -3.0, -17.0);
    glVertex3f(-7.5, -2.0, -17.0);
    glVertex3f(-7.5, -2.0, -19.0);
    glVertex3f(-8.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-7.5, -2.0, -17.0);
    glVertex3f(-7.5, -1.5, -17.0);
    glVertex3f(-7.5, -1.5, -19.0);
    glVertex3f(-7.5, -2.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-8.0, -0.5, -17.0);
    glVertex3f(-7.5, -1.5, -17.0);
    glVertex3f(-7.5, -1.5, -19.0);
    glVertex3f(-8.0, -0.5, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-18.0, -3.0, -17.0);
    glVertex3f(-17.5, -2.0, -17.0);
    glVertex3f(-17.5, -2.0, -19.0);
    glVertex3f(-18.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-17.5, -2.0, -17.0);
    glVertex3f(-17.5, -1.5, -17.0);
    glVertex3f(-17.5, -1.5, -19.0);
    glVertex3f(-17.5, -2.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-18.0, -0.5, -17.0);
    glVertex3f(-17.5, -1.5, -17.0);
    glVertex3f(-17.5, -1.5, -19.0);
    glVertex3f(-18.0, -0.5, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-28.0, -3.0, -17.0);
    glVertex3f(-27.5, -2.0, -17.0);
    glVertex3f(-27.5, -2.0, -19.0);
    glVertex3f(-28.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-27.5, -2.0, -17.0);
    glVertex3f(-27.5, -1.5, -17.0);
    glVertex3f(-27.5, -1.5, -19.0);
    glVertex3f(-27.5, -2.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-28.0, -0.5, -17.0);
    glVertex3f(-27.5, -1.5, -17.0);
    glVertex3f(-27.5, -1.5, -19.0);
    glVertex3f(-28.0, -0.5, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-38.0, -3.0, -17.0);
    glVertex3f(-37.5, -2.0, -17.0);
    glVertex3f(-37.5, -2.0, -19.0);
    glVertex3f(-38.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-37.5, -2.0, -17.0);
    glVertex3f(-37.5, -1.5, -17.0);
    glVertex3f(-37.5, -1.5, -19.0);
    glVertex3f(-37.5, -2.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-38.0, -0.5, -17.0);
    glVertex3f(-37.5, -1.5, -17.0);
    glVertex3f(-37.5, -1.5, -19.0);
    glVertex3f(-38.0, -0.5, -19.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-48.0, -3.0, -17.0);
    glVertex3f(-47.5, -2.0, -17.0);
    glVertex3f(-47.5, -2.0, -19.0);
    glVertex3f(-48.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-47.5, -2.0, -17.0);
    glVertex3f(-47.5, -1.5, -17.0);
    glVertex3f(-47.5, -1.5, -19.0);
    glVertex3f(-47.5, -2.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-48.0, -0.5, -17.0);
    glVertex3f(-47.5, -1.5, -17.0);
    glVertex3f(-47.5, -1.5, -19.0);
    glVertex3f(-48.0, -0.5, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-78.0, -3.0, -17.0);
    glVertex3f(-77.5, -2.0, -17.0);
    glVertex3f(-77.5, -2.0, -19.0);
    glVertex3f(-78.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-77.5, -2.0, -17.0);
    glVertex3f(-77.5, -1.5, -17.0);
    glVertex3f(-77.5, -1.5, -19.0);
    glVertex3f(-77.5, -2.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-78.0, -0.5, -17.0);
    glVertex3f(-77.5, -1.5, -17.0);
    glVertex3f(-77.5, -1.5, -19.0);
    glVertex3f(-78.0, -0.5, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-83.0, -0.5, -17.0);
    glVertex3f(-83.5, -1.5, -17.0);
    glVertex3f(-83.5, -1.5, -19.0);
    glVertex3f(-83.0, -0.5, -19.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-83.5, -2.0, -17.0);
    glVertex3f(-83.5, -1.5, -17.0);
    glVertex3f(-83.5, -1.5, -19.0);
    glVertex3f(-83.5, -2.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-83.0, -3.0, -17.0);
    glVertex3f(-83.5, -2.0, -17.0);
    glVertex3f(-83.5, -2.0, -19.0);
    glVertex3f(-83.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-78.0, -3.0, -17.0);
    glVertex3f(-77.5, -2.0, -17.0);
    glVertex3f(-77.5, -2.0, -19.0);
    glVertex3f(-78.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-87.5, -2.0, -17.0);
    glVertex3f(-87.5, -1.5, -17.0);
    glVertex3f(-87.5, -1.5, -19.0);
    glVertex3f(-87.5, -2.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-88.0, -0.5, -17.0);
    glVertex3f(-87.5, -1.5, -17.0);
    glVertex3f(-87.5, -1.5, -19.0);
    glVertex3f(-88.0, -0.5, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-88.0, -3.0, -17.0);
    glVertex3f(-87.5, -2.0, -17.0);
    glVertex3f(-87.5, -2.0, -19.0);
    glVertex3f(-88.0, -3.0, -19.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-93.0, -0.5, -17.0);
    glVertex3f(-93.5, -1.5, -17.0);
    glVertex3f(-93.5, -1.5, -19.0);
    glVertex3f(-93.0, -0.5, -19.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-93.5, -2.0, -17.0);
    glVertex3f(-93.5, -1.5, -17.0);
    glVertex3f(-93.5, -1.5, -19.0);
    glVertex3f(-93.5, -2.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-93.0, -3.0, -17.0);
    glVertex3f(-93.5, -2.0, -17.0);
    glVertex3f(-93.5, -2.0, -19.0);
    glVertex3f(-93.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-53.0, -0.5, -17.0);
    glVertex3f(-53.5, -1.5, -17.0);
    glVertex3f(-53.5, -1.5, -19.0);
    glVertex3f(-53.0, -0.5, -19.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-53.5, -2.0, -17.0);
    glVertex3f(-53.5, -1.5, -17.0);
    glVertex3f(-53.5, -1.5, -19.0);
    glVertex3f(-53.5, -2.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-53.0, -3.0, -17.0);
    glVertex3f(-53.5, -2.0, -17.0);
    glVertex3f(-53.5, -2.0, -19.0);
    glVertex3f(-53.0, -3.0, -19.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-43.0, -0.5, -17.0);
    glVertex3f(-43.5, -1.5, -17.0);
    glVertex3f(-43.5, -1.5, -19.0);
    glVertex3f(-43.0, -0.5, -19.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-43.5, -2.0, -17.0);
    glVertex3f(-43.5, -1.5, -17.0);
    glVertex3f(-43.5, -1.5, -19.0);
    glVertex3f(-43.5, -2.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-43.0, -3.0, -17.0);
    glVertex3f(-43.5, -2.0, -17.0);
    glVertex3f(-43.5, -2.0, -19.0);
    glVertex3f(-43.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-33.0, -0.5, -17.0);
    glVertex3f(-33.5, -1.5, -17.0);
    glVertex3f(-33.5, -1.5, -19.0);
    glVertex3f(-33.0, -0.5, -19.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-33.5, -2.0, -17.0);
    glVertex3f(-33.5, -1.5, -17.0);
    glVertex3f(-33.5, -1.5, -19.0);
    glVertex3f(-33.5, -2.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-33.0, -3.0, -17.0);
    glVertex3f(-33.5, -2.0, -17.0);
    glVertex3f(-33.5, -2.0, -19.0);
    glVertex3f(-33.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-23.0, -0.5, -17.0);
    glVertex3f(-23.5, -1.5, -17.0);
    glVertex3f(-23.5, -1.5, -19.0);
    glVertex3f(-23.0, -0.5, -19.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-23.5, -2.0, -17.0);
    glVertex3f(-23.5, -1.5, -17.0);
    glVertex3f(-23.5, -1.5, -19.0);
    glVertex3f(-23.5, -2.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-23.0, -3.0, -17.0);
    glVertex3f(-23.5, -2.0, -17.0);
    glVertex3f(-23.5, -2.0, -19.0);
    glVertex3f(-23.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-13.0, -0.5, -17.0);
    glVertex3f(-13.5, -1.5, -17.0);
    glVertex3f(-13.5, -1.5, -19.0);
    glVertex3f(-13.0, -0.5, -19.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-13.5, -2.0, -17.0);
    glVertex3f(-13.5, -1.5, -17.0);
    glVertex3f(-13.5, -1.5, -19.0);
    glVertex3f(-13.5, -2.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-13.0, -3.0, -17.0);
    glVertex3f(-13.5, -2.0, -17.0);
    glVertex3f(-13.5, -2.0, -19.0);
    glVertex3f(-13.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-3.0, -0.5, -17.0);
    glVertex3f(-3.5, -1.5, -17.0);
    glVertex3f(-3.5, -1.5, -19.0);
    glVertex3f(-3.0, -0.5, -19.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-3.5, -2.0, -17.0);
    glVertex3f(-3.5, -1.5, -17.0);
    glVertex3f(-3.5, -1.5, -19.0);
    glVertex3f(-3.5, -2.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-3.0, -3.0, -17.0);
    glVertex3f(-3.5, -2.0, -17.0);
    glVertex3f(-3.5, -2.0, -19.0);
    glVertex3f(-3.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(7.0, -0.5, -17.0);
    glVertex3f(6.5, -1.5, -17.0);
    glVertex3f(6.5, -1.5, -19.0);
    glVertex3f(7.0, -0.5, -19.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(6.5, -2.0, -17.0);
    glVertex3f(6.5, -1.5, -17.0);
    glVertex3f(6.5, -1.5, -19.0);
    glVertex3f(6.5, -2.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(7.0, -3.0, -17.0);
    glVertex3f(6.5, -2.0, -17.0);
    glVertex3f(6.5, -2.0, -19.0);
    glVertex3f(7.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(17.0, -0.5, -17.0);
    glVertex3f(16.5, -1.5, -17.0);
    glVertex3f(16.5, -1.5, -19.0);
    glVertex3f(17.0, -0.5, -19.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(16.5, -2.0, -17.0);
    glVertex3f(16.5, -1.5, -17.0);
    glVertex3f(16.5, -1.5, -19.0);
    glVertex3f(16.5, -2.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(17.0, -3.0, -17.0);
    glVertex3f(16.5, -2.0, -17.0);
    glVertex3f(16.5, -2.0, -19.0);
    glVertex3f(17.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(27.0, -0.5, -17.0);
    glVertex3f(26.5, -1.5, -17.0);
    glVertex3f(26.5, -1.5, -19.0);
    glVertex3f(27.0, -0.5, -19.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(26.5, -2.0, -17.0);
    glVertex3f(26.5, -1.5, -17.0);
    glVertex3f(26.5, -1.5, -19.0);
    glVertex3f(26.5, -2.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(27.0, -3.0, -17.0);
    glVertex3f(26.5, -2.0, -17.0);
    glVertex3f(26.5, -2.0, -19.0);
    glVertex3f(27.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(37.0, -0.5, -17.0);
    glVertex3f(36.5, -1.5, -17.0);
    glVertex3f(36.5, -1.5, -19.0);
    glVertex3f(37.0, -0.5, -19.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(36.5, -2.0, -17.0);
    glVertex3f(36.5, -1.5, -17.0);
    glVertex3f(36.5, -1.5, -19.0);
    glVertex3f(36.5, -2.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(37.0, -3.0, -17.0);
    glVertex3f(36.5, -2.0, -17.0);
    glVertex3f(36.5, -2.0, -19.0);
    glVertex3f(37.0, -3.0, -19.0);
    glEnd();

    //uung sekoci  s kiri
    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(43.0, -3.0, 17.0);
    glVertex3f(43.5, -2.0, 17.0);
    glVertex3f(43.5, -2.0, 19.0);
    glVertex3f(43.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(43.5, -2.0, 17.0);
    glVertex3f(43.5, -1.5, 17.0);
    glVertex3f(43.5, -1.5, 19.0);
    glVertex3f(43.5, -2.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(43.0, -0.5, 17.0);
    glVertex3f(43.5, -1.5, 17.0);
    glVertex3f(43.5, -1.5, 19.0);
    glVertex3f(43.0, -0.5, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(33.0, -3.0, 17.0);
    glVertex3f(33.5, -2.0, 17.0);
    glVertex3f(33.5, -2.0, 19.0);
    glVertex3f(33.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(33.5, -2.0, 17.0);
    glVertex3f(33.5, -1.5, 17.0);
    glVertex3f(33.5, -1.5, 19.0);
    glVertex3f(33.5, -2.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(33.0, -0.5, 17.0);
    glVertex3f(33.5, -1.5, 17.0);
    glVertex3f(33.5, -1.5, 19.0);
    glVertex3f(33.0, -0.5, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(23.0, -3.0, 17.0);
    glVertex3f(23.5, -2.0, 17.0);
    glVertex3f(23.5, -2.0, 19.0);
    glVertex3f(23.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(23.5, -2.0, 17.0);
    glVertex3f(23.5, -1.5, 17.0);
    glVertex3f(23.5, -1.5, 19.0);
    glVertex3f(23.5, -2.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(23.0, -0.5, 17.0);
    glVertex3f(23.5, -1.5, 17.0);
    glVertex3f(23.5, -1.5, 19.0);
    glVertex3f(23.0, -0.5, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(13.0, -3.0, 17.0);
    glVertex3f(13.5, -2.0, 17.0);
    glVertex3f(13.5, -2.0, 19.0);
    glVertex3f(13.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(13.5, -2.0, 17.0);
    glVertex3f(13.5, -1.5, 17.0);
    glVertex3f(13.5, -1.5, 19.0);
    glVertex3f(13.5, -2.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(13.0, -0.5, 17.0);
    glVertex3f(13.5, -1.5, 17.0);
    glVertex3f(13.5, -1.5, 19.0);
    glVertex3f(13.0, -0.5, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(3.0, -3.0, 17.0);
    glVertex3f(3.5, -2.0, 17.0);
    glVertex3f(3.5, -2.0, 19.0);
    glVertex3f(3.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(3.5, -2.0, 17.0);
    glVertex3f(3.5, -1.5, 17.0);
    glVertex3f(3.5, -1.5, 19.0);
    glVertex3f(3.5, -2.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(3.0, -0.5, 17.0);
    glVertex3f(3.5, -1.5, 17.0);
    glVertex3f(3.5, -1.5, 19.0);
    glVertex3f(3.0, -0.5, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-8.0, -3.0, 17.0);
    glVertex3f(-7.5, -2.0, 17.0);
    glVertex3f(-7.5, -2.0, 19.0);
    glVertex3f(-8.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-7.5, -2.0, 17.0);
    glVertex3f(-7.5, -1.5, 17.0);
    glVertex3f(-7.5, -1.5, 19.0);
    glVertex3f(-7.5, -2.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-8.0, -0.5, 17.0);
    glVertex3f(-7.5, -1.5, 17.0);
    glVertex3f(-7.5, -1.5, 19.0);
    glVertex3f(-8.0, -0.5, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-18.0, -3.0, 17.0);
    glVertex3f(-17.5, -2.0, 17.0);
    glVertex3f(-17.5, -2.0, 19.0);
    glVertex3f(-18.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-17.5, -2.0, 17.0);
    glVertex3f(-17.5, -1.5, 17.0);
    glVertex3f(-17.5, -1.5, 19.0);
    glVertex3f(-17.5, -2.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-18.0, -0.5, 17.0);
    glVertex3f(-17.5, -1.5, 17.0);
    glVertex3f(-17.5, -1.5, 19.0);
    glVertex3f(-18.0, -0.5, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-28.0, -3.0, 17.0);
    glVertex3f(-27.5, -2.0, 17.0);
    glVertex3f(-27.5, -2.0, 19.0);
    glVertex3f(-28.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-27.5, -2.0, 17.0);
    glVertex3f(-27.5, -1.5, 17.0);
    glVertex3f(-27.5, -1.5, 19.0);
    glVertex3f(-27.5, -2.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-28.0, -0.5, 17.0);
    glVertex3f(-27.5, -1.5, 17.0);
    glVertex3f(-27.5, -1.5, 19.0);
    glVertex3f(-28.0, -0.5, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-38.0, -3.0, 17.0);
    glVertex3f(-37.5, -2.0, 17.0);
    glVertex3f(-37.5, -2.0, 19.0);
    glVertex3f(-38.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-37.5, -2.0, 17.0);
    glVertex3f(-37.5, -1.5, 17.0);
    glVertex3f(-37.5, -1.5, 19.0);
    glVertex3f(-37.5, -2.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-38.0, -0.5, 17.0);
    glVertex3f(-37.5, -1.5, 17.0);
    glVertex3f(-37.5, -1.5, 19.0);
    glVertex3f(-38.0, -0.5, 19.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-48.0, -3.0, 17.0);
    glVertex3f(-47.5, -2.0, 17.0);
    glVertex3f(-47.5, -2.0, 19.0);
    glVertex3f(-48.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-47.5, -2.0, 17.0);
    glVertex3f(-47.5, -1.5, 17.0);
    glVertex3f(-47.5, -1.5, 19.0);
    glVertex3f(-47.5, -2.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-48.0, -0.5, 17.0);
    glVertex3f(-47.5, -1.5, 17.0);
    glVertex3f(-47.5, -1.5, 19.0);
    glVertex3f(-48.0, -0.5, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-78.0, -3.0, 17.0);
    glVertex3f(-77.5, -2.0, 17.0);
    glVertex3f(-77.5, -2.0, 19.0);
    glVertex3f(-78.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-77.5, -2.0, 17.0);
    glVertex3f(-77.5, -1.5, 17.0);
    glVertex3f(-77.5, -1.5, 19.0);
    glVertex3f(-77.5, -2.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-78.0, -0.5, 17.0);
    glVertex3f(-77.5, -1.5, 17.0);
    glVertex3f(-77.5, -1.5, 19.0);
    glVertex3f(-78.0, -0.5, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-83.0, -0.5, 17.0);
    glVertex3f(-83.5, -1.5, 17.0);
    glVertex3f(-83.5, -1.5, 19.0);
    glVertex3f(-83.0, -0.5, 19.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-83.5, -2.0, 17.0);
    glVertex3f(-83.5, -1.5, 17.0);
    glVertex3f(-83.5, -1.5, 19.0);
    glVertex3f(-83.5, -2.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-83.0, -3.0, 17.0);
    glVertex3f(-83.5, -2.0, 17.0);
    glVertex3f(-83.5, -2.0, 19.0);
    glVertex3f(-83.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-78.0, -3.0, 17.0);
    glVertex3f(-77.5, -2.0, 17.0);
    glVertex3f(-77.5, -2.0, 19.0);
    glVertex3f(-78.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-87.5, -2.0, 17.0);
    glVertex3f(-87.5, -1.5, 17.0);
    glVertex3f(-87.5, -1.5, 19.0);
    glVertex3f(-87.5, -2.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-88.0, -0.5, 17.0);
    glVertex3f(-87.5, -1.5, 17.0);
    glVertex3f(-87.5, -1.5, 19.0);
    glVertex3f(-88.0, -0.5, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-88.0, -3.0, 17.0);
    glVertex3f(-87.5, -2.0, 17.0);
    glVertex3f(-87.5, -2.0, 19.0);
    glVertex3f(-88.0, -3.0, 19.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-93.0, -0.5, 17.0);
    glVertex3f(-93.5, -1.5, 17.0);
    glVertex3f(-93.5, -1.5, 19.0);
    glVertex3f(-93.0, -0.5, 19.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-93.5, -2.0, 17.0);
    glVertex3f(-93.5, -1.5, 17.0);
    glVertex3f(-93.5, -1.5, 19.0);
    glVertex3f(-93.5, -2.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-93.0, -3.0, 17.0);
    glVertex3f(-93.5, -2.0, 17.0);
    glVertex3f(-93.5, -2.0, 19.0);
    glVertex3f(-93.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-53.0, -0.5, 17.0);
    glVertex3f(-53.5, -1.5, 17.0);
    glVertex3f(-53.5, -1.5, 19.0);
    glVertex3f(-53.0, -0.5, 19.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-53.5, -2.0, 17.0);
    glVertex3f(-53.5, -1.5, 17.0);
    glVertex3f(-53.5, -1.5, 19.0);
    glVertex3f(-53.5, -2.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-53.0, -3.0, 17.0);
    glVertex3f(-53.5, -2.0, 17.0);
    glVertex3f(-53.5, -2.0, 19.0);
    glVertex3f(-53.0, -3.0, 19.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-43.0, -0.5, 17.0);
    glVertex3f(-43.5, -1.5, 17.0);
    glVertex3f(-43.5, -1.5, 19.0);
    glVertex3f(-43.0, -0.5, 19.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-43.5, -2.0, 17.0);
    glVertex3f(-43.5, -1.5, 17.0);
    glVertex3f(-43.5, -1.5, 19.0);
    glVertex3f(-43.5, -2.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-43.0, -3.0, 17.0);
    glVertex3f(-43.5, -2.0, 17.0);
    glVertex3f(-43.5, -2.0, 19.0);
    glVertex3f(-43.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-33.0, -0.5, 17.0);
    glVertex3f(-33.5, -1.5, 17.0);
    glVertex3f(-33.5, -1.5, 19.0);
    glVertex3f(-33.0, -0.5, 19.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-33.5, -2.0, 17.0);
    glVertex3f(-33.5, -1.5, 17.0);
    glVertex3f(-33.5, -1.5, 19.0);
    glVertex3f(-33.5, -2.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-33.0, -3.0, 17.0);
    glVertex3f(-33.5, -2.0, 17.0);
    glVertex3f(-33.5, -2.0, 19.0);
    glVertex3f(-33.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-23.0, -0.5, 17.0);
    glVertex3f(-23.5, -1.5, 17.0);
    glVertex3f(-23.5, -1.5, 19.0);
    glVertex3f(-23.0, -0.5, 19.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-23.5, -2.0, 17.0);
    glVertex3f(-23.5, -1.5, 17.0);
    glVertex3f(-23.5, -1.5, 19.0);
    glVertex3f(-23.5, -2.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-23.0, -3.0, 17.0);
    glVertex3f(-23.5, -2.0, 17.0);
    glVertex3f(-23.5, -2.0, 19.0);
    glVertex3f(-23.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-13.0, -0.5, 17.0);
    glVertex3f(-13.5, -1.5, 17.0);
    glVertex3f(-13.5, -1.5, 19.0);
    glVertex3f(-13.0, -0.5, 19.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-13.5, -2.0, 17.0);
    glVertex3f(-13.5, -1.5, 17.0);
    glVertex3f(-13.5, -1.5, 19.0);
    glVertex3f(-13.5, -2.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-13.0, -3.0, 17.0);
    glVertex3f(-13.5, -2.0, 17.0);
    glVertex3f(-13.5, -2.0, 19.0);
    glVertex3f(-13.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-3.0, -0.5, 17.0);
    glVertex3f(-3.5, -1.5, 17.0);
    glVertex3f(-3.5, -1.5, 19.0);
    glVertex3f(-3.0, -0.5, 19.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-3.5, -2.0, 17.0);
    glVertex3f(-3.5, -1.5, 17.0);
    glVertex3f(-3.5, -1.5, 19.0);
    glVertex3f(-3.5, -2.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-3.0, -3.0, 17.0);
    glVertex3f(-3.5, -2.0, 17.0);
    glVertex3f(-3.5, -2.0, 19.0);
    glVertex3f(-3.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(7.0, -0.5, 17.0);
    glVertex3f(6.5, -1.5, 17.0);
    glVertex3f(6.5, -1.5, 19.0);
    glVertex3f(7.0, -0.5, 19.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(6.5, -2.0, 17.0);
    glVertex3f(6.5, -1.5, 17.0);
    glVertex3f(6.5, -1.5, 19.0);
    glVertex3f(6.5, -2.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(7.0, -3.0, 17.0);
    glVertex3f(6.5, -2.0, 17.0);
    glVertex3f(6.5, -2.0, 19.0);
    glVertex3f(7.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(17.0, -0.5, 17.0);
    glVertex3f(16.5, -1.5, 17.0);
    glVertex3f(16.5, -1.5, 19.0);
    glVertex3f(17.0, -0.5, 19.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(16.5, -2.0, 17.0);
    glVertex3f(16.5, -1.5, 17.0);
    glVertex3f(16.5, -1.5, 19.0);
    glVertex3f(16.5, -2.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(17.0, -3.0, 17.0);
    glVertex3f(16.5, -2.0, 17.0);
    glVertex3f(16.5, -2.0, 19.0);
    glVertex3f(17.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(27.0, -0.5, 17.0);
    glVertex3f(26.5, -1.5, 17.0);
    glVertex3f(26.5, -1.5, 19.0);
    glVertex3f(27.0, -0.5, 19.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(26.5, -2.0, 17.0);
    glVertex3f(26.5, -1.5, 17.0);
    glVertex3f(26.5, -1.5, 19.0);
    glVertex3f(26.5, -2.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(27.0, -3.0, 17.0);
    glVertex3f(26.5, -2.0, 17.0);
    glVertex3f(26.5, -2.0, 19.0);
    glVertex3f(27.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(37.0, -0.5, 17.0);
    glVertex3f(36.5, -1.5, 17.0);
    glVertex3f(36.5, -1.5, 19.0);
    glVertex3f(37.0, -0.5, 19.0);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(36.5, -2.0, 17.0);
    glVertex3f(36.5, -1.5, 17.0);
    glVertex3f(36.5, -1.5, 19.0);
    glVertex3f(36.5, -2.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(37.0, -3.0, 17.0);
    glVertex3f(36.5, -2.0, 17.0);
    glVertex3f(36.5, -2.0, 19.0);
    glVertex3f(37.0, -3.0, 19.0);
    glEnd();


    //tutup atas bawah sekoci
    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(43.0, -3.0, -17.0);
    glVertex3f(37.0, -3.0, -17.0);
    glVertex3f(37.0, -3.0, -19.0);
    glVertex3f(43.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(43.0, -0.5, -17.0);
    glVertex3f(37.0, -0.5, -17.0);
    glVertex3f(37.0, -0.5, -19.0);
    glVertex3f(43.0, -0.5, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(33.0, -3.0, -17.0);
    glVertex3f(27.0, -3.0, -17.0);
    glVertex3f(27.0, -3.0, -19.0);
    glVertex3f(33.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(33.0, -0.5, -17.0);
    glVertex3f(27.0, -0.5, -17.0);
    glVertex3f(27.0, -0.5, -19.0);
    glVertex3f(33.0, -0.5, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(23.0, -3.0, -17.0);
    glVertex3f(17.0, -3.0, -17.0);
    glVertex3f(17.0, -3.0, -19.0);
    glVertex3f(23.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(23.0, -0.5, -17.0);
    glVertex3f(17.0, -0.5, -17.0);
    glVertex3f(17.0, -0.5, -19.0);
    glVertex3f(23.0, -0.5, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(13.0, -3.0, -17.0);
    glVertex3f(7.0, -3.0, -17.0);
    glVertex3f(7.0, -3.0, -19.0);
    glVertex3f(13.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(13.0, -0.5, -17.0);
    glVertex3f(7.0, -0.5, -17.0);
    glVertex3f(7.0, -0.5, -19.0);
    glVertex3f(13.0, -0.5, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(3.0, -3.0, -17.0);
    glVertex3f(-3.0, -3.0, -17.0);
    glVertex3f(-3.0, -3.0, -19.0);
    glVertex3f(3.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(3.0, -0.5, -17.0);
    glVertex3f(-3.0, -0.5, -17.0);
    glVertex3f(-3.0, -0.5, -19.0);
    glVertex3f(3.0, -0.5, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-8.0, -3.0, -17.0);
    glVertex3f(-13.0, -3.0, -17.0);
    glVertex3f(-13.0, -3.0, -19.0);
    glVertex3f(-8.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-8.0, -0.5, -17.0);
    glVertex3f(-13.0, -0.5, -17.0);
    glVertex3f(-13.0, -0.5, -19.0);
    glVertex3f(-8.0, -0.5, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-18.0, -3.0, -17.0);
    glVertex3f(-23.0, -3.0, -17.0);
    glVertex3f(-23.0, -3.0, -19.0);
    glVertex3f(-18.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-18.0, -0.5, -17.0);
    glVertex3f(-23.0, -0.5, -17.0);
    glVertex3f(-23.0, -0.5, -19.0);
    glVertex3f(-18.0, -0.5, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-28.0, -3.0, -17.0);
    glVertex3f(-33.0, -3.0, -17.0);
    glVertex3f(-33.0, -3.0, -19.0);
    glVertex3f(-28.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-28.0, -0.5, -17.0);
    glVertex3f(-33.0, -0.5, -17.0);
    glVertex3f(-33.0, -0.5, -19.0);
    glVertex3f(-28.0, -0.5, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-38.0, -3.0, -17.0);
    glVertex3f(-43.0, -3.0, -17.0);
    glVertex3f(-43.0, -3.0, -19.0);
    glVertex3f(-38.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-38.0, -0.5, -17.0);
    glVertex3f(-43.0, -0.5, -17.0);
    glVertex3f(-43.0, -0.5, -19.0);
    glVertex3f(-38.0, -0.5, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-48.0, -3.0, -17.0);
    glVertex3f(-53.0, -3.0, -17.0);
    glVertex3f(-53.0, -3.0, -19.0);
    glVertex3f(-48.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-48.0, -0.5, -17.0);
    glVertex3f(-53.0, -0.5, -17.0);
    glVertex3f(-53.0, -0.5, -19.0);
    glVertex3f(-48.0, -0.5, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-78.0, -3.0, -17.0);
    glVertex3f(-83.0, -3.0, -17.0);
    glVertex3f(-83.0, -3.0, -19.0);
    glVertex3f(-78.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-78.0, -0.5, -17.0);
    glVertex3f(-83.0, -0.5, -17.0);
    glVertex3f(-83.0, -0.5, -19.0);
    glVertex3f(-78.0, -0.5, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-88.0, -3.0, -17.0);
    glVertex3f(-93.0, -3.0, -17.0);
    glVertex3f(-93.0, -3.0, -19.0);
    glVertex3f(-88.0, -3.0, -19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-88.0, -0.5, -17.0);
    glVertex3f(-93.0, -0.5, -17.0);
    glVertex3f(-93.0, -0.5, -19.0);
    glVertex3f(-88.0, -0.5, -19.0);
    glEnd();

    //tutup atas bawah sekoci kiri
    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(43.0, -3.0, 17.0);
    glVertex3f(37.0, -3.0, 17.0);
    glVertex3f(37.0, -3.0, 19.0);
    glVertex3f(43.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(43.0, -0.5, 17.0);
    glVertex3f(37.0, -0.5, 17.0);
    glVertex3f(37.0, -0.5, 19.0);
    glVertex3f(43.0, -0.5, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(33.0, -3.0, 17.0);
    glVertex3f(27.0, -3.0, 17.0);
    glVertex3f(27.0, -3.0, 19.0);
    glVertex3f(33.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(33.0, -0.5, 17.0);
    glVertex3f(27.0, -0.5, 17.0);
    glVertex3f(27.0, -0.5, 19.0);
    glVertex3f(33.0, -0.5, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(23.0, -3.0, 17.0);
    glVertex3f(17.0, -3.0, 17.0);
    glVertex3f(17.0, -3.0, 19.0);
    glVertex3f(23.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(23.0, -0.5, 17.0);
    glVertex3f(17.0, -0.5, 17.0);
    glVertex3f(17.0, -0.5, 19.0);
    glVertex3f(23.0, -0.5, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(13.0, -3.0, 17.0);
    glVertex3f(7.0, -3.0, 17.0);
    glVertex3f(7.0, -3.0, 19.0);
    glVertex3f(13.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(13.0, -0.5, 17.0);
    glVertex3f(7.0, -0.5, 17.0);
    glVertex3f(7.0, -0.5, 19.0);
    glVertex3f(13.0, -0.5, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(3.0, -3.0, 17.0);
    glVertex3f(-3.0, -3.0, 17.0);
    glVertex3f(-3.0, -3.0, 19.0);
    glVertex3f(3.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(3.0, -0.5, 17.0);
    glVertex3f(-3.0, -0.5, 17.0);
    glVertex3f(-3.0, -0.5, 19.0);
    glVertex3f(3.0, -0.5, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-8.0, -3.0, 17.0);
    glVertex3f(-13.0, -3.0, 17.0);
    glVertex3f(-13.0, -3.0, 19.0);
    glVertex3f(-8.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-8.0, -0.5, 17.0);
    glVertex3f(-13.0, -0.5, 17.0);
    glVertex3f(-13.0, -0.5, 19.0);
    glVertex3f(-8.0, -0.5, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-18.0, -3.0, 17.0);
    glVertex3f(-23.0, -3.0, 17.0);
    glVertex3f(-23.0, -3.0, 19.0);
    glVertex3f(-18.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-18.0, -0.5, 17.0);
    glVertex3f(-23.0, -0.5, 17.0);
    glVertex3f(-23.0, -0.5, 19.0);
    glVertex3f(-18.0, -0.5, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-28.0, -3.0, 17.0);
    glVertex3f(-33.0, -3.0, 17.0);
    glVertex3f(-33.0, -3.0, 19.0);
    glVertex3f(-28.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-28.0, -0.5, 17.0);
    glVertex3f(-33.0, -0.5, 17.0);
    glVertex3f(-33.0, -0.5, 19.0);
    glVertex3f(-28.0, -0.5, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-38.0, -3.0, 17.0);
    glVertex3f(-43.0, -3.0, 17.0);
    glVertex3f(-43.0, -3.0, 19.0);
    glVertex3f(-38.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-38.0, -0.5, 17.0);
    glVertex3f(-43.0, -0.5, 17.0);
    glVertex3f(-43.0, -0.5, 19.0);
    glVertex3f(-38.0, -0.5, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-48.0, -3.0, 17.0);
    glVertex3f(-53.0, -3.0, 17.0);
    glVertex3f(-53.0, -3.0, 19.0);
    glVertex3f(-48.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-48.0, -0.5, 17.0);
    glVertex3f(-53.0, -0.5, 17.0);
    glVertex3f(-53.0, -0.5, 19.0);
    glVertex3f(-48.0, -0.5, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-78.0, -3.0, 17.0);
    glVertex3f(-83.0, -3.0, 17.0);
    glVertex3f(-83.0, -3.0, 19.0);
    glVertex3f(-78.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-78.0, -0.5, 17.0);
    glVertex3f(-83.0, -0.5, 17.0);
    glVertex3f(-83.0, -0.5, 19.0);
    glVertex3f(-78.0, -0.5, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-88.0, -3.0, 17.0);
    glVertex3f(-93.0, -3.0, 17.0);
    glVertex3f(-93.0, -3.0, 19.0);
    glVertex3f(-88.0, -3.0, 19.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.9, 2.9, 3.9);
    glVertex3f(-88.0, -0.5, 17.0);
    glVertex3f(-93.0, -0.5, 17.0);
    glVertex3f(-93.0, -0.5, 19.0);
    glVertex3f(-88.0, -0.5, 19.0);
    glEnd();



    glPopMatrix();
    glutSwapBuffers();
}

void idle()
{
    if (!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
        mouseDown = false;
}

void mouseMotion(int x, int y)
{
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {


    case 'a':
        apoz = apoz + 5;
        if (apoz > 360) apoz = 0;
        glutPostRedisplay();
        break;
    case 'd':
        dpoz = dpoz + 5;
        if (dpoz > 360) dpoz = 0;
        glutPostRedisplay();
        break;
    case 'w':
        wpoz = wpoz + 5;
        if (wpoz > 360) wpoz = 0;
        glutPostRedisplay();
        break;
    case 's':
        spoz = spoz + 5;
        if (spoz > 360) spoz = 0;
        glutPostRedisplay();
        break;

    case 'c':
        c = c + 1;
        glutPostRedisplay();
        break;


    }
}
void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1500, 600);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("3d");
    init();
    glutDisplayFunc(tampil);
    glutReshapeFunc(ukuran);

    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);
    glutKeyboardFunc(keyboard);
    glutIdleFunc(tampil);
    glutMainLoop();
    return 0;
}
