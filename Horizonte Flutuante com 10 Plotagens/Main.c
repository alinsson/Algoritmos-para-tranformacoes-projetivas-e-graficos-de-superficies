/*          ===================================================
                    Algoritmo do Horizonte Flutuante
            ===================================================             */

/* Biliotecas                                                               */
#include "math.h"
#include "windows.h"
#include "graphics.h"

/* Nomes de Constantes e Controles                                          */
#define lab 0
#define func1 1
#define func2 2
#define func3 3
#define func4 4
#define func5 5
#define func6 6
#define func7 7
#define func8 8
#define func9 9
#define func10 10
#define SQR(x)  ((x)*(x))
#define DISTANCIA(a, b, c, x, y, z) sqrt(SQR(a-x) + SQR(b-y) + SQR(c-z))
#define PROD_VET(V1, V2, V3, a1, a2, a3, b1, b2, b3) V1 = a2*b3-a3*b2; \
V2 = a3*b1-a1*b3; V3 = a1*b2-a2*b1
#define NORMA(V1, V2, V3)  (sqrt((V1)*(V1) + (V2)*(V2) + (V3)*(V3)))
#define W (SQR(x - M_PI) + SQR(y - M_PI))

int   op;                 /* Escolhe grafico para plotar                    */
float dist_obs  = 10000,  /* Distancia do observador à origem               */
      dist_plano = 2000,  /* Distancia do plano de projecao à origem        */
      a, b, c, d,         /* Equacao do plano de projecao: ax+by+cz+d = 0   */
      u1, u2, u3,         /* Vetor 1 tangente ao plano de projecao          */
      v1, v2, v3,         /* Vetor 2 tangente ao plano de projecao          */
      A, B,                       /* Coordenadas do centro da tela          */
      TAM = 20,                   /* Coeficiente de ampliacao               */
      n1, n2, n3,                 /* Vetor normal                           */
      x0, y0, z0,                 /* Posicao do observador                  */
      nu = 40, nv = 40,           /* Subidivisoes do dominio                */
      inc = 0.02,                 /* Incremento do parametro                */
      P1, P2, P3,                 /* Ponto no plano de projecao             */
      o1 = 3, o2 = 1, o3 = 0.5,   /* Direcao do observador                  */
      O1 = 3, O2 = 1, O3 = 0.5;   /* Copias de o1, o2, o3                   */
HWND  label,           /* HWND da label                                     */
      bot1,            /* HWND do botao 1                                   */
      bot2,            /* HWND do botao 2                                   */
      bot3,            /* HWND do botao 3                                   */
      bot4,            /* HWND do botao 4                                   */
      bot5,            /* HWND do botao 5                                   */
      bot6,            /* HWND do botao 6                                   */
      bot7,            /* HWND do botao 7                                   */
      bot8,            /* HWND do botao 8                                   */
      bot9,            /* HWND do botao 9                                   */
      bot10;           /* HWND do botao 10                                  */

/* Definicao da parametrizacao F(x,y) = (f1(x,y), f2(x,y), f3(x,y)) da
   superficie cujo grafico eh desenhado. Neste caso, temos a parametri-
   zacao da superficie:
   Se op == 1, temos F(x,y)=(x,y,sin(x*x+y*y));                   
   Se op == 2, temos F(x,y)=(x,y,3*sin(x)*sin(y)/(2+sin(x)*sin(y)));
   Se op == 3, temos F(x,y)=(x,y,4*sin(x)*sin(y)/(2+sin(x*x+y*y)));
   Se op == 4, temos F(x,y)=(x,y,8*sin(x*y*y-y*x*x)/(1+x*x+y*y));
   Se op == 5, temos
   F(x,y)=(x,y,1.0/5.0*sin(x)*cos(y)-3.0/2.0*cos(7.0/4.0 * W)*exp(-W));
   Se op == 6, temos F(x,y)=(x,y,cos(x)*sin(y));                                     
   Se op == 7, temos F(x,y)=(x,y,log(x*x+y*y+1));
   Se op == 8, temos F(x,y)=(x,y,-3*y/((x*x)+(y*y)+1));
   Se op == 9, temos F(x,y)=(x,y,sin(x*x*y)/(x*x*x*x+y*y));
   Se op == 10, temos F(x,y)=(x,y,1-4*sin(x*x+y*y)/(x*x+y*y));              */
