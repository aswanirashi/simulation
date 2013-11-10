#include <iostream>
#include <stdlib.h>
#include<stdio.h>
#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include<string.h>
#include "imageloader.h"
float pnt_x=-2.05f , pnt_y = -1.0f ;
int flag=0,number=10,i,len,number_left=1;
char name[10]="2.bmp",final[100],final2[100],folder[100]="0/",final3[100];

//strcpy(name,"2.bmp");

using namespace std;

void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
		case 27: //Escape key
			exit(0);
	}
	
}
//void update(int value);

//Makes the image into a texture, and returns the id of the texture
GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
				 0,                            //0 for now
				 GL_RGB,                       //Format OpenGL uses for image
				 image->width, image->height,  //Width and height
				 0,                            //The border of the image
				 GL_RGB, //GL_RGB, because pixels are stored in RGB format
				 GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
				                   //as unsigned numbers
				 image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}

GLuint _textureId; //The id of the texture
GLuint _textureId1;

int angle=0;
void handleKeypress2(int key, int x, int y)
{
	if (key == GLUT_KEY_LEFT)
        {
                pnt_x=pnt_x-0.005;
		if (angle==0)
			angle=180;
		else
		angle-=45;
		sprintf(folder,"%d/",angle);
                strcpy(final3,"");
                //sprintf(final2,"%d",number);
                strcat(final3,folder);
                strcat(final3,final2);
                strcat(final3,".bmp");

                 Image* image3 = loadBMP(final3);
                _textureId1 = loadTexture(image3);
                delete image3;

        }
        if (key == GLUT_KEY_RIGHT)
        {
                pnt_x=pnt_x+0.005;
		//printf("%f\n",pnt_x);
		//if(pnt_x < -2.02)
		//	pnt_x=pnt_x-0.05;
		if (angle==180)
			angle=0;
		else
		angle+=45;
		sprintf(folder,"%d/",angle);
		strcpy(final3,"");
		sprintf(final2,"%d",number);
		strcat(final3,folder);
                strcat(final3,final2);
                strcat(final3,".bmp");
               // printf("final2_left : %s\n",final3);
                 Image* image3 = loadBMP(final3);
                _textureId1 = loadTexture(image3);
                delete image3;

        }
        if (key == GLUT_KEY_UP)
        {
                pnt_y=pnt_y+0.01;
		if (number==1)
			number=10;
		else
		number=number-1;
		strcpy(final3,"");
		sprintf(final2,"%d",number);
		strcat(final3,folder);
		strcat(final3,final2);
		strcat(final3,".bmp");		
		//printf("final2: %s\n",final3);
		 Image* image2 = loadBMP(final3);
	        _textureId1 = loadTexture(image2);
        	delete image2;

        }
        if (key == GLUT_KEY_DOWN)
        {
                pnt_y=pnt_y-0.01;
		if (number==10)
			number=1;
		else
		number=number+1;
		strcpy(final3,"");
		sprintf(final2,"%d",number);
		strcat(final3,folder);
		strcat(final3,final2);
		strcat(final3,".bmp");		
		//printf("final2: %s\n",final3);
		 Image* image2 = loadBMP(final3);
	        _textureId1 = loadTexture(image2);
        	delete image2;
        }
}

void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	
	Image* image = loadBMP("map.bmp");
	_textureId = loadTexture(image);
	delete image;
	Image* image1 = loadBMP("0/2.bmp");
        _textureId1 = loadTexture(image1);
        delete image1;

	glEnable( GL_POINT_SMOOTH );
    	glEnable( GL_BLEND );
    	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
   	glPointSize( 10.0 );
}

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)w / (float)h, 1.0, 200.0);
}

void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.0f, 1.0f, -6.0f);

	GLfloat ambientLight[] = {0.2f, 0.2f, 0.2f, 1.0f};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

	GLfloat directedLight[] = {0.7f, 0.7f, 0.7f, 1.0f};
	GLfloat directedLightPos[] = {-10.0f, 15.0f, 20.0f, 0.0f};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, directedLight);
	glLightfv(GL_LIGHT0, GL_POSITION, directedLightPos);

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, _textureId);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glColor3f( 1.0f, 0.0f, 0.0f );
	glBegin( GL_POINTS );
	glVertex3f(pnt_x, pnt_y, 2.5f);
	//printf("Rashi\n");
	glEnd();

	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-4.0f, -2.5f, 2.5f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(0.0f, -2.5f, 2.5f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(0.0f, 0.5f, 2.5f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-4.0f, 0.5f, 2.5f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPushMatrix();
//	glEnd();
	glPopMatrix();
	glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, _textureId1);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glBegin(GL_QUADS);

        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(0.0f, -2.5f, 2.5f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(3.0f, -2.5f, 2.5f);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(3.0f, 0.5f, 2.5f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(0.0f, 0.5f, 2.5f);
        glEnd();
	glDisable(GL_TEXTURE_2D);
	glFinish();
	glutSwapBuffers();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1200, 700);
	
	glutCreateWindow("Map");
	initRendering();
	
	glutDisplayFunc(drawScene);
	glutIdleFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	glutSpecialFunc(handleKeypress2);
	//glutTimerFunc(10, update, 0);	
	glutMainLoop();
	return 0;
}








