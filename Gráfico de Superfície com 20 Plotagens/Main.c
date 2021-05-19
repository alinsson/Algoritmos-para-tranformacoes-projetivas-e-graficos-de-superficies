/*          ===================================================
                  Contrucao do grafico de uma superficie
            ===================================================             */
            
/* Biliotecas                                                               */
#include "math.h"
#include "windows.h"
#include "graphics.h"
#include "GraficoSuperficie_private.h"

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
#define func11 11
#define func12 12
#define func13 13
#define func14 14
#define func15 15
#define func16 16
#define func17 17
#define func18 18
#define func19 19
#define func20 20

/* Variaveis Globais                                                        */
int   a, b,            /* Coordenadas do centro da tela                     */
      c, d,            /* Constantes reais                                  */
      op;              /* Escolhe grafico para plotar                       */
float A, B,            /* Coordenadas do centro da tela                     */
      K,               /* Cooeficiente de ampliacao                         */
      nu,              /* Quant. subdivisores no dominio da variavel u      */
      nv,              /* Quant. subdivisores no dominio da variavel v      */
      fi,              /* Angulo de rotacao em torno do eixo y              */
      teta,            /* Angulo de rotacao em torno do eixo z              */
      R,               /* Raio                                              */
      dom = M_PI;      /* Domínio das funcoes                               */
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
      bot10,           /* HWND do botao 10                                  */
      bot11,           /* HWND do botao 11                                  */
      bot12,           /* HWND do botao 12                                  */
      bot13,           /* HWND do botao 13                                  */
      bot14,           /* HWND do botao 14                                  */
      bot15,           /* HWND do botao 15                                  */
      bot16,           /* HWND do botao 16                                  */
      bot17,           /* HWND do botao 17                                  */
      bot18,           /* HWND do botao 18                                  */
      bot19,           /* HWND do botao 19                                  */
      bot20;           /* HWND do botao 20                                  */

/* Definicao da parametrizacao F(u,v) = (f1(u,v), f2(u,v), f3(u,v)) da
   superficie cujo grafico eh desenhado. Neste caso, temos a parametri-
   zacao da superficie:
   Se op == 1, temos F(u, v) = (u, v, sin(u * u + v * v)/4)                   
   Se op == 2, temos a Garrafa de Klein;
   Se op == 3, temos F(u, v) = (u, v, 3 * sin(u) * sin(v)/(2 + sin(u) * sin(v)))
   Se op == 4, temos uma esfera de raio R;
   Se op == 5, temos um cilindro circular eliptico de raio R;
   Se op == 6, temos um cone;                                                
   Se op == 7, temos uma helicóide;
   Se op == 8, temos um toro;
   Se op == 9, temos uma catenóide
   Se op == 10, temos uma hiperbolóide de 1 folha
   Se op == 11, temos uma curvatura gaussiana
   Se op == 12, temos uma elipsóide
   Se op == 13, temos F(u, v) =
   (u * sin(u) * cos(v), u * sin(v), u * cos(u) * cos(v)
   Se op == 14, temos uma parabolóide hiperbólico
   Se op == 15, temos um F(u, v) =
   ((11 + 2 * cos(u)) * cos(v), (11 + 2 * cos(u)) * sen(v), 2 * sen(u) + v) 
   Se op == 16, temos uma pseudo-esfera
   Se op == 17, temos F(u, v) = (u, v, 1 - sqrt(sqrt((u*v)(u*v)))
   Se op == 18, temos F(u, v) = (u, v, 0,05*(u * u * u - 3 * u * v * v))
   Se op == 19, temos F(u, v) =
   (u, v, 8 * sin(u * v * v - v * u * u)/(1 +  u * u * v * v))
   Se op == 20, temos F(u, v) =
   (u, v, 1 - 4 * sin(u * u + v * v)/(u * u + v * v))                       */
float f1(float u, float v) { 
   if(op == 1) {
      return u;
   }
   
   if(op == 2) {
      return 6 * cos(u) * (1 + sin(u)) + 4 * (1 - cos(u)/4) * (cos(v + 3.1418));
   }
   
   if(op == 3) {
      return u;
   }
   
   if(op == 4) {
      return R * cos(u) * sin(v);
   }
   
   if(op == 5) {
      return R * cos(u);
   }
   
   if(op == 6) {
      return u * cos(v);
   }
   
   if(op == 7) {
      return u * cos(v);
   }
   
   if(op == 8) {
      return (c + d * cos(u)) * cos(v);
   }
   
   if(op == 9) {
      return cos(c * v) * cos(u);
   }
   
   if(op == 10) {
      return cos(u) - v * sin(u);
   }
   
   if(op == 11) {
      return u;
   }
   
   if(op == 12) {
      return c * sin(u) * cos(v);
   }
   
   if(op == 13) {
      return u * sin(u) * cos(v);
   }
   
   if(op == 14) {
      return c * u;
   }
   
   if(op == 15) {
      return (11 + 2 * cos(u)) * cos(v);
   }
   
   if(op == 16) {
      return cos(u) * sin(v);
   }
   
   if(op == 17) {
      return u;
   }
   
   if(op == 18) {
      return u;
   }   

   if(op == 19) {
      return u;
   }
   
   if(op == 20) {
      return u;
   }
}

