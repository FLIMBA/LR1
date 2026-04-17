/*
#include <stdio.h>

int main(){
    int x=0;
    while (x<10)
    {  	
        printf("%d\n",x);
  	    x++;
    }
    printf("The end ");
    return 0;
}*/

/*
#include <stdio.h> 
#include <stdlib.h> 
int main()
{
    int x=0,b,k;     
    printf ("k=");	// вывод текста "k=" на экран («приглашение» перед вводом с клавиатуры)
    scanf("%d",&k);			// ввод данных с клавиатуры в переменную k
    for (;;)  
    {	
        x=x+1;
    	b=x*x; 
	    printf ("\nx=%d\tx*x=%d\n",x,b);	
	    if (x==k) break;		// выход из цикла по условию
    }
    system("pause");			
return 0;
}
*/
/*
#include <stdio.h> 
#include <stdlib.h> 
#define k 7

int main()
{
    int a,sum=0;
    for (a=1; a<=k; a++)
    {  
        if (a%2==0) continue;
        sum += a;	// эквивалентно sum=sum+a; 
    }
    printf("sum=%d\n", sum);
    //system("pause");
    return 0;
}
*/

/*
// Версия программы с контролем ошибок ввода 
#include <stdio.h> 
#include <stdlib.h> 
#define PI 3.14		// определяем константу PI

int main()
{
    int r;
    double s;
    do	
    {
        printf ("\nr="); scanf("%d",&r);
        if (r<0) // проверка введенного значения r
        {
            printf ("error: r<0 !!! \n"); // ветвь «да»:  сообщение об ошибке
	        continue;		              // досрочный переход на следующую итерацию
        }
        else  break;			          // ветвь «нет» : выход из цикла
    }while (true);		                  // бесконечный цикл (нет проверки условия)
    s=PI*r*r;
    printf ("s=%f\n",s);		          // вывод результата вычислений
    system("pause");
    return 0; 
}
*/

/*
// программа ведет диалог с оператором
#include <stdio.h> 
#include <stdlib.h>
#include <cstdlib> // русификация текстов
int main()
{
    system("chcp 65001 > nul"); // русификация текстов
    int summa=0, x,c;
    printf ("Суммирование чисел  через два (пока сумма < 100) \n ");
    printf ("****************************\n");
    do
    {
        printf ("Введите начальное число ->");	scanf ("%d",&x); 
   	    printf ("Слагаемые:\n");
	    summa=0;
	    while (summa<100)
	    {   
            summa=summa+x;		// или summa += x;
		    printf ("%d\n",x);
		    x = x+2;			// или x+=2;
	    }
	    printf ("\nСумма = %d\n",summa);
        printf ("Продолжить выполнение? (0-нет, 1-да)\n");
        scanf ("%d",&c); 
    } while (c ==1);
    system("pause");
    return 0;
}
*/

/*
#include <stdio.h> 
#include <stdlib.h>
#include <cstdlib>
int main(){	
    int i,b; 
    printf ("Вычисление квадратов чисел от 1 до 9\n");
    printf ("------------------------------------\n");
    for (i=1; i<10; i++)  
	{	
        b=i*i; 
        printf ("x=%d\t x*x=%d\n",i,b);
	}
    system("pause");
    return 0;
}
*/

