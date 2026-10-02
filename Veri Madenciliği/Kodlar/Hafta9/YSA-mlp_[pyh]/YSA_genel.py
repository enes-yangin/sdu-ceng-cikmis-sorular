from numpy import exp, array, random, dot

class YapaySinirAglariCKA():
    def __init__(self):
        # rastgele sayý
        random.seed(1)

        # 2 giriþ 1 çýkýþlý YSA
        # -1'den 1'e rastgele aðýrlýk deðerleri
        self.agirliklar = 2 * random.random((2, 1))

    # Sigmoid aktivasyon fonksiyonu
    def __sigmoid(self, x):
        return 1 / (1 + exp(-x))

    # Sigmoid aktivasyon fonksiyonunun türevi
    def __sigmoid_turev(self, x):
        return x * (1 - x)

    # Eðitim - training aþamasý
    def egit_beni(self, egitim_girisler, egitim_cikislar, toplam_iterasyon):
        for iterasyon in range(toplam_iterasyon):
            cikis = self.besle(egitim_girisler)

            # Hata hesabý...
            hata = egitim_cikislar - cikis

            # Aðýrlýk ayar deðeri
            ayar = dot(egitim_girisler.T, hata * self.__sigmoid_turev(cikis))

            # Aðýrlýklarý ayarlama...
            self.agirliklar += ayar

    # Ýleri besleme/test/uyg.
    def besle(self, giris):
        return self.__sigmoid(dot(giris, self.agirliklar))

if __name__ == "__main__":

    #YSA kurulumu...
    ysa = YapaySinirAglariCKA()

    print("Başlangıç ağırlıkları (rastgele): ")
    print(ysa.agirliklar)

    # Eðitim seti þeyi...
    egitim_girisler = array([[1, 0], [1, 1], [0, 0]])
    egitim_cikislar = array([[1, 1, 0]]).T

    # Ýlgili iterasyon deðeri kadar eðitim
    ysa.egit_beni(egitim_girisler, egitim_cikislar, 200000)

    print("Eğitim sonrası ağırlıklar: ")
    print(ysa.agirliklar)

    # Test aþamasý
    print("Yeni test girişleri için çıkış kaç ki lan?: ")
    print(ysa.besle(array([0, 1])))
    