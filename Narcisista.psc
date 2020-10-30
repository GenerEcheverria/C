Algoritmo NumeroNarcisista
	Definir suma, F, F2, digEntrada, contDig, N, X, potencia, V, aux como Entero;
	suma<-0;
	digEntrada<-0;
	contDig<-0;
	aux<-0;
	Escribir "Escribe un numero entero";
	Leer N;
	digEntrada<-N;
	Mientras N<>0 Hacer
		contdig<-contdig+1;
		aux<-N%10;
		N<-((N-aux)/10);
	Fin Mientras
	N<-digEntrada; 
	Dimension V(contDig); 
	Para F<-1 Hasta contDig Con Paso 1 Hacer
		V(F)<-N%10;
		N<-((N-V(F))/10);
	Fin Para
	
	X<-contDig;
	Para F<-1 Hasta contDig Con Paso 1 Hacer
		potencia<-1;
		Para F2<-1 Hasta X Con Paso 1 Hacer
			potencia<-potencia*V(F);
		Fin Para
		suma<-suma+potencia;
	Fin Para
	Si digEntrada=suma Entonces
		Escribir digEntrada " es narcisista";
	SiNo
		Escribir digEntrada " no es narcisista";
	FinSi
FinAlgoritmo
