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
#include "glm.h"
float pnt_x=-2.05f , pnt_y = -1.0f ,posx=1.0f , posy=-2.0f , posz=2.5f , posx1 = 1.5f , posy1 =-2.0f , posz1=2.5f,posx2=1.5f,posy2=-2.0f,posz2=2.5f,p_x=-2.05f , p_y=0.0f;
int flag=0,number=10,i,len,number_left=1,see=0;
char name[10]="2.bmp",final[100],final2[100],folder[100]="0/",final3[100];
int modper=0,flag_sur=0;
float prx=0,pry=0;

//strcpy(name,"2.bmp");
float passivex=0,passivey=0,passivez=0,mouseflag=0;
GLMmodel * p1;
GLMmodel * p2;


using namespace std;

void handleKeypress(unsigned char key, int x, int y) {

	if(key== 27) //Escape key
		exit(0);
/*	if(key== 115) //s key
	{
		if(flag_sur==1)
			flag_sur=0;
		else
			flag_sur=1;
	}
	if(key==97)
	{
		if(flag_sur==1)
		{
			posx=posx-0.25f;
			posx1=posx1-0.25f;
		}
	}
	if(key==100)
	{
		if(flag_sur==1)
		{
			posx=posx+0.25f;	
			posx1=posx1+0.25;
		}
	}
	if(key==119)
	{
		if(flag_sur==1)
		{
			posy=posy+0.25f;
			posy1=posy1+0.25f;
		}
	
	}
	
	if(key==122)
        {
                if(flag_sur==1)
		{
			posy1=posy1-0.25f;
                        posy=posy-0.25f;
		}
        
        }
*/
}
	

void update(int value);

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

int angle=0;
void handleKeypress2(int key, int x, int y)
{
/*
	if (key == GLUT_KEY_LEFT)
        {
                pnt_x=pnt_x-0.005;
		if (angle==0)
			angle=180;
		else
			angle-=45;
	//	see=1;
		posx=posx-10;
		posx1=posx1-10;
		if(posx==-49)
		{
			posx=1.0f;
			posx1=1.5f;
		}
		sprintf(folder,"%d/",angle);
                strcpy(final3,"");
                sprintf(final2,"%d",number);
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
		posx=posx+10;
		posx1=posx1+10;
		if(posx==51)
		{
			posx=1.0f;
			posx1=1.5f;
		}
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
*/
}

void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

//	glDepthFunc(GL_LEQUAL);

        p1 = glmReadOBJ("shaolin_left.obj");
        p2 = glmReadOBJ("shaolin_right.obj");
        glmUnitize(p1);
        glmFacetNormals(p1);
        glmVertexNormals(p1, 90.0);

        glmUnitize(p2);
        glmFacetNormals(p2);
        glmVertexNormals(p2, 90.0);
	Image* image = loadBMP("images_new/map.bmp");
	_textureId = loadTexture(image);
	delete image;
/*	Image* image1 = loadBMP("0/2.bmp");
        _textureId1 = loadTexture(image1);
        delete image1;

*/	glEnable( GL_POINT_SMOOTH );
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


void drawScene() 
{
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
	//glScalef(50.0f,50.f,50.0f);
	
	glPushMatrix();
        glColor3f( 1.0f, 0.0f, 0.0f );
	glBegin( GL_POINTS );
	glVertex3f(pnt_x , pnt_y , 2.5f);
	//printf("Rashi\n");
	glEnd();
	glPopMatrix();
	
	glLineWidth(5);
        glColor3f(1.0, 0.0, 0.0);
  
        glBegin(GL_LINES);
        glVertex3f(pnt_x, pnt_y, 2.5f);
        glVertex3f(pnt_x+0.05f, pnt_y+0.05f, 2.5f);
        glEnd();
	glLineWidth(5);
  
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);
        glVertex3f(pnt_x, pnt_y, 2.5f);
        glVertex3f(pnt_x-0.05f, pnt_y+0.05f, 2.5f);
        glEnd();
	//people
	
	glPushMatrix();
        glColor3f( 1.0f, 0.0f, 0.0f );
 
        glBegin( GL_POINTS );
        glVertex3f(p_x , p_y , 2.5f);
        //printf("Rashi\n");
        glEnd();
        glPopMatrix();


	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_QUADS);

	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(-1.5f, -2.0f, 2.5f);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(1.5f, -2.0f, 2.5f);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(1.5f, 0.0f, 2.5f);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(-1.5f, 0.0f, 2.5f);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPushMatrix();
//	glEnd();
	glPopMatrix();
/*	glEnable(GL_TEXTURE_2D);
        //glBindTexture(GL_TEXTURE_2D, _textureId1);

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
	
	glPushMatrix();
	glTranslatef(posx,posy,posz);
	//if(see==0)
	
	glScalef(0.25f,0.25f,0.25f);
	glColor3f(1.0,1.0,1.0);
	if(modper%2==0)
		glmDraw(p1, GLM_COLOR );
	else
		glmDraw(p2, GLM_COLOR );
	glPopMatrix();
	 glPushMatrix();
        glTranslatef(posx1,posy1,posz);
        //if(see==0)

        glScalef(0.25f,0.25f,0.25f);
        glColor3f(1.0,1.0,1.0);
        if(modper%2==0)
                glmDraw(p1, GLM_COLOR );
        else
                glmDraw(p2, GLM_COLOR );
        glPopMatrix();
	glPushMatrix();
        glTranslatef(posx2,posy2,posz2);
        //if(see==0)

        glScalef(0.25f,0.25f,0.25f);
        glColor3f(1.0,1.0,1.0);
        if(modper%2==0)
                glmDraw(p1, GLM_COLOR );
        else
                glmDraw(p2, GLM_COLOR );
        glPopMatrix();
*/
	glutSwapBuffers();
	
}
void myMouseMove( int x, int y)
{
printf("coordinates %d %d\n",x,y);
        //passivex=(x-(windowwidth/2))*(xscale);
        //passivey=((y-(windowheight/2))*(yscale))*-1;
        //passivex=x*0.01;//*0.02;//(x-(windowwidth/2);
        //passivey=y*0.01;//*0.02;
        /*if(mouseflag==0){
                mouseflag=1;
                prx=x;
                pry=y;
        }
*/
        /*float delx,dely;
        delx=-(prx-x);
        dely=+(pry-y);
        //passivex+=delx/40;
        //passivey+=dely/40;
        passivex=(x-800)*0.01;
        passivez=(y-800)*0.01;
        prx=x;
        pry=y;
        //printf("x=%d,y=%d,delx=%f,dely=%f,inix=%f,iniy=%f\n",x,y,delx,dely,inix,iniy);
        printf("%f %f\n",x/20.0,y/20.0);
          inix=x/20.0;
          iniy=y/20.0;*/
        passivez=0;//-(windowheight/2);
        //printf("MY MOUSE MOVE  %d,%d\n",x,y);
        //passivex=x/((800*2*w)+-w);
        //passivey=1-(y/((600*2*h)+-h));

        glutPostRedisplay();
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1200, 700);
	
	glutCreateWindow("Map");
	initRendering();
	
	glutDisplayFunc(drawScene);
	glutIdleFunc(drawScene);
	glutPassiveMotionFunc(myMouseMove);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	glutSpecialFunc(handleKeypress2);
	glutTimerFunc(25, update, 0);	
	glutMainLoop();
	return 0;
}
void update(int v)
{
	posx+=0.001;
	posz+=0.005;
	 modper=(modper+1)%2;
	glutPostRedisplay();
        glutTimerFunc(50,update, 0);


}







