"""=============={ LISTAS }=============="""
"""Tipos de dados devem ser iguais"""
# Criando uma lista com alguns elementos
lista = [10, 20, 30, 40, 50]

# Acessando elementos individuais da lista
primeiro_elemento = lista[0]
segundo_elemento = lista[1]

# Imprimindo os elementos acessados
print(f'O primeiro elemento da lista é {primeiro_elemento}')
print(f'O segundo elemento da lista é {segundo_elemento}')

# Adicionando um elemento ao final da lista
lista.append(60)
print(f'Lista após adicionar 60: {lista}')

# Inserindo um elemento em uma posição específica
lista.insert(_index=2, _object=25)  # Inserindo 25 na posição 2
print(f'Lista após inserir 25 na posição 2: {lista}')

# Removendo um elemento da lista
lista.remove(40)  # Remove o primeiro valor 40 encontrado
print(f'Lista após remover 40: {lista}')

# Removendo o último elemento da lista
ultimo_elemento = lista.pop()
print(f'Elemento removido: {ultimo_elemento}')
print(f'Lista após remover o último elemento: {lista}')

# Acessando um subgrupo da lista (fatiamento)
sub_lista = lista[1:4]
print(f'Sub-lista (elementos de índice 1 a 3): {sub_lista}')

# Ordenando a lista
lista.sort()
print(f'Lista ordenada: {lista}')

# Iterando sobre os elementos da lista
print('Iterando sobre a lista:')
for elemento in lista:
    print(elemento)

"""=============={ DICIONARIOS }=============="""
"""Trabalha com chave e valor"""
# Criando um dicionário com alguns pares chave-valor
dicionario = {
    "nome": "Alice",
    "idade": 25,
    "cidade": "São Paulo"
}

# Acessando e imprimindo valores individuais usando chaves
nome = dicionario["nome"]
idade = dicionario["idade"]
cidade = dicionario["cidade"]

print(f'Nome: {nome}')
print(f'Idade: {idade}')
print(f'Cidade: {cidade}')

# Adicionando um novo par chave-valor ao dicionário
dicionario["profissão"] = "Engenheira"
print(f'Dicionário após adicionar profissão: {dicionario}')

# Modificando o valor associado a uma chave existente
dicionario["idade"] = 26
print(f'Dicionário após modificar a idade: {dicionario}')

# Removendo um par chave-valor do dicionário
del dicionario["cidade"]
print(f'Dicionário após remover a cidade: {dicionario}')

# Acessando todas as chaves e valores do dicionário
chaves = dicionario.keys()
valores = dicionario.values()

print(f'Chaves: {list(chaves)}')
print(f'Valores: {list(valores)}')

# Iterando sobre os pares chave-valor do dicionário
print('Iterando sobre o dicionário:')
for chave, valor in dicionario.items():
    print(f'{chave}: {valor}')

# Verificando se uma chave existe no dicionário
if "nome" in dicionario:
    print(f'O nome no dicionário é: {dicionario["nome"]}')
else:
    print('A chave "nome" não está no dicionário')

# Usando o método get() para acessar valores de forma segura
profissao = dicionario.get("profissão", "Desconhecido")
print(f'Profissão: {profissao}')

# Limpando todos os elementos do dicionário
dicionario.clear()
print(f'Dicionário após limpar todos os elementos: {dicionario}')

"""=============={ RANGE }=============="""
"""Define um espaço de valores apenas do tipo int"""
# range
for item in range(5):
    print(item)

for item in range(20, 25):
    print(item)

for item in range(100, 150, 10):
    print(item)

"""=============={ TUPLA }=============="""
"""Tipos de dados podem ser diferentes"""

tupla_heterogenea = (1, "Olá", 3.14, [10, 20, 30], {"chave": "valor"})

# Acessando e imprimindo elementos individuais da tupla
print(f'Inteiro: {tupla_heterogenea[0]}')
print(f'String: {tupla_heterogenea[1]}')
print(f'Float: {tupla_heterogenea[2]}')
print(f'Lista: {tupla_heterogenea[3]}')
print(f'Dicionário: {tupla_heterogenea[4]}')

# Modificando a lista dentro da tupla
tupla_heterogenea[3].append(40)