
"""composição entre as classes Conta e Extrato. Essa composição representa que uma conta pode ser composta por vários extratos."""

import datetime
from classExtrato import Extrato

class Conta:
   def __init__(self, clientes, numero, saldo):
      self.clientes = clientes
      self.numero = numero
      self.saldo = saldo
      self.dataabertura = datetime.datetime.today()
      self.extrato = Extrato()

   def depositar(self, valor):
      self.saldo += valor
      self.extrato.transacoes.append(["DEPOSITO", valor, "Data", datetime.datetime.today()])

   def sacar(self, valor):
      if self.saldo < valor:
         return False
      else:
         self.saldo -= valor
         self.extrato.transacoes.append(["SAQUE", valor, "Data", datetime.datetime.today()])
         return True

   def transfereValor(self, contaDestino, valor):
      if self.saldo < valor:
         return ("Não existe saldo suficiente")
      else:
         contaDestino.depositar(valor)
         self.saldo -= valor
         self.extrato.transacoes.append(["TRANSFERENCIA", valor, "Data", datetime.datetime.today()])
         return("Transferencia Realizada")

   def gerarsaldo(self):
      print(f"numero: {self.numero}\nsaldo: {self.saldo}")

"""AGREGAÇÃO
Na linha número 46, é instanciado um objeto conta1 com dois clientes agregados: 
cliente1 e cliente2. Esses dois objetos são passados como parâmetros."""
from classCliente import Cliente
from classConta import Conta
cliente1 = Cliente("123", "Joao", "Rua X")
cliente2 = Cliente ("456", "Maria", "Rua W")
conta1 = Conta([cliente1, cliente2], 1, 2000)
conta1.depositar(1000)
conta1.sacar(1500)
conta1.extrato.extrato(conta1.numero)