float f2(float u, float v) {
   if(op == 1) {
      return v;
   }
   
   if(op == 2) {
      return 16 * sin(u);
   }
   
   if(op == 3) {
      return v;
   }
      
   if(op == 4) {
      return R * cos(u) * cos(v);
   }
   
   if(op == 5) {
      return R * sin(u);
   }
   
   if(op == 6) {
      return u * sin(v);
   }
   
   if(op == 7) {
      return u * sin(v);
   }
   
   if(op == 8) {
      return (c + d * cos(u)) * sin(v);
   }
   
   if(op == 9) {
      return cos(c * v) * sin(u);
   }
   
   if(op == 10) {
      return sin(u) + v * cos(u);
   }
   
   if(op == 11) {
      return v;
   }
   
   if(op == 12) {
      return d * sin(u) * sin(v);
   }
      
   if(op == 13) {
      return u * sin(v);
   }
   
   if(op == 14) {
      return d * v;
   }
   
   if(op == 15) {
      return (11 + 2 * cos(u)) * sin(v);
   }
   
   if(op == 16) {
   return sin(u) * sin(v);
   }
   
   if(op == 17) {
      return v;
   }
   
   if(op == 18) {
      return v;
   }
   
   if(op == 19) {
      return v;
   }
   
   if(op == 20) {
      return v;
   }
}

float f3(float u, float v) {
   if(op == 1) {
      return sin((u * u + v * v)/4);
   }
   
   if(op == 2) {
      return 4 * (1 - (cos(u))/2) * sin(v);
   }
   
   if(op == 3) {
      return 3 * sin(u) * sin(v)/(2 + sin(u) * sin(v));      
   }
   
   if(op == 4) {
      return R*sin(u);
   }

   if(op == 5) {
      return v;
   }
   
   if(op == 6) {
      return u;
   }
   
   if(op == 7) {
      return v;
   }
   
   if(op == 8) {
      return d * sin(u);
   }
   
   if(op == 9) {
      return v;
   }
   
   if(op == 10) {
      return v;
   }
   
   if(op == 11) {
      return (-36 * (u * u + v * v))/(
      (1 + 9 * u * u * u * u + 18 * u * u * v * v + 9 * v * v * v * v) *
      (1 + 9 * u * u * u * u + 18 * u * u * v * v + 9 * v * v * v * v));
   }
   
   if(op == 12) {
      return c * d * cos(u);
   }
   
   if(op == 13) {
      return u * cos(u) * cos(v);
   }
   
   if(op == 14) {
      return u * u - v * v;
   }
   
   if(op == 15) {
      return 2 * sin(u) + v;
   }
   
   if(op == 16) {
      return c*(cos(v) + log(tan(v/2)));
   }
   
   if(op == 17) {
      return 1 - sqrt(sqrt((u*v)*(u*v)));
   }
   
   if(op == 18) {
      return 0,05 * (u * u * u - 3 * u * v * v);
   }
   
   if(op == 19) {
      return 8 * sin(u * v * v - v * u * u)/(1 +  u * u + v * v);
   }

   if(op == 20) {
      return 1 - 4 * sin(u * u + v * v)/(u * u + v * v);
   }
}

/* ------------------------------------------------------------------------ */
   
void ProjetaPonto(float x, float y, float z, int *projX, int *projY) {

   /* Calcula as coordenadas do ponto (x, y, z) no plano de projecao. Eh
      feita uma ampliacao de K unidades e uma trasnlacao da origem do
      sistema de coordenadas do plano de projecao para o ponto (A, B)       */
   float X, Y;

   /* Gira (x, y, z) de teta radianos em torno do eixo z e de fi radianos em
      torno do eixo y. Eh feita uma projecao ortografica na direcao x       */
   X = y * cos(teta) + x * sin(teta);
   Y = x * cos(teta) * sin(fi) - y * sin(fi) * sin(teta) + z * cos(fi);

   /* Ampiacao e traslacao de (X, Y)                                        */
   *projX = (int)(A + K * X);
   *projY = (int)(B - K * Y);
}

/* ------------------------------------------------------------------------ */

void DesenhaEixos(int k, int cor1, int cor2) {

   /* Desenha os eixos x, y, z usando tamanho k e cores especificadas       */
   int X0, Y0, X1, Y1, X2, Y2, X3, Y3;
   
   setcolor(WHITE);
   outtextxy(0, 0, "Alinsson Figueira de Souza");
   outtextxy(0, 18, "Engenharia da Computação - UFC");
   outtextxy(0, 36, "Trabalho de Cálculo II - Juan Carlos Medeiros");

   /* Calcula a Projecao na origem (0, 0, 0)                                */
   ProjetaPonto(0, 0, 0, &X0, &Y0);

   setcolor(cor1);
   ProjetaPonto(k, 0, 0, &X1, &Y1);
   
   /* Desenha o eixo x                                                      */
   line(X0, Y0, X1, Y1);
   setcolor(cor2);
   outtextxy(X1, Y1, "x");
   
   setcolor(cor1);
   ProjetaPonto(0, k, 0, &X2, &Y2);
   
   /* Desenha o eixo y                                                      */
   line(X0, Y0, X2, Y2);
   setcolor(cor2);
   outtextxy(X2, Y2, "y");
   
   setcolor(cor1);
   ProjetaPonto(0, 0, k, &X3, &Y3);
   
   /* Desenha o eixo z                                                      */
   line(X0, Y0, X3, Y3);
   setcolor(cor2);
   outtextxy(X3, Y3, "z");   
}

/* ------------------------------------------------------------------------ */

