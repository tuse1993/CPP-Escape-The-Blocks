#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
#include<windows.h>
#include<mmsystem.h>
#include <unistd.h>
#define ESCAPE 27
using namespace std;
void update(int);

float CarMoveX = 0.0f;
float CarMoveY = 0.0f;

int viewFlag = 0;
int cnt = 0;
int carFlag = 0;
int pauseFlag = 0;

float _move1 = 0.0f;
float _move2 = 0.0f;
float _move3 = 0.0f;
float _move4 = 0.0f;
float _move5 = 0.0f;
float _move6 = 0.0f;
float _move7 = 0.0f;
float _move8 = 0.0f;
float score=0;

float a1=0.0f;
float b1=0.12f;
float c1=0.05f;
float d1=0.08f;
float e1=0.04f;
float f1=0.02f;
float g1=0.02f;
float h1=0.02f;

float a2=0.0f;
float b2=0.05f;
float c2=0.05f;
float d2=0.08f;
float e2=0.04f;
float f2=0.02f;
float g2=0.02f;
float h2=0.02f;

float i1=0.02f;
float i2=0.02f;
float i3=0.02f;
float i4=0.02f;

float tree1 = 0.0f;
float tree2 = 0.0f;
float tree3 = 0.0f;
float tree4 = 0.0f;
float tree5 = 0.0f;

float rightLight1 = 0.0f;
float rightLight2 = 0.0f;
float rightLight3 = 0.0f;
float rightLight4 = 0.0f;

float LeftLight1 = 0.0f;
float LeftLight2 = 0.0f;
float LeftLight3 = 0.0f;
float LeftLight4 = 0.0f;

double LightX = 0.0f;
double LightY = 0.0f;
double LightZ = 0.0f;

double GreenX = 0.0f;
double GreenY = 0.73f;
double GreenZ = 0.0f;

double DesertX = 0.91f;
double DesertY = 0.84f;
double DesertZ = 0.49f;

int iSecret1 = rand() % 4 + 1;
int iSecret2 = rand() % 4 + 1;

bool gameOver = false;
static bool paused = false;
char keys='a';
int highscore;


float getX(int x){
    return (float)x/(float)400;
}

float getY(int y){
    return (float)y/(float)400;
}

