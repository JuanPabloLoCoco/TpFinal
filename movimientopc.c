#define MovValido(i,j,x,y,dim) (((i+(x))<0) || ((i+(y))>dim) || ((j+(y))<0) || ((j+(y))>dim) || ((x==0) && (y!=1))?1:0;  

/*i y j representan la posicion, x e y los desplazamientos*/
/*se analiza que no se salga de los limites de la matrix y que los movimientos sean con la L inferior*/
/*con este procedimiento se hace mas eficiente la busqueda de movimientos*/

#define bloque 10
typedef struct{
  int fi;
  int ci;
  int ff;
  int cf;
}movimiento; /*estructura con posiciones iniciales y finales de movimientos*/

int aleatorio(int izq, int der)
{ 
  int num;
  seed(time(null));
  num= srand/((double)rand_max)*(der+izq+1)
  return num;
}

int Minimo (char **matriz, int dim,movimiento *tabla)
{
  
  int i,j,t,s,cont=0;
  for (i=0,i<dim, i++)
  {
    for (j=0, j<dim, j++)
    {
      for (t=0, t<2, t++)
      {
        for (s=-1,s<2,s++)
        {    
          salto=Buscarmismo(matriz,i,j,t,s,dim) /*devuleve la cantidad de saltos que realizo hasta encontrar uno igual.*/
          if (salto!=0) /*Si salto es distinto de 0, significa que encontro en una cierta cantidad de saltos*/
          {
            if ((cont%bloque)==0)
            {
              tabla=realloc(tabla,(cont+bloque)*sizeof (movimiento));
            }
            asignacionTabla(tabla,cont,i,j,i+t*salto,j+s*salto,) 
          }  
        }
      }  
    }
  }   
  tabla=realloc(tabla,cont*sizeof(movimiento);
  return cont;
}
              
               
int Buscarmismo(char **matriz,int i, int j, int t, int s, int dim)
{
  int salto;
  for (salto=1, MovValido(i,j,t*salto,s*salto,dim) && (matriz[i+t*salto][j+s*salto]=="" || matriz[i][j]==matriz[i+t*salto][j+s*salto]),salto++) /*cuenta la cantidad de saltos en una posicion hasta encontrar indebido*/
  {
    if matriz[i][j]==matriz[i+t*salto][j+s*salto];
      return salto;  
  }
  return 0;
}                 
                  

                  
int Maximo (char **matriz, int dim,movimiento *tabla)
{
  int i,j,t,s,max=1,contmax=0,cont=0,posfx,posfy ; /*contmax es el contado del listado de maximos*/
                                      /*Cont, cuenta los saltos*/
                                      /*max, señala la cantidad maxima de botones. Inicializa en 1, porque seguro que hay movimiento*/
  for (i=0,i<dim, i++)
  {
    for (j=0, j<dim, j++)
    {
      for (t=0, t<2, t++)
      {
        for (s=-1,s<2,s++)
        {
          /*if (MovValido(i,j,t,s, dim) && matriz[i][j]==matriz[i+t][j+s])*/
          
          {
            cont=contarsaltos(matriz,i,j,t,s,dim,&posfx,&posfy)
            if (cont>max)
            {
              max=cont;
              contmax=0;
              tabla=realloc(tabla,(contmax+bloque)*sizeof (movimiento)); /*consultar que tan bien esta esto*/
              asignacionTabla(tabla,0,i,j,posfx,posfy));
              contmax++;
            }
            if (cont==max)
            {
              if ((contmax%bloque)==0)  
              {  
                tabla=realloc(tabla,(contmax+bloque)*sizeof(movimiento));
              }  
              asignacionTabla(tabla,contmax,i,j,posfx,posfy);
              contmax++;
            }
          }
        }
      }
    }
  }
  tabla=realloc(tabla,(contmax)*sizeof(movimiento));
  return contmax;
}
     
int contarsaltos(char **matriz,int x,int y, int desx, int desy, int dim, int *posfx, int *posfy )
{
  int botones=0, saltos;

  for (saltos=1, MovValido(x,y,desx*saltos,desy*saltos,dim) && (matriz[x][y]==matriz[x+desx*saltos][y+desy*saltos]||matriz[x+desx*saltos][y+desy*saltos]==""),saltos++)
  { 
    if (matriz[x][y]==matriz[x+desx*saltos][y+desy*saltos])
    { 
      botones++;
      *posfx=x+desx*saltos
      *posfy=y+desy*saltos
    }
  }
  return botones;
}
                  
asignacionTabla(movimientos tabla[],int pos,int fo,int co,int ff,int cf)
{
  tabla[pos].fi=i;
  tabla[pos].ci=j;
  tabla[pos].ff=ff;
  tabla[pos].cf=cf;
}

void MovPc(char **matriz,int dim)
{
  int op,opciones,elegida;
  movimento *tabla;
  op=aleatorio(0,1);
  if (op==0)
    opciones=Minimo(matriz,dim, tabla);
  else
    opciones=Maximo(matriz, dim,tabla);
  elegida=aleatorio(0,opciones-1);
  hacermovimiento(tabla[elegida].fi,tabla[elegida].ci,tabla[elegida].ff,tabla[elegida].cf);
  return;
 }
 