float f1(float x, float y) { 
   if((op == 1)||(op == 2)||(op == 3)||(op == 4)||(op == 5)||(op == 6)||
   (op == 7)||(op == 8)||(op == 9)||(op == 10)) {
      return x;
   }
}

float f2(float x, float y) { 
   if((op == 1)||(op == 2)||(op == 3)||(op == 4)||(op == 5)||(op == 6)||
   (op == 7)||(op == 8)||(op == 9)||(op == 10)) {
      return y;
   }
}

float f3(float x, float y) { 
   if(op == 1) {
      return sin(x * x + y * y);
   }
   
   if(op == 2) {
      return 3 * sin(x) * sin(y)/(2 + sin(x) * sin(y));
   }

   if(op == 3) {
      return 4 * sin(x) * sin(y)/(2 + sin(x * x + y * y));         
   }
   
   if(op == 4) {
      return 8 * sin(x * y * y - y * x * x)/(1 + x * x + y * y);
   }
   
   if(op == 5) {
      return 1.0/5.0 * sin(x) * cos(y) - 3.0/2.0 * cos(7.0/4.0 * W) * exp(-W);
   }
   if(op == 6) {
      return cos(x) * sin(y);
   }
   
   if(op == 7) {
      return log(x * x + y * y + 1);
   }
   
   if(op == 8) {
      return -3 * y/((x * x) + (y * y) + 1);
   }
   
   if(op == 9) {
      return sin(x * x * y)/(x * x * x * x + y * y);
   }
   
   if(op == 10) {
      return 1 - 4 * sin(x * x + y * y)/(x * x + y * y);
   }
}
 
void ProjetaPonto(float x1, float y1, float z1, float *x, float *y) {
/* Determina as coordenadas do ponto (x1, y1, z1) no plano de projecao. Deve
   ser feita antes uma chamada a DeterminaPlanoDeProjecao(). */
  float q1, q2, q3, t;

  t = 1/(1 - (a*x1 + b*y1 + c*z1 + d)/(a*x0 + b*y0 + c*z0 + d));
  q1 = x0 + t*(x1 - x0);
  q2 = y0 + t*(y1 - y0);
  q3 = z0 + t*(z1 - z0);
  *x = (q1 - P1)*v1 + (q2 - P2)*v2 + (q3 - P3)*v3;
  *y = (q1 - P1)*u1 + (q2 - P2)*u2 + (q3 - P3)*u3;
}

void DeterminaPlanoDeProjecao(void) {
/*Determina o  plano de  projecao ax + by + cz + d = 0, um ponto do plano
  (P1, P2, P3) e 2 vetores tangentes ao plano (u1, u2, u3) e (v1, v2, v3)
  perpendiculares entre si                                                  */
  float N_o, prod_aux, t, N_u, N_v, compr_aux = 10;

  N_o = NORMA(o1, o2, o3);
  a = o1; b = o2; c = o3;
  o1 = o1/N_o; o2 = o2/N_o; o3 = o3/N_o;
  x0 = o1*dist_obs; y0 = o2*dist_obs; z0 = o3*dist_obs;
  P1 = o1*dist_plano; P2 = o2*dist_plano; P3 = o3*dist_plano;
  d = -a*P1 - b*P2 - c*P3;

/*Determinacao de 2 vetores ortogonais no plano de projecao                 */
  if (o1 != 0) {
    t = 1/(1 - compr_aux*c/(a*x0 + b*y0 + c*z0 + d));
    u1 = x0 + t*(P1 - x0) - P1;
    u2 = y0 + t*(P2 - y0) - P2;
    u3 = z0 + t*(P3 - z0 + compr_aux) - P3;
    N_u = NORMA(u1, u2, u3);
    u1 = u1/N_u; u2 = u2/N_u; u3 = u3/N_u;

    t = 1/(1 - compr_aux*b/(a*x0 + b*y0 + c*z0 + d));
    v1 = x0 + t*(P1 - x0) - P1;
    v2 = y0 + t*(P2 - y0 + compr_aux) - P2;
    v3 = z0 + t*(P3 - z0) - P3;
    N_v = NORMA(v1, v2, v3);
    v1 = v1/N_v; v2 = v2/N_v; v3 = v3/N_v;
  }

  else if (o2 != 0) {
    t = 1/(1 - compr_aux*c/(a*x0 + b*y0 + c*z0 + d));
    u1 = x0 + t*(P1 - x0) - P1;
    u2 = y0 + t*(P2 - y0) - P2;
    u3 = z0 + t*(P3 - z0 + compr_aux) - P3;
    N_u = NORMA(u1, u2, u3);
    u1 = u1/N_u; u2 = u2/N_u; u3 = u3/N_u;

    t = 1/(1 - compr_aux*a/(a*x0 + b*y0 + c*z0 + d));
    v1 = x0 + t*(P1 - x0 + compr_aux) - P1;
    v2 = y0 + t*(P2 - y0) - P2;
    v3 = z0 + t*(P3 - z0) - P3;
    N_v = NORMA(v1, v2, v3);
    v1 = v1/N_v; v2 = v2/N_v; v3 = v3/N_v;
  }

  else if (o3 != 0) {
    t = 1/(1 - compr_aux*a/(a*x0 + b*y0 + c*z0 + d));
    u1 = x0 + t*(P1 - x0 + compr_aux) - P1;
    u2 = y0 + t*(P2 - y0) - P2;
    u3 = z0 + t*(P3 - z0) - P3;
    N_u = NORMA(u1, u2, u3);
    u1 = u1/N_u; u2 = u2/N_u; u3 = u3/N_u;

    t = 1/(1 - compr_aux*b/(a*x0 + b*y0 + c*z0 + d));
    v1 = x0 + t*(P1 - x0) - P1;
    v2 = y0 + t*(P2 - y0 + compr_aux) - P2;
    v3 = z0 + t*(P3 - z0) - P3;
    N_v = NORMA(v1, v2, v3);
    v1 = v1/N_v; v2 = v2/N_v; v3 = v3/N_v;
  }

  prod_aux = u1*v1 + u2*v2 + u3*v3;
  v1 = v1 - prod_aux*u1;
  v2 = v2 - prod_aux*u2;
  v3 = v3 - prod_aux*u3;
}

