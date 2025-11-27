def calcula_imc (peso, altura):
    return peso * 100 / (altura * 2)

peso = eval(input('digite o peso em quilos'))
altura = eval(input('digite a altura em centímetros'))
calcula_imc(peso, altura)
imc = calcula_imc(peso, altura)
print ('imc = ', imc)


def taximetro(distancia, multiplicador=1):
    largada = 3
    km_rodado = 2
    valor = (largada + distancia * km_rodado) * multiplicador
    return valor

pagamento = taximetro(3.5)
print(pagamento)


def taximetro(distancia):
    def calculaMult():
        if distancia < 5:
            return 1.2
        else:
            return 1

    multiplicador = calculaMult()
    largada = 3
    km_rodado = 2
    valor = (largada + distancia * km_rodado) * multiplicador
    return valor