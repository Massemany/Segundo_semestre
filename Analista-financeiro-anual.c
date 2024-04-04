#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


struct rendastruct{
    float valor;
    char descricao[100];
    int data;
};

  struct despesatruct{
    float valor;
    char descricao[100];
    int data;
    float saudetotalf,lazertotalf,alimentacaototalf,despesa_fixatotalf,outrostotalf;

};

struct rendastruct renda[12][10];
struct despesatruct despesa[12][100];

int funcaorenda(int mesrenda,int funcaocontrenda);
int funcaomes ();
int funcaodespesa(int mesdespesa,int funcaocontdespesa);


int main(int argc, char *argv[]) {
    FILE * rendafile;
    FILE * despesafile;
    setlocale (LC_ALL,"Portuguese");
    int opcao,mes;
    int contrenda[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    int contdespesa[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
    float saudetotal[12] = {0,0,0,0,0,0,0,0,0,0,0,0},lazertotal[12] = {0,0,0,0,0,0,0,0,0,0,0,0},alimentacaototal[12] = {0,0,0,0,0,0,0,0,0,0,0,0},despesa_fixatotal[12] = {0,0,0,0,0,0,0,0,0,0,0,0},outrostotal[12] = {0,0,0,0,0,0,0,0,0,0,0,0};

    do {

        do{
                //Menu
            printf("\n M E N U\n");

            printf("\n 1 - Cadastro\n 2 - Relatório\n 3 - Encerrar\n");
            printf("Digite a opcao: ");
            scanf("%i",&opcao);
            fflush(stdin);

            if (opcao > 3 || opcao < 1){
               printf("Erro , digite novamente\n\n");
            }

        }while(opcao > 3 || opcao < 1);

        if (opcao == 1){

          do{
                    //Mes
                printf("\nQual mês deseja acessar: ");
                mes = funcaomes();

          }while(mes < 1 ||mes > 12);

          mes--;

            int incluirOUexcluir;

            do {
                        //Incluir ou excluir
                printf("\nDigite:\n 1 para excluir\n 2 para Incluir\nDigite a opção desejadada: ");
                scanf("%i",&incluirOUexcluir);
                fflush(stdin);

                if (incluirOUexcluir > 2 || incluirOUexcluir < 1){
                    printf("\n\nVocê só pode digitar 1 [Excluir] ou 2 [Incluir]\n\n");
                }

            }while(incluirOUexcluir > 2 || incluirOUexcluir < 1);

            int opcao2;

            if (incluirOUexcluir == 1){
                        //excluir
                int excluir,contexcluir;

                do {

                    printf("\n\nVocê só pode digitar 1 [Excluir renda] ou 2 [Excluir despesa]:");
                    scanf("%i",&excluir);
                    fflush(stdin);

                    if (excluir > 2 || excluir < 1){
                         printf("\n\nVocê só pode digitar 1 [Excluir renda] ou 2 [Excluir despesa]\n\n");
                    }

                }while(excluir > 2 || excluir < 1);

            if (excluir == 1){
                        //excluir renda
                for (contexcluir = 0;contexcluir < contrenda[mes];contexcluir++){
                    renda[mes][contexcluir].valor = 0;
                    renda[mes][contexcluir].data = 0;
                    strcpy(renda[mes][contexcluir].descricao,"");
                }

                contrenda[mes] = 0;

            }else if (excluir == 2){
                        //excluir despesa
                for (contexcluir = 0;contexcluir < contdespesa[mes];contexcluir++){
                    despesa[mes][contexcluir].valor = 0;
                    despesa[mes][contexcluir].data = 0;
                    strcpy(despesa[mes][contexcluir].descricao,"");

                }

                saudetotal[mes] = 0;
                lazertotal[mes] = 0;
                alimentacaototal[mes] = 0;
                despesa_fixatotal[mes] = 0;
                outrostotal[mes] = 0;
                contdespesa[mes] = 0;

            }
            printf("\n\nMês %i Excluido\n\n",mes+1);

            }else if (incluirOUexcluir == 2){

            do {
                //incluir
                printf("\nDigite:\n 1 para cadastrar renda\n 2 para cadastrar despesa\n");
                printf("Digite a opcão: ");
                scanf("%i",&opcao2);
                fflush(stdin);

                if (opcao2 > 2 || opcao2 < 1){
                        printf("\n\nVocê só pode digitar 1 [Cadastrar renda] ou 2 [Cadastrar despesa]\n\n");
                    }

            }while(opcao2 >  2 || opcao2 < 1);

                if (opcao2 == 1){
                        // incluir renda
                    printf("\n[Somente, no máximo, 10 rendas por cada mês]\n");

                   contrenda[mes] = funcaorenda(mes,contrenda[mes]);

                }else if (opcao2 == 2){
                            //incluir despesa
                    printf("\n[Somente, no máximo, 100 despesas por cada mês]\n");

                    contdespesa[mes] = funcaodespesa(mes,contdespesa[mes]);
                    int testecont;
                    for(testecont = 0;testecont < contdespesa[mes];testecont++){
                        saudetotal[mes] += despesa[mes][testecont].saudetotalf;
                        lazertotal[mes] += despesa[mes][testecont].lazertotalf;
                        alimentacaototal[mes] += despesa[mes][testecont].alimentacaototalf;
                        despesa_fixatotal[mes] += despesa[mes][testecont].despesa_fixatotalf;
                        outrostotal[mes] += despesa[mes][testecont].outrostotalf;
                    }
                }
            }

        }else if (opcao == 2){

           int contrelatorio,relatorio,relatorioanual;
           float rendamensal[12],rendamaior[12];
           float despesamensal[12],despesamaior[12];
           float saldomensal[12];

           printf("\n\nDigite 1 para ver relatório mensal\nDigite 2 para ver o relatório anual\nDigite a opção desejada :");
           scanf("%i",&relatorioanual);
            fflush(stdin);

           if(relatorioanual == 1){

            do{
               printf("\nDigite:\n 1 para Renda \n 2 para Despesa\n 3 para Saldo\nDigite a opção: ");
               scanf("%i",&relatorio);
               fflush(stdin);
               if (relatorio < 0 || relatorio > 3){
                printf("\n\nErro por favor digite novamente\n\n");
               }
            }while(relatorio < 0 || relatorio > 3);

            do{
               printf("\n\nDigite o mês que deseja consultar: ");
               mes = funcaomes();
               }while(mes < 1 || mes > 12);
               mes--;

               if (relatorio == 1){

                    rendamensal[mes] = 0;
                    rendamaior[mes] = renda[mes][0].valor;

                    for (contrelatorio = 0;contrelatorio < contrenda[mes];contrelatorio++){
                        printf(" Valor da %iª renda: R$%.2f pago no dia %i por/pela %s\n",contrelatorio+1,renda[mes][contrelatorio].valor,renda[mes][contrelatorio].data,renda[mes][contrelatorio].descricao);

                        rendamensal[mes] += renda[mes][contrelatorio].valor;

                        if (renda[mes][contrelatorio].valor > rendamaior[mes]){
                             rendamaior[mes] = renda[mes][contrelatorio].valor;
                        }

                    }

                    printf(" Valor total da renda desse mês: R$%.2f\n",rendamensal[mes]);
                    printf(" Maior renda desse mês: R$%.2f",rendamaior[mes]);

               }else if (relatorio == 2){

                    despesamensal[mes] = 0;
                    despesamaior[mes] = despesa[mes][0].valor;

                    for (contrelatorio = 0;contrelatorio < contdespesa[mes];contrelatorio++){
                        printf(" Valor da %iª despesa: R$%.2f gerado no dia %i por/pela %s\n",contrelatorio+1,despesa[mes][contrelatorio].valor,despesa[mes][contrelatorio].data,despesa[mes][contrelatorio].descricao);

                        despesamensal[mes] += despesa[mes][contrelatorio].valor;

                        if (despesa[mes][contrelatorio].valor > despesamaior[mes]){
                                despesamaior[mes] = despesa[mes][contrelatorio].valor;
                        }

                    }

                    printf("\n valor total da despesa desse mês: R$%.2f",despesamensal[mes]);
                    printf("\n Maior despesa desse mês: R$%.2f",despesamaior[mes]);
                    printf("\n O tipo Saúde teve um valor total de R$%.2f",saudetotal[mes]);
                    printf("\n O tipo Lazer teve um valor total de R$%.2f",lazertotal[mes]);
                    printf("\n O tipo Despesa fixa teve um valor total de R$%.2f",despesa_fixatotal[mes]);
                    printf("\n O tipo Alimentação teve um valor total de R$%.2f",alimentacaototal[mes]);
                    printf("\n O tipo Outros(imprevistos) teve um valor total de R$%.2f\n",outrostotal[mes]);

               }else if (relatorio == 3){
                   saldomensal[mes] = 0;
                    for (contrelatorio = 0;contrelatorio < contrenda[mes];contrelatorio++){
                             saldomensal[mes] += renda[mes][contrelatorio].valor;
                    }
                    for (contrelatorio = 0;contrelatorio < contdespesa[mes];contrelatorio++){
                            saldomensal[mes] -= despesa[mes][contrelatorio].valor;

                    }
                    printf("--------------------------------------------\n");
                    printf("O saldo do mês %i era R$%.2f",mes+1,saldomensal[mes]);
                    printf("\n------------------------------------------");
               }


            }else if (relatorioanual == 2){
                int contdespesaAnual[12],contrendaAnual[12],mediarenda=0,mediadespesa=0;
                float despesaAnual,rendaAnual,saldofinal;
                float mediatotalrenda,mediatotaldespesa;
                float saudefinal,lazerfinal,despesa_fixafinal,outrosfinal,alimentacaofinal;
                rendafile = fopen("Renda.txt","w");
                despesafile = fopen("Despesa.txt","w");
                mediarenda = 0;
                for (mes = 0;mes < 12;mes++){


                    saudefinal += saudetotal[mes];
                    lazerfinal += lazertotal[mes];
                    alimentacaofinal+= alimentacaototal[mes];
                    despesa_fixafinal += despesa_fixatotal[mes];
                    outrosfinal += outrostotal[mes];

                    fprintf(rendafile,"Mês %i\n",mes+1);
                    fprintf(despesafile,"Mês %i\n",mes+1);

                    for (contrendaAnual[mes] = 0;contrendaAnual[mes] < contrenda[mes];contrendaAnual[mes]++){

                        fprintf(rendafile,"%iª Renda:%.2f Data:%i Discrição:%s\n",contrendaAnual[mes]+1,renda[mes][contrendaAnual[mes]].valor,renda[mes][contrendaAnual[mes]].data,renda[mes][contrendaAnual[mes]].descricao);

                        rendaAnual += renda[mes][contrendaAnual[mes]].valor;
                        mediarenda++;
                    }


                    for (contdespesaAnual[mes]= 0;contdespesaAnual[mes] < contdespesa[mes];contdespesaAnual[mes]++){
                            fprintf(despesafile,"%iª Despesa:%.2f Data:%i Discrição:%s\n",contdespesaAnual[mes]+1,despesa[mes][contdespesaAnual[mes]].valor,despesa[mes][contdespesaAnual[mes]].data,despesa[mes][contdespesaAnual[mes]].descricao);
                            despesaAnual += despesa[mes][contdespesaAnual[mes]].valor;
                            mediadespesa++;

                    }

                }
                fclose(rendafile);
                fclose(despesafile);
                float maiortipo = 0;
                char stipo[20];

                if (saudefinal > maiortipo){
                    maiortipo = saudefinal;
                    strcpy(stipo,"Saúde");
                }
                if (lazerfinal > maiortipo){
                    maiortipo = lazerfinal;
                    strcpy(stipo,"Lazer");
                }
                if(alimentacaofinal > maiortipo){
                    alimentacaofinal += maiortipo;
                    strcpy(stipo,"Alimentação");
                }
                if (despesa_fixafinal > maiortipo){
                    maiortipo = despesa_fixafinal;
                    strcpy(stipo,"Despesa Fixa");
                }
                if (outrosfinal > maiortipo){
                    maiortipo = outrosfinal;
                    strcpy(stipo,"Outros(Imprevisto)");
                }

                saldofinal = rendaAnual - despesaAnual;
                mediatotaldespesa = despesaAnual/mediadespesa;
                mediatotalrenda = rendaAnual/mediarenda;

                printf("\nTotal da renda anual: R$%.2f\n",rendaAnual);
                printf("Total da despesa anual: R$%.2f\n",despesaAnual);
                printf("Média das despesas: R$%.2f\n",mediatotaldespesa);
                printf("Média das rendas: R$%.2f\n",mediatotalrenda);
                printf("Saldo final: R$%.2f\n",saldofinal);
                printf("O tipo [%s] teve o valor mais alto entre todos, que é de R$%.2f\n",stipo,maiortipo);
                printf("[Porcentagem dos tipos de despesas]:\n");
                printf("Saúde: %%%.2f\n",saudefinal/despesaAnual*100);
                printf("Alimentação: %%%.2f\n",alimentacaofinal/despesaAnual*100);
                printf("Lazer: %%%.2f\n",lazerfinal/despesaAnual*100);
                printf("Despesa fixa: %%%.2f\n",despesa_fixafinal/despesaAnual*100);
                printf("Outros: %%%.2f\n",outrosfinal/despesaAnual*100);

                rendaAnual = 0;
                despesaAnual = 0;
                saudefinal = 0;
                lazerfinal = 0;
                alimentacaofinal = 0;
                despesa_fixafinal =0;
                outrosfinal = 0;
                maiortipo = 0;
                mediarenda = 0;
                mediadespesa = 0;




            }

        }
    }while(opcao != 3);

     if(opcao==3){
         printf("\nAgradecemos a execução!\n\nPROJETO DEa: Antônio Jorge, Marcela Assemany, Vinicius Antônio e David Mendes.");
     }

    return 0;
}

//funcao renda
int funcaorenda(int mesrenda,int funcaocontrenda){
    int funcaotestewhile;

     do{

        if (funcaocontrenda < 10){
            printf("\nDigite:\n Sua renda: ");
            scanf("%f",&renda[mesrenda][funcaocontrenda].valor);
            fflush(stdin);

            if (renda[mesrenda][funcaocontrenda].valor > 0){

                do{
                    printf(" O dia do recebimento:");
                    scanf("%i",&renda[mesrenda][funcaocontrenda].data);
                    fflush(stdin);

                    if (renda[mesrenda][funcaocontrenda].data > 31 || renda[mesrenda][funcaocontrenda].data < 1){
                        printf("\n\nO dia não pode ser maior que 31 ou menor que 1\n\n");
                    }

                }while(renda[mesrenda][funcaocontrenda].data > 31 || renda[mesrenda][funcaocontrenda].data < 1);

                printf(" A descrição da renda: ");
                fflush(stdin);
                gets(renda[mesrenda][funcaocontrenda].descricao);

                funcaocontrenda++;

                funcaotestewhile = 1;

            } else {
                renda[mesrenda][funcaocontrenda].valor = 0;
                funcaotestewhile = 0;

            }
        }else {
            funcaotestewhile = 0;
            printf("\n\nVocê só pode digitar no máximo 10 rendas por mês\n\n");
        }
    }while(funcaotestewhile == 1);
    return funcaocontrenda;

}
//funcao mes
int funcaomes (){
    int pedirmes;

                scanf("%i",&pedirmes);
                fflush(stdin);
                if (pedirmes < 1 || pedirmes > 12){
                    printf("\nVoce digitou um mês inválido, tente novamente\n");
                }

            return pedirmes;
}
// funcao despesa
int funcaodespesa(int mesdespesa,int funcaocontdespesa){
    int funcaotestewhile;
    int tipo;
      do{

                        if (funcaocontdespesa < 100 ){
                                        //incluir despesa
                            printf("\nDigite:\n O valor da despesa: ");
                            scanf("%f",&despesa[mesdespesa][funcaocontdespesa].valor);
                            fflush(stdin);

                            if (despesa[mesdespesa][funcaocontdespesa].valor > 0){
                                funcaotestewhile = 1;

                                do{

                                    printf("\n 1 - Saúde\n 2 - Lazer\n 3 - alimentação\n 4 - despesa fixa\n 5 - Outros(emprevistos)\nDigite o tipo da despesa: ");
                                    scanf("%i",&tipo);
                                    fflush(stdin);


                                    switch (tipo){
                                        case 1:
                                            despesa[mesdespesa][funcaocontdespesa].saudetotalf += despesa[mesdespesa][funcaocontdespesa].valor;
                                            break;

                                        case 2:
                                            despesa[mesdespesa][funcaocontdespesa].lazertotalf += despesa[mesdespesa][funcaocontdespesa].valor;
                                            break;

                                        case 3:

                                            despesa[mesdespesa][funcaocontdespesa].alimentacaototalf += despesa[mesdespesa][funcaocontdespesa].valor;
                                            break;

                                        case 4:
                                            despesa[mesdespesa][funcaocontdespesa].despesa_fixatotalf += despesa[mesdespesa][funcaocontdespesa].valor;
                                            break;

                                        case 5:
                                            despesa[mesdespesa][funcaocontdespesa].outrostotalf += despesa[mesdespesa][funcaocontdespesa].valor;
                                            break;

                                        default:
                                            printf("\nVocê digitou um número inválido, por favor tente novamente\n\n");

                                    }

                                }while(tipo < 1 || tipo > 5);

                                do {

                                    printf("\n Digite o dia do pagamento: ");
                                    scanf("%i",&despesa[mesdespesa][funcaocontdespesa].data);
                                    fflush(stdin);

                                    if (despesa[mesdespesa][funcaocontdespesa].data > 31 || despesa[mesdespesa][funcaocontdespesa].data < 1){
                                        printf("\n\n[O dia não pode ser maior que 31 ou menor que 1, tente novamente.]\n\n");

                                    }

                                }while(despesa[mesdespesa][funcaocontdespesa].data > 31 || despesa[mesdespesa][funcaocontdespesa].data < 1);

                                fflush(stdin);
                                printf(" A descrição dessa despesa: ");
                                gets(despesa[mesdespesa][funcaocontdespesa].descricao);

                                funcaocontdespesa++;

                            }else {
                                funcaotestewhile = 0;
                                despesa[mesdespesa][funcaocontdespesa].valor = 0;

                            }

                        }else{
                                funcaotestewhile = 0;
                                printf("\n\nVocê só pode digitar no máximo 100 despesas por mês\n\n");
                            }
                }while(funcaotestewhile == 1);
                return funcaocontdespesa;
}
