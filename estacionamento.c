#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {

    setlocale (LC_ALL,"Portuguese");
	float horas=0,min1=0,min2=0,hrsai=-1,minsai=-1,segsai=-1,hrcheg=-1,mincheg=-1,segcheg=-1,per;// Variavel De tempo
	float pagamento=0,pagvalor=0; //Variavel de Valor e pagamento
	int tipveiculo=0,codveiculo=-100000; // Variavel do veiculo
	int dia,opcao,valor=0;// variavel do dia e contador
	float total_are=0,total_dev=0,total_diferenca=0;// valor total arrecadado a diferença e o que deveria ter sido arrecadado
	float tot_CAR_pequeno_dev=0,tot_Car_grade_Dev=0,tot_Moto_dev=0;//valor que deveria ser arrecadado por tipo de veiculo
	float tot_CAR_pequeno_are=0,tot_Car_grade_are=0,tot_Moto_are=0;// valor total que foi arrecadado por tipo de veiculo
	int codigo_carrogrande=0,cont=0,contdif=0,cont_quantidade_acima=0,cont_menor_carro_pequeno=0,cont_carro_pequeno=0,conthora=0;//os contadores e o codigo do carro grande
	float menor_car_grande=0;//variavel pra saber se esse foi o menor pagamento do carro grande
	float carro_pequeno_porcentagem=0;// variavel do ´percentual de carro pequeno com menor valor
	int contrelatorio =0;
	float total_mes_moto=0,total_mes_carropequeno=0,total_mes_carrogrande=0;

     printf("<<< Código desenvolvido por :Antonio Jorge, David Mendes, Marcela Assemany e Vinicius Antonio Reis>>>\n\n");
	do{

	printf("\n1 - Registra Movimento");
	printf("\n2 - Gerar Relatório");
	printf("\n3 - Encerrar");

    do {
        opcao = 0;
        fflush(stdin);
        printf("\nSelecione uma das Opções : ");
        scanf("%i",&opcao);
        if (opcao == 1){
            contrelatorio = 1;
        }
        if (opcao > 3 || opcao <= 0){
            printf("\nVocê digitou um valor invalido por favor digite [1] ou [2] ou [3]\n");
        }

    }while (opcao > 3 || opcao <= 0);


        if (opcao == 1){

            for (dia=1;dia <=30;dia++){
                printf("Dia %i\n",dia);

                do{

                    do {
                        tipveiculo = 0;
                        fflush(stdin);
                        printf("Voce esta de [MOTO]1 [CARRO PEQUENO]2 [CARRO GRANDE]3 : ");
                        scanf("%i",&tipveiculo);
                        if (tipveiculo > 3 || tipveiculo <= 0){
                            printf("\nVocê digitou um valor invalido por favor digite [1] ou [2] ou [3]\n\n");
                        }
                    }while (tipveiculo > 3 || tipveiculo <=0);
                    do{
                        codveiculo = -100000;

                        fflush(stdin);
                        printf("Codigo do veiculo : ");
                        scanf("%i",&codveiculo);

                        if(codveiculo == -100000){
                            printf("\nO Codigo atual é invalido \n\n");
                        }

                        }while(codveiculo == -100000 );

                    if (codveiculo != -1){
                        do {

                            hrsai = -1;
                            printf("hora da chegada\n");
                            fflush(stdin);
                            printf("digite a hora da chegada : ");
                            scanf("%f",&hrsai);

                            minsai = -1;
                            fflush(stdin);
                            printf("digite os minutos da chegada : ");
                            scanf("%f",&minsai);

                            segsai = -1;
                            fflush(stdin);
                            printf("digite os segundos da chegada : ");
                            scanf("%f",&segsai);

                            hrcheg = -1;
                            fflush(stdin);
                            printf("\nhora da saida\n");
                            printf("digite a hora da saida : ");
                            scanf("%f",&hrcheg);

                            mincheg = -1;
                            fflush(stdin);
                            printf("digite os minutos da saida : ");
                            scanf("%f",&mincheg);

                            segcheg = -1;
                            fflush(stdin);
                            printf("digite os segundos da saida : ");
                            scanf("%f",&segcheg);




                            min1=(hrsai*60)+ minsai + (segsai/60);
                            min2=(hrcheg*60) + mincheg+ (segcheg/60);
                            per=min2-min1;
                            horas=per/60;

                        if (hrcheg <= 24 && mincheg <= 60 && segcheg <= 60 &&hrcheg >= 0 && mincheg >= 0 && segcheg >=0 &&hrsai <= 24 && minsai <= 60 && segsai <= 60 && hrsai >= 0 && minsai >= 0 && segsai >=0 && min1 <= 1440 && min2 <= 1440 && horas >= 0 ){

                            conthora = 1;
                        }else {
                            if (horas < 0){
                                printf("\nA hora da Chegado precisa ser maior que a da saida\n");
                            }
                            printf("\nVocê digitou um valor incorreto por favor tente novamente\n\n");
                            conthora =0;
                        }
                        }while (conthora == 0);


                        if (tipveiculo == 1){

                            if (horas >= 0 && horas <= 0.5){
                                pagvalor = 0;
                            }else if (horas >0.5 && horas <=1){
                                pagvalor = 1*4;
                            }else if (horas > 1 &&horas <= 2){
                                pagvalor = 1*2.50 + 1*4;
                            }else if (horas > 2 && horas <= 3 ){
                                pagvalor = 2*2.50 + 1*4;
                            }else if (horas > 3 && horas <= 4){
                                    pagvalor = 3*2.50 + 1*4;
                            }else if (horas > 4 && horas <= 5){
                                    pagvalor = 4*2.50 + 1*4;
                            }else if (horas > 5 && horas <= 6){
                                    pagvalor = 5*2.50 + 1*4;
                            }else if (horas > 6 && horas <= 7){
                                    pagvalor = 6*2.50 + 1*4;
                            }else if (horas > 7 && horas <= 8){
                                    pagvalor = 7*2.50 + 1*4;
                            }else if (horas > 8 && horas <= 9){
                                    pagvalor = 8*2.50 + 1*4;
                            }else if (horas > 9 && horas <= 10){
                                    pagvalor = 9*2.50 + 1*4;
                            }else if (horas > 10 && horas <= 11){
                                    pagvalor = 10*2.50 + 1*4;
                            }else if (horas > 11 && horas <= 12){
                                    pagvalor = 11*2.50 + 1*4;
                            }else if (horas > 12 && horas <= 13){
                                    pagvalor = 12*2.50 + 1*4;
                            }else if (horas > 13 && horas <= 14){
                                    pagvalor = 13*2.50 + 1*4;
                            }else if (horas > 14 && horas <= 15){
                                    pagvalor = 14*2.50 + 1*4;
                            }else if (horas > 15 && horas <= 16){
                                    pagvalor = 15*2.50 + 1*4;
                            }else if (horas > 16 && horas <= 17){
                                    pagvalor = 16*2.50 + 1*4;
                            }else if (horas > 17 && horas <= 18){
                                    pagvalor = 17*2.50 + 1*4;
                            }else if (horas > 18 && horas <= 19){
                                    pagvalor = 18*2.50 + 1*4;
                            }else if (horas > 19 && horas <= 20){
                                    pagvalor = 19*2.50 + 1*4;
                            }else if (horas > 20 && horas <= 21){
                                    pagvalor = 20*2.50 + 1*4;
                            }else if (horas > 21 && horas <= 22){
                                    pagvalor = 21*2.50 + 1*4;
                            }else if (horas > 22 && horas <= 23){
                                    pagvalor = 22*2.50 + 1*4;
                            }else if (horas > 23 && horas <= 24){
                                    pagvalor = 23*2.50 + 1*4;
                            }

                        }else if (tipveiculo == 2){

                            if (horas >= 0 && horas <= 0.5){
                                pagvalor = 0;
                            }else if (horas >0.5 && horas <=1){
                                pagvalor = 1*5.50;
                            }else if (horas > 1 && horas <= 2){
                                pagvalor = 1*4 + 1*5.50;
                            }else if (horas > 2 && horas <= 3 ){
                                pagvalor = 2*4 + 1*5.50;
                            }else if (horas > 3 && horas <= 4 ){
                                pagvalor = 3*4 + 1*5.50;
                            }else if (horas > 4 && horas <= 5 ){
                                pagvalor = 4*4 + 1*5.50;
                            }else if (horas > 5 && horas <= 6 ){
                                pagvalor = 5*4 + 1*5.50;
                            }else if (horas > 6 && horas <= 7 ){
                                pagvalor = 6*4 + 1*5.50;
                            }else if (horas > 7 && horas <= 8 ){
                                pagvalor = 7*4 + 1*5.50;
                            }else if (horas > 8 && horas <= 9 ){
                                pagvalor = 8*4 + 1*5.50;
                            }else if (horas > 9 && horas <= 10 ){
                                pagvalor = 9*4 + 1*5.50;
                            }else if (horas > 10 && horas <= 11 ){
                                pagvalor = 10*4 + 1*5.50;
                            }else if (horas > 11 && horas <= 12 ){
                                pagvalor = 11*4 + 1*5.50;
                            }else if (horas > 12 && horas <= 13 ){
                                pagvalor = 12*4 + 1*5.50;
                            }else if (horas > 13 && horas <= 14 ){
                                pagvalor = 13*4 + 1*5.50;
                            }else if (horas > 14 && horas <= 15 ){
                                pagvalor = 14*4 + 1*5.50;
                            }else if (horas > 15 && horas <= 16 ){
                                pagvalor = 15*4 + 1*5.50;
                            }else if (horas > 16 && horas <= 17 ){
                                pagvalor = 16*4 + 1*5.50;
                            }else if (horas > 17 && horas <= 18 ){
                                pagvalor = 17*4 + 1*5.50;
                            }else if (horas > 18 && horas <= 19 ){
                                pagvalor = 18*4 + 1*5.50;
                            }else if (horas > 19 && horas <= 20 ){
                                pagvalor = 19*4 + 1*5.50;
                            }else if (horas > 20 && horas <= 21 ){
                                pagvalor = 20*4 + 1*5.50;
                            }else if (horas > 21 && horas <= 22 ){
                                pagvalor = 21*4 + 1*5.50;
                            }else if (horas > 22 && horas <= 23 ){
                                pagvalor = 22*4 + 1*5.50;
                            }else if (horas > 23 && horas <= 24 ){
                                pagvalor = 23*4 + 1*5.50;
                            }

                        }else if (tipveiculo == 3) {

                            if (horas >= 0 && horas <= 0.5){
                                pagvalor = 0;
                            }else if (horas >0.5 && horas <=1){
                                pagvalor = 1*7.50;
                            }else if (horas > 1 && horas <= 2){
                                pagvalor = 1*5.50 + 1*7.50;
                            }else if (horas > 2 && horas <= 3 ){
                                pagvalor = 2*5.50 + 1*7.50;
                            }else if (horas > 3 && horas <= 4 ){
                                pagvalor = 3*5.50 + 1*7.50;
                            }else if (horas > 4 && horas <= 5 ){
                                pagvalor = 4*5.50 + 1*7.50;
                            }else if (horas > 5 && horas <= 6 ){
                                pagvalor = 5*5.50 + 1*7.50;
                            }else if (horas > 6 && horas <= 7 ){
                                pagvalor = 6*5.50 + 1*7.50;
                            }else if (horas > 7 && horas <= 8 ){
                                pagvalor = 7*5.50 + 1*7.50;
                            }else if (horas > 8 && horas <= 9 ){
                                pagvalor = 8*5.50 + 1*7.50;
                            }else if (horas > 9 && horas <= 10 ){
                                pagvalor = 9*5.50 + 1*7.50;
                            }else if (horas > 10 && horas <= 11 ){
                                pagvalor = 10*5.50 + 1*7.50;
                            }else if (horas > 11 && horas <= 12 ){
                                pagvalor = 11*5.50 + 1*7.50;
                            }else if (horas > 12 && horas <= 12 ){
                                pagvalor = 12*5.50 + 1*7.50;
                            }else if (horas > 13 && horas <= 14 ){
                                pagvalor = 13*5.50 + 1*7.50;
                            }else if (horas > 14 && horas <= 15 ){
                                pagvalor = 14*5.50 + 1*7.50;
                            }else if (horas > 15 && horas <= 16 ){
                                pagvalor = 15*5.50 + 1*7.50;
                            }else if (horas > 16 && horas <= 17 ){
                                pagvalor = 16*5.50 + 1*7.50;
                            }else if (horas > 17 && horas <= 18 ){
                                pagvalor = 17*5.50 + 1*7.50;
                            }else if (horas > 18 && horas <= 19 ){
                                pagvalor = 18*5.50 + 1*7.50;
                            }else if (horas > 19 && horas <= 20 ){
                                pagvalor = 19*5.50 + 1*7.50;
                            }else if (horas > 20 && horas <= 21 ){
                                pagvalor = 20*5.50 + 1*7.50;
                            }else if (horas > 21 && horas <= 22 ){
                                pagvalor = 21*5.50 + 1*7.50;
                            }else if (horas > 22 && horas <= 23 ){
                                pagvalor = 22*5.50 + 1*7.50;
                            }else if (horas > 23 && horas <= 24 ){
                                pagvalor = 23*5.50 + 1*7.50;
                            }

                        }

                        printf("\nO valor que voce precisa pagar é de R$%.2f ",pagvalor);
                        do {
                            pagamento = -1;
                            fflush(stdin);
                            printf("\nDigite o valor do pagamento R$ ");
                            scanf("%f",&pagamento);
                            if (pagamento < 0){
                                printf("\nO pagamento não pode ser negativo ou uma letra \n");
                            }
                        } while (pagamento < 0);

                        if(pagamento > pagvalor){
                            cont_quantidade_acima++;
                        }

                        if (tipveiculo == 1){
                            tot_Moto_dev += pagvalor;
                            tot_Moto_are += pagamento;
                        }else if (tipveiculo == 2){
                            cont_carro_pequeno++;
                            tot_CAR_pequeno_are += pagamento;
                            tot_CAR_pequeno_dev += pagvalor;
                            if (pagamento < pagvalor){
                                cont_menor_carro_pequeno++;
                            }
                        }else if (tipveiculo == 3){
                            tot_Car_grade_are += pagamento;
                            tot_Car_grade_Dev += pagvalor;
                             if (cont == 0){
                                menor_car_grande = pagamento;
                                codigo_carrogrande = codveiculo;
                                cont++;
                             }
                             if (pagamento < menor_car_grande) {
                                menor_car_grande = pagamento;
                                codigo_carrogrande = codveiculo;
                            }
                        }

                        total_are += pagamento;
                        total_dev += pagvalor;
                        contdif++;


                        if (pagamento > pagvalor){
                            printf("Você pagou R$%.2f a mais\n",pagamento-pagvalor);
                        }else if (pagamento < pagvalor){
                            printf("Você  pagou R$%.2f a menos\n",(pagamento-pagvalor)*-1);
                        }else{
                            printf("Você pagou o valor certo\n");
                        }

                    }
                }while (codveiculo != -1);
                printf("\n\nO valor total arrecado foi de R$%.2f\n",total_are);

                printf("O valor total da moto que deveria ser arrecadado R$%.2f\n",tot_Moto_dev);
                printf("O valor total do carro pequeno que deveria ser arrecadado  R$%.2f\n",tot_CAR_pequeno_dev);
                printf("O valor total do carro grande que deveria ser arrecadado  R$%.2f\n\n",tot_Car_grade_Dev);

                float total_M = tot_Moto_are-tot_Moto_dev,total_Cp =tot_CAR_pequeno_are-tot_CAR_pequeno_dev ,Total_Cg = tot_Car_grade_are-tot_Car_grade_Dev;

                if (total_M >= 0){
                printf("A diferença do valor arrecadado R$%.2f \ne do valor pago R$%.2f \ndas moto foi de R$%.2f não houve prejuizo para a empresa\n\n",tot_Moto_dev,tot_Moto_are,total_M);
                }else{
                printf("A diferença do valor arrecadado R$%.2f \ne do valor pago R$%.2f \ndas moto foi de R$%.2f houve prejuizo para a empresa\n\n",tot_Moto_dev,tot_Moto_are,total_M);
                }

                if (total_Cp >= 0){
                    printf("A diferença do valor arrecadado R$%.2f \ne do valor pago R$%.2f \ndos carro pequeno foi de R$%.2f não houve prejuizo para a empresa\n\n",tot_CAR_pequeno_dev,tot_CAR_pequeno_are,total_Cp);
                }else {
                     printf("A diferença do valor arrecadado R$%.2f \ne do valor pago R$%.2f\ndos carro pequeno foi de R$%.2f  houve prejuizo para a empresa\n\n",tot_CAR_pequeno_dev,tot_CAR_pequeno_are,total_Cp);
                }

                if (Total_Cg >= 0){
                     printf("A diferença do valor arrecadado R$%.2f \ne do valor pago R$%.2f \ndos carro grande  foi de R$%.2f não houve prejuizo para a empresa\n\n",tot_Car_grade_Dev,tot_Car_grade_are,Total_Cg);
                }else {
                    printf("A diferença do valor arrecadado R$%.2f \ne do valor pago R$%.2f \ndos carro grande  foi de R$%.2f  houve prejuizo para a empresa\n\n",tot_Car_grade_Dev,tot_Car_grade_are,Total_Cg);
                }

                //Resetando variaves
                if (total_dev > total_are){
                total_diferenca += total_dev - total_are;
                }else {
                total_diferenca += total_are - total_dev;
                }
                total_mes_moto += tot_Moto_are;
                total_mes_carropequeno += tot_CAR_pequeno_are;
                total_mes_carrogrande += tot_Car_grade_are;
                total_M =0;
                Total_Cg =0;
                total_Cp =0;
                tot_Moto_dev =0;
                tot_Moto_are =0;
                tot_CAR_pequeno_are =0;
                tot_CAR_pequeno_dev =0;
                tot_Car_grade_are =0;
                tot_Car_grade_Dev =0;
                total_are = 0;
                pagamento =0;

            }
        }else if (opcao == 2){
            if (contrelatorio == 0){
                printf("\nPrimeiro registre o movimento antes de gerar o relatoiro\n");
            }else {
                int media_dif = total_diferenca/contdif;
                carro_pequeno_porcentagem = (float)cont_menor_carro_pequeno/cont_carro_pequeno*100;
                printf("O valor total das moto arrecadado no mes foi de R$%.2f\n",total_mes_moto);
                printf("O valor total dos carro pequeno arrecadado no mes foi de R$%.2f\n",total_mes_carropequeno);
                printf("O valor total dos carro grande arrecadado no mes foi de R$%.2f\n",total_mes_carrogrande);
                printf("A Média da diferença no valor das cobranças realizadas foi de R$%.2f\n",media_dif);
                printf("O codigo do veiculo com o menor valor pago entre os carro grande foi %i\n",codigo_carrogrande);
                printf("Percentual de CARROS PEQUENOS com valor cobrado abaixo do valor correto foi de %.0f%%\n",carro_pequeno_porcentagem);
                printf("Quantidade de cobranças feitas com valor pago maior do que o valor correto foi de %i",cont_quantidade_acima);
            }
        }

	}while (opcao < 3);
	printf("\n\nFim!");
	return 0;

}
