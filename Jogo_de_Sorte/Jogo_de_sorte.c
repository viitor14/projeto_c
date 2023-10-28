#include <stdio.h>   
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
 //diretiva #define deixa definir uma constante (algo que não muda nunca)

int main(void)
{
  setlocale(LC_ALL, "Portuguese_Brazil");
  srand(time(NULL));
  int continuar=0,modo_de_jogo,chute,pontuacao=0;
  int numero_secreto = rand()%10; int numero_de_tentativas = 5;
  int bonus=0;
do{
    system("cls");
    printf("********************************\n");
    printf("* Bem vindo a Loteria Federal! *\n");
    printf("********************************\n\n");
    printf("Escolha qual modo você quer jogar:\n\n\t1-DIVERSÃO\n\t2-COMPETIVIDADE\n\t3-PERSONALIZADO\n\t4-SAIR\n\t\t");
    scanf("%d",&modo_de_jogo);
    
    switch (modo_de_jogo)
    {
    
    case 1:
    do{
      
      numero_secreto = rand()%11;

      for(int i = 1; i <= numero_de_tentativas; i++){

        printf("\n--- Tentativa %d de %d ---\n", i, numero_de_tentativas);
        printf("Qual é o seu chute?\n");
        scanf("%d", &chute);
        printf("Seu chute foi: %d\n", chute);

        if(chute < 0) {
          printf("Você não pode chutar números negativos!\n");
          i--;

          continue;
        }

        int acertou = (chute == numero_secreto);
        int maior   = (chute > numero_secreto);
      

        if(acertou) {
          printf("\n");
          printf("Parabéns! Você acertou!\n");
          printf("Jogue de novo, você é um bom jogador!\n");
          break;
        } else if(maior) 
        {
          printf("Seu chute foi acima do número secreto!\n");
          printf("\n");
        } else 
        {
          printf("Seu chute foi abaixo do número secreto!\n");
          printf("\n");
        }

        printf("Você errou!\n");
        if(i== numero_de_tentativas)
        {
          printf("O número era: %d\n",numero_secreto);
        }
        printf("Mas não desanime, tente de novo!\n");
      }
    
      printf("Deseja continuar:\n1-SIM\n2-NÂO");
      scanf("%d",&continuar);
      
      printf("\n");
    }while (continuar==1);
    
      printf("Fim de jogo!\n");
      system("pause");
      return 0;
    
    break;//-------------------------------------------------------------FIM DO PRIMEIRO MODO----------------------------------------------------
    
    case 2://-----------------------------------------------------------INICIO DO SEGUNDO MODO-----------------------------------------------------

      do{
        if(continuar==1){system("cls");}
        continuar=0;
        printf("\n\n\t\t---COMPETIVIDADE---\n");
        printf("\nVocê selecionou o modo competitivo e vai duelar contra a máquina.\n");
        printf("No modo competitivo são três fases onde:\n");
        printf("FASE 1 - Você tem 2 chances para acerta o número entre 1 e 5.\n");
        printf("FASE 2 - Você tem 5 chances para acerta o número entre 1 e 10\n");
        printf("FASE 3 - Você tem 7 chances para acerta o número entre 1 e 20\n");
        
        //---------------------------------------------------------------PRIMEIRA FASE------------------------------------------
        
        int chute1 = 0,numero_de_tentativas=0;
        numero_secreto = rand()%6;
        while (numero_secreto==0)
        {
          
          numero_secreto = rand()%6;
        }
        
        
        printf("\n\t\t\t\x1b[31m*FASE 1*\033[0m\n");
        
        for(numero_de_tentativas=1;numero_de_tentativas<=2;numero_de_tentativas++)
        {
          
          printf("\nVamos lá! Dê seu %d chute: ",numero_de_tentativas);
          scanf("%d",&chute1);
          
          if(chute1<0){ //Caso digite um número negativo é convertido para positivo
            if(numero_de_tentativas==1){
              chute1 = -(chute1);
              printf("\nPercebi que você digitou um numero negativo, esse número foi convertido para positvo %d\n",chute1);
              
            }else{
              chute1 = -(chute1);
              printf("\nVixe você tentou novamente chutar um número negativo, esse número foi convertido para positivo %d\n",chute1);
            }
          }else{}
          
          if(chute1==numero_secreto)
          {
          
            if(numero_de_tentativas==1){
              printf("\nParabéns você acertou de primeira.\n");
              printf("Por ter acertado de primeira você ganhou 2 pontos.\n");
              printf("Vamos para a próxima fase.\n\n");
              pontuacao += 2;
              break;            
            }else{

              printf("\nParabéns você acertou\n");
              printf("Você não conseguiu de primeira por isso ganhou somente 1 ponto\n");
              pontuacao ++;
              printf("Vamos para a próxima fase.\n\n");


            }
          }else{
            if(numero_de_tentativas==1){
              printf("\nVocê errou sua 1 tentativa, tente novamente.\n");
            }else{
              printf("Poxa! Que pena que você não conseguiu passar da primeira fase.\n");
              printf("Sua pontuação foi: %d\n",pontuacao);
              printf("O número certo era %d.\n",numero_secreto);
              printf("Quer tentar novamente?\n\t1-SIM\n\t2-NÃO\n\t");
              scanf("%d",&continuar);
              if(continuar!=1){

                system("pause");
                return 0;
              }
             
            }

          }

        }
      }while(continuar==1);
      //--------------------------------------------------------------FIM DA FASE 1----------------------------------------------------------
          if(numero_de_tentativas==1){
            printf("\tSua pontuação até o momento é: %d pontos.\n",pontuacao);
            }else{
              printf("\tSua pontuação até o momento é: %d ponto.\n",pontuacao);
            }
      //--------------------------------------------------------------INICIO DA FASE 2 ------------------------------------------------------
         int chute1 = 0;
        numero_secreto = rand()%11;
        while (numero_secreto==0)
        {
          
          numero_secreto = rand()%11;
        }          
        int dica;
          
          printf("\n\t\t\t\x1b[31m*FASE 2*\033[0m\n\n");
          printf("Ótimo você conseguiu chegar na segunda fase\n");
          printf("Agora suas chances aumentaram para 5 e os números vão de 1 a 10\n");
          printf("ATENÇÃO! A partir de agora pode haver pegadinhas!\n\n");
          printf("Quer dica? (Se usar a dica você perderá 1 ponto)\n\t\t1-SIM\n\t\t2-NÃO\n");
          do{

            scanf("%d",&dica);
            
          }while(dica >= 3);
          
          if(pontuacao>0){
            if(dica==1){
              pontuacao--;
              printf("\nBOA! Você adquiriu dicas para as PRÓXIMAS FASES. SEGUE AS INFOS ABAIXO:\tSUA PONTUAÇÃO FOI ATUALIZADA: %dPONTO\n",pontuacao);
              printf("\n*CASO VOCÊ DÊ UM CHUTE E FOI ERRADO, VAI MOSTRAR SE ESTÁ PERTO, MUITO PERTO OU LONGE DO NÚMERO ESCOLHIDO.\n\t-TÁ PERTO: QUER DIZER QUE A DIFERENÇA DO SEU CHUTE PARA O NÚMERO CERTO FOI ENTRE 1 E 5.");
              printf("\n\t-TÁ LONGE: QUER DIZER QUE A DIFERENÇA FOI MAIS DO QUE 5.\n");
              printf("\t-MUITO PERTO: QUER DIZER QUE A DIFERENÇA DO SEU CHUTE PARA O NÚMERO CORRETO FOI ENTRE 1 E 3\n\n");
            }
          }else{
            printf("\nQUE PENA! Infelizmente você não tem condições de adquirir as dicas.\t\t\t\t\tSUA PONTUAÇÃO É: %d PONTO\n",pontuacao);
          }
          
          for(numero_de_tentativas=1;numero_de_tentativas<=5;numero_de_tentativas ++)
          {
            
            printf("Dê seu %d chute: ",numero_de_tentativas);
            scanf("%d",&chute1);
            
            int diferenca= chute1 - numero_secreto;
            if(diferenca<0){
              diferenca = -(diferenca);}
          
            
            if(chute1<0){        //PEGADINHA
              if(numero_de_tentativas==1){
                printf("\nParabéns você conseguiu cair na pegadinha de primeira.\n");
                printf("Já avisei que números NEGATIVOS NÃO PODEM!\n");
                printf("!\t\t\nXAU!");
                system("pause");
                return 0;

            }else{
                printf("\nParabéns você conseguiu cair na pegadinha\n");
                printf("Já avisei que números NEGATIVOS NÃO PODEM!\n");
                pontuacao --;
                printf("Por causa disso você perdeu 1 ponto.\tSUA PONTUAÇÃO: %d",pontuacao);

            }
          }
            
            if(numero_de_tentativas==1){
              if(chute1==numero_secreto){
                pontuacao+=5;
                printf("\nCaralho, você tem muita sorte. Por causa disso você ganhou 5 pontos.\tSUA PONTUAÇÃO: %d PONTOS\n",pontuacao);
                printf("Boa sorte na última fase!\n\n");
                break;
              }else{
                printf("\nErrrroooou! tente novamente!\n");
                printf("Você ainda tem mais 4 chances\n");
                if(dica==1){
                 if(diferenca >=4 && diferenca<=5){
                  printf("Tá perto\n\n");
                 }else if(diferenca >=1 && diferenca <= 3){
                  printf("MUITO PERTO!\n\n");
                }else{
                  printf("Tá longe\n\n");
                }
              }
              }
            }else if(numero_de_tentativas==2 ||numero_de_tentativas==3){
              if(chute1==numero_secreto){
                pontuacao+=4;
                printf("Excelente você conseguiu acerta na %d tentativa. Por causa disso você ganhou 4 pontos.\nSUA PONTUAÇÃO: %d PONTOS\n",numero_de_tentativas,pontuacao);
                printf("Boa sorte na última fase!\n\n");
                break;
              }else{
                int chances = 5-numero_de_tentativas;
                printf("\nErrrroooou! tente novamente!\n");
                printf("Você ainda tem mais %d chances\n",chances);
                
                if(dica==1){
                  if(diferenca >=4 && diferenca<=5){
                    printf("Tá perto\n\n");
                 }else if(diferenca >=1 && diferenca <= 3){
                  printf("MUITO PERTO!\n\n");
                }else{
                  printf("Tá longe\n\n");
                }
                }
              }

            }else if(numero_de_tentativas==4){
              if(chute1==numero_secreto){
                pontuacao+=3;
                printf("Boa, você acertou na sua 4 tentativa. Por causa disso você ganhou 3 pontos.\nSUA PONTUAÇÃO: %d PONTOS\n",pontuacao);
                break;
              }else{
                int chances = 5 - numero_de_tentativas;
                printf("\nErrrroooou! tente novamente!\n");
                printf("Você ainda tem mais %d chances\n",chances);
                
                if(dica==1){
                  if(diferenca >=4 && diferenca<=5){
                    printf("Tá perto\n\n");
                 }else if(diferenca >=1 && diferenca <= 3){
                  printf("MUITO PERTO!\n\n");
                }else{
                  printf("Tá longe\n\n");
                }
                }
              }
            }else{
              if(chute1==numero_secreto){
                pontuacao+=2;
                printf("Foi na última mas parabéns, você acertou. Por causa disso você ganhou 2 pontos.\tSUA PONTUAÇÃO: %d PONTOS\n\n",pontuacao);
                break;
              }else{
                printf("\nO número certo era %d.\n",numero_secreto);
                printf("Poxa! infelizmente você não conseguiu passar para a 3 fase.Você só conseguiu fazer %d ponto\n",pontuacao);
                system("pause");
                return 0;
              }
            }
          } //--------------------------------------------------------FIM DA SEGUNDA FASE-------------------------------------------------
            //-------------------------------------------------------ÍNICIO DA TERCEIRA FASE----------------------------------------
          chute1=0;
          numero_secreto=rand()%21;
          while(numero_secreto==0){
            numero_secreto=rand()%21;
          }
          
            printf("\n\t\t\t\x1b[31m*FASE 3*\033[0m\n\n");
            printf("Que bom que você conseguiu chegar aqui na terceira fase. Agora ficou mais difícil.\n");
            printf("O número certo agora pode ser de 1 até 20 e você terá somente 7 chances.\n");
            printf("Não se preocupe no final tem um bônus.\n");
            printf("Boa sorte!\n\n");

            for(numero_de_tentativas=1;numero_de_tentativas<=7;numero_de_tentativas++)
            {
            int chances = 7 - numero_de_tentativas;
            printf("Digite seu %d chute: ",numero_de_tentativas);
            scanf("%d",&chute1);

            int diferenca= chute1 - numero_secreto;
            if(diferenca<0){diferenca = -(diferenca);}
     
            if(chute1<0){        //PEGADINHA
              if(numero_de_tentativas==1){
                printf("\nParabéns você conseguiu cair na pegadinha de primeira.\n");
                printf("Já avisei que números NEGATIVOS NÃO PODEM!\n");
                printf("!\t\t\nXAU!");
                system("pause");
                return 0;

            }else{
                printf("\nParabéns você conseguiu cair na pegadinha\n");
                printf("Já avisei que números NEGATIVOS NÃO PODEM!\n");
                pontuacao --;
                printf("Por causa disso você perdeu 1 ponto.\tSUA PONTUAÇÃO: %d",pontuacao);

            }
          }
            
            if(numero_de_tentativas==1){
              if(chute1==numero_secreto){
                pontuacao+=7;
                printf("\nPQP!! Você é muito cagado. Por causa disso você ganhou 7 pontos.\tSUA PONTUAÇÃO: %d PONTOS\n",pontuacao);
                printf("Deseja ir para o bônus?\n\t1-SIM\n\t2-NÃO\n\t");
                scanf("%d",&bonus);
                break;
              }else{
                printf("\nErrrroooou! tente novamente!\n");
                printf("Você ainda tem mais 6 chances\n");
                if(dica==1){
                 if(diferenca >=6 && diferenca<=10){
                  printf("Tá perto\n\n");
                 }else if(diferenca >=1 && diferenca <= 5){
                  printf("MUITO PERTO!\n\n");
                }else{
                  printf("Tá longe\n\n");
                }
              }
              }
            }else if(numero_de_tentativas>=2 && numero_de_tentativas<=4){
              if(chute1==numero_secreto){
                pontuacao+=5;
                printf("Excelente você conseguiu acerta na %d tentativa. Por causa disso você ganhou 5 pontos.\nSUA PONTUAÇÃO: %d PONTOS\n",numero_de_tentativas,pontuacao);
                printf("Deseja ir para o bônus?\n\t1-SIM\n\t2-NÃO\n\t");
                scanf("%d",&bonus);
                break;
              }else{
                
                printf("\nErrrroooou! tente novamente!\n");
                printf("Você ainda tem mais %d chances\n",chances);
                
                if(dica==1){
                  if(diferenca >=6 && diferenca<=10){
                    printf("Tá perto\n\n");
                 }else if(diferenca >=1 && diferenca <= 5){
                  printf("MUITO PERTO!\n\n");
                }else{
                  printf("Tá longe\n\n");
                }
                }
              }

            }else if(numero_de_tentativas >=5 && numero_de_tentativas<=6){
              if(chute1==numero_secreto){
                pontuacao+=4;
                printf("Boa, você acertou na sua %d tentativa. Por causa disso você ganhou 4 pontos.\nSUA PONTUAÇÃO: %d PONTOS\n",numero_de_tentativas, pontuacao);
                printf("Deseja ir para o bônus?\n\t1-SIM\n\t2-NÃO\n\t");
                scanf("%d",&bonus);
                break;
              }else{
                
                printf("\nErrrroooou! tente novamente!\n");
                printf("Você ainda tem mais %d chances\n",chances);
                
                if(dica==1){
                  if(diferenca >=6 && diferenca<=10){
                    printf("Tá perto\n\n");
                 }else if(diferenca >=1 && diferenca <= 5){
                  printf("MUITO PERTO!\n\n");
                }else{
                  printf("Tá longe\n\n");
                }
                }
              }
            }else{
              if(chute1==numero_secreto){
                pontuacao+=3;
                printf("Foi na última mas parabéns, você acertou. Por causa disso você ganhou 3 pontos.\tSUA PONTUAÇÃO: %d PONTOS\n\n",pontuacao);
                printf("Deseja ir para o bônus?\n\t1-SIM\n\t2-NÃO\n\t");
                scanf("%d",&bonus);
                break;
              }else{
                printf("Quase ein! Infelizmente você não conseguiu vencer, mas não se preocupe preparei um bônus para melhorar seus pontos\n");
                bonus=1;
                
              }
            } 
          }
          if(bonus==1){
            printf("\n\nVocê conseguiu chegar na última fase por isso vou lhe presentear com um bônus\n");
            printf("Aqui no bônus, você terá a chance de aumentar seus pontos.\n");
            printf("As opções são de multiplicação ou soma e isso acontecera de forma automatica!.\n");
            printf("Então terá que conta com a sorte kkk!.\n\n");
            printf("Vamos lá para o sorteio?\n");
            system ("pause");

            int sorte, i=0,mult=0,pontuacao_nova=0,sorteio,rodadas=1,sorteia;
            sorte=rand()%11;
            while(sorte>2){
              sorte=rand()%10;
            }
            
            if(sorte==1){
              printf("\n\t\t\x1b[34mMULTIPLICAÇÃO\033[0m\n");
              printf("Olha que coisa boa, sua pontuação vai ser multiplicada.\n");
              printf("Agora irei fazer o sorteio para saber quantas vezes seu número vai ser multiplicado.\n");
              printf("*LEMBRANDO QUE O ULTIMO NÚMERO QUE FOR SORTEADO SERÁ O NÚMERO MULTIPLICADOR E PODE SER ATÉ 10X*\n");
                do{
                  system("pause");
                  for(i=1;i<=10;i++){
                    
                    
                    mult=rand()%11;
                    printf("%dx\n",mult);
                  }
                  sorteia= 3-rodadas;
                  printf("O multiplicador será %d\n",mult);
                  while(rodadas<=3){
                    if(rodadas<3){

                    printf("Você pode sorteia mais %d vezes\n",sorteia);
                    printf("Deseja fazer um novo sorteio?\n\t1-SIM\n\t2-NÃO");
                    scanf("%d",&sorteio);
                    if(sorteio==1){
                        rodadas ++;
                      }else{
                         rodadas +=5;
                        break;
                      }
                    break;
                    }else{
                      sorteio +=5;
                      printf("Você não pode mais sorteia, o número multiplicador será %d.\n",mult);
                      break;

                    }
                     
                  }
                    if(sorteio>1){break;}
                }while(sorteio==1);
              
              pontuacao_nova = mult * pontuacao;
              printf("\nOlha ai, essa é sua nova pontuação: \x1b[32m%d PONTOS\003[0m\n",pontuacao_nova);
              printf("\n\n\t\tOBRIGADO POR PARTICIPAR!!\n");
            
            }else{
              printf("\n\t\t\x1b[34mADIÇÃO\033[0m\n");
              printf("Olha que coisa boa, sua pontuação vai ser adicionada por algum valor.\n");
              printf("Agora irei fazer o sorteio para saber qual valor que será adicionado no seu número.\n");
              printf("*LEMBRANDO QUE O ULTIMO NÚMERO QUE FOR SORTEADO SERÁ O NÚMERO ADICIONADO E PODE SER ATÉ +10*\n");
                do{
                  
                  for(i=1;i<=10;i++){
                    
                    
                    mult=rand()%11;
                    printf("%d+\n",mult);
                  }
                  sorteia= 3-rodadas;
                  printf("O adicional será %d\n",mult);
                  while(rodadas<=3){
                    if(rodadas<3){

                    printf("Você pode sorteia mais %d vezes\n",sorteia);
                    printf("Deseja fazer um novo sorteio?\n\t1-SIM\n\t2-NÃO");
                    scanf("%d",&sorteio);
                    if(sorteio==1){
                        rodadas ++;
                      }else{
                         rodadas +=5;
                        break;
                      }
                    break;
                    }else{
                      sorteio +=5;
                      printf("Você não pode mais sorteia, o número adicionado será %d.\n",mult);
                      break;

                    }
                     
                  }
                    if(sorteio>1){break;}
                }while(sorteio==1);
              
              pontuacao_nova = mult + pontuacao;
              printf("\nOlha ai, essa é sua pontuação final: \x1b[32m%d PONTOS\033[0m\n",pontuacao_nova);
              printf("\n\n\t\tOBRIGADO POR PARTICIPAR!!\n");
            
            }
          }
        system("pause");
        return 0;
      break;//----------------------------------------------------FIM DO SEGUNDO MODO--------------------------------------------------------   
      case 3:
        printf("\n\n\tEM BREVE\n");
        system ("pause");
      break;
      case 4:
      return 0;
      
      default:
      break;
    }
    
   
  }while(1);
}