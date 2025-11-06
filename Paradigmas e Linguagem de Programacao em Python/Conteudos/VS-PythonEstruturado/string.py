#delimitadores de string
s1 = 'apostrofes'
print(s1)
s2 = "aspas"
print(s2)
s3 = '''apostrofes triplos
uma string'''
print(s3)
s4 = """aspas triplas"""
print(s4)
print(s1, s2, s3, s4)

# Criando uma string
texto = "Olá, Mundo!"

# Acessando caracteres individuais
primeiro_caractere = texto[0]
ultimo_caractere = texto[-1]

print(f'Primeiro caractere: {primeiro_caractere}')
print(f'Último caractere: {ultimo_caractere}')

# Fatiando uma string
sub_texto = texto[5:10]
print(f'Substring (índices 5 a 9): {sub_texto}')

# Concatenando strings
saudacao = "Olá"
nome = "Alice"
frase = saudacao + ", " + nome + "!"
print(f'Frase concatenada: {frase}')

# Dividindo uma string em uma lista
lista_palavras = texto.split()
print(f'Lista de palavras: {lista_palavras}')

# Substituindo partes de uma string
texto_modificado = texto.replace(_old="Mundo", _new="Python")
print(f'Texto modificado: {texto_modificado}')

# Convertendo para maiúsculas e minúsculas
texto_maiusculo = texto.upper()
texto_minusculo = texto.lower()
print(f'Texto em maiúsculas: {texto_maiusculo}')
print(f'Texto em minúsculas: {texto_minusculo}')

# Removendo espaços em branco (trim)
texto_espacos = " Olá, Mundo! "
texto_sem_espacos = texto_espacos.strip()
print(f'Texto sem espaços extras: {texto_sem_espacos}')

# Verificando a presença de substring
if "Mundo" in texto:
    print('A palavra "Mundo" está presente no texto.')

# Formatação de strings
idade = 30
cidade = "São Paulo"
frase_formatada = f'Meu nome é {nome}, tenho {idade} anos e moro em {cidade}.'
print(f'Frase formatada: {frase_formatada}')

# Outro método de formatação
frase_formatada_2 = "Meu nome é {}, tenho {} anos e moro em {}.".format(nome, idade, cidade)
print(f'Outra frase formatada: {frase_formatada_2}')