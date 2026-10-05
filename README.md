# Sistema de Gerenciamento de Cantina

Projeto acadêmico desenvolvido em **C** para o curso de Engenharia de Software (UCB). O programa simula o atendimento de uma cantina pelo terminal, com registro de pedidos, descontos e relatório de vendas.

## Funcionalidades

- **Novo pedido:** o cliente informa o nome e escolhe quantos itens quiser do cardápio, com validação de produto e quantidade.
- **Desconto progressivo** sobre o total do pedido:

  | Total do pedido | Desconto |
  |-----------------|----------|
  | a partir de R$ 30,00 | 5% |
  | a partir de R$ 60,00 | 10% |
  | a partir de R$ 100,00 | 15% |

- **Simulador de desconto:** calcula o desconto de qualquer valor sem registrar pedido.
- **Calculadora:** soma, subtração, multiplicação e divisão (com tratamento de divisão por zero).
- **Relatório da sessão:** pedidos realizados, itens vendidos, faturamento bruto, descontos concedidos e faturamento final.

## Cardápio

| Item | Preço |
|------|-------|
| Sanduíche | R$ 12,00 |
| Refrigerante | R$ 6,00 |
| Suco | R$ 8,00 |
| Salgado | R$ 7,00 |
| Café | R$ 4,00 |

## Como executar

O programa usa `windows.h` (`Sleep` e `system("cls")`), então **funciona no Windows**.

Com o [MinGW](https://www.mingw-w64.org/) (gcc) instalado:

```bash
gcc main.c -o cantina
./cantina
```

## Conceitos aplicados

- Menus com `switch` e repetição com `do-while`
- Funções (`calcularDesconto`, `fazerPedido`, `mostrarRelatorio`, entre outras)
- Variáveis globais para os totais da sessão
- Validação de entradas do usuário
- Estruturas condicionais encadeadas (`if / else if`)

## Observações

Os dados do relatório ficam apenas na memória: ao encerrar o programa, o histórico da sessão é perdido.

## Autora

Ester Guimarães Nunes — [GitHub](https://github.com/EsterGuima)