void DesenhaEixos(int tam, int cor) {
/*Desenha os eixos x, y, z usando tamanho e cor especificados               */
  float X0, Y0, X, Y;
  int cor_aux, x_x, x_y, y_x, y_y, z_x, z_y;

  setcolor(WHITE);
  outtextxy(0, 0, "Alinsson Figueira de Souza");
  outtextxy(0, 18, "Engenharia da Computação - UFC");
  outtextxy(0, 36, "Trabalho de Cálculo II - Juan Carlos Medeiros");


  cor_aux = getcolor();
  setcolor(cor);
  ProjetaPonto(0, 0, 0, &X0, &Y0);
  ProjetaPonto(tam, 0, 0, &X, &Y);
  line((int) (A + X0*TAM), (int) (B - Y0*TAM),
       (int) (A + X*TAM), (int) (B - Y*TAM));
  x_x = (int) (A + X*TAM); x_y = (int) (B - Y*TAM);
  ProjetaPonto(0, tam, 0, &X, &Y);
  line((int) (A + X0*TAM), (int) (B - Y0*TAM),
       (int) (A + X*TAM), (int) (B - Y*TAM));
  y_x = (int) (A + X*TAM); y_y = (int) (B - Y*TAM);
  ProjetaPonto(0, 0, tam, &X, &Y);
  line((int) (A + X0*TAM), (int) (B - Y0*TAM),
       (int) (A + X*TAM), (int) (B - Y*TAM));
  z_x = (int) (A + X*TAM); z_y = (int) (B - Y*TAM);

  setcolor(cor_aux);
  outtextxy(x_x, x_y, "x");
  outtextxy(y_x, y_y, "y");
  outtextxy(z_x, z_y, "z");
}

void DesenhaPonto(float x, float y, float z) {
/*Desenha a projecao do ponto (x, y, z) no plano de projecao. Deve ser feita
  antes uma chamada a DeterminaPlanoDeProjecao()                            */
  float X, Y, q1, q2, q3, t;

  t = 1/(1 - (a*x + b*y + c*z + d)/(a*x0 + b*y0 + c*z0 + d));
  q1 = x0 + t*(x - x0);
  q2 = y0 + t*(y - y0);
  q3 = z0 + t*(z - z0);
  X = (q1 - P1)*v1 + (q2 - P2)*v2 + (q3 - P3)*v3;
  Y = (q1 - P1)*u1 + (q2 - P2)*u2 + (q3 - P3)*u3;
  putpixel((int) (A + X*TAM), (int) (B - Y*TAM), getcolor());
}