void DesenhaSuperficie(float umin, float umax, float vmin, float vmax,
   int cor) {

   /* Usando a cor especificada, desenha a superficie definida pelas
      equacoes parametricas (f1(u, v), f2(u, v), f3(u, v)) usando pequenos
      quadrilateros. Eh usado como dominio o retangulo
      [umin, umax] x [vmin, vmax]                                           */
   float u, v, x, y, z, incrU, incrV;
   int X1, X2, X3, X4, Y1, Y2, Y3, Y4;

   /* Incremento da variavel u                                              */
   incrU = (umax - umin)/nu;
   
   /* Incremento da variavel v                                              */
   incrV = (vmax - vmin)/nv;
   
   setcolor(cor);
   
   u = umin + incrU;
   
   /* Se nao houvesse erro de aproximacao esse "while" poderia ser
      substituido por "while(u <= umax)"                                    */
   while(u < umax + incrU/2) {
      
      v = vmin + incrV;
      
      /* Se nao houvesse erro de aproximacao esse "while" poderia ser
         substituido por "while(v <= vmax)"                                 */
      while(v < vmax + incrV/2) {
         x = f1(u, v);
         y = f2(u, v);
         z = f3(u, v);
         ProjetaPonto(x, y, z, &X1, &Y1);
         
         x = f1(u - incrU, v);
         y = f2(u - incrU, v);
         z = f3(u - incrU, v);
         ProjetaPonto(x, y, z, &X2, &Y2);
         
         x = f1(u, v - incrV);
         y = f2(u, v - incrV);
         z = f3(u, v - incrV);
         ProjetaPonto(x, y, z, &X3, &Y3);
         
         x = f1(u - incrU, v - incrV);
         y = f2(u - incrU, v - incrV);
         z = f3(u - incrU, v - incrV);
         ProjetaPonto(x, y, z, &X4, &Y4);
         
         line(X1, Y1, X2, Y2);
         line(X4, Y4, X2, Y2);
         line(X3, Y3, X4, Y4);
         line(X3, Y3, X1, Y1);
         
         v = v + incrV;
      }
      
      u = u + incrU;
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
   hwnd = CreateWindowEx(0,"Janela","Gráficos de Superfícies",
   WS_OVERLAPPED|WS_SYSMENU|WS_SIZEBOX|WS_MAXIMIZEBOX|WS_MINIMIZEBOX,
   50,50,843,500,NULL,NULL,NULL,NULL);
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
   case WM_CREATE: //Processo de criação da janela
   
   label = CreateWindowEx(0,"STATIC",
           "Clique em uma das funções acima para plotar o gráfico e tecle"
           " algo para sair.\n\n\Professor: Juan Carlos\nDisciplina:"
           " Cálculo II\nTrabalho: Gráficos de Superfícies\nAluno: Alinsson"
           " Figueira de Souza",
           WS_CHILD|WS_VISIBLE,10,365,600,400,window,(HMENU)lab,NULL,0);
   bot1 = CreateWindowEx(0,"BUTTON","F(u,v)=(u,v,sin(u*u+v*v)/2*2)",
          WS_CHILD|WS_VISIBLE,415,80,400,30,window,(HMENU)func1,0,0);
   bot2 = CreateWindowEx(0,"BUTTON","Garrafa de Klein",
          WS_CHILD|WS_VISIBLE,415,10,400,30,window,(HMENU)func2,0,0);
   bot3 = CreateWindowEx(0,"BUTTON",
          "F(u,v)=(u,v,3*sin(u)*sin(v)/(2+sin(u)*sin(v)))",
          WS_CHILD|WS_VISIBLE,415,255,400,30,window,(HMENU)func3,0,0);
   bot4 = CreateWindowEx(0,"BUTTON","Esfera de raio R",
          WS_CHILD|WS_VISIBLE,10,220,400,30,window,(HMENU)func4,0,0);
   bot5 = CreateWindowEx(0,"BUTTON","Cilindro Circular Eliptico de raio R",
          WS_CHILD|WS_VISIBLE,10,325,400,30,window,(HMENU)func5,0,0);
   bot6 = CreateWindowEx(0,"BUTTON","Cone",
          WS_CHILD|WS_VISIBLE,10,45,400,30,window,(HMENU)func6,0,0);
   bot7 = CreateWindowEx(0,"BUTTON","Helicóide",
          WS_CHILD|WS_VISIBLE,10,80,400,30,window,(HMENU)func7,0,0);
   bot8 = CreateWindowEx(0,"BUTTON","Toro",
          WS_CHILD|WS_VISIBLE,10,10,400,30,window,(HMENU)func8,0,0);
   bot9 = CreateWindowEx(0,"BUTTON","Catenóide",
          WS_CHILD|WS_VISIBLE,10,115,400,30,window,(HMENU)func9,0,0);
   bot10 = CreateWindowEx(0,"BUTTON","Hiperbolóide de 1 Folha",
           WS_CHILD|WS_VISIBLE,10,290,400,30,window,(HMENU)func10,0,0);
   bot11 = CreateWindowEx(0,"BUTTON","Curvatura Gaussiana",
           WS_CHILD|WS_VISIBLE,10,255,400,30,window,(HMENU)func11,0,0);
   bot12 = CreateWindowEx(0,"BUTTON","Elipsóide",
           WS_CHILD|WS_VISIBLE,10,150,400,30,window,(HMENU)func12,0,0);
   bot13 = CreateWindowEx(0,"BUTTON",
           "F(u,v)=(u*sin(u)*cos(v),u*sin(v),u*cos(u)*cos(v))",
           WS_CHILD|WS_VISIBLE,415,290,400,30,window,(HMENU)func13,0,0);
   bot14 = CreateWindowEx(0,"BUTTON","Parabolóide Hiperbólico",
           WS_CHILD|WS_VISIBLE,415,45,400,30,window,(HMENU)func14,0,0);
   bot15 = CreateWindowEx(0,"BUTTON",
           "F(u,v)=(11+2*cos(u))*cos(v),(11+2*cos(u))*sen(v),2*sen(u)+v)",
           WS_CHILD|WS_VISIBLE,415,325,400,30,window,(HMENU)func15,0,0);
   bot16 = CreateWindowEx(0,"BUTTON","Pseudo-Esfera",
           WS_CHILD|WS_VISIBLE,10,185,400,30,window,(HMENU)func16,0,0);
   bot17 = CreateWindowEx(0,"BUTTON","F(u,v)=(u,v,1-sqrt(sqrt((u*v)*(u*v)))",
           WS_CHILD|WS_VISIBLE,415,150,400,30,window,(HMENU)func17,0,0);
   bot18 = CreateWindowEx(0,"BUTTON","F(u,v)=(u,v,0,05*(u*u*u-3*u*v*v))",
           WS_CHILD|WS_VISIBLE,415,115,400,30,window,(HMENU)func18,0,0);
   bot19 = CreateWindowEx(0,"BUTTON",
           "F(u,v)=(u,v,8*sin(u*v*v-v*u*u)/(1+u*u*v*v))",
           WS_CHILD|WS_VISIBLE,415,220,400,30,window,(HMENU)func19,0,0);
   bot20 = CreateWindowEx(0,"BUTTON",
           "F(u,v)=(u,v,1-4*sin(u*u+v*v)/(u*u+v*v))",
           WS_CHILD|WS_VISIBLE,415,185,400,30,window,(HMENU)func20,0,0);

break;

/* Mensagem enviada quando um controle é clicado:                           */
case WM_COMMAND:
   switch(wParam) {

   /* F(u, v) = (u, v, sin(u * u + v * v)/4)                                */
   case func1:
     op = 1;
  
     initwindow(800, 800, "Gráficos de Superfície");
     
      /* Defini (A, B) como sendo as coordenadas do centro da tela          */
      A = getmaxx()/2, B = getmaxy()/2;
      a = getmaxx()/2, b = getmaxy()/2;
          
      K = 60;             /* Cooeficiente de ampliacao                      */
      nu = 100,           /* Quant. subdivisores no dominio da variavel u   */
      nv = 100,           /* Quant. subdivisores no dominio da variavel v   */
      fi = -M_PI/7,       /* Angulo de rotacao em torno do eixo y           */
      teta = -M_PI/7,     /* Angulo de rotacao em torno do eixo z           */
      DesenhaSuperficie(-2 * dom, 2 * dom, -2 * dom, 2 * dom, RED);
      DesenhaEixos(6, YELLOW, WHITE);
      setcolor(WHITE);
      outtextxy(320, 700, "F(u, v) = sin(u * u + v * v)/4");
      
      /* Espera teclar uma tecla para sair do Modo Grafico em closegraph()  */
      getch();

      /* Fecha Modo Gráfico                                                 */
      closegraph();

   break;
   
   /* Garrafa de Klein                                                      */
 	 case func2:
      op = 2;
     
      initwindow(800, 800, "Gráficos de Superfície");
       
      /* Defini (A, B) como sendo as coordenadas do centro da tela          */
      A = getmaxx()/2, B = getmaxy()/2;
      a = getmaxx()/2, b = getmaxy()/2;
  
      K = 15,             /* Cooeficiente de ampliacao                      */
      nu = 60,            /* Quant. subdivisores no dominio da variavel u   */
      nv = 60,            /* Quant. subdivisores no dominio da variavel v   */
      fi = -2,            /* Angulo de rotacao em torno do eixo y           */
      teta = -1.5,        /* Angulo de rotacao em torno do eixo z           */
      DesenhaSuperficie(-dom, 2 * dom, -dom, 2 * dom, RED);
      DesenhaEixos(24, YELLOW, WHITE);
      setcolor(WHITE);
      outtextxy(350, 700, "Garrafa de Klein");
   
      /* Espera teclar uma tecla para sair do Modo Grafico em closegraph()  */
      getch();

      /* Fecha Modo Gráfico                                                 */
      closegraph();

	 break;
	 
   /* F(u, v) = (u, v, 3 * sin(u) * sin(v)/(2 + sin(u) * sin(v)))           */
 	 case func3:
      op = 3;
       
      initwindow(800, 800, "Gráficos de Superfície");
         
      /* Defini (A, B) como sendo as coordenadas do centro da tela          */
      A = getmaxx()/2, B = getmaxy()/2;
      a = getmaxx()/2, b = getmaxy()/2;
      
      K = 60,             /* Cooeficiente de ampliacao                      */
      nu = 100,           /* Quant. subdivisores no dominio da variavel u   */
      nv = 100,           /* Quant. subdivisores no dominio da variavel v   */
      fi = -M_PI/11,      /* Angulo de rotacao em torno do eixo y           */
      teta = -M_PI/11,    /* Angulo de rotacao em torno do eixo z           */
      DesenhaSuperficie(-2 * dom, 2 * dom, -2 * dom, 2 * dom, RED);
      DesenhaEixos(6, YELLOW, WHITE);
      setcolor(WHITE);
      outtextxy(250, 700,
      "F(u, v) = (u, v, 3 * sin(u) * sin(v)/(2 + sin(u) * sin(v)))");
   
      /* Espera teclar uma tecla para sair do Modo Grafico em closegraph()  */
      getch();

      /* Fecha Modo Gráfico                                                 */
      closegraph();

	 break;

   /* Esfera de raio R                                                      */
   case func4:
      op = 4;
       
      initwindow(800, 800, "Gráficos de Superfície");
         
       /* Defini (A, B) como sendo as coordenadas do centro da tela         */
      A = getmaxx()/2, B = getmaxy()/2;
      a = getmaxx()/2, b = getmaxy()/2;
    
      K = 60,             /* Cooeficiente de ampliacao                      */
      R = 5,              /* Raio                                           */
      nu = 100,           /* Quant. subdivisores no dominio da variavel u   */
      nv = 100,           /* Quant. subdivisores no dominio da variavel v   */
      fi = -M_PI/7,       /* Angulo de rotacao em torno do eixo y           */
      teta = -M_PI/7,     /* Angulo de rotacao em torno do eixo z           */
      DesenhaSuperficie(-dom, dom, -dom, dom, RED);
      DesenhaEixos(6, YELLOW, WHITE);
      setcolor(WHITE);
      outtextxy(270, 720, "Plotagem de uma Esfera de raio R = 5");
      
      /* Espera teclar uma tecla para sair do Modo Grafico em closegraph()  */
      getch();

      /* Fecha Modo Gráfico                                                 */
      closegraph();

	 break;

   /* Cilindro Circular Eliptico de raio R                                  */
	 case func5:
      op = 5;
      initwindow(800, 800, "Gráficos de Superfície");
         
      /* Defini (A, B) como sendo as coordenadas do centro da tela          */
      A = getmaxx()/2, B = getmaxy()/2;
      a = getmaxx()/2, b = getmaxy()/2;
    
      K = 60,             /* Cooeficiente de ampliacao                      */
      R = 5,              /* Raio                                           */
      nu = 100,           /* Quant. subdivisores no dominio da variavel u   */
      nv = 100,           /* Quant. subdivisores no dominio da variavel v   */
      fi = -M_PI/7,       /* Angulo de rotacao em torno do eixo y           */
      teta = -M_PI/7,     /* Angulo de rotacao em torno do eixo z           */
      DesenhaSuperficie(-dom, dom, -dom, dom, RED);
      DesenhaEixos(6, YELLOW, WHITE);
      setcolor(WHITE);
      outtextxy(280, 720, "Cilindro circular eliptico de raio R = 5");

      /* Espera teclar uma tecla para sair do Modo Grafico em closegraph()  */
      getch();
    
      /* Fecha Modo Gráfico                                                 */
      closegraph();

	 break;

   /* Cone                                                                  */
	 case func6:
      op = 6;
      initwindow(800, 800, "Gráficos de Superfície");
         
      /* Defini (A, B) como sendo as coordenadas do centro da tela          */
      A = getmaxx()/2, B = getmaxy()/2;
      a = getmaxx()/2, b = getmaxy()/2;
    
      K = 70,             /* Cooeficiente de ampliacao                      */
      nu = 100,           /* Quant. subdivisores no dominio da variavel u   */
      nv = 100,           /* Quant. subdivisores no dominio da variavel v   */
      fi = -M_PI/7,       /* Angulo de rotacao em torno do eixo y           */
      teta = -M_PI/7,     /* Angulo de rotacao em torno do eixo z           */
      DesenhaSuperficie(-dom, dom, -dom, dom, RED);
      DesenhaEixos(6, YELLOW, WHITE);
      setcolor(WHITE);
      outtextxy(370, 720, "Cone");

      /* Espera teclar uma tecla para sair do Modo Grafico em closegraph()  */
      getch();

      /* Fecha Modo Gráfico                                                 */
      closegraph();

	 break;

   /* Helicóide                                                             */
	 case func7:
      op = 7;
      initwindow(800, 800, "Gráficos de Superfície");
         
      /* Defini (A, B) como sendo as coordenadas do centro da tela          */
      A = getmaxx()/2, B = getmaxy()/2;
      a = getmaxx()/2, b = getmaxy()/2;
    
      K = 80,             /* Cooeficiente de ampliacao                      */
      nu = 100,           /* Quant. subdivisores no dominio da variavel u   */
      nv = 100,           /* Quant. subdivisores no dominio da variavel v   */
      fi = -M_PI/5,       /* Angulo de rotacao em torno do eixo y           */
      teta = -M_PI/5,     /* Angulo de rotacao em torno do eixo z           */
      DesenhaSuperficie(-dom, dom, -dom, dom, RED);
      DesenhaEixos(6, YELLOW, WHITE);
      setcolor(WHITE);
      outtextxy(390, 720, "Helicóide");

      /* Espera teclar uma tecla para sair do Modo Grafico em closegraph()  */
      getch();
    
      /* Fecha Modo Gráfico                                                 */
      closegraph();

	 break;
	
	 /* Toro                                                                  */
   case func8:
      op = 8;
      initwindow(800, 800, "Gráficos de Superfície");
     
      /* Defini (A, B) como sendo as coordenadas do centro da tela          */
      A = getmaxx()/2, B = getmaxy()/2;
      a = getmaxx()/2, b = getmaxy()/2;

      c = 1,              /* Contante real                                  */
      d = 3,              /* Contante real                                  */
      K = 70,             /* Cooeficiente de ampliacao                      */
      nu = 100,           /* Quant. subdivisores no dominio da variavel u   */
      nv = 100,           /* Quant. subdivisores no dominio da variavel v   */
      fi = -M_PI/7,       /* Angulo de rotacao em torno do eixo y           */
      teta = -M_PI/7,     /* Angulo de rotacao em torno do eixo z           */
      DesenhaSuperficie(-dom, dom, -dom, dom, RED);
      DesenhaEixos(6, YELLOW, WHITE);
      setcolor(WHITE);
      outtextxy(380, 720, "Toro");
      
      /* Espera teclar uma tecla para sair do Modo Grafico em closegraph()  */
      getch();

      /* Fecha Modo Gráfico                                                 */
      closegraph();

	 break;

	 /* Catenóide                                                             */
   case func9:
      op = 9;
      initwindow(800, 800, "Gráficos de Superfície");
         
      /* Defini (A, B) como sendo as coordenadas do centro da tela          */
      A = getmaxx()/2, B = getmaxy()/2;
      a = getmaxx()/2, b = getmaxy()/2;
    
      c = 3,              /* Contante real                                  */
      K = 70,             /* Cooeficiente de ampliacao                      */
      nu = 80,            /* Quant. subdivisores no dominio da variavel u   */
      nv = 80,            /* Quant. subdivisores no dominio da variavel v   */
      fi = -M_PI/7,       /* Angulo de rotacao em torno do eixo y           */
      teta = -M_PI/7,     /* Angulo de rotacao em torno do eixo z           */
      DesenhaSuperficie(-dom, dom, -dom, dom, RED);
      DesenhaEixos(6, YELLOW, WHITE);
      setcolor(WHITE);
      outtextxy(370, 720, "Catenóide");

      /* Espera teclar uma tecla para sair do Modo Grafico em closegraph()  */
      getch();
    
      /* Fecha Modo Gráfico                                                 */
      closegraph();

	 break;

	 /* Hiperbolóide de 1 folha                                               */
   case func10:
      op = 10;
      initwindow(800, 800, "Gráficos de Superfície");
       
      /* Defini (A, B) como sendo as coordenadas do centro da tela          */
      A = getmaxx()/2, B = getmaxy()/2;
      a = getmaxx()/2, b = getmaxy()/2;

      K = 70,             /* Cooeficiente de ampliacao                      */
      nu = 100,           /* Quant. subdivisores no dominio da variavel u   */
      nv = 100,           /* Quant. subdivisores no dominio da variavel v   */
      fi = -M_PI/7,       /* Angulo de rotacao em torno do eixo y           */
      teta = -M_PI/7,     /* Angulo de rotacao em torno do eixo z           */
      DesenhaSuperficie(-dom, dom, -dom, dom, RED);
      DesenhaEixos(6, YELLOW, WHITE);
      setcolor(WHITE);
      outtextxy(330, 720, "Hiperbolóide de 1 folha");
      
      /* Espera teclar uma tecla para sair do Modo Grafico em closegraph()  */
      getch();

      /* Fecha Modo Gráfico                                                 */
      closegraph();

	 break;

	 /*  Curvatura Gaussiana                                                  */
   case func11:
      op = 11;
      initwindow(800, 800, "Gráficos de Superfície");
     
      /* Defini (A, B) como sendo as coordenadas do centro da tela          */
      A = getmaxx()/2, B = getmaxy()/2;
      a = getmaxx()/2, b = getmaxy()/2;
   
      K = 70,             /* Cooeficiente de ampliacao                      */
      nu = 100,           /* Quant. subdivisores no dominio da variavel u   */
      nv = 100,           /* Quant. subdivisores no dominio da variavel v   */
      fi = -M_PI/7,       /* Angulo de rotacao em torno do eixo y           */
      teta = -M_PI/7,     /* Angulo de rotacao em torno do eixo z           */
      DesenhaSuperficie(-dom, dom, -dom, dom, RED);
      DesenhaEixos(6, YELLOW, WHITE);
      setcolor(WHITE);
      outtextxy(350, 720, "Curvatura Gaussiana");

      /* Espera teclar uma tecla para sair do Modo Grafico em closegraph()  */
      getch();
    
      /* Fecha Modo Gráfico                                                 */
      closegraph();

   break;

	 /* Elipsóide                                                             */
   case func12:
      op = 12;
      initwindow(800, 800, "Gráficos de Superfície");
     
      /* Defini (A, B) como sendo as coordenadas do centro da tela          */
      A = getmaxx()/2, B = getmaxy()/2;
      a = getmaxx()/2, b = getmaxy()/2;

      c = 1,              /* Contante real                                  */
      d = 4,              /* Contante real                                  */
      K = 70,             /* Cooeficiente de ampliacao                      */
      nu = 100,           /* Quant. subdivisores no dominio da variavel u   */
      nv = 100,           /* Quant. subdivisores no dominio da variavel v   */
      fi = -M_PI/7,       /* Angulo de rotacao em torno do eixo y           */
      teta = -M_PI/7,     /* Angulo de rotacao em torno do eixo z           */
      DesenhaSuperficie(-dom, dom, -dom, dom, RED);
      DesenhaEixos(6, YELLOW, WHITE);
      setcolor(WHITE);
      outtextxy(380, 720, "Elipsóide");
      
      /* Espera teclar uma tecla para sair do Modo Grafico em closegraph()  */
      getch();

      /* Fecha Modo Gráfico                                                 */
      closegraph();

	 break;
	 
	 /* F(u, v) = (u * sin(u) * cos(v), u * sin(v), u * cos(u) * cos(v)       */
	 case func13:
      op = 13;
      initwindow(800, 800, "Gráficos de Superfície");
     
      /* Defini (A, B) como sendo as coordenadas do centro da tela          */
      A = getmaxx()/2, B = getmaxy()/2;
      a = getmaxx()/2, b = getmaxy()/2;

      K = 50,             /* Cooeficiente de ampliacao                      */
      nu = 80,            /* Quant. subdivisores no dominio da variavel u   */
      nv = 80,            /* Quant. subdivisores no dominio da variavel v   */
      fi = -M_PI/7,       /* Angulo de rotacao em torno do eixo y           */
      teta = -M_PI/7,     /* Angulo de rotacao em torno do eixo z           */
      DesenhaSuperficie(0, 2*dom, 0, dom, RED);
      DesenhaEixos(6, YELLOW, WHITE);
      setcolor(WHITE);
      outtextxy(220, 720,
      "F(u, v) = (u * sin(u) * cos(v), u * sin(v), u * cos(u) * cos(v)");
      
      /* Espera teclar uma tecla para sair do Modo Grafico em closegraph()  */
      getch();

      /* Fecha Modo Gráfico                                                 */
      closegraph();

   break;

   /* Parabolóide Hiperbólico                                               */
   case func14:
      op = 14;
      initwindow(800, 800, "Gráficos de Superfície");
     
      /* Defini (A, B) como sendo as coordenadas do centro da tela          */
      A = getmaxx()/2, B = getmaxy()/2;
      a = getmaxx()/2, b = getmaxy()/2;

      c = 2,              /* Contante real                                  */
      d = 3,              /* Contante real                                  */
      K = 30,             /* Cooeficiente de ampliacao                      */
      nu = 100,           /* Quant. subdivisores no dominio da variavel u   */
      nv = 100,           /* Quant. subdivisores no dominio da variavel v   */
      fi = -M_PI/7,       /* Angulo de rotacao em torno do eixo y           */
      teta = -M_PI/7,     /* Angulo de rotacao em torno do eixo z           */
      DesenhaSuperficie(-dom, dom, -dom, dom, RED);
      DesenhaEixos(12, YELLOW, WHITE);
      setcolor(WHITE);
      outtextxy(340, 720, "Parabolóide Hiperbólico");
      
      /* Espera teclar uma tecla para sair do Modo Grafico em closegraph()  */
      getch();

      /* Fecha Modo Gráfico                                                 */
      closegraph();
   
   break;
   
   /* Cilindro Hiperbólico de raio R                                        */
   case func15:
      op = 15;
      initwindow(800, 800, "Gráficos de Superfície");
     
      /* Defini (A, B) como sendo as coordenadas do centro da tela          */
      A = getmaxx()/2, B = getmaxy()/2;
      a = getmaxx()/2, b = getmaxy()/2;

      K = 20,             /* Cooeficiente de ampliacao                      */
      nu = 120,           /* Quant. subdivisores no dominio da variavel u   */
      nv = 120,           /* Quant. subdivisores no dominio da variavel v   */
      fi = -M_PI/7,       /* Angulo de rotacao em torno do eixo y           */
      teta = -M_PI/7,     /* Angulo de rotacao em torno do eixo z           */
      DesenhaSuperficie(-4*dom, 4*dom, -4*dom, 4*dom, RED);
      DesenhaEixos(20, YELLOW, WHITE);
      setcolor(WHITE);
      outtextxy(230, 720,
      "F(u,v) = ((11 + 2 cos(u)) cos(v),(11 + 2 cos(u)) sen(v),2 sen(u) + v)");
      
      /* Espera teclar uma tecla para sair do Modo Grafico em closegraph()  */
      getch();

      /* Fecha Modo Gráfico                                                 */
      closegraph();
  
   break;
   
   /* Pseudo-Esfera                                                         */
   case func16:
      op = 16;
      initwindow(800, 800, "Gráficos de Superfície");
     
      /* Defini (A, B) como sendo as coordenadas do centro da tela          */
      A = getmaxx()/2, B = getmaxy()/2;
      a = getmaxx()/2, b = getmaxy()/2;

      c = 1,              /* Contante real                                  */
      K = 70,             /* Cooeficiente de ampliacao                      */
      nu = 100,           /* Quant. subdivisores no dominio da variavel u   */
      nv = 100,           /* Quant. subdivisores no dominio da variavel v   */
      fi = -M_PI/7,       /* Angulo de rotacao em torno do eixo y           */
      teta = -M_PI/7,     /* Angulo de rotacao em torno do eixo z           */
      DesenhaSuperficie(-2*dom, 2*dom, 0, dom, RED);
      DesenhaEixos(6, YELLOW, WHITE);
      setcolor(WHITE);
      outtextxy(360, 720, "Pseudo-Esfera");
      
      /* Espera teclar uma tecla para sair do Modo Grafico em closegraph()  */
      getch();

      /* Fecha Modo Gráfico                                                 */
      closegraph();
   
   break;        
   
   /* F(u, v) = (u, v, 1 - sqrt(sqrt((u*v)(u*v)))                           */
   case func17:
      op = 17;
      initwindow(800, 800, "Gráficos de Superfície");
     
      /* Defini (A, B) como sendo as coordenadas do centro da tela          */
      A = getmaxx()/2, B = getmaxy()/2;
      a = getmaxx()/2, b = getmaxy()/2;

      K = 50,             /* Cooeficiente de ampliacao                      */
      nu = 100,           /* Quant. subdivisores no dominio da variavel u   */
      nv = 100,           /* Quant. subdivisores no dominio da variavel v   */
      fi = -M_PI/7,       /* Angulo de rotacao em torno do eixo y           */
      teta = -M_PI/7,     /* Angulo de rotacao em torno do eixo z           */
      DesenhaSuperficie(-2*dom, 2*dom, -2*dom, 2*dom, RED);
      DesenhaEixos(6, YELLOW, WHITE);
      setcolor(WHITE);
      outtextxy(320, 720, "F(u, v) = (u, v, 1 - sqrt|u*v|)");
      
      /* Espera teclar uma tecla para sair do Modo Grafico em closegraph()  */
      getch();

      /* Fecha Modo Gráfico                                                 */
      closegraph();
   
   break;
   
   /* F(u, v) = (u, v, 0,05*(u * u * u - 3 * u * v * v))                    */
	 case func18:
      op = 18;
      initwindow(800, 800, "Gráficos de Superfície");
     
      /* Defini (A, B) como sendo as coordenadas do centro da tela          */
      A = getmaxx()/2, B = getmaxy()/2;
      a = getmaxx()/2, b = getmaxy()/2;

      K = 20,             /* Cooeficiente de ampliacao                      */
      nu = 100,           /* Quant. subdivisores no dominio da variavel u   */
      nv = 100,           /* Quant. subdivisores no dominio da variavel v   */
      fi = -M_PI/3,       /* Angulo de rotacao em torno do eixo y           */
      teta = -M_PI/3,     /* Angulo de rotacao em torno do eixo z           */
      DesenhaSuperficie(-dom, dom, -dom, dom, RED);
      DesenhaEixos(6, YELLOW, WHITE);
      setcolor(WHITE);
      outtextxy(220, 720,
      "F(u, v) = (u, v, 0,05 * (u * u * u - 3 * u * v * v))");
      
      /* Espera teclar uma tecla para sair do Modo Grafico em closegraph()  */
      getch();

      /* Fecha Modo Gráfico                                                 */
      closegraph();

   break;
   
   /* F(u, v) = (u, v, 8 * sin(u * v * v - v * u * u)/(1 +  u * u * v * v)) */
   case func19:
      op = 19;
      initwindow(800, 800, "Gráficos de Superfície");
     
      /* Defini (A, B) como sendo as coordenadas do centro da tela          */
      A = getmaxx()/2, B = getmaxy()/2;
      a = getmaxx()/2, b = getmaxy()/2;

      K = 60,             /* Cooeficiente de ampliacao                      */
      nu = 100,           /* Quant. subdivisores no dominio da variavel u   */
      nv = 100,           /* Quant. subdivisores no dominio da variavel v   */
      fi = -M_PI/7,       /* Angulo de rotacao em torno do eixo y           */
      teta = -M_PI/6,     /* Angulo de rotacao em torno do eixo z           */
      DesenhaSuperficie(-2*dom, 2*dom, -2*dom, 2*dom, RED);
      DesenhaEixos(6, YELLOW, WHITE);
      setcolor(WHITE);
      outtextxy(220, 720,
      "F(u, v) = (u, v, 8 * sin(u * v * v - v * u * u)/(1 +  u * u * v * v))");
      
      /* Espera teclar uma tecla para sair do Modo Grafico em closegraph()  */
      getch();

      /* Fecha Modo Gráfico                                                 */
      closegraph();

   break;
   
   /*F(u, v) = (u, v, 1 - 4 * sin(u * u + v * v)/(u * u + v * v))           */
   case func20:
      op = 20;
      initwindow(800, 800, "Gráficos de Superfície");
     
      /* Defini (A, B) como sendo as coordenadas do centro da tela          */
      A = getmaxx()/2, B = getmaxy()/2;
      a = getmaxx()/2, b = getmaxy()/2;

      K = 60,             /* Cooeficiente de ampliacao                      */
      nu = 100,           /* Quant. subdivisores no dominio da variavel u   */
      nv = 100,           /* Quant. subdivisores no dominio da variavel v   */
      fi = -M_PI/7,       /* Angulo de rotacao em torno do eixo y           */
      teta = -M_PI/6,     /* Angulo de rotacao em torno do eixo z           */
      DesenhaSuperficie(-2*dom, 2*dom, -2*dom, 2*dom, RED);
      DesenhaEixos(6, YELLOW, WHITE);
      setcolor(WHITE);
      outtextxy(220, 720,
      "F(u, v) = (u, v, 1 - 4 * sin(u * u + v * v)/(u * u + v * v))");
      
      /* Espera teclar uma tecla para sair do Modo Grafico em closegraph()  */
      getch();

      /* Fecha Modo Gráfico                                                 */
      closegraph();
     
	} break;

default:
	return DefWindowProc(window,msg,wParam,lParam);
}
 
return 0;
}

/* ------------------------------------------------------------------------ */

/*** FIM DE "Main.c" ***/
