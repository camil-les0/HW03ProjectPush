#include<iostream>
#include<fstream>
#include<cctype>
#include<cstdlib>

using namespace std;
bool valido(string);
int main (){
	
	ifstream achi;
	achi.open("C:/Users/Usuario/Desktop/aple.txt");
	if(achi.fail()){
		cout << "entradada invalida";
	exit(1);
	}
	
	string lin;
	int i=0,j=0;
	while(getline(achi,lin)){
		if(lin.empty()){
		j++;
		}i++;}
		
	if (i==j){
		cout<<"El archivo esta vacio";
		exit(1);
	}
	achi.close();
	int tam = i-j, k=0;
	string line;
	int bas[tam];
	achi.open("C:/Users/Usuario/Desktop/aple.txt");
	while(getline(achi,line)){
		if (line.empty()){
			continue;
		}
		if(!valido(line)){
			cout<<"la linea no es valida:"<<line<<endl;
			exit(1);
		}else{
			bas[k]= atoi(line.c_str());
		}
		k++;
	}
	
	double suma=0, prom;
	
	for(int l= 0; l<tam;l++){
		suma= bas[l]+suma;
	}
	 prom = suma/tam;
	 int aux;
	 for (int l=0;l<tam-1;l++){
	 	for(int v=l+1; v<tam;v++){
	 		if(bas[l]>bas[v]){
	 			aux = bas[l];
	 			bas[l]= bas[v];
	 			bas[v]=aux;
			 }
		 }
	 }
	string num;
	do{
	cout << "ingrese un numero para buscarlo : "<<endl;
		getline(cin,num);
		if(!valido(num)){
			cout<<"error";
	}
	 }while(!valido(num));
	 
	 	int num1;
	 	num1= atoi(num.c_str());
	 	int encontrado = -1;
	 
	 for (int l=0;l<tam;l++){
	 	if(num1 == bas[l]){
	 		encontrado= l;
	 		break;
		 }
	 }
	 if(encontrado != -1){
	 cout << "El numero se encuentra en la posicion: "<<encontrado<<endl; 
	}else{
		cout<<"El valor buscado no existe"<<endl;
	}
	 
	cout <<" La suma es :"<<suma<<endl;
	 
	cout<<"El promedio es: "<<prom<<endl;
	
	cout<<"El numero mayor es: "<<bas[tam-1]<<endl;
	
	cout <<"El numero menor es: "<< bas[0]<<endl;
	
	cout<<"la cadena resultante es: "<<endl;	
			
	for(int l= 0; l<tam;l++){
		cout <<bas[l]<<"  ";
	} 
	ofstream arch;
	arch.open("Dato.txt");
	arch <<" La suma es :"<<suma<<endl;
	 
	arch<<"El promedio es: "<<prom<<endl;
	
	arch<<"El numero mayor es: "<<bas[tam-1]<<endl;
	
	arch<<"El numero menor es: "<< bas[0]<<endl;
	
	arch<<"la cadena resultante es: "<<endl;
	
		for(int l= 0; l<tam;l++){
		arch <<bas[l]<<"  ";
	} 
	
	arch.close();
	
	return 0;
}
bool valido(string b){
	bool p=false;
	string a;
	int contar = 0;
	for (int t=0; t < b.size(); t++){
	if(isspace(b[t])){
		contar++;
	}else{
		break;
	}
	}
	
	if(contar!=0){
		a=b.substr(contar);
	}else{
		a=b;
	}
	
	if(a.empty()) return p;
	
	if(a[0]=='+'||a[0]=='-'||isdigit(a[0])){
		if((a[0]=='+'||a[0]=='-')&& 1==a.length()){
			p=false;
			return p;
		}
		p=true;
		
		for(int v=1; v<a.length(); v++){

    if(isdigit(a[v])){
    	p=true;
        continue;
    }else if(isspace(a[v])){
        for(int j=v; j<a.length(); j++){
            if(!isspace(a[j])){
                p=false;
                return p;
            }
        }
    }
}
}else 
{
	p=false;
}
return p;
}