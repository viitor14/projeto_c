#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>
#include <unistd.h>
#define numero_ctt 100

typedef struct
{
    char email[50], nome[50], ddd[50],numero[11];
    long int contato;
} lista;

void adicionarnome(lista *adicionar)
{
    while (getchar() != '\n')
        ; // retirar o espaço vazio que é deixado pelo scanf, para poder ultilizar o fgets

    fgets(adicionar->nome, sizeof(adicionar->nome), stdin);
    for (int i = 0; adicionar->nome[i] != '\0'; i++)
    {
        if (adicionar->nome[i] == '\n')
        {
            adicionar->nome[i] = '\0';
            break;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Portuguese,Brazil");
    lista lista_de_contato[numero_ctt];
    int novo_contato, mudancas_aovivo;
    int escolher_contato, i,verificar_digito;
    char opcao;

    FILE *arquivo;

    arquivo = fopen("contato.txt", "r");
    i = 1;
    if (arquivo != NULL)
    {
        fscanf(arquivo, "Numero de contatos %d", &novo_contato);
        do
        {
            fscanf(arquivo, "%s", lista_de_contato[i].nome);
            fscanf(arquivo, "%s", lista_de_contato[i].email);
            fscanf(arquivo, "%s %s", lista_de_contato[i].ddd, lista_de_contato[i].numero);
            i++;
        } while (i <= novo_contato);

        fclose(arquivo);
    }
    else
    {
        novo_contato = 0;
    }
    for (i = 0; i <= 50; i++)
            {
                for (mudancas_aovivo = 0; mudancas_aovivo <= 50; mudancas_aovivo++)
                    if (lista_de_contato[mudancas_aovivo].nome[i] == '_')
                    {
                        lista_de_contato[mudancas_aovivo].nome[i] = ' ';
                    }
            }

    mudancas_aovivo = 0;
    do
    {
        opcao = '0';
        system("cls");
        printf("\tLista telefonica!\n\n");
        printf("\t\x1b[34m1-LISTA TELEFONICA (%d)\n", novo_contato);
        printf("\t2-ADICIONAR CONTATO\n");
        printf("\t3-EDITAR CONTATO\n");
        printf("\t4-EXCLUIR CONTATO\n");
        printf("\t5-SALVAR E SAIR!\033[0m\n\t");
        scanf(" %c", &opcao);

        switch (opcao)
        {
        case '1':
            for (i = 0; i <= 50; i++)
            {
                for (mudancas_aovivo = 0; mudancas_aovivo <= 50; mudancas_aovivo++)
                    if (lista_de_contato[mudancas_aovivo].nome[i] == '_')
                    {
                        lista_de_contato[mudancas_aovivo].nome[i] = ' ';
                    }
            }

            printf("\n\t\x1b[31mLISTA TELEFONICA\033[0m\n\n");

            if (novo_contato == 0)
            {
                printf("SEM CONTATO\n");
                system("pause");
                break;
            }
            do
            {

                printf("\n\t1-Ver todos seus contatos.\n\t2-Buscar contato.\n\t");
                scanf(" %c", &opcao);
                while (getchar() != '\n')
                    ; // retirar o espaço que o scanf deixa
                while (opcao != '1' && opcao != '2')
                {
                    printf("\033[1A\033[K"); // Vai voltar 1 linha e vai apagar o que tinha nela 1A é a linha e K apaga
                    scanf(" %c", &opcao);
                    while (getchar() != '\n')
                        ;
                }

                if (opcao == '1')
                {

                    for (i = 1; i <= novo_contato; i++)
                    {
                        printf("\nNome: %s\n", lista_de_contato[i].nome);
                        printf("Email: %s\n", lista_de_contato[i].email);
                        printf("Numero:(%s)%s\n", lista_de_contato[i].ddd, lista_de_contato[i].numero);
                    }
                    
                }
                else
                {
                    opcao = '\0';
                    printf("\n\t\x1b[32mBuscar contato.\033[0m\n");
                    printf("Escolhar como quer fazer a busca:\n\t1-Nome\n\t2-Email\n\t3-Numero\n\t0-Voltar\n\t");
                    scanf(" %c", &opcao);
                    while (getchar() != '\n'); // retirar o espaço que o scanf deixa
                    while (opcao != '0' && opcao != '1' && opcao != '2' && opcao != '3')
                    {
                        printf("\033[1A\033[K"); // Vai voltar 1 linha e vai apagar o que tinha nela 1A é a linha e K apaga
                        scanf(" %c", &opcao);
                        while (getchar() != '\n')
                            ;
                    }

                    if (opcao == '0')
                    {
                        printf("\033[12A"); // Move o cursor 2 linhas para cima
                        printf("\033[0J");
                    }
                    else if (opcao == '1')
                    {
                        printf("EM BREVE");
                    }
                    else if (opcao == '2')
                    {
                        printf("EM BREVE");
                    }
                    else if (opcao == '3')
                    {
                        printf("EM BREVE");
                    }
                }

            } while (opcao == '0');
            system("pause");
            break;

        case '2':
            printf("\n\n\t\x1b[31mADICIONAR CONTATO\033[0m\n");
            mudancas_aovivo++;
            novo_contato++;
            lista_de_contato[novo_contato].contato = novo_contato;

            printf("Nome: ");
            adicionarnome(&lista_de_contato[novo_contato]);
            printf("\033[sEmail: ");
            scanf("%s", lista_de_contato[novo_contato].email);
            printf("\033[sDDD: ");
            do
            {   
                verificar_digito=1;
                scanf("%s", lista_de_contato[novo_contato].ddd);
                while (getchar() != '\n');
            
                for (i = 0; lista_de_contato[novo_contato].ddd[i] != '\0'; i++) 
                {
                    if (!isdigit(lista_de_contato[novo_contato].ddd[i]))
                    {
                    verificar_digito = 0;  // Encontrou um caractere que não é um dígito33332222333w
                   
                    printf("\x1b[31mDDD invalido, digite novamente (ex:xxx)\033[0m");
                    sleep(4);
                    printf("\033[u");
                    printf("\033[0J");
                    printf("DDD: ");
                    break;  // Não é necessário continuar verificando
                    }   
                }
            } while (verificar_digito==0);
            printf("\033[sNumero: ");
            do
            {   
                verificar_digito=1;
                scanf("%s", lista_de_contato[novo_contato].numero);
                while (getchar() != '\n');
            
                for (i = 0; i < 9; i++) 
                {
                    if (!isdigit(lista_de_contato[novo_contato].numero[i]))
                    {
                    verificar_digito = 0;  // Encontrou um caractere que não é um dígito
                    
                    printf("\x1b[31mNúmero inválido, digite novamente (ex:xxxxxxxxx)\033[0m");
                    sleep(4);
                    printf("\033[u");
                    printf("\033[0J");
                    printf("Numero: ");
                    break;  // Não é necessário continuar verificando
                    }   
                }
            } while (verificar_digito==0);
            break;

        case '3':
            printf("\n\n\t\x1b[31mEDITAR CONTATO\033[0m\n");
            if (novo_contato == 0)
            {
                printf("VOCE NAO TEM CONTATO PARA EDITAR\n");
                system("pause");
                break;
            }
            for (i = 1; i <= novo_contato; i++)
            {
                printf("\x1b[31m#%d\033[0m\n", i);
                printf("Nome: %s\n", lista_de_contato[i].nome);
                printf("Email: %s\n", lista_de_contato[i].email);
                printf("Numero: (%s)%s\n\n", lista_de_contato[i].ddd, lista_de_contato[i].numero);
            }
            printf("\n\033[sEscolha qual contato voce quer editar pelo numero indentificador do contato representado por # ou 0 para voltar: ");
            do
            {
                scanf("%d", &escolher_contato);
                while (getchar() != '\n');
                
                if (escolher_contato < 0 || escolher_contato > novo_contato)
                {
                    printf("\x1b[31mContato inexistente!\033[0m ");
                    sleep(1);
                    printf("\033[u");//volta p linha 228 onde tem um "checkpoint" \033[s
                    printf("\033[0J");//limpa a tela ate onde esta no cursor
                    printf("Escolha qual contato voce quer editar pelo numero indentificador do contato representado por # ou 0 para voltar: ");
                }
            } while (escolher_contato < 0 || escolher_contato > novo_contato);
            if (escolher_contato == 0)
            {
                break;
            }
            printf("\nNome: %s\n", lista_de_contato[escolher_contato].nome);
            printf("Email: %s\n", lista_de_contato[escolher_contato].email);
            printf("Numero: (%s)%s\n", lista_de_contato[escolher_contato].ddd, lista_de_contato[escolher_contato].numero);
            printf("\n\t1-EDITAR NOME");
            printf("\n\t2-EDITAR EMAIL");
            printf("\n\t3-EDITAR NUMERO");
            printf("\n\t4-EDITAR TUDO\n\t");
            do
            {
                scanf(" %c", &opcao);
            } while (opcao < '0' || opcao > '4');
            switch (opcao)
            {
                while (getchar() != '\n');
            case '1':
                printf("\n\t1-EDITAR NOME");
                printf("\nNome novo: ");
                adicionarnome(&lista_de_contato[escolher_contato]);
                break;

            case '2':
                printf("\n\t2-EDITAR EMAIL");
                printf("\nEmail novo: ");
                scanf("%s", lista_de_contato[escolher_contato].email);

                break;

            case '3':
                printf("\n\t3-EDITAR NUMERO");
                printf("\nDDD novo: ");
                do
                {   
                    verificar_digito=1;
                    scanf("%s", lista_de_contato[novo_contato].ddd);
                    while (getchar() != '\n');
                
                    for (i = 0; lista_de_contato[novo_contato].ddd[i]!='\0'; i++) 
                    {
                        if (!isdigit(lista_de_contato[novo_contato].ddd[i]))
                        {
                        verificar_digito = 0;  
                        printf("\033[1A\033[K");
                        printf("DDD invalido, digite novamente (ex:xxx): ");
                        break;  
                        }   
                    }
                } while (verificar_digito==0);
                printf("Numero novo: ");
                do
                {   
                    verificar_digito=1;
                    scanf("%s", lista_de_contato[novo_contato].numero);
                    while (getchar() != '\n');
                
                    for (i = 0; i < 9; i++) 
                    {
                        if (!isdigit(lista_de_contato[novo_contato].numero[i]))
                        {
                        verificar_digito = 0;  
                        printf("\033[1A\033[K");
                        printf("Número inválido, digite novamente (ex:xxxxxxxxx): ");
                        break;  
                        }   
                    }
                } while (verificar_digito==0);
                break;

            case '4':
                printf("\n\t4-EDITAR TUDO\n\t");
                printf("\nNome novo: ");
                adicionarnome(&lista_de_contato[escolher_contato]);
                printf("Email novo: ");
                scanf("%s", lista_de_contato[escolher_contato].email);
                printf("DDD novo: ");
                do
                {   
                    verificar_digito=1;
                    scanf("%s", lista_de_contato[escolher_contato].ddd);
                    while (getchar() != '\n');
                
                    for (i = 0; lista_de_contato[novo_contato].ddd[i]!='\0'; i++) 
                    {
                        if (!isdigit(lista_de_contato[escolher_contato].ddd[i]))
                        {
                        verificar_digito = 0;  
                        printf("\033[1A\033[K");
                        printf("DDD invalido, digite novamente (ex:xxx): ");
                        break;  
                        }   
                    }
                } while (verificar_digito==0); 
                printf("Numero novo: ");
                do
                {   
                    verificar_digito=1;
                    scanf("%s", lista_de_contato[escolher_contato].numero);
                    while (getchar() != '\n');
                
                    for (i = 0; i < 9; i++) 
                    {
                        if (!isdigit(lista_de_contato[escolher_contato].numero[i]))
                        {
                        verificar_digito = 0;  
                        printf("\033[1A\033[K");
                        printf("Número inválido, digite novamente (ex:xxxxxxxxx): ");
                        break;  
                        }   
                    }
                } while (verificar_digito==0);
                break;
            default:
                break;
            }

            printf("\nContato alterado com sucesso!");
            system("pause");
            break;

        case '4':

            printf("\n\n\t\x1b[31mEXCLUIR CONTATO\033[0m\n");
            if (novo_contato == 0)
            {
                printf("VOCE NAO TEM CONTATO PARA EXCLUIR\n");
                system("pause");
                break;
            }

            printf("Aqui abaixo estao todos seus contatos: %d\n\n", novo_contato);
            for (i = 1; i <= novo_contato; i++)
            {
                printf("\x1b[31m#%d\033[0m\n", i);
                printf("Nome: %s\n", lista_de_contato[i].nome);
                printf("Email: %s\n", lista_de_contato[i].email);
                printf("Numero: (%s)%s\n\n", lista_de_contato[i].ddd, lista_de_contato[i].numero);
            }
            printf("Escolha qual contato voce quer excluir pelo numero indentificador \x1b[31m#\033[0m ou 0 para voltar: ");
            do
            {
                scanf("%d", &escolher_contato);
                if (escolher_contato < 0 || escolher_contato > novo_contato)
                {
                    printf("Contato inexistente! ");
                }
            } while (escolher_contato < 0 || escolher_contato > novo_contato);
            if (escolher_contato == 0)
            {
                break;
            }
            for (i = escolher_contato; i < novo_contato; i++)
            {
                lista_de_contato[i] = lista_de_contato[i + 1];
            }
            novo_contato--;
            printf("Contato excluido com sucesso!\n");
            system("pause");

            break;

        case '5':

            for (i = 0; i <= 50; i++)
            {
                for (mudancas_aovivo = 0; mudancas_aovivo <= 50; mudancas_aovivo++)
                    if (lista_de_contato[mudancas_aovivo].nome[i] == ' ')
                    {
                        lista_de_contato[mudancas_aovivo].nome[i] = '_';
                    }
            }
            arquivo = fopen("contato.txt", "w"); // " W " vai susbstituir
            fprintf(arquivo, "Numero de contatos %d\n", novo_contato);
            for (i = 1; i <= novo_contato; i++)
            {
                fprintf(arquivo, "%s\n", lista_de_contato[i].nome);
                fprintf(arquivo, "%s\n", lista_de_contato[i].email);
                fprintf(arquivo, "%s %s\n", lista_de_contato[i].ddd, lista_de_contato[i].numero);
            }
            fclose(arquivo);

            return 0;

        default:
            break;
        }
    } while (1);
    return 0;
}
