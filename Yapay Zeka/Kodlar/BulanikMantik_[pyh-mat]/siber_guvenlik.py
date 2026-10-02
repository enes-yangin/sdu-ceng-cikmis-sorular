import numpy as np
import skfuzzy as fuzzy
from skfuzzy import control as karar  

giris1 = karar.Antecedent(np.arange(0, 101, 1),'guvenlik_puani')
giris2 = karar.Antecedent(np.arange(0, 101, 1),'harcama_gucu')
cikis = karar.Consequent(np.arange(0, 101, 1),'fon_orani')

giris1['cok_dusuk'] = fuzzy.trimf(giris1.universe, [0, 0, 25])
giris1['dusuk'] = fuzzy.trimf(giris1.universe, [0, 25, 50])
giris1['orta'] = fuzzy.trimf(giris1.universe, [25, 50, 75])
giris1['yuksek'] = fuzzy.trimf(giris1.universe, [50, 75, 100])
giris1['cok_yuksek'] = fuzzy.trimf(giris1.universe, [75, 100, 100])

giris2['cok_zayif'] = fuzzy.trimf(giris2.universe, [0, 0, 15])
giris2['zayif'] = fuzzy.trimf(giris2.universe, [0, 40, 65])
giris2['normal'] = fuzzy.trimf(giris2.universe, [40, 65, 88])
giris2['guclu'] = fuzzy.trimf(giris2.universe, [60, 90, 100])
giris2['cok_guclu'] = fuzzy.trimf(giris2.universe, [85, 100, 100])

cikis['cok_dusuk'] = fuzzy.trimf(cikis.universe, [0, 0, 25])
cikis['dusuk'] = fuzzy.trimf(cikis.universe, [0, 25, 50])
cikis['orta'] = fuzzy.trimf(cikis.universe, [25, 50, 75])
cikis['yuksek'] = fuzzy.trimf(cikis.universe, [50, 75, 100])
cikis['cok_yuksek'] = fuzzy.sigmf(cikis.universe, 85, 0.16)

giris1.view()
giris2.view()
cikis.view()

kural1 = karar.Rule(giris1['cok_dusuk'] & giris2['cok_zayif'], cikis['cok_dusuk'])
kural2 = karar.Rule(giris1['dusuk'] & giris2['normal'], cikis['orta'])
kural3 = karar.Rule(giris1['cok_yuksek'] & giris2['cok_guclu'], cikis['dusuk'])
kural4 = karar.Rule(giris1['orta'] & giris2['zayif'], cikis['dusuk'])
kural5 = karar.Rule(giris1['yuksek'] & giris2['cok_zayif'], cikis['orta'])
kural6 = karar.Rule(giris1['orta'] & giris2['guclu'], cikis['yuksek'])
kural7 = karar.Rule(giris1['cok_dusuk'] & giris2['cok_guclu'], cikis['cok_yuksek'])

funding_karar = karar.ControlSystem([kural1, kural2, kural3, kural4, kural5, kural6, kural7])

funding_ = karar.ControlSystemSimulation(funding_karar)

# Giriş değerleri...
funding_.input['guvenlik_puani'] = 21
funding_.input['harcama_gucu'] = 12

# Hesap
funding_.compute()
print(funding_.output['fon_orani'])
cikis.view(sim=funding_)
