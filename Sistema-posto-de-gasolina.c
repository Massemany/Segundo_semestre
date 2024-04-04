#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


float calculo_pagamento (char escolha[10], int litros, float alc, float gaso, float total_arrecadado){
	float valor, pag, desconto;
	float contalc=0, contgaso=0;
	float alcpag, gasopag, maior_valor;
	
	
	if(litros>20){
		
		if(strcmp(escolha, "gasolina")==0||strcmp(escolha, "Gasolina")==0 || strcmp(escolha, "GASOLINA")==0){	// 0 em C é o equivalente a dizer q é verdadeiro e sem erros.
				valor = litros * gaso;
				desconto = gaso - (0.06 * gaso);
				pag = litros * desconto;
					return (pag);
			};
		if(strcmp(escolha, "alcool")==0 || strcmp(escolha, "Alcool")==0 || strcmp(escolha, "ALCOOL")==0){	//funcao strcmp da biblioteca serviu pra comparar se oq ta na variavel escolha é igual a "alcool" ou o outro.
				valor = litros * alc;
				desconto = alc - (0.05 * alc);
				pag = litros * desconto;
					return (pag);
		};
		}else{		//caso seja menor que 20 os litros abastecidos
		if(strcmp(escolha, "gasolina")==0||strcmp(escolha, "Gasolina")==0 || strcmp(escolha, "GASOLINA")==0){
				valor = litros * gaso;
				desconto = gaso - (0.04 * gaso);
				pag = litros * desconto;
					return (pag);
		};
		if(strcmp(escolha, "alcool")==0|| strcmp(escolha, "Alcool")==0 || strcmp(escolha, "ALCOOL")==0){
			valor = litros * alc;
			desconto = alc - (0.03 * alc);
			pag = litros * desconto;
				return (pag);
		};
	};
		
};



int main(int argc, char *argv[]) {
	float alc=0, gaso=0, desconto=0, valor=0, pag;	
	int litros=0, cont,quantidadelitros;
	float gasopag, total_arrecadado, alcpag;	//pagamentos individuais e total
	float contgaso=0, contalc=0, totalcont=0;		//contagem dos tipos
	float mediagaso=0;		//media no relatorio
	float calculopercent;	//percentual relatorio
	int porcentagem;		//percentual relatorio
	float maior_valor=0;	
	float medialitros;	//media de litros
	char escolha[10] = {0,0,0,0,0,0,0,0,0,0};	//string
	float quantveiculos;
	int litrogasolina[30],litroalcool[30],contlitroalcool=0,contlitrogasolina=0,acimaDaMedia=0;

	//pergunta do preco da gasolina
	printf("Ola! primeiramente, qual o valor atual da Gasolina e do Alcool?\n");
	scanf("%f", &gaso);
	scanf("%f", &alc);
	
	
	
	do{
		printf("\n-------------------------------------------------------------\nPara encerrar a operacao, digite 'f' no pedido da litragem\n------------------------------------------------------------\n");
		
	//pergunta do tipo escolhido 
	printf("\nQual o tipo desejado? [gasolina ou alcool]\n");
	fflush(stdin);
	gets(escolha);
	
	//pergunta do quanto em litros quer abastecer
	printf("Quantos litros deseja abastecer de %s?\n", escolha);
	scanf("%d", &litros);
	quantidadelitros += litros;
	//printf("%f de al e %f de gaso, %s com %f\n\n", alcool, gasolina, escolha, litros);		//TESTE, OBS: colocar .2 para diminuir as respostas ja que sao float.
	//analisando escolha do abastecimento final e comparando com qual e como foi escrito o tipo
	
	pag = calculo_pagamento(escolha, litros, alc, gaso, total_arrecadado);
	printf("\nO preco total, com desconto, ficou R$%.2f\n", pag);
	
	total_arrecadado += pag;	//soma dos pagamentos para valor total
	
	if(strcmp(escolha, "gasolina")==0 ||strcmp(escolha, "Gasolina")==0|| strcmp(escolha, "GASOLINA")==0){
		contgaso = contgaso +1;	//para calcular a media da gasolina
		
		gasopag += pag;	//para calcular a media da gasolina
		
	}
	
	if(strcmp(escolha, "alcool")==0	|| strcmp(escolha, "Alcool")==0 || strcmp(escolha, "ALCOOL")==0){
		contalc = contalc + 1;
		
		alcpag += pag;
		
	}	
		
		if(pag>maior_valor){
			maior_valor = pag;
		}
		
		
	if(strcmp(escolha, "gasolina")==0 || strcmp(escolha, "Gasolina")==0|| strcmp(escolha, "GASOLINA")==0){	//contabilizar a quantidade de veiculos blablabla, peguei tudo de toinho
		 litrogasolina[contlitrogasolina] = quantidadelitros;
                contlitrogasolina++;

	}else{
		 litroalcool[contlitroalcool] = quantidadelitros;
                contlitroalcool++;

	}	
		
			
	}while(strcmp(escolha,"f")!=0); 	//encerra no proximo comando, mas pelo menos encerra, so colocar 0.

	//Media do valor da gasolina
	mediagaso = gasopag / contgaso;
	
	//contagem do total de operacoes de abastecimento, para o calculo do percentual de alcool.
	totalcont = contgaso + contalc;
	//percentual de vendas do alcool
	calculopercent = contalc / totalcont;
	porcentagem = calculopercent * 100;
	
	//relatorio
	printf("\nR E L A T O R I O\n");
	
	printf("\nTotal arrecadado no dia:	R$%.2f\n", total_arrecadado);
	
	printf("Media geral de gasolina:	R$%.2f\n", mediagaso);
	
	printf("Percentagem da venda de alcool:	%d%% \n", porcentagem);	//ta dando erro
	
	//o tipo que vendeu menos
	if(contgaso < contalc){
		printf("O tipo que vendeu menos:	Gasolina\n");
	}else{
		printf("O tipo que vendeu menos:	Alcool\n");
	}
	
	//maior valor
	printf("Maior valor pago:		%.2f\n", maior_valor);
	
	//media de litros
	medialitros = quantidadelitros / totalcont;
	printf("Quantidade media de litros vendidos por abastecimento:	%.2f\n", medialitros);
	
	//veiculos q abasteceram acima da media de litros.
	for(cont=0;cont < contlitroalcool;cont++){
        if(litroalcool[cont] > medialitros){
            acimaDaMedia++;
        }
    }

    for(cont=0;cont < contlitrogasolina;cont++){
        if(litrogasolina[cont] > medialitros){
            acimaDaMedia++;
        }
    }

    printf("O numero de veiculos que abasteceram com quantidade de litros acima da media:	%i\n",acimaDaMedia);

	
	return 0;
}


