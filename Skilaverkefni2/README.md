# FORR3CG Skilaverkefni 2 (5%) Vor 2023

## Almennar reglur fyrir verkefnið

- **Verkefnið er einstaklingsverkefni**. Ef tveir eða fleiri nemendur skila sömu lausnunum er gefið 0 (núll) fyrir þær lausnir.
- **Ef kóði er tekinn af netinu** (eða öðrum álíka stöðum) skal taka það fram, benda á hvaðan hann kemur og skrifa skýringar (e. comment) við hverja línu kóðans sé það ekki gert verður gefið 0 (núll) fyrir verkefnið í heild.
- **Frjálst val er** um að skrifa skýringar við kóðann, að öðru leiti en þar sem liðurinn hér að ofan kallar á, en þú þarft að geta útskýrt hverja línu kóðans nákvæmlega ef beðið er um.
- **Ekki er heimilt** að nota tilbúnar lausnir fyrir kviklega fylkið (e. dynamic array) eins og t.d. std::vector. Notið ekki *auto* og allir bendar (e. pointer) skulu vera hráir (e. raw), sem sagt ekki nota *smart pointers*.
- **Sein skil** ef skilað er eftir að skilafrestur er liðinn dragast tveir frá einkunn fyrir hvern byrjaðan sólarhring sem liðinn er frá skilafresti.

## Verkefnið

Skrifaðu forrit sem heldur utan um áfanga sem nemandi er í og einkunnir í þeim.

Forritið þarf að innihalda klasa sem heldur utan um áfanga. Fyrir áfanga þarf að skrá id (heiltala), nafn (strengur) og einkunn (kommutala). Úfærðu smiði og getters/setters ásamt prenta falli, einkunn á alltaf að skrifast út með tveimur aukastöfum.

Gerðu svo annan klasa sem heldur utan um nemanda. Fyrir nemanda þarf að skrá nafn (strengur), **kviklegt fylki** (e. dynamic array) sem í eru áfangarnir sem nemandinn er í og svo stærð fylkisins. Hafðu upphafsstærð fylkisins tvö stök og það á að stækka um tvö stök í hvert skipti sem þarf að stækka það. Útfærðu smiði og eyði (e. destructor) ásamt eftirfarandi föllum:

- Fall sem finnur laust stak í fylkinu.
- Föll til að skrá áfanga á nemanda:
  1. Tekur inn tilvik af áfanga.
  2. Tekur inn upplýsingar til að búa til áfanga.
- Fall til að uppfæra einkunn nemanda í tilteknum áfanga.
- Fall sem fjarlægir áfanga af nemanda.
- Fall sem skrifar á skjáinn einn áfanga sem nemandi er í, finnur áfangann út frá id.
- Fall sem skrifar á skjáinn alla áfanga sem nemandi er í ásamt því að birta meðaleinkunn nemanda í öllum áföngunum.

Skrifaðu svo forrit sem sýnir notkun klasanna. Ekki þarf að huga neitt að villuprófunum. Ekki þarf að bregðast við tvískráningum. Öll gögn skal harðkóða.

Mundu að skipta klösunum upp í .h og .cpp skrár.

Skilaðu svo öllum skránum (ættu að vera tvær .h skrár og þrjár .cpp skrár) á Innu. Engar þjappaðar skrár.

Dæmi um virkni forritsins:

```c++
int main() {
    Nemandi geir = Nemandi("Geir");
    geir.skraAfanga(33, "GAGN", 2.43);

    Afangi forr(34, "FORR", 3.59);
    geir.skraAfanga(forr);
    geir.skodaAfanga(34); // ætti að skrifa út:
                          // ID: 34, nafn: FORR, einkunn: 3.59
    
    geir.skraAfanga(35, "ROBO", 10);
    geir.skraAfanga(36, "KEST", 6.249);

    //            áfangi_id, einkunn
    geir.uppfaeraEinkunn(34, 4.49);

    //       áfangi_id
    geir.eydaAfanga(33);

    geir.prenta(); // ætti að skrifa út:
                   //   Nemandi: Geir, áfangar:
                   //   ID: 34, nafn: FORR, einkunn: 4.49
                   //   ID: 35, nafn: ROBO, einkunn: 10.00
                   //   ID: 36, nafn: KEST, einkunn: 6.25
                   //   Meðaleinkunnin er 6.91
                    
    return 0;
}
```
