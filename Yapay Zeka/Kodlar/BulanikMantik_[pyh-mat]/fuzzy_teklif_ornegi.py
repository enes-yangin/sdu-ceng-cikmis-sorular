"""
Teklif Etme Problemi
\m/, \m/, \m/,
pip install -U scikit-fuzzy
* Girişler
   - `çekicilik`
      * Hedef kişi 0'dan 10'a ne kadar çekici?
      * Fuzzy kümeler: az, orta, çok
   - `para durumu`
      * Hedef kişi 0'dan 10'a ne kadar zengin?
      * Fuzzy kümeler: düşük, orta düzey, zengin
* Çıkış
   - `teklif`
      * %0'dan %100'e teklif etme eğilimi nedir?
      * Fuzzy kümeler: yok, belki, kesin 
* Kurallar
   - Eğer *çekicilik* çok  *ya da* *para durumu* zengin ise teklif olasılığı kesin
   - Eğer *çekicilik* orta ise teklif olasılığı belki
   - Eğer *çekicilik* az  *ve* *para durumu* düşük ise teklif olasılığı yok

"""
import numpy as np
import skfuzzy as fuzz
from skfuzzy import control as karar

#Giriş ve çıkışları tanımlıyoruz
cekicilik = karar.Antecedent(np.arange(0, 11, 1), 'çekicilik')
paradurumu = karar.Antecedent(np.arange(0, 11, 1), 'para durumu')
teklif = karar.Consequent(np.arange(0, 101, 1), 'teklif olasılığı')

# Üyelik fonksiyonlarını sayıya göre otomatik oluşturma
"""
cekicilik.automf(3)
para.automf(3)
"""

# Üyelik fonksiyonları türlerini tanımlama
cekicilik['az'] = fuzz.trimf(cekicilik.universe, [0, 0, 6])
cekicilik['orta'] = fuzz.trimf(cekicilik.universe, [0, 6, 10])
cekicilik['çok'] = fuzz.trimf(cekicilik.universe, [6, 10, 10])

paradurumu['düşük'] = fuzz.trimf(paradurumu.universe, [0, 0, 6])
paradurumu['orta düzey'] = fuzz.trimf(paradurumu.universe, [0, 6, 10])
paradurumu['zengin'] = fuzz.trimf(paradurumu.universe, [6, 10, 10])

teklif['yok ya'] = fuzz.trimf(teklif.universe, [0, 0, 52])
teklif['belki'] = fuzz.trimf(teklif.universe, [0, 52, 100])
teklif['kesin'] = fuzz.trimf(teklif.universe, [52, 100, 100])

# Görüntüleme
"""
cekicilik['orta'].view()
cekicilik.view()
paradurumu.view()
teklif.view()
"""

kural1 = karar.Rule(cekicilik['az'] | paradurumu['düşük'], teklif['yok ya'])
kural2 = karar.Rule(paradurumu['orta düzey'], teklif['belki'])
kural3 = karar.Rule(cekicilik['çok'] & paradurumu['zengin'], teklif['kesin'])
kural4 = karar.Rule(cekicilik['az'] | paradurumu['zengin'], teklif['kesin'])

#kural1.view()
#kural2.view()
#kural3.view()

teklif_karar = karar.ControlSystem([kural1, kural2, kural3, kural4])

teklif_ = karar.ControlSystemSimulation(teklif_karar)

# Giriş değerleri...
teklif_.input['çekicilik'] = 8.56
teklif_.input['para durumu'] = 3

# Hesap
teklif_.compute()

print(teklif_.output['teklif olasılığı'])
teklif.view(sim=teklif_)
