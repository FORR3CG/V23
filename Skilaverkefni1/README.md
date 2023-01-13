# FORR3CG - Skilaverkefni 1 (5%)

- **Verkefnið er einstaklingsverkefni.** Ef tveir eða fleiri nemendur skila sömu lausnunum er gefið 0 (núll) fyrir þær lausnir.
- **Ef kóði er tekinn af netinu** (eða öðrum álíka stöðum) skal taka það fram, benda á hvaðan hann kemur og skrifa skýringar (e. comment) við hverja línu kóðans. Almennt eru ekki gefin stig fyrir kóða sem tekinn er af netinu.
- **Frjálst val er** um að skrifa skýringar við kóðann, að öðru leiti en þar sem liðurinn hér að ofan kallar á, en þú þarft að geta útskýrt hverja línu kóðans nákvæmlega ef beðið er um.
- **Ekki er heimilt** að nota tilbúnar lausnir fyrir fylkin (t.d. std::vector) og ekki nota `global` breytur.
- **Það á að nota** `do-while` og `switch-case` við lausn valmyndarinnar.

## Verkefnalýsing - Stafarugl

Skrifaðu forrit sem tekur eitthundrað bókstafi (bara enska stafrófið) af handahófi (e. random) og setur í tvívítt fylki (10 x 10). Forritið þarf svo að eiga annað fylki (einvítt) sem heldur utan um hversu of hver stafur kemur upp.

Forritið á svo að birta valmynd þar sem notandinn getur valið um að gera eftirfarandi (útfærðu föll fyrir fyrstu fjóra liðina):

- Sjá allar 100 bókstafina, skrifist snyrtilega út í 10 línum, 10 bókstafir í línu.
- Sjá fjölda af hverjum bókstaf.
- Sjá bókstafinn sem kom oftast upp og hversu oft hann kom upp. __*__
- Sjá bókstafinn sem kom sjaldnast upp og hversu oft hann kom upp. __*__
- Hætta keyrslu forritsins.

__*__ ekki þarf að bregðast sérstaklega við ef tveir eða fleiri bókstafir koma jafn oft eða sjaldan upp. Nóg er að birta einn.

Forritið þarf svo að bregðast við með viðeigandi hætti ef notandi velur eitthvað annað en það sem er í boði í valmyndinni.

### Dæmi um virkni

<img src="./SV1.gif" width="50%" height="50%">

## Skil á verkefninu

Skilið verkefninu á Innu. Skilin ættu að vera ein .cpp skrá.

## Bjargir

### Slembitölur (e. random)

Til að nota slembitölur í C++ þarf að nota söfnin `cstdlib` og `ctime`. Fallið `srand` er svo notað til að "seed-a" slembifallið og fallið `rand` notað til að fá slembitölu. Dæmi:

```c++
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));
    for(int i = 0; i < 5; i++) {
        std::cout << std::rand() % 10 << std::endl; // skrifar út eina tölu á bilinu 0 til og með 9
    }
    return 0;
}
```

### Frumstilla stök í fylki

Til að frumstilla öll stök í fylki með sama gildinu er nóg að gera eftirfarandi:

```c++
int fylki[5] = {0}; // býr til 5 staka fylki og setur öll stökin sem núll
```
