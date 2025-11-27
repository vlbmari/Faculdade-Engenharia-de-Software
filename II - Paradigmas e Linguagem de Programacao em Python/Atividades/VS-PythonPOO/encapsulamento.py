class Conta:
    def __init__(self, numero):
        self.numero = numero
        self._saldo = 0

    """Ao usar o decorador @property em métodos, você mantém os atributos como protegidos, permitindo que sejam 
    acessados apenas por meio desses métodos decorados. Isso garante que os atributos sejam manipulados de maneira segura e 
    conforme as regras definidas na classe."""
    @property 
    def saldo(self):
        return self._saldo
  
    """permite que o atributo saldo seja modificado"""
    @saldo.setter
    def saldo(self, saldo):
        if saldo < 0:
            print ("saldo inválido")
        else:
            self._saldo = saldo
            
def main():
    conta = Conta(1)
    conta.saldo = 1000 # usando o @saldo.setter
    print(f'saldo da conta = {conta.saldo}') # usando o @property
    
if __name__ == "__main__":
    main()
