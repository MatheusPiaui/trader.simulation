#include <iostream>

using namespace std;

int menu();
double calculaTaxa(double, double);
double calculaValorBruto(double, double);
double somaTaxas(double,double);
double calculaLucro(double, double);
double lucroFinal(double, double);


main()
{
	menu();
}

int menu()
{
	short int op = -1;

	double valLiquido=0,taxa=0,valBruto=0;
	double valVenda=0,valCompra=0,taxaVenda=0,valTaxaCompra=0,lucro=0;

	while(op != 0)
	{
		cout<<"Escolha uma opcao:"<<endl;
		cout<<"1 - Calcular Taxa de Compra e Valor bruto"<<endl;
		cout<<"2 - Calcular Lucro"<<endl;
		cout<<"0 - Sair"<<endl;
		cin>>op;
		cout<<endl;
		switch(op){
			case 1: 
				cout<<"Digite o Valor Liquido: ";
				cin>>valLiquido;
				cout<<endl;
				cout<<"Digite o Percentual de taxa da Compra %: ";
				cin>>taxa;
				cout<<endl;

				valBruto = calculaValorBruto(valLiquido,taxa);

				cout.precision(8);

				cout<<"Valor Bruto:  "<<fixed<<valBruto<<endl;
				cout<<"Taxa de Compra:  "<<fixed<<calculaTaxa(valBruto,taxa)<<endl;
				cout<<endl<<endl;
				break;
			case 2:
				cout<<"Digite o Valor da Venda: ";
				cin>>valVenda;
				cout<<endl;
				cout<<"Digite o Percentual de taxa da Venda %: ";
				cin>>taxaVenda;
				cout<<endl;
				cout<<"Digite o Valor pago em taxas na compra: ";
				cin>>valTaxaCompra;
				cout<<endl;

				lucro = calculaLucro(valVenda,somaTaxas(valTaxaCompra,calculaTaxa(valVenda,taxaVenda)));

				cout.precision(8);

				cout<<"Lucro:  "<<fixed<<lucro<<endl;
				cout<<endl<<"Digite o Valor da sua compra, para gerar o lucro final: ";
				cin>>valCompra;

				cout<<endl<<"Lucro Final  "<<fixed<<lucroFinal(lucro,valCompra)<<endl;
				cout<<endl<<endl;


		}
	}
	return op;
}


//taxa é o percentual de taxa de compra
//dado em percentual
double calculaValorBruto(double valLiquido, double taxa){
	return valLiquido / (1-(taxa/100));
}

double calculaTaxa(double bruto, double taxa){
	return (taxa/100)*bruto;
}

///////


double somaTaxas(double tCompra,double tVenda){
	return tCompra + tVenda;
}

double calculaLucro(double valVenda, double totalTaxa){
	return valVenda - totalTaxa;
}

double lucroFinal(double lucro, double valCompra){
	return lucro - valCompra;
}


