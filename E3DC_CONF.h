//
//  E3DC_CONF.h
//  RscpExcample
//
//  originally Created by Eberhard Mayer on 16.08.18. / OS 09.03.2022
//  Copyright © 2018 Eberhard Mayer. All rights reserved.
//
#define VERSION "2022.03.09.0" //Delta
#ifndef E3DC_CONF_h
#define E3DC_CONF_h


#endif /* E3DC_CONF_h */
// Konfigurationsdatei
#define CONF_FILE "e3dc.config.txt"
#define OPENWB "localhost"

#define WURZELZAEHLER 0;     // 0 = interner Zähler 6 = externer Zähler

#define LADESCHWELLE 30;     // bis zur dieser Schwelle wird geladen bevor die Regelung beginnt
#define LADEENDE 95;         // Zielwert bis Ende Regelung, dannach wird Ladung auf Landeende2 weiter geregelt und dann ab SOMMERLADEENDE freigegeben
#define LADEENDE2 99;
#define UNTERERLADEKORRIDOR 300 // die Ladeleistung soll zwischen dem unteren und
#define OBERERLADEKORRIDOR   2200 // oberere Ladeleistung liegen, jedoch
#define MINIMUMLADELEISTUNG  80 // immer > MINIMUMLADELEISTUNG
#define MAXIMUMLADELEISTUNG 3000 // maximale Ladeleistung
#define WRLEISTUNG 12000 // maximale Wechselrichterleistung

#define SPEICHERGROESSE 12.0 // nutzbare Kapazität des S10 Speichers, Dezimalwert
#define REGELZEITENDE   14.0 // Uhrzeit (als Dezimalwert) bis zu dieser Uhrzeit wird das Laden überwacht
#define REGELZEITBEGINN 10.0 // alle Zeiten in GMT = MEZ Winterzeit - 1
#define SOMMERLADEENDE  15.0 // alle Zeiten in GMT = MEZ Winterzeit - 1
#define EINSPEISELIMIT   5.3 // maximal erlaubte Einspeiseleistung in kW
#define JZKORR 55 //Jahreszeitkorrektur des Regelzeitraumes in Prozent: max. Regelzeitraum wird für Sommer (21.06.) angegeben. 
// Jahreszeitkorrektur 55% bedeutet, dass sich der Regelzeitraum am 21.12. auf 55% des Sommer-Regelzeitraumes verkleinert. 
// Dazwischen wird über cos-Funktion interpoliert. 100% bedeutet, der Regelzeitraum wird nicht reduziert/korrigiert

//const int cLadeschwelle = LADESCHWELLE; // Minimum Lade-Schwelle wird bevorzugt der E3DC-Speicher geladen
//const int cLadeende = LADEENDE;     // Lade-Schwelle des überwachten Ladens
typedef struct {
    char server_ip[20];
    uint32_t  server_port;
    char e3dc_user[128];
    char e3dc_password[128];
    char aes_password[128];
    char logfile[128],conffile[128];
    char openWBhost[128];
    bool wallbox,ext1,ext2,ext3,ext7,debug,htsat,htsun,openWB,aWATTar,regelungaktiv;
    uint8_t wurzelzaehler,ladeschwelle, ladeende, ladeende2, unload, AWtest;
    int32_t ht, untererLadekorridor, obererLadekorridor, minimumLadeleistung, maximumLadeleistung, wrleistung, peakshave, peakshsoc, wbmode, wbminlade;
    float_t speichergroesse,regelzeitende, regelzeitbeginn, sommerladeende, einspeiselimit, jahreszeitkorrektur, hton, htoff, htsockel, wbminSoC, breite, laenge, Avhourly, AWDiff, AWAufschlag;

}e3dc_config_t;
