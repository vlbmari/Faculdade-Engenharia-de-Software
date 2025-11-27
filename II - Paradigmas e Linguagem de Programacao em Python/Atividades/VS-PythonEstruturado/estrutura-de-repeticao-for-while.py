
"""
=============={ FOR }==============
Usado quando você quer iterar sobre uma sequência de itens ou quando o número de repetições é conhecido antecipadamente.

-- Sintaxe --
for <variável> in <sequência>:
     Bloco que será repetido para todos os itens da sequência
Instrução fora do for
"""
#Exemplo 1
for item in range(2, 9, 3):
    print(item)

#Exemplo 2
for numero in range(11):
    print(numero)

#Exemplo 3
numero = 5
for i in range(1, 11):
    resultado = numero * i
    print(f'{numero} x {i} = {resultado}')

#Exemplo 4
nome = input("Entre com seu nome: \n")
for letra in nome:
    print(letra)

#Exemplo 5
texto = "programação"
letra_para_contar = "a"
contador = 0

#Exemplo 6
for letra in texto:
    if letra == letra_para_contar:
        contador += 1
print(f"A letra '{letra_para_contar}' aparece {contador} vezes na palavra '{texto}'.")

#Exemplo 7
nomes = ['Laura', 'Lis', 'Guilherme', 'Enzo', 'Arthur']
for nome in nomes:
    print(nome)

#Exemplo 8
"""
Quando o Python encontra a instrução continue, ele ignora todas as instruções restantes no laço para aquela iteração
e vai direto para a próxima iteração. Isso é útil quando você deseja pular certos valores ou condições dentro de um laço.
"""
for num in range(1, 11):
    if num == 5:
        continue
    else:
        print(num)
print('Laço encerrado')

#Exemplo 9
"""
O continue permite pular uma iteração específica sem interromper todo o laço, enquanto break encerra o laço por completo.
"""
for num in range(1, 11):
    if num == 5:
        break
    else:
        print(num)
print('Laço encerrado')

#Exemplo 10 
"""
Quando o Python encontra a instrução pass, ele simplesmente continua a execução sem fazer nada. 
Isso pode ser útil em várias situações, como durante o desenvolvimento de código, em que você deseja 
planejar a estrutura do seu programa antes de preencher os detalhes.
"""
for num in range(1, 11):
    if num % 2 == 0:
        pass
    else:
        print(num)
print('Laço encerrado')


"""
=============={ WHILE }==============
Usado quando você quer repetir um bloco de código enquanto uma condição for verdadeira e você não sabe quantas vezes isso precisará ocorrer.


-- Sintaxe --
while condição:
    bloco_de_codigo

while True:
    bloco_de_codigo
"""

#Exemplo 1
palavra = input('Entre com uma palavra: \n')
while palavra != 'sair':
    palavra = input('Digite sair para encerrar o laço: \n')
print('Você digitou sair e agora está fora do laço')

#Exemplo 2
while True:
   print('loop')
   palavra = input('Entre com uma palavra:')
   if palavra == 'sair':
      break
print('Você digitou sair e agora está fora do laço')

#Exemplo 3
while True:
    print('Você está no primeiro laço.')
    opcao1 = input('Deseja sair dele? Digite SIM para isso. \n')
    if opcao1 == 'SIM':
        break  # este break é do primeiro laço
    else:
        while True:
            print('Você está no segundo laço.')
            opcao2 = input('Deseja sair dele? Digite SIM para isso. \n')
            if opcao2 == 'SIM':
               break  # este break é do segundo laço
        print('Você saiu do segundo laço.')
print('Você saiu do primeiro laço')