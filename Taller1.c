
#include<stdio.h>


int ultimodigito(int n) 
{
    int ultimo=n%10;
    
    return ultimo;
}

int cuadrado(int n) 
{
    
    int elevado=n*n;
    
    return elevado;
}

void curiosos() 
{
    /*Imprimir los números curiosos
    menores que 100.
    (*) Número curioso: todo número
    natural n para el cual (n*n)
    contiene a n en su extremo derecho.
    Por ejemplo, 25 y 76 son números
    curiosos, pues 25(25)=625 y
    76(76)=5776.
    */
    printf("\n\nLos numeros curiosos menores que 100 son:");
    
    int nc;
    
    for(int i=1;i<100;i++)
        {
            nc=i*i;
                if(i/10==0)
                    {
                        if(nc%10==i)
                            {
                                printf("\n%d",i);
                            }
                    }
                if(i/100==0 && i != 1)
                    {
                        if(nc%100==i)
                            {
                                printf("\n%d",i);
                            }
                    } 
        }

}

int cantidaddigitos(int n) 
{
        int nuevo=n;
        int contador=0;
        while(nuevo != 0)
            {   
                nuevo=nuevo/10;
                contador++;
            }
        return contador;
}

int feliz(int n) 
{
    /*Retornar 1 si un número es feliz
    y 0 en caso contrario.

    (*) Número feliz: todo número
    natural n para el cual a la suma
    de los cuadrados de sus dígitos se
    aplica, de manera recurrente, el
    mismo proceso hasta obtener, como
    último resultado, 1.
    Por ejemplo, 203 es un número feliz
    ya que 203 ⇾ 2(2)+0(0)+3(3)=13
    ⇾ 1(1)+3(3)=10 ⇾ 1(1)+0(0)=1.
    */

    int totaldigitos=cantidaddigitos(n);
    int ncopia=n;
    int operacion=0;
    int contador=0;

    while(contador != cuadrado(cantidaddigitos(n)))
        {
            while(totaldigitos!=0) 
                {
                    operacion=operacion+cuadrado(ncopia%10);
                    ncopia=ncopia/10;
                    totaldigitos=totaldigitos-1;
                }
            ncopia=operacion;
            operacion=0;
            totaldigitos=cantidaddigitos(ncopia);
            contador++;
        }
    int result=0;

    if(ncopia==1) 
        {
            result=1;
        }
    return result;
}

void oblongos() 
{
    /*
    Imprimir los números oblongos
    menores que 100.

    (*) Número oblongo: todo número
    natural n que resulta del producto
    entre dos naturales consecutivos.
    Por ejemplo, los números 30,
    42 y 56
    son números oblongos, pues 30=5*6 y
    56=7*8.
    */

    printf("\n\nLos numeros oblongos menores que 100 son:");
    for(int i=0; i<10; i++)     
        {
            printf("\n%d x %d = %d",i,i+1,i*(i+1));
        }
}

long potencia( int k,int n) 
{
    long ncopia=n;
    int i=1;

    while(i != k) 
        {
            ncopia=n*ncopia;
            i++;
        }

    return ncopia;
}

int narcisistas (int n) 
{
    /*
    Retornar 1 si un número es
    narcisista y 0 en caso contrario

    (*) Número narcisista: todo número
    natural n, de k dígitos, que es
    igual a la suma de las k potencias
    de sus dígitos.
    Por ejemplo, 153 es un número
    narcisista de 3 dígitos, ya que
    1(1)1+5(5)5+3(3)3=153.
    */

    int k=cantidaddigitos(n);
    int ncopia=n;
    int operacion=0;

    while(k != 0)
        {
            operacion=potencia((cantidaddigitos(n)),ncopia%10)+operacion;
            ncopia=ncopia/10;
            k=k-1;
        }
    
    int result=0;
    
    if(n==operacion)
        {
            result=1;
        }
    return result;
}

int sumadivisores(int n) 
{
    int suma=0;
    
    for(int i=1; i<n; i++)
        {
            if(n%i==0) 
                {
                    suma=i+suma;
                }
        }
    return suma;
}

void abundantes() 
{
    /*
    Imprimir los números abundantes
    menores que 100.

    (*)Número abundante: todo número
    natural n para el cual la suma de
    sus divisores propios es mayor que
    n. Por ejemplo, 12 es abundante ya
    que sus divisores son 1, 2, 3, 4 y
    6 y se cumple que 1+2+3+4+6=16,
    que es mayor que 12.
    */
    printf("\n\nLos numeros abundantes menores que 100 son:\n");
    
    for(int n=1; n<100; n++) 
        {
            if(n==12) 
                {
                    if(n<sumadivisores(n)) 
                        {
                            printf("%d",n);
                        }
                }
            if(n>12) 
                {
                    if(n<sumadivisores(n)) 
                        {
                            printf(",%d",n);
                        }
                }
    
        }

}

int main()
{

    int n, num;

    int opcion;
    opcion=0;

    /*El menu consta de un while que nos ayudara a volver las veces que queramos a esta
    y que podamos finalizarla cuando queramos*/
      
    while(opcion != 6)
        {
            printf("\n\nmenu\n");
            
            printf("1. Imprimir los números curiosos menores que 100\n");
            
            printf("2. Función feliz que retorne 1 si un número es feliz y 0 en caso contrario:\n");
            
            printf("3. imprimir los números oblongos menores que 100:\n");
            
            printf("4. función narcisistas que retorne 1 si un número es narcisista y 0 en caso contrario:\n");
            
            printf("5. Imprimir los números abundantes menores que 100.:\n");
            
            printf("6. salir");
            
            printf("\nelija una opcion:\n");
            
            /*Las distintas opciones nos redirigen al valor guardado con anterioridad 
            y posterior a eso redirigirnos al menu.*/
            
            scanf("%d", & opcion);
            if(opcion == 1)
                  {
                        curiosos();
                  }
            if(opcion == 2)
                  {
                        printf("\n ingresa tu numero feliz:");
                        
                        scanf("%d",&n);
                        
                        if(feliz(n) == 1)
                            {
                                printf("\n\nEl numero %d es feliz",n);
                            }
                        else 
                            {
                                printf("\n\nEl numero %d no es feliz",n);
                            };
                  }
            if(opcion == 3)
                  {
                        oblongos();
                        
                  }
            if(opcion == 4)
                  {
                            printf("\n ingresa tu numero narcisista:");
                            
                            scanf("%d",&num);
                            
                            if(narcisistas(num)==1) 
                                {
                                    printf("\n\nEl numero %d es narcisista",num);
                                }
                            else 
                                {
                                    printf("\n\nEl numero %d no es narcisista",num);
                                }
                  }
            if(opcion == 5)
                  {
                        abundantes();
                  }
            if(opcion == 6)
                  {
                        printf("\nSalir");
                  }
            if(opcion != 1 && opcion != 2 && opcion != 3 && opcion !=4 && opcion !=5 && opcion != 6)
                  {
                  opcion=6;
            
                  /*Cualquier opcion que sea distinta a los valores de 1 a 6 terminara 
                  dando a entender al programa que es un 6, lo que finalizará el mismo.*/
                  }
        }    
    
    return 0;
    
}
    


