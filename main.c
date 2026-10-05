#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void fazerPedido();
void mostrarRelatorio();
void simularDesconto();
void calculadora();
void menu();

float calcularDesconto(float total);

int pedidosRealizados = 0;
int itensVendidos = 0;

float faturamentoBruto = 0;
float descontosConcedidos = 0;
float faturamentoFinal = 0;

// menu principal
void menu()
{
    printf("\n     Bem Vindo(a) a   \n");
    printf("    CANTINA DA UCB! :)   ");
    printf("\n-----------------------\n");
    printf("\n1 -- Fazer um novo pedido");
    printf("\n2 -- Calculadora");
    printf("\n3 -- Simulador de desconto");
    printf("\n4 -- Relatorio da sessao");
    printf("\n0 -- Sair\n");

    printf("\nPor favor, escolha uma das opcoes acima: \n");
}

// main
int main()
{

    int opcao;

    do
    {

        menu();
        scanf("%d", &opcao);

        switch (opcao)
        {

        case 1:
            system("cls");
            fazerPedido();
            break;

        case 2:
            system("cls");
            calculadora();
            break;

        case 3:
            system("cls");
            simularDesconto();
            printf("\nPressione ENTER para voltar ao menu...");
            getchar();
            getchar();
            break;

        case 4:
            system("cls");
            mostrarRelatorio();
            printf("\nPressione ENTER para voltar ao menu...");
            getchar();
            getchar();
            break;

        case 0:
            system("cls");
            printf("Sistema encerrado!!");
            Sleep(1500);
            break;

        default:
            system("cls");
            printf("Opcao Invalida!!\n");
            Sleep(1500);
        }

    } while (opcao != 0);

    return 0;
}

// desconto

float calcularDesconto(float total)
{
    float desconto;

    if (total >= 100)
    {
        desconto = total * 0.15;
    }
    else if (total >= 60)
    {
        desconto = total * 0.10;
    }
    else if (total >= 30)
    {
        desconto = total * 0.05;
    }
    else
    {
        desconto = 0;
    }

    return desconto;
}

// pedido
void fazerPedido()
{

    int produto, quantidade, continuar = 1, itensRegistrados = 0;
    char nome[50];

    float preco = 0;
    float subtotal = 0;
    float totalBruto = 0;
    float desconto = 0;
    float totalFinal = 0;

    printf("Digite o seu nome: ");
    scanf("%s", nome);

    system("cls");

    printf("\n-----------------------------------------\n");
    printf("     Bem vindo(a) %s ao nosso cardapio\n", nome);
    printf("-----------------------------------------\n");

    do
    {

        printf("\n1 - Sanduiche ..... R$ 12,00\n");
        printf("2 - Refrigerante .. R$ 6,00\n");
        printf("3 - Suco .......... R$ 8,00\n");
        printf("4 - Salgado ....... R$ 7,00\n");
        printf("5 - Cafe .......... R$ 4,00\n");

        printf("\nEscolha um item: ");
        scanf("%d", &produto);

        if (produto < 1 || produto > 5)
        {
            printf("\nProduto invalido! Tente novamente\n");
            Sleep(1500);
            continue;
        }

        printf("Qual a quantidade?: ");
        scanf("%d", &quantidade);

        if (quantidade <= 0)
        {
            printf("\nQuantidade invalida! Tente novamente\n");
            Sleep(1500);
            continue;
        }

        switch (produto)
        {

        case 1:
            preco = 12.00;
            printf("\n%d sanduiche(s) adicionado(s)!\n", quantidade);
            break;

        case 2:
            preco = 6.00;
            printf("\n%d refrigerante(s) adicionado(s)!\n", quantidade);
            break;

        case 3:
            preco = 8.00;
            printf("\n%d suco(s) adicionado(s)!\n", quantidade);
            break;

        case 4:
            preco = 7.00;
            printf("\n%d salgado(s) adicionado(s)!\n", quantidade);
            break;

        case 5:
            preco = 4.00;
            printf("\n%d cafe(s) adicionado(s)!\n", quantidade);
            break;
        }

        subtotal = preco * quantidade;

        totalBruto = totalBruto + subtotal;

        itensRegistrados = itensRegistrados + quantidade;

        printf("\nSubtotal: R$ %.2f\n", subtotal);
        Sleep(1500);

        printf("\nDeseja adicionar outro item?");
        printf("\n1 - Sim!");
        printf("\n0 - Nao.");
        printf("\nEscolha: ");
        scanf("%d", &continuar);
        Sleep(500);

    } while (continuar == 1);

    // desconto

    desconto = calcularDesconto(totalBruto);

    totalFinal = totalBruto - desconto;

    printf("\n================================\n");
    printf("       RESUMO DO PEDIDO\n");
    printf("================================\n");

    printf("Cliente: %s\n", nome);
    printf("Itens registrados: %d\n", itensRegistrados);
    printf("Total bruto: R$ %.2f\n", totalBruto);
    printf("Desconto: R$ %.2f\n", desconto);
    printf("Total final: R$ %.2f\n", totalFinal);

    printf("================================\n");
    printf("Pedido registrado com sucesso!\n");

    pedidosRealizados++;
    itensVendidos = itensVendidos + itensRegistrados;

    faturamentoBruto = faturamentoBruto + totalBruto;
    descontosConcedidos = descontosConcedidos + desconto;
    faturamentoFinal = faturamentoFinal + totalFinal;

    Sleep(1500);
    printf("\nPressione ENTER para continuar...");
    getchar();
    getchar();

    system("cls");
}