/*
#include <stdio.h> 
#include <stdlib.h>
#include <cstdlib>
#define A 10
#define B 100
#define K 200
int main()
{
    system("chcp 65001 > nul"); 
    int x, y, i, sum;	
    printf ("\nСуммирование натурального ряда чисел\n");
    printf ("суммировать пока сумма < 200\n");
    printf ("---------------------------------------------\n");
    while (true)	//беcконечный цикл, выход по break 
    {
        printf ("\nВведите начальное значение для суммирования (от 10 до 100): ");
        scanf ("%d",&x);	// ввод данных с клавиатуры
        if (x>=A && x<=B)
        {
            printf ("\nВведите шаг суммирования : "); scanf ("%d",&y);
	        printf ("---------------------------------------------\nСлагаемые :\n");
	        for (i=1,sum=0; sum<K; x+=y, i++) 
	        { 	
                printf ("%d\n",x);
		        sum += x;
		        if (i>10) 	// полная форма записи (i>10)!=0
		        {
                    printf ("Количество итераций cуммирования > 10\n");
		            sum=0;
		            break; 	 // выход из цикла for
		        }
            }
            if (sum !=0) {
                printf ("сумма=%d\n",sum);
                printf ("\n--------------------------------------------------");
		    }
        }
        else {	
            printf ("Начальное значение вне допустимого диапазона, конец вычислений\n");
	        break; // выход из беcконечного цикла
        }
    }
    system("pause");
    return 0;
}
*/

/*
#include <stdio.h> 
#include <stdlib.h>
#include <cstdlib>
#define d1 32
#define d2 365
#define n 6
int main()
{
    int  count, errc=0;
    double farin, celsius;
    system("chcp 65001 > nul"); 
    printf ("Перевод значений: температура по Фаренгейту –> температура по Цельсию\n");
    printf ("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
    for (count = 1; count <= 6; count++)
    {
        printf ("Введите значение температуры  от %d  до %d\n(значение по Фаренгейту):",d1,d2);
        scanf ("%le",&farin);
        while (farin < d1 || farin > d2)
 	    {
            if (errc<5)
		    {
                errc++;
		        printf ("Повторите ввод, ошибка № %d:  ",errc);
		        scanf ("%d",&farin);
                if (farin >= d1 && farin <= d2)
                {
                    break;  // выходим из while, если значение корректное
                }
		    }
		    else goto ex0;		// выход из двух вложенный циклов
        }//-------------- конец цикла while
        celsius =  (farin - 32)/1.8;
        printf ("%f (по Фаренгейту) = %f (по Цельсию)",farin,celsius);
        printf ("\n------------------------------------------------------------\n");
    }//--------- конец цикла for
	printf ("\nНормальное завершение \n");
	system("pause");
	return 0;

ex0:  
    printf ("\nАварийное завершение : оператор ошибся более 5 раз!!!\n");	
    system("pause");
    return 1;
}
*/

#include <stdio.h>
#include <stdlib.h>
#define d1 32
#define d2 365
#define n 6

int main()
{
    int count, errc = 0;
    double farin, celsius;
    
    system("chcp 65001 > nul");
    
    printf("Перевод значений: температура по Фаренгейту -> температура по Цельсию\n");
    printf("+++++++++++++++++++++++++++++++++++++++++++++++++\n");
    
    for (count = 1; count <= n; count++)
    {
        printf("Введите значение температуры от %d до %d\n(значение по Фаренгейту):", d1, d2);
        scanf("%lf", &farin);
        
        while (farin < d1 || farin > d2)  // пока значение некорректное
        {
            if (errc < 5)
            {
                errc++;
                printf("Повторите ввод, ошибка № %d: ", errc);
                scanf("%lf", &farin);
                
                // ВАЖНО: сразу проверяем новое значение
                if (farin >= d1 && farin <= d2)
                {
                    break;  // выходим из while, если значение корректное
                }
                // если значение всё ещё некорректное - цикл продолжается
            }
            else goto ex0;  // слишком много ошибок
        }
        
        // Если дошли сюда - значение корректное
        celsius = (farin - 32) / 1.8;
        printf("%f (по Фаренгейту) = %f (по Цельсию)", farin, celsius);
        printf("\n------------------------------------------------------------\n");
    }
    
    printf("\nНормальное завершение \n");
    system("pause");
    return 0;

ex0:  
    printf("\nАварийное завершение: оператор ошибся более 5 раз!!!\n");    
    system("pause");
    return 1;
}