void drawBlock(int num1, int num2){
    ////////////////////////////////////////////////////////////////
    //Block1
    if(num1 != 1 && num2 != 1)
    {
        glPushMatrix();
        glTranslatef(i1=i1-0.001, _move8, 0.0f);
        glBegin(GL_QUADS);
        glColor3d(1,0,0);
        glVertex3f(getX(-133), getY(350), 0.0f);
        glVertex3f(getX(-87), getY(350), 0.0f);
        glVertex3f(getX(-107), getY(380), 0.0f);
        glVertex3f(getX(-153), getY(380), 0.0f);
        glEnd();


        glBegin(GL_QUADS);
        glColor3d(1,0.5,0);
        glVertex3f(getX(-133), getY(250), 0.0f);
        glVertex3f(getX(-87), getY(250), 0.0f);
        glVertex3f(getX(-87), getY(350), 0.0f);
        glVertex3f(getX(-133), getY(350), 0.0f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3d(1,1,0);
        glVertex3f(getX(-153), getY(280), 0.0f);
        glVertex3f(getX(-133), getY(250), 0.0f);
        glVertex3f(getX(-133), getY(350), 0.0f);
        glVertex3f(getX(-153), getY(380), 0.0f);
        glEnd();
        glPopMatrix();
    }

    //Block2
    if(num1 != 2 && num2 != 2)
    {
        glPushMatrix();
        glTranslatef(i2=i2-0.0005, _move8, 0.0f);
        glBegin(GL_QUADS);
        glColor3d(1,0,0);
        glVertex3f(getX(-53), getY(350), 0.0f);
        glVertex3f(getX(-07), getY(350), 0.0f);
        glVertex3f(getX(-27), getY(380), 0.0f);
        glVertex3f(getX(-73), getY(380), 0.0f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3d(1,0.5,0);
        glVertex3f(getX(-53), getY(250), 0.0f);
        glVertex3f(getX(-07), getY(250), 0.0f);
        glVertex3f(getX(-07), getY(350), 0.0f);
        glVertex3f(getX(-53), getY(350), 0.0f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3d(1,1,0);
        glVertex3f(getX(-73), getY(280), 0.0f);
        glVertex3f(getX(-53), getY(250), 0.0f);
        glVertex3f(getX(-53), getY(350), 0.0f);
        glVertex3f(getX(-73), getY(380), 0.0f);
        glEnd();
        glPopMatrix();
    }

    //Block3

    if(num1 != 3 && num2 != 3)
    {
        glPushMatrix();
        glTranslatef(i3=i3+0.0005, _move8, 0.0f);
        glBegin(GL_QUADS);
        glColor3d(1,0,0);
        glVertex3f(getX(27), getY(350), 0.0f);
        glVertex3f(getX(73), getY(350), 0.0f);
        glVertex3f(getX(53), getY(380), 0.0f);
        glVertex3f(getX(7), getY(380), 0.0f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3d(1,0.5,0);
        glVertex3f(getX(27), getY(250), 0.0f);
        glVertex3f(getX(73), getY(250), 0.0f);
        glVertex3f(getX(73), getY(350), 0.0f);
        glVertex3f(getX(27), getY(350), 0.0f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3d(1,1,0);
        glVertex3f(getX(7), getY(280), 0.0f);
        glVertex3f(getX(27), getY(250), 0.0f);
        glVertex3f(getX(27), getY(350), 0.0f);
        glVertex3f(getX(7), getY(380), 0.0f);
        glEnd();
        glPopMatrix();
    }

    //Block4
    if(num1 != 4 && num2 != 4)
    {
        glPushMatrix();
        glTranslatef(i4=i4+0.001, _move8, 0.0f);
        glBegin(GL_QUADS);
        glColor3d(1,0,0);
        glVertex3f(getX(107), getY(350), 0.0f);
        glVertex3f(getX(153), getY(350), 0.0f);
        glVertex3f(getX(133), getY(380), 0.0f);
        glVertex3f(getX(87), getY(380), 0.0f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3d(1,0.5,0);
        glVertex3f(getX(107), getY(250), 0.0f);
        glVertex3f(getX(153), getY(250), 0.0f);
        glVertex3f(getX(153), getY(350), 0.0f);
        glVertex3f(getX(107), getY(350), 0.0f);
        glEnd();

        glBegin(GL_QUADS);
        glColor3d(1,1,0);
        glVertex3f(getX(87), getY(280), 0.0f);
        glVertex3f(getX(107), getY(250), 0.0f);
        glVertex3f(getX(107), getY(350), 0.0f);
        glVertex3f(getX(87), getY(380), 0.0f);
        glEnd();
        glPopMatrix();
    }

}

void drawLeftCar()
{
    //car..................................
    glPushMatrix();
    glTranslatef(CarMoveX, CarMoveY, 0.0f);
    glColor3d(.57,.57,.57);
    glBegin(GL_QUADS);
    glVertex3f(getX(-150), getY(-280), 0.0f);//b
    glVertex3f(getX(-50), getY(-280), 0.0f);//a

    glVertex3f(getX(-25), getY(-100), 0.0f);//c
    glVertex3f(getX(-120), getY(-100), 0.0f);//d
    glEnd();

    glColor3d(.57,.57,.57);
    glBegin(GL_QUADS);
    glVertex3f(getX(-155), getY(-230), 0.0f);//b
    glVertex3f(getX(-55), getY(-230), 0.0f);//a

    glVertex3f(getX(-40), getY(-130), 0.0f);//c
    glVertex3f(getX(-135), getY(-130), 0.0f);//d
    glEnd();

    glColor3d(1,1,1);
    glBegin(GL_QUADS);
    glVertex3f(getX(-135), getY(-130), 0.0f);//b
    glVertex3f(getX(-40), getY(-130), 0.0f);//a

    glVertex3f(getX(-28), getY(-120), 0.0f);//c
    glVertex3f(getX(-120), getY(-120), 0.0f);//d
    glEnd();

    glColor3d(1,1,1);
    glBegin(GL_QUADS);
    glVertex3f(getX(-145), getY(-250), 0.0f);//b
    glVertex3f(getX(-45), getY(-250), 0.0f);//a

    glVertex3f(getX(-55), getY(-230), 0.0f);//c
    glVertex3f(getX(-155), getY(-230), 0.0f);//d
    glEnd();

    glColor3d(.46,.46,.46);
    glBegin(GL_QUADS);
    glVertex3f(getX(-50), getY(-280), 0.0f);//b
    glVertex3f(getX(-45), getY(-285), 0.0f);//a

    glVertex3f(getX(-20), getY(-110), 0.0f);//c
    glVertex3f(getX(-25), getY(-100), 0.0f);//d
    glEnd();

    glColor3d(0,0,0);
    glBegin(GL_QUADS);
    glVertex3f(getX(-55), getY(-230), 0.0f);//b
    glVertex3f(getX(-45), getY(-250), 0.0f);//a

    glVertex3f(getX(-28), getY(-120), 0.0f);//c
    glVertex3f(getX(-40), getY(-130), 0.0f);//d
    glEnd();

    glColor3d(0,0,0);
    glBegin(GL_QUADS);
    glVertex3f(getX(-145), getY(-285), 0.0f);//b
    glVertex3f(getX(-45), getY(-285), 0.0f);//a

    glVertex3f(getX(-50), getY(-280), 0.0f);//c
    glVertex3f(getX(-150), getY(-280), 0.0f);//d
    glEnd();
    glPopMatrix();
}

void drawRightCar()
{
    glPushMatrix();
    glTranslatef(CarMoveX-.3, CarMoveY, 0.0f);
    glColor3d(.57,.57,.57);
    glBegin(GL_QUADS);
    glVertex3f(getX(150), getY(-280), 0.0f);//b
    glVertex3f(getX(50), getY(-280), 0.0f);//a

    glVertex3f(getX(25), getY(-100), 0.0f);//c
    glVertex3f(getX(120), getY(-100), 0.0f);//d
    glEnd();

    glColor3d(.57,.57,.57);
    glBegin(GL_QUADS);
    glVertex3f(getX(155), getY(-230), 0.0f);//b
    glVertex3f(getX(55), getY(-230), 0.0f);//a

    glVertex3f(getX(40), getY(-130), 0.0f);//c
    glVertex3f(getX(135), getY(-130), 0.0f);//d
    glEnd();

    glColor3d(1,1,1);
    glBegin(GL_QUADS);
    glVertex3f(getX(135), getY(-130), 0.0f);//b
    glVertex3f(getX(40), getY(-130), 0.0f);//a

    glVertex3f(getX(28), getY(-120), 0.0f);//c
    glVertex3f(getX(120), getY(-120), 0.0f);//d
    glEnd();

    glColor3d(1,1,1);
    glBegin(GL_QUADS);
    glVertex3f(getX(145), getY(-250), 0.0f);//b
    glVertex3f(getX(45), getY(-250), 0.0f);//a

    glVertex3f(getX(55), getY(-230), 0.0f);//c
    glVertex3f(getX(155), getY(-230), 0.0f);//d
    glEnd();

    glColor3d(.46,.46,.46);
    glBegin(GL_QUADS);
    glVertex3f(getX(50), getY(-280), 0.0f);//b
    glVertex3f(getX(45), getY(-285), 0.0f);//a

    glVertex3f(getX(20), getY(-110), 0.0f);//c
    glVertex3f(getX(25), getY(-100), 0.0f);//d
    glEnd();

    glColor3d(0,0,0);
    glBegin(GL_QUADS);
    glVertex3f(getX(55), getY(-230), 0.0f);//b
    glVertex3f(getX(45), getY(-250), 0.0f);//a

    glVertex3f(getX(28), getY(-120), 0.0f);//c
    glVertex3f(getX(40), getY(-130), 0.0f);//d
    glEnd();

    glColor3d(0,0,0);
    glBegin(GL_QUADS);
    glVertex3f(getX(145), getY(-285), 0.0f);//b
    glVertex3f(getX(45), getY(-285), 0.0f);//a

    glVertex3f(getX(50), getY(-280), 0.0f);//c
    glVertex3f(getX(150), getY(-280), 0.0f);//d
    glEnd();
    glPopMatrix();
}

void specialKeys(int key, int x, int y) {
     switch (key) {
      case GLUT_KEY_RIGHT:
        if(CarMoveX < 0.70){
            CarMoveX += 0.05f;
            glutPostRedisplay();
            if(CarMoveX > 0.25)
            {
                carFlag = 1;
            }
            break;
        }

         break;

      case GLUT_KEY_LEFT:
          if(CarMoveX>-0.35){
            CarMoveX-=0.05f;
            glutPostRedisplay();
            if(CarMoveX < 0.25)
            {
              carFlag = 0;
            }
            break;
          }

           break;
      case GLUT_KEY_UP:
        if(CarMoveY < 0){
            CarMoveY += 0.05f;
            glutPostRedisplay();
            break;
        }
         break;
      case GLUT_KEY_DOWN:
        if(CarMoveY>-0.35){
            CarMoveY-=0.05f;
            glutPostRedisplay();
            break;
          }
           break;
      default:
        break;

    }
}

void drawGameOver(void * font, char *s, int point, float x, float y){
    glRasterPos2f(x, y);
	 glColor3f(1.0, 1.0, 1.0);

     for (int i = 0; i < strlen (s); i++){
          glutBitmapCharacter (font, s[i]);
          }

    if(point != 0)
    {
         int temp = point;
         int countArr=0;
         int pointArr[5];

         while(temp > 9)
         {
            pointArr[countArr] = temp%10;
            temp /= 10;
            countArr++;
         }
         pointArr[countArr] = temp%10;
         countArr++;
         for(int i = countArr; i>=0; i--){
            glutBitmapCharacter(font,48+ (pointArr[i]));
         }
    }
}

void drawScore(void * font, char *s, int point, float x, float y){
     glRasterPos2f(x, y);
	 glColor3f(1.0, 1.0, 1.0);

     for (int i = 0; i < strlen (s); i++){
          glutBitmapCharacter (font, s[i]);
          }
     int temp = point;
     int countArr=0;
     int pointArr[5];

     while(temp > 9)
     {
        pointArr[countArr] = temp%10;
        temp /= 10;
        countArr++;
     }
     pointArr[countArr] = temp%10;
     countArr++;
     for(int i = countArr; i>=0; i--){
        glutBitmapCharacter(font,48+ (pointArr[i]));
     }
}

void drawGreenView(){
    //Left side green triangle
    glColor3d(GreenX,GreenY,GreenZ);
    glBegin(GL_QUADS);
    glVertex3f(getX(-400), getY(400), 0.0f);
    glVertex3f(getX(-120), getY(400), 0.0f);
    glVertex3f(getX(-400), getY(-400), 0.0f);
    glVertex3f(getX(-400), getY(-400), 0.0f);
    glEnd();

    //Right side green triangle
    glColor3d(GreenX,GreenY,GreenZ);
    glBegin(GL_QUADS);
    glVertex3f(getX(120), getY(400), 0.0f);
    glVertex3f(getX(400), getY(400), 0.0f);
    glVertex3f(getX(400), getY(-400), 0.0f);
    glVertex3f(getX(400), getY(-400), 0.0f);
    glEnd();

    //Left side red triangle
    glColor3d(1,0,0);
    glBegin(GL_QUADS);
    glVertex3f(getX(-120), getY(400), 0.0f);//a
    glVertex3f(getX(-120), getY(400), 0.0f);//b
    glVertex3f(getX(-400), getY(-400), 0.0f);//c
    glVertex3f(getX(-350), getY(-400), 0.0f);//d
    glEnd();

    //Right side red triangle
    glColor3d(1,0,0);
    glBegin(GL_QUADS);
    glVertex3f(getX(120), getY(400), 0.0f);//a
    glVertex3f(getX(120), getY(400), 0.0f);//b
    glVertex3f(getX(400), getY(-400), 0.0f);//c
    glVertex3f(getX(350), getY(-400), 0.0f);//d
    glEnd();

    //Crismass Tree...............................1
    glPushMatrix();
    glTranslatef(tree1=tree1-0.0015, _move3, 0.0f);
    glPushMatrix();
    glTranslatef(getX(0),getY(-200) , 0.0f);
    glColor3d(.53,.27,0);
    glBegin(GL_POLYGON);
    glVertex2f(getX(-357),getY(90));
    glVertex2f(getX(-343),getY(90));
    glVertex2f(getX(-343),getY(140));
    glVertex2f(getX(-357),getY(140));
    glEnd();

    glColor3d(.11,.55,.24);
    glBegin(GL_POLYGON);
    glVertex2f(getX(-390),getY(140));
    glVertex2f(getX(-310),getY(140));
    glVertex2f(getX(-350),getY(170));
    glEnd();

    glColor3d(.11,.55,.24);
    glBegin(GL_POLYGON);
    glVertex2f(getX(-380),getY(158));
    glVertex2f(getX(-320),getY(158));
    glVertex2f(getX(-350),getY(185));
    glEnd();

    glColor3d(.11,.55,.24);
    glBegin(GL_POLYGON);
    glVertex2f(getX(-370),getY(175));
    glVertex2f(getX(-330),getY(175));
    glVertex2f(getX(-350),getY(200));
    glEnd();
    glPopMatrix();
    glPopMatrix();

    /////////////////////////////////////////////////////////////2
    glPushMatrix();
    glTranslatef(tree2=tree2-0.0015, _move5, 0.0f);
    glPushMatrix();
    glTranslatef(getX(0),getY(150) , 0.0f);
    glColor3d(.53,.27,0);
    glBegin(GL_POLYGON);
    glVertex2f(getX(-357),getY(90));
    glVertex2f(getX(-343),getY(90));
    glVertex2f(getX(-343),getY(140));
    glVertex2f(getX(-357),getY(140));
    glEnd();

    glColor3d(.11,.55,.24);
    glBegin(GL_POLYGON);
    glVertex2f(getX(-390),getY(140));
    glVertex2f(getX(-310),getY(140));
    glVertex2f(getX(-350),getY(170));
    glEnd();

    glColor3d(.11,.55,.24);
    glBegin(GL_POLYGON);
    glVertex2f(getX(-380),getY(158));
    glVertex2f(getX(-320),getY(158));
    glVertex2f(getX(-350),getY(185));
    glEnd();

    glColor3d(.11,.55,.24);
    glBegin(GL_POLYGON);
    glVertex2f(getX(-370),getY(175));
    glVertex2f(getX(-330),getY(175));
    glVertex2f(getX(-350),getY(200));
    glEnd();
    glPopMatrix();
    glPopMatrix();
    ////////////////////////////////////////////////////////3
    glPushMatrix();
    glTranslatef(tree3=tree3-0.0015, _move5, 0.0f);
    glPushMatrix();
    glTranslatef(getX(80),getY(0) , 0.0f);
    glColor3d(.53,.27,0);
    glBegin(GL_POLYGON);
    glVertex2f(getX(-357),getY(90));
    glVertex2f(getX(-343),getY(90));
    glVertex2f(getX(-343),getY(140));
    glVertex2f(getX(-357),getY(140));
    glEnd();

    glColor3d(.11,.55,.24);
    glBegin(GL_POLYGON);
    glVertex2f(getX(-390),getY(140));
    glVertex2f(getX(-310),getY(140));
    glVertex2f(getX(-350),getY(170));
    glEnd();

    glColor3d(.11,.55,.24);
    glBegin(GL_POLYGON);
    glVertex2f(getX(-380),getY(158));
    glVertex2f(getX(-320),getY(158));
    glVertex2f(getX(-350),getY(185));
    glEnd();

    glColor3d(.11,.55,.24);
    glBegin(GL_POLYGON);
    glVertex2f(getX(-370),getY(175));
    glVertex2f(getX(-330),getY(175));
    glVertex2f(getX(-350),getY(200));
    glEnd();
    glPopMatrix();
    glPopMatrix();

    //////////////////////////////////////////////////////////4
    glPushMatrix();
    glTranslatef(tree4=tree4+0.0015, _move4, 0.0f);
    glPushMatrix();
    glTranslatef(getX(650),getY(-100) , 0.0f);
    glColor3d(.53,.27,0);
    glBegin(GL_POLYGON);
    glVertex2f(getX(-357),getY(90));
    glVertex2f(getX(-343),getY(90));
    glVertex2f(getX(-343),getY(140));
    glVertex2f(getX(-357),getY(140));
    glEnd();

    glColor3d(.11,.55,.24);
    glBegin(GL_POLYGON);
    glVertex2f(getX(-390),getY(140));
    glVertex2f(getX(-310),getY(140));
    glVertex2f(getX(-350),getY(170));
    glEnd();

    glColor3d(.11,.55,.24);
    glBegin(GL_POLYGON);
    glVertex2f(getX(-380),getY(158));
    glVertex2f(getX(-320),getY(158));
    glVertex2f(getX(-350),getY(185));
    glEnd();

    glColor3d(.11,.55,.24);
    glBegin(GL_POLYGON);
    glVertex2f(getX(-370),getY(175));
    glVertex2f(getX(-330),getY(175));
    glVertex2f(getX(-350),getY(200));
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void drawDesertView(){
   //Left side Yellow triangle
    glColor3d(DesertX,DesertY,DesertZ);
    glBegin(GL_QUADS);
    glVertex3f(getX(-400), getY(400), 0.0f);
    glVertex3f(getX(-120), getY(400), 0.0f);
    glVertex3f(getX(-400), getY(-400), 0.0f);
    glVertex3f(getX(-400), getY(-400), 0.0f);
    glEnd();

//Right side Yellow triangle
    glColor3d(DesertX,DesertY,DesertZ);
    glBegin(GL_QUADS);
    glVertex3f(getX(120), getY(400), 0.0f);
    glVertex3f(getX(400), getY(400), 0.0f);
    glVertex3f(getX(400), getY(-400), 0.0f);
    glVertex3f(getX(400), getY(-400), 0.0f);
    glEnd();

//Left side red triangle
    glColor3d(1,0,0);
    glBegin(GL_QUADS);
    glVertex3f(getX(-120), getY(400), 0.0f);//a
    glVertex3f(getX(-120), getY(400), 0.0f);//b
    glVertex3f(getX(-400), getY(-400), 0.0f);//c
    glVertex3f(getX(-350), getY(-400), 0.0f);//d
    glEnd();

//Right side red triangle
    glColor3d(1,0,0);
    glBegin(GL_QUADS);
    glVertex3f(getX(120), getY(400), 0.0f);//a
    glVertex3f(getX(120), getY(400), 0.0f);//b
    glVertex3f(getX(400), getY(-400), 0.0f);//c
    glVertex3f(getX(350), getY(-400), 0.0f);//d
    glEnd();

//caktas tree......................................1
    glPushMatrix();
    glTranslatef(tree1=tree1-0.0015, _move3, 0.0f);
    glPushMatrix();
    glTranslatef(getX(0),getY(-200) , 0.0f);
    glColor3d(0,.5,0);
    glBegin(GL_POLYGON);
    glVertex2f(getX(-365),getY(90));
    glVertex2f(getX(-335),getY(90));
    glVertex2f(getX(-350),getY(180));
    glEnd();

    glColor3d(0,.5,0);
    glBegin(GL_POLYGON);
    glVertex2f(getX(-365),getY(90));
    glVertex2f(getX(-335),getY(90));
    glVertex2f(getX(-375),getY(150));
    glEnd();

    glColor3d(0,.5,0);
    glBegin(GL_POLYGON);
    glVertex2f(getX(-365),getY(90));
    glVertex2f(getX(-335),getY(90));
    glVertex2f(getX(-325),getY(150));
    glEnd();
    glPopMatrix();
    glPopMatrix();

    ///////////////////////////////////////////////////////2
    glPushMatrix();
    glTranslatef(tree2=tree2-0.0015, _move5, 0.0f);
    glPushMatrix();
    glTranslatef(getX(0),getY(150) , 0.0f);
    glColor3d(0,.5,0);
    glBegin(GL_POLYGON);
    glVertex2f(getX(-365),getY(90));
    glVertex2f(getX(-335),getY(90));
    glVertex2f(getX(-350),getY(180));
    glEnd();

    glColor3d(0,.5,0);
    glBegin(GL_POLYGON);
    glVertex2f(getX(-365),getY(90));
    glVertex2f(getX(-335),getY(90));
    glVertex2f(getX(-375),getY(150));
    glEnd();

    glColor3d(0,.5,0);
    glBegin(GL_POLYGON);
    glVertex2f(getX(-365),getY(90));
    glVertex2f(getX(-335),getY(90));
    glVertex2f(getX(-325),getY(150));
    glEnd();
    glPopMatrix();
    glPopMatrix();

    ////////////////////////////////////////////////////////////3
    glPushMatrix();
    glTranslatef(tree3=tree3-0.0015, _move5, 0.0f);
    glPushMatrix();
    glTranslatef(getX(80),getY(0) , 0.0f);
    glColor3d(0,.5,0);
    glBegin(GL_POLYGON);
    glVertex2f(getX(-365),getY(90));
    glVertex2f(getX(-335),getY(90));
    glVertex2f(getX(-350),getY(180));
    glEnd();

    glColor3d(0,.5,0);
    glBegin(GL_POLYGON);
    glVertex2f(getX(-365),getY(90));
    glVertex2f(getX(-335),getY(90));
    glVertex2f(getX(-375),getY(150));
    glEnd();

    glColor3d(0,.5,0);
    glBegin(GL_POLYGON);
    glVertex2f(getX(-365),getY(90));
    glVertex2f(getX(-335),getY(90));
    glVertex2f(getX(-325),getY(150));
    glEnd();
    glPopMatrix();
    glPopMatrix();

    //////////////////////////////////////////////////////////////4
    glPushMatrix();
    glTranslatef(tree4=tree4+0.0015, _move4, 0.0f);
    glPushMatrix();
    glTranslatef(getX(650),getY(-100) , 0.0f);
    glColor3d(0,.5,0);
    glBegin(GL_POLYGON);
    glVertex2f(getX(-365),getY(90));
    glVertex2f(getX(-335),getY(90));
    glVertex2f(getX(-350),getY(180));
    glEnd();

    glColor3d(0,.5,0);
    glBegin(GL_POLYGON);
    glVertex2f(getX(-365),getY(90));
    glVertex2f(getX(-335),getY(90));
    glVertex2f(getX(-375),getY(150));
    glEnd();

    glColor3d(0,.5,0);
    glBegin(GL_POLYGON);
    glVertex2f(getX(-365),getY(90));
    glVertex2f(getX(-335),getY(90));
    glVertex2f(getX(-325),getY(150));
    glEnd();
    glPopMatrix();
    glPopMatrix();

    /////////////////////////////////////////////////////////////5
    glPushMatrix();
    glTranslatef(tree5=tree5+0.0015, _move7, 0.0f);
    glPushMatrix();
    glTranslatef(getX(600),getY(200) , 0.0f);
    glColor3d(0,.5,0);
    glBegin(GL_POLYGON);
    glVertex2f(getX(-365),getY(90));
    glVertex2f(getX(-335),getY(90));
    glVertex2f(getX(-350),getY(180));
    glEnd();

    glColor3d(0,.5,0);
    glBegin(GL_POLYGON);
    glVertex2f(getX(-365),getY(90));
    glVertex2f(getX(-335),getY(90));
    glVertex2f(getX(-375),getY(150));
    glEnd();

    glColor3d(0,.5,0);
    glBegin(GL_POLYGON);
    glVertex2f(getX(-365),getY(90));
    glVertex2f(getX(-335),getY(90));
    glVertex2f(getX(-325),getY(150));
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void drawRightLightPost(){
    glPushMatrix();
    glTranslatef(rightLight1=rightLight1+0.0018, _move1, 0.0f);
    glPushMatrix();
    glTranslatef(0.01f, 0.0f, 0.0f);
    glColor3d(.24,1,1);
    glBegin(GL_QUADS);
    glVertex3f(getX(370), getY(-310), 0.0f);//b
    glVertex3f(getX(380), getY(-310), 0.0f);//a

    glVertex3f(getX(380), getY(-170), 0.0f);//c
    glVertex3f(getX(370), getY(-170), 0.0f);//d
    glEnd();

    glColor3d(.24,1,1);
    glBegin(GL_QUADS);
    glVertex3f(getX(320), getY(-170), 0.0f);//b
    glVertex3f(getX(370), getY(-170), 0.0f);//a

    glVertex3f(getX(370), getY(-180), 0.0f);//c
    glVertex3f(getX(320), getY(-180), 0.0f);//d
    glEnd();

    glColor3d(LightX,LightY,LightZ);
    glBegin(GL_QUADS);
    glVertex3f(getX(320), getY(-180), 0.0f);//b
    glVertex3f(getX(340), getY(-180), 0.0f);//a

    glVertex3f(getX(340), getY(-190), 0.0f);//c
    glVertex3f(getX(320), getY(-190), 0.0f);//d
    glEnd();
    glPopMatrix();
    glPopMatrix();

    ////////////////////////////////////////////////2
    glPushMatrix();
    glTranslatef(rightLight2=rightLight2+0.0018, _move3, 0.0f);
    glPushMatrix();
    glTranslatef(getX(-60), getY(180), 0.0f);
    glColor3d(.24,1,1);
    glBegin(GL_QUADS);
    glVertex3f(getX(370), getY(-310), 0.0f);//b
    glVertex3f(getX(380), getY(-310), 0.0f);//a

    glVertex3f(getX(380), getY(-170), 0.0f);//c
    glVertex3f(getX(370), getY(-170), 0.0f);//d
    glEnd();

    glColor3d(.24,1,1);
    glBegin(GL_QUADS);
    glVertex3f(getX(320), getY(-170), 0.0f);//b
    glVertex3f(getX(370), getY(-170), 0.0f);//a

    glVertex3f(getX(370), getY(-180), 0.0f);//c
    glVertex3f(getX(320), getY(-180), 0.0f);//d
    glEnd();

    glColor3d(LightX,LightY,LightZ);
    glBegin(GL_QUADS);
    glVertex3f(getX(320), getY(-180), 0.0f);//b
    glVertex3f(getX(340), getY(-180), 0.0f);//a

    glVertex3f(getX(340), getY(-190), 0.0f);//c
    glVertex3f(getX(320), getY(-190), 0.0f);//d
    glEnd();
    glPopMatrix();
    glPopMatrix();

    ///////////////////////////////////////////////////////3
    glPushMatrix();
    glTranslatef(rightLight3=rightLight3+0.0018, _move5, 0.0f);
    glPushMatrix();
    glTranslatef(getX(-125), getY(380), 0.0f);
    glColor3d(.24,1,1);
    glBegin(GL_QUADS);
    glVertex3f(getX(370), getY(-310), 0.0f);//b
    glVertex3f(getX(380), getY(-310), 0.0f);//a

    glVertex3f(getX(380), getY(-170), 0.0f);//c
    glVertex3f(getX(370), getY(-170), 0.0f);//d
    glEnd();

    glColor3d(.24,1,1);
    glBegin(GL_QUADS);
    glVertex3f(getX(320), getY(-170), 0.0f);//b
    glVertex3f(getX(370), getY(-170), 0.0f);//a

    glVertex3f(getX(370), getY(-180), 0.0f);//c
    glVertex3f(getX(320), getY(-180), 0.0f);//d
    glEnd();

    glColor3d(LightX,LightY,LightZ);
    glBegin(GL_QUADS);
    glVertex3f(getX(320), getY(-180), 0.0f);//b
    glVertex3f(getX(340), getY(-180), 0.0f);//a

    glVertex3f(getX(340), getY(-190), 0.0f);//c
    glVertex3f(getX(320), getY(-190), 0.0f);//d
    glEnd();
    glPopMatrix();
    glPopMatrix();

    //////////////////////////////////////////////////4
    glPushMatrix();
    glTranslatef(rightLight4=rightLight4+0.0018, _move7, 0.0f);
    glPushMatrix();
    glTranslatef(getX(-200), getY(590), 0.0f);
    glColor3d(.24,1,1);
    glBegin(GL_QUADS);
    glVertex3f(getX(370), getY(-310), 0.0f);//b
    glVertex3f(getX(380), getY(-310), 0.0f);//a

    glVertex3f(getX(380), getY(-170), 0.0f);//c
    glVertex3f(getX(370), getY(-170), 0.0f);//d
    glEnd();

    glColor3d(.24,1,1);
    glBegin(GL_QUADS);
    glVertex3f(getX(320), getY(-170), 0.0f);//b
    glVertex3f(getX(370), getY(-170), 0.0f);//a

    glVertex3f(getX(370), getY(-180), 0.0f);//c
    glVertex3f(getX(320), getY(-180), 0.0f);//d
    glEnd();

    glColor3d(LightX,LightY,LightZ);
    glBegin(GL_QUADS);
    glVertex3f(getX(320), getY(-180), 0.0f);//b
    glVertex3f(getX(340), getY(-180), 0.0f);//a

    glVertex3f(getX(340), getY(-190), 0.0f);//c
    glVertex3f(getX(320), getY(-190), 0.0f);//d
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void drawLeftLightPost(){
    glPushMatrix();
    glTranslatef(LeftLight1=LeftLight1-0.0018, _move1, 0.0f);
    glPushMatrix();
    glTranslatef(getX(-5), 0.0f, 0.0f);
    glColor3d(.24,1,1);
    glBegin(GL_QUADS);
    glVertex3f(getX(-370), getY(-310), 0.0f);//b
    glVertex3f(getX(-380), getY(-310), 0.0f);//a

    glVertex3f(getX(-380), getY(-170), 0.0f);//c
    glVertex3f(getX(-370), getY(-170), 0.0f);//d
    glEnd();

    glColor3d(.24,1,1);
    glBegin(GL_QUADS);
    glVertex3f(getX(-320), getY(-170), 0.0f);//b
    glVertex3f(getX(-370), getY(-170), 0.0f);//a

    glVertex3f(getX(-370), getY(-180), 0.0f);//c
    glVertex3f(getX(-320), getY(-180), 0.0f);//d
    glEnd();

    glColor3d(LightX,LightY,LightZ);
    glBegin(GL_QUADS);
    glVertex3f(getX(-320), getY(-180), 0.0f);//b
    glVertex3f(getX(-340), getY(-180), 0.0f);//a

    glVertex3f(getX(-340), getY(-190), 0.0f);//c
    glVertex3f(getX(-320), getY(-190), 0.0f);//d
    glEnd();
    glPopMatrix();
    glPopMatrix();

    ////////////////////////////////////////////////2
    glPushMatrix();
    glTranslatef(LeftLight2=LeftLight2-0.0018, _move3, 0.0f);
    glPushMatrix();
    glTranslatef(getX(55), getY(180), 0.0f);
    glColor3d(.24,1,1);
    glBegin(GL_QUADS);
    glVertex3f(getX(-370), getY(-310), 0.0f);//b
    glVertex3f(getX(-380), getY(-310), 0.0f);//a

    glVertex3f(getX(-380), getY(-170), 0.0f);//c
    glVertex3f(getX(-370), getY(-170), 0.0f);//d
    glEnd();

    glColor3d(.24,1,1);
    glBegin(GL_QUADS);
    glVertex3f(getX(-320), getY(-170), 0.0f);//b
    glVertex3f(getX(-370), getY(-170), 0.0f);//a

    glVertex3f(getX(-370), getY(-180), 0.0f);//c
    glVertex3f(getX(-320), getY(-180), 0.0f);//d
    glEnd();

    glColor3d(LightX,LightY,LightZ);
    glBegin(GL_QUADS);
    glVertex3f(getX(-320), getY(-180), 0.0f);//b
    glVertex3f(getX(-340), getY(-180), 0.0f);//a

    glVertex3f(getX(-340), getY(-190), 0.0f);//c
    glVertex3f(getX(-320), getY(-190), 0.0f);//d
    glEnd();
    glPopMatrix();
    glPopMatrix();

    ///////////////////////////////////////////////////////3
    glPushMatrix();
    glTranslatef(LeftLight3=LeftLight3-0.0018, _move5, 0.0f);
    glPushMatrix();
    glTranslatef(getX(125), getY(380), 0.0f);
    glColor3d(.24,1,1);
    glBegin(GL_QUADS);
    glVertex3f(getX(-370), getY(-310), 0.0f);//b
    glVertex3f(getX(-380), getY(-310), 0.0f);//a

    glVertex3f(getX(-380), getY(-170), 0.0f);//c
    glVertex3f(getX(-370), getY(-170), 0.0f);//d
    glEnd();

    glColor3d(.24,1,1);
    glBegin(GL_QUADS);
    glVertex3f(getX(-320), getY(-170), 0.0f);//b
    glVertex3f(getX(-370), getY(-170), 0.0f);//a

    glVertex3f(getX(-370), getY(-180), 0.0f);//c
    glVertex3f(getX(-320), getY(-180), 0.0f);//d
    glEnd();

    glColor3d(LightX,LightY,LightZ);
    glBegin(GL_QUADS);
    glVertex3f(getX(-320), getY(-180), 0.0f);//b
    glVertex3f(getX(-340), getY(-180), 0.0f);//a

    glVertex3f(getX(-340), getY(-190), 0.0f);//c
    glVertex3f(getX(-320), getY(-190), 0.0f);//d
    glEnd();
    glPopMatrix();
    glPopMatrix();

    //////////////////////////////////////////////////4
    glPushMatrix();
    glTranslatef(LeftLight4=LeftLight4-0.0018, _move7, 0.0f);
    glPushMatrix();
    glTranslatef(getX(200), getY(590), 0.0f);
    glColor3d(.24,1,1);
    glBegin(GL_QUADS);
    glVertex3f(getX(-370), getY(-310), 0.0f);//b
    glVertex3f(getX(-380), getY(-310), 0.0f);//a

    glVertex3f(getX(-380), getY(-170), 0.0f);//c
    glVertex3f(getX(-370), getY(-170), 0.0f);//d
    glEnd();

    glColor3d(.24,1,1);
    glBegin(GL_QUADS);
    glVertex3f(getX(-320), getY(-170), 0.0f);//b
    glVertex3f(getX(-370), getY(-170), 0.0f);//a

    glVertex3f(getX(-370), getY(-180), 0.0f);//c
    glVertex3f(getX(-320), getY(-180), 0.0f);//d
    glEnd();

    glColor3d(LightX,LightY,LightZ);
    glBegin(GL_QUADS);
    glVertex3f(getX(-320), getY(-180), 0.0f);//b
    glVertex3f(getX(-340), getY(-180), 0.0f);//a

    glVertex3f(getX(-340), getY(-190), 0.0f);//c
    glVertex3f(getX(-320), getY(-190), 0.0f);//d
    glEnd();
    glPopMatrix();
    glPopMatrix();
}

void keyboard(unsigned char key, int x, int y) {
   switch (key) {
      case 110:     // n key(Night View)
         LightX=1.0;
         LightY=1.0;
         LightZ=1.0;
         GreenX=0.0;
         GreenY=0.0;
         GreenZ=0.0;
         DesertX = 0.0;
         DesertY = 0.0;
         DesertZ = 0.0;
         break;
      case 100:     // d key(Day View)
         LightX=0.0;
         LightY=0.0;
         LightZ=0.0;
         GreenX=0.0;
         GreenY=0.73;
         GreenZ=0.0;
         DesertX = 0.91f;
         DesertY = 0.84f;
         DesertZ = 0.49f;
         break;
      case 112:                   //p key(Pause)
        if(pauseFlag == 0)
        {
            pauseFlag=1;
        }
        break;
      case 115:             //s key(start)
        if(pauseFlag == 1)
        {
            pauseFlag=0;
        }
        break;

   }
}

void drawScene(){
    glClearColor(.24,.24,.24,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);

    if(viewFlag == 0)
    {
        drawGreenView();

    }
    else
    {
        drawDesertView();
    }
//Middle unbrake line
    glColor3d(.87,.84,0);
    glBegin(GL_QUADS);
    glVertex3f(getX(-20), getY(-400), 0.0f);//a
    glVertex3f(getX(20), getY(-400), 0.0f);//b
    glVertex3f(getX(6), getY(400), 0.0f);//c
    glVertex3f(getX(-6), getY(400), 0.0f);//d
    glEnd();

///////////////////////////////////////////////PlaySound(TEXT("Sound Of Tires .wav"),NULL,SND_SYNC);////////////////////////////
    //Middle break line black_1
    glPushMatrix();
    glTranslatef(0.0f, _move1, 0.0f);
    glColor3d(.24,.24,.24);
    glBegin(GL_QUADS);
    glVertex3f(getX(-50), getY(-310), 0.0f);//b
    glVertex3f(getX(50), getY(-310), 0.0f);//a

    glVertex3f(getX(50), getY(-290), 0.0f);//c
    glVertex3f(getX(-50), getY(-290), 0.0f);//d
    glEnd();
    glPopMatrix();

//Middle break line black_2
    glPushMatrix();
    glTranslatef(0.0f, _move2, 0.0f);
    glColor3d(.24,.24,.24);
    glBegin(GL_QUADS);
    glVertex3f(getX(-50), getY(-200), 0.0f);//b
    glVertex3f(getX(50), getY(-200), 0.0f);//a

    glVertex3f(getX(50), getY(-180), 0.0f);//c
    glVertex3f(getX(-50), getY(-180), 0.0f);//d
    glEnd();
    glPopMatrix();

//Middle break line black_3
    glPushMatrix();
    glTranslatef(0.0f, _move3, 0.0f);
    glColor3d(.24,.24,.24);
    glBegin(GL_QUADS);
    glVertex3f(getX(-50), getY(-100), 0.0f);//b
    glVertex3f(getX(50), getY(-100), 0.0f);//a

    //PlaySound(TEXT("Sound Of Tires .wav"),NULL,SND_SYNC);Vertex3f(getX(50), getY(-80), 0.0f);//c
    glVertex3f(getX(-50), getY(-80), 0.0f);//d
    glEnd();
    glPopMatrix();

//Middle break line black_4
    glPushMatrix();
    glTranslatef(0.0f, _move4, 0.0f);
    glColor3d(.24,.24,.24);
    glBegin(GL_QUADS);
    glVertex3f(getX(-50), getY(0), 0.0f);//b
    glVertex3f(getX(50), getY(0), 0.0f);//a

    glVertex3f(getX(50), getY(20), 0.0f);//c
    glVertex3f(getX(-50), getY(20), 0.0f);//d
    glEnd();
    glPopMatrix();

//Middle break line black_5
    glPushMatrix();
    glTranslatef(0.0f, _move5, 0.0f);
    glColor3d(.24,.24,.24);
    glBegin(GL_QUADS);
    glVertex3f(getX(-50), getY(100), 0.0f);//b
    glVertex3f(getX(50), getY(100), 0.0f);//a

    glVertex3f(getX(50), getY(120), 0.0f);//c
    glVertex3f(getX(-50), getY(120), 0.0f);//d
    glEnd();
    glPopMatrix();

//Middle break line black_6
    glPushMatrix();
    glTranslatef(0.0f, _move6, 0.0f);
    glColor3d(.24,.24,.24);
    glBegin(GL_QUADS);
    glVertex3f(getX(-50), getY(200), 0.0f);//b
    glVertex3f(getX(50), getY(200), 0.0f);//a

    glVertex3f(getX(50), getY(220), 0.0f);//c
    glVertex3f(getX(-50), getY(220), 0.0f);//d
    glEnd();
    glPopMatrix();

//Middle break line black_7
    glPushMatrix();
    glTranslatef(0.0f, _move7, 0.0f);
    glColor3d(.24,.24,.24);
    glBegin(GL_QUADS);
    glVertex3f(getX(-50), getY(300), 0.0f);//b
    glVertex3f(getX(50), getY(300), 0.0f);//a

    glVertex3f(getX(50), getY(320), 0.0f);//c
    glVertex3f(getX(-50), getY(320), 0.0f);//d
    glEnd();
    glPopMatrix();

//Middle break line black_8
    glPushMatrix();
    glTranslatef(0.0f, _move8, 0.0f);
    glColor3d(.24,.24,.24);
    glBegin(GL_QUADS);
    glVertex3f(getX(-50), getY(380), 0.0f);//b
    glVertex3f(getX(50), getY(380), 0.0f);//a

    glVertex3f(getX(50), getY(400), 0.0f);//c
    glVertex3f(getX(-50), getY(400), 0.0f);//d
    glEnd();
    glPopMatrix();

//Left break line
    glColor3d(1,1,1);
    glBegin(GL_QUADS);
    glVertex3f(getX(-200), getY(-400), 0.0f);//a
    glVertex3f(getX(-190), getY(-400), 0.0f);//b
    glVertex3f(getX(-50), getY(400), 0.0f);//c
    glVertex3f(getX(-60), getY(400), 0.0f);//d
    glEnd();

///////////////////////////////////////////////////////////////

//Left break line black_1
    glPushMatrix();
    glTranslatef(a2=a2-0.001, _move1, 0.0f);
    glColor3d(.24,.24,.24);
    glBegin(GL_QUADS);
    glVertex3f(getX(-140), getY(-310), 0.0f);//b
    glVertex3f(getX(-190), getY(-310), 0.0f);//a

    glVertex3f(getX(-190), getY(-290), 0.0f);//c
    glVertex3f(getX(-140), getY(-290), 0.0f);//d
    glEnd();
    glPopMatrix();

//Left break line black_2
    glPushMatrix();
    glTranslatef(b2=b2-0.001, _move2, 0.0f);
    glColor3d(.24,.24,.24);
    glBegin(GL_QUADS);
    glVertex3f(getX(-110), getY(-200), 0.0f);//b
    glVertex3f(getX(-190), getY(-200), 0.0f);//a

    glVertex3f(getX(-190), getY(-180), 0.0f);//c
    glVertex3f(getX(-110), getY(-180), 0.0f);//d
    glEnd();
    glPopMatrix();

//Left break line black_3
    glPushMatrix();
    glTranslatef(c2=c2-0.001, _move3, 0.0f);
    glColor3d(.24,.24,.24);
    glBegin(GL_QUADS);
    glVertex3f(getX(-85), getY(-100), 0.0f);//b
    glVertex3f(getX(-170), getY(-100), 0.0f);//a

    glVertex3f(getX(-170), getY(-80), 0.0f);//c
    glVertex3f(getX(-85), getY(-80), 0.0f);//d
    glEnd();
    glPopMatrix();

//Left break line black_4
    glPushMatrix();
    glTranslatef(d2=d2-0.001, _move4, 0.0f);
    glColor3d(.24,.24,.24);
    glBegin(GL_QUADS);
    glVertex3f(getX(-70), getY(0), 0.0f);//b
    glVertex3f(getX(-170), getY(0), 0.0f);//a

    glVertex3f(getX(-170), getY(20), 0.0f);//c
    glVertex3f(getX(-70), getY(20), 0.0f);//d
    glEnd();
    glPopMatrix();

//Left break line black_5
    glPushMatrix();
    glTranslatef(e2=e2-0.001, _move5, 0.0f);
    glColor3d(.24,.24,.24);
    glBegin(GL_QUADS);
    glVertex3f(getX(-60), getY(100), 0.0f);//b
    glVertex3f(getX(-160), getY(100), 0.0f);//a

    glVertex3f(getX(-160), getY(120), 0.0f);//c
    glVertex3f(getX(-60), getY(120), 0.0f);//d
    glEnd();
    glPopMatrix();

//Left break line black_6
    glPushMatrix();
    glTranslatef(f2=f2-0.001, _move6, 0.0f);
    glColor3d(.24,.24,.24);
    glBegin(GL_QUADS);
    glVertex3f(getX(-50), getY(200), 0.0f);//b
    glVertex3f(getX(-140), getY(200), 0.0f);//a

    glVertex3f(getX(-140), getY(220), 0.0f);//c
    glVertex3f(getX(-50), getY(220), 0.0f);//d
    glEnd();
    glPopMatrix();

//Left break line black_7
    glPushMatrix();
    glTranslatef(g2=g2-0.001, _move7, 0.0f);
    glColor3d(.24,.24,.24);
    glBegin(GL_QUADS);
    glVertex3f(getX(-30), getY(300), 0.0f);//b
    glVertex3f(getX(-110), getY(300), 0.0f);//a

    glVertex3f(getX(-110), getY(320), 0.0f);//c
    glVertex3f(getX(-30), getY(320), 0.0f);//d
    glEnd();
    glPopMatrix();

//Left break line black_8
    glPushMatrix();
    glTranslatef(h2=h2-0.001, _move8, 0.0f);
    glColor3d(.24,.24,.24);
    glBegin(GL_QUADS);
    glVertex3f(getX(-25), getY(380), 0.0f);//b
    glVertex3f(getX(-90), getY(380), 0.0f);//a

    glVertex3f(getX(-90), getY(400), 0.0f);//c
    glVertex3f(getX(-25), getY(400), 0.0f);//d
    glEnd();
    glPopMatrix();

//Right break line

////////////////////////////////////////////////////////////////////////
    glColor3d(1,1,1);
    glBegin(GL_QUADS);
    glVertex3f(getX(200), getY(-400), 0.0f);//a
    glVertex3f(getX(190), getY(-400), 0.0f);//b
    glVertex3f(getX(50), getY(400), 0.0f);//c
    glVertex3f(getX(60), getY(400), 0.0f);//d
    glEnd();

//Right break line black_1
    glPushMatrix();
    glTranslatef(a1=a1+0.001, _move1, 0.0f);
    glColor3d(.24,.24,.24);
    glBegin(GL_QUADS);
    glVertex3f(getX(140), getY(-310), 0.0f);//b
    glVertex3f(getX(220), getY(-310), 0.0f);//a

    glVertex3f(getX(220), getY(-290), 0.0f);//c
    glVertex3f(getX(140), getY(-290), 0.0f);//d
    glEnd();
    glPopMatrix();


//Right break line black_2
    glPushMatrix();
    glTranslatef(b1=b1+0.001, _move2, 0.0f);
    glColor3d(.24,.24,.24);
    glBegin(GL_QUADS);
    glVertex3f(getX(90), getY(-200), 0.0f);//b
    glVertex3f(getX(180), getY(-200), 0.0f);//a

    glVertex3f(getX(180), getY(-180), 0.0f);//c
    glVertex3f(getX(90), getY(-180), 0.0f);//d
    glEnd();
    glPopMatrix();


//Right break line black_3
    glPushMatrix();
    glTranslatef(c1=c1+0.001, _move3, 0.0f);
    glColor3d(.24,.24,.24);
    glBegin(GL_QUADS);
    glVertex3f(getX(80), getY(-100), 0.0f);//b
    glVertex3f(getX(180), getY(-100), 0.0f);//a

    glVertex3f(getX(180), getY(-80), 0.0f);//c
    glVertex3f(getX(80), getY(-80), 0.0f);//d
    glEnd();
    glPopMatrix();

//Right break line black_4
    glPushMatrix();
    glTranslatef(d1=d1+0.001, _move4, 0.0f);
    glColor3d(.24,.24,.24);
    glBegin(GL_QUADS);
    glVertex3f(getX(70), getY(0), 0.0f);//b
    glVertex3f(getX(150), getY(0), 0.0f);//a

    glVertex3f(getX(150), getY(20), 0.0f);//c
    glVertex3f(getX(70), getY(20), 0.0f);//d
    glEnd();
    glPopMatrix();



//Right break line black_5
    glPushMatrix();
    glTranslatef(e1=e1+0.001, _move5, 0.0f);
    glColor3d(.24,.24,.24);
    glBegin(GL_QUADS);
    glVertex3f(getX(60), getY(100), 0.0f);//b
    glVertex3f(getX(140), getY(100), 0.0f);//a

    glVertex3f(getX(140), getY(120), 0.0f);//c
    glVertex3f(getX(60), getY(120), 0.0f);//d
    glEnd();
    glPopMatrix();

//Right break line black_6
    glPushMatrix();
    glTranslatef(f1=f1+0.001, _move6, 0.0f);
    glColor3d(.24,.24,.24);
    glBegin(GL_QUADS);
    glVertex3f(getX(50), getY(200), 0.0f);//b
    glVertex3f(getX(120), getY(200), 0.0f);//a

    glVertex3f(getX(120), getY(220), 0.0f);//c
    glVertex3f(getX(50), getY(220), 0.0f);//d
    glEnd();
    glPopMatrix();

//Right break line black_7
    glPushMatrix();
    glTranslatef(g1=g1+0.001, _move7, 0.0f);
    glColor3d(.24,.24,.24);
    glBegin(GL_QUADS);
    glVertex3f(getX(20), getY(300), 0.0f);//b
    glVertex3f(getX(110), getY(300), 0.0f);//a

    glVertex3f(getX(110), getY(320), 0.0f);//c
    glVertex3f(getX(20), getY(320), 0.0f);//d
    glEnd();
    glPopMatrix();

//Right break line black_8
    glPushMatrix();
    glTranslatef(h1=h1+0.001, _move8, 0.0f);
    glColor3d(.24,.24,.24);
    glBegin(GL_QUADS);
    glVertex3f(getX(5), getY(380), 0.0f);//b
    glVertex3f(getX(90), getY(380), 0.0f);//a

    glVertex3f(getX(90), getY(400), 0.0f);//c
    glVertex3f(getX(5), getY(400), 0.0f);//d
    glEnd();
    glPopMatrix();

    if(carFlag == 0)
    {
        drawLeftCar();
    }
    else
    {
        drawRightCar();
    }

    drawBlock(iSecret1, iSecret2);
    drawScore(GLUT_BITMAP_TIMES_ROMAN_24, "Score :: ",score,0.7,.92);
    drawRightLightPost();
    drawLeftLightPost();

    ifstream fin;
    fin.open("HighScore.txt");
    fin>>highscore;
    fin.close();

    drawScore(GLUT_BITMAP_TIMES_ROMAN_24, "High Score :: ",highscore,0.55,.8);
    glutSwapBuffers();
}

void update(int value){

    if(pauseFlag == 0)
    {
        _move1 -= 0.005;
        _move2 -= 0.005;
        _move3 -= 0.005;
        _move4 -= 0.005;
        _move5 -= 0.005;
        _move6 -= 0.005;
        _move7 -= 0.005;
        _move8 -= 0.005;

        if(gameOver==false){
            score += .1;
        }

        if(_move1-0.7 < -1.0)
        {
            _move1 = 1.7;
            a1=-0.3f;
            a2=0.3f;
            rightLight1=-0.6f;
            LeftLight1=0.6f;

        }
        if(_move2-0.5 < -1.0)
        {
            _move2 = 1.5;
            b1=-0.2f;
            b2=0.22f;
        }
        if(_move3-0.2 < -1.0)
        {
            _move3 = 1.2;
            c1=-0.18f;
            c2=0.19f;
            rightLight2=-0.42f;
            LeftLight2=0.42f;
            cnt++;
            if(cnt ==3)
            {
                if(viewFlag == 0)
                    viewFlag=1;
                else
                    viewFlag=0;
                cnt=0;
            }
            else
            {
                tree1=0.3;
            }
        }
        if(_move4 < -1.0)
        {
            _move4 = 1.0;
            d1=-0.15f;
            d2=0.15f;

            tree4=-0.3;
        }
        if(_move5+0.25 < -1.0)
        {
            _move5 = 0.75;
            e1=-0.13f;
            e2=0.13f;
            tree2=0.3;
            tree3=0.2;
            rightLight3=-0.27f;
            LeftLight3=0.27f;
        }
        if(_move6+0.55 < -1.0)
        {
            _move6 = 0.45;
            f1=-0.1f;
            f2=0.1f;
        }
        if(_move7+0.8 < -1.0)
        {
            _move7 = 0.2;
            g1=-0.02f;
            g2=0.02f;
            tree5=-0.1;
            rightLight4=-0.07f;
            LeftLight4=0.07f;
        }
        if(_move8+1.0< -1.0)
        {
            _move8 = 0;
            h1=0.01f;
            h2=-0.01f;
            i1= 0.01f;
            i2= 0.01f;
            i3= 0.01f;
            i4= 0.01f;
            iSecret1 = rand() % 4 + 1;
            iSecret2 = rand() % 4 + 1;
        }
    //..........................................................................................................................
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(10, update, 0); //Notify GLUT to call update again in 20 milliseconds
    }

	else
    {
        glutTimerFunc(1, update, 0);
    }
}

bool Collision(){

    //Collision................................................................................................................
    if(i1 <= -0.151 && CarMoveX < -0.1 && CarMoveX >= -0.4 && _move8 <= -0.82499 && _move8 >= -1.59){

        return true;
    }

    else if(i2 <= -0.064 && CarMoveX > -0.25 && CarMoveX < 0.25 && _move8 <= -0.82499 && _move8 >= -1.59){

          return true;
    }

    else if(i3 > 0.106 && CarMoveX > 0.2 && CarMoveX < 0.65 && _move8 <= -0.82499 && _move8 >= -1.59){

          return true;
    }
    else if(i4 > 0.197 && CarMoveX > 0.5 && CarMoveX < 0.8 && _move8 <= -0.82499 && _move8 >= -1.59){

         return true;
    }
    else{
        return false;
    }
}

void myInit(){
	glClearColor(0, 0, 0, 0);
	glColor3f(1, 1, 0.5);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}

int HighScore(int lastScore){
    ifstream fin;
    fin.open("HighScore.txt");

    fin>>highscore;

    if(lastScore>highscore){
        ofstream fout;
        fout.open("HighScore.txt");

        fout<<lastScore<<endl;
        fout.close();

        return lastScore;
        fin.close();
    }
    else {
        return highscore;
        fin.close();
    }

}

void GameOver(int lastScore){
    myInit();
    drawGameOver(GLUT_BITMAP_TIMES_ROMAN_24, "GAME OVER",0, -.1, .2);
    drawGameOver(GLUT_BITMAP_TIMES_ROMAN_24, "Score :: ",lastScore, -.1, .1);
    highscore=HighScore(lastScore);
    drawGameOver(GLUT_BITMAP_TIMES_ROMAN_24, " High Score :: ",highscore, -.1, 0);
    //pauseFlag=1;
}

void myDisplay(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

    if(gameOver == false)
    {
        drawScene();
    }

    if(Collision())
    {
        gameOver = true;
    }

    if(gameOver == true)
    {   //PlaySound(TEXT("Sound Of Tires .wav"),NULL,SND_SYNC);
        GameOver(score);
    }
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(0, 0);

    glutCreateWindow("Escape The Blocks");
    glutDisplayFunc(myDisplay);
    myInit();
    glutTimerFunc(20, update, 0);
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