// calculadora
void calculadora()
{

    int opcao;
    float numero1, numero2, resultado;

    do
    {

        printf("\n--------------------\n");
        printf("    CALCULADORA\n");
        printf("--------------------\n");

        printf("1 - Somar\n");
        printf("2 - Subtrair\n");
        printf("3 - Multiplicar\n");
        printf("4 - Dividir\n");
        printf("0 - Voltar\n");

        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 0)
        {
            system("cls");
            break;
        }

        if (opcao < 1 || opcao > 4)
        {
            printf("\nOpcao invalida!\n");
            continue;
        }

        printf("\nDigite o primeiro numero: ");
        scanf("%f", &numero1);

        printf("Digite o segundo numero: ");
        scanf("%f", &numero2);

        switch (opcao)
        {

        case 1:
            resultado = numero1 + numero2;
            printf("\nResultado: %.2f\n", resultado);
            break;

        case 2:
            resultado = numero1 - numero2;
            printf("\nResultado: %.2f\n", resultado);
            break;

        case 3:
            resultado = numero1 * numero2;
            printf("\nResultado: %.2f\n", resultado);
            break;

        case 4:

            if (numero2 == 0)
            {
                printf("\nNao e possivel dividir por zero!\n");
            }
            else
            {
                resultado = numero1 / numero2;
                printf("\nResultado: %.2f\n", resultado);
            }

            break;
        }

    } while (opcao != 0);
}

// desconto
void simularDesconto()
{
    float valorCompra;
    float desconto;
    float valorFinal;

    printf("\n-------------------------\n");
    printf("    SIMULAR DESCONTO\n");
    printf("-------------------------\n");

    printf("\nValor da compra: R$ ");
    scanf("%f", &valorCompra);

    if (valorCompra < 0)
    {
        printf("\nValor invalido!\n");
        return;
    }

    desconto = calcularDesconto(valorCompra);
    valorFinal = valorCompra - desconto;

    printf("\nValor da compra: R$ %.2f\n", valorCompra);
    printf("Desconto: R$ %.2f\n", desconto);
    printf("Valor final: R$ %.2f\n", valorFinal);
}

// relatorio
void mostrarRelatorio()
{
    printf("\n==============================\n");
    printf("        RELATORIO\n");
    printf("==============================\n");

    printf("Pedidos realizados: %d\n", pedidosRealizados);
    printf("Itens vendidos: %d\n", itensVendidos);
    printf("Faturamento bruto: R$ %.2f\n", faturamentoBruto);
    printf("Descontos concedidos: R$ %.2f\n", descontosConcedidos);
    printf("Faturamento final: R$ %.2f\n", faturamentoFinal);
    printf("==============================\n");
}