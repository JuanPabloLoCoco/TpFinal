#define MovValido(i,j,x,y,dim) (((i+x)<0) || ((i+y)>dim) || ((j+y)<0) || ((j+y)>dim) || ((x==0) && (y!=1))?1:0;  /*i y j representan la posicion, x e y los desplazamientos*/
#define bloque 10

int aleatorio(int izq, int der)
{ 
  int num;
  seed(time(null));
  num= srand/((double)rand_max)*(der+izq+1)
  return num;
}



int Minimo (char **matriz, int dim, *tabla[])
{
  
  int i,j,cont=0,t,s;
  
  for (i=0,i<dim, i++)
  {
    for (j=0, j<dim, j++)
    {
      for (t=0, t<2, t++)
      {
        for (s=-1,s<2,s++)
        {
          if (MovValido(i,j,t,s, dim) && matriz[i][j]==matriz[i+t][j+s])
          {
            if ((cont%bloque)==0)
            {
              tabla[]=realloc(tabla[],(cont+bloque)*sizeof tabla[]);
            }
            asignacionTabla(tabla,cont,i,j,t,s,1) 
          }
        }
      }  
    }
  }   
  tabla[]=realloc(tabla[],cont*sizeof(tabla[]);
  return cont;
}

int Maximo (char **matriz, int dim, *tabla[])
{
  int i,j,cont=0,t,s,max=1,contmax=0;
  
  for (i=0,i<dim, i++)
  {
    for (j=0, j<dim, j++)
    {
      for (t=0, t<2, t++)
      {
        for (s=-1,s<2,s++)
        {
          if (MovValido(i,j,t,s, dim) && matriz[i][j]==matriz[i+t][j+s])
          {
            cont=contarsaltos(tabla, dim, i,j,t,s)
            if (cont>max)
            {
              max=cont;
              contmax=0;
              tabla[]=realloc(tabla[],(contmax+bloque)*sizeof (*tabla[]); /*consultar que tan bien esta esto*/
              asignacionTabla(tabla,0,i,j,t,s,max));
              contmax++;
            }
            if (cont==max)
            {
              if ((contmax%bloque)==0)  
              {  
                tabla[]=realloc(tabla[],(contmax+bloque)*sizeof(tabla[]));
              }  
              asignacionTabla(tabla,contmax,i,j,t,s,max);
              contmax++;
            }
          }
        }
      }
    }
  }
  tabla[]=realloc(tabla[],(contmax)*sizeof(tabla[]));
  return contmax;
}
     


asignacionTabla(char tabla[][],int pos,int fo,int co,int x,int y,int salto)
{
  tabla[pos][0]=i;
  tabla[pos][1]=j;
  tabla[pos][2]=i+(salto*x);
  tabla[pos][3]=j+(salto*y);
}

void MovPc(char **matriz,int dim)
{
  int op,opciones,elegida;
  char *tabla[4];
  op=aleatorio(0,1);
  if (op==0)
    opciones=Minimo(matriz,dim, tabla);
  else
    opciones=Maximo(matriz, dim,tabla);
  elegida=aleatorio(1,opciones);
  hacermovimiento(tabla[elegida][0],tabla[elegida][1],tabla[elegida][2],tabla[elegida][3]);
  return;
 }
 
int contarsaltos(char ** matriz,int dim,int posx,int posy,despx,despy)
{
  int cont=1;
  for (cont=1;matriz[posx][posy]==matriz[posx+cont*despx][posy+cont*despy] && movValido(posx,posy,despx,despy,dim);cont++)
  ;
  return cont-1;
}