void DesenhaPontoCor(float x, float y, float z, int cor) {
/*Desenha a projecao do ponto (x, y, z) no plano de projecao. Deve ser feita
  antes uma chamada a DeterminaPlanoDeProjecao(). E' usada a cor fornecida  */
  float X, Y, q1, q2, q3, t;

  t = 1/(1 - (a*x + b*y + c*z + d)/(a*x0 + b*y0 + c*z0 + d));
  q1 = x0 + t*(x - x0);
  q2 = y0 + t*(y - y0);
  q3 = z0 + t*(z - z0);
  X = (q1 - P1)*v1 + (q2 - P2)*v2 + (q3 - P3)*v3;
  Y = (q1 - P1)*u1 + (q2 - P2)*u2 + (q3 - P3)*u3;
  putpixel((int) (A + X*TAM), (int) (B - Y*TAM), cor);
}

void DesenhaSuperficie5(float (*f) (float, float), float (*g) (float, float),
     float (*h) (float, float), float umin, float umax,
     float vmin, float vmax, int cor1, int cor2) {
/*Desenha o grafico da funcao (x, y, f(x, y)) usando o algoritmo conhecido
  como "horizonte flutuante"                                                */
  float X, Y, u, v;
  int horizonte_max[2000], horizonte_min[2000], maxx, i, x, y;

  maxx = getmaxx();
  for (i = 0; i <= maxx; i++) {
    horizonte_max[i] = 9999;
    horizonte_min[i] = -9999;
  }

  for (u = umax; u > umin; u -= (umax - umin)/nu) {
    for (v = vmin; v < vmax; v += inc) {
      ProjetaPonto(f(u, v), g(u, v), h(u, v), &X, &Y);
      x = (int) (A + X*TAM); y = (int) (B - Y*TAM);
      if (x >= 0 && x <= maxx) {
	if (y < horizonte_max[x]) {
	  horizonte_max[x] = y;
	  DesenhaPontoCor(f(u, v), g(u, v), h(u, v), cor1);
	}
	if (y > horizonte_min[x]) {
	  horizonte_min[x] = y;
	  DesenhaPontoCor(f(u, v), g(u, v), h(u, v), cor2);
	}
      }
    }

    v = vmax;
    ProjetaPonto(f(u, v), g(u, v), h(u, v), &X, &Y);
    x = (int) (A + X*TAM); y = (int) (B - Y*TAM);
    if (x >= 0 && x <= maxx) {
      if (y < horizonte_max[x]) {
	horizonte_max[x] = y;
	DesenhaPontoCor(f(u, v), g(u, v), h(u, v), cor1);
      }
      if (y > horizonte_min[x]) {
	horizonte_min[x] = y;
	DesenhaPontoCor(f(u, v), g(u, v), h(u, v), cor2);
      }
    }
  }

  u = umin;
  for (v = vmin; v < vmax; v += inc) {
    ProjetaPonto(f(u, v), g(u, v), h(u, v), &X, &Y);
    x = (int) (A + X*TAM); y = (int) (B - Y*TAM);
    if (x >= 0 && x <= maxx) {
      if (y < horizonte_max[x]) {
	horizonte_max[x] = y;
	DesenhaPontoCor(f(u, v), g(u, v), h(u, v), cor1);
      }
      if (y > horizonte_min[x]) {
	horizonte_min[x] = y;
	DesenhaPontoCor(f(u, v), g(u, v), h(u, v), cor2);
      }
    }
  }

  v = vmax;
  ProjetaPonto(f(u, v), g(u, v), h(u, v), &X, &Y);
  x = (int) (A + X*TAM); y = (int) (B - Y*TAM);
  if (x >= 0 && x <= maxx) {
    if (y < horizonte_max[x]) {
      horizonte_max[x] = y;
      DesenhaPontoCor(f(u, v), g(u, v), h(u, v), cor1);
    }
    if (y > horizonte_min[x]) {
      horizonte_min[x] = y;
      DesenhaPontoCor(f(u, v), g(u, v), h(u, v), cor2);
    }
  }
}
LRESULT CALLBACK WinProc(HWND window,UINT msg, WPARAM wParam,LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,
    LPSTR lpCmdLine, int nShowCmd) {

   MSG message;
   HWND hwnd;
   WNDCLASSEX wc;
   wc.cbClsExtra=0;
   wc.cbSize=sizeof(wc);
   wc.cbWndExtra=0;
   wc.hbrBackground=GetSysColorBrush(COLOR_BTNFACE);
   wc.hCursor=LoadCursor(NULL,IDC_ARROW);
   wc.hIcon=LoadIcon(NULL,IDI_APPLICATION);
   wc.hIconSm=LoadIcon(NULL,IDI_APPLICATION);
   wc.lpfnWndProc=WinProc;
   wc.lpszClassName="Janela";
   wc.lpszMenuName=NULL;
   wc.style=0;
   RegisterClassEx(&wc);
   hwnd = CreateWindowEx(0,"Janela","Gráficos de Superfícies com Algoritmo do "
   "Horizonte Flutuante",
   WS_OVERLAPPED|WS_SYSMENU|WS_SIZEBOX|WS_MAXIMIZEBOX|WS_MINIMIZEBOX,
   50,50,843,325,NULL,NULL,NULL,NULL);
   ShowWindow(hwnd,SW_SHOW);
   UpdateWindow(hwnd);
  
   while(GetMessage(&message,0,0,0)){
      TranslateMessage(&message);
	    DispatchMessage(&message);
   }

   return message.wParam ;
}

