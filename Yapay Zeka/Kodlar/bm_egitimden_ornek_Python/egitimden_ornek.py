"""
\m/, \m/, \m/,
pip install -U scikit-fuzzy 
eğer yukarıdaki olmazsa, cmd'de python -m pip install -U scikit-fuzzy 

"""
import numpy as np
import skfuzzy as fuzz
from skfuzzy import control as karar
import pandas as pd

#Giriş ve çıkışları tanımlıyoruz
boy = karar.Antecedent(np.arange(140, 201, 1), 'boy')
kilo = karar.Antecedent(np.arange(45, 101, 1), 'kilo')
yas = karar.Antecedent(np.arange(8, 36, 1), 'yaş')
spor = karar.Consequent(np.arange(1, 6, 1), 'spor')

# Üyelik fonksiyonları türlerini tanımlama
boy['çok kısa'] = fuzz.trimf(boy.universe, [140, 140, 155])
boy['kısa'] = fuzz.trimf(boy.universe, [140, 155, 170])
boy['orta'] = fuzz.trimf(boy.universe, [155, 170, 185])
boy['uzun'] = fuzz.trimf(boy.universe, [170, 185, 200])
boy['çok uzun'] = fuzz.trimf(boy.universe, [185, 200, 200])

kilo['çok zayıf'] = fuzz.trimf(kilo.universe, [45, 45, 59])
kilo['zayıf'] = fuzz.trimf(kilo.universe, [45, 59, 73])
kilo['fit'] = fuzz.trimf(kilo.universe, [59, 73, 87])
kilo['şişman'] = fuzz.trimf(kilo.universe, [73, 87, 100])
kilo['çok şişman'] = fuzz.trimf(kilo.universe, [87, 100, 100])

yas['çocuk'] = fuzz.trimf(yas.universe, [8, 8, 22])
yas['ergen'] = fuzz.trimf(yas.universe, [8, 22, 35])
yas['genç'] = fuzz.trimf(yas.universe, [22, 35, 35])

spor['yüzme'] = fuzz.trimf(spor.universe, [1, 1, 2])
spor['karate'] = fuzz.trimf(spor.universe, [1, 2, 3])
spor['futbol'] = fuzz.trimf(spor.universe, [2, 3, 4])
spor['voleybol'] = fuzz.trimf(spor.universe, [3, 4, 5])
spor['basketbol'] = fuzz.trimf(spor.universe, [4, 5, 5])

# Görüntüleme
"""
boy.view()
yas.view()
kilo.view()
spor.view()
"""


kural1 = karar.Rule(boy['kısa'] & kilo['fit'] & yas["ergen"], spor['futbol'])
kural2 = karar.Rule(boy['çok uzun'] & kilo['şişman'] & yas["genç"], spor['basketbol'])
kural3 = karar.Rule(boy['çok uzun'] & kilo['zayıf'] & yas["ergen"], spor['voleybol'])
kural4 = karar.Rule(boy['çok uzun'] & kilo['zayıf'] & yas["genç"], spor['voleybol'])
kural5 = karar.Rule(boy['çok kısa'] | kilo['çok zayıf'] | yas["çocuk"], spor['karate'])
kural6 = karar.Rule(boy['uzun'] & kilo['çok şişman'] & yas["genç"], spor['futbol'])
kural7 = karar.Rule(boy['orta'] & kilo['şişman'] & yas["ergen"], spor['yüzme'])
kural8 = karar.Rule(boy['çok kısa'] & kilo['fit'] & yas["çocuk"], spor['yüzme'])
kural9 = karar.Rule(boy['çok uzun'] & kilo['fit'] & yas["ergen"], spor['basketbol'])
kural10 = karar.Rule(boy['orta'] | kilo['fit'] & yas["genç"], spor['futbol'])
kural11 = karar.Rule(boy['kısa'] & kilo['zayıf'] | yas["çocuk"], spor['karate'])

spor_karar = karar.ControlSystem([kural1, kural2, kural3, kural4, kural5, kural6, kural7, kural8, kural9, kural10, kural11])

spor_ = karar.ControlSystemSimulation(spor_karar)

print("#### BM Spor Dalı Seçim Sistemi ####")
print("Merhaba... Hemen hesaplıyorum abi (:")

#Dosyadan okuyarak değerlendirme
df = pd.read_excel('degerler.xlsx', sheetName='Sayfa1')

for i in df.index:
    spor_.input['boy'] = df['Boy'][i]
    spor_.input['kilo'] = df['Kilo'][i]
    spor_.input['yaş'] = df['Yaş'][i]
    
    adsoyad = df['Ad Soyad'][i]
# Hesap
    spor_.compute()
    print(i+1,". öğrenci",adsoyad," için çözüm:")
    print(spor_.output['spor'])
    spor.view(sim=spor_)
print("Bütün öğrenciler hesaplandı.")