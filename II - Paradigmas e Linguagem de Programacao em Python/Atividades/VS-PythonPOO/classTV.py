"""se pedirmos para mudar o canal para baixo, além do mínimo, ela vá para o canal máximo. 
Se mudarmos para cima, além do canal máximo, que volte ao canal mínimo."""

class Televisão:
    def __init__(self, pcanal, min, max):
        self.canal = pcanal
        self.cmin = min
        self.cmax = max

    def muda_canal_para_baixo(self):
        if self.canal - 1 >= self.cmin:
            self.canal -= 1
        else:
            self.canal = self.cmax

    def muda_canal_para_cima(self):
        if self.canal + 1 <= self.cmax:
            self.canal += 1
        else:
            self.canal = self.cmin

tv1 = Televisão(9 , 2,  10 )
print(tv1.canal)
tv1.muda_canal_para_cima()
print(tv1.canal)
tv1.muda_canal_para_cima()
print(tv1.canal)

tv2 = Televisão(3 , 2,  10 )
print(tv2.canal)
tv2.muda_canal_para_baixo()
print(tv2.canal)
tv2.muda_canal_para_baixo()
print(tv2.canal)


"""class Televisao:
    def __init__(self, pcanal, min, max):
        self.canal = pcanal
        self.cmin = min
        self.cmax = max

    def muda_canal_para_baixo(self):
        self.canal -= 1


    def muda_canal_para_cima(self):
        self.canal += 1

tv1 = Televisao(2 , 2,  10 )
print(f"Canal Sintonizado: ",tv1.canal)

print(f"Mudando canal para cima")
for x in  range (1,20):
    tv1.muda_canal_para_cima()
    print(f"Canal Sintonizado: ",tv1.canal)

tv2 = Televisao(10, 2, 10)
print(f"Canal Sintonizado: ",tv2.canal)
print(f"Mudando canal para baixo")
for x in  range (1,20):
    tv2.muda_canal_para_baixo()
    print(f"Canal Sintonizado: ",tv2.canal)"""