LRESULT CALLBACK WinProc(HWND window,UINT msg, WPARAM wParam,LPARAM lParam){
switch(msg) {
   case WM_CLOSE:
	 PostQuitMessage(0);
	 break;
   case WM_CREATE: /*Processo de criação da janela                          */
   
   label = CreateWindowEx(0,"STATIC",
           "Clique em uma das funções acima para plotar o gráfico e tecle"
           " algo para sair.\n\n\Professor: Juan Carlos\nDisciplina:"
           " Cálculo II\nTrabalho: Gráficos de Superfícies\nAluno: Alinsson"
           " Figueira de Souza",
           WS_CHILD|WS_VISIBLE,10,185,600,400,window,(HMENU)lab,NULL,0);
   bot1 = CreateWindowEx(0,"BUTTON","F(x,y)=(x,y,sin(x*x+y*y))",
          WS_CHILD|WS_VISIBLE,415,10,400,30,window,(HMENU)func1,0,0);
   bot2 = CreateWindowEx(0,"BUTTON",
          "F(x,y)=(x,y,3*sin(x)*sin(y)/(2+sin(x)*sin(y)))",
          WS_CHILD|WS_VISIBLE,415,45,400,30,window,(HMENU)func2,0,0);
   bot3 = CreateWindowEx(0,"BUTTON",
          "F(x,y)=(x,y,4*sin(x)*sin(y)/(2+sin(x*x+y*y)))",
          WS_CHILD|WS_VISIBLE,415,80,400,30,window,(HMENU)func3,0,0);
   bot4 = CreateWindowEx(0,"BUTTON",
          "F(x,y)=(x,y,8*sin(x*y*y-y*x*x)/(1+x*x+y*y))",
          WS_CHILD|WS_VISIBLE,415,115,400,30,window,(HMENU)func4,0,0);
   bot5 = CreateWindowEx(0,"BUTTON",
          "F(x,y)=(1.0/5.0*sin(x)*cos(y)-3.0/2.0*cos(7.0/4.0 * W)*exp(-W))",
          WS_CHILD|WS_VISIBLE,415,150,400,30,window,(HMENU)func5,0,0);
   bot6 = CreateWindowEx(0,"BUTTON","F(x,y)=(x,y,cos(x)*sin(y))",
          WS_CHILD|WS_VISIBLE,10,10,400,30,window,(HMENU)func6,0,0);
   bot7 = CreateWindowEx(0,"BUTTON","F(x,y)=(x,y,log(x*x+y*y+1))",
          WS_CHILD|WS_VISIBLE,10,45,400,30,window,(HMENU)func7,0,0);
   bot8 = CreateWindowEx(0,"BUTTON","F(x,y)=(x,y,-3*y/((x*x)+(y*y)+1))",
          WS_CHILD|WS_VISIBLE,10,80,400,30,window,(HMENU)func8,0,0);
   bot9 = CreateWindowEx(0,"BUTTON","F(x,y)=(x,y,sin(x*x*y)/(x*x*x*x+y*y))",
          WS_CHILD|WS_VISIBLE,10,115,400,30,window,(HMENU)func9,0,0);
   bot10 = CreateWindowEx(0,"BUTTON","F(x,y)=(x,y,1-4*sin(x*x+y*y)/(x*x+y*y))",
           WS_CHILD|WS_VISIBLE,10,150,400,30,window,(HMENU)func10,0,0);

break;

/*Mensagem enviada quando um controle é clicado:                            */
case WM_COMMAND:
   switch(wParam) {

   /*F(x, y) = (x, y, sin(x * x + y * y))                                 */
   case func1:
      op = 1;
      initwindow(800, 800, "Gráficos de Superfície com Algoritmo do "
      "Horizonte Flutuante");
      o1 = 3, o2 = 1, o3 = 1; inc = 0.001;
      nu = 120, nv = 120;
      A = getmaxx()/2, B = getmaxy()/2, TAM = 120;
      DeterminaPlanoDeProjecao();
      DesenhaSuperficie5(f1, f2, f3, -3, 3, -3, 3, GREEN, WHITE);
      DesenhaEixos(4, WHITE);
      outtextxy(300, 720,
      "F(x, y) = (x, y, sin(x * x + y * y))");
      getch();
      closegraph();
    break;
    
    /*F(x, y) = (x, y, 3 * sin(x) * sin(y)/(2 + sin(x) * sin(y)))           */
    case func2:
      op = 2;
      initwindow(800, 800, "Gráficos de Superfície com Algoritmo do "
      "Horizonte Flutuante");
      o1 = 3, o2 = 1, o3 = 0.5; inc = 0.01;
      nu = 100, nv = 100;
      A = getmaxx()/2; B = getmaxy()/2; TAM = 80;
      DeterminaPlanoDeProjecao();
      DesenhaSuperficie5(f1, f2, f3, -5, 5, -5, 5, GREEN, WHITE);
      DesenhaEixos(6, WHITE);
      outtextxy(220, 720,
      "F(x, y) = (x, y, 3 * sin(x) * sin(y)/(2 + sin(x) * sin(y)))");
      getch();
      closegraph();
    break;
 
    /*F(x, y) = (x, y, 4 * sin(x) * sin(y)/(2 + sin(x * x + y * y)))        */
    case func3:
      op = 3;
      initwindow(800, 800, "Gráficos de Superfície com Algoritmo do "
      "Horizonte Flutuante");
      o1 = 3, o2 = 1, o3 = 0.5; inc = 0.001;
      nu = 120, nv = 120;
      A = getmaxx()/2, B = getmaxy()/2, TAM = 70;
      DeterminaPlanoDeProjecao();
      DesenhaSuperficie5(f1, f2, f3, -5, 5, -5, 5, GREEN, BROWN);
      DesenhaEixos(7, WHITE);
      outtextxy(220, 720,
      "F(x, y) = (x, y, 4 * sin(x) * sin(y)/(2 + sin(x * x + y * y)))");
      getch();
      closegraph();
    break;
    
    /*F(x, y) = (x, y, 8 * sin(x * y * y - y * x * x)/(1 + x * x + y * y))  */
    case func4:
      op = 4;
      initwindow(800, 800, "Gráficos de Superfície com Algoritmo do "
      "Horizonte Flutuante");
      o1 = 3, o2 = 1, o3 = 0.5; inc = 0.001;
      nu = 90, nv = 90;
      A = getmaxx()/2, B = getmaxy()/2, TAM = 75;
      DeterminaPlanoDeProjecao();
      DesenhaSuperficie5(f1, f2, f3, -5, 5, -5, 5, GREEN, BROWN);
      DesenhaEixos(6, WHITE);
      outtextxy(220, 720,
      "F(x, y) = (x, y, 8 * sin(x * y * y - y * x * x)/(1 + x * x + y * y))");
      getch();
      closegraph();
    break;

    /*F(x, y) = (x, y , 1.0/5.0 * sin(x) * cos(y)-3.0/2.0 * cos(7.0/4.0 * W)*/
    case func5:
      op = 5;
      initwindow(800, 800, "Gráficos de Superfície com Algoritmo do "
      "Horizonte Flutuante");
      o1 = 3, o2 = 1, o3 = 1; inc = 0.005;
      nu = 100, nv = 100;
      A = getmaxx()/4, B = getmaxy()/2, TAM = 120;
      DeterminaPlanoDeProjecao();
      DesenhaSuperficie5(f1, f2, f3, 0, 6.29, 0, 6.29, GREEN, WHITE);
      DesenhaEixos(3, WHITE);
      outtextxy(50, 720,
      "F(x, y) = (x, y , 1.0/5.0 * sin(x) * cos(y)-3.0/2.0 * cos(7.0/4.0 * W)"
      " * exp(-W)), para W = sqrt(x - PI) + sqrt(y - PI)");
      getch();
      closegraph();
    break;

    /*F(x, y)=(x, y, cos(x) * sin(y))                                       */
    case func6:
      op = 6;
      initwindow(800, 800, "Gráficos de Superfície com Algoritmo do "
      "Horizonte Flutuante");
      o1 = 3, o2 = 1, o3 = 1; inc = 0.001;
      nu = 120, nv = 120;
      A = getmaxx()/2, B = getmaxy()/2, TAM = 140;
      DeterminaPlanoDeProjecao();
      DesenhaSuperficie5(f1, f2, f3, -3, 3, -3, 3, GREEN, WHITE);
      DesenhaEixos(3, WHITE);
      outtextxy(300, 720,
      "F(x, y)=(x, y, cos(x) * sin(y))");
      getch();
      closegraph();
    break;
    
    /*F(x, y) = (x, y, log(x * x + y * y + 1))                              */
    case func7:
      op = 7;
      initwindow(800, 800, "Gráficos de Superfície com Algoritmo do "
      "Horizonte Flutuante");
      o1 = 3, o2 = 3, o3 = 2; inc = 0.001;
      nu = 120, nv = 120;
      A = getmaxx()/2+20, B = getmaxy()/2+20, TAM = 150;
      DeterminaPlanoDeProjecao();
      DesenhaSuperficie5(f1, f2, f3, -3, 3, -3, 3, RED, WHITE);
      DesenhaEixos(3, WHITE);
      outtextxy(300, 720,
      "F(x, y) = (x, y, log(x * x + y * y + 1))");
      getch();
      closegraph();
    break;
   
    /*F(x, y) = (x, y, -3 * y/((x * x) + (y * y) + 1))                      */
    case func8:
      op = 8;
      initwindow(800, 800, "Gráficos de Superfície com Algoritmo do "
      "Horizonte Flutuante");
      o1 = 3, o2 = 1, o3 = 1; inc = 0.001;
      nu = 120, nv = 120;
      A = getmaxx()/2, B = getmaxy()/2, TAM = 140;
      DeterminaPlanoDeProjecao();
      DesenhaSuperficie5(f1, f2, f3, -3, 3, -3, 3, GREEN, WHITE);
      DesenhaEixos(3, WHITE);
      outtextxy(260, 720,
      "F(x, y) = (x, y, -3 * y/((x * x) + (y * y) + 1))");
      getch();
      closegraph();
    break;
    
    /*F(x, y) = (x, y, sin(x * x * y)/(x * x * x * x + y * y))              */
    case func9:
      op = 9;
      initwindow(800, 800, "Gráficos de Superfície com Algoritmo do "
      "Horizonte Flutuante");
      o1 = 3, o2 = 1, o3 = 1; inc = 0.001;
      nu = 120, nv = 120;
      A = getmaxx()/2, B = getmaxy()/2, TAM = 140;
      DeterminaPlanoDeProjecao();
      DesenhaSuperficie5(f1, f2, f3, -3, 3, -3, 3, RED, WHITE);
      DesenhaEixos(3, WHITE);
      outtextxy(260, 720,
      "F(x, y) = (x, y, sin(x * x * y)/(x * x * x * x + y * y))");
      getch();
      closegraph();
    break;
    
    /*F(x, y) = (x, y, 1 - 4 * sin(x * x + y * y)/(x * x + y * y)           */
    case func10:
      op = 10;
      initwindow(800, 800, "Gráficos de Superfície com Algoritmo do "
      "Horizonte Flutuante");
      o1 = 3, o2 = 1, o3 = 1; inc = 0.001;
      nu = 120, nv = 120;
      A = getmaxx()/2, B = getmaxy()/2, TAM = 130;
      DeterminaPlanoDeProjecao();
      DesenhaSuperficie5(f1, f2, f3, -3, 3, -3, 3, BLUE, WHITE);
      DesenhaEixos(4, WHITE);
      outtextxy(240, 720,
      "F(x, y) = (x, y, 1 - 4 * sin(x * x + y * y)/(x * x + y * y)");
      getch();
      closegraph();
    } break;
    
   default:
      return DefWindowProc(window,msg,wParam,lParam);
}

return 0;
}

/* ------------------------------------------------------------------------ */

/*** FIM DE "Main.c" ***/
