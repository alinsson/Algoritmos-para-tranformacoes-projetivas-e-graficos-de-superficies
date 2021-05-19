# Algoritmos para tranformações projetivas e gráficos de superfícies em wireframes

Estes códigos foram desenvolvidos em 2011 para um trabalho de Cálculo 2 em um curso de Engenharia da Computação na UFC.

Aqui é descrito alguns tipos de transformações projetivas do IR³ e alguns algoritmos que podem ser usados na construção do gráfico de uma superfície em modelo wireframe.

O objetivo da Geometria Descritiva é representar com total rigor objetos tridimensionais num suporte bidimensional (papel, por exemplo).

A projeção ortográfica é uma forma de representar graficamente objetos tridimensionais em superfícies planas, de modo a transmitir suas características com precisão e demonstrar sua verdadeira grandeza. Temos ainda Projeção cilíndrica ou paralela (do tipo oblíqua e ortogonal) e cônica ou central.

Primeiros testes com gráficos planos:

![image](https://user-images.githubusercontent.com/6897439/118873679-66a12300-b8c0-11eb-9b45-d1ce8b307f84.png)

O código constrói o gráfico de uma superfície definida em forma paramétrica por F(u,v) = (f1(u,v), f2(u,v), f3(u,v)), com u E [umin, umax] e v E [umin, umax]:

![image](https://user-images.githubusercontent.com/6897439/118873761-820c2e00-b8c0-11eb-9ca8-d771cb44dee6.png)

Existem técnicas para melhorar a visualização do seu gráfico, como sombreamento, pintura e eliminação de curvas invisíveis. Para isso vários algoritmos podem ser usados, por exemplo:
- Algoritmo do Pintor;
- Algoritmo do Horizonte Flutuante;

Usado com gráficos de funções z = f(x,y).
Algumas funções utilizadas:

![image](https://user-images.githubusercontent.com/6897439/118873795-8b959600-b8c0-11eb-82d9-acfa1e3ffa9f.png)
![image](https://user-images.githubusercontent.com/6897439/118873818-918b7700-b8c0-11eb-9538-6f9ed87d1677.png)

Resultado:

![image](https://user-images.githubusercontent.com/6897439/118873879-a536dd80-b8c0-11eb-936c-977c96e16033.png)
![image](https://user-images.githubusercontent.com/6897439/118873888-a831ce00-b8c0-11eb-820a-24a4609516bb.png)
![image](https://user-images.githubusercontent.com/6897439/118873897-aa942800-b8c0-11eb-9ec5-bd78f853f858.png)
![image](https://user-images.githubusercontent.com/6897439/118873912-ae27af00-b8c0-11eb-9fa9-4b95646ce4e0.png)
![image](https://user-images.githubusercontent.com/6897439/118873925-b1bb3600-b8c0-11eb-8c20-55bdf88222fb.png)
![image](https://user-images.githubusercontent.com/6897439/118873936-b41d9000-b8c0-11eb-85dd-a1a46fdd3a74.png)
![image](https://user-images.githubusercontent.com/6897439/118873945-b7188080-b8c0-11eb-9e1f-725575862505.png)
![image](https://user-images.githubusercontent.com/6897439/118873959-ba137100-b8c0-11eb-97c1-d5a224a83e05.png)
![image](https://user-images.githubusercontent.com/6897439/118873965-bc75cb00-b8c0-11eb-9148-7408a5998d50.png)
![image](https://user-images.githubusercontent.com/6897439/118873976-bf70bb80-b8c0-11eb-894a-e7b7e7b0bbaa.png)

Este material é apenas um complemento do trabalho do professor Lenimar Nunes de Andrade, orientador de mestrado do meu professor de Cálculo II, Juan Carlos Oliveira de Medeiros.
Foram utilizados os artigos Curvas e superfícies de Bélzies e B-splines e Transformações Projetivas de Gráficos de Superfícies do professor Lenimar N. Andrade. Os algoritmos no artigo foram escritos em 1999 na linguagem C. 

Instruções para rodar os arquivos:
- Usando a biblioteca graphics.h no compilador DEV-C++;
- Copiar os seguintes arquivos:
	- graphics.h em C:\Dev-Cpp\include
	- libbgi.a em C:\Dev-Cpp\lib 
- Crie um novo projeto;
- Depois de criar o projeto, Opções do Projeto -> Parâmetros e no campo Linker, colocar as opções:
	- lbgi
	- lgdi32
	- lcomdlg32
	- luuid
	- loleaut32
	- lole32
