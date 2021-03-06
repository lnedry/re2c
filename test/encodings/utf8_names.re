// re2c $INPUT -o $OUTPUT -i8 --input-encoding utf8
#include <stdio.h>

int lex(const char *YYCURSOR)
{
#define YYCTYPE unsigned char
    const char *YYMARKER;

    /*!re2c
    re2c:yyfill:enable = 0;

    end = "\x00";

    utfExamples =
    ( "Abadía"
    | "Åberg"
    | "Abián"
    | "Adám"
    | "Ádám"
    | "Adenízia"
    | "Áder"
    | "Adrián"
    | "Ágatha"
    | "Agustín"
    | "Ahouré"
    | "Aída"
    | "Aïda"
    | "Ajeé"
    | "Akgül"
    | "Alagía"
    | "Alarcón"
    | "Aléman"
    | "Álex"
    | "Alizé"
    | "Alizée"
    | "Álvarez"
    | "Álvaro"
    | "Amélie"
    | "Anaís"
    | "Anaïs"
    | "Anastasákis"
    | "Andéol"
    | "András"
    | "André"
    | "Andréanne"
    | "Andrée"
    | "Andrés"
    | "Andújar"
    | "Anél"
    | "Ángel"
    | "Ángela"
    | "Angélil"
    | "Aníbal"
    | "Aníta"
    | "Añor"
    | "Antónia"
    | "António"
    | "Aoás"
    | "Apolónia"
    | "Araújo"
    | "Arbeláez"
    | "Arcón"
    | "Arévalo"
    | "Áron"
    | "Ásdís"
    | "Auböck"
    | "Augé"
    | "Áurea"
    | "Aurélie"
    | "Aurélien"
    | "Ávila"
    | "Baláz"
    | "Balázs"
    | "Ballivián"
    | "Bárbara"
    | "Bård"
    | "Barnabé"
    | "Barré"
    | "Barták"
    | "Barteková"
    | "Baugé"
    | "Bäumer"
    | "Béatrice"
    | "Bécaud"
    | "Bédard"
    | "Bédié"
    | "Begoña"
    | "Béla"
    | "Bélanger"
    | "Belascoarán"
    | "Belén"
    | "Bělohlávek"
    | "Beltré"
    | "Benavídez"
    | "Bendegúz"
    | "Benítez"
    | "Benjámin"
    | "Benoît"
    | "Beresová"
    | "Bermúdez"
    | "Bernabéu"
    | "Bernárdez"
    | "Béryl"
    | "Beyoncé"
    | "Böckler"
    | "Boczkó"
    | "Boglárka"
    | "Bolaños"
    | "Bolívar"
    | "Bolükbasi"
    | "Borgström"
    | "Borlée"
    | "Böröcz"
    | "Botín"
    | "Briceño"
    | "Brücken"
    | "Brzobohatý"
    | "Bubeník"
    | "Bublé"
    | "Bühler"
    | "Búranová"
    | "Büsra"
    | "Büthe"
    | "Büyükakcay"
    | "Byström"
    | "Cabrnochová"
    | "Cáceres"
    | "Calderón"
    | "Cañadilla"
    | "Cañas"
    | "Cañavate"
    | "Canelón"
    | "Cánepa"
    | "Cantú"
    | "Capó"
    | "Cárdenas"
    | "Carlén"
    | "Carré"
    | "Casañas"
    | "Cassarà"
    | "Cássia"
    | "Castellaños"
    | "Cátia"
    | "Cazaubón"
    | "Cebrián"
    | "Cécile"
    | "Cécilia"
    | "Cédric"
    | "Célestin"
    | "Céline"
    | "Célio"
    | "Čepický"
    | "Cerén"
    | "César"
    | "Céspedes"
    | "Cézanne"
    | "Chacón"
    | "Chaunté"
    | "Chávez"
    | "Chihuán"
    | "Chloé"
    | "Chrétien"
    | "Cibrián"
    | "Cintrón"
    | "Cíosóig"
    | "Cissé"
    | "Clélia"
    | "Clémence"
    | "Clément"
    | "Clévenot"
    | "Colón"
    | "Compaoré"
    | "Conceição"
    | "Concepción"
    | "Condé"
    | "Córdoba"
    | "Cordón"
    | "Córdova"
    | "Cortés"
    | "Crépeau"
    | "Cristóbal"
    | "Cubillán"
    | "Cué"
    | "Cuétara"
    | "Cynné"
    | "Czaková"
    | "Czigány"
    | "Daabousová"
    | "Dallapé"
    | "Dániel"
    | "Danièle"
    | "Danté"
    | "Dávalos"
    | "Dávid"
    | "DawnCheré"
    | "Débora"
    | "Déborah"
    | "Déby"
    | "Décary"
    | "Delía"
    | "Dembélé"
    | "Dénes"
    | "Dépré"
    | "DerlisRamón"
    | "Dési"
    | "Desirée"
    | "Desrosières"
    | "Díaz"
    | "Diémé"
    | "Dièye"
    | "Dilmé"
    | "Djá"
    | "Djénébou"
    | "Dolínek"
    | "Domínguez"
    | "Donté"
    | "Dóra"
    | "Dorjsürengiin"
    | "Dostál"
    | "Duchonová"
    | "Ducó"
    | "Dueñas"
    | "Dukátová"
    | "Durán"
    | "Dvorák"
    | "Echávarri"
    | "Echevarría"
    | "Éder"
    | "Édgar"
    | "Ekateríni"
    | "Élodie"
    | "Elphége"
    | "Émane"
    | "Émile"
    | "Emilíana"
    | "Émilie"
    | "Épangue"
    | "Erdélyi"
    | "Ergüven"
    | "Érica"
    | "Érick"
    | "Érika"
    | "España"
    | "Espíndola"
    | "Étienne"
    | "Eugénie"
    | "Eurén"
    | "Éva"
    | "Éve"
    | "Évora"
    | "Fabián"
    | "Fábio"
    | "Fabíola"
    | "Fagúndez"
    | "Fältskog"
    | "Fariña"
    | "Felício"
    | "Félix"
    | "Ferencová"
    | "Fernández"
    | "Flávia"
    | "Flesjå"
    | "Flóra"
    | "Florenç"
    | "Flügel"
    | "Flüggen"
    | "Foldházi"
    | "François"
    | "Françoise"
    | "Frédéric"
    | "Frédérick"
    | "Frisé"
    | "Fürste"
    | "Gábor"
    | "Gádorfalvi"
    | "Gagné"
    | "Gáliková"
    | "Gándara"
    | "Garbiñe"
    | "García"
    | "Garrigós"
    | "Gascón"
    | "Gáspár"
    | "Gastón"
    | "Gaudí"
    | "Gélineau"
    | "Geneviève"
    | "Gérard"
    | "Germán"
    | "Gerónimo"
    | "Géroudet"
    | "Gévrise"
    | "Giménez"
    | "Ginóbili"
    | "Gnassingbé"
    | "Gomà"
    | "Gómez"
    | "Gonçalves"
    | "Göncz"
    | "González"
    | "Göran"
    | "Grátz"
    | "Grégory"
    | "Grévy"
    | "Grimké"
    | "Grimsbö"
    | "Grímsson"
    | "Grönberg"
    | "Grövdal"
    | "Guillén"
    | "Güldeniz"
    | "Gülec"
    | "Gulldén"
    | "Gümbel"
    | "Gündegmaa"
    | "Günes"
    | "Günther"
    | "Gutiérrez"
    | "Güvenc"
    | "Guzmán"
    | "György"
    | "Gyurcsány"
    | "HÃ¤fner"
    | "Háido"
    | "Håkan"
    | "Hambüchen"
    | "Hamchétou"
    | "Hárai"
    | "Härstedt"
    | "Håvard"
    | "Havlát"
    | "Héléna"
    | "Hélene"
    | "Hendrychová"
    | "Hernán"
    | "Hernández"
    | "Hernangómez"
    | "Hervé"
    | "Hidvégi"
    | "Higuaín"
    | "Hinriksdóttir"
    | "Hjálmsdóttir"
    | "Holingerová"
    | "Holló"
    | "Horváth"
    | "Hosnyánszky"
    | "Hosszú"
    | "Hrasnová"
    | "Hristóforos"
    | "Hrivnák"
    | "Hufnágel"
    | "Hultén"
    | "Hüseyin"
    | "Hypólito"
    | "Hyryläinen"
    | "Ibañez"
    | "Ibargüen"
    | "Idéhn"
    | "Ié"
    | "Illés"
    | "Inácio"
    | "Iñárritu"
    | "Inés"
    | "István"
    | "Iván"
    | "Jackée"
    | "Jágr"
    | "Jakubský"
    | "Jámison"
    | "Jämsä"
    | "Janatková"
    | "János"
    | "Járóka"
    | "Jaurès"
    | "Jeremiáš"
    | "Jérémie"
    | "Jérémy"
    | "Jérent"
    | "Jérome"
    | "Jéssica"
    | "Jesús"
    | "Jhené"
    | "Jiménez"
    | "Jiří"
    | "João"
    | "Joaquín"
    | "Joëlle"
    | "Jóhannsson"
    | "Jonatán"
    | "JonBenét"
    | "Jördis"
    | "Jorén"
    | "Josée"
    | "Josué"
    | "Jóźwiak"
    | "Juhász"
    | "Júlio"
    | "Júnior"
    | "Juppé"
    | "Jürgen"
    | "Jurinová"
    | "Kaboré"
    | "Kafétien"
    | "Kaká"
    | "Kalovský"
    | "Kapás"
    | "Karlström"
    | "Karolína"
    | "Kasó"
    | "Katarína"
    | "Kätlin"
    | "KÃ©vin"
    | "Kemrová"
    | "Késely"
    | "Kévin"
    | "Khloé"
    | "Khüderbulga"
    | "Kléber"
    | "Kléberson"
    | "Klobucník"
    | "Klocová"
    | "Klöden"
    | "Kněžínková"
    | "Köbrich"
    | "Köhler"
    | "Kohlová"
    | "Koňařík"
    | "Kořán"
    | "Kovács"
    | "Kovágó"
    | "Kozák"
    | "Krejčí"
    | "Kristián"
    | "Krisztián"
    | "Krizsán"
    | "Krüger"
    | "Kühn"
    | "Kühne"
    | "Kylliäinen"
    | "Laanmäe"
    | "Labbé"
    | "Laferrière"
    | "Laprovíttola"
    | "Larrañaga"
    | "László"
    | "Lázaro"
    | "Léa"
    | "Léandre"
    | "Lefèvre"
    | "Leitón"
    | "Lemprière"
    | "León"
    | "Lepistö"
    | "Lerú"
    | "Lidström"
    | "Lillána"
    | "Listopadová"
    | "Liván"
    | "Lívia"
    | "Lloréns"
    | "Lluís"
    | "Löke"
    | "Longová"
    | "López"
    | "Lotiès"
    | "Lövnes"
    | "Lü"
    | "Lübeck"
    | "Lucía"
    | "Lückenkemper"
    | "Luís"
    | "Lukás"
    | "Lukáš"
    | "Lúthersdóttir"
    | "Madaí"
    | "Madarász"
    | "Mäe"
    | "Magallán"
    | "Mägi"
    | "Mahé"
    | "Maíla"
    | "Majdán"
    | "Mäkelä"
    | "Mandátová"
    | "Mané"
    | "Mangué"
    | "Marc-André's"
    | "Márcio"
    | "Maréchal"
    | "Marí"
    | "Mária"
    | "María"
    | "Marílson"
    | "Marín"
    | "Mariño"
    | "Mário"
    | "Márk"
    | "MarozsÃ¡n"
    | "Márquez"
    | "Martí"
    | "Martín"
    | "Martínek"
    | "Martínez"
    | "Márton"
    | "Massó"
    | "Mätas"
    | "Máté"
    | "Matías"
    | "Matús"
    | "Maurício"
    | "Máximo"
    | "Meité"
    | "Mélanie"
    | "Mélina"
    | "Méline"
    | "Méndez"
    | "Meroúsis"
    | "Micheál"
    | "Michèle"
    | "Mihaíl"
    | "Mijaín"
    | "Miklós"
    | "Millán"
    | "Miltiádis"
    | "Moisés"
    | "Mokosová"
    | "Molnár"
    | "Mónaco"
    | "Monáe"
    | "Mónica"
    | "Mónika"
    | "Montaño"
    | "Morén"
    | "Mörk"
    | "Mörö"
    | "Müller"
    | "Muñiz"
    | "Muñoz"
    | "Murúa"
    | "Nádia"
    | "Naïm"
    | "Natália"
    | "Negrón"
    | "Németh"
    | "Néstor"
    | "Niccolò"
    | "Nicolás"
    | "Niinistö"
    | "Nóbrega"
    | "Noélie"
    | "Noémie"
    | "Nordén"
    | "Núbia"
    | "Nuñez"
    | "Ódorová"
    | "Öhrström"
    | "Ólafur"
    | "Óleo"
    | "Opatrný"
    | "Orbán"
    | "Ordóñez"
    | "Oréane"
    | "Ortíz"
    | "Óscar"
    | "Ozlü"
    | "Ozyüksel"
    | "Pääbo"
    | "Pabón"
    | "Padacké"
    | "Pádraig"
    | "Páez"
    | "Pajón"
    | "Pál"
    | "Palát"
    | "Panayióta"
    | "Pär"
    | "Paré"
    | "Pärt"
    | "Patiño"
    | "Patrícia"
    | "Patrocínio"
    | "Pattantyús"
    | "Pavón"
    | "Péché"
    | "Péchoux"
    | "Pelikán"
    | "Peña"
    | "Peñate"
    | "Pénélope"
    | "Péni"
    | "Pépin"
    | "Pérez"
    | "Perón"
    | "Pétain"
    | "Petchamé"
    | "Péter"
    | "Pétervári"
    | "Philémon"
    | "Phúc"
    | "Piétrus"
    | "Pinzón"
    | "Pité"
    | "Pitkämäki"
    | "Poésy"
    | "Pokorný"
    | "Polívka"
    | "Póta"
    | "Préval"
    | "Prokopová"
    | "Puigcercós"
    | "Pürevjargalyn"
    | "Putálová"
    | "Quiñones"
    | "Quiñonez"
    | "Quintillà"
    | "Quvenzhané"
    | "Rácz"
    | "Ramírez"
    | "Raúl"
    | "Řebíček"
    | "Récsei"
    | "Rédli"
    | "Réka"
    | "Rémi"
    | "Renáta"
    | "Rendón"
    | "René"
    | "Renée"
    | "Rénelle"
    | "Rentería"
    | "Repcík"
    | "Reséndiz"
    | "Rézola"
    | "Ribéry"
    | "Richárd"
    | "Ríga"
    | "Robenílson"
    | "Róbert"
    | "Róchez"
    | "Rocío"
    | "Rodríguez"
    | "Rogério"
    | "Rolfö"
    | "Román"
    | "Romová"
    | "Rónald"
    | "Rosário"
    | "Rubén"
    | "Rühr"
    | "Ruíz"
    | "Sá"
    | "Saborío"
    | "Sagardía"
    | "Sallói"
    | "Salomé"
    | "Salvadó"
    | "Samassékou"
    | "Sánchez"
    | "Sandé"
    | "Sándor"
    | "Sardá"
    | "Sárosi"
    | "Sátila"
    | "Saúl"
    | "Saunière"
    | "Savón"
    | "Scalamandré"
    | "Schächter"
    | "Schäfer"
    | "Schäuble"
    | "Schlögl"
    | "Schmiedlová"
    | "Schön"
    | "Schröder"
    | "Schüpbac"
    | "Schüssel"
    | "Schütze"
    | "Séamus"
    | "Seán"
    | "Sebastián"
    | "Sébastien"
    | "Sebestyén"
    | "Sélom"
    | "Sène"
    | "Senyürek"
    | "Seppälä"
    | "Sepúlveda"
    | "Sérgio"
    | "Shkëlzen"
    | "Sicília"
    | "Silfvén"
    | "Siljamäki"
    | "Sinéad"
    | "Sjåstad"
    | "Sjöberg"
    | "Sjödin"
    | "Sjöström"
    | "Skantár"
    | "Söderberg"
    | "Söderling"
    | "Sofía"
    | "Solé"
    | "Solís"
    | "Söllner"
    | "Somorácz"
    | "Sörenstam"
    | "Ståhl"
    | "Ståle"
    | "Stefanídi"
    | "Stéphane"
    | "Stéphanie"
    | "Strålman"
    | "Strömberg"
    | "Stübe"
    | "Studničková"
    | "Suárez"
    | "Šuláková"
    | "Süle"
    | "Süleyman"
    | "Švácha"
    | "Svärd"
    | "Svennerstål"
    | "Szabián"
    | "Szabó"
    | "Szász"
    | "Szilágyi"
    | "Szomolányi"
    | "Szücs"
    | "Szwarnóg"
    | "Taaramäe"
    | "Tabaré"
    | "Tainá"
    | "Takács"
    | "Támara"
    | "Tamás"
    | "Tarragó"
    | "Tazegül"
    | "Tcheuméo"
    | "Tchórz"
    | "Téa"
    | "Tentóglou"
    | "Teófilo"
    | "Teré"
    | "Tévez"
    | "Thaísa"
    | "Théo"
    | "Théophile"
    | "Thérèse"
    | "Théry"
    | "Thiéry"
    | "Tímea"
    | "Tió"
    | "Todenhöfer"
    | "Tomáš"
    | "Tomorkhüleg"
    | "Tõnu"
    | "Topolánek"
    | "Tormé"
    | "Tornéus"
    | "Törnroos"
    | "Török"
    | "Tórrez"
    | "Tórtola"
    | "Tóth"
    | "Touadéra"
    | "Tramèr"
    | "Traoré"
    | "Träsch"
    | "Trévor"
    | "Tsinopoúlou"
    | "Túñez"
    | "Türk"
    | "Tüvshinbat"
    | "Tüvshinbayar"
    | "Üitümen"
    | "Ünal"
    | "Ungvári"
    | "Urán"
    | "Úrsula"
    | "Üstündag"
    | "Václav"
    | "Valdés"
    | "Valentín"
    | "Valérian"
    | "Valériane"
    | "Välimäki"
    | "Vallée"
    | "Vámos"
    | "Vásquez"
    | "Vázquez"
    | "Velázquez"
    | "Veldáková"
    | "Venyercsán"
    | "Veréb"
    | "Verón"
    | "Verrasztó"
    | "Víctor"
    | "Victória"
    | "Viktória"
    | "Vilató"
    | "Villaécija"
    | "Villafría"
    | "Vinícius"
    | "Viñolas"
    | "Vitória"
    | "Vladimír"
    | "Wallén"
    | "Wálter"
    | "Wanyá"
    | "Wé"
    | "Wéverton"
    | "Wikström"
    | "Xénia"
    | "Yáñez"
    | "Younés"
    | "Zagré"
    | "Zalánki"
    | "Zelená"
    | "Zélia"
    | "Zoltán"
    | "Zságer"
    | "Zsófia"
    );

    utfExamples end { return 0; }
    * { return 1; }
    */
}

