# Bank Management System – C++

**Konsolenbasierte Bankverwaltungsanwendung als Lernprojekt mit objektorientierter Programmierung (OOP).**

Dieses Projekt habe ich im Rahmen meines **strukturierten Selbststudiums der Softwareentwicklung** in C++ umgesetzt. Dabei wende ich Programmierkonzepte praktisch an: Klassen und Objekte, Vererbung, Kapselung, Dateiverarbeitung sowie die Aufteilung eines größeren Programms in überschaubare Verantwortungsbereiche.

Das Ziel ist nicht, eine produktionsreife Banking-Software bereitzustellen, sondern nachvollziehbar zu zeigen, wie ich Geschäftsabläufe in Code umsetze und mein Verständnis für Softwarearchitektur weiterentwickle.

**Projektstatus:** Die grundlegenden Funktionen der Bankverwaltung sind implementiert. Der Bereich Währungsverwaltung befindet sich noch in Entwicklung.

## Funktionen

### Benutzer und Zugriffsrechte
- Anmeldung mit Benutzername und Passwort
- Benutzerverwaltung (Anlegen, Suchen, Bearbeiten und Löschen)
- Prüfung von Zugriffsberechtigungen für verschiedene Funktionen
- Protokollierung von Anmeldungen

### Kunden und Konten
- Kunden und Bankkonten anzeigen und suchen
- Neue Kunden anlegen sowie vorhandene Kundendaten aktualisieren oder löschen
- Kontostände anzeigen und Gesamtsaldo aller Konten berechnen

### Banktransaktionen
- Einzahlungen und Auszahlungen
- Überweisungen zwischen Konten
- Prüfung des verfügbaren Kontostands bei Überweisungen
- Speicherung und Anzeige von Überweisungsprotokollen

### Währungen
- Klassen und Daten für die Verwaltung von Währungen sind vorhanden
- Die Einbindung der Währungsfunktionen in den vollständigen Programmablauf wird noch weiterentwickelt

## Technologien und Konzepte

| Bereich | Umsetzung |
| --- | --- |
| Programmiersprache | C++ |
| Entwicklungsumgebung | Visual Studio 2022 |
| Benutzeroberfläche | Konsolenanwendung |
| Programmierparadigma | Objektorientierte Programmierung (OOP) |
| Zentrale Konzepte | Klassen, Vererbung, Kapselung und Methoden |
| Standardbibliothek | `std::string`, `std::vector`, Dateiströme |
| Datenspeicherung | Lokale Textdateien mit `fstream` |
| Versionsverwaltung | Git und GitHub |

Aktuell verwendet die Anwendung **noch keine Datenbank**. Die Daten werden in Textdateien gelesen und gespeichert.

## Projektaufbau und Trennung der Verantwortlichkeiten

Mir ist wichtig, die **Benutzeroberfläche** nicht mit der gesamten **Geschäftslogik** zu vermischen. Deshalb ist das Projekt in Klassen mit unterschiedlichen Aufgaben aufgeteilt.

| Bereich | Beispiele | Aufgabe |
| --- | --- | --- |
| Geschäftslogik und Daten | `clsBankClient.h`, `clsUser.h`, `clsCurrency.h` | Verwaltung der fachlichen Operationen und Daten |
| Konsolenoberfläche | `clsLoginScreen.h`, `clsMainScreen.h`, `clsClientsList.h`, `clsTransfer.h` | Menüs, Eingaben und Ergebnisse |
| Hilfsklassen | `clsPerson.h`, `clsString.h`, `clsDate.h`, `clsInputValidate.h` | Wiederverwendbare Funktionen |

**Beispiel:** Die Klasse `clsTransfer` übernimmt die Interaktion mit dem Benutzer bei einer Überweisung. Die fachliche Operation `Transfer(...)` liegt dagegen in `clsBankClient`. Dort wird unter anderem geprüft, ob das Guthaben ausreicht, bevor Beträge übertragen und protokolliert werden.

Diese Aufteilung ist ein **Lernschritt in Richtung Separation of Concerns**. Sie ist noch keine vollständig getrennte Mehrschichtenarchitektur. Beispielsweise lesen und schreiben einzelne Fachklassen ihre Daten derzeit selbst in Textdateien.

Diesen Bereich möchte ich mit zunehmender Erfahrung weiter verbessern.

## Installation und Start

**Voraussetzungen:** Windows mit Visual Studio 2022 und installierter C++-Desktopentwicklung.

1. Repository herunterladen oder klonen.
2. `ConsoleApplication1.sln` in Visual Studio 2022 öffnen.
3. Eine passende Build-Konfiguration wählen, beispielsweise `Debug | x64`.
4. Das Projekt erstellen und die Konsolenanwendung starten.

Die Anwendung verwendet relative Pfade zu Textdateien. Das Arbeitsverzeichnis muss deshalb so eingestellt sein, dass diese Dateien gefunden werden.

## Ein typischer Programmablauf

1. Der Benutzer meldet sich über die Konsole an.
2. Das Hauptmenü zeigt die verfügbaren Aktionen.
3. Bei geschützten Funktionen werden die Zugriffsrechte geprüft.
4. Der Benutzer kann Kunden verwalten, Kontostände einsehen oder Überweisungen ausführen.
5. Die entsprechenden Daten und Protokolle werden in Textdateien aktualisiert.

## Was ich dabei lerne

- Größere Aufgaben in Klassen mit klaren Verantwortlichkeiten zerlegen
- Objektorientierte Konzepte praktisch einsetzen
- Daten mit `vector` verarbeiten und in Dateien speichern
- Benutzeroberfläche und fachliche Regeln unterscheiden
- Bestehenden Code nachvollziehen, Fehler suchen und Funktionen erweitern
- Meine Entwicklung mit Git und GitHub dokumentieren

## Screenshots

Screenshots der Anmeldung, des Hauptmenüs, der Kundenverwaltung und der Überweisungen werden ergänzt.

## Geplante Weiterentwicklung

- Währungsverwaltung fertigstellen und in die Bedienoberfläche integrieren
- Aufbau und Wiederverwendbarkeit einzelner Klassen verbessern
- Eingabeprüfung und Fehlerbehandlung erweitern
- Die Datenspeicherung perspektivisch von Textdateien auf eine **relationale Datenbank** umstellen
- Erlernte Konzepte auch in **C#** und in weiteren Projekten anwenden

Diese Punkte sind geplant und noch nicht als fertig implementierte Funktionen zu verstehen.

## Hintergrund

Das Projekt ist Teil meines längerfristigen, strukturierten Lernwegs in der Softwareentwicklung.

Ich nutze es, um theoretische Konzepte praktisch einzuüben, mein Verständnis für sauberen Code auszubauen und mich auf eine **Ausbildung zum Fachinformatiker für Anwendungsentwicklung** vorzubereiten.

**Repository:** https://github.com/Mohammed081224/Bank-Management-System
