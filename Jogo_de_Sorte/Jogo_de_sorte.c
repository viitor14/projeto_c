#include <stdio.h>   
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <windows.h>
 //diretiva #define deixa definir uma constante (algo que n�o muda nunca)

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
    printf("Escolha qual modo voc� quer jogar:\n\n\t1-DIVERS�O\n\t2-COMPETIVIDADE\n\t3-PERSONALIZADO\n\t4-SAIR\n\t\t");
    scanf("%d",&modo_de_jogo);
    
    switch (modo_de_jogo)
    {
    
    case 1:
    do{
      
      numero_secreto = rand()%11;

      for(int i = 1; i <= numero_de_tentativas; i++){

        printf("\n--- Tentativa %d de %d ---\n", i, numero_de_tentativas);
        printf("Qual � o seu chute?\n");
        scanf("%d", &chute);
        printf("Seu chute foi: %d\n", chute);

        if(chute < 0) {
          printf("Voc� n�o pode chutar n�meros negativos!\n");
          i--;

          continue;
        }

        int acertou = (chute == numero_secreto);
        int maior   = (chute > numero_secreto);
      

        if(acertou) {
          printf("\n");
          printf("Parab�ns! Voc� acertou!\n");
          printf("Jogue de novo, voc� � um bom jogador!\n");
          break;
        } else if(maior) 
        {
          printf("Seu chute foi acima do n�mero secreto!\n");
          printf("\n");
        } else 
        {
          printf("Seu chute foi abaixo do n�mero secreto!\n");
          printf("\n");
        }

        printf("Voc� errou!\n");
        if(i== numero_de_tentativas)
        {
          printf("O n�mero era: %d\n",numero_secreto);
        }
        printf("Mas n�o desanime, tente de novo!\n");
      }
    
      printf("Deseja continuar:\n1-SIM\n2-N�O");
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
        printf("\nVoc� selecionou o modo competitivo e vai duelar contra a m�quina.\n");
        printf("No modo competitivo s�o tr�s fases onde:\n");
        printf("FASE 1 - Voc� tem 2 chances para acerta o n�mero entre 1 e 5.\n");
        printf("FASE 2 - Voc� tem 5 chances para acerta o n�mero entre 1 e 10\n");
        printf("FASE 3 - Voc� tem 7 chances para acerta o n�mero entre 1 e 20\n");
        
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
          
          printf("\nVamos l�! D� seu %d chute: ",numero_de_tentativas);
          scanf("%d",&chute1);
          
          if(chute1<0){ //Caso digite um n�mero negativo � convertido para positivo
            if(numero_de_tentativas==1){
              chute1 = -(chute1);
              printf("\nPercebi que voc� digitou um numero negativo, esse n�mero foi convertido para positvo %d\n",chute1);
              
            }else{
              chute1 = -(chute1);
              printf("\nVixe voc� tentou novamente chutar um n�mero negativo, esse n�mero foi convertido para positivo %d\n",chute1);
            }
          }else{}
          
          if(chute1==numero_secreto)
          {
          
            if(numero_de_tentativas==1){
              printf("\nParab�ns voc� acertou de primeira.\n");
              printf("Por ter acertado de primeira voc� ganhou 2 pontos.\n");
              printf("Vamos para a pr�xima fase.\n\n");
              pontuacao += 2;
              break;            
            }else{

              printf("\nParab�ns voc� acertou\n");
              printf("Voc� n�o conseguiu de primeira por isso ganhou somente 1 ponto\n");
              pontuacao ++;
              printf("Vamos para a pr�xima fase.\n\n");


            }
          }else{
            if(numero_de_tentativas==1){
              printf("\nVoc� errou sua 1 tentativa, tente novamente.\n");
            }else{
              printf("Poxa! Que pena que voc� n�o conseguiu passar da primeira fase.\n");
              printf("Sua pontua��o foi: %d\n",pontuacao);
              printf("O n�mero certo era %d.\n",numero_secreto);
              printf("Quer tentar novamente?\n\t1-SIM\n\t2-N�O\n\t");
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
            printf("\tSua pontua��o at� o momento �: %d pontos.\n",pontuacao);
            }else{
              printf("\tSua pontua��o at� o momento �: %d ponto.\n",pontuacao);
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
          printf("�timo voc� conseguiu chegar na segunda fase\n");
          printf("Agora suas chances aumentaram para 5 e os n�meros v�o de 1 a 10\n");
          printf("ATEN��O! A partir de agora pode haver pegadinhas!\n\n");
          printf("Quer dica? (Se usar a dica voc� perder� 1 ponto)\n\t\t1-SIM\n\t\t2-N�O\n");
          do{

            scanf("%d",&dica);
            
          }while(dica >= 3);
          
          if(pontuacao>0){
            if(dica==1){
              pontuacao--;
              printf("\nBOA! Voc� adquiriu dicas para as PR�XIMAS FASES. SEGUE AS INFOS ABAIXO:\tSUA PONTUA��O FOI ATUALIZADA: %dPONTO\n",pontuacao);
              printf("\n*CASO VOC� D� UM CHUTE E FOI ERRADO, VAI MOSTRAR SE EST� PERTO, MUITO PERTO OU LONGE DO N�MERO ESCOLHIDO.\n\t-T� PERTO: QUER DIZER QUE A DIFEREN�A DO SEU CHUTE PARA O N�MERO CERTO FOI ENTRE 1 E 5.");
              printf("\n\t-T� LONGE: QUER DIZER QUE A DIFEREN�A FOI MAIS DO QUE 5.\n");
              printf("\t-MUITO PERTO: QUER DIZER QUE A DIFEREN�A DO SEU CHUTE PARA O N�MERO CORRETO FOI ENTRE 1 E 3\n\n");
            }
          }else{
            printf("\nQUE PENA! Infelizmente voc� n�o tem condi��es de adquirir as dicas.\t\t\t\t\tSUA PONTUA��O �: %d PONTO\n",pontuacao);
          }
          
          for(numero_de_tentativas=1;numero_de_tentativas<=5;numero_de_tentativas ++)
          {
            
            printf("D� seu %d chute: ",numero_de_tentativas);
            scanf("%d",&chute1);
            
            int diferenca= chute1 - numero_secreto;
            if(diferenca<0){
              diferenca = -(diferenca);}
          
            
            if(chute1<0){        //PEGADINHA
              if(numero_de_tentativas==1){
                printf("\nParab�ns voc� conseguiu cair na pegadinha de primeira.\n");
                printf("J� avisei que n�meros NEGATIVOS N�O PODEM!\n");
                printf("!\t\t\nXAU!");
                system("pause");
                return 0;

            }else{
                printf("\nParab�ns voc� conseguiu cair na pegadinha\n");
                printf("J� avisei que n�meros NEGATIVOS N�O PODEM!\n");
                pontuacao --;
                printf("Por causa disso voc� perdeu 1 ponto.\tSUA PONTUA��O: %d",pontuacao);

            }
          }
            
            if(numero_de_tentativas==1){
              if(chute1==numero_secreto){
                pontuacao+=5;
                printf("\nCaralho, voc� tem muita sorte. Por causa disso voc� ganhou 5 pontos.\tSUA PONTUA��O: %d PONTOS\n",pontuacao);
                printf("Boa sorte na �ltima fase!\n\n");
                break;
              }else{
                printf("\nErrrroooou! tente novamente!\n");
                printf("Voc� ainda tem mais 4 chances\n");
                if(dica==1){
                 if(diferenca >=4 && diferenca<=5){
                  printf("T� perto\n\n");
                 }else if(diferenca >=1 && diferenca <= 3){
                  printf("MUITO PERTO!\n\n");
                }else{
                  printf("T� longe\n\n");
                }
              }
              }
            }else if(numero_de_tentativas==2 ||numero_de_tentativas==3){
              if(chute1==numero_secreto){
                pontuacao+=4;
                printf("Excelente voc� conseguiu acerta na %d tentativa. Por causa disso voc� ganhou 4 pontos.\nSUA PONTUA��O: %d PONTOS\n",numero_de_tentativas,pontuacao);
                printf("Boa sorte na �ltima fase!\n\n");
                break;
              }else{
                int chances = 5-numero_de_tentativas;
                printf("\nErrrroooou! tente novamente!\n");
                printf("Voc� ainda tem mais %d chances\n",chances);
                
                if(dica==1){
                  if(diferenca >=4 && diferenca<=5){
                    printf("T� perto\n\n");
                 }else if(diferenca >=1 && diferenca <= 3){
                  printf("MUITO PERTO!\n\n");
                }else{
                  printf("T� longe\n\n");
                }
                }
              }

            }else if(numero_de_tentativas==4){
              if(chute1==numero_secreto){
                pontuacao+=3;
                printf("Boa, voc� acertou na sua 4 tentativa. Por causa disso voc� ganhou 3 pontos.\nSUA PONTUA��O: %d PONTOS\n",pontuacao);
                break;
              }else{
                int chances = 5 - numero_de_tentativas;
                printf("\nErrrroooou! tente novamente!\n");
                printf("Voc� ainda tem mais %d chances\n",chances);
                
                if(dica==1){
                  if(diferenca >=4 && diferenca<=5){
                    printf("T� perto\n\n");
                 }else if(diferenca >=1 && diferenca <= 3){
                  printf("MUITO PERTO!\n\n");
                }else{
                  printf("T� longe\n\n");
                }
                }
              }
            }else{
              if(chute1==numero_secreto){
                pontuacao+=2;
                printf("Foi na �ltima mas parab�ns, voc� acertou. Por causa disso voc� ganhou 2 pontos.\tSUA PONTUA��O: %d PONTOS\n\n",pontuacao);
                break;
              }else{
                printf("\nO n�mero certo era %d.\n",numero_secreto);
                printf("Poxa! infelizmente voc� n�o conseguiu passar para a 3 fase.Voc� s� conseguiu fazer %d ponto\n",pontuacao);
                system("pause");
                return 0;
              }
            }
          } //--------------------------------------------------------FIM DA SEGUNDA FASE-------------------------------------------------
            //-------------------------------------------------------�NICIO DA TERCEIRA FASE----------------------------------------
          chute1=0;
          numero_secreto=rand()%21;
          while(numero_secreto==0){
            numero_secreto=rand()%21;
          }
          
            printf("\n\t\t\t\x1b[31m*FASE 3*\033[0m\n\n");
            printf("Que bom que voc� conseguiu chegar aqui na terceira fase. Agora ficou mais dif�cil.\n");
            printf("O n�mero certo agora pode ser de 1 at� 20 e voc� ter� somente 7 chances.\n");
            printf("N�o se preocupe no final tem um b�nus.\n");
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
                printf("\nParab�ns voc� conseguiu cair na pegadinha de primeira.\n");
                printf("J� avisei que n�meros NEGATIVOS N�O PODEM!\n");
                printf("!\t\t\nXAU!");
                system("pause");
                return 0;

            }else{
                printf("\nParab�ns voc� conseguiu cair na pegadinha\n");
                printf("J� avisei que n�meros NEGATIVOS N�O PODEM!\n");
                pontuacao --;
                printf("Por causa disso voc� perdeu 1 ponto.\tSUA PONTUA��O: %d",pontuacao);

            }
          }
            
            if(numero_de_tentativas==1){
              if(chute1==numero_secreto){
                pontuacao+=7;
                printf("\nPQP!! Voc� � muito cagado. Por causa disso voc� ganhou 7 pontos.\tSUA PONTUA��O: %d PONTOS\n",pontuacao);
                printf("Deseja ir para o b�nus?\n\t1-SIM\n\t2-N�O\n\t");
                scanf("%d",&bonus);
                break;
              }else{
                printf("\nErrrroooou! tente novamente!\n");
                printf("Voc� ainda tem mais 6 chances\n");
                if(dica==1){
                 if(diferenca >=6 && diferenca<=10){
                  printf("T� perto\n\n");
                 }else if(diferenca >=1 && diferenca <= 5){
                  printf("MUITO PERTO!\n\n");
                }else{
                  printf("T� longe\n\n");
                }
              }
              }
            }else if(numero_de_tentativas>=2 && numero_de_tentativas<=4){
              if(chute1==numero_secreto){
                pontuacao+=5;
                printf("Excelente voc� conseguiu acerta na %d tentativa. Por causa disso voc� ganhou 5 pontos.\nSUA PONTUA��O: %d PONTOS\n",numero_de_tentativas,pontuacao);
                printf("Deseja ir para o b�nus?\n\t1-SIM\n\t2-N�O\n\t");
                scanf("%d",&bonus);
                break;
              }else{
                
                printf("\nErrrroooou! tente novamente!\n");
                printf("Voc� ainda tem mais %d chances\n",chances);
                
                if(dica==1){
                  if(diferenca >=6 && diferenca<=10){
                    printf("T� perto\n\n");
                 }else if(diferenca >=1 && diferenca <= 5){
                  printf("MUITO PERTO!\n\n");
                }else{
                  printf("T� longe\n\n");
                }
                }
              }

            }else if(numero_de_tentativas >=5 && numero_de_tentativas<=6){
              if(chute1==numero_secreto){
                pontuacao+=4;
                printf("Boa, voc� acertou na sua %d tentativa. Por causa disso voc� ganhou 4 pontos.\nSUA PONTUA��O: %d PONTOS\n",numero_de_tentativas, pontuacao);
                printf("Deseja ir para o b�nus?\n\t1-SIM\n\t2-N�O\n\t");
                scanf("%d",&bonus);
                break;
              }else{
                
                printf("\nErrrroooou! tente novamente!\n");
                printf("Voc� ainda tem mais %d chances\n",chances);
                
                if(dica==1){
                  if(diferenca >=6 && diferenca<=10){
                    printf("T� perto\n\n");
                 }else if(diferenca >=1 && diferenca <= 5){
                  printf("MUITO PERTO!\n\n");
                }else{
                  printf("T� longe\n\n");
                }
                }
              }
            }else{
              if(chute1==numero_secreto){
                pontuacao+=3;
                printf("Foi na �ltima mas parab�ns, voc� acertou. Por causa disso voc� ganhou 3 pontos.\tSUA PONTUA��O: %d PONTOS\n\n",pontuacao);
                printf("Deseja ir para o b�nus?\n\t1-SIM\n\t2-N�O\n\t");
                scanf("%d",&bonus);
                break;
              }else{
                printf("Quase ein! Infelizmente voc� n�o conseguiu vencer, mas n�o se preocupe preparei um b�nus para melhorar seus pontos\n");
                bonus=1;
                
              }
            } 
          }
          if(bonus==1){
            printf("\n\nVoc� conseguiu chegar na �ltima fase por isso vou lhe presentear com um b�nus\n");
            printf("Aqui no b�nus, voc� ter� a chance de aumentar seus pontos.\n");
            printf("As op��es s�o de multiplica��o ou soma e isso acontecera de forma automatica!.\n");
            printf("Ent�o ter� que conta com a sorte kkk!.\n\n");
            printf("Vamos l� para o sorteio?\n");
            system ("pause");

            int sorte, i=0,mult=0,pontuacao_nova=0,sorteio,rodadas=1,sorteia;
            sorte=rand()%11;
            while(sorte>2){
              sorte=rand()%10;
            }
            
            if(sorte==1){
              printf("\n\t\t\x1b[34mMULTIPLICA��O\033[0m\n");
              printf("Olha que coisa boa, sua pontua��o vai ser multiplicada.\n");
              printf("Agora irei fazer o sorteio para saber quantas vezes seu n�mero vai ser multiplicado.\n");
              printf("*LEMBRANDO QUE O ULTIMO N�MERO QUE FOR SORTEADO SER� O N�MERO MULTIPLICADOR E PODE SER AT� 10X*\n");
                do{
                  system("pause");
                  for(i=1;i<=10;i++){
                    
                    
                    mult=rand()%11;
                    printf("%dx\n",mult);
                  }
                  sorteia= 3-rodadas;
                  printf("O multiplicador ser� %d\n",mult);
                  while(rodadas<=3){
                    if(rodadas<3){

                    printf("Voc� pode sorteia mais %d vezes\n",sorteia);
                    printf("Deseja fazer um novo sorteio?\n\t1-SIM\n\t2-N�O");
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
                      printf("Voc� n�o pode mais sorteia, o n�mero multiplicador ser� %d.\n",mult);
                      break;

                    }
                     
                  }
                    if(sorteio>1){break;}
                }while(sorteio==1);
              
              pontuacao_nova = mult * pontuacao;
              printf("\nOlha ai, essa � sua nova pontua��o: \x1b[32m%d PONTOS\003[0m\n",pontuacao_nova);
              printf("\n\n\t\tOBRIGADO POR PARTICIPAR!!\n");
            
            }else{
              printf("\n\t\t\x1b[34mADI��O\033[0m\n");
              printf("Olha que coisa boa, sua pontua��o vai ser adicionada por algum valor.\n");
              printf("Agora irei fazer o sorteio para saber qual valor que ser� adicionado no seu n�mero.\n");
              printf("*LEMBRANDO QUE O ULTIMO N�MERO QUE FOR SORTEADO SER� O N�MERO ADICIONADO E PODE SER AT� +10*\n");
                do{
                  
                  for(i=1;i<=10;i++){
                    
                    
                    mult=rand()%11;
                    printf("%d+\n",mult);
                  }
                  sorteia= 3-rodadas;
                  printf("O adicional ser� %d\n",mult);
                  while(rodadas<=3){
                    if(rodadas<3){

                    printf("Voc� pode sorteia mais %d vezes\n",sorteia);
                    printf("Deseja fazer um novo sorteio?\n\t1-SIM\n\t2-N�O");
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
                      printf("Voc� n�o pode mais sorteia, o n�mero adicionado ser� %d.\n",mult);
                      break;

                    }
                     
                  }
                    if(sorteio>1){break;}
                }while(sorteio==1);
              
              pontuacao_nova = mult + pontuacao;
              printf("\nOlha ai, essa � sua pontua��o final: \x1b[32m%d PONTOS\033[0m\n",pontuacao_nova);
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