const char *names[] =
    { "Abadía"
    , "Åberg"
    , "Abián"
    , "Adám"
    , "Ádám"
    , "Adenízia"
    , "Áder"
    , "Adrián"
    , "Ágatha"
    , "Agustín"
    , "Ahouré"
    , "Aída"
    , "Aïda"
    , "Ajeé"
    , "Akgül"
    , "Alagía"
    , "Alarcón"
    , "Aléman"
    , "Álex"
    , "Alizé"
    , "Alizée"
    , "Álvarez"
    , "Álvaro"
    , "Amélie"
    , "Anaís"
    , "Anaïs"
    , "Anastasákis"
    , "Andéol"
    , "András"
    , "André"
    , "Andréanne"
    , "Andrée"
    , "Andrés"
    , "Andújar"
    , "Anél"
    , "Ángel"
    , "Ángela"
    , "Angélil"
    , "Aníbal"
    , "Aníta"
    , "Añor"
    , "Antónia"
    , "António"
    , "Aoás"
    , "Apolónia"
    , "Araújo"
    , "Arbeláez"
    , "Arcón"
    , "Arévalo"
    , "Áron"
    , "Ásdís"
    , "Auböck"
    , "Augé"
    , "Áurea"
    , "Aurélie"
    , "Aurélien"
    , "Ávila"
    , "Baláz"
    , "Balázs"
    , "Ballivián"
    , "Bárbara"
    , "Bård"
    , "Barnabé"
    , "Barré"
    , "Barták"
    , "Barteková"
    , "Baugé"
    , "Bäumer"
    , "Béatrice"
    , "Bécaud"
    , "Bédard"
    , "Bédié"
    , "Begoña"
    , "Béla"
    , "Bélanger"
    , "Belascoarán"
    , "Belén"
    , "Bělohlávek"
    , "Beltré"
    , "Benavídez"
    , "Bendegúz"
    , "Benítez"
    , "Benjámin"
    , "Benoît"
    , "Beresová"
    , "Bermúdez"
    , "Bernabéu"
    , "Bernárdez"
    , "Béryl"
    , "Beyoncé"
    , "Böckler"
    , "Boczkó"
    , "Boglárka"
    , "Bolaños"
    , "Bolívar"
    , "Bolükbasi"
    , "Borgström"
    , "Borlée"
    , "Böröcz"
    , "Botín"
    , "Briceño"
    , "Brücken"
    , "Brzobohatý"
    , "Bubeník"
    , "Bublé"
    , "Bühler"
    , "Búranová"
    , "Büsra"
    , "Büthe"
    , "Büyükakcay"
    , "Byström"
    , "Cabrnochová"
    , "Cáceres"
    , "Calderón"
    , "Cañadilla"
    , "Cañas"
    , "Cañavate"
    , "Canelón"
    , "Cánepa"
    , "Cantú"
    , "Capó"
    , "Cárdenas"
    , "Carlén"
    , "Carré"
    , "Casañas"
    , "Cassarà"
    , "Cássia"
    , "Castellaños"
    , "Cátia"
    , "Cazaubón"
    , "Cebrián"
    , "Cécile"
    , "Cécilia"
    , "Cédric"
    , "Célestin"
    , "Céline"
    , "Célio"
    , "Čepický"
    , "Cerén"
    , "César"
    , "Céspedes"
    , "Cézanne"
    , "Chacón"
    , "Chaunté"
    , "Chávez"
    , "Chihuán"
    , "Chloé"
    , "Chrétien"
    , "Cibrián"
    , "Cintrón"
    , "Cíosóig"
    , "Cissé"
    , "Clélia"
    , "Clémence"
    , "Clément"
    , "Clévenot"
    , "Colón"
    , "Compaoré"
    , "Conceição"
    , "Concepción"
    , "Condé"
    , "Córdoba"
    , "Cordón"
    , "Córdova"
    , "Cortés"
    , "Crépeau"
    , "Cristóbal"
    , "Cubillán"
    , "Cué"
    , "Cuétara"
    , "Cynné"
    , "Czaková"
    , "Czigány"
    , "Daabousová"
    , "Dallapé"
    , "Dániel"
    , "Danièle"
    , "Danté"
    , "Dávalos"
    , "Dávid"
    , "DawnCheré"
    , "Débora"
    , "Déborah"
    , "Déby"
    , "Décary"
    , "Delía"
    , "Dembélé"
    , "Dénes"
    , "Dépré"
    , "DerlisRamón"
    , "Dési"
    , "Desirée"
    , "Desrosières"
    , "Díaz"
    , "Diémé"
    , "Dièye"
    , "Dilmé"
    , "Djá"
    , "Djénébou"
    , "Dolínek"
    , "Domínguez"
    , "Donté"
    , "Dóra"
    , "Dorjsürengiin"
    , "Dostál"
    , "Duchonová"
    , "Ducó"
    , "Dueñas"
    , "Dukátová"
    , "Durán"
    , "Dvorák"
    , "Echávarri"
    , "Echevarría"
    , "Éder"
    , "Édgar"
    , "Ekateríni"
    , "Élodie"
    , "Elphége"
    , "Émane"
    , "Émile"
    , "Emilíana"
    , "Émilie"
    , "Épangue"
    , "Erdélyi"
    , "Ergüven"
    , "Érica"
    , "Érick"
    , "Érika"
    , "España"
    , "Espíndola"
    , "Étienne"
    , "Eugénie"
    , "Eurén"
    , "Éva"
    , "Éve"
    , "Évora"
    , "Fabián"
    , "Fábio"
    , "Fabíola"
    , "Fagúndez"
    , "Fältskog"
    , "Fariña"
    , "Felício"
    , "Félix"
    , "Ferencová"
    , "Fernández"
    , "Flávia"
    , "Flesjå"
    , "Flóra"
    , "Florenç"
    , "Flügel"
    , "Flüggen"
    , "Foldházi"
    , "François"
    , "Françoise"
    , "Frédéric"
    , "Frédérick"
    , "Frisé"
    , "Fürste"
    , "Gábor"
    , "Gádorfalvi"
    , "Gagné"
    , "Gáliková"
    , "Gándara"
    , "Garbiñe"
    , "García"
    , "Garrigós"
    , "Gascón"
    , "Gáspár"
    , "Gastón"
    , "Gaudí"
    , "Gélineau"
    , "Geneviève"
    , "Gérard"
    , "Germán"
    , "Gerónimo"
    , "Géroudet"
    , "Gévrise"
    , "Giménez"
    , "Ginóbili"
    , "Gnassingbé"
    , "Gomà"
    , "Gómez"
    , "Gonçalves"
    , "Göncz"
    , "González"
    , "Göran"
    , "Grátz"
    , "Grégory"
    , "Grévy"
    , "Grimké"
    , "Grimsbö"
    , "Grímsson"
    , "Grönberg"
    , "Grövdal"
    , "Guillén"
    , "Güldeniz"
    , "Gülec"
    , "Gulldén"
    , "Gümbel"
    , "Gündegmaa"
    , "Günes"
    , "Günther"
    , "Gutiérrez"
    , "Güvenc"
    , "Guzmán"
    , "György"
    , "Gyurcsány"
    , "HÃ¤fner"
    , "Háido"
    , "Håkan"
    , "Hambüchen"
    , "Hamchétou"
    , "Hárai"
    , "Härstedt"
    , "Håvard"
    , "Havlát"
    , "Héléna"
    , "Hélene"
    , "Hendrychová"
    , "Hernán"
    , "Hernández"
    , "Hernangómez"
    , "Hervé"
    , "Hidvégi"
    , "Higuaín"
    , "Hinriksdóttir"
    , "Hjálmsdóttir"
    , "Holingerová"
    , "Holló"
    , "Horváth"
    , "Hosnyánszky"
    , "Hosszú"
    , "Hrasnová"
    , "Hristóforos"
    , "Hrivnák"
    , "Hufnágel"
    , "Hultén"
    , "Hüseyin"
    , "Hypólito"
    , "Hyryläinen"
    , "Ibañez"
    , "Ibargüen"
    , "Idéhn"
    , "Ié"
    , "Illés"
    , "Inácio"
    , "Iñárritu"
    , "Inés"
    , "István"
    , "Iván"
    , "Jackée"
    , "Jágr"
    , "Jakubský"
    , "Jámison"
    , "Jämsä"
    , "Janatková"
    , "János"
    , "Járóka"
    , "Jaurès"
    , "Jeremiáš"
    , "Jérémie"
    , "Jérémy"
    , "Jérent"
    , "Jérome"
    , "Jéssica"
    , "Jesús"
    , "Jhené"
    , "Jiménez"
    , "Jiří"
    , "João"
    , "Joaquín"
    , "Joëlle"
    , "Jóhannsson"
    , "Jonatán"
    , "JonBenét"
    , "Jördis"
    , "Jorén"
    , "Josée"
    , "Josué"
    , "Jóźwiak"
    , "Juhász"
    , "Júlio"
    , "Júnior"
    , "Juppé"
    , "Jürgen"
    , "Jurinová"
    , "Kaboré"
    , "Kafétien"
    , "Kaká"
    , "Kalovský"
    , "Kapás"
    , "Karlström"
    , "Karolína"
    , "Kasó"
    , "Katarína"
    , "Kätlin"
    , "KÃ©vin"
    , "Kemrová"
    , "Késely"
    , "Kévin"
    , "Khloé"
    , "Khüderbulga"
    , "Kléber"
    , "Kléberson"
    , "Klobucník"
    , "Klocová"
    , "Klöden"
    , "Kněžínková"
    , "Köbrich"
    , "Köhler"
    , "Kohlová"
    , "Koňařík"
    , "Kořán"
    , "Kovács"
    , "Kovágó"
    , "Kozák"
    , "Krejčí"
    , "Kristián"
    , "Krisztián"
    , "Krizsán"
    , "Krüger"
    , "Kühn"
    , "Kühne"
    , "Kylliäinen"
    , "Laanmäe"
    , "Labbé"
    , "Laferrière"
    , "Laprovíttola"
    , "Larrañaga"
    , "László"
    , "Lázaro"
    , "Léa"
    , "Léandre"
    , "Lefèvre"
    , "Leitón"
    , "Lemprière"
    , "León"
    , "Lepistö"
    , "Lerú"
    , "Lidström"
    , "Lillána"
    , "Listopadová"
    , "Liván"
    , "Lívia"
    , "Lloréns"
    , "Lluís"
    , "Löke"
    , "Longová"
    , "López"
    , "Lotiès"
    , "Lövnes"
    , "Lü"
    , "Lübeck"
    , "Lucía"
    , "Lückenkemper"
    , "Luís"
    , "Lukás"
    , "Lukáš"
    , "Lúthersdóttir"
    , "Madaí"
    , "Madarász"
    , "Mäe"
    , "Magallán"
    , "Mägi"
    , "Mahé"
    , "Maíla"
    , "Majdán"
    , "Mäkelä"
    , "Mandátová"
    , "Mané"
    , "Mangué"
    , "Marc-André's"
    , "Márcio"
    , "Maréchal"
    , "Marí"
    , "Mária"
    , "María"
    , "Marílson"
    , "Marín"
    , "Mariño"
    , "Mário"
    , "Márk"
    , "MarozsÃ¡n"
    , "Márquez"
    , "Martí"
    , "Martín"
    , "Martínek"
    , "Martínez"
    , "Márton"
    , "Massó"
    , "Mätas"
    , "Máté"
    , "Matías"
    , "Matús"
    , "Maurício"
    , "Máximo"
    , "Meité"
    , "Mélanie"
    , "Mélina"
    , "Méline"
    , "Méndez"
    , "Meroúsis"
    , "Micheál"
    , "Michèle"
    , "Mihaíl"
    , "Mijaín"
    , "Miklós"
    , "Millán"
    , "Miltiádis"
    , "Moisés"
    , "Mokosová"
    , "Molnár"
    , "Mónaco"
    , "Monáe"
    , "Mónica"
    , "Mónika"
    , "Montaño"
    , "Morén"
    , "Mörk"
    , "Mörö"
    , "Müller"
    , "Muñiz"
    , "Muñoz"
    , "Murúa"
    , "Nádia"
    , "Naïm"
    , "Natália"
    , "Negrón"
    , "Németh"
    , "Néstor"
    , "Niccolò"
    , "Nicolás"
    , "Niinistö"
    , "Nóbrega"
    , "Noélie"
    , "Noémie"
    , "Nordén"
    , "Núbia"
    , "Nuñez"
    , "Ódorová"
    , "Öhrström"
    , "Ólafur"
    , "Óleo"
    , "Opatrný"
    , "Orbán"
    , "Ordóñez"
    , "Oréane"
    , "Ortíz"
    , "Óscar"
    , "Ozlü"
    , "Ozyüksel"
    , "Pääbo"
    , "Pabón"
    , "Padacké"
    , "Pádraig"
    , "Páez"
    , "Pajón"
    , "Pál"
    , "Palát"
    , "Panayióta"
    , "Pär"
    , "Paré"
    , "Pärt"
    , "Patiño"
    , "Patrícia"
    , "Patrocínio"
    , "Pattantyús"
    , "Pavón"
    , "Péché"
    , "Péchoux"
    , "Pelikán"
    , "Peña"
    , "Peñate"
    , "Pénélope"
    , "Péni"
    , "Pépin"
    , "Pérez"
    , "Perón"
    , "Pétain"
    , "Petchamé"
    , "Péter"
    , "Pétervári"
    , "Philémon"
    , "Phúc"
    , "Piétrus"
    , "Pinzón"
    , "Pité"
    , "Pitkämäki"
    , "Poésy"
    , "Pokorný"
    , "Polívka"
    , "Póta"
    , "Préval"
    , "Prokopová"
    , "Puigcercós"
    , "Pürevjargalyn"
    , "Putálová"
    , "Quiñones"
    , "Quiñonez"
    , "Quintillà"
    , "Quvenzhané"
    , "Rácz"
    , "Ramírez"
    , "Raúl"
    , "Řebíček"
    , "Récsei"
    , "Rédli"
    , "Réka"
    , "Rémi"
    , "Renáta"
    , "Rendón"
    , "René"
    , "Renée"
    , "Rénelle"
    , "Rentería"
    , "Repcík"
    , "Reséndiz"
    , "Rézola"
    , "Ribéry"
    , "Richárd"
    , "Ríga"
    , "Robenílson"
    , "Róbert"
    , "Róchez"
    , "Rocío"
    , "Rodríguez"
    , "Rogério"
    , "Rolfö"
    , "Román"
    , "Romová"
    , "Rónald"
    , "Rosário"
    , "Rubén"
    , "Rühr"
    , "Ruíz"
    , "Sá"
    , "Saborío"
    , "Sagardía"
    , "Sallói"
    , "Salomé"
    , "Salvadó"
    , "Samassékou"
    , "Sánchez"
    , "Sandé"
    , "Sándor"
    , "Sardá"
    , "Sárosi"
    , "Sátila"
    , "Saúl"
    , "Saunière"
    , "Savón"
    , "Scalamandré"
    , "Schächter"
    , "Schäfer"
    , "Schäuble"
    , "Schlögl"
    , "Schmiedlová"
    , "Schön"
    , "Schröder"
    , "Schüpbac"
    , "Schüssel"
    , "Schütze"
    , "Séamus"
    , "Seán"
    , "Sebastián"
    , "Sébastien"
    , "Sebestyén"
    , "Sélom"
    , "Sène"
    , "Senyürek"
    , "Seppälä"
    , "Sepúlveda"
    , "Sérgio"
    , "Shkëlzen"
    , "Sicília"
    , "Silfvén"
    , "Siljamäki"
    , "Sinéad"
    , "Sjåstad"
    , "Sjöberg"
    , "Sjödin"
    , "Sjöström"
    , "Skantár"
    , "Söderberg"
    , "Söderling"
    , "Sofía"
    , "Solé"
    , "Solís"
    , "Söllner"
    , "Somorácz"
    , "Sörenstam"
    , "Ståhl"
    , "Ståle"
    , "Stefanídi"
    , "Stéphane"
    , "Stéphanie"
    , "Strålman"
    , "Strömberg"
    , "Stübe"
    , "Studničková"
    , "Suárez"
    , "Šuláková"
    , "Süle"
    , "Süleyman"
    , "Švácha"
    , "Svärd"
    , "Svennerstål"
    , "Szabián"
    , "Szabó"
    , "Szász"
    , "Szilágyi"
    , "Szomolányi"
    , "Szücs"
    , "Szwarnóg"
    , "Taaramäe"
    , "Tabaré"
    , "Tainá"
    , "Takács"
    , "Támara"
    , "Tamás"
    , "Tarragó"
    , "Tazegül"
    , "Tcheuméo"
    , "Tchórz"
    , "Téa"
    , "Tentóglou"
    , "Teófilo"
    , "Teré"
    , "Tévez"
    , "Thaísa"
    , "Théo"
    , "Théophile"
    , "Thérèse"
    , "Théry"
    , "Thiéry"
    , "Tímea"
    , "Tió"
    , "Todenhöfer"
    , "Tomáš"
    , "Tomorkhüleg"
    , "Tõnu"
    , "Topolánek"
    , "Tormé"
    , "Tornéus"
    , "Törnroos"
    , "Török"
    , "Tórrez"
    , "Tórtola"
    , "Tóth"
    , "Touadéra"
    , "Tramèr"
    , "Traoré"
    , "Träsch"
    , "Trévor"
    , "Tsinopoúlou"
    , "Túñez"
    , "Türk"
    , "Tüvshinbat"
    , "Tüvshinbayar"
    , "Üitümen"
    , "Ünal"
    , "Ungvári"
    , "Urán"
    , "Úrsula"
    , "Üstündag"
    , "Václav"
    , "Valdés"
    , "Valentín"
    , "Valérian"
    , "Valériane"
    , "Välimäki"
    , "Vallée"
    , "Vámos"
    , "Vásquez"
    , "Vázquez"
    , "Velázquez"
    , "Veldáková"
    , "Venyercsán"
    , "Veréb"
    , "Verón"
    , "Verrasztó"
    , "Víctor"
    , "Victória"
    , "Viktória"
    , "Vilató"
    , "Villaécija"
    , "Villafría"
    , "Vinícius"
    , "Viñolas"
    , "Vitória"
    , "Vladimír"
    , "Wallén"
    , "Wálter"
    , "Wanyá"
    , "Wé"
    , "Wéverton"
    , "Wikström"
    , "Xénia"
    , "Yáñez"
    , "Younés"
    , "Zagré"
    , "Zalánki"
    , "Zelená"
    , "Zélia"
    , "Zoltán"
    , "Zságer"
    , "Zsófia"
    };

int main()
{
    for (const char *name : names) {
        if (lex(name) != 0) {
            fprintf(stderr, "failed name: %s\n", name);
            return 1;
        }
    }
    return 0;
}
