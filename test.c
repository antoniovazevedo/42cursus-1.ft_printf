#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

void ft_putnbr_base(int nbr, char *base);

int main(void)
{
	/*
		%[flags][modifiers][conversion]

		-- FLAGS
			0	altera comportamento da width, preenche com zeros em vez de espaços
				só é utilizado com resultado alinhado à direita (opção por defeito da width),
				pelo que não tem efeito quando a flag – está presente

			-	altera comportamento da width, alinhando resultado à esquerda
				tem prioridade se fornecido juntamente com flag 0
		
			⎵	(espaço)
				resultado é prefixado com um espaço em conversões de números signed (>= 0)

			+	resultado é prefixado com símbolo + em conversões de números signed (>= 0)
				// tem prioridade se fornecido juntamente com flag ⎵ (espaço)

			#	modifica [de que forma? 🤔] as conversões x, X, f, g 

		-- MODIFIERS
			width		garante que resultado tem pelo menos x caracteres
						por defeito preenche os restantes, se necessário, com espaços
						por defeito alinha resultado à direita

			precision	aplica-se a todas as conversões excepto char
						se conversão é string, resultado é truncado para o nº de caracteres da precisão
						se conversão é int e nº caracters do resultado é menor que precisão,
							resultado é prefixado com zeros até perfazer nº de caracteres da precisão
						se conversão é float, resultado é apresentado arredondado com nº de casas decimais igual à precisão  
	*/
	char *str2 = "<%0*.10x>\n";
	printf(str2, 21, 1);
	ft_printf(str2, 21, 1);